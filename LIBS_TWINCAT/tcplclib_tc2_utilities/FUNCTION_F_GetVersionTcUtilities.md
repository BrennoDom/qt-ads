# FUNCTION F_GetVersionTcUtilities

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FUNCTION F\_GetVersionTcUtilities

This function is obsolete and should not be used. Please use the global constant: stLibVersion\_Tc2\_Utilities to read the [PLC library version](ms-xhelp:///?Id=beckhoff-7763-42a9-8f38-7373c5674d28) information.

![55128053](/tcplclib_tc2_utilities/1033/Images/gif/36243083__en-US__Web.gif)

This function can be used to read PLC library version information.

## FUNCTION F\_GetVersionTcUtilities : UINT

## VAR\_INPUT

```
VAR_INPUT  
    nVersionElement : INT;  
END_VAR
```

**nVersionElement** : Version element to be read. Possible parameters:

* 1 : major number;
* 2 : minor number;
* 3 : revision number;

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
