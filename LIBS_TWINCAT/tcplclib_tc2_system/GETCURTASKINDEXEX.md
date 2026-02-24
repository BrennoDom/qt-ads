# GETCURTASKINDEXEX

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [General functions](ms-xhelp:///?Id=beckhoff-1e7a-48a5-88e7-caf74e14975e)
4. GETCURTASKINDEXEX

# GETCURTASKINDEXEX

![13898779](/tcplclib_tc2_system/1033/Images/png/18014399226433803__Web.png)

The function determines the task index of the task in which it is called. In contrast to the function block [GETCURTASKINDEX](ms-xhelp:///?Id=beckhoff-64d8-4e29-89aa-2ceaa17c08d2), a distinction can be made as to whether the function is called in a cyclic real-time context or not.

## FUNCTION GETCURTASKINDEXEX : DINT

```
VAR_INPUT  
    (*keine*)  
END_VAR
```

| Return parameter | Description |
| --- | --- |
| -1 | The function is called from the Windows context. |
| 0 | The function is called from the real-time context, but not from a cyclic PLC task. This is the case, for example, with the automatic call of FB\_init methods during initialization. |
| 1 to n | The function is called from a cyclic PLC task. The return value is the task index. |

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
