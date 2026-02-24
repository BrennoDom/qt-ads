# FB_DALIV2xSteinelLiveLinkMotionSensor

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Third-party function blocks](ms-xhelp:///?Id=beckhoff-3be5-46f6-9609-796403dd277e)
5. [Steinel](ms-xhelp:///?Id=beckhoff-6cf7-4430-9fe8-10b84a51ebff)
6. FB\_DALIV2xSteinelLiveLinkMotionSensor

# FB\_DALIV2xSteinelLiveLinkMotionSensor

![9871675](/tcplclib_tc2_dali/1033/Images/gif/4528374539__Web.gif)

|  |  |
| --- | --- |
| 21736211 | This function block is used as an example and is not included in the library. The function block can be downloaded as an export file and imported into the desired project. Adjustments can be made as required. |

This function block evaluates the measured brightness and presence of the Steinel LiveLink DALI control unit. This function block can also be used to initialize the DALI control units.

The DALI control unit occupies a short address and contains 2 instances. Instance 1 contains the motion sensor, instance 0 the brightness sensor. The device does not fully comply with the IEC 62386 standard and uses a company-specific protocol instead.

A detected movement is sent as an event while the brightness is read out cyclically. Each instance can be decoded individually as required.

TwinCAT 3 PLCopenXML file download: [FB\_DALIV2xSteinelLiveLinkMotionSensor.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_dali/Resources/zip/18014403037897867.zip)

## VAR\_INPUT

```
bInitialize            : BOOL := FALSE;  
nAddr                  : BYTE;  
(* Occupancy Sensor Parameters *)  
bPIREnable             : BOOL := TRUE;  
nPIRMotion             : BYTE := 4;      (* 5 s + (nPIRMotion 5 s) *)  
nPIRRepeat             : BYTE := 6;      (* 5 s + (nPIRRepeat 5 s) *)  
nPIRVerificationLevel  : BYTE := 1;      (* standard *)  
nPIRDetectionRange     : BYTE := 255;    (*(only for HF sensors) 100 % *)  
(* Light Sensor Parameters *)  
bLSEnable              : BOOL := TRUE;  
tLSCycleTime           : TIME := T#1M;
```

**bInitialize:** The DALI controller is initialized via a positive edge at this input. The parameters are written to the DALI control unit, which must be accessible via the short address *nAddr*. The output *bInitializing* is TRUE during initialization.

**nAddr:** Short address of the DALI control unit.

**bPIREnable:** Parameter: If this input is TRUE, the motion sensor (instance 1) is enabled. The occupancy sensor is disabled by FALSE.

**nPIRMotion:** Parameter: Sets the value for the *Motion Timer*. If no movement is detected, the status of the motion sensor is not changed until after the *Motion Timer* has expired. The time is calculated based on the formula 5 s + nPIRMotion \* 5 s. This means that times of 5 s to 21 min 20 s are possible.

**nPIRRepeat:** Parameter: Sets the value for the *Repeat Timer*. The motion sensor status is retransmitted after the *Report Timer* has expired, even if the status has not changed. The time is calculated based on the formula 5 s + nPIRRepeat \* 5 s. This means that times of 5 s to 21 min 20 s are possible.

**nPIRVerificationLevel:** Parameter: The detection sensitivity can be adjusted (0: motion detection disabled, 1: very sensitive to 15: very insensitive).

**nPIRDetectionRange:** Parameter: If an HF sensor is used, the detection range can be set (0: 0% to 255: 100%).

**bLSEnable:** Parameter: If this input is TRUE, the brightness sensor (instance 0) is enabled. The brightness sensor is disabled by FALSE.

**tLSCycleTime:** Cycle time in which the current actual value of the brightness sensor is read out.

Further details on the parameters can be found in the IEC 62386 standard and the manufacturer's documentation.

## VAR\_OUTPUT

```
bInitializing     : BOOL;  
bError            : BOOL;  
nErrorId          : UDINT;  
nInputDeviceError : BYTE;  
(* Occupancy Sensor *)  
bPIROccupied      : BOOL;  
(* Light Sensor *)  
nActualLightLevel : UINT;
```

**bInitializing:** This output is TRUE during initialization.

**bError**: This output is switched to TRUE as soon as an **error** occurs during the execution of a command. The command-specific error code is contained in *nErrorId*.

**nErrorId**: Contains the command-specific error code of the most recently executed command. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

**nInputDeviceError:** The status of the DALI control unit (INPUT DEVICE ERROR) is queried before the initialization. 0 means no error. The individual error numbers are vendor-specific.

**bPIROccupied:** This output indicates the status of the motion sensor.

**nActualLightLevel:** This output indicates the actual value of the brightness sensor.

## VAR\_IN\_OUT

```
stCommandBuffer   : ST_DALIV2CommandBuffer;
```

**stCommandBuffer**: Reference to the internal structure for communication with the function block [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250) (KL6821).

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.4 | Tc2\_DALI from v3.6.2.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
