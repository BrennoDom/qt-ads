# FB_Rec_Generic

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# FB\_Rec\_Generic

![17284754](/tcplclib_tc2_enocean/1033/Images/gif/173363979__en-US__Web.gif)

This function block receives all data that were received via EnOcean. This block can be used for all kinds of EnOcean telegrams.

The user must interpret the data himself. The manufacturer’s documentation for the sending EnOcean device is necessary for this.

## VAR\_INPUT

```
str_KL6581 : STR_KL6581;  
byNode     : BYTE;  
dw_ID      : DWORD;
```

**str\_KL6581:** Is linked with the data structure of block [FB\_KL6581()](ms-xhelp:///?Id=beckhoff-45e5-4533-98ae-900c39c9c4dc) (see [STR\_KL6581](ms-xhelp:///?Id=beckhoff-5a94-43ed-9608-18055618a879)).

**byNode:** Filter - if the value is zero the EnOcean telegrams from all KL6583s are received. If a value of 1 to 8 is entered, only the data from the corresponding KL6583 are received.

**dw\_ID:** EnOcean ID to be received.

## VAR\_OUTPUT

```
ar_Value   : ARRAY [0..3] OF BYTE;  
by_Node    : BYTE;  
by_STATE   : BYTE;  
bReceive   : BOOL := TRUE;  
EnOceanTyp : E_EnOcean_Org;
```

**ar\_Value:** 4-byte EnOcean data.

**by\_Node:** Node number of the KL6583 that has received the EnOcean telegram.

**by\_STATE:** EnOcean STATUS field.

**bReceive:** On receiving an EnOcean telegram this value is set to FALSE for one cycle.

**EnOceanTyp:** EnOcean ORG field (see [E\_EnOcean\_Org](ms-xhelp:///?Id=beckhoff-e3c8-482c-89a5-b64382283c8d)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
