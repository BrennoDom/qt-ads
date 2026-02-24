# EIB_BIT_CONTROL_SEND

## Library
tcplclib_tc2_eib

## Category
Motion Control

# EIB\_BIT\_CONTROL\_SEND

![11325076](/tcplclib_tc2_eib/1033/Images/gif/187948939__en-US__Web.gif)

This function block sends a 2-bit EIB value to the set group address. Two IEC61131-3 BOOL variables are available as input values. The data are only transferred if there is a change in one of the two data types. If the value changes again within 200 milliseconds, new data are only sent to the EIB device after another 200 millisecond has passed (see diagram). No new EIB telegram is sent if the value changes within the "min. send time" but falls back to the old, already sent value within the "min. send time".

## VAR\_INPUT

```
Group_Address : EIB_GROUP_ADDR;  
bControl      : BOOL;  
bValue        : BOOL;  
str_Rec       : EIB_REC;
```

**Group\_Address:** Group address to which the data is sent (see [EIB\_GROUP\_ADDR](ms-xhelp:///?Id=beckhoff-b660-4bbb-871b-bcd96d7eaa4e)).

**bControl:** Range of values TRUE/FALSE.

**bValue:** Range of values TRUE/FALSE.

**str\_Rec:** The data structure with which the [KL6301()](ms-xhelp:///?Id=beckhoff-032b-44a9-b21c-bae726e1c8b9) function block must be linked (see [EIB\_REC](ms-xhelp:///?Id=beckhoff-3248-4b8c-9c74-e6771baf4094)).

## VAR\_OUTPUT

```
bError   : BOOL;  
iErrorID : EIB_ERROR_CODE;
```

**bError:** this output goes TRUE as soon as an error occurs. This error is described via the *iErrorID* variable.

**iErrorID:** This output outputs an error code in the event of an error (see [EIB\_ERROR\_CODE](ms-xhelp:///?Id=beckhoff-9096-470f-8523-760659ef887f)). *bError* goes TRUE at the same time.

![34816825](/tcplclib_tc2_eib/1033/Images/gif/187833739__en-US__Web.gif)

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_EIB from 3.3.4.0 |
