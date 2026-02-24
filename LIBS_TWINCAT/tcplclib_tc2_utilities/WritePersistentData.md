# WritePersistentData

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# WritePersistentData

![4437887](/tcplclib_tc2_utilities/1033/Images/png/9007199290459275__Web.png)

If persistent variables are defined in a PLC runtime system, their current values are normally saved in a .bootdata file in the TwinCAT\Boot folder when stopping/shutting down the TwinCAT system (following the last PLC cycle). Before writing the current persistent data to the file, a backup of the old persistent data is made by renaming the system's old .bootdata file to .bootdata-old.

A file is created for every runtime system that is configured.

The next time the system starts, the .bootdata file is read and the persistent variables in the runtime system are initialized with the values from the file.

This backup file (.bootdata-old) of the persistent data is read at system startup if the file (.bootdata) containing the persistent data does not exist. This is an exception, but it can occur, for example, if an IPC without UPS experiences a power failure and TwinCAT could not shut down properly.

With the WritePersistentData function block you can initiate the saving of the persistent data from the PLC program and ensure that an up-to-date .bootdata file with the persistent data is available. The PORT input parameter specifies the runtime system whose persistent data is to be saved.

## VAR\_INPUT

```
VAR_INPUT  
    NETID  : T_AmsNetId;  
    PORT   : T_AmsPort;  
    START  : BOOL;  
    TMOUT  : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: Network address of the TwinCAT computer on which the ADS command is to be executed (type: T\_AmsNetID). An empty string can be entered for the local computer.

**PORT**: ADS port number of the PLC runtime system whose persistent data is to be saved (type: T\_AmsPort).

**START**: The function block is activated by a positive edge at this input.

**TMOUT**: Timeout time that may not be exceeded when executing the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY  : BOOL;  
    ERR   : BOOL;  
    ERRID : UDINT;  
END_VAR
```

**BUSY**: When the function block is activated this output is set. It remains set until a feedback is received.

**ERR**: If an ADS error should occur during the transfer of the command, then this output is set once the BUSY output is reset.

**ERRID**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the ERR output is set.

**Example:**

```
PROGRAM MAIN  
VAR  
    bStart                : BOOL;  
    bError                : BOOL;  
    bBusy                 : BOOL;  
    nErrorId              : UDINT;  
    fbWritePersistentData : WritePersistentData;  
    fbR_Trig              : R_TRIG;  
END_VAR
```

```
VAR PERSISTENT  
    perA  : INT;  
    perB  : BOOL;  
    perC  : BYTE;  
    perD  : STRING;  
    perE  : ARRAY[0..10] OF INT;  
    perF  : ARRAY[0..10] OF UDINT;  
END_VAR
```

```
fbR_Trig( CLK:=bStart );  
IF fbR_Trig.Q THEN  
    perA := 24443;  
    perB := TRUE;  
    perC := 7;  
    perD := 'Switch ON/OFF';  
    perE[ 0 ] := 1;  
    perE[ 10 ] := 11;  
    perF[ 0 ] := 263;  
    perF[ 10 ] := 23323;  
    fbWritePersistentData(NETID:='', PORT:=851, START:=bStart, TMOUT:=T#1s );  
ELSE  
    fbWritePersistentData( START:=FALSE);  
END_IF;  
  
bBusy := fbWritePersistentData.BUSY;  
bError := fbWritePersistentData.ERR;  
nErrorId := fbWritePersistentData.ERRID;
```

See also: Appendix > [System behavior when writing persistent data](ms-xhelp:///?Id=beckhoff-7dbf-469d-9b3d-bb346f7d2cc4)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
