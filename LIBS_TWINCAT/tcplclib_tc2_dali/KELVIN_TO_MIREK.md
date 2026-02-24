# KELVIN_TO_MIREK

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Low-Level commands](ms-xhelp:///?Id=beckhoff-408c-4669-b5d5-6c547023c614)
5. [Part 209 (color/color temperature control)](ms-xhelp:///?Id=beckhoff-a837-4797-bf19-33a8438d83d2)
6. KELVIN\_TO\_MIREK

# KELVIN\_TO\_MIREK

![59011071](/tcplclib_tc2_dali/1033/Images/gif/1012603147__Web.gif)

Conversion of the color temperature from Kelvin to Mirek.

Mirek is the unit that is used with most DALI commands. The return value is limited and lies within the range from 0 to 65535 (see table).

Mirek = 1,000,000 / (color temperature in Kelvin).

| Kelvin | Mirek |
| --- | --- |
| 0 | 65535 |
| 15 | 65535 |
| 16 | 62500 |
| 1000 | 1000 |
| 10000 | 100 |
| 1000000 | 1 |
| 1000001 | 0 |

## VAR\_INPUT

```
fKelvin : LREAL;
```

**fKelvin:** Color temperature in Kelvin.

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DALI from v3.4.3.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
