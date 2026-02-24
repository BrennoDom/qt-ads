# FB_ASI_SlaveDiag

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [ASI master terminal](ms-xhelp:///?Id=beckhoff-eee2-417f-9360-0c5cf67a2427)
4. FB\_ASI\_SlaveDiag

# FB\_ASI\_SlaveDiag

![41372713](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314158859__Web.png)

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    stParameterBuffer : ST_ParameterBuffer;  
END_VAR
```

**stParameterBuffer**: Data buffer for the background communication (type: [ST\_ParameterBuffer](ms-xhelp:///?Id=beckhoff-24d8-4a67-bc8c-6e338fc526cd)).

## VAR\_INPUT

```
VAR_INPUT  
    iSlaveaddress : BYTE;  
    iCounter      : INT;(*1:PhysicalFaultCounter, 2:TimeoutCounter, 3:ResponseCounter, 4:Leave-DataExchCounter, 5:DataExch-FailedCounter *)  
    bCounterReset : BOOL;  
    bReadLES      : BOOL;(*Read List of all detected Slaves*)  
    bReadLAS      : BOOL;(*Read List of all activated Slaves*)  
    bStart        : BOOL;  
END_VAR
```

**iSlaveaddress**: slave address

**iCounter**: 1:PhysicalFaultCounter, 2:TimeoutCounter, 3:ResponseCounter, 4:Leave-DataExchCounter, 5:DataExch-FailedCounter

**bCounterReset**: resetting of the current counter.

**bReadLES**: List of the identified ASI Slaves (LES).

**bReadWrite**: 0=READ, 1=WRITE.

**bReadLAS**: List of the activated ASI Slaves (LAS).

**bStart**: The respective task is carried out via a rising edge at this boolean input.

**bCycleMode**: 0=continuous reading 1= reading once.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy         : BOOL;  
    bErr          : BOOL;  
    iErrornumber  : DWORD;(* Error code of ASI-Master *)  
    iCounterValue : WORD;(*Counter of a slave*)  
    iSlaveList    : DWORD;(*LES or LAS of all Slaves*)  
END_VAR
```

**bBusy**: This output remains TRUE until the block has executed a command. While Busy = TRUE, no new command will be accepted at the inputs. Please note that it is not the execution of the service but its acceptance whose time is monitored.

**bErr**: This output shows the error status.

**iErrornumber**: contains the command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs.

| Command-specific error code (decimal) | Description |
| --- | --- |
| 1 | Communication timeout |
| 2 | ASI slave address does not exist |
| 3 - 10 | Reserved |
| 11 | ASI slave is not activated (slave is not in LAS) |
| 12 | An error occurred during communication. |
| 13 | Data exchange bit (CN.4) not set |

**iCountervalue**: Counter value.

**iSlaveList**: LES or LAS.

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86) | ASI master terminal | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
