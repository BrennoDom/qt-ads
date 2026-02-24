# NTC_TO_INT: INT

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [POUs](ms-xhelp:///?Id=beckhoff-d0d7-47c8-bb7c-a9b7cd043f93)
4. [Functions](ms-xhelp:///?Id=beckhoff-5ba9-4eb8-9fd8-fdf530760286)
5. NTC\_TO\_INT: INT

# NTC\_TO\_INT: INT

![53044787](/tcplclib_tc2_mpbus/1033/Images/gif/181497483__en-US__Web.gif)

This function calculates a temperature from the value of an NTC resistor.

Connect this function to **iMP\_Sensor\_Analog**. As output, you receive an INT variable that represents the temperature with a resolution of 0.01°C (20.5°C, for example, is represented as 2050).

The lowest valid value of 104 ohms corresponds to 145°C. If the value is smaller than this, 16#7FFD is output.

The largest valid value of 48555 ohms corresponds to -20°C. If the value is greater than this, 16#7FFE is output.

## VAR\_INPUT

```
MP_Value : WORD;
```

**MP\_Value:** Input for an ohmic NTC sensor

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MPBus from 3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
