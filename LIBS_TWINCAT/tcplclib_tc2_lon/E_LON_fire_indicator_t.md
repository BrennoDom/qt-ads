# E_LON_fire_indicator_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_fire\_indicator\_t

Used by: SNVT\_fire\_indcte

```
TYPE E_LON_fire_indicator_t :  
(  
  eLON_FN_NUL       := -1,  
  eLON_FN_UNDEFINED := 0,  
  eLON_FN_STROBE_U  := 1,  
  eLON_FN_STROBE_S  := 2,  
  eLON_FN_HORN      := 3,  
  eLON_FN_CHIME     := 4,  
  eLON_FN_BELL      := 5,  
  eLON_FN_SOUNDER   := 6,  
  eLON_FN_SPEAKER   := 7,  
  eLON_FN_UNIVERSAL := 8  
)  
END_TYPE
```

**eLON\_FN\_NUL:**  Invalid Value

**eLON\_FN\_UNDEFINED:**  Undefined indicator

**eLON\_FN\_STROBE\_U:**  The indicator is un-synchronized

**eLON\_FN\_STROBE\_S:**  The indicator is synchronized

**eLON\_FN\_HORN:**  The indicator is a DC input, pre coded Horn

**eLON\_FN\_CHIME:**  The indicator is a DC input, pre coded Chime

**eLON\_FN\_BELL:**  The indicator is a DC input

**eLON\_FN\_SOUNDER:**  The indicator is powered from the device

**eLON\_FN\_SPEAKER:**  The indicator is an AC input for the speaker

**eLON\_FN\_UNIVERSAL:**  General purpose indicator

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
