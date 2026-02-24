# MC_AxTableReadOutNonCyclic_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [TableFunctions](ms-xhelp:///?Id=beckhoff-978e-49e7-b056-ee4189e74a33)
5. MC\_AxTableReadOutNonCyclic\_BkPlcMc (from V3.0)

# MC\_AxTableReadOutNonCyclic\_BkPlcMc (from V3.0)

![15374270](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854776075__Web.gif)

The function block determines the slave values assigned to a master value with the aid of a table.

|  |  |
| --- | --- |
| 4150710 | This function block is a component of cam plates or similar non-linear couplings. It is generally not called direct by an application. |

```
VAR_INPUT  
    pTable:         POINTER TO LREAL:=0;  
    fMasterValue:   LREAL:=0.0;  
    nFirstIdx:      UDINT:=1;  
    nLastIdx:       UDINT:=1;  
    bReInit:        BOOL:=FALSE;  
END_VAR
```

```
VAR_OUTPUT  
    fSlaveValue:    LREAL:=0.0;  
    fSlaveGear:     LREAL:=0.0;  
    bUnderRange:    BOOL;  
    bOverRange:     BOOL;  
END_VAR
```

**pTable**: This parameter is used to transfer the address of an ARRAY[nFirstIdx..nLastIdx.1..2].

Note

**Crash of the PLC application**

An incorrect specification at this point causes the **PLC application to crash** through triggering of serious runtime errors (**Page Fault Exception**).

**fMasterValue**: This parameter is used to transfer the master value, for which the corresponding slave values are to be determined.

**nFirstIdx**: This parameter is used to transfer the lower index of the ARRAY, whose address is transferred as **pTable**.

**Attention**: An incorrect specification at this point causes the **PLC application to crash** through triggering of serious runtime errors (**Page Fault Exception**).

**nLastIdx**: This parameter is used to transfer the upper index of the ARRAY, whose address is transferred as **pTable**.

Note

**Crash of the PLC application**

An incorrect specification at this point causes the **PLC application to crash** through triggering of serious runtime errors (**Page Fault Exception**).

**bReInit**: This input indicates to the function block that the search procedure should start at the top of the table.

**fSlaveValue**: This parameter is used to output the slave value belonging to **fMasterValue**.

**fSlaveGear**: This parameter is used to output the local slope of the slave values at the point in the table specified by the master.

**bUnderRange**: This output becomes TRUE, if the master value reaches the bottom of the table or falls below it.

**bOverRange**: This output becomes TRUE, if the master value reaches the top of the table or exceeds it.

## Behaviour of the function block

The function block searches inside the transferred table for a master pair of values, which matches or includes the transferred **fMasterValue**. Within the found intervals a linear intermediate interpolation is calculated. The result is output as **fSlaveValue**. The local slope determined in this calculation is output as **fSlaveGear**.

If **fMasterValue** is below the value range described by the table, **bUnderRange** is indicated. The value output as **fSlaveValue** is the value allocated to the lowest point of the table. 0.0 is returned as **fSlaveGear**.

If **fMasterValue** is above the value range described by the table, **bOverRange** is indicated. The value output as **fSlaveValue** is the value allocated to the highest point of the table. 0.0 is returned as **fSlaveGear**.

The return value **fSlaveGear** represents the ratio of the first derivatives of **fMasterValue** and **fSlaveValue**. If **fMasterValue** represents a position or a virtual time, the multiplication of master progress velocity and **fSlaveGear** returns the set slave velocity. This can be used to generate a pilot-control velocity. An [MC\_AxRtSetExtGenValues\_BkPlcMc](ms-xhelp:///?Id=beckhoff-47ec-4355-83da-221f9f967897) function block is preferable for this purpose.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
