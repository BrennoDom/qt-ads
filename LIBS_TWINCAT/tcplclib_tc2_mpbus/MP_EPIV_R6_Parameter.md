# MP_EPIV_R6_Parameter

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [POUs](ms-xhelp:///?Id=beckhoff-d0d7-47c8-bb7c-a9b7cd043f93)
4. [Function blocks](ms-xhelp:///?Id=beckhoff-6545-479b-937c-f69f8d2863f3)
5. MP\_EPIV\_R6\_Parameter

# MP\_EPIV\_R6\_Parameter

![63390755](/tcplclib_tc2_mpbus/1033/Images/gif/5206626827__Web.gif)

This function block is used to parameterize drives of series EP..R-R6+BAC.

*MP\_Address* is used to specify the MP-Bus device with which the function block is to communicate. *bStart* activates communication with the MP-Bus device. *bBusy* indicates that the function block is active. *bError* is used to indicate an error in communication with the drive. The type of the error can be read with *iErrorID*.

## VAR\_INPUT

```
MP_Address           : USINT := 1;  
bStart               : BOOL;  
bRead_Write          : BOOL;  
strDataKL6771        : DataKL6771;  
nUnitSelection_Write : E_MP_EP_R_R6_UnitSel := E_MP_l_h;  
bControlMode_Write   : BOOL;  
rVmaxSeq1_Write      : LREAL;  
rVmaxSeq2_Write      : LREAL;
```

**MP\_Address:** MP-Bus address of the slave.

**bStart:** A rising edge starts the function block. If this remains continuously TRUE, the function block will be activated cyclically with a period specified in *TMPolling*.

**bRead\_Write:** If FALSE then READ only; if TRUE then READ and WRITE.

**strDataKL6771:** The data structure with which the [KL6771()](ms-xhelp:///?Id=beckhoff-c937-4fb9-a52b-2fb5de852d97) function block must be linked (see [DataKL6771](ms-xhelp:///?Id=beckhoff-b149-499c-8025-802a734c96f2)).

**nUnitSelection\_Write:** Scaling for *rAbsoluteFlow\_UnitSel* (see [E\_MP\_EP\_R\_R6\_UnitSel](ms-xhelp:///?Id=beckhoff-e690-4266-bc88-c7e9ed06dd6d)).

**bControlMode\_Write:** FALSE: position-controlled, TRUE: flow-controlled.

**rVmaxSeq1\_Write:** 0...100%.

**rVmaxSeq2\_Write:** 0...100%.

## VAR\_OUTPUT

```
bBusy               : BOOL;  
bError              : BOOL;  
iErrorId            : MP_Error;  
strMP_Serial_Number : MP_Serial_Number;  
nUnitSelection_Read : E_MP_EP_R_R6_UnitSel;  
bControlMode_Read   : BOOL;  
rVmaxSeq1_Read      : LREAL;  
rVmaxSeq2_Read      : LREAL;  
rAbsVnom_InitSel    : LREAL;  
rAbsVnom_l_h        : LREAL;  
rAbsVnom_gpm        : LREAL;
```

**bBusy:** This bit is set for as long as the function block is active.

**bError:** This output goes TRUE as soon as an error occurs. This error is described via the *iErrorId* variable.

**iErrorId:** This output outputs an error code in the event of an error (see [MP\_Error](ms-xhelp:///?Id=beckhoff-1b03-4e19-bdad-077c71ea9445)). *bError* goes TRUE at the same time.

**strMP\_Serial\_Number:** Structure for the serial number (see [MP\_Serial\_Number](ms-xhelp:///?Id=beckhoff-a3be-444b-bf90-d137036d8bb8)).

**nUnitSelection\_Read:** Setting the scaling (see [E\_MP\_EP\_R\_R6\_UnitSel](ms-xhelp:///?Id=beckhoff-e690-4266-bc88-c7e9ed06dd6d)).

**bControlMode\_Read:** FALSE: position-controlled, TRUE: flow-controlled.

**rVmaxSeq1\_Read:** Maximum sequence speed 1 in % (0...100%).

**rVmaxSeq2\_Read:** Maximum sequence speed 2 in % (0...100%).

**rAbsVnom\_InitSel:** Nominal volume (see *rAbsoluteFlow\_UnitSel*).

**rAbsVnom\_l\_h:** Nominal volume in l/h (0...4294967295).

**rAbsVnom\_gpm:** Nominal volume in gpm (0...4294967295).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.14 | Tc2\_MPBus from 3.4.8.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
