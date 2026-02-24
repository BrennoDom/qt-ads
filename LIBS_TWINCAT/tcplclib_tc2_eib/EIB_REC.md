# EIB_REC

## Library
tcplclib_tc2_eib

## Category
Motion Control

# EIB\_REC

Links the send and receive function blocks with the function block *KL6301*.

```
TYPE EIB_REC :  
STRUCT  
  Rec_Group      : EIB_GROUP_ADDR;  
  Rec_Len        : INT;  
  Rec_Idx        : INT := 1;  
  Rec_Data       : ARRAY[1..15] OF BYTE;  
  Rec_bWriteBusy : BOOL;  
  Rec_bReadBusy  : BOOL;  
  Rec_bReady     : BOOL;  
  Rec_bError     : BOOL;  
  Rec_iErrorID   : EIB_Error_Code;  
  pStr_Send      : PVOID;  
  Rec_Data_rec   : BOOL;  
  Rec_Typ        : EIB_Read_Typ;  
END_STRUCT  
END_TYPE
```

**Rec\_Group:** Group address (see [EIB\_GROUP\_ADDR](ms-xhelp:///?Id=beckhoff-b660-4bbb-871b-bcd96d7eaa4e))

**Rec\_Len:** Length

**Rec\_Idx:** Index

**Rec\_Data:** Data bytes

**Rec\_bWriteBusy:** Data is written

**Rec\_bReadBusy:** Data is read

**Rec\_bReady:** Ready

**Rec\_bError:** This output goes TRUE as soon as an error occurs. This error is described via the variable *Rec\_iErrorID*.

**Rec\_iErrorID:** This output outputs an error code in the event of an error (see [EIB\_ERROR\_CODE](ms-xhelp:///?Id=beckhoff-9096-470f-8523-760659ef887f)). *bError* goes TRUE at the same time.

**pStr\_Send:** Pointer to the data to be sent.

**Rec\_Data\_rec:** Signals reception of data.

**Rec\_Typ:** Type of telegram.

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_EIB from 3.3.4.0 |
