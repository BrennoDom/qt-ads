# Data_Window

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [DUTs](ms-xhelp:///?Id=beckhoff-ec1f-451d-a0f5-4c656574c991)
4. [Enums](ms-xhelp:///?Id=beckhoff-a688-45f4-907e-ed52c85f5141)
5. Data\_Window

# Data\_Window

This ENUM can be used to specify the ventilation method.

```
TYPE Data_Window :  
(  
  Window_Close  := 8,  
  Window_Unlock := 9,  
  Window_Open   := 16#0A,  
  Window_20     := 16#0B,  
  Window_40     := 16#0C,  
  Window_60     := 16#0D,  
  Window_80     := 16#0E,  
  Window_100    := 16#0F,  
  Auto_Close    := 1,  
  Auto_5_15min  := 2,  
  Auto_8_30min  := 3,  
  Auto_10_50min := 4,  
  Auto_open     := 5,  
  Auto          := 0  
)  
END_TYPE
```

**Window\_Close:** Closes the window

**Window\_Unlock:** If you use "Unlock", use the switch in the window to restart the MP-Bus communication

**Window\_Open:** Opens the window

**Window\_20:** Opens the window 20%

**Window\_40:** Opens the window 40%

**Window\_60:** Opens the window 60%

**Window\_80:** Opens the window 80%

**Window\_100:** Opens the window 100%

**Auto\_Close:** Automatic closing

**Auto\_5\_15min:** Automatic ventilation every 5..15 minutes

**Auto\_8\_30min:** Automatic ventilation every 8..30 minutes

**Auto\_10\_50min:** Automatic ventilation every 10..50 minutes

**Auto\_open:** Automatic ventilation open

**Auto:** Automatic mode

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MPBus from 3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
