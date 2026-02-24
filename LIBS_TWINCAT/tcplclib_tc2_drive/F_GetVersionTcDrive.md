# F_GetVersionTcDrive

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-02e8-422c-8be2-5398740f979f)
3. F\_GetVersionTcDrive

# F\_GetVersionTcDrive

![51192804](/tcplclib_tc2_drive/1033/Images/gif/2308800523__Web.gif)

This function can be used to read PLC library version information.

## 58082052 Inputs

```
VAR_INPUT  
    nVersionElement : INT;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **nVersionElement** | INT | **nVersionElement**: version element to be read.  Possible parameters:   * 1 : major number; * 2 : minor number; * 3 : revision number; |

## 52976421 Return value

```
FUNCTION F_GetVersionTcDrive : UINT
```

| Name | Type | Description |
| --- | --- | --- |
| **F\_GetVersionTcDrive** | UINT | Return value of the function. Version element as UINT. |

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
