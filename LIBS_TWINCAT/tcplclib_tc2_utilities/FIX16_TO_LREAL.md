# FIX16_TO_LREAL

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FIX16\_TO\_LREAL

![30282311](/tcplclib_tc2_utilities/1033/Images/gif/36051083__en-US__Web.gif)

Converts a signed 16-bit fixed-point number to a floating-point number of type: LREAL.

## FUNCTION FIX16\_TO\_LREAL: LREAL

## VAR\_INPUT

```
VAR_INPUT  
    in : T_FIX16;  
END_VAR
```

**in**: The fixed-point number to be converted (type: [T\_FIX16](ms-xhelp:///?Id=beckhoff-164a-40cb-8504-92a3977b7841)).

**Example:**

See function description: [LREAL\_TO\_FIX16](ms-xhelp:///?Id=beckhoff-ebc9-4f8b-83fc-fd047b7a3f98).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
