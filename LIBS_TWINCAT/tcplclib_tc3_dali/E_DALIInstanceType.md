# E_DALIInstanceType

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [DUTs](ms-xhelp:///?Id=beckhoff-e84a-422d-b94e-99adcaade658)
4. [Enumerations](ms-xhelp:///?Id=beckhoff-c968-4aa7-be35-e6241e64c6c6)
5. E\_DALIInstanceType

# E\_DALIInstanceType

```
TYPE E_DALIInstanceType :  
(  
  IT00GenericInstance                        := 0,  
  IT01PushButton                             := 1,  
  IT02AbsoluteInputDevice                    := 2,  
  IT03OccupancySensor                        := 3,  
  IT04LightSensor                            := 4,  
  IT05ColourSensor                           := 5,  
  IT06GeneralPurposeSensor                   := 6,  
  IT32InputControlDeviceFeedback             := 32,  
  IT33ManualConfiguration                    := 33,  
  IT51LuminaireMountedControlDevice          := 51,  
  Unknown                                    := 255  
) BYTE := Unknown;  
END_TYPE
```

**IT00GenericInstance:** Part 103: Control device (instance type 0)

**IT01PushButton:** Part 301: Push button (instance type 1)

**IT02AbsoluteInputDevice:** Part 302: Absolute input device (instance type 2)

**IT03OccupancySensor** Part 303: Occupancy sensor (instance type 3)

**IT04LightSensor:** Part 304: Light sensor (instance type 4)

**IT05ColourSensor:** Part 305: Color sensor (instance type 5)

**IT06GeneralPurposeSensor:** Part 306: Universal sensor (instance type 6)

**IT32InputControlDeviceFeedback:** Part 332: Feedback for input devices (instance type 32)

**IT33ManualConfiguration:** Part 333: Manual configuration (instance type 33)

**IT51LuminaireMountedControlDevice:** Part 351: Control device integrated in the luminaire (instance type 51)

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.11 | Tc3\_DALI from v3.5.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
