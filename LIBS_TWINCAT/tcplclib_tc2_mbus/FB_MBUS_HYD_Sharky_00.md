# FB_MBUS_HYD_Sharky_00

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [POUs](ms-xhelp:///?Id=beckhoff-22fb-41cd-a51c-d1597d45a6ca)
4. [Hydrometer overview](ms-xhelp:///?Id=beckhoff-0aa5-4906-8601-9440c083cd4e)
5. FB\_MBUS\_HYD\_Sharky\_00

# FB\_MBUS\_HYD\_Sharky\_00

![41459137](/tcplclib_tc2_mbus/1033/Images/gif/174970251__en-US__Web.gif)

This block is used to read energy meters from:

Hydrometer:

-Sharky 773

-Sharky 775

-ENERGY INT 6

Brunata:

-Brunata Optuna H (775)

Aquametro:

-AMNTRONIC SONIC D

All values of telegram 00 ( application reset subcode 00 / All ) are read. The device automatically switches to the corresponding mode.

stPulsecounter1 and stPulsecounter2 are only output if the pulse module is connected.

If further telegrams are required, the block [FB\_MBUS\_General\_Send()](ms-xhelp:///?Id=beckhoff-7b44-4f8f-aefc-9ad31e83ecd2) can be used to select the required telegram, and the block [FB\_MBUS\_General()](ms-xhelp:///?Id=beckhoff-8e90-4a30-8684-e4959275ff37) can be used to read all data of the respective telegram.

The block can only be executed together with the block [FB\_MBUSKL6781()](ms-xhelp:///?Id=beckhoff-2b5d-4be4-b4d2-353673675260).

[Functionality of the block](ms-xhelp:///?Id=beckhoff-dfe8-4545-b25b-3fd875d7bad6)

## VAR\_INPUT

```
usiAddress   : USINT;  
stSecAdr     : ST_MBUS_SecAdr;  
eBaudrate    : E_MBUS_Baudrate := eMBUS_Baud2400;  
bStart       : BOOL;  
bSND_NKE     : BOOL := TRUE;  
bReadInit    : BOOL := TRUE;  
tMinSendTime : TIME := t#2s;  
usiUnit      : USINT;  
bDisabled    : BOOL := FALSE;
```

**usiAddress:** 
[Primary address](ms-xhelp:///?Id=beckhoff-3e32-45c4-90d9-d20c91a7dc41) of the meter to be read with this block.

**stSecAdr:** 
[Secondary address](ms-xhelp:///?Id=beckhoff-91da-4e20-98b6-6c037a5efb7a) of the meter to be read with this block (see [ST\_MBUS\_SecAdr](ms-xhelp:///?Id=beckhoff-a78a-4fca-b07d-b2756fa9e090)).

**eBaudrate:** 300, 2400 baud (see [E\_MBUS\_Baudrate](ms-xhelp:///?Id=beckhoff-9ee5-43e2-8e09-418785a2cd23)).

**bStart:** A positive edge of this input triggers one reading of the meter.

**bSND\_NKE:** TRUE initializes the meter for each read operation and sets the meter to the first telegram (SND\_NKE).

**bReadInit:** If the PLC is restarted, the meter is read once.

**tMinSendTime:** Standard t#2s. The meter is read again, once the time set here has elapsed. If t#0s the meter is not read and can be read manually with *bStart*.

**usiUnit:** Unit of the energy values to be output by the block. 0=W(h) / 1=KW(h) / 2 =MW(h) / 3=GW(h).

**bDisabled:** TRUE = deselection of the block.

## VAR\_OUTPUT

```
bBusy            : BOOL;  
bReady           : BOOL;  
bError           : BOOL;  
eError           : E_MBUS_ERROR;  
dwIdNumber       : DWORD;  
byStatus         : BYTE;  
byGEN            : BYTE;  
byCounter        : BYTE;  
usiRecivedAdr    : USINT;  
eMedium          : E_MBUS_Medium;  
sMan             : STRING(3);  
stEnergy         : ST_MBus_Info;  
stTariff1        : ST_MBus_Info;  
stTariff2        : ST_MBus_Info;  
stVolume         : ST_MBus_Info;  
stPower          : ST_MBus_Info;  
stFlow           : ST_MBus_Info;  
stForwardTemp    : ST_MBus_Info;  
stReturnTemp     : ST_MBus_Info;  
stDiffTemp       : ST_MBus_Info;  
stOperatingHours : ST_MBus_Info;  
stDateTime       : ST_MBus_Info;  
stDueDay1        : ST_MBUS_DueDayHYD1;  
stDueDay2        : ST_MBUS_DueDayHYD1;  
stPulsecounter1  : ST_MBus_Info;  
stPulsecounter2  : ST_MBus_Info;
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

**stEnergy:** Meter reading, energy consumption (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stTariff1:** Meter reading tariff 1 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stTariff2:** Meter reading tariff 2 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stVolume:** Meter reading, water consumption (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stPower:** Current energy consumption, power (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stFlow:** Current water consumption (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stForwardTemp:** Flow temperature (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stReturnTemp:** Return temperature (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stDiffTemp:** Temperature difference (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stOperatingHours:** Current operating hours (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stDateTime:** Current date, time (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stDueDay1:** Values cutoff date 1 (see [ST\_MBUS\_DueDayHYD1](ms-xhelp:///?Id=beckhoff-3b68-4094-a9ed-d5f5420d949b)).

**stDueDay2:** Values cutoff date 2 (see [ST\_MBUS\_DueDayHYD1](ms-xhelp:///?Id=beckhoff-3b68-4094-a9ed-d5f5420d949b)).

**stPulsecounter1:** Meter reading pulse counter 1 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stPulsecounter2:** Meter reading pulse counter 2 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

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
