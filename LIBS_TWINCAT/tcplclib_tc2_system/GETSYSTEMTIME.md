# GETSYSTEMTIME

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [[Obsolete]](ms-xhelp:///?Id=beckhoff-e729-4de7-9481-4905b7f6ef80)
4. GETSYSTEMTIME

# GETSYSTEMTIME

|  |  |
| --- | --- |
| 38520254 | This function block is replaced by the newer function F\_GetSystemTime(), which only needs one return value, not two. |

![11137969](/tcplclib_tc2_system/1033/Images/png/9007199285911563__Web.png)

With this function block the operating system time stamp can be read. The time stamp is a 64 bit integer value, with a precision of 100ns, which is updated with every call of the PLC. Amongst other uses, it can be utilized for timing tasks or time measurements. One unit corresponds to 100 ns. The time represents the number of 100 ns intervals since 1 January 1601.

See: [F\_GetSystemTime](ms-xhelp:///?Id=beckhoff-117c-43d5-b024-3da6115215c4)

## VAR\_INPUT

```
VAR_INPUT  
(*none*)  
END_VAR
```

## VAR\_OUTPUT

```
VAR_OUTPUT  
    timeLoDW   : UDINT;  
    timeHiDW   : UDINT;  
END_VAR
```

**timeLoDW**: Contains the low-value 4 bytes of the time stamp.

**timeHiDW**: Contains the high-value 4 bytes of the time stamp.

**Sample of calling the function block in FBD:**

![33132859](/tcplclib_tc2_system/1033/Images/png/31173771__en-US__Web.png)

The sample illustrates calling the function block via the instance ‘GetSystemTime1’, and delivers the 64 bit, integer value (hex) 1BCD6EAB05C4E60 as the time stamp.

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
