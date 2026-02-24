# ADSLOGLREAL

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [ADS functions](ms-xhelp:///?Id=beckhoff-5576-4d9d-9f14-f989dcb02fd7)
4. ADSLOGLREAL

# ADSLOGLREAL

![2794612](/tcplclib_tc2_system/1033/Images/png/9007199286100363__Web.png)

This function issues when called a message box holding a specifiable text on the screen, and writes an entry into the system's log. In the text to be output, a LREAL value (floating point number) can be inserted at a point specified by the user. For this purpose the stored format string must contain the characters %f at the desired location. Always remember that here too, as illustrated in the example, the function must be called using edge-control (see also the note in the description of ADSLOGDINT). The return value contains the function error code, or, if successful, 0.

## FUNCTION ADSLOGLREAL : DINT

```
VAR_INPUT  
    msgCtrlMask   : DWORD;  
    msgFmtStr     : T_MaxString;  
    lrealArg      : LREAL;  
END_VAR
```

**msgCtrlMask**: Control mask which determines the type and effect of the message output. Listing of all the control masks for message output currently implemented as global constants in the library (see description of the function [ADSLOGDINT](ms-xhelp:///?Id=beckhoff-7cde-4c0c-bfd0-d945d7106339)).

**msgFmtStr**: Contains the message to be issued (type: [T\_MaxString](ms-xhelp:///?Id=beckhoff-77e0-4f6f-a54e-eec93d1cd558)). It can contain the formatting code %d for the output of a DINT value at any position.

**lrealArg**: Contains the numerical value to be inserted into the message.

**Example of calling the function in FBD:**

![25151514](/tcplclib_tc2_system/1033/Images/png/31362571__en-US__Web.png)

The resulting message box:

![25037038](/tcplclib_tc2_system/1033/Images/png/9007199286106763__Web.png)

Here the LREAL value 187.203045 is inserted into a message. The insertion point is marked by the %f characters in the format string. The number is truncated after the sixth decimal point during output.

**Example of calling the function in ST:**

```
PROGRAM MAIN  
VAR  
    rtMessageOutput: R_TRIG; (* Declaration *)  
    bTemperatureTooHigh: BOOL;  
    udiAdsLogRes: UDINT;  
END_VAR  
  
rtMessageOutput(CLK := bTemperatureTooHigh);  
IF rtMessageOutput.Q THEN   
    udiAdsLogRes := ADSLOGLREAL( msgCtrlMask := ADSLOG_MSGTYPE_HINT OR ADSLOG_MSGTYPE_MSGBOX, msgFmtStr := 'PLC Msg.: Max Temp. reached ! Temperature: %f', lrealArg := 187.203045);  
END_IF;
```

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
