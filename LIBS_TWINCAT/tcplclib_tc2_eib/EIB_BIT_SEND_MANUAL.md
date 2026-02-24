# EIB_BIT_SEND_MANUAL

## Library
tcplclib_tc2_eib

## Category
Motion Control

# EIB\_BIT\_SEND\_MANUAL

![61729771](/tcplclib_tc2_eib/1033/Images/gif/187958539__en-US__Web.gif)

This function block sends a 1-bit EIB value to the set group address. An IEC61131-3 BOOL variable is available as input value. The data is sent when *bSend* has a positive edge. *bBusy* is set as long the function block is active. *bBusy* is set to FALSE once the EIB command was sent or if an error occurs. An error is indicated by setting the *bError* variable. The error code is indicated in the *iErrorID*.

## VAR\_INPUT

```
Group_Address : EIB_GROUP_ADDR;  
bSend         : BOOL;  
bData         : BOOL;  
str_Rec       : EIB_REC;
```

**Group\_Address:** Group address to which the data is sent (see [EIB\_GROUP\_ADDR](ms-xhelp:///?Id=beckhoff-b660-4bbb-871b-bcd96d7eaa4e)).

**bSend:** Positive edge sends EIB telegram.

**bData:** Range of values TRUE/FALSE.

**str\_Rec:** The data structure with which the [KL6301()](ms-xhelp:///?Id=beckhoff-032b-44a9-b21c-bae726e1c8b9) function block must be linked (see [EIB\_REC](ms-xhelp:///?Id=beckhoff-3248-4b8c-9c74-e6771baf4094)).

## VAR\_OUTPUT

```
bBusy    : BOOL;  
bError   : BOOL;  
iErrorID : EIB_ERROR_CODE;
```

**bBusy:** The block is active. Wait for new functions, until *bBusy* is FALSE again.

**bError:** this output goes TRUE as soon as an error occurs. This error is described via the *iErrorID* variable.

**iErrorID:** This output outputs an error code in the event of an error (see [EIB\_ERROR\_CODE](ms-xhelp:///?Id=beckhoff-9096-470f-8523-760659ef887f)). *bError* goes TRUE at the same time.

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_EIB from 3.3.4.0 |
