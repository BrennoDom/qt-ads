# EIB_DATE_SEND

## Library
tcplclib_tc2_eib

## Category
Motion Control

# EIB\_DATE\_SEND

![18697032](/tcplclib_tc2_eib/1033/Images/gif/187961739__en-US__Web.gif)

This function block sends a 3-byte EIB value to the set group address. Three IEC61131-3 word variables are available as input values. The data are sent when the block is called for the first time the and then every 5 minutes.

## VAR\_INPUT

```
Group_Address : EIB_GROUP_ADDR;  
wDay          : WORD;  
wMonth        : WORD;  
wYear         : WORD;  
str_Rec       : EIB_REC;
```

**Group\_Address:** Group address to which the data is sent (see [EIB\_GROUP\_ADDR](ms-xhelp:///?Id=beckhoff-b660-4bbb-871b-bcd96d7eaa4e)).

**wDay:** Range of values 1...31.

**wMonth:** Range of values 1...12.

**wYear:** Range of values 1...99. If a value greater 2000 entered, 2000 is automatically subtracted. For the year 2005, for example, only the 5 is transferred to the EIB node.

**str\_Rec:** The data structure with which the [KL6301()](ms-xhelp:///?Id=beckhoff-032b-44a9-b21c-bae726e1c8b9) function block must be linked (see [EIB\_REC](ms-xhelp:///?Id=beckhoff-3248-4b8c-9c74-e6771baf4094)).

## VAR\_OUTPUT

```
bError   : BOOL;  
iErrorID : EIB_ERROR_CODE;
```

**bError:** this output goes TRUE as soon as an error occurs. This error is described via the *iErrorID* variable.

**iErrorID:** This output outputs an error code in the event of an error (see [EIB\_ERROR\_CODE](ms-xhelp:///?Id=beckhoff-9096-470f-8523-760659ef887f)). *bError* goes TRUE at the same time.

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_EIB from 3.3.4.0 |
