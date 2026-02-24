# E_MBUS_Baudrate

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [DUTs](ms-xhelp:///?Id=beckhoff-150e-454f-9b9c-2dace1ed642c)
4. [Enums](ms-xhelp:///?Id=beckhoff-3e72-4e2d-b162-3a62166aa205)
5. E\_MBUS\_Baudrate

# E\_MBUS\_Baudrate

Configurable baud rates

```
TYPE E_MBUS_Baudrate :  
(  
  eMBUS_NoBaudrate := 0,  
  eMBUS_Baud300    := 30,  
  eMBUS_Baud600    := 60,  
  eMBUS_Baud1200   := 120,  
  eMBUS_Baud2400   := 240,  
  eMBUS_Baud4800   := 480,  
  eMBUS_Baud9600   := 960  
)  
END_TYPE
```

**eMBUS\_NoBaudrate:** Standard baud rate = 2400 baud

**eMBUS\_Baud300:** 300 baud

**eMBUS\_Baud600:** 600 baud

**eMBUS\_Baud1200:** 1200 baud

**eMBUS\_Baud2400:** 2400 baud

**eMBUS\_Baud4800:** 4800 baud

**eMBUS\_Baud9600:** 9600 baud

M-Bus counters are generally supplied with 2400 baud.

The KL6781 supports 300, 600, 1200, 2400, 4800, 9600 baud.

The KL6781 interface is set to *eBaudrate* when the PLC starts or when the input *eBaudrate* changes.

Not all M-Bus devices support baud rates above 2400.

![33821816](/tcplclib_tc2_mbus/1033/Images/gif/175082251__en-US__Web.gif)

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MBus from 3.3.4.0 |

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
