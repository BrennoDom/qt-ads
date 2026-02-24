# E_LON_fire_initiator_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_fire\_initiator\_t

Used by: SNVT\_fire\_init

```
TYPE E_LON_fire_initiator_t :  
(  
  eLON_FI_NUL                     := -1,  
  eLON_FI_UNDEFINED               := 0,  
  eLON_FI_THERMAL_FIXED           := 1,  
  eLON_FI_SMOKE_ION               := 2,  
  eLON_FI_MULTI_ION_THERMAL       := 3,  
  eLON_FI_SMOKE_PHOTO             := 4,  
  eLON_FI_MULTI_PHOTO_THERMAL     := 5,  
  eLON_FI_MULTI_PHOTO_ION         := 6,  
  eLON_FI_MULTI_PHOTO_ION_THERMAL := 7,  
  eLON_FI_THERMAL_ROR             := 8,  
  eLON_FI_MULTI_THERMAL_ROR       := 9,  
  eLON_FI_MANUAL_PULL             := 10,  
  eLON_FI_WATER_FLOW              := 11,  
  eLON_FI_WATER_FLOW_TAMPER       := 12,  
  eLON_FI_STATUS_ONLY             := 13,  
  eLON_FI_MANUAL_CALL             := 14,  
  eLON_FI_FIREMAN_CALL            := 15,  
  eLON_FI_UNIVERSAL               := 16  
)  
END_TYPE
```

**eLON\_FI\_NUL:**  Invalid Value

**eLON\_FI\_UNDEFINED:**  Initiator is undefined

**eLON\_FI\_THERMAL\_FIXED:**  Initiator is thermal fixed (heat)

**eLON\_FI\_SMOKE\_ION:**  Initiator is smoke and ion

**eLON\_FI\_MULTI\_ION\_THERMAL:**  Initiator is multi-ion and thermal

**eLON\_FI\_SMOKE\_PHOTO:**  Initiator is smoke and photo

**eLON\_FI\_MULTI\_PHOTO\_THERMAL:**  Initiator is multi-photo and thermal

**eLON\_FI\_MULTI\_PHOTO\_ION:**  Initiator is multi-photo and ion

**eLON\_FI\_MULTI\_PHOTO\_ION\_THERMAL:**  Initiator is multi-photo, ion and thermal

**eLON\_FI\_THERMAL\_ROR:**  Initiator is thermal fixed and Rate of Rise

**eLON\_FI\_MULTI\_THERMAL\_ROR:**  Initiator is multi-thermal and Rate of Rise

**eLON\_FI\_MANUAL\_PULL:**  Initiator is manual pull

**eLON\_FI\_WATER\_FLOW:**  Initiator is water flow

**eLON\_FI\_WATER\_FLOW\_TAMPER:**  Initiator is water flow and tamper

**eLON\_FI\_STATUS\_ONLY:**  Initiator is status only

**eLON\_FI\_MANUAL\_CALL:**  Initiator is a manual call point

**eLON\_FI\_FIREMAN\_CALL:**  Initiator is a fireman call point

**eLON\_FI\_UNIVERSAL:**  General purpose initiator definition

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
