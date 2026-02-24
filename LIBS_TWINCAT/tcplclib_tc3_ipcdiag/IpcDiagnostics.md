# IpcDiagnostics

## Library
tcplclib_tc3_ipcdiag

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
2. [Samples](ms-xhelp:///?Id=beckhoff-c692-4bbf-a324-a2db194d6c8a)
3. IpcDiagnostics

# IpcDiagnostics

The sample shows the simple reading of various IPC diagnostics parameters with the help of the function blocks [FB\_IPCDiag\_ReadParameter](ms-xhelp:///?Id=beckhoff-41de-431c-804d-3aa55cec49b6) and [FB\_IPCDiag\_ReadParameterPeriodic](ms-xhelp:///?Id=beckhoff-9a5b-4fe1-ae2d-e530f7797ee1).

Six parameters are read once only and one parameter whose values change over time is read periodically. Variables are created for these parameters.

```
PROGRAM IpcDiagnostics  
VAR CONSTANT  
    cNetId         : T_AmsNetID := '';        // local  
    cNbrParameters : UDINT := 6;              // number of parameters to read  
END_VAR  
VAR  
    sDeviceName     : STRING(39);  
    nCpuFreq        : UDINT;  
    nTcBuild        : UINT;  
    aNetworkNames   : ARRAY[1..3] OF STRING(79); // array in order to receive info of up to three network ports (NICs)  
    aIpAddr         : ARRAY[1..3] OF STRING(39); // array in order to receive info of up to three network ports (NICs)  
    aDHCP           : ARRAY[1..3] OF BOOL;       // array in order to receive info of up to three network ports (NICs)  
    nCpuTemperature : INT;                       // should be read periodically  
  
    eState           : E_State := E_State.Init;  
    hrGetValue       : HRESULT;  
    fbDiagRegister   : FB_IPCDiag_Register := (sNetId:=cNetId);  
    fbDiagRead       : FB_IPCDiag_ReadParameter := (sNetId:=cNetId);  
    nKeyIdx          : USINT := 1;  
    aParameterKeys   : ARRAY[1..cNbrParameters] OF E_IPCDiag_ParameterKey   
                                                   := [ E_IPCDiag_ParameterKey.IPCDeviceName,  
                                                        E_IPCDiag_ParameterKey.CPU_Frequency,  
                                                        E_IPCDiag_ParameterKey.TC_VersionBuild,  
                                                        E_IPCDiag_ParameterKey.NIC_Name,  
                                                        E_IPCDiag_ParameterKey.NIC_IPv4Address,  
                                                        E_IPCDiag_ParameterKey.NIC_DHCP ];  
    fbDiagReadPeriodic : FB_IPCDiag_ReadParameterPeriodic := (eParameterKey:=E_IPCDiag_ParameterKey.eCPU_Temp,   
                                                              tPeriod:= T#10S, sNetId:=cNetId);  
END_VAR
```

Each parameter is read as follows: The instance of `FB_IPCDiag_ReadParameter` is triggered and called cyclically until the reading procedure is completed. Following that, the parameter is copied using the `GetParameter()` method to its own variable, which has been prepared for the purpose.

```
E_State.ReadOnce: // reads every parameter once  
    IF NOT fbDiagRead.bBusy THEN  
        fbDiagRead(bExecute:= TRUE, eParameterKey:=aParameterKeys[nKeyIdx], fbRegister:=fbDiagRegister);      
    ELSE  
        fbDiagRead(bExecute:= FALSE, fbRegister:=fbDiagRegister);  
    END_IF  
    IF NOT fbDiagRead.bBusy THEN  
        IF fbDiagRead.bError THEN  
            eState := E_State.Error;  
        ELSE // get value  
            IF aParameterKeys[nKeyIdx] = E_IPCDiag_ParameterKey.IPCDeviceName THEN  
                hrGetValue := fbDiagRead.GetParameter(pBuffer:=ADR(sDeviceName), nBufferSize:=SIZEOF(sDeviceName));  
                  
            ELSIF aParameterKeys[nKeyIdx] = E_IPCDiag_ParameterKey.CPU_Frequency THEN  
                hrGetValue := fbDiagRead.GetParameter(pBuffer:=ADR(nCpuFreq), nBufferSize:=SIZEOF(nCpuFreq));  
  
            ...  
  
            END_IF  
                  
            IF SUCCEEDED(hrGetValue) THEN  
                IF nKeyIdx = cNbrParameters THEN // all keys successfully read  
                    nKeyIdx := 1;  
                    eState := E_State.ReadPeriodically;  
                ELSE  
                    nKeyIdx := nKeyIdx + 1;  
                END_IF  
            ELSE  
                eState := E_State.Error;  
            END_IF  
        END_IF  
    END_IF    
```

Once all six parameters have been read successfully, the state of the sample program changes from `E_State.ReadOnce` to `E_State.ReadPeriodically`, in which the seventh variable is read periodically. The instance of `FB_IPCDiag_ReadParameterPeriodic` is called cyclically. The selected parameter is queried internally with the set period of 10 seconds. A valid value can be copied into the prepared variable as soon as the function block output `bValid` is set.

```
E_State.ReadPeriodically:  
    fbDiagReadPeriodic(bEnable:=TRUE, fbRegister:=fbDiagRegister);  
    IF fbDiagReadPeriodic.bValid THEN  
        fbDiagReadPeriodic.GetParameter(pBuffer:=ADR(nCpuTemperature), nBufferSize:=SIZEOF(nCpuTemperature) );      
    END_IF  
    IF fbDiagReadPeriodic.bError THEN  
        eState := E_State.Error;  
    END_IF
```

If you wish to supplement the sample by a further periodic parameter query, you can declare an additional instance of `FB_IPCDiag_ReadParameterPeriodic` and similarly call it in the state `E_State.Ready`.

Download: [TC3\_PlcSample\_IpcDiag](https://infosys.beckhoff.com/content/1033/tcplclib_tc3_ipcdiag/Resources/zip/8747975691.zip)

[TwinCAT 3 | PLC Library: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
