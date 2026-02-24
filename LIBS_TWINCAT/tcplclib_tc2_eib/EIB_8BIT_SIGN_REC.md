# EIB_8BIT_SIGN_REC

## Library
tcplclib_tc2_eib

## Category
Motion Control

# EIB\_8BIT\_SIGN\_REC

![66939890](/tcplclib_tc2_eib/1033/Images/gif/187862539__en-US__Web.gif)

This function block receives 8 bits of EIB data on the set group address and converts them into an IEC61131-3 INT variable. In addition the value may be converted automatically.

## VAR\_INPUT

```
Group_Address : EIB_GROUP_ADDR;  
Scaling_Mode  : INT;  
strData_Rec   : EIB_REC;
```

**Group\_Address:** Group address from which the data is sent (see [EIB\_GROUP\_ADDR](ms-xhelp:///?Id=beckhoff-b660-4bbb-871b-bcd96d7eaa4e)). This group address must be entered in the filters!

**Scaling\_Mode:**   
 0 - The 8 bit value is output as a percentage value 0...100%  
 1 - The 8 bit value is output as an angle 0...360°  
 2 - The 8 bit value is output as a byte value 0...255

**strData\_Rec:** The data structure with which the [KL6301()](ms-xhelp:///?Id=beckhoff-032b-44a9-b21c-bae726e1c8b9) function block must be linked (see [EIB\_REC](ms-xhelp:///?Id=beckhoff-3248-4b8c-9c74-e6771baf4094)).

## VAR\_OUTPUT

```
bDataReceive : BOOL;  
iData        : INT;
```

**bDataReceive:** This bit is set to FALSE for exactly one cycle when an EIB telegram with the group address is received.

**iData:** Scaled value, see *Scaling\_Mode* (-1, an invalid scaling mode was entered)

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_EIB from 3.3.4.0 |
