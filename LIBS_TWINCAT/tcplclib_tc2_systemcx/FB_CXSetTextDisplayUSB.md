# FB_CXSetTextDisplayUSB

## Library
tcplclib_tc2_systemcx

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
2. [Function Blocks](ms-xhelp:///?Id=beckhoff-ec9d-42ff-9fdd-c53aca476e55)
3. FB\_CXSetTextDisplayUSB

# FB\_CXSetTextDisplayUSB

The function block is used for the CX2100 and for the EL6090 terminal. When the function block is called, only the matching NetID and port number for the respective device has to be allocated.

|  | nPort: | sNetID |
| --- | --- | --- |
| CX2100 | Is displayed in TwinCAT on the ESB device tab. | Is the NetID of the PC or is left blank (‘ ‘). |
| EL6090 | Is the EtherCAT address of the terminal | Is the EtherCAT address of the EtherCAT master. |

![5968939](/tcplclib_tc2_systemcx/1033/Images/png/9007201154667915__Web.png)

The function block FB\_CXSetTextDisplayUSB is used to write and delete messages on the two-line display. The cursor is controlled on the display by switching it on and off or by making it flash. The function block is also used to switch the backlight on or off.

## VAR\_INPUT

```
VAR_INPUT  
     bExecute     : BOOL;  
     sNetID       : T_AmsNetID;  
     nPort        : T_AmsPort;  
     eMode        : E_CX2100_DisplayModesWr;  
     sLine1       : STRING(80);  
     sLine2       : STRING(80);  
     nCursorPosX  : USINT;  
     nCursorPosy  : USINT;  
END_VAR
```

**bExecute:** The command is executed with the rising edge.

**sNetID:** AMSNetID of the device.

**nPort:** AmsPort of the device.

**eMode:** Mode switching.

**sLine1:** String with 80 characters. This string is displayed with the corresponding command in the first line. For strings with more than 16 characters, the text is displayed as scrolling text.

**sLine2:** String with 80 characters. This string is displayed with the corresponding command in the second line. For strings with more than 16 characters, the text is displayed as scrolling text.

**nCursorPosX:** Cursor position on the X axis. The string is written from this position in the display.

**nCursorPosY:** Cursor position on the Y axis. The string is written from this position in the display.

## VAR\_OUTPUT

```
VAR_OUTPUT  
     bBusy        : BOOL;  
     bError       : BOOL;  
     nErrorID     : UDINT;  
END_VAR
```

**bBusy:** The command is in the process of being transmitted by ADS. No new command will be accepted as long as "bBusy" remains TRUE.

**bError:** Becomes TRUE, as soon as an error occurs.

**nErrorID:** Supplies the error number when the bError output is set.

**E\_CX2100\_DisplayModesWr:**

```
E_CX2100_DisplayModesWr : (  
     eCX2100_DisplayNoActionWr := 0,  
     eCX2100_CursorOn,  
     eCX2100_CursorOff,  
     eCX2100_CursorBlinkOn,  
     eCX2100_CursorBlinkOff,  
     eCX2100_BackLightOn,  
     eCX2100_BackLightOff,  
     eCX2100_ClearDisplay,  
     eCX2100_WriteLine1,  
     eCX2100_WriteLine2,  
     eCX2100_WriteLines,  
     eCX2100_CursorPosX,  
     eCX2100_CursorPosY,  
     eCX2100_CursorPosXY  
;
```

**eCX2100\_DisplayNoActionWr:** No action.

**eCX2100\_CursorOn:** Switch on the cursor.

**eCX2100\_CursorOff:** Switch off the cursor.

**eCX2100\_CursorBlinkOn:** Switching on the cursor blinking.

**eCX2100\_CursorBlinkOff:** Switch off the cursor blinking.

**eCX2100\_BackLightOn:** Switch on the backlight.

**eCX2100\_BackLightOff:** Switch off the backlight.

**eCX2100\_ClearDisplay:** Clear display.

**eCX2100\_WriteLine1:** Write the first line.

**eCX2100\_WriteLine2:** Write the second line.

**eCX2100\_WriteLines:** Write lines.

**eCX2100\_CursorPosX:** Cursor position on the X axis.

**eCX2100\_CursorPosY:** Cursor position on the Y axis.

**eCX2100\_CursorPosXY:** Cursor position on the XY axis.

## Requirements when using the EL6090

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 | PC or CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7: TC RT x86, WEC7: TC CE7 ARMV7, TC/BSD: TC RT x64, TC OS ARMT2) | Tc2\_SystemCX |

## Requirements when using the CX2100

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 | CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7: TC RT x86, TC/BSD: TC RT x64) | Tc2\_SystemCX |

[TwinCAT 3 | PLC Library: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
