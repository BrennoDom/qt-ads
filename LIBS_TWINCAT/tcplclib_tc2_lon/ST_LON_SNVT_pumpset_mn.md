# ST_LON_SNVT_pumpset_mn

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_pumpset\_mn

Used by: SNVT\_pumpset\_mn

```
TYPE ST_LON_SNVT_pumpset_mn :  
STRUCT  
  eMain_pump                  : E_LON_motor_state_t;  
  eBooster_pump               : E_LON_motor_state_t;  
  ePriority_level             : E_LON_Priority_level_t;  
  eProcess_ready              : E_LON_boolean_t;  
  eEmergency_stop_activated   : E_LON_boolean_t;  
  eMain_pump_drive_enabled    : E_LON_boolean_t;  
  eBooster_pump_drive_enabled : E_LON_boolean_t;  
  eMaintenance_required       : E_LON_boolean_t;  
END_STRUCT  
END_TYPE
```

**eMain\_pump:** Main pump state (motor state names) (see [E\_LON\_motor\_state\_t](ms-xhelp:///?Id=beckhoff-5508-45ad-bd90-bc563f99c5dc)).

**eBooster\_pump:** Booster pump state (motor state names) (see [E\_LON\_motor\_state\_t](ms-xhelp:///?Id=beckhoff-5508-45ad-bd90-bc563f99c5dc)).

**ePriority\_level:** Priority level (priority level names) (see [E\_LON\_Priority\_level\_t](ms-xhelp:///?Id=beckhoff-547f-4059-a509-dba364144176)).

**eProcess\_ready:** Process ready (boolean) (see [E\_LON\_boolean\_t](ms-xhelp:///?Id=beckhoff-d20f-4a1d-946e-6e930b436d90)).

**eEmergency\_stop\_activated:** Emergency stop (boolean) (see [E\_LON\_boolean\_t](ms-xhelp:///?Id=beckhoff-d20f-4a1d-946e-6e930b436d90)).

**eMain\_pump\_drive\_enabled:** Main pump enabled (boolean) (see [E\_LON\_boolean\_t](ms-xhelp:///?Id=beckhoff-d20f-4a1d-946e-6e930b436d90)).

**eBooster\_pump\_drive\_enabled:** Booster pump enabled (boolean) (see [E\_LON\_boolean\_t](ms-xhelp:///?Id=beckhoff-d20f-4a1d-946e-6e930b436d90)).

**eMaintenance\_required:** Maintenance required (boolean) (see [E\_LON\_boolean\_t](ms-xhelp:///?Id=beckhoff-d20f-4a1d-946e-6e930b436d90)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
