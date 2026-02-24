# FB_CXGetTextDisplayUSB

## Library
tcplclib_tc2_systemcx

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
2. [Function Blocks](ms-xhelp:///?Id=beckhoff-ec9d-42ff-9fdd-c53aca476e55)
3. FB\_CXGetTextDisplayUSB

# FB\_CXGetTextDisplayUSB

The function block is used for the CX2100 and for the EL6090 terminal. When the function block is called, only the matching NetID and port number for the respective device has to be allocated.

|  | nPort: | sNetID |
| --- | --- | --- |
| CX2100 | Is displayed in TwinCAT on the ESB device tab. | Is the NetID of the PC or is left blank (‘ ‘). |
| EL6090 | Is the EtherCAT address of the terminal | Is the EtherCAT address of the EtherCAT master. |

![53720453](/tcplclib_tc2_systemcx/1033/Images/png/9007201154665483__Web.png)

The function block FB\_CXGetTextDisplayUSB is used to read the lines on the display. In addition, the cursor status is read, i.e. cursor switched on or off, or is flashing. The function block also indicates whether the backlight is switched on or off.

## VAR\_INPUT

```
VAR_INPUT  
     bExecute      : BOOL;  
     sNetID        : T_AmsNetID;  
     nPort         : T_AmsPort;  
     eMode         : E_CX2100_DisplayModesRd;  
END_VAR
```

**bExecute:** The command is executed with a rising edge.

**sNetID:** AMSNetID of the device.

**nPort:** AMSPort of the device.

**eMode:** Mode switching.

## VAR\_OUTPUT

```
VAR_OUTPUT  
     bBusy         : BOOL;  
     bError        : BOOL;  
     nErrorID      : UDINT;  
     sLine1        : STRING(80);  
     sLine2        : STRING(80);  
     nCursorPosX   : USINT;  
     nCursorPosY   : USINT;  
     nCursorMode   : USINT;  
     nBacklight    : USINT;  
END_VAR
```

**bBusy:** Command is being transmitted via ADS. No new command will be accepted as long as "bBusy" remains TRUE.

**bError:** Becomes TRUE, as soon as an error occurs.

**nErrorID:** Returns the error number when the bError output is set.

**sLine1:** This string is read with the corresponding command.

**sLine2:** This string is read with the corresponding command.

**nCursorPosX:** Cursor position on the X axis

**nCursorPosY:** Cursor position on the Y axis

**nCursorMode:** Mode of the cursor

**nBacklight:** Backlight

**E\_CX2100\_DisplayModesRd:**

```
E_CX2100_DisplayModesRd : (  
     eCX2100_DisplayNoActionRd := 0,  
     eCX2100_ReadCursorInfo,  
     eCX2100_ReadBackLight,  
     eCX2100_ReadLine1,  
     eCX2100_ReadLine2,  
     eCX2100_ReadLines  
);
```

**eCX2100\_DisplayNoActionRd:** No action.

**eCX2100\_ReadCursorInfo:** Read values via the cursor.

**eCX2100\_ReadBackLight:** Read backlight values.

**eCX2100\_ReadLine1:** Read values from the first line.

**eCX2100\_ReadLine2:** Read values from the second line.

**eCX2100\_ReadLines:** Read values from lines.

## Requirements when using the CX2100

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 | CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7: TC RT x86, TC/BSD: TC RT x64) | Tc2\_SystemCX |

## Requirements when using the EL6090

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 | PC or CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7: TC RT x86, WEC7: TC CE7 ARMV7, TC/BSD: TC RT x64, TC OS ARMT2) | Tc2\_SystemCX |

[TwinCAT 3 | PLC Library: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
