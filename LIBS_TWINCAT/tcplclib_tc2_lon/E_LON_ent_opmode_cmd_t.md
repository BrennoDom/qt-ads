# E_LON_ent_opmode_cmd_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_ent\_opmode\_cmd\_t

Used by: SNVT\_ent\_opmode / SNVT\_ent\_status

```
TYPE E_LON_ent_opmode_cmd_t :  
(  
  eLON_EM_NUL           := -1,  
  eLON_EM_UNDEFINED     := 0,  
  eLON_EM_AUTO          := 1,  
  eLON_EM_AUTO_RED      := 2,  
  eLON_EM_CLOSE_LOCK    := 3,  
  eLON_EM_CLOSE_UNLOCK  := 4,  
  eLON_EM_EXIT_ONLY     := 5,  
  eLON_EM_OPEN          := 6,  
  eLON_EM_OPEN_ONCE     := 7,  
  eLON_EM_MANUAL        := 8,  
  eLON_EM_FIRE          := 9,  
  eLON_EM_EVAC          := 10,  
  eLON_EM_WEATHER       := 11,  
  eLON_EM_DAY_LOCKING   := 12,  
  eLON_EM_NIGHT_LOCKING := 13,  
  eLON_EM_BLOCKED       := 14,  
  eLON_EM_SERVICE       := 15,  
  eLON_EM_ENTRY_ONLY    := 16  
)  
END_TYPE
```

**eLON\_EM\_NUL:**  Invalid Value

**eLON\_EM\_UNDEFINED:**  Operation mode is not defined

**eLON\_EM\_AUTO:**  Operation mode is AUTOMATIC

**eLON\_EM\_AUTO\_RED:**  Operation mode is AUTOMATIC with reduced width

**eLON\_EM\_CLOSE\_LOCK:**  Operation mode is CLOSE AND LOCK

**eLON\_EM\_CLOSE\_UNLOCK:**  Operation mode is CLOSE AND UNLOCK

**eLON\_EM\_EXIT\_ONLY:**  Operation mode is EXIT ONLY

**eLON\_EM\_OPEN:**  Operation mode is OPEN

**eLON\_EM\_OPEN\_ONCE:**  Operation mode is OPEN AND CLOSE ONCE

**eLON\_EM\_MANUAL:**  Operation mode is MANUAL

**eLON\_EM\_FIRE:**  Operation mode is FIRE

**eLON\_EM\_EVAC:**  Operation mode is EVACUATION

**eLON\_EM\_WEATHER:**  Operation mode is WEATHER MODE

**eLON\_EM\_DAY\_LOCKING:**  Operation mode is DAY\_LOCKING, locking with reduced level of security

**eLON\_EM\_NIGHT\_LOCKING:**  Operation mode is NIGHT\_LOCKING, locking with maximum level of security

**eLON\_EM\_BLOCKED:**  Operation mode is BLOCKED, no operations is allowed

**eLON\_EM\_SERVICE:**  Operation mode is SERVICE

**eLON\_EM\_ENTRY\_ONLY:**  Operation mode is ENTRY\_ONLY

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
