# E_MBUS_Medium

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [DUTs](ms-xhelp:///?Id=beckhoff-150e-454f-9b9c-2dace1ed642c)
4. [Enums](ms-xhelp:///?Id=beckhoff-3e72-4e2d-b162-3a62166aa205)
5. E\_MBUS\_Medium

# E\_MBUS\_Medium

Medium

```
TYPE E_MBUS_Medium :  
(  
  eMBUS_MediumNull                      := -1,  
  eMBUS_MediumOther                     := 0,  
  eMBUS_MediumOil                       := 1,  
  eMBUS_MediumElectricity               := 2,  
  eMBUS_MediumGas                       := 3,  
  eMBUS_MediumHeat_Outlet               := 4,  
  eMBUS_MediumSteam                     := 5,  
  eMBUS_MediumHot_Water                 := 6,  
  eMBUS_MediumWater                     := 7,  
  eMBUS_MediumHeat_Cost_Allocator       := 8,  
  eMBUS_MediumCompressed_Air            := 9,  
  eMBUS_MediumCooling_load_meter_outlet := 10,  
  eMBUS_MediumCooling_load_meter_intlet := 11,  
  eMBUS_MediumHeat_inlet                := 12,  
  eMBUS_MediumHeat_cooling_load_Meter   := 13,  
  eMBUS_MediumBusSystem                 := 14,  
  eMBUS_MediumUnknownMedium             := 15,  
  eMBUS_MediumReserved16                := 16,  
  eMBUS_MediumReserved17                := 17,  
  eMBUS_MediumReserved18                := 18,  
  eMBUS_MediumReserved19                := 19,  
  eMBUS_MediumReserved20                := 20,  
  eMBUS_MediumReserved21                := 21,  
  eMBUS_MediumColdWater                 := 22,  
  eMBUS_MediumDualWater                 := 23,  
  eMBUS_MediumPressure                  := 24,  
  eMBUS_MediumA_D_Converter             := 25,  
  eMBUS_MediumReserved26                := 26,  
  eMBUS_MediumReserved27                := 27,  
  eMBUS_MediumReserved28                := 28,  
  eMBUS_MediumReserved29                := 29,  
  eMBUS_MediumReserved30                := 30  
)  
END_TYPE
```

**eMBUS\_MediumNull:** Not assigned.

**eMBUS\_MediumOther:** Other.

**eMBUS\_MediumOil:** Oil.

**eMBUS\_MediumElectricity:** Electricity.

**eMBUS\_MediumGas:** Gas.

**eMBUS\_MediumHeat\_Outlet:** Heat (return).

**eMBUS\_MediumSteam:** Steam.

**eMBUS\_MediumHot\_Water:** Hot water.

**eMBUS\_MediumWater:** Water.

**eMBUS\_MediumHeat\_Cost\_Allocator:** Heating cost distributor.

**eMBUS\_MediumCompressed\_Air:** Compressed air.

**eMBUS\_MediumCooling\_load\_meter\_outlet:** Cooling (return).

**eMBUS\_MediumCooling\_load\_meter\_intlet:** Cooling (supply/flow).

**eMBUS\_MediumHeat\_inlet:** Heat (supply/flow).

**eMBUS\_MediumHeat\_cooling\_load\_Meter:** Heating / cooling.

**eMBUS\_MediumBusSystem:** Bus / system.

**eMBUS\_MediumUnknownMedium:** Unknown.

**eMBUS\_MediumReserved16:** Reserved.

**eMBUS\_MediumReserved17:** Reserved.

**eMBUS\_MediumReserved18:** Reserved.

**eMBUS\_MediumReserved19:** Reserved.

**eMBUS\_MediumReserved20:** Reserved.

**eMBUS\_MediumReserved21:** Reserved.

**eMBUS\_MediumColdWater:** Cold water.

**eMBUS\_MediumDualWater:** Mixed water.

**eMBUS\_MediumPressure:** Pressure.

**eMBUS\_MediumA\_D\_Converter:** A/D converter.

**eMBUS\_MediumReserved26:** Reserved.

**eMBUS\_MediumReserved27:** Reserved.

**eMBUS\_MediumReserved28:** Reserved.

**eMBUS\_MediumReserved29:** Reserved.

**eMBUS\_MediumReserved30:** Reserved.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MBus from 3.3.4.0 |

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
