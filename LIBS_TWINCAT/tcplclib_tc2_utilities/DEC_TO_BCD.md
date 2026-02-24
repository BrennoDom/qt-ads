# DEC_TO_BCD

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# DEC\_TO\_BCD

![37029065](/tcplclib_tc2_utilities/1033/Images/png/9007199290168075__Web.png)

The "DEC\_TO\_BCD" function block allows decimal numbers to be converted to BCD format. The number to be converted is checked for the reliability of the values.

## VAR\_INPUT

```
VAR_INPUT  
    START  : BOOL;  
    DIN    : BYTE;  
END_VAR
```

**START**: The function block is activated by a positive edge at this input.

**DIN**: The decimal number requiring conversion.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY   : BOOL;  
    ERR    : BOOL;  
    ERRID  : UDINT;  
    BOUT   : BYTE;  
END_VAR
```

**BUSY**: This input is set at the start of the conversion procedure, and remains set until the conversion has been completed. Once the BUSY output has been reset, the BCD value is available at the BOUT output.

**ERR**: This variable is set to TRUE if an error occurs.

**ERRID**: Error code.

**BOUT**: The converted variable in BCD format is available at this output if the process is successful.

## Error Codes:

| Error Code | Error Description |
| --- | --- |
| 0 | no error |
| 0x00FF | the variable that is to be converted has a forbidden decimal value |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
