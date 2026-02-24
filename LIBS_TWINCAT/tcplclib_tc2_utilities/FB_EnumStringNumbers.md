# FB_EnumStringNumbers

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_EnumStringNumbers

![47570623](/tcplclib_tc2_utilities/1033/Images/png/9007199290219275__Web.png)

This function block can be used to search a string in a REPEAT or WHILE loop for numbers. The string may contain several numbers. Any numbers that are found are output as sub-strings at the block output. The function searches from the current position for the first character that can be interpreted as a numeral. The search is aborted if a character is found that cannot be interpreted as a number. The *eCmd* parameter determines whether the search is for the first number or the next number. The *eType* parameter determines the format of the numbers in the search string.

## VAR\_INPUT

```
VAR_INPUT  
    sSearch   : T_MaxString;  
    eCmd      : E_EnumCmdType := eEnumCmd_First;  
    eType     : E_NumGroupTypes := eNumGroup_Float;  
END_VAR
```

**sSearch**: Search string to be searched for numbers (type: T\_MaxString).

**eCmd**: Control command for the enumeration block (type: [E\_EnumCmdType](ms-xhelp:///?Id=beckhoff-cb91-427b-a901-37149aa7aa27)).

**eType**: Number format of the searched number (type: [E\_NumGroupTypes](ms-xhelp:///?Id=beckhoff-2d35-4200-a29a-36172c0cdbaa)). This parameter determines which characters are to be ignored and which are to be interpreted as numerals:

| Value | Meaning |
| --- | --- |
| eNumGroup\_Float | Numbers '0' to '9', '+', '-' (signs) and 'e' or 'E' (exponent character) are interpreted as valid numerals. |
| eNumGroup\_Unsigned | Numbers '0' to '9' are interpreted as valid numerals. '+', '-', 'e', 'E' characters are ignored. |
| eNumGroup\_Signed | Numbers '0' to '9', '+', '-' (signs) are interpreted as valid numerals. 'e', 'E' characters are ignored. |

If the string contains numbers in the exponential notation, eType = *eNumGroup\_Float* must be set (default).

## VAR\_OUTPUT

```
VAR_OUTPUT  
    sNumber    : T_MaxString;  
    nPos       : INT;  
    bEOS       : BOOL;  
END_VAR
```

**sNumber**: The last found number as string (type: T\_MaxString).

**nPos**: This variable always returns the position after the last found and correctly formatted numeral, i.e. at this position the block will start searching for new numerals when it is called next time. *nPos* is zero when the final zero of the *sSearch* string has been reached. The first character in the string has position number = 1 (non-zero based position).

**bEOS**: This variable is FALSE if a new number was found and the end of the string has not yet been reached. In this case *sNumber* returns a valid number as a string. This variable is TRUE if no further number was found. In this case any further search must be aborted (*sNumber* returns no valid value).

**Example:**

In the following example the *sNumber* variable is searched for valid numbers. Any sub-strings that are found are stored in the array variable *arrNums*.

```
TYPE ST_ScanRes :  
STRUCT  
    sNumber   : T_MaxString;  
    nPos      : INT;  
    sRemain   : T_MaxString;  
END_STRUCT  
END_TYPE
```

```
PROGRAM MAIN  
VAR  
    sSearch    : T_MaxString := 'Some numbers in string: +-12e-34, -56, +78';  
    fbEnum     : FB_EnumStringNumbers := ( eType := eNumGroup_Float (* eNumGroup_Signed, eNumGroup_Unsigned *) );  
    arrNums    : ARRAY[1..MAX_SCAN_NUMS] OF ST_ScanRes;  
    idx        : INT;  
    length     : INT;  
    bEnum      : BOOL := TRUE;  
END_VAR  
VAR CONSTANT  
    MAX_SCAN_NUMS : INT := 10;  
END_VAR
```

```
IF bEnum THEN  
    bEnum := FALSE;  
  
    MEMSET( ADR( arrNums ), 0, SIZEOF( arrNums ) );  
    idx := 0;  
    length := LEN( sSearch );  
  
    fbEnum( sSearch := sSearch, eCmd := eEnumCmd_First );  
    WHILE NOT fbEnum.bEOS DO  
        IF idx < MAX_SCAN_NUMS THEN  
            idx := idx + 1;  
  
            arrNums[idx].sNumber:= fbEnum.sNumber;  
            arrNums[idx].nPos := fbEnum.nPos;  
            IF fbEnum.nPos <> 0 THEN  
                arrNums[idx].sRemain:= RIGHT( sSearch, length - fbEnum.nPos + 1 );  
            END_IF  
  
        END_IF  
        fbEnum( eCmd := eEnumCmd_Next );  
    END_WHILE  
END_IF
```

Found strings:

* '-12e-34'
* '-56'
* '+78'

*eType* parameter *eNumGroup\_Signed* returns the following results:

* '-12'
* '-34'
* '-56'
* '+78'

*eType* parameter *eNumGroup\_Unsigned* returns the following results:

* '12'
* '34'
* '56'
* '78'

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
