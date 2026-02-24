# FB_CX70xx_RW_EEPROM

## Library
tcplclib_tc2_systemcx

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
2. [Function Blocks](ms-xhelp:///?Id=beckhoff-ec9d-42ff-9fdd-c53aca476e55)
3. FB\_CX70xx\_RW\_EEPROM

# FB\_CX70xx\_RW\_EEPROM

The function block allows a maximum of 120 bytes to be written to the EEPROM (hardware) of the CX70xx. The EEPROM may be written to a maximum of 200 times. The memory is intended for one-time writing.

This function block can be used to personalize the CX70xx. That means, in the simplest case you write your company ID into the EEPROM. When starting the CX70xx program, read the contents of the memory. For example, if it is empty, you cannot continue to run the program because it is no longer your original CX70xx that you programmed.

If you want to exchange a CX70xx for a new device, the EEPROM must be written again by you.

## VAR\_INPUT

| Name | Type | Description |
| --- | --- | --- |
| bExecute | BOOL | A positive edge starts the function block. |
| eMode | E\_CX70xx\_EEPROM\_Mode | ReadOnly: EEPROM read WriteOnly: EEPROM write WriteAndRead: EEPROM write and read |
| pSrcBuf | PVOID | Pointer to the data buffer to be written. |
| cbSrcBufLen | UINT | Length of data to be written (max. 120 bytes) |
| pDstBuf | PVOID | Pointer to the data buffer into which the contents of the EEPROM are to be copied. |
| cbDstBufLen | UINT | Length of data to be read. (maximum 120 bytes) When reading, the length information must be greater than or equal to the data contained in the EEPROM. |

## VAR\_OUTPUT

| Name | Type | Description |
| --- | --- | --- |
| bBusy | BOOL | The function block is active and working. |
| bError | BOOL | The function block has an error. |
| nErrorID | UDINT | ADS Error Code Examples:  DEVICE\_INVALIDACCESS: the EEPROM write cycles have reached the maximum value. The EEPROM cannot be rewritten.  DEVICE\_INVALIDPARM: the allocated pointers are invalid/NULL.  DEVICE\_INVALIDSIZE: the allocated buffer size is too small or too large.  DEVICE\_SRVNOTSUPP: the image version of the CX70xx does not support this feature. An update (>=35695) is necessary. |
| nDataSizeEEPROM | UINT | Current size in bytes of the read EEPROM data |
| nWritesCycles | UINT | Number of write operations still available |

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024.22 | CX (x86, x64, ARM) | Tc2\_SystemCX (System) >= 3.4.7.0 |

[TwinCAT 3 | PLC Library: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
