# F_CX81xx_ADDRESS

## Library
tcplclib_tc2_systemcx

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
2. [Functions](ms-xhelp:///?Id=beckhoff-48c8-4ac6-bc46-6e026efec7f3)
3. F\_CX81xx\_ADDRESS

# F\_CX81xx\_ADDRESS

![49774232](/tcplclib_tc2_systemcx/1033/Images/jpg/10008047115__Web.jpg)

This function reads the position of the address selection switch of the CXxxxx. One possible application is that you can activate different program parts in the PLC depending on the switch position.

This function reads the position of the DIP switch of the CXxxxx. One possible application is that you can activate different program parts in the PLC depending on the switch position.

## VAR\_INPUT

```
VAR_INPUT  
    iCX_Typ      : INT;          (* Use product code without ‘CX’ e.g.: CX8180 -> 8180 *)  
END_VAR
```

## VAR\_OUTPUT

```
F_CX80xx_ADDRESS     : INT;
```

**F\_CX80xx\_ADDRESS** : -1, non-implemented CX, address of the switch

## Requirements

| Development environment | Target platform | Hardware | PLC libraries to include |
| --- | --- | --- | --- |
| TwinCAT v3.1 Build 4022.30 | ARM | CXxxxx | Tc2\_SystemCX |

[TwinCAT 3 | PLC Library: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
