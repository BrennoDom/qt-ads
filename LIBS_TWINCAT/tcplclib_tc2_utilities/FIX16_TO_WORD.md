# FIX16_TO_WORD

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FIX16\_TO\_WORD

![4105351](/tcplclib_tc2_utilities/1033/Images/gif/36057483__en-US__Web.gif)

This function converts a 16-bit fixed-point number to a WORD variable (the WORD variable contains the digits and decimal places for the fixed-point number).

## FUNCTION FIX16\_TO\_WORD: WORD

## VAR\_INPUT

```
VAR_INPUT  
    in : T_FIX16;  
END_VAR
```

**in**: fixed point number to convert (type: [T\_FIX16](ms-xhelp:///?Id=beckhoff-164a-40cb-8504-92a3977b7841)).

**Example:**

```
PROGRAM FIX_TO_WORD  
VAR  
    fp16 : WORD;  
END_VAR
```

```
fp16 := FIX16_TO_WORD(LREAL_TO_FIX16(12.5, 8));
```

The value of the *fp16* variable is: 2#0000110010000000.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
