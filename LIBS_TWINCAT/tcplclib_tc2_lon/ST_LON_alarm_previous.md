# ST_LON_alarm_previous

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_alarm\_previous

Used by: SNVT\_lamp\_status

```
TYPE ST_LON_alarm_previous :  
STRUCT  
  bLamp_current_high    : BOOL;  
  bLamp_current_low     : BOOL;  
  bMain_current_high    : BOOL;  
  bMain_current_low     : BOOL;  
  bLamp_voltage_high    : BOOL;  
  bLamp_voltage_low     : BOOL;  
  bMain_voltage_high    : BOOL;  
  bMain_voltage_low     : BOOL;  
  bPowerfactor_low      : BOOL;  
  bOLC_temp_high        : BOOL;  
  bPower_high           : BOOL;  
  bPower_low            : BOOL;  
  bRelay_failure        : BOOL;  
  bCap_failure          : BOOL;  
  bLamp_failure         : BOOL;  
  bBallast_failure      : BOOL;  
  bInter_com_failure    : BOOL;  
  bExter_com_failure    : BOOL;  
  bMain_volt_below_spec : BOOL;  
  bLamp_restart_count   : BOOL;  
  bFading_ready         : BOOL;  
  bBallast_temp_high    : BOOL;  
  bDigi_in_A            : BOOL;  
  bDigi_in_B            : BOOL;  
  bBit_25_res           : BOOL;  
  bBit_26_res           : BOOL;  
  bBit_27_res           : BOOL;  
  bBit_28_res           : BOOL;  
  bBit_29_res           : BOOL;  
  bBit_30_res           : BOOL;  
  bBit_31_res           : BOOL;  
  bBit_32_res           : BOOL;  
  bBit_33_res           : BOOL;  
  bBit_34_res           : BOOL;  
  bBit_35_res           : BOOL;  
  bBit_36_res           : BOOL;  
  bBit_37_res           : BOOL;  
  bBit_38_res           : BOOL;  
  bBit_39_res           : BOOL;  
  bBit_40_res           : BOOL;  
END_STRUCT  
END_TYPE
```

**bLamp\_current\_high:** Lamp current too high.

**bLamp\_current\_low:** Lamp current too low.

**bMain\_current\_high:** Main current too high.

**bMain\_current\_low:** Main current too low.

**bLamp\_voltage\_high:** Lamp voltage too high.

**bLamp\_voltage\_low:** Lamp voltage too low.

**bMain\_voltage\_high:** Main voltage too high.

**bMain\_voltage\_low:** Main voltage too low.

**bPowerfactor\_low:** Powerfactor too low.

**bOLC\_temp\_high:** Temperature too high.

**bPower\_high:** Power too high.

**bPower\_low:** Power too low.

**bRelay\_failure:** Relay failure.

**bCap\_failure:** Capacitor failure.

**bLamp\_failure:** Lamp failure.

**bBallast\_failure:** Ballast failure.

**bInter\_com\_failure:** Internal communication failure.

**bExter\_com\_failure:** External communication failure.

**bMain\_volt\_below\_spec:** Main voltage below performance specification.

**bLamp\_restart\_count:** Lamp restart retry counter / cycling failure.

**bFading\_ready:** Fading ready.

**bBallast\_temp\_high:** Ballast temperature too high.

**bDigi\_in\_A:** digital input A active.

**bDigi\_in\_B:** digital input B active.

**bBit\_25\_res:**

**bBit\_26\_res:**

**bBit\_27\_res:**

**bBit\_28\_res:**

**bBit\_29\_res:**

**bBit\_30\_res:**

**bBit\_31\_res:**

**bBit\_32\_res:**

**bBit\_33\_res:**

**bBit\_34\_res:**

**bBit\_35\_res:**

**bBit\_36\_res:**

**bBit\_37\_res:**

**bBit\_38\_res:**

**bBit\_39\_res:**

**bBit\_40\_res:**

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
