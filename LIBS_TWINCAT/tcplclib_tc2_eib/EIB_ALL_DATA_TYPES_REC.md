# EIB_ALL_DATA_TYPES_REC

## Library
tcplclib_tc2_eib

## Category
Motion Control

# EIB\_ALL\_DATA\_TYPES\_REC

![53422044](/tcplclib_tc2_eib/1033/Images/gif/9007199442609931__en-US__Web.gif)

This function block receives variable EIB data sizes on the set group address and outputs the raw data as a byte ARRAY.

## VAR\_INPUT

```
Group_Address : EIB_GROUP_ADDR;  
strData_Rec   : EIB_REC;
```

**Group\_Address:** Group address from which the data is sent (see [EIB\_GROUP\_ADDR](ms-xhelp:///?Id=beckhoff-b660-4bbb-871b-bcd96d7eaa4e)). This group address must be entered in the filters!

**strData\_Rec:** The data structure with which the [KL6301()](ms-xhelp:///?Id=beckhoff-032b-44a9-b21c-bae726e1c8b9) function block must be linked (see [EIB\_REC](ms-xhelp:///?Id=beckhoff-3248-4b8c-9c74-e6771baf4094)).

## VAR\_OUTPUT

```
bDataReceive     : BOOL;  
EIB_Data_Receive : ARRAY [1..14] OF BYTE;  
EIB_Data_Len     : USINT;  
bEIB_READ        : BOOL;
```

**bDataReceive:** This bit is set to FALSE for exactly one cycle when an EIB telegram with the group address is received.

**EIB\_Data\_Receive:** Contains the user data of the received EIB telegram.

**EIB\_Data\_Len:** Contains the user data length of the incoming EIB telegram.  
Data < 8 bit specified length 1,  
Data >=) 8 bit specified length +1  
Sample: If 1 bit of data is received, the length in EIB\_Data\_Len is 1. If 2 bytes of data are received, the length in EIB\_Data\_Len is 3.

**bEIB\_READ:** TRUE = EIB read command. FALSE = normal EIB telegram (from v3.3.5.0).

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_EIB from 3.3.4.0 |
