# FB_BA_SeqLink

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# FB\_BA\_SeqLink

![27335113](/tcplclib_tc3_ba_common/1033/Images/gif/9007204100880523__Web.gif)

This function block represents the higher-level control unit, which specifies which sequence controller is currently active.

The data exchange between the control function block FB\_BA\_SeqLink and the sequence controllers [FB\_BA\_SeqCtrl](ms-xhelp:///?Id=beckhoff-5f1e-4dd3-b036-9ec1a0438ff2) takes place via the structure variable [stSeqLink](ms-xhelp:///?Id=beckhoff-a03c-4c29-895b-799bbd71e49e).

## Functional description

## Start-up behavior

A TRUE signal at input *bEn* activates the entire sequence control. The function block will initially activate the sequence controller named on *udiSttCtrl*. All other sequence controller base their output value on the ranking of the active controller, see [FB\_BA\_SeqCtrl](ms-xhelp:///?Id=beckhoff-5f1e-4dd3-b036-9ec1a0438ff2). The start controller will be set once to its value *rSync* at the start of the sequence.  
In order to enable "sensible" adjustment of the entire control sequence, the start controller is maintained in active state as a minimum for the time *udiIniSwiOvrDly\_sec* [s]. During this time, no switching takes place to another controller of this sequence.

## Switching behavior

When the sequence controller reaches its maximum or minimum value, the next controller in the sequence is activated, depending on the controller direction of action, if the actual value is below or above the set value of the next controller.  
4 cases are distinguished:

* The still active controller has direct direction of action (cooling) and is at its maximum value: The next higher controller in the sequence will be selected if the actual value exceeds the set value for this controller.
* The still active controller has direct direction of action (cooling) and is at its minimum value: The next lower controller in the sequence is then selected, if the actual value falls below the set value for this controller.
* The still active controller has indirect direction of action (heating) and is at its maximum value: The next lower controller in the sequence is then selected, if the actual value falls below the set value for this controller.
* The still active controller has indirect direction of action (heating) and is at its minimum value: The next higher controller in the sequence will be selected if the actual value exceeds the set value for this controller.

## Switch-off behavior

If the enable status is removed from a controller within the sequence or if it develops a fault, it is no longer available for the whole sequence.  
If this is not the previously active controller, a temperature change may occur, depending on which control value this controller has output, which is compensated by the controller sequence, if possible.  
However, if it is the active controller whose enable is canceled, the next "sensible" controller must be selected. The sequence link function block uses the following rules:

* The deactivated controller had direct direction of action (cooling)
* There is an operational controller with a higher ordinal number → switch to the next higher operational controller.   
  Only an operational controller with lower ordinal number is available → switch to the next lower operational controller.   
  No operational controller is available → fault message
* The deactivated controller had indirect direction of action (heating)
* An operational controller with lower ordinal number is available → switch to the next lower operational controller.   
  There is an operational controller with a higher ordinal number → switch to the next higher operational controller.   
  No operational controller is available → fault message

## Sequence behavior

If a controller is added to the sequence, it is in any case initially inactive and will output its minimum or maximum value, depending on the direction of action and positioning within the sequence order. The resulting temperature change is compensated by the controller sequence, if possible.

## VAR\_INPUT

```
bEn                 : BOOL;  
udiSttCtrl          : UDINT;  
udiIniSwiOvrDly_sec : UDINT;  
rX                  : REAL
```

**bEn:** Activation of the sequence controller.

**udiSttCtrl:** Ordinal number of the sequence controller that should be the start controller upon general activation. Internally limited to values ranging from 0 to *gBA\_cMaxSeqCtrl*.

**udiIniSwiOvrDly\_sec:** The first controller remains active for at least this time [s] in the sequence before other criteria (see [FB\_BA\_SeqLink](ms-xhelp:///?Id=beckhoff-d060-4ce8-9edc-114c51dff6a8)) allow switching to a different controller.

**rX:** Actual value of the control.

## VAR\_OUTPUT

```
udiCurCtrl                : UDINT;  
bSeqActv                  : BOOL;  
bNotRead                  : BOOL;  
bNoneOp                   : BOOL;  
udiRemTiIniSwiOvrDly_sec  : UDINT;  
bErr                      : BOOL;  
sErrDescr                 : T_MAXSTRING;
```

**udiCurCtrl:** Ordinal number of the currently active sequence controller. If no controller is active, 0 is output here.

**bSeqActv:** The sequence function block is enabled (*bEn*) and has no error resulting in switch-off, see error detection.

**bNotRead:** Each sequence controller transfers data to the control function block via the structure *stSeqLink*. This output is TRUE, as long as no data were transmitted - this is the case when the PLC is switched on.

**bNoneOp:** This output is switched to TRUE, if none of the sequence controller is enabled (*bEn*=TRUE).

**udiRemTiIniSwiOvrDly\_sec:** Remaining initialization time [s] before switching for the first time (see [FB\_BA\_SeqLink](ms-xhelp:///?Id=beckhoff-d060-4ce8-9edc-114c51dff6a8)).

**bErr:** This output is switched to TRUE if the parameters entered are erroneous. This function block may not suspend its execution in the event of an error, see error detection.

**sErrDescr:** Contains the error description.

| Error description |
| --- |
| 01: Error: The sequence link has been informed that the controller ordinal number *udiMyNum* has been assigned twice. |
| 02: Warning: Direction of action changed twice in the controller sequence. |
| 03: Warning: In the controller sequence, a controller with a higher ordinal number has a lower set value than its "predecessor". No correction takes place; the controller sequence runs with the parameters that were entered. |
| 04: Warning: The sequence controller, which is defined as start controller (*udiSttCtrl*) is not parameterized at all, i.e. it is not present. The controller with the lowest ordinal number is used as start controller. |
| 05: Warning: The ordinal number of the start controller is higher than the maximum permitted number of controllers or zero. The controller with the lowest ordinal number is used as start controller. |
| 06: Warning: The sequence controller, which is defined as start controller (*udiSttCtrl*) is not enabled (present). The controller with the lowest ordinal number is used as start controller. |

Only the first error triggers a fault in the sequence link function block and blocks its execution (bSeqActv = FALSE). All associated controllers are then no longer active, and all controllers issue the control value "0". The function block is not active:

## VAR\_IN\_OUT

```
stSeqLink : ST_BA_SeqLink;
```

**stSeqLink:** Data and command structure (see [ST\_BA\_SeqLink / ST\_BA\_SeqLinkData](ms-xhelp:///?Id=beckhoff-a03c-4c29-895b-799bbd71e49e)) between the individual sequence controllers and the control function block FB\_BA\_SeqLink. This structure is used by the sequence link function block to receive all relevant sequence controller data and at the same time to notify the controllers which is the active one.

|  |  |
| --- | --- |
| 44689431 | If several sequence controllers have the same number (*udiMyNum*), this is detected and output as an error at the sequence controller and at the control function block. |

## Requirements

| Development environment | Required library | Necessary function |
| --- | --- | --- |
| TwinCAT3.1 4022.16 | Tc3Building Automation Common from V1.0.4.3 | TF8040 | TwinCAT Building Automation from V1.0.5.0 |
