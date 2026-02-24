# FB_Rec_RPS_Window_Handle

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# FB\_Rec\_RPS\_Window\_Handle

![51228725](/tcplclib_tc2_enocean/1033/Images/gif/173373579__en-US__Web.gif)

This function block receives data from a window handle that were received via EnOcean. The block outputs the data in a data structure (ORG field 5).

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
ar_Data  : AR_EnOceanWindow;  
by_Node  : BYTE;  
bReceive : BOOL := TRUE;
```

**ar\_Data:** window handle data (see [set\_EnOceanWindow](ms-xhelp:///?Id=beckhoff-04b7-4ad4-8994-fa5536cada8b)).

**by\_Node:** Node number of the KL6583 that has received the EnOcean telegram.

**bReceive:** On receiving an EnOcean telegram this value is set to FALSE for one cycle.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
