# F_GetVersionTcMc2Drive

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# F\_GetVersionTcMc2Drive

![6472929](/tcplclib_tc2_mc2_drive/1033/Images/gif/9007201556885259__Web.gif)

This function can be used to read PLC library version information.

## FUNCTION F\_GetVersionTcMc2Drive: UINT

```
VAR_INPUT  
    nVersionElement : INT;  
END_VAR
```

**nVersionElement**: Version element to be read. Possible parameters:

* 1 : major number;
* 2 : minor number;
* 3 : revision number;
