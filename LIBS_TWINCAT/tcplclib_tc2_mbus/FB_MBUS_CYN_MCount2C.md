# FB_MBUS_CYN_MCount2C

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [POUs](ms-xhelp:///?Id=beckhoff-22fb-41cd-a51c-d1597d45a6ca)
4. [Cynox](ms-xhelp:///?Id=beckhoff-b2dd-47ed-b4de-6d394d23143d)
5. FB\_MBUS\_CYN\_MCount2C

# FB\_MBUS\_CYN\_MCount2C

![50655658](/tcplclib_tc2_mbus/1033/Images/gif/3407927307__en-US__Web.gif)

This function block is used to read pulse counters from Cynox.

The function block can only be executed together with the function block [FB\_MBUSKL6781()](ms-xhelp:///?Id=beckhoff-2b5d-4be4-b4d2-353673675260).

[Functionality of the function block](ms-xhelp:///?Id=beckhoff-dfe8-4545-b25b-3fd875d7bad6)

## VAR\_INPUT

```
usiAddress   : USINT;  
stSecAdr     : ST_MBUS_SecAdr;  
eBaudrate    : E_MBUS_Baudrate := eMBUS_Baud2400;  
bStart       : BOOL;  
bSND_NKE     : BOOL := TRUE;  
bReadInit    : BOOL := TRUE;  
tMinSendTime : TIME := t#2s;  
bDisabled    : BOOL := FALSE;
```

**usiAddress:** 
[Primary address](ms-xhelp:///?Id=beckhoff-3e32-45c4-90d9-d20c91a7dc41) of the meter to be read with this block.

**stSecAdr:** 
[Secondary address](ms-xhelp:///?Id=beckhoff-91da-4e20-98b6-6c037a5efb7a) of the meter to be read with this block (see [ST\_MBUS\_SecAdr](ms-xhelp:///?Id=beckhoff-a78a-4fca-b07d-b2756fa9e090)).

**eBaudrate:** 2400 baud (see [E\_MBus\_Baudrate](ms-xhelp:///?Id=beckhoff-9ee5-43e2-8e09-418785a2cd23)).

**bStart:** A positive edge of this input triggers one reading of the meter.

**bSND\_NKE:** TRUE initializes the meter for each read operation and sets the meter to the first telegram (SND\_NKE).

**bReadInit:** If the PLC is restarted, the meter is read once.

**tMinSendTime:** Standard t#2s. The meter is read again, once the time set here has elapsed. If t#0s the meter is not read and can be read manually with *bStart*.

**bDisabled:** TRUE = deselection of the function block.

## VAR\_OUTPUT

```
bBusy           : BOOL;  
bReady          : BOOL;  
bError          : BOOL;  
eError          : E_MBUS_ERROR;  
dwIdNumber      : DWORD;  
byStatus        : BYTE;  
byGEN           : BYTE;  
byCounter       : BYTE;  
usiRecivedAdr   : USINT;  
eMedium         : E_MBUS_Medium;  
sMan            : STRING(3);  
stCurrent1      : ST_MBus_Info;  
stCurrent2      : ST_MBus_Info;  
stCurrent3      : ST_MBus_Info;  
stCurrent4      : ST_MBus_Info;  
stHistorical1   : ST_MBus_Info;  
stHistorical2   : ST_MBus_Info;  
stHistorical3   : ST_MBus_Info;  
stHistorical4   : ST_MBus_Info;  
stNextDeadline  : ST_MBus_Info;  
stLastDeadline  : ST_MBus_Info;  
stCurrentTime   : ST_MBus_Info;  
stOperatingTime : ST_MBus_Info;
```

**bBusy:** The *bBusy* output is TRUE while the meter is being read.

**bReady:** The *bReady* output is TRUE for one cycle, once meter reading is completed.

**bError:** this output goes TRUE as soon as an error occurs. This error is described via the variable *eError*.

**eError:** In the event of an error the output issues an error code (see [E\_MBUS\_ERROR](ms-xhelp:///?Id=beckhoff-4cab-465a-91d8-d2f9ff9e69d9)). *bError* goes TRUE at the same time.

**dwIdNumber:** Serial number of the meter (secondary address).

**byStatus:** Device status.

**byGEN:** Software version of the device.

**byCounter:** Number of times the master has accessed data of the respective slave.

**usiRecivedAdr:** Received primary address (0-250).

**eMedium:** Medium (see [E\_MBUS\_Medium](ms-xhelp:///?Id=beckhoff-c529-425e-8b1a-4d4c3080afd2)).

**sMan:** Manufacturer code.

**stCurrent1:** Current value 1 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stCurrent2:** Current value 2 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stCurrent3:** Current value 3 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stCurrent4:** Current value 4 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stHistorical1:** Historical value 1 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stHistorical2:** Historical value 2 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stHistorical3:** Historical value 3 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stHistorical4:** Historical value 4 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stNextDeadline:** Next reporting date (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stLastDeadline:** Last reporting date (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stCurrentTime:** Current time (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stOperatingTime:** Operating time (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

## VAR\_IN\_OUT

```
stCom : ST_MBUS_Communication;
```

**stCom:** This structure is used to link the block [FB\_MBUSKL6781()](ms-xhelp:///?Id=beckhoff-c554-4dbc-b2f4-dac10e7c746d) with the meter blocks (see [ST\_MBUS\_Communication](ms-xhelp:///?Id=beckhoff-c554-4dbc-b2f4-dac10e7c746d)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.32 | Tc2\_MBus from 3.4.6.0 |

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
