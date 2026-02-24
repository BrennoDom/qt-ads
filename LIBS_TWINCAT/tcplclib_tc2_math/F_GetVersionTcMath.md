# F_GetVersionTcMath

## Library
tcplclib_tc2_math

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Math](ms-xhelp:///?Id=beckhoff-c1bf-4c0b-92f1-a78a2d79cc10)
2. [[obsolete functions]](ms-xhelp:///?Id=beckhoff-a744-4721-80c2-00fffb09c30d)
3. F\_GetVersionTcMath

# F\_GetVersionTcMath

![8066134](/tcplclib_tc2_math/1033/Images/gif/68490379__en-US__Web.gif)

The function returns library version info.

## FUNCTION F\_GetVersionTcMath : UINT

```
VAR_INPUT  
    nVersionElement : INT;  
END_VAR
```

**nVersionElement** : Version parameter:

* 1 : major number;
* 2 : minor number;
* 3 : revision number;

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Math |

[TwinCAT 3 | PLC Library:Tc2\_Math](ms-xhelp:///?Id=beckhoff-c1bf-4c0b-92f1-a78a2d79cc10)
