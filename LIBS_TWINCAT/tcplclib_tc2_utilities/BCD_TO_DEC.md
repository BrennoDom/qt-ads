# BCD_TO_DEC

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# BCD\_TO\_DEC

![24632334](/tcplclib_tc2_utilities/1033/Images/png/9007199290164875__Web.png)

The "BCD\_TO\_DEC" function block allows numbers in BCD to be converted to decimal format. The BCD number to be converted is checked for the reliability of the values.

## VAR\_INPUT

```
VAR_INPUT  
    START  : BOOL;  
    BIN    : BYTE;  
END_VAR
```

**START**: The function block is activated by a positive edge at this input.

**BIN**: The BCD number to be converted.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY   : BOOL;  
    ERR    : BOOL;  
    ERRID  : UDINT;  
    DOUT   : BYTE;  
END_VAR
```

**BUSY**: This input is set at the start of the conversion procedure, and remains set until the conversion has been completed. Once the BUSY output has been reset, the decimal value is available at the DOUT output.

**ERR**: This variable is set to TRUE if an error occurs.

**ERRID**: Error code.

**DOUT**: The converted variable in decimal format is available at this output if the process is successful.

## Error Codes:

| Error code | Error descriptions |
| --- | --- |
| 0 | no error |
| 0x000F | Unreliable value in the low nibble of the BCD number |
| 0x00F0 | Unreliable value in the high nibble of the BCD number |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
