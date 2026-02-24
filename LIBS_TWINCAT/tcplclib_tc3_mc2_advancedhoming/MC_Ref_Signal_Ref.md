# MC_Ref_Signal_Ref

## Library
tcplclib_tc3_mc2_advancedhoming

## Category
Motion Control

# MC\_Ref\_Signal\_Ref

```
TYPE MC_Ref_Signal_Ref :  
STRUCT  
    SignalSource : E_SignalSource := SignalSource_Default;  
    TouchProbe   : E_TouchProbe   := PlcEvent;  
    Level        : BOOL;  
END_STRUCT  
END_TYPE
```

| Name | Type | Description |
| --- | --- | --- |
| SignalSource | E\_SignalSource | Optionally defines the signal source, if it can be selected via the controller. In many cases the signal source is permanently configured in the drive and should then be set to the default value *SignalSource\_Default*.  (Cf. E\_SignalSource **Tc2\_MC2** library documentation) |
| TouchProbe | E\_TouchProbe | Defines the latch unit (probe unit) within the encoder hardware used.  (Cf. E\_TouchProbe**Tc2\_MC2** library documentation) |
| Level | BOOL | The current signal state of the sensor must be transferred here. |
