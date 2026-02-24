# FB_CXSimpleUps

## Library
tcplclib_tc2_systemcx

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
2. [Function Blocks](ms-xhelp:///?Id=beckhoff-ec9d-42ff-9fdd-c53aca476e55)
3. FB\_CXSimpleUps

# FB\_CXSimpleUps

![13722030](/tcplclib_tc2_systemcx/1033/Images/png/9007199440657163__Web.png)

The function block FB\_CXSimpleUps can be used on the CX1000 or CX1020 in order to activate the UPS CX1190-UPS from the PLC. In this case the UPS settings must be deactivated in the TwinCAT System Manager.

![56389407](/tcplclib_tc2_systemcx/1033/Images/png/9007199440660363__Web.png)

## VAR\_INPUT

```
                  
VAR_INPUT  
    bDIPDisable : BOOL;  
    iDischargeLevel : USINT;  
    tDelay     : TIME;  
END_VAR
```

**bDIPDisable**  : if TRUE, then the orientation of the '1-2-3..8-9-0' switch on the UPS is ignored, in this case the iDischargeLevel is used instead.

**iDischargeLevel**  : Discharge Switch Off Level: 0 = 100% (Maximum Discharge), 9 = 90%, 8 = 80%, ..., 2 = 20%, 1 = 10% (Minimum Discharge).

**tDelay** : Holding time, time before the Shutdown is executed. This time is used to overcome short power outages (up to 10s) without shutdown.  
 Once the holding time is elapsed, the FB finishes the holding period and waits internally for additional 2.5s.  
 If the power has returned by then, the FB continues with normal run mode, otherwise the powerfail shutdown is executed.  
 If the power returns during or after the shutdown, then the CX reboots after discharging and recharging the UPS.

## VAR\_OUTPUT

```
                                                      
VAR_OUTPUT  
    bPowerFailure : BOOL;  
    bShutdownActive : BOOL;  
    bUpsReady     : BOOL;  
    b24VInOK        : BOOL;  
    bHolding        : BOOL;  
    tTimeUntilShutdown : TIME;  
    eUpsState     : E_UPS_STATE;  
END_VAR
```

**bPowerFailure** : gets TRUE, if a power failure of the power supply is detected, gets FALSE, if the power supply is restored.

**bShutdownActive** : gets TRUE, if a Stop or Shutdown is being executed.

**bUpsReady** : gets TRUE, if the UPS supplies the voltage.

**b24VInOK** : gets TRUE, if the power supply supplies the UPS with 24V.

**bHolding** : gets TRUE, if a power failure of the power supply is detected, and the holding time has not yet elapsed.

**tTimeUntilShotdown** : Shows the time until the system shuts down after a power fault.

**eUpsState** : Shows the status of the UPS [UNDEF | CHARGING | CHARGED | DISCHARGE | DISCHARGE\_RESTART | OUTPUT\_OFF | OVERLOAD].

## VAR\_CONFIG

```
                              
VAR_CONFIG  
    Ii24VState AT %I*     : BYTE;  
    IiChargeState AT %I* : USINT;  
    QiControl AT %Q*        : BYTE;  
    QiDIPControl AT %Q* : USINT;  
END_VAR
```

**Ii24VState**  : needs to be linked to input '24V State', see picture above.

**IiChargeState**  : needs to be linked to input 'Charge State', see picture above.

**QiControl**  : needs to be linked to output 'Control', see picture above.

**QiDIPControl**  : needs to be linked to output 'DIP Ctrl', see picture above.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | CX (x86) | Tc2\_SystemCX |

|  |  |
| --- | --- |
| 37742617 | For other CX and PC please refer to the function block FB\_S\_SUPS\_BAPI in the [Tc2\_SUPS](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_sups/27021601480747275.html) library. |

[TwinCAT 3 | PLC Library: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
