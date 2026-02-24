# FB_MBUS_TIP_SINUS85M

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [POUs](ms-xhelp:///?Id=beckhoff-22fb-41cd-a51c-d1597d45a6ca)
4. [TIP](ms-xhelp:///?Id=beckhoff-a2a5-44a1-a89d-f21ae2dda7df)
5. FB\_MBUS\_TIP\_SINUS85M

# FB\_MBUS\_TIP\_SINUS85M

![41471619](/tcplclib_tc2_mbus/1033/Images/gif/3408129931__en-US__Web.gif)

This function block is used to read electricity meters from Thüringer Industrie Produkte GmbH.

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

**eBaudrate:** 300, 600, 1200, 2400, 4800, 9600 baud (see [E\_MBUS\_Baudrate](ms-xhelp:///?Id=beckhoff-9ee5-43e2-8e09-418785a2cd23)).

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
stActivePowerTariff1 : ST_MBus_Info;  
stActivePowerTariff2 : ST_MBus_Info;  
stApparentPowerL1    : ST_MBus_Info;  
stApparentPowerL2    : ST_MBus_Info;  
stApparentPowerL3    : ST_MBus_Info;  
stApparentPowerTotal : ST_MBus_Info;  
stActivePowerL1      : ST_MBus_Info;  
stActivePowerL2      : ST_MBus_Info;  
stActivePowerL3      : ST_MBus_Info;  
stActivePowerTotal   : ST_MBus_Info;  
stReactivePowerL1    : ST_MBus_Info;  
stReactivePowerL2    : ST_MBus_Info;  
stReactivePowerL3    : ST_MBus_Info;  
stReactivePowerTotal : ST_MBus_Info;  
stVoltageL1          : ST_MBus_Info;  
stVoltageL2          : ST_MBus_Info;  
stVoltageL3          : ST_MBus_Info;  
stPowerLineFrequency : ST_MBus_Info;  
stCurrentTariff      : ST_MBus_Info;  
stCurrentL1          : ST_MBus_Info;  
stCurrentL2          : ST_MBus_Info;  
stCurrentL3          : ST_MBus_Info;  
stCurrentTotal       : ST_MBus_Info;  
stPowerFactorL1      : ST_MBus_Info;  
stPowerFactorL2      : ST_MBus_Info;  
stPowerFactorL3      : ST_MBus_Info;  
stPowerFactorTotal   : ST_MBus_Info;
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

**stActivePowerTariff1:** Active energy import tariff 1 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stActivePowerTariff2:** Active energy import tariff 2 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stApparentPowerL1:** Current apparent power L1 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stApparentPowerL2:** Current apparent power L2 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stApparentPowerL3:** Current apparent power L3 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stApparentPowerTotal:** Current total apparent power (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stActivePowerL1:** Current effective power phase L1 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stActivePowerL2:** Current effective power phase L2 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stActivePowerL3:** Current effective power phase L3 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stActivePowerTotal:** Current total effective power (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stReactivePowerL1:** Current reactive power phase L1 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stReactivePowerL2:** Current reactive power phase L2 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stReactivePowerL3:** Current reactive power phase L3 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stReactivePowerTotal:** Current total reactive power (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stVoltageL1:** Current voltage phase L1 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stVoltageL2:** Current voltage phase L2 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stVoltageL3:** Current voltage phase L3 (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stPowerLineFrequency:** Current mains frequency (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stCurrentTariff:** Current tariff (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stCurrentL1:** Current phase L1 current (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stCurrentL2:** Current phase L2 current (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stCurrentL3:** Current phase L3 current (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stCurrentTotal:** Current total current (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stPowerFactorL1:** Current form factor phase L1 (cos Phi) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stPowerFactorL2:** Current form factor phase L2 (cos Phi) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stPowerFactorL3:** Current form factor phase L3 (cos Phi) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stPowerFactorTotal:** Current total form factor (cos Phi) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

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
