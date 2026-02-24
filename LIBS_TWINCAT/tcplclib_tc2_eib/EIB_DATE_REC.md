# EIB_DATE_REC

## Library
tcplclib_tc2_eib

## Category
Motion Control

# EIB\_DATE\_REC

![59548322](/tcplclib_tc2_eib/1033/Images/gif/187881739__en-US__Web.gif)

This function block receives 3 bytes of EIB data on the set group address and converts them into three IEC61131-3 WORD variables.

## VAR\_INPUT

```
Group_Address : EIB_GROUP_ADDR;  
strData_Rec   : EIB_REC;
```

**Group\_Address:** Group address from which the data is sent (see [EIB\_GROUP\_ADDR](ms-xhelp:///?Id=beckhoff-b660-4bbb-871b-bcd96d7eaa4e)). This group address must be entered in the filters!

**strData\_Rec:** The data structure with which the [KL6301()](ms-xhelp:///?Id=beckhoff-032b-44a9-b21c-bae726e1c8b9) function block must be linked (see [EIB\_REC](ms-xhelp:///?Id=beckhoff-3248-4b8c-9c74-e6771baf4094)).

## VAR\_OUTPUT

```
bDataReceive : BOOL;  
wDay         : WORD;  
wMonth       : WORD;  
wYear        : WORD;
```

**bDataReceive:** This bit is set to FALSE for exactly one cycle when an EIB telegram with the group address is received.

**wDay:** date, days [1...31]

**wMonth:** date, month [1...12]

**wYear:** date, year [0...99]

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_EIB from 3.3.4.0 |
