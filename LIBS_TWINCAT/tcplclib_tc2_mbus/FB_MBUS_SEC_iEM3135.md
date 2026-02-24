# FB_MBUS_SEC_iEM3135

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [POUs](ms-xhelp:///?Id=beckhoff-22fb-41cd-a51c-d1597d45a6ca)
4. [Schneider Electric](ms-xhelp:///?Id=beckhoff-bc65-431f-a2ea-4ef56add593c)
5. FB\_MBUS\_SEC\_iEM3135

# FB\_MBUS\_SEC\_iEM3135

![11533784](/tcplclib_tc2_mbus/1033/Images/gif/3408128011__en-US__Web.gif)

This function block is used to read electricity meters from Schneider Electric.

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

**eBaudrate:** 300..9600 baud (see [E\_MBUS\_Baudrate](ms-xhelp:///?Id=beckhoff-9ee5-43e2-8e09-418785a2cd23)).

**bStart:** A positive edge of this input triggers one reading of the meter.

**bSND\_NKE:** TRUE initializes the meter for each read operation and sets the meter to the first telegram (SND\_NKE).

**bReadInit:** If the PLC is restarted, the meter is read once.

**tMinSendTime:** Standard t#2s. The meter is read again, once the time set here has elapsed. If t#0s the meter is not read and can be read manually with *bStart*.

**bDisabled:** TRUE = deselection of the function block.

## VAR\_OUTPUT

```
bBusy                : BOOL;  
bReady               : BOOL;  
bError               : BOOL;  
eError               : E_MBUS_ERROR;  
dwIdNumber           : DWORD;  
byStatus             : BYTE;  
byGEN                : BYTE;  
byCounter            : BYTE;  
usiRecivedAdr        : USINT;  
eMedium              : E_MBUS_Medium;  
sMan                 : STRING(3);  
stCurrentPhase1      : ST_MBus_Info;  
stCurrentPhase2      : ST_MBus_Info;  
stCurrentPhase3      : ST_MBus_Info;  
stCurrentAverage     : ST_MBus_Info;  
stVoltageL1N         : ST_MBus_Info;  
stVoltageL2N         : ST_MBus_Info;  
stVoltageL3N         : ST_MBus_Info;  
stVoltageAverageLN   : ST_MBus_Info;  
stVoltageL1L2        : ST_MBus_Info;  
stVoltageL2L3        : ST_MBus_Info;  
stVoltageL3L1        : ST_MBus_Info;  
stVoltageAverageLL   : ST_MBus_Info;  
stPowerActivePhase1  : ST_MBus_Info;  
stPowerActivePhase2  : ST_MBus_Info;  
stPowerActivePhase3  : ST_MBus_Info;  
stPowerActiveTotal   : ST_MBus_Info;  
stPowerReactiveTotal : ST_MBus_Info;  
stPowerApparentTotal : ST_MBus_Info;  
stPowerFactorTotal   : ST_MBus_Info;  
stFrequency          : ST_MBus_Info;
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

**stCurrentPhase1:** Current intensity phase 1 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stCurrentPhase2:** Current intensity phase 2 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stCurrentPhase3:** Current intensity phase 3 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stCurrentAverage:** Average value of current intensity (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stVoltageL1N:** Voltage L1-N (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stVoltageL2N:** Voltage L2-N (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stVoltageL3N:** Voltage L3-N (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stVoltageAverageLN:** Average value of voltage L-N (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stVoltageL1L2:** Voltage L1-L2 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stVoltageL2L3:** Voltage L2-L3 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stVoltageL3L1:** Voltage L3-L1 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stVoltageAverageLL:** Average value of voltage L-L (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stPowerActivePhase1:** Effective power phase 1 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stPowerActivePhase2:** Effective power phase 2 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stPowerActivePhase3:** Effective power phase 3 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stPowerActiveTotal:** Total effective power (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stPowerReactiveTotal:** Total reactive power (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stPowerApparentTotal:** Total apparent power (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stPowerFactorTotal:** Power factor (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stFrequency:** Frequency (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

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
