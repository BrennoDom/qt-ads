# F_GetVersionTcNcDrive

## Library
tcplclib_tc2_ncdrive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-725e-4601-b0fd-30492204b699)
3. F\_GetVersionTcNcDrive

# F\_GetVersionTcNcDrive

![31783765](/tcplclib_tc2_ncdrive/1033/Images/gif/2302129291__Web.gif)

This function can be used to read PLC library version information.

## FUNCTION F\_GetVersionTcNcDrive: UINT

```
VAR_INPUT  
    nVersionElement : INT;  
END_VAR
```

**nVersionElement**: Version element to be read. Possible parameters:

* 1 : major number;
* 2 : minor number;
* 3 : revision number;

[TwinCAT 3 | PLC Library: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
