# FB_EnOcean_Search

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# FB\_EnOcean\_Search

![5882489](/tcplclib_tc2_enocean/1033/Images/gif/173389579__en-US__Web.gif)

This function block displays all EnOcean IDs that it has received and enters them in a reception array, (*ar\_ID)*. Up to 256 EnOcean devices can be recognized. Alternatively the block can also be created separately for each KL6583. This allows you to recognize whether an EnOcean device is received by several KL6583s.

## VAR\_INPUT

```
bStart     : BOOL;  
str_KL6581 : STR_KL6581;  
byNode     : BYTE;
```

**bStart:** If TRUE the block is activated, if FALSE it is deactivated.

**str\_KL6581:** Is linked with the data structure of block [FB\_KL6581()](ms-xhelp:///?Id=beckhoff-45e5-4533-98ae-900c39c9c4dc) (see [STR\_KL6581](ms-xhelp:///?Id=beckhoff-5a94-43ed-9608-18055618a879)).

**byNode:** Filter - if the value is zero the EnOcean telegrams from all KL6583s are received. If a value of 1 to 8 is entered, only the data from the corresponding KL6583 are received.

## VAR\_OUTPUT

```
bReceive : BOOL := TRUE;  
iDevices : INT;  
ar_ID    : ARRAY [0..255] OF DWORD;
```

**bReceive:** On receiving an EnOcean telegram this value is set to FALSE for one cycle.

**iDevices:** Number of EnOcean devices found.

**ar\_ID:** EnOcean IDs that were found.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
