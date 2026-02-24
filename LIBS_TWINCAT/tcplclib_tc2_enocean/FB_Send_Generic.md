# FB_Send_Generic

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# FB\_Send\_Generic

![58405349](/tcplclib_tc2_enocean/1033/Images/gif/173376779__en-US__Web.gif)

This function block sends data via EnOcean. The type and the data contents are arbitrary. All kinds of EnOcean data telegrams can be sent with this block.

## VAR\_INPUT

```
bStart      : BOOL;  
by_Node     : BYTE;  
by_ORG      : E_EnOcean_Org;  
pt_SendData : DWORD;  
by_STATE    : BYTE;  
nEnOceanID  : BYTE;  
str_KL6581  : STR_KL6581;
```

**bStart:** A rising edge sends the data.

**by\_Node:** Address of the KL6583 module to which the telegram is to be sent (valid values: 1...8).

**by\_ORG:** ORG field of the EnOcean telegram (see [E\_EnOcean\_Org](ms-xhelp:///?Id=beckhoff-e3c8-482c-89a5-b64382283c8d)).

**pt\_SendData:** Pointer to the data to be sent. ADR is used to determine the pointer address. The pointer must point to 4-byte variable.

**by\_STATE:** EnOcean STATE. Can be changed by the TCM module.

**nEnOceanID:** Virtual EnOcean ID. A value of 0…127 is added to the real EnOcean ID (valid values: 0...127).

**str\_KL6581:** Is linked with the data structure of block [FB\_KL6581()](ms-xhelp:///?Id=beckhoff-45e5-4533-98ae-900c39c9c4dc) (see [STR\_KL6581](ms-xhelp:///?Id=beckhoff-5a94-43ed-9608-18055618a879)).

## VAR\_OUTPUT

```
bBusy    : BOOL;  
bError   : BOOL;  
iErrorID : E_KL6581_Err;
```

**bBusy:** The block is active. No new data can be sent at this stage.

**bError:** this output goes TRUE as soon as an error occurs. This error is described via the *iErrorId* variable.

**iErrorID:** Describes the error type (see [E\_KL6581\_Err](ms-xhelp:///?Id=beckhoff-3415-4c23-8a89-721c05c3fbe1)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
