# E_HomingErrorCodes

## Library
tcplclib_tc3_mc2_advancedhoming

## Category
Motion Control

# E\_HomingErrorCodes

```
TYPE MC_Switch_Mode :  
(  
    MC_HOMINGERROR_DRIVETYPE               := 16#4B90,  
    MC_HOMINGERROR_DIRECTION               := 16#4B91,  
    MC_HOMINGERROR_SWITCHMODE              := 16#4B92,  
    MC_HOMINGERROR_MODE                    := 16#4B93,  
    MC_HOMINGERROR_TORQUEPARAMETER         := 16#4B94,  
    MC_HOMINGERROR_LAGPARAMETER            := 16#4B95,  
    MC_HOMINGERROR_DISTANCELIMIT           := 16#4B96,  
    MC_HOMINGERROR_PARAMETER_ALREADYSTORED := 16#4B97,  
    MC_HOMINGERROR_PARAMETER_NOTSTORED     := 16#4B98  
) UDINT;  
END_TYPE
```

| Name | Description |
| --- | --- |
| MC\_HOMINGERROR\_DRIVETYPE | The following drives are supported:   * AX5xxx-xxxx-02xx (FW>=2.05) * EL7201-0000 /-0001 / -0010 / 0011 * AX8xxx-xxxx-xxxx (FW>=???) |
| MC\_HOMINGERROR\_DIRECTION | Parameterized direction is not permissible for this function block. |
| MC\_HOMINGERROR\_SWITCHMODE | Parameterized mode is not permissible for this function block. |
| MC\_HOMINGERROR\_MODE |  |
| MC\_HOMINGERROR\_TORQUEPARAMETER | Parameterized torque presets are not permissible. |
| MC\_HOMINGERROR\_LAGPARAMETER | Parameterized lag error is not permissible (<0). |
| MC\_HOMINGERROR\_DISTANCELIMIT | Parameterized maximum distance is not permissible (<0). |
| MC\_HOMINGERROR\_PARAMETER\_ALREADYSTORED | The MC\_StepHomingParameter function block has been called again with the HOMINGPARAMETERCTRLMODE\_READ mode, although parameters have already been backed up. |
| MC\_HOMINGERROR\_PARAMETER\_NOTSTORED | The MC\_StepHomingParameter function block has been called again with the HOMINGPARAMETERCTRLMODE\_RESTORE mode, although no parameters have been backed up. |
