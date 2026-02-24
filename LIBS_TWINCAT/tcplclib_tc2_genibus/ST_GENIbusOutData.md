# ST_GENIbusOutData

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# ST\_GENIbusOutData

Structure for linking the output image of the process variables. There is a choice of four different possible structures, of which finally only one is to be linked:

```
TYPE ST_GENIbusOutData :  
STRUCT  
  stKL6DeviceOut5B  : ST_GENIbusKL6DeviceOut5B;  
  stKL6DeviceOut22B : ST_GENIbusKL6DeviceOut22B;  
  stEL6DeviceOut22B : ST_GENIbusEL6DeviceOut22B;  
  stPcComDeviceOut  : ST_GENIbusPcComDeviceOut64B;  
END_STRUCT  
END_TYPE
```

**stKL6DeviceOut5B:** output process image of a 5-byte data terminal with standard communication bus, e.g. KL6021 (see [ST\_GENIbusKL6DeviceOut5B](ms-xhelp:///?Id=beckhoff-b576-4d97-b8dd-798f11db932a)).

**stKL6DeviceOut22B:** output process image of a 22-byte data terminal with standard communication bus, e.g. KL6041 (see [ST\_GENIbusKL6DeviceOut22B](ms-xhelp:///?Id=beckhoff-33d3-4466-b030-2bcc752790ed)).

**stEL6DeviceOut22B:** output process image of a 22-byte EtherCAT data terminal, e.g. EL6021 (see [ST\_GENIbusEL6DeviceOut22B](ms-xhelp:///?Id=beckhoff-a6fd-4f23-b559-488dc5b9464f)).

**stPcComDeviceOut:** output process image of a serial PC interface (see [ST\_GENIbusPcComDeviceOut64B](ms-xhelp:///?Id=beckhoff-b427-4a85-ae1b-1a81d81f8487)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
