# str_KL6581

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# str\_KL6581

Internal structure.

This structure is used to link the block [FB\_KL6581()](ms-xhelp:///?Id=beckhoff-45e5-4533-98ae-900c39c9c4dc) with the send/receive blocks.

```
TYPE STR_KL6581 :  
STRUCT  
  by_Status : BYTE;  
  by_Node   : BYTE;  
  by_ORG    : BYTE;  
  ar_DB     : ARRAY[0..3] OF BYTE;  
  _Dummy    : BYTE;  
  dw_ID     : DWORD;  
  ptData    : PVOID;  
  iErrorId  : E_KL6581_Err;  
  by_STATE  : BYTE;  
  bError    : BOOL;  
  idx       : USINT;  
END_STRUCT  
END_TYPE
```

**by\_Status:** Status.

**by\_Node:** Node number of the KL6583 that has received the EnOcean telegram.

**by\_ORG:** EnOcean telegram type.

**ar\_DB:** Data bytes.

**\_Dummy:** Placeholder, no other purpose.

**dw\_ID:** Transmitter ID.

**ptData:** Pointer.

**iErrorId:** Describes the error type (see [E\_KL6581\_Err](ms-xhelp:///?Id=beckhoff-3415-4c23-8a89-721c05c3fbe1)).

**by\_STATE:** State.

**bError:** this output goes TRUE as soon as an error occurs. This error is described via the *iErrorId* variable.

**idx:** Index.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
