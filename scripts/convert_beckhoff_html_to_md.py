#!/usr/bin/env python3
"""
Beckhoff HTML → Markdown Type Converter
Extracts TYPE ... STRUCT/UNION/ENUM blocks from Beckhoff Infosys HTML
and writes them as .md files in BHF_context/<library>/<TypeName>.md

Usage:
    python3 scripts/convert_beckhoff_html_to_md.py \
        --zip  include/bkinfosys3_vs_100_en_us.zip \
        --out  include/BHF_context
"""

import argparse
import html
import os
import re
import sys
import zipfile
from pathlib import Path


def extract_type_blocks(html_content: str):
    """Find all <pre>/<xmp>/<code> blocks containing TYPE definitions."""
    blocks = re.findall(
        r'<(pre|xmp|code)[^>]*>(.*?)</\1>', html_content, re.I | re.DOTALL
    )
    results = []
    for tag, content in blocks:
        decoded = html.unescape(content)
        # Normalize line breaks
        text = decoded.replace('<br />', '\n').replace('<br/>', '\n').replace('<br>', '\n')
        # Remove any remaining HTML tags
        text = re.sub(r'<[^>]+>', '', text)
        text = html.unescape(text)
        text = text.strip()
        if not text.startswith('TYPE'):
            continue

        # Extract type name from "TYPE Name :" or "TYPE Name"
        first_line = text.split('\n')[0].strip()
        type_name_match = re.match(r'TYPE\s+([A-Za-z_]\w*)', first_line)
        if not type_name_match:
            continue
        type_name = type_name_match.group(1)

        results.append((type_name, text))
    return results


def get_library_from_path(zip_path: str) -> str:
    """Extract library name from zip entry path.
    e.g. 'tcplclib_tc2_mc2/1033/70161291.html' → 'tcplclib_tc2_mc2'
    """
    parts = Path(zip_path).parts
    if len(parts) >= 1:
        return parts[0]
    return ''


SKIP_LIBRARIES = {
    'bkinfosys3',
    'tcinfosys3',
    'tc3_overview',
    'tc3_installation',
    'tc3_licensing',
    'tc3_userinterface',
    'tc3_io_quickstart',
    'typesystem',
    'globaldatatypes',
    'machineupdate',
    'folderandfiletypes',
    'corrected_timestamps',
    'assets',
    'tc3_plc_intro',
    'tc3_c',
    'tc3_ads_intro',
    'tc3_adsdll2',
    'tc3_ads.net',
    'tc3_ads_dlljava',
    'tc1000_tc3_ads',
    'tc1100_tc3_io',
    'tc1200_tc3_plc',
    'tc1210_tc3_plc_cpp',
    'tc1220_tc3_plc_cpp_matlab',
    'tc1250_tc3_plc_ncptp',
    'tc1260_tc3_plc_ncptp_nci',
    'tc1270_tc3_plc_ncptp_nci_cnc',
    'tc1275_tc3_plc_ncptp_nci_cnce',
    'tc1300_tc3_cpp',
    'tc1320_tc3_cpp_matlab',
    'te1010_tc3_realtime_monitor',
    'te1111_ethercat_simulation',
    'te1120_xcad_interface',
    'te1200_tc3_plcstaticanalysis',
    'te131x_tc3_filterdesigner',
    'te132x_tc3_bodeplot',
    'te13xx_tc3_scopeview',
    'te1400_tc3_target_matlab',
    'te1401_tc3_target_matlab',
    'te1410_tc3_interface_matlab',
    'te1500_tc3_valve_diagram_editor',
    'te1510_tc3_cam_design_tool',
    'te1610',
    'te2000_tc3_hmi_engineering',
    'te3500_tc3_analytics_workbench',
    'te3520_tc3_analytics_service_tool',
    'tc3_automationinterface',
    'tc3_remote_manager',
    'tc3_sourcecontrol',
    'tc3_multiuser',
    'tc3_security_management',
    'tc3ncerrcode',
    'tc3_sampleprogram1',
    'tc3_matlab_overview',
    'tc3_eventlogger',
    'tc3-safety',
    'tc3-plc',
    'tc3_ads_over_mqtt',
    'tc3_ads_ps_tcxaemgmt',
    'tc3_adssamples_net',
    'tc3_adsnetref',
    'secure_ads',
    'ams_nat',
    'eap',
    'lang-basic.js',
    'lang-css.js',
    'lang-delphi.js',
    'lang-matlab.js',
    'lang-pascal.js',
    'lang-powershell.js',
    'lang-sql.js',
    'lang-st.js',
    'lang-vb.js',
    'lang-vhdl.js',
    'prettify.css',
    'prettify.js',
    'project_compare_tool',
    'variant_management',
    'aml_dataexchange',
}


def main():
    parser = argparse.ArgumentParser(description='Convert Beckhoff HTML types to .md')
    parser.add_argument('--zip', required=True, help='Path to bkinfosys3_vs_100_en_us.zip')
    parser.add_argument('--out', required=True, help='Output directory (BHF_context)')
    parser.add_argument('--library', help='Only process this library (e.g. tcplclib_tc2_mc2)')
    parser.add_argument('--dry-run', action='store_true', help='Only list what would be converted')
    args = parser.parse_args()

    zip_path = Path(args.zip)
    out_dir = Path(args.out)

    if not zip_path.exists():
        print(f'Error: {zip_path} not found', file=sys.stderr)
        sys.exit(1)

    converted = 0
    skipped = 0
    errors = 0

    out_dir.mkdir(parents=True, exist_ok=True)

    with zipfile.ZipFile(str(zip_path), 'r') as z:
        all_entries = [e for e in z.namelist() if e.endswith('.html')]
        print(f'Scanning {len(all_entries)} HTML files...')

        for entry in all_entries:
            library = get_library_from_path(entry)
            if not library:
                continue
            if library in SKIP_LIBRARIES:
                continue
            if args.library and library != args.library:
                continue

            try:
                raw = z.read(entry).decode('utf-8', errors='replace')
            except Exception as e:
                print(f'  [ERROR] reading {entry}: {e}', file=sys.stderr)
                errors += 1
                continue

            types = extract_type_blocks(raw)
            if not types:
                skipped += 1
                continue

            lib_out = out_dir / library
            lib_out.mkdir(parents=True, exist_ok=True)

            for type_name, content in types:
                # Sanitize filename
                safe_name = type_name.replace('/', '_').replace('\\', '_')
                md_path = lib_out / f'{safe_name}.md'

                if args.dry_run:
                    print(f'  [DRY] {library}/{safe_name}.md')
                    continue

                # Write .md in the same format the existing TypeRegistry expects
                md_content = f'# {type_name}\n\n'
                md_content += '## Library\n'
                md_content += f'{library}\n\n'
                md_content += '## Category\n'
                md_content += 'Generated\n\n'
                md_content += '```\n'
                md_content += content
                if not content.endswith('\n'):
                    md_content += '\n'
                md_content += '```\n'

                with open(md_path, 'w', encoding='utf-8') as f:
                    f.write(md_content)

                converted += 1
                print(f'  [OK] {library}/{safe_name}.md')

    print(f'\nDone: {converted} converted, {skipped} skipped (no TYPE), {errors} errors')


if __name__ == '__main__':
    main()
