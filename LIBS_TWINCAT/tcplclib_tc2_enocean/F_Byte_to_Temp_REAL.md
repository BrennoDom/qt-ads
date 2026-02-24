# F_Byte_to_Temp : REAL

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# F\_Byte\_to\_Temp : REAL

![60476403](/tcplclib_tc2_enocean/1033/Images/gif/173395979__en-US__Web.gif)

This function converts a byte raw value into a REAL variable.

In EnOcean, temperature data are transmitted in a certain format, which is one byte in size. These data are usually scaled to a certain temperature value.

For example, a value is transmitted from a range of values from 0 to 40°C. The minimum and maximum data value and the raw value are transferred to the function. The output of the function then outputs the temperature as REAL variable.

## VAR\_INPUT

```
byData  : BYTE;  
minTemp : REAL := 0;  
maxTemp : REAL := 40;
```

**byData:** Raw data.

**minTemp:** Minimum temperature.

**maxTemp:** Maximum temperature.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
