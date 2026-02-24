# EIB_ALL_DATA_TYPES_SEND

## Library
tcplclib_tc2_eib

## Category
Motion Control

# EIB\_ALL\_DATA\_TYPES\_SEND

![12470207](/tcplclib_tc2_eib/1033/Images/gif/9007199442680331__Web.gif)

This function block sends a freely selectable EIB value to the set group address. An IEC61131-3 byte ARRAY variable is available as input value. The data are sent depending on the set mode.

## VAR\_INPUT

```
bStart        : BOOL;  
iMode         : INT;  
Group_Address : EIB_GROUP_ADDR;  
DATA          : ARRAY [1..14] OF BYTE;  
EIB_Data_Len  : USINT := 1;  
PRIORITY      : EIB_PRIORITY := EIB_PRIORITY_LOW;  
CyclePolling  : TIME := t#100ms;  
MinSendTime   : TIME := t#1s;  
str_Rec       : EIB_REC;  
bReadCommand  : BOOL;
```

**bStart:** If the mode is set to 0, an EIB telegram with rising edge is sent to *bStart*.

**iMode:**   
 0 - manual (Fig. 1)  
 1 - polling (Fig. 2)  
 2 - OnChange (Fig. 3)

**Group\_Address:** Group address to which the data is sent (see [EIB\_GROUP\_ADDR](ms-xhelp:///?Id=beckhoff-b660-4bbb-871b-bcd96d7eaa4e)).

**DATA:** EIB data values.

**EIB\_Data\_Len:** Length of EIB data,  
 EIB values >=) 1 byte: use length +1,  
 EIB values < 1 byte: use length = 1

**PRIORITY:** EIB priority, Low, High, alarm (see [EIB\_PRIORITY](ms-xhelp:///?Id=beckhoff-4026-4bd3-b5ee-edeca0d4e34e)).

**CyclePolling:** If mode 1 is selected, an EIB telegram is sent at the set time, even if the data values have not changed.

**MinSendTime:** If mode 2 is selected, data are only transferred in the event of a change. *MinSendTime* defines the minimum time between two EIB telegrams.

**str\_Rec:** The data structure with which the [KL6301()](ms-xhelp:///?Id=beckhoff-032b-44a9-b21c-bae726e1c8b9) function block must be linked (see [EIB\_REC](ms-xhelp:///?Id=beckhoff-3248-4b8c-9c74-e6771baf4094)).

**bReadCommand:** A response can be sent to an EIB READ COMMAND.

## VAR\_OUTPUT

```
bBusy    : BOOL;  
bError   : BOOL;  
iErrorID : EIB_ERROR_CODE;
```

**bBusy:** The block is active. Wait for new functions, until *bBusy* is FALSE again.

**bError:** this output goes TRUE as soon as an error occurs. This error is described via the *iErrorID* variable.

**iErrorID:** This output outputs an error code in the event of an error (see [EIB\_ERROR\_CODE](ms-xhelp:///?Id=beckhoff-9096-470f-8523-760659ef887f)). *bError* goes TRUE at the same time.

## Übertragungsmodus

## Mode 0 manual

![45123001](/tcplclib_tc2_eib/1033/Images/gif/187942539__en-US__Web.gif)

Figure 1

## Mode 1 Polling

![3453833](/tcplclib_tc2_eib/1033/Images/gif/187945739__en-US__Web.gif)

Figure 2

## Mode 2 OnChange

![31084503](/tcplclib_tc2_eib/1033/Images/gif/187900939__en-US__Web.gif)

Abbildung 3

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_EIB from 3.3.4.0 |
