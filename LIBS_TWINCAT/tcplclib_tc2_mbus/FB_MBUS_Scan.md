# FB_MBUS_Scan

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [POUs](ms-xhelp:///?Id=beckhoff-22fb-41cd-a51c-d1597d45a6ca)
4. [General device blocks](ms-xhelp:///?Id=beckhoff-c2c9-4532-a008-46db7e04da46)
5. FB\_MBUS\_Scan

# FB\_MBUS\_Scan

![20640979](/tcplclib_tc2_mbus/1033/Images/gif/174947851__en-US__Web.gif)

This block can be used to scan the M-Bus bus. All primary addresses (0..250) are queried successively. The array *arrDevice* is used to show certain device information.

Only the primary address is used for scanning.

The [primary address](ms-xhelp:///?Id=beckhoff-3e32-45c4-90d9-d20c91a7dc41) of all devices must be set.

The block can only be executed together with the block [FB\_MBUSKL6781()](ms-xhelp:///?Id=beckhoff-2b5d-4be4-b4d2-353673675260).

## VAR\_INPUT

```
bStart       : BOOL;  
bStop        : BOOL;  
eBaudrate    : E_MBUS_Baudrate := eMBUS_Baud2400;  
bDisabled    : BOOL := FALSE;
```

**bStart:** The search is initiated with a positive edge at this input.

**bStop:** The search is stopped with a positive edge at this input.

**eBaudrate:** 300, 600, 1200, 2400, 4800, 9600 Baud.

**bDisabled:** TRUE = deselection of the block.

## VAR\_OUTPUT

```
bBusy            : BOOL;  
bReady           : BOOL;  
bError           : BOOL;  
eError           : E_MBUS_ERROR;  
usiAddress       : USINT;  
usiCount         : USINT;  
arrDevice        : ARRAY [0..250] OF ST_MBus_Scan;
```

**bBusy:** The *bBusy* output is TRUE while the meter is being read.

**bReady:** The *bReady* output is TRUE for one cycle, once meter reading is completed.

**bError:** this output goes TRUE as soon as an error occurs. This error is described via the variable *eError*.

**eError:** In the event of an error the output issues an error code (see [E\_MBUS\_ERROR](ms-xhelp:///?Id=beckhoff-4cab-465a-91d8-d2f9ff9e69d9)). *bError* goes TRUE at the same time.

**usiAddress:**  [Primary address](ms-xhelp:///?Id=beckhoff-3e32-45c4-90d9-d20c91a7dc41) of the meter to be read with this block.

**usiCount:** Number of detected valid devices.

**arrDevice:** Information about the detected devices (see [ST\_MBus\_scan](ms-xhelp:///?Id=beckhoff-7b33-49d3-b9e8-be8c85de826a)).

## VAR\_IN\_OUT

```
stCom : ST_MBUS_Communication;
```

**stCom:** This structure is used to link the block [FB\_MBUSKL6781()](ms-xhelp:///?Id=beckhoff-c554-4dbc-b2f4-dac10e7c746d) with the meter blocks (see [ST\_MBUS\_Communication](ms-xhelp:///?Id=beckhoff-c554-4dbc-b2f4-dac10e7c746d)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MBus from 3.3.4.0 |

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
