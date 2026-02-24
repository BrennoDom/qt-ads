# FB_DALIV2xOsramProfSensorCoupler

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Third-party function blocks](ms-xhelp:///?Id=beckhoff-3be5-46f6-9609-796403dd277e)
5. [Osram](ms-xhelp:///?Id=beckhoff-fa65-48df-983a-fc5ad4abfc00)
6. FB\_DALIV2xOsramProfSensorCoupler

# FB\_DALIV2xOsramProfSensorCoupler

![43556055](/tcplclib_tc2_dali/1033/Images/gif/4528358539__Web.gif)

|  |  |
| --- | --- |
| 56460178 | This function block is used as an example and is not included in the library. The function block can be downloaded as an export file and imported into the desired project. Adjustments can be made as required. |

This function block evaluates the measured brightness and presence of the Osram DALI Professional Sensor Coupler. This function block can also be used to initialize the DALI control units.

The motion sensor and the brightness sensor have separate short addresses. The DALI control unit thus occupies two short addresses. The device does not fully comply with the IEC 62386 standard and uses a company-specific protocol instead.

A detected movement is sent as an event while the brightness is read out cyclically.

TwinCAT 3 PLCopenXML file download: [FB\_DALIV2xOsramProfSensorCoupler.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_dali/Resources/zip/9007203783154699.zip)

## VAR\_INPUT

```
bInitialize       : BOOL := FALSE;  
(* Occupancy Sensor Parameters *)  
nPIRAddr          : BYTE;  
tPIRBlankingTime  : TIME := T#1M;  
(* Light Sensor Parameters *)  
nLSAddr           : BYTE;  
tLSCycleTime      : TIME := T#1M;
```

**bInitialize:** The DALI controller is initialized via a positive edge at this input. The parameters are written to the DALI control unit, which must be accessible via the short addresses *nPIRAddr* and *nLSAddr*. The output *bInitializing* is TRUE during initialization.

**nPIRAddr:** Short address of the DALI control unit for the motion sensor.

**tPIRBlankingTime:** Parameter: Once the status of the motion sensor was sent, no further changes are sent for this time. The unit is 1 s. This means that times of up to 4 min 15 s (value 255) are possible.

**nLSAddr:** Short address of the DALI control unit for the brightness sensor.

**tLSCycleTime**: Cycle time in which the current actual value of the brightness sensor is read out.

Further details about the parameters can be found in the manufacturer's documentation.

## VAR\_OUTPUT

```
bInitializing     : BOOL;  
bError            : BOOL;  
nErrorId          : UDINT;  
(* Occupancy Sensor *)  
nPIRStatus        : BYTE;  
bPIROccupied      : BOOL;  
(* Light Level *)  
nLSStatus         : BYTE;  
nActualLightLevel : WORD;
```

**bInitializing:** This output is TRUE during initialization.

**bError**: This output is switched to TRUE as soon as an **error** occurs during the execution of a command. The command-specific error code is contained in *nErrorId*.

**nErrorId**: Contains the command-specific error code of the most recently executed command. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

**nPIRStatus:** Before the initialization, the status of the DALI control unit for the motion sensor is queried and output at this output.

**bPIROccupied:** This output indicates the actual value of the motion sensor.

**nLSStatus:** Before the initialization, the status of the DALI controller for the brightness sensor is queried and output at this output.

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
