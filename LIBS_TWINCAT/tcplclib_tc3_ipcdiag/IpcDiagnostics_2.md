# IpcDiagnostics_2

## Library
tcplclib_tc3_ipcdiag

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
2. [Samples](ms-xhelp:///?Id=beckhoff-c692-4bbf-a324-a2db194d6c8a)
3. IpcDiagnostics\_2

# IpcDiagnostics\_2

This sample is very similar to the IpcDiagnostics sample and differs only in terms of the implementation flavor and optional writing of a parameter.

The program is structured in such a way that it can easily be adapted for access to other IPC diagnostics parameters.

**Enumeration definition**

```
{attribute 'qualified_only'}  
TYPE E_State :  
(  
    Init,  
    Idle,  
    ReadOnce_CpuUsage,  
    ReadOnce_CpuTemperature,  
    ReadOnce_SrnMainboard,  
    ReadOnce_SrnIPC,  
    Write_DHCP,  
    Write_IPAddr,  
    ReadPeriodically,  
    Error  
);  
END_TYPE
```

**Variable Declaration**

```
PROGRAM MAIN  
VAR  
    bStart                 : BOOL := TRUE;           // flag to trigger (re)start of statemachine  
    bSkipSettingIPAddr     : BOOL := TRUE;           // for safety reasons - set FALSE if you want to set the IP address  
    eState                 : E_State := E_State.Init;  
      
    bError                 : BOOL;                   // error flag (indicator: error occured)  
    hrErrorCode            : HRESULT;                // last error code  
    hrGetValue             : HRESULT;  
      
    nCpuUsage              : UINT;                   // CPU usage [%]  
    nCpuTemperature        : INT;                    // CPU temerature [°C]  
    sSerialNumberMainboard : STRING;                 // serial number of mainboard  
    sSerialNumberIPC       : STRING;                 // serial number of IPC  
    nNicModuleIdx          : USINT := 1;             // select which NIC adapter should be adapted with a new IP address  
    bDHCP                  : BOOL := FALSE;  
    sIPAddr                : T_IPv4Addr := '174.18.3.154'; // the new ip address   
    aFanSpeed              : ARRAY[1..2] OF UINT;    // speed of fans - should be read periodically  
      
    fbDiagRegister         : FB_IPCDiag_Register := (sNetId:=cNetId);  
    fbDiagRead             : FB_IPCDiag_ReadParameter := (sNetId:=cNetId);  
    fbDiagReadPeriodic     : FB_IPCDiag_ReadParameterPeriodic := (tPeriod:= T#10S, sNetId:=cNetId);  
    fbDiagWrite            : FB_IPCDiag_WriteParameter := (sNetId:=cNetId);  
END_VAR  
VAR CONSTANT  
    cNetId : T_AmsNetID := ''; // local  
END_VAR
```

**Initialization**

```
E_State.Init:  
    IF NOT fbDiagRegister.bBusy THEN  
        fbDiagRegister(bExecute:=TRUE);  
    ELSE  
        fbDiagRegister(bExecute:=FALSE, bError=>bError, hrErrorCode=>hrErrorCode);  
    END_IF  
    IF NOT fbDiagRegister.bBusy THEN  
        IF fbDiagRegister.bError THEN  
            eState := E_State.Error;  
        ELSE  
            eState := E_State.Idle;  
        END_IF  
    END_IF
```

**Simple parameter query (using CPU temperature as an example)**

```
E_State.ReadOnce_CpuTemperature:  
    IF NOT fbDiagRead.bBusy THEN  
        fbDiagRead(bExecute:= TRUE, eParameterKey:=E_IPCDiag_ParameterKey.CPU_Temp, fbRegister:=fbDiagRegister);      
    ELSE  
        fbDiagRead(bExecute:= FALSE, fbRegister:=fbDiagRegister, bError=>bError, hrErrorCode=>hrErrorCode);  
    END_IF  
    IF NOT fbDiagRead.bBusy THEN  
        IF fbDiagRead.bError THEN  
            eState := E_State.Error;  
        ELSE // get value  
            hrGetValue := fbDiagRead.GetParameter(pBuffer:=ADR(nCpuTemperature), nBufferSize:=SIZEOF(nCpuTemperature));      
            IF FAILED(hrGetValue) THEN  
                eState := E_State.Error;  
            ELSE  
                eState := E_State.ReadOnce_SrnMainboard;  
            END_IF  
        END_IF  
    END_IF        
```

**Writing a parameter (using the IP address as an example)**

```
E_State.Write_IPAddr:  
    IF NOT fbDiagWrite.bBusy THEN  
        fbDiagWrite(bExecute:= TRUE,   
                    eParameterKey:=E_IPCDiag_ParameterKey.NIC_IPv4Address,  
                    pBuffer:=ADR(sIPAddr),  
                    nBufferSize:=INT_TO_UDINT(LEN(sIPAddr)+1),  
                    nModuleIdx:=nNicModuleIdx,  
                    fbRegister:=fbDiagRegister );      
    ELSE  
        fbDiagWrite(bExecute:= FALSE, fbRegister:=fbDiagRegister, bError=>bError, hrErrorCode=>hrErrorCode);  
    END_IF  
    IF NOT fbDiagWrite.bBusy THEN  
        IF fbDiagWrite.bError THEN  
            eState := E_State.Error;  
        ELSE  
            eState := E_State.ReadPeriodically;  
        END_IF  
    END_IF
```

**Periodic query of a parameter (using the fan speed as an example)**

```
E_State.ReadPeriodically:  
    fbDiagReadPeriodic(bEnable:=TRUE, eParameterKey:=E_IPCDiag_ParameterKey.Fan_Speed, fbRegister:=fbDiagRegister,  
                       bError=>bError, hrErrorCode=>hrErrorCode);  
    IF fbDiagReadPeriodic.bValid THEN  
        fbDiagReadPeriodic.GetParameter(pBuffer:=ADR(aFanSpeed), nBufferSize:=SIZEOF(aFanSpeed) );      
    END_IF  
    IF fbDiagReadPeriodic.bError THEN  
        eState := E_State.Error;  
    END_IF    
```

[TwinCAT 3 | PLC Library: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
