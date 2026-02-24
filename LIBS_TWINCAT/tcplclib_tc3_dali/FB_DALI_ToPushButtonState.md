# FB_DALI_ToPushButtonState

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Devices](ms-xhelp:///?Id=beckhoff-6e24-4037-9db1-b195b107840a)
5. FB\_DALI\_ToPushButtonState

# FB\_DALI\_ToPushButtonState

![8621060](/tcplclib_tc3_dali/1033/Images/png/10944339723__Web.png)

Determines the static state from the events of a button.

For correct evaluation, the events *Button Released* (Bit 0) and *Button Pressed* (Bit 1) must be activated via the event filter.

|  |  |
| --- | --- |
| 10480683 | Release only those events that you need for the application. If too many events are sent, this can have a negative effect on the behavior of the application. |

## VAR\_INPUT

```
nPushButtonEvent       : UINT;
```

**nPushButtonEvent:** This variable contains the individual events of the push button, which are represented by the respective bits.

| Bit | Description |
| --- | --- |
| 0 | Push button released. |
| 1 | Push button pressed. |
| 2 | Short keystroke. |
| 3 | Double keystroke. |
| 4 | Start long keystroke. |
| 5 | Repeat long keystroke. |
| 6 | Stop long keystroke. |
| 7 | Push button free again; was previously blocked. |
| 8 | Push button blocked. |

The function block [FB\_DALI\_ToPushButtonState](ms-xhelp:///?Id=beckhoff-c0d2-477c-96f3-465feb2dd845) can be used to convert the state of a push button into a BOOL variable.

## VAR\_OUTPUT

```
bPushButton    : BOOL;
```

**bPushButton:** This variable returns the static state of the button, which was determined on the basis of the individual events.

## Example

The example shows how the events of a 4-fold DALI push button are converted into four individual variables.

```
PROGRAM Demo_ST  
VAR  
  fbSwitchPanel         : FB_DALI_Lunatone_Cross_Switch(Communication.fbKL6821Communication);  
  bInitialize           : BOOL;  
  bError                : BOOL;  
  bInitializing         : BOOL;  
  aToPushButtonState    : ARRAY [1..4] OF FB_DALI_ToPushButtonState();  
  aPushButton           : ARRAY [1..4] OF BOOL;  
END_VAR
```

Program part in structured text:

```
fbSwitchPanel(    bInitialize := bInitialize,  
                  nShortAddress := 0,  
                  bInitializing  => bInitializing,  
                  bError => bError);  
aToPushButtonState[1](nPushButtonEvent := fbSwitchPanel.nPushButton1Event,  
                      bPushButton => aPushButton[1]);  
aToPushButtonState[2](nPushButtonEvent := fbSwitchPanel.nPushButton2Event,  
                      bPushButton => aPushButton[2]);  
aToPushButtonState[3](nPushButtonEvent := fbSwitchPanel.nPushButton3Event,  
                      bPushButton => aPushButton[3]);  
aToPushButtonState[4](nPushButtonEvent := fbSwitchPanel.nPushButton4Event,  
                      bPushButton => aPushButton[4]);
```

Program part in the Continuous Function Chart (CFC):

![27217289](/tcplclib_tc3_dali/1033/Images/png/10944342667__Web.png)

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.25 | Tc3\_DALI from v3.10.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
