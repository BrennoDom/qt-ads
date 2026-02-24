# FB_MBUS_HYD_Sharky

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [POUs](ms-xhelp:///?Id=beckhoff-22fb-41cd-a51c-d1597d45a6ca)
4. [Hydrometer overview](ms-xhelp:///?Id=beckhoff-0aa5-4906-8601-9440c083cd4e)
5. FB\_MBUS\_HYD\_Sharky

# FB\_MBUS\_HYD\_Sharky

![49345813](/tcplclib_tc2_mbus/1033/Images/gif/174967051__en-US__Web.gif)

This block is used to read energy meters from:

Hydrometer:

-Sharky 773

-Sharky 775

-ENERGY INT 6

Brunata:

-Brunata Optuna H (775)

Aquametro:

-AMNTRONIC SONIC D

Only the most common values (see "VAR\_OUTPUT") of the telegrams:

00 ( Application Reset-Subcode 00 / All )  
10 ( Application Reset-Subcode 10 / User data)  
20 ( Application Reset-Subcode 20 / Simple billing)  
30 ( Application Reset-Subcode 30 / Enhanced billing)  
40 ( Application Reset-Subcode 40 / Multi tariff billing)  
or 50 ( Application Reset-Subcode 50 / Instant values)

are read.

The device is not switched to these telegrams; it must be set to one of these telegrams.

The block [FB\_MBUS\_HYD\_Sharky\_00()](ms-xhelp:///?Id=beckhoff-6f7c-4075-9022-42419a9f8748) can be used if further data are required, or the block [FB\_MBUS\_General\_Send()](ms-xhelp:///?Id=beckhoff-7b44-4f8f-aefc-9ad31e83ecd2) can be used to select the required telegram, and the block [FB\_MBUS\_General()](ms-xhelp:///?Id=beckhoff-8e90-4a30-8684-e4959275ff37) can be used to read all data of the respective telegram.

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
stVolume         : ST_MBus_Info;  
stFlow           : ST_MBus_Info;  
stForwardTemp    : ST_MBus_Info;  
stReturnTemp     : ST_MBus_Info;  
stTariff1        : ST_MBus_Info;
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

**stVolume:** Meter reading, water consumption (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stFlow:** Current water consumption (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stForwardTemp:** Flow temperature (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stReturnTemp:** Return temperature (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stTariff1:** Energy consumption tariff 1 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

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
