# F_ToLCase

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_ToLCase

![2784095](/tcplclib_tc2_utilities/1033/Images/gif/35849483__en-US__Web.gif)

The F\_ToLCase function converts all capital letters of a character string to lower-case letters.

|  |  |
| --- | --- |
| 25056856 | Character set  By default the conversion function uses the character set of the Windows code pager 1252 Latin 1, SBCS (singles byte character set). A different character set can be selected at runtime (currently only Windows code page 1250 Central European) via the global variable GLOBAL\_SBCS\_TABLE selected (see example). |

## FUNCTION F\_ToLCase: T\_MaxString

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
    sLCase : STRING;  
END_VAR
```

```
sLCase := F_ToLCase( 'TO LOWER CASE 1234567890 ÄÖÜß' );
```

The result of the conversion is: 'to lower case 1234567890 äöüß'

```
GLOBAL_SBCS_TABLE := eSBCS_CentralEuropean;  
sLCase := F_ToLCase( 'TO LOWER CASE 1234567890 ĄĘŚĆŻŹŁÓ' );
```

The result of the conversion is: 'to lower case 1234567890 ąęśćżźłó'

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
