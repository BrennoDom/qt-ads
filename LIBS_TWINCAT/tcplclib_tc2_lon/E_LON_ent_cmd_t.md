# E_LON_ent_cmd_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_ent\_cmd\_t

Used by: SNVT\_ent\_state

```
TYPE E_LON_ent_cmd_t :  
(  
  eLON_ES_NUL            := -1,  
  eLON_ES_UNDEFINED      := 0,  
  eLON_ES_OPEN_PULS      := 1,  
  eLON_ES_OPEN           := 2,  
  eLON_ES_CLOSE          := 3,  
  eLON_ES_STOP           := 4,  
  eLON_ES_STOP_RESUME    := 5,  
  eLON_ES_ENTRY_REQ      := 6,  
  eLON_ES_EXIT_REQ       := 7,  
  eLON_ES_KEY_REQ        := 8,  
  eLON_ES_SAFETY_EXT_REQ := 9,  
  eLON_ES_EMERGENCY_REQ  := 10,  
  eLON_ES_UPDATE_STATE   := 11,  
  eLON_ES_SAF_EXT_RESUME := 12,  
  eLON_ES_EMERG_RESUME   := 13  
)  
END_TYPE
```

**eLON\_ES\_NUL:**  Invalid Value

**eLON\_ES\_UNDEFINED:**  State is not yet defined

**eLON\_ES\_OPEN\_PULS:**  Open the device and close it when back in normal position

**eLON\_ES\_OPEN:**  Open the device if not locked

**eLON\_ES\_CLOSE:**  Close the device

**eLON\_ES\_STOP:**  Stop the device

**eLON\_ES\_STOP\_RESUME:**  Continue after stop command

**eLON\_ES\_ENTRY\_REQ:**  Entry request, access in to the area

**eLON\_ES\_EXIT\_REQ:**  Exit request, access out from the area

**eLON\_ES\_KEY\_REQ:**  Exit request, access out from the area

**eLON\_ES\_SAFETY\_EXT\_REQ:**  Safety request, the device will go to a pre-defined safety position/mode

**eLON\_ES\_EMERGENCY\_REQ:**  Emergency request, the device will go to an pre-defined emergency position/mode

**eLON\_ES\_UPDATE\_STATE:**  Update the current state and mode

**eLON\_ES\_SAF\_EXT\_RESUME:**  Resume after Safety function

**eLON\_ES\_EMERG\_RESUME:**  Resume after Emergency function

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
