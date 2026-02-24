# Int64Div64Ex

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# Int64Div64Ex

![60664521](/tcplclib_tc2_utilities/1033/Images/gif/36019083__en-US__Web.gif)

The function divides two TwinCAT 2 signed 64-bit numbers (“legacy” type: [T\_LARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-3d0c-4b6a-95f9-eef4d2da39b1)). The result is a signed 64-bit number.

## FUNCTION Int64Div64Ex: T\_LARGE\_INTEGER

## VAR\_INPUT

```
VAR_INPUT  
    dividend  : T_LARGE_INTEGER;  
    divisor   : T_LARGE_INTEGER;  
END_VAR
```

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    remainder : T_LARGE_INTEGER;  
END_VAR
```

**remainder**: Residual.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
