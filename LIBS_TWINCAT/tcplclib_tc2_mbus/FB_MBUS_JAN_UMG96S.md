# FB_MBUS_JAN_UMG96S

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [POUs](ms-xhelp:///?Id=beckhoff-22fb-41cd-a51c-d1597d45a6ca)
4. [Janitza overview](ms-xhelp:///?Id=beckhoff-dd49-4d17-b510-439c4a4a1348)
5. FB\_MBUS\_JAN\_UMG96S

# FB\_MBUS\_JAN\_UMG96S

![2107829](/tcplclib_tc2_mbus/1033/Images/gif/174986251__en-US__Web.gif)

This block is used to read electricity meters from Janitza:

-UMG96S

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

**eBaudrate:** 300, 2400, 9600 baud (see [E\_MBUS\_Baudrate](ms-xhelp:///?Id=beckhoff-9ee5-43e2-8e09-418785a2cd23)).

**bStart:** A positive edge of this input triggers one reading of the meter.

**bSND\_NKE:** TRUE initializes the meter for each read operation and sets the meter to the first telegram (SND\_NKE).

**bReadInit:** If the PLC is restarted, the meter is read once.

**tMinSendTime:** Standard t#2s. The meter is read again, once the time set here has elapsed. If t#0s the meter is not read and can be read manually with *bStart*.

**usiUnit:** Unit of the energy values to be output by the block. 0=W(h) / 1=KW(h) / 2 =MW(h) / 3=GW(h).

**bDisabled:** TRUE = deselection of the block.

## VAR\_OUTPUT

```
bBusy                   : BOOL;  
bReady                  : BOOL;  
bError                  : BOOL;  
eError                  : E_MBUS_ERROR;  
dwIdNumber              : DWORD;  
byStatus                : BYTE;  
byGEN                   : BYTE;  
byCounter               : BYTE;  
usiRecivedAdr           : USINT;  
eMedium                 : E_MBUS_Medium;  
sMan                    : STRING(3);  
stActiveEnergy          : ST_MBus_Info;  
stActiveEnergyTariff1   : ST_MBus_Info;  
stActiveEnergyTariff2   : ST_MBus_Info;  
stReactiveEnergy        : ST_MBus_Info;  
stReactiveEnergyTariff1 : ST_MBus_Info;  
stReactiveEnergyTariff2 : ST_MBus_Info;  
stApparentEnergy        : ST_MBus_Info;  
stActivePower           : ST_MBus_Info;  
stActivePowerL1         : ST_MBus_Info;  
stActivePowerL2         : ST_MBus_Info;  
stActivePowerL3         : ST_MBus_Info;  
stReactivePower         : ST_MBus_Info;  
stApparentPower         : ST_MBus_Info;  
stCurrent               : ST_MBus_Info;  
stCurrentL1             : ST_MBus_Info;  
stCurrentL2             : ST_MBus_Info;  
stCurrentL3             : ST_MBus_Info;  
stVoltageL1             : ST_MBus_Info;  
stVoltageL2             : ST_MBus_Info;  
stVoltageL3             : ST_MBus_Info;
```

**stActiveEnergy:** Active energy without backstop (telegram 2, data point 14) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stActiveEnergyTariff1:** Active energy, relative (telegram 2, data point 15) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stActiveEnergyTariff2:** Active energy, supplied (telegram 2, data point 16) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stReactiveEnergy:** Reactive energy, inductive (telegram 2, data point 17) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stReactiveEnergyTariff1:** Reactive energy, capacitive (telegram 2, data point 18) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stReactiveEnergyTariff2:** Reactive energy, without backstop (telegram 2, data point 19) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stApparentEnergy:** Apparent energy (telegram 2, data point 20) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stActivePower:** Instantaneous consumption, power, total (telegram 2, data point 29) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stActivePowerL1:** Instantaneous consumption, power, phase L1 (telegram 2, data point 38) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stActivePowerL2:** Instantaneous consumption, power, phase L2 (telegram 2, data point 39) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stActivePowerL3:** Instantaneous consumption, power, phase L3 (telegram 2, data point 40) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stReactivePower:** Reactive power (telegram 2, data point 30) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stApparentPower:** Apparent power (telegram 2, data point 31) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stCurrent:** Current (telegram 2, data point 28) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stCurrentL1:** Current L1 (telegram 2, data point 35) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stCurrentL2:** Current L2 (telegram 2, data point 36) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stCurrentL3:** Current L3 (telegram 2, data point 37) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stVoltageL1:** Voltage L1 (telegram 2, data point 32) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stVoltageL2:** Voltage L2 (telegram 2, data point 33) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

**stVoltageL3:** Voltage L3 (telegram 2, data point 34) (see [ST\_MBus\_Info](ms-xhelp:///?Id=beckhoff-02ee-4cac-966f-9064b61eceb8)).

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
