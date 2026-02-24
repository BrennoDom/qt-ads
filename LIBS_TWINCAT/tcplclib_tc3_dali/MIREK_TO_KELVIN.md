# MIREK_TO_KELVIN

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Commands](ms-xhelp:///?Id=beckhoff-e647-4709-92f0-6dc69db8d17c)
5. [Part 209 (color/color temperature control)](ms-xhelp:///?Id=beckhoff-d816-4de1-bd09-5e02b92cfc27)
6. [Help Functions](ms-xhelp:///?Id=beckhoff-1b88-4158-93a6-6959e39986b3)
7. MIREK\_TO\_KELVIN

# MIREK\_TO\_KELVIN

![27626671](/tcplclib_tc3_dali/1033/Images/gif/6438345995__Web.gif)

Conversion of the color temperature from Mirek to Kelvin.

Mirek is a color temperature unit used by most DALI commands. The return value of the function is limited to the value range 0…1000001 (see table).

Kelvin = 1000000 / (color temperature in Mirek).

| Mirek | Kelvin |
| --- | --- |
| 0 | 1000001.0 |
| 1 | 1000000.0 |
| 100 | 10000.0 |
| 1000 | 1000.0 |
| 10000 | 100.0 |
| 65534 | 15.259 |
| 65535 | 0.0 |

## VAR\_INPUT

```
nMirek    : UINT;
```

**nMirek:** Color temperature in Mirek.

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.10 | Tc3\_DALI from v3.4.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
