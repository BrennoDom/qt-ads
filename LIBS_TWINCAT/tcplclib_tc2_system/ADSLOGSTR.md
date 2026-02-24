# ADSLOGSTR

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [ADS functions](ms-xhelp:///?Id=beckhoff-5576-4d9d-9f14-f989dcb02fd7)
4. ADSLOGSTR

# ADSLOGSTR

![24006753](/tcplclib_tc2_system/1033/Images/png/9007199286109963__Web.png)

This function issues when called a message box holding a specifiable text on the screen, and writes an entry into the system's log. In the text to be given out, a string (a sequence of characters) can be inserted in the text at a point specified by the user. For this purpose the stored format must contain the characters %s at the desired location. Always remember that here too, as illustrated in the example, the function must be called using edge-control (see also the note in the description of [ADSLOGDINT](ms-xhelp:///?Id=beckhoff-7cde-4c0c-bfd0-d945d7106339)). The result value contains the function error code, or, if successful, 0.

## FUNCTION ADSLOGSTR : DINT

```
VAR_INPUT  
    msgCtrlMask  : DWORD;  
    msgFmtStr    : T_MaxString;  
    strArg       : T_MaxString;  
END_VAR
```

**msgCtrlMask**: Control mask which determines the type and effect of the message output (see separate table at [ADSLOGDINT](ms-xhelp:///?Id=beckhoff-7cde-4c0c-bfd0-d945d7106339)).

**msgFmtStr**: Contains the message to be issued (type: [T\_MaxString](ms-xhelp:///?Id=beckhoff-77e0-4f6f-a54e-eec93d1cd558)). It can contain the formatting code %s for the output of a text argument at any position.

**strArg**: Contains the string which is to be inserted into the message (type: [T\_MaxString](ms-xhelp:///?Id=beckhoff-77e0-4f6f-a54e-eec93d1cd558)).

**Example of calling the function in FBD:**

![14734188](/tcplclib_tc2_system/1033/Images/gif/31372171__en-US__Web.gif)

The resulting message box:

![65498832](/tcplclib_tc2_system/1033/Images/gif/31375371__en-US__Web.gif)

With this, the PLC programmer inserts the string stored in the variable strSFCErrorStep into the message. The insertion point is marked by the %s characters in the format string.

**Example of calling the function in ST:**

```
PROGRAM MAIN  
VAR  
    strSFCErrorStep : STRING; (* Declaration*)  
    rtMessageOutput: R_TRIG;  
    bSFCError: BOOL;  
END_VAR  
  
rtMessageOutput(CLK := bSFCError);  
IF rtMessageOutput.Q THEN  
    udiAdsLogRes := ADSLOGSTR( msgCtrlMask := ADSLOG_MSGTYPE_ERROR OR ADSLOG_MSGTYPE_MSGBOX, msgFmtStr := 'PLC Msg.: Guarding time executed in SFC step: %s', strArg := strSFCErrorStep);  
END_IF;
```

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
