# ST_GENIbusInData

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# ST\_GENIbusInData

Structure for linking the input image of the process variables. There is a choice of four different possible structures, of which finally only one is to be linked:

```
TYPE ST_GENIbusInData :  
STRUCT  
  stKL6DeviceIn5B  : ST_GENIbusKL6DeviceIn5B;  
  stKL6DeviceIn22B : ST_GENIbusKL6DeviceIn22B;  
  stEL6DeviceIn22B : ST_GENIbusEL6DeviceIn22B;  
  stPcComDeviceIn  : ST_GENIbusPcComDeviceIn64B;  
END_STRUCT  
END_TYPE
```

**stKL6DeviceIn5B:**  input process image of a 5-byte data terminal with standard communication bus, e.g. KL6021 (see [ST\_GENIbusKL6DeviceIn5B](ms-xhelp:///?Id=beckhoff-f0ff-47ad-9d98-ef3f31eb3971)).

**stKL6DeviceIn22B:**  input process image of a 22-byte data terminal with standard communication bus, e.g. KL6041 (see [ST\_GENIbusKL6DeviceIn22B](ms-xhelp:///?Id=beckhoff-1b75-45ad-b480-a9f931331f5e)).

**stEL6DeviceIn22B:**  input process image of a 22-byte EtherCAT data terminal, e.g. EL6021 (see [ST\_GENIbusEL6DeviceIn22B](ms-xhelp:///?Id=beckhoff-22fa-414d-9bb5-66235a2f3eba)).

**stPcComDeviceIn:**  input process image of a serial PC interface (see [ST\_GENIbusPcComDeviceIn64B](ms-xhelp:///?Id=beckhoff-70c6-41b2-8548-d61624a66bb7)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
