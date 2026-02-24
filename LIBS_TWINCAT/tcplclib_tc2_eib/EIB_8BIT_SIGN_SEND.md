# EIB_8BIT_SIGN_SEND

## Library
tcplclib_tc2_eib

## Category
Motion Control

# EIB\_8BIT\_SIGN\_SEND

![50254714](/tcplclib_tc2_eib/1033/Images/gif/187926539__en-US__Web.gif)

This function block sends a 8-bit EIB value to the set group address. An IEC61131-3 INT value is available as input value. Scaling\_Mode can be used to scale the input data value. The data are only transferred if there is a change in the data value. If the value changes again within 1 second, new data are only sent to the EIB device after "minSendTime" has passed (see diagram). No new EIB telegram is sent if the value changes within the "min. send time" but falls back to the old, already sent value within the "min. send time".

## VAR\_INPUT

```
Group_Address : EIB_GROUP_ADDR;  
iData         : INT;  
Scaling_Mode  : INT;  
str_Rec       : EIB_REC;
```

**Group\_Address:** Group address to which the data is sent (see [EIB\_GROUP\_ADDR](ms-xhelp:///?Id=beckhoff-b660-4bbb-871b-bcd96d7eaa4e)).

**iData:** Data to be sent. Range of values depending on Scaling\_Mode.

**Scaling\_Mode:**   
 0 - 0...100 [%]  
 1 - 0...360 [°]  
 2 - 0...255

**str\_Rec:** The data structure with which the [KL6301()](ms-xhelp:///?Id=beckhoff-032b-44a9-b21c-bae726e1c8b9) function block must be linked (see [EIB\_REC](ms-xhelp:///?Id=beckhoff-3248-4b8c-9c74-e6771baf4094)).

## VAR\_OUTPUT

```
bError   : BOOL;  
iErrorID : EIB_ERROR_CODE;
```

**bError:** this output goes TRUE as soon as an error occurs. This error is described via the *iErrorID* variable.

**iErrorID:** This output outputs an error code in the event of an error (see [EIB\_ERROR\_CODE](ms-xhelp:///?Id=beckhoff-9096-470f-8523-760659ef887f)). *bError* goes TRUE at the same time.

![49639248](/tcplclib_tc2_eib/1033/Images/gif/187900939__en-US__Web.gif)

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_EIB from 3.3.4.0 |
