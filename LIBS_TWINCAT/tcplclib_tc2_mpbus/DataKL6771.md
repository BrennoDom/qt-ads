# DataKL6771

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [DUTs](ms-xhelp:///?Id=beckhoff-ec1f-451d-a0f5-4c656574c991)
4. [Structures](ms-xhelp:///?Id=beckhoff-9706-4771-ad0e-639d770876a0)
5. DataKL6771

# DataKL6771

Links the send and receive blocks with the function block *KL6771*

```
TYPE DataKL6771 :  
STRUCT  
  OrderNumber : BYTE;  
  ReciveData  : BOOL;  
  SendData    : BOOL;  
  Error       : BOOL;  
  ErrorID     : MP_Error;  
  pNumber     : DWORD;  
END_STRUCT  
END_TYPE
```

**OrderNumber:** Internal byte

**ReceiveData:** Data is being received.

**SendData:** Data is being sent.

**Error:** This output goes TRUE as soon as an error occurs. This error is described via the *ErrorID* variable.

**ErrorID:** This output outputs an error code in the event of an error (see [MP\_Error](ms-xhelp:///?Id=beckhoff-1b03-4e19-bdad-077c71ea9445)). *Error* goes TRUE at the same time.

**pNumber:** Internal pointer

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MPBus from 3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
