# F_CX8190_LED_ERR

## Library
tcplclib_tc2_systemcx

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
2. [Functions](ms-xhelp:///?Id=beckhoff-48c8-4ac6-bc46-6e026efec7f3)
3. F\_CX8190\_LED\_ERR

# F\_CX8190\_LED\_ERR

![46628683](/tcplclib_tc2_systemcx/1033/Images/jpg/10008235787__Web.jpg)

Since the CX8190 supports various protocols, the two LEDs WD and ERR on the CX8190 are not used by the firmware. This allows the user to create his own diagnosis messages. The LEDs can be used to indicate, for example, whether the CX8190 has received an IP address from the DHCP server or whether devices are exchanging data.

The F\_CX8190\_LED\_ERR function controls the ERR LED on the CX8190. Various color and flashing modes can be used here. The possible LED colors are red and green.

## VAR\_INPUT

```
VAR_INPUT  
    eMode      : E_CX8190_LED;  
END_VAR
```

eMode: The way in which the LED lights up.

## VAR\_OUTPUT

```
F_ F_CX8190_LED_ERR     : INT;
```

**F\_CX8190\_LED\_ERR**: -1, not implemented flash code, 0 OK

## Requirements

| Development environment | Target platform | Hardware | PLC libraries to include |
| --- | --- | --- | --- |
| TwinCAT v3.1 Build 4022.30 | ARM | CXxxxx | Tc2\_SystemCX |

[TwinCAT 3 | PLC Library: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
