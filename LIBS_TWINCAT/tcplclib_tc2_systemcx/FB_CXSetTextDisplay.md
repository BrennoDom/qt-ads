# FB_CXSetTextDisplay

## Library
tcplclib_tc2_systemcx

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
2. [Function Blocks](ms-xhelp:///?Id=beckhoff-ec9d-42ff-9fdd-c53aca476e55)
3. FB\_CXSetTextDisplay

# FB\_CXSetTextDisplay

![663215](/tcplclib_tc2_systemcx/1033/Images/png/9007199440653963__Web.png)

The functionblock FB\_CXSetTextDisplay can be used to send text messages to the two line display of the CX1100.

## VAR\_INPUT

```
VAR_INPUT  
    bExecute   : BOOL;  
    nDevID     : UDINT;  
    nMode      : E_CX1100_DisplayModes;  
    stLine     : STRING(20);  
    nCursorPos : DWORD;  
END_VAR
```

**bExecute**: Command is executed with rising edge.

**nDevID**: Device ID of the CX1100-Device.

**nMode**: Modeswitch (see Enumeration)

**stLine**: String with 20 characters. This String is displayed with the appropriate command.

**nCursorPos**: Cursor position. The string is being written beginning from this position.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy    : BOOL;  
    bErr     : BOOL;  
    nErrorID : UDINT;  
END_VAR
```

**bBusy** : Command is being transported via ADS. bBusy remains TRUE, while no new command is accepted.

**bErr** : gets TRUE, with any error.

**nErrorID** : contains the error id if bErr is TRUE.

**E\_CX1000\_DisplayModes** :

```
E_CX1000_DisplayModes : (  
 e_CX1100_DisplayNoAction := 0,  
 e_CX1100_DisplayOn := 1,  
 e_CX1100_DisplayOff,  
 e_CX1100_CursorOn,  
 e_CX1100_CursorOff,  
 e_CX1100_CursorBlinkOn,  
 e_CX1100_CursorBlinkOff,  
 e_CX1100_BackLightOn,  
 e_CX1100_BackLightOff,  
 e_CX1100_ClearDisplay,  
 e_CX1100_WriteLine1,  
 e_CX1100_WriteLine2  
); 
```

**e\_CX1000\_DisplayNoAction** : No Action.

**e\_CX1000\_DisplayOn** : Switches display on.

**e\_CX1000\_DisplayOff** : Switches display off.

**e\_CX1000\_CursorOn** : Switches cursor on.

**e\_CX1000\_CursorOff** : Switches cursor off.

**e\_CX1000\_CursorBlinkOn** : Switches blinking of cursor on.

**e\_CX1000\_CursorBlinkOff** : Switches blinking of cursor off.

**e\_CX1000\_BackLightOn** : Switches background light on.

**e\_CX1000\_BackLightOff** : Switches background light off.

**e\_CX1000\_ClearDisplay** : Clears display.

**e\_CX1000\_WriteLine1** : Write line 1.

**e\_CX1000\_WriteLine2** : Write line 2.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | CX (x86) | Tc2\_SystemCX |

[TwinCAT 3 | PLC Library: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
