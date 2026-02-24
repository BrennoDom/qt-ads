# FB_TcTouchLock_AcquireFocus

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [TcTouchLock](ms-xhelp:///?Id=beckhoff-9537-4550-ae1d-cc57eb7a0a4f)
4. FB\_TcTouchLock\_AcquireFocus

# FB\_TcTouchLock\_AcquireFocus

![37966223](/tcplclib_tc2_iofunctions/1033/Images/jpg/6823088011__Web.jpg)

The function block FB\_TcTouchLock\_AcquireFocus is used to avoid simultaneous inputs via several multi-touch Control Panels connected to an IPC, which would be disruptive. To this end, the focus is placed on one of the connected Control Panels, while inputs from all other connected Control Panels are blocked. The function block FB\_TcTouchLock\_AcquireFocus can be used to request and release the focus.

If the focus is requested from a multi-touch Control Panel when another multi-touch Control Panel currently has the focus, the focus must first be released by this Panel. Once the release has taken place, the focus is automatically set to the device that is waiting for it.

The multi-touch Control Panels that are accessed by the function block must first be configured using the command line application TcTouchLockService.exe. A unique identification number must be assigned to each device.

## VAR\_INPUT

```
VAR_INPUT  
    bEnable    : BOOL;  
    sSetID     : STRING(32);  
    tLEDTime   : TIME := 200;  
END_VAR
```

**bEnable:** TRUE = request focus, FALSE = release focus

**sSetID:** ID of the device

**tLEDTime**: The output LED flashes at the specified interval (100 ms – 1 s) while the focus is requested

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bAcquired  : BOOL := FALSE;(* Focus status information *)  
    bLED       : BOOL := FALSE;(* LED control output *)  
    bBusy      : BOOL;(* TRUE => function in progress *)  
    bError:    : BOOL;(* Error flag *)  
    nErrID     : UDINT;(* Error code *)  
END_VAR
```

**bAcquired:** TRUE if the client has the focus; FALSE if the client loses the focus.

**bLED:** This output has the following meaning, depending on the mode:

| Mode | Meaning |
| --- | --- |
| Constant TRUE | The Panel has the focus |
| Constant FALSE | The Panel does not have the focus |
| Toggeles | The Panel is waiting for the focus |

**bBusy**: TRUE, as long as the function block is active.

**bError:** TRUE if an ADS error occurs during transmission of the command. The bBusy output is reset beforehand.

**nErrId**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-721e-4655-8e94-3548ed43349a) or the command-specific error code (table) when the *bError* output is set.

| Error Codes | Error description |
| --- | --- |
| 0x0000 | No error |
| 0x0006 | Target port not found |

**Sample: Control of touch focus via special key**

Manual setting of the focus can be controlled via a special key on the Panel, for example. Since it must be possible to request the focus via the touchscreen when the input is locked, an input option outside the lockable touchscreen must be provided. The special key is linked to the corresponding input variable in the PLC program through the TwinCAT System Manager. One FB\_TcTouchLock\_AquireFocus instance is created per Panel and configured with the Panel ID. After pressing the special key on a Panel, the function block R\_TRIG detects the rising edge, and the PLC program tries to set the touch focus via the corresponding FB\_TcTouchLock\_AquireFocus instance. The function block can also control an output (e.g. an LED), which signals whether the touch focus has been set successfully or whether an attempt is still being made to obtain the focus. Pressing the special key again resets the touch focus, allowing the touch focus to be set to another Panel.

![6151694](/tcplclib_tc2_iofunctions/1033/Images/jpg/6853873547__Web.jpg)

For two Panels the PLC program looks like this:

```
PROGRAM MAIN  
VAR   
    button1 AT%IX0.0 : BOOL;   
    button2 AT%IX0.1 : BOOL;   
  
    led1 AT%QX0.0 : BOOL;   
    led2 AT%QX0.1 : BOOL;   
  
    fbPanel1 : FB_TcTouchLock_AcquireFocus := ( sSetID := 'A' );   
    fbPanel2 : FB_TcTouchLock_AcquireFocus := ( sSetID := 'B' );   
  
    trigger1 : R_TRIG;   
    trigger2 : R_TRIG;   
END_VAR
```

```
(* Panel 1 *)  
trigger1( CLK := button1 );   
IF trigger1.Q THEN  
fbPanel1.bEnable := NOT fbPanel1.bEnable;   
END_IF  
fbPanel1(bLED=>LED1);   
  
(* Panel 2 *)  
trigger2( CLK := button2 );   
IF trigger2.Q THEN  
fbPanel2.bEnable := NOT fbPanel2.bEnable;   
END_IF  
fbPanel2(bLED=>LED2 );
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1. >= 4022.31 | PC or CX (x86, x64) | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
