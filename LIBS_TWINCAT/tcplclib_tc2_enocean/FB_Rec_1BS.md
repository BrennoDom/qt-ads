# FB_Rec_1BS

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# FB\_Rec\_1BS

![21345065](/tcplclib_tc2_enocean/1033/Images/gif/173367179__en-US__Web.gif)

This function block receives data that were received via EnOcean. This block is used for integration of window contacts, for example (ORG field 6).

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
bOpen    : BOOL;  
bClose   : BOOL;  
bLRN     : BOOL;  
by_Node  : BYTE;  
bReceive : BOOL := TRUE;
```

**bOpen:** Contact open.

**bClose:** Contact closed.

**bLRN:** LRN button pressed.

**by\_Node:** Node number of the KL6583 that has received the EnOcean telegram.

**bReceive:** On receiving an EnOcean telegram this value is set to FALSE for one cycle.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
