# FB_BA_SeqCtrl

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# FB\_BA\_SeqCtrl

![36079911](/tcplclib_tc3_ba_common/1033/Images/gif/9007204100509963__Web.gif)

PID controller as part of a sequence.

## Functional description

The functionalities of this controller are identical to [FB\_BA\_PIDCtrl](ms-xhelp:///?Id=beckhoff-480e-47a5-877e-eb3ff0f703a7).

*udiOpMode* = 0 (upstream proportional component)

![56283746](/tcplclib_tc3_ba_common/1033/Images/gif/4936089483__en-US__Web.gif)

*udiOpMode* = 1 (parallel structure)

![36791668](/tcplclib_tc3_ba_common/1033/Images/gif/4936094219__en-US__Web.gif)

In addition the controller, if enabled by *bEn* = TRUE, is controlled via a higher level control function block [FB\_BA\_SeqLink](ms-xhelp:///?Id=beckhoff-d060-4ce8-9edc-114c51dff6a8).

The data exchange between the control function block [FB\_BA\_SeqLink](ms-xhelp:///?Id=beckhoff-d060-4ce8-9edc-114c51dff6a8) and the sequence controllers *FB\_BA\_SeqCtrl* takes place via the structure variable [stSeqLink](ms-xhelp:///?Id=beckhoff-a03c-4c29-895b-799bbd71e49e).

## Heating-cooling sequence

The controller sequence should be configured such that the sequence controller with lower ordinal number are used for heating and the ones with the higher number for cooling. Only one change is permitted:

* Sequence controller n (*udiMyNum*=n, *bActn*=TRUE)
* Sequence controller n+1 (*udiMyNum* = n+1, *bActn* = FALSE)

Exclusive programming of cooling and heating controllers is also possible.

Any parameterization that contradicts this convention is detected and indicated as an error at control function block [FB\_BA\_SeqLink](ms-xhelp:///?Id=beckhoff-d060-4ce8-9edc-114c51dff6a8).

## Controller output

The control function block [FB\_BA\_SeqLink](ms-xhelp:///?Id=beckhoff-d060-4ce8-9edc-114c51dff6a8) specifies which sequence controller is active. What is output at the respective control output *rY* is determined inside the individual sequence controllers. Each controller receives the information about the states of the other controllers via the in-out variable *stSeqLink* and evaluates four cases internally.

1. None of the sequence controllers is enabled, whether due to a missing enable signal (*bEn*) at the input or due to an error detected on the control function block [FB\_BA\_SeqLink](ms-xhelp:///?Id=beckhoff-d060-4ce8-9edc-114c51dff6a8)  
    -> The internal PID controllers are inactive and output 0.0 at the control output *rY*.
2. The sequence controller is enabled and has been set to active by the control function block [FB\_BA\_SeqLink](ms-xhelp:///?Id=beckhoff-d060-4ce8-9edc-114c51dff6a8).  
    -> The internal PID controller is active. Its output signal is output at the control output *rY*.
3. The sequence controller is enabled, but a sequence controller with a **higher** ordinal number has been set to active by the control function block [FB\_BA\_SeqLink](ms-xhelp:///?Id=beckhoff-d060-4ce8-9edc-114c51dff6a8)  
    -> The internal PID controller is inactive. If the sequence controller is in heating mode (*bActn=*FALSE), it will output its minimum value *rYMin* at the control output *rY*. Conversely, if it is in cooling mode (*bActn =* TRUE), then it outputs the maximum value *rYM*ax at the control output *rY*.
4. The sequence controller is enabled, but a sequence controller with a **lower** ordinal number has been set to active by the control function block [FB\_BA\_SeqLink](ms-xhelp:///?Id=beckhoff-d060-4ce8-9edc-114c51dff6a8)  
    -> The internal PID controller is inactive. If the sequence controller is in heating mode (*bActn=*FALSE), it will output its maximum value *rYMax* at the control output *rY*. If it is in cooling mode (*bActn=T*RUE), it will output its minimum value *rYMin* at the control output *rY*.

## Synchronization

If a sequence controller is activated by the higher-level controller, this always results in synchronization, i.e. the controller starts with a fixed value at the output *rY*. 3 cases are distinguished:

1. The entire sequence control was switched on via the input *bEn* of the higher-level controller [FB\_BA\_SeqLink](ms-xhelp:///?Id=beckhoff-d060-4ce8-9edc-114c51dff6a8). The controller with the ordinal number *udiSttCtrl* at the input of [FB\_BA\_SeqLink](ms-xhelp:///?Id=beckhoff-d060-4ce8-9edc-114c51dff6a8) is the start controller.  
    -> The sequence controller is synchronized with the value, which is entered at its input *rYSeqInit*.
2. The sequence controller, which has just has been activated, had a higher ordinal number than the "previous" one  
    -> If the sequence controller is in heating mode (*bActn =* FALSE), then it is synchronized with its minimum value *rYMin*. If it is in cooling mode (*bActn=*TRUE), the synchronization value is its maximum value *rYM*ax.
3. The sequence controller, which has just has been activated, had a lower ordinal number than the "previous" one  
    -> If the sequence controller is in heating mode (*bActn =* FALSE), then it is synchronized with its maximum value *rYMax*. If it is in cooling mode (*bActn=*TRUE), the synchronization value is its minimum value *rYMin*.

Each sequence controller can also be synchronized by specifying a value *rSync* and activating *bSync*, if it has just been activated by the higher-level controller. A constant TRUE signal at the input *bSync* (e.g. accidental) is internally intercepted through edge formation, so that obstruction of the synchronization described above on activation is avoided.

## Start-up behavior

In order to enable "sensible" adjustment of the entire control sequence, the start controller is maintained in active state as a minimum for the time *udiIniSwiOvrDly\_sec* [s], which is entered at the function block [FB\_BA\_SeqLink](ms-xhelp:///?Id=beckhoff-d060-4ce8-9edc-114c51dff6a8). During this time, no switching takes place to another controller of this sequence.  
The output *rY* of the start controller is synchronized **once** to its value *rYSeqInit*.

## VAR\_INPUT

```
bEn            : BOOL;  
rW             : REAL;  
rX             : REAL;  
udiOpMode      : UDINT;  
bActn          : BOOL;  
rKp            : REAL;  
udiTn_ms       : UDINT;  
udiTv_ms       : UDINT;  
udiTd_ms       : UDINT;  
rYMax          : REAL;  
rYMin          : REAL;  
rNZ            : REAL;  
udiCycCl       : UDINT;  
bSync          : BOOL;  
rSync          : REAL;  
rYSeqInit      : REAL;  
udiMyNum       : UDINT;
```

**bEn:** Activation of the sequence controller

**rW:** Set value

**rX:** Actual value

**udiOpMode:** *udiOpMode*=0: Controller with upstream proportional component, *udiOpMode* = 1: Controller in parallel structure. The values are limited internally to 0 and 1.

**bActn:** Direction of action reversal of the controller. For heating/cooling operation: *bActn*=FALSE corresponds to heating mode, *bActn*=TRUE corresponds to cooling mode.

**rKp:** Controller gain. Only affects the proportional component. Internally limited to a minimum value of 0.

**udiTn\_ms:** Integral action time of the I component [ms]. A zero value at this parameter disables the I component. Internally limited to a minimum value of 0.

**udiTv\_ms:** Rate time of the D component [ms]. A zero value at this parameter disables the D component. Internally limited to a minimum value of 0.

**udiTd\_ms:** Damping time of the D component [s]. Internally limited to a minimum value of 0.

**rYMax:** Upper controller output limit [%]. Selectable range: 0..100%.

**rYMin:** Lower controller output limit [%]. Selectable range: 0..100%. The value *lrMin* is upwardly limited by *lrYMax*.

**rNZ:** neutral zone (see Deadband diagram). Internally limited to a minimum value of 0. Mode of action is same as [FB\_BA\_PID\_Ctrl](ms-xhelp:///?Id=beckhoff-480e-47a5-877e-eb3ff0f703a7).

**udiCycCl:** Call cycle of the function block as a multiple of the cycle time. Internally limited to a minimum value of 1.  
Example: *tTaskCycleTime* = 20 ms, *udiCycCl* = 10 -> the control algorithm is called every 200 ms. Thus the outputs are also updated only every 200 ms.

**bSync / rSync:** Synchronization command: Set output value *rY* to *rSync.* The value *rSync* is limited internally to values ranging from *rYMin* to *rYMax*.

**rYSeqInit:** Starting value of the controller after restart of the whole control sequence.

**udiMyNum:** Ordinal number of the sequence controller. Internally limited to values ranging from 0 to *gBA\_cMaxSeqCtrl*.

## VAR\_OUTPUT

```
rY        : REAL;  
rE        : REAL;  
bErr      : BOOL;  
sErrDescr : T_MAXSTRING;
```

**rY:** Control value. Section: 0..100%, unless limited further by *rYMin* and *rYMax.*

**rE:** Control deviation (The calculation depends on the [direction of action](ms-xhelp:///?Id=beckhoff-480e-47a5-877e-eb3ff0f703a7)).

**bErr:** This output is switched to TRUE if the parameters entered are erroneous.

**sErrDescr:** Contains the error description.

| Error description |
| --- |
| 01: Error: The controller ordinal number *udiMyNum* has been assigned twice |
| 02: Error: The controller ordinal number *udiMyNum* of the enabled controller is 0. That is only allowed for controllers that are not in use and thus not enabled. |

## VAR\_IN\_OUT

```
stSeqLink : ST_BA_SeqLink;
```

**stSeqLink:** Data and command structure (see [ST\_BA\_SeqLink / ST\_BA\_SeqLinkData](ms-xhelp:///?Id=beckhoff-a03c-4c29-895b-799bbd71e49e)) between the individual sequence controllers and the control function block [FB\_BA\_SeqLink](ms-xhelp:///?Id=beckhoff-d060-4ce8-9edc-114c51dff6a8).

|  |  |
| --- | --- |
| 62689558 | If several sequence controllers have the same number (*diMyNum*), this is detected and output as an error at the sequence controller and at the control function block [FB\_BA\_SeqLink](ms-xhelp:///?Id=beckhoff-d060-4ce8-9edc-114c51dff6a8). |

## Requirements

| Development environment | Required library | Necessary function |
| --- | --- | --- |
| TwinCAT3.1 4022.16 | Tc3Building Automation Common from V1.0.4.3 | TF8040 | TwinCAT Building Automation from V1.0.5.0 |
