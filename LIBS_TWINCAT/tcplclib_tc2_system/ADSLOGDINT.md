# ADSLOGDINT

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [ADS functions](ms-xhelp:///?Id=beckhoff-5576-4d9d-9f14-f989dcb02fd7)
4. ADSLOGDINT

# ADSLOGDINT

![34708966](/tcplclib_tc2_system/1033/Images/png/9007199286090763__Web.png)

This function issues when called a message box holding a specifiable text on the screen, and writes an entry into the system’s log. Since a PLC program is cyclically processed, it is necessary for an item such as a message box to be output under edge-control. This is most easily achieved with an R\_TRIG or F\_TRIG function block placed in series (see also examples below).

Using the ADSLOGDINT function a DINT value (4 bytes signed integer) can be inserted in the text to be output at a point specified by the user. For this purpose the stored format string must contain the characters '%d' at the desired location. The return parameter contains the function error code, or 0 if successful.

## FUNCTION ADSLOGDINT : DINT

```
VAR_INPUT  
    msgCtrlMask : DWORD;  
    msgFmtStr   : T_MaxString;  
    dintArg     : DINT;  
END_VAR
```

**msgCtrlMask**: Control mask which determines the type and effect of the message output (see separate table).

| Constant | Description |
| --- | --- |
| ADSLOG\_MSGTYPE\_HINT | Message type is hint. |
| ADSLOG\_MSGTYPE\_WARN | Message type is warning. |
| ADSLOG\_MSGTYPE\_ERROR | Message type is error. |
| ADSLOG\_MSGTYPE\_LOG | Message is written into the log. |
| ADSLOG\_MSGTYPE\_MSGBOX | Message is output to a message box. Caution: This functionality is not available under Windows CE. |
| ADSLOG\_MSGTYPE\_STRING | Message is a directly given string (default). |

The control masks can be ORed in the desired combination.

**msgFmtStr**: Contains the message to be issued (type: [T\_MaxString](ms-xhelp:///?Id=beckhoff-77e0-4f6f-a54e-eec93d1cd558)). It can contain the formatting code %d for the output of a DINT value at any position.

**dintArg**: Contains the numerical value to be inserted into the message.

**Example of calling the function in FBD:**

![43945239](/tcplclib_tc2_system/1033/Images/png/31352971__en-US__Web.png)

The resulting message box:

![59962836](/tcplclib_tc2_system/1033/Images/png/9007199286097163__Web.png)

The DINT value 4711 is inserted here into a message. The insertion point is marked by the %d characters in the format string.

**Example of calling the function in ST:**

```
PROGRAM MAIN  
VAR  
    rtMessageOutput: R_TRIG; (* Declaration *)  
    bFeedTooHigh: BOOL;  
    udiAdsLogRes: UDINT;  
END_VAR  
  
rtMessageOutput(CLK := bFeedTooHigh);  
IF rtMessageOutput.Q THEN   
    UdiAdsLogRes := ADSLOGDINT( msgCtrlMask := ADSLOG_MSGTYPE_HINT OR ADSLOG_MSGTYPE_MSGBOX,   
                    msgFmtStr := 'PLC Msg: Feed too high! Current feed: %d', dintArg:= 4711);  
END_IF
```

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
