# EIB_READ_SEND

## Library
tcplclib_tc2_eib

## Category
Motion Control

# EIB\_READ\_SEND

![34055563](/tcplclib_tc2_eib/1033/Images/gif/187964939__en-US__Web.gif)

This function block sends a *Read\_Group\_Req* to the set group address. For receiving a Read\_Group\_Res the group address filter of the KL6301 has to be parameterized accordingly.

## VAR\_INPUT

```
Group_Address : EIB_GROUP_ADDR;  
bRead         : BOOL;  
str_Rec       : EIB_REC;
```

**Group\_Address:** Group address to which the data is sent (see [EIB\_GROUP\_ADDR](ms-xhelp:///?Id=beckhoff-b660-4bbb-871b-bcd96d7eaa4e)).

**bRead:** Rising edge starts the block and sends a Read\_Group\_Req to the EIB device. Attention: For receiving a response the group address must be entered in the filter!

**str\_Rec:** The data structure with which the [KL6301()](ms-xhelp:///?Id=beckhoff-032b-44a9-b21c-bae726e1c8b9) function block must be linked (see [EIB\_REC](ms-xhelp:///?Id=beckhoff-3248-4b8c-9c74-e6771baf4094)).

## VAR\_OUTPUT

```
bError   : BOOL;  
iErrorID : EIB_ERROR_CODE;  
bBusy    : BOOL;
```

**bError:** this output goes TRUE as soon as an error occurs. This error is described via the *iErrorId* variable.

**iErrorID:** This output outputs an error code in the event of an error (see [EIB\_ERROR\_CODE](ms-xhelp:///?Id=beckhoff-9096-470f-8523-760659ef887f)). *bError* goes TRUE at the same time.

**bBusy:** The function block is in operation as long as *bBusy* is set, i.e. TRUE. Please wait until *bBusy* changes to FALSE.

![38064613](/tcplclib_tc2_eib/1033/Images/gif/187968139__en-US__Web.gif)

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_EIB from 3.3.4.0 |
