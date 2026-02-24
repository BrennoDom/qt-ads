# FB_Rec_Teach_In

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# FB\_Rec\_Teach\_In

![52942405](/tcplclib_tc2_enocean/1033/Images/gif/173392779__en-US__Web.gif)

This function block indicates when a learn button is pressed on an EnOcean device. If the flag *bLearnType* is set, further information about the EnOcean device can be read. This function must be provided by the EnOcean device. So far, however, it is only supported by very few EnOcean devices.

## VAR\_INPUT

```
bStart     : BOOL;  
byNode     : BYTE;  
str_KL6581 : STR_KL6581;
```

**bStart:** If TRUE the block is activated, if FALSE it is deactivated.

**byNode:** Filter - if the value is zero the EnOcean telegrams from all KL6583s are received. If a value of 1 to 8 is entered, only the data from the corresponding KL6583 are received.

**str\_KL6581:** Is linked with the data structure of block [FB\_KL6581()](ms-xhelp:///?Id=beckhoff-45e5-4533-98ae-900c39c9c4dc) (see [STR\_KL6581](ms-xhelp:///?Id=beckhoff-5a94-43ed-9608-18055618a879)).

## VAR\_OUTPUT

```
bLearnType   : BOOL;  
by_Node      : BYTE;  
dw_ID        : DWORD;  
str_Teach_In : STR_Teach_In;  
bReceive     : BOOL := TRUE;
```

**bLearnType:** If the bit is set you will find further data in the *str\_Teach\_In* structure.

**by\_Node:** Number of EnOcean devices found.

**dw\_ID:** EnOcean ID for which the teach-in button was pressed.

**str\_Teach\_In:** Data structure, profile, type and manufacturer ID (see [STR\_Teach\_In](ms-xhelp:///?Id=beckhoff-5a94-43ed-9608-18055618a879)).

**bReceive:** On receiving an EnOcean telegram this value is set to FALSE for one cycle.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
