# EIB_8BIT_SIGN_SEND_EX

## Library
tcplclib_tc2_eib

## Category
Motion Control

# EIB\_8BIT\_SIGN\_SEND\_EX

![44100051](/tcplclib_tc2_eib/1033/Images/gif/9007199442670731__Web.gif)

This function block sends a 8-bit EIB value to the set group address. An IEC61131-3 INT value is available as input value. *Scaling\_Mode* can be used to scale the input data value. The data can be sent in Manual, Polling or OnChange mode (*iMode*).

## VAR\_INPUT

```
bStart         : BOOL;  
iMode          : INT;  
Group_Address  : EIB_GROUP_ADDR;  
iData          : INT;  
Scaling_Mode   : INT;  
str_Rec        : EIB_REC;  
CyclePolling   : TIME := t#500ms;  
MinSendTime    : TIME := t#1s;  
bEnableReadReq : BOOL;
```

**bStart:** Activates the function block. The function block starts operating depending on the set mode (see *iMode*).

**iMode:**   
0 - With a positive edge at *bStart*, an EIB telegram is sent. *bBusy* becomes FALSE again when the command has been processed.  
1 - Polling Mode: If *bStart* is TRUE is, EIB telegrams are sent at intervals of CyclePolling.  
2 - OnChange Mode: If *bStart* is TRUE, an EIB telegram is sent automatically when the data changes. *MinSendTime* can be used to parameterize the minimum interval between two EIB messages, in order to avoid excessive EIB network load.

**Group\_Address:** Group address to which the data is sent (see [EIB\_GROUP\_ADDR](ms-xhelp:///?Id=beckhoff-b660-4bbb-871b-bcd96d7eaa4e)).

**iData:** Data to be sent. Range of values depending on *Scaling\_Mode*.

**Scaling\_Mode:**   
 0 - 0...100 [%]  
 1 - 0...360 [°]  
 2 - 0...255

**str\_Rec:** The data structure with which the [KL6301()](ms-xhelp:///?Id=beckhoff-032b-44a9-b21c-bae726e1c8b9) function block must be linked (see [EIB\_REC](ms-xhelp:///?Id=beckhoff-3248-4b8c-9c74-e6771baf4094)).

**CyclePolling:** Polling time for *iMode* = 1 (polling mode). The minimum time is 200 ms.

**MinSendTime:** Minimum interval time, which has to elapse before a telegram is sent in OnChange mode. The minimum time is 200 ms.

**bEnableReadReq:** Enables the execution of read commands.

## VAR\_OUTPUT

```
bBusy    : BOOL;  
bError   : BOOL;  
iErrorID : EIB_ERROR_CODE;
```

**bBusy:** The block is active. Wait for new functions, until *bBusy* is FALSE again.

**bError:** this output goes TRUE as soon as an error occurs. This error is described via the *iErrorID* variable.

**iErrorID:** This output outputs an error code in the event of an error (see [EIB\_ERROR\_CODE](ms-xhelp:///?Id=beckhoff-9096-470f-8523-760659ef887f)). *bError* goes TRUE at the same time.

OnChange Mode:

![61356140](/tcplclib_tc2_eib/1033/Images/gif/187900939__en-US__Web.gif)

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_EIB from 3.3.4.0 |
