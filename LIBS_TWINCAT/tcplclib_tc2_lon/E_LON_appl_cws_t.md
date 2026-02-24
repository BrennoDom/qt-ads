# E_LON_appl_cws_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_appl\_cws\_t

Used by: SNVT\_clothes\_w\_c / SNVT\_clothes\_w\_s

```
TYPE E_LON_appl_cws_t :  
(  
  eLON_CWS_NUL            := -1,  
  eLON_CWS_LOAD_SENSING   := 0,  
  eLON_CWS_WETTING        := 1,  
  eLON_CWS_DETERGENT      := 2,  
  eLON_CWS_WASHING        := 3,  
  eLON_CWS_WATERING       := 4,  
  eLON_CWS_RINSING        := 5,  
  eLON_CWS_ARRANGING      := 6,  
  eLON_CWS_DRAIN          := 7,  
  eLON_CWS_SPINNING       := 8,  
  eLON_CWS_FINAL_SPINNING := 9,  
  eLON_CWS_FLUFFING       := 10,  
  eLON_CWS_DRYING         := 11,  
  eLON_CWS_COOLING        := 12  
)  
END_TYPE
```

**eLON\_CWS\_NUL:**  Invalid Value

**eLON\_CWS\_LOAD\_SENSING:**  Sensing Load

**eLON\_CWS\_WETTING:**  Wetting

**eLON\_CWS\_DETERGENT:**  Detergent

**eLON\_CWS\_WASHING:**  Washing

**eLON\_CWS\_WATERING:**  Watering

**eLON\_CWS\_RINSING:**  Rinsing

**eLON\_CWS\_ARRANGING:**  Arranging

**eLON\_CWS\_DRAIN:**  Drain

**eLON\_CWS\_SPINNING:**  Spinning

**eLON\_CWS\_FINAL\_SPINNING:**  In Final Spin

**eLON\_CWS\_FLUFFING:**  Fluffing

**eLON\_CWS\_DRYING:**  Drying

**eLON\_CWS\_COOLING:**  Cooling

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
