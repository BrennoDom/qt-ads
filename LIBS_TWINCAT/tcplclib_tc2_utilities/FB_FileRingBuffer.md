# FB_FileRingBuffer

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_FileRingBuffer

![28015283](/tcplclib_tc2_utilities/1033/Images/png/9007199290222475__Web.png)

The FB\_FileRingBuffer function block allows data records of varying lengths to be written into a ring buffer file, or for data records that have previously been written there to be removed from the ring buffer file. The written data sets are read in the same order as they were previously written to the ring buffer file, based on the FIFO principle, i.e. the oldest entries are read first. Opening, closing, writing and reading the data records is controlled by action calls. The function block features the following tasks:

* **A\_Open** (opens an existing ring buffer file for appending or generating new data sets. An error is not returned if the file is already open. )
* **A\_Close** (Closes an open ring buffer file. An error is not returned if the file is already closed. )
* **A\_Create** (Opens a new ring buffer file. If the file already exists, it is overwritten. An error is not returned if the file is already open.)
* **A\_AddTail** (Write a new data record into the ring buffer file. )
* **A\_GetHead** (Reads the oldest data record from the ring buffer file, but does not remove it – the data pointer is not moved to the next data record. )
* **A\_RemoveHead** (Reads and removes the oldest data record from the ring buffer file – the data pointer is moved on to the next data record.)
* **A\_Reset** (Deletes all the data records from an open ring buffer file. Only the data pointer and the number of data records are reset; the existing physical file size is not changed, although the oldest data records will be overwritten by new ones.)

When a ring buffer file that already exists is opened, the file header is read first. In a ring buffer file that has previously been closed without error, bit 0 in the header status (Header.status.Bit 0) must be zero. If not, it is assumed that the file was not properly closed beforehand, and the corrupt file is replaced by a new, empty file, while Header.status.Bit 1 is set to 1 (file corrupted). When the file is closed, Header.status.Bit 0 is set to 0, and the complete file header is updated in the file.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId     : T_AmsNetId := '';  
    sPathName  : T_MaxString := 'c:\Temp\data.dat';  
    ePath      : E_OpenPath := PATH_GENERIC;  
    nID        : UDINT := 0;  
    cbBuffer   : UDINT := 16#100000;  
    bOverwrite : BOOL := FALSE;  
    pWriteBuff : POINTER TO BYTE;  
    cbWriteLen : UDINT;  
    pReadBuff  : POINTER TO BYTE;  
    cbReadLen  : UDINT;  
    tTimeout   : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: A string containing the network address of the TwinCAT computer where the buffer file is to be written or read can be given here (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**sPathName**: Contains the path and file name for the buffer file to be opened (type: T\_MaxString). **Notice**: The path can only point to the local computer’s file system! This means that network paths cannot be used here!

**ePath**: This input can be used to select a TwinCAT system path on the target device for opening the file (type: E\_OpenPath).

**nID**: User-defined 32-bit value. When a new file is opened, this value is saved in the file and can be used, for instance, for checking the version of the buffer file.

**cbBuffer**: The maximum size, in bytes, of the buffer file that is to be open. This parameter is saved in the file header when the file is created, and is checked when the same file is opened again. You can only reopen files that have been created using the same maximum buffer size. You cannot, in other words, create a file with a smaller buffer size, fill it with data records, and then open it again with a larger buffer size. If the check of the maximum buffer size fails, a new file with the new buffer size is automatically created and opened. Bit 1 (file corrupted) is also set in the file header status.

**bOverwrite:** Write behavior when the maximum file buffer size is reached. If TRUE is asserted at this input, the oldest entries are overwritten if the maximum file buffer size has already been reached. (Entries are deleted until there is enough free buffer size to save the new entry.) If FALSE is present at this input, a buffer overflow when the maximum file buffer size is reached is reported as an error.

**pWriteBuff:** The address of the PLC variable or of a buffer variable that contains the value data that is to be written. The address can be determined with the ADR operator. The programmer is himself responsible for dimensioning the buffer variable in such a way that *cbWriteLen* data bytes can be taken from it.

**cbWriteLen**: The number of value data bytes that are to be written. (In the case of string variables this includes the final null).

**pReadBuff**: The address of the PLC variables or of a buffer variable into which the value data that has been read is to be copied. The address can be determined with the ADR operator. The programmer is himself responsible for dimensioning the buffer variable in such a way that it can accept cbReadLen data bytes. The size of the buffer variables in bytes must be greater than or equal to the size of the data record that is to be read.

**cbReadLen**: The number of value data bytes to be read. If the buffer size is too small, data is not copied. The function block reports a buffer underflow error, and the buffer size required for the next data record that is to be read is returned at the *cbReturn* output.

**tTimeOut**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy     : BOOL;  
    bError    : BOOL;  
    nErrId    : UDINT;  
    cbReturn  : UDINT;  
    stHeader  : ST_FileRBufferHead;  
END_VAR
```

**bBusy**: When the function block is activated this output is set. It remains set until a feedback is received.

**bError**: In the event of an error during the command transfer, this output is set once the *bBusy* output has been reset.

**nErrId**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) or the command-specific error code (table) when the *bError* output is set.

**cbReturn**: The number of value data bytes successfully read. If a read buffer underflow error has occurred, this output supplies the necessary read buffer size in bytes.

**stHeader**: Ring buffer file header/status. (Type: [ST\_FileRBufferHead](ms-xhelp:///?Id=beckhoff-4c7d-43b5-8ac2-2f0a4220ec1b))

| Command-specific error codes | Error description |
| --- | --- |
| 0x8000 | Writing: File buffer is empty. Reading: File buffer overflow. |
| 0x8001 | PLC application: read buffer underflow (pReadBuff, cbReadLen) has been dimensioned too small. |
| 0x8002 | Ring buffer file is closed, and must be opened first. |
| 0x8003 | Input parameter has incorrect value. |

It is not essential for the PLC application to know the binary structure of the file. The following illustration, however, shows the general structure of the ring buffer file used:

|  |  |  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Header (48 bytes) see description of ST\_FileRBufferHead | Length of data set 1 (4 bytes) | Data set 1 | Length of data set 2  (4 bytes) | Data set 2 | Length of data set 3  (4 bytes) | Data set 3 | Length of data set n  (4 bytes) | Data set n |

An empty ring buffer file only contains the header. The buffer itself follows the header. The variables Header.ptrFirst and Header.ptrLast point to the position immediately behind the header. Writing causes the ptrLast data pointer to be moved onwards. The ptrFirst data pointer follows the ptrLast data pointer during reading. When the maximum buffer size is reached the pointers are returned to the start of the buffer.

**Example:**

See: [Example: File ring FiFo (FB\_FileRingBuffer).](ms-xhelp:///?Id=beckhoff-ceeb-446c-a0d0-c5c4a19ac918)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
