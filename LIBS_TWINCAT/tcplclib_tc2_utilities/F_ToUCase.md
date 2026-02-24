# F_ToUCase

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_ToUCase

![24185120](/tcplclib_tc2_utilities/1033/Images/gif/35852683__en-US__Web.gif)

The F\_ToUCase function converts all lower-case letters of a character string to capital letters.

|  |  |
| --- | --- |
| 16339495 | Character set  By default the conversion function uses the character set of the Windows code pager 1252 Latin 1, SBCS (singles byte character set). A different character set can be selected at runtime (currently only Windows code page 1250 Central European) via the global variable GLOBAL\_SBCS\_TABLE selected (see example). |

## FUNCTION F\_ToUCase: T\_MaxString

## VAR\_INPUT

```
VAR_INPUT  
    in : T_MaxString;  
END_VAR
```

**in**: The string to be converted (Type: T\_MaxString).

**Example**:

```
PROGRAM MAIN  
VAR  
    sUCase : STRING;  
END_VAR
```

```
sUCase := F_ToUCase( 'to upper case 1234567890 äöüß' );
```

The result of the conversion is: 'TO UPPER CASE 1234567890 ÄÖÜß'

```
GLOBAL_SBCS_TABLE := eSBCS_CentralEuropean;  
sUCase := F_ToUCase( 'to upper case 1234567890 ąęśćżźłó' );
```

The result of the conversion is: 'TO UPPER CASE 1234567890 ĄĘŚĆŻŹŁÓ'

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
