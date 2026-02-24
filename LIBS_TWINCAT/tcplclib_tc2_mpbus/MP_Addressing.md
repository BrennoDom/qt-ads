# MP_Addressing

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [POUs](ms-xhelp:///?Id=beckhoff-d0d7-47c8-bb7c-a9b7cd043f93)
4. [Function blocks](ms-xhelp:///?Id=beckhoff-6545-479b-937c-f69f8d2863f3)
5. MP\_Addressing

# MP\_Addressing

![58038438](/tcplclib_tc2_mpbus/1033/Images/gif/181503883__en-US__Web.gif)

This function block allows an MP-Bus slave to be addressed. It is also possible to use this function block to read the serial number of the slave.  
*MP\_Address* is used to transfer the address of the slave that is addressed or whose serial number is to be read. The serial number is read out on a rising edge of *bReadAddr*. It is output through *MP\_Serial\_Numer\_Out*. A rising edge of *bAddrAuto* addresses a slave whose address is *MP\_Address*. The function block waits for the time set in *TMOUT* for the transmission of the slave with its serial number. Transmission of the serial number is initiated differently from one slave to another. Please see the documentation for the MP-Bus device for how the serial number can be sent (in most cases there is a switch on the drive which will trigger this action when pressed). No telegrams are sent to the slaves during the time specified by *TMOUT*.

A rising edge at *bAddrManual* initiates manual addressing. This requires the serial number of the drive to be stored in *MP\_Serial\_Number\_In*. The serial number of the slave can be found on a sticker on the drive.

Sample: 00234-00016-002-031. Enter the following in the variable *MP\_Serial\_Number\_IN*:

YearAndWeek = 234

DayAndNumber = 16

DeviceFamily = 2

TestStation = 31

FamilySuffix = is not evaluated, and should therefore be ignored.

*bBusy* is set for as long as the function block is active. An error is indicated through *bError*, while the error number can be read with *iErrorId*.

## VAR\_INPUT

```
MP_Address          : USINT := 1;  
bAddrAuto           : BOOL;  
bReadAddr           : BOOL;  
bAddrManual         : BOOL;  
MP_Serial_Number_IN : MP_Serial_Number;  
TMOUT               : TIME := t#30s;  
strDataKL6771       : DataKL6771;
```

**MP\_Address:** The MP address that is to be used for the addressing or for reading the serial number. Valid values (1...8)

**bAddrAuto:** A rising edge starts the function block. The function block halts other MP-Bus communication, and waits until the time set through *TMOUT* has elapsed for an MP-Bus slave has transmitted its serial number, for instance in response to pressing a switch. The MP-Bus address that has been configured in the *MP\_Address* variable is then transmitted to the slave.

**bReadAddr:** A rising edge starts the function block. The function block reads the serial number of the MP-Bus slave whose address is *MP\_Address*.

**bAddrManual:** A rising edge starts the function block. The function block addresses the slave that has serial number *MP\_Serial\_Number\_IN*. The slave's addresses configured with *MP\_Address*.

**MP\_Serial\_Number\_IN:** Serial number of the device (see [MP\_Serial\_Number](ms-xhelp:///?Id=beckhoff-a3be-444b-bf90-d137036d8bb8)).

**TMOUT:** Automatic addressing is interrupted after the time specified by *TMOUT*.

**strDataKL6771:** The data structure with which the [KL6771()](ms-xhelp:///?Id=beckhoff-c937-4fb9-a52b-2fb5de852d97) function block must be linked (see [DataKL6771](ms-xhelp:///?Id=beckhoff-b149-499c-8025-802a734c96f2)).

## VAR\_OUTPUT

```
bBusy                : BOOL;  
bError               : BOOL;  
iErrorId             : MP_Error;  
MP_Serial_Number_OUT : MP_Serial_Number;
```

**bBusy:** This bit is set for as long as the function block is active.

**bError:** This output goes TRUE as soon as an error occurs. This error is described via the iErrorId variable.

**iErrorId:** This output outputs an error code in the event of an error (see [MP\_Error](ms-xhelp:///?Id=beckhoff-1b03-4e19-bdad-077c71ea9445)). *bError* goes TRUE at the same time.

**MP\_Serial\_Number\_OUT:** The serial number of the addressed or queried slave (see [MP\_Serial\_Number](ms-xhelp:///?Id=beckhoff-a3be-444b-bf90-d137036d8bb8)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MPBus from 3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
