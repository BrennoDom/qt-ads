# E_BA_Terminal_KL

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# E\_BA\_Terminal\_KL

Enumerator for selecting the respective Bus Terminal.

```
TYPE E_BA_TERMINAL_KL:  
(  
  KL3208_0010     := 0,  
  KL320x_0000     := 1,  
  KL300x          := 2,  
  KL301x          := 3,  
  KL302x          := 4,  
  KL304x          := 5,  
  KL305x          := 6,  
  KL306x          := 7,  
  KL3132_0000     := 8,  
  KL3142_0000     := 9,  
  KL3152_0000     := 10,  
  KL3162_0000     := 11,  
  KL3172_0000     := 12,  
  KL3172_0500     := 13,  
  KL3172_1000     := 14,  
  KL3182_0000     := 15,  
  KL3404          := 16,  
  KL3464          := 17,  
  KL3408          := 18,  
  KL3468          := 19,  
  KL3444          := 20,  
  KL3454          := 21,  
  KL3448          := 22,  
  KL3458          := 23,  
  Undefined       := 16#FFFF  
)DINT;  
END_TYPE
```

**KL3208\_0010:** Temperature sensors with wire breakage and short-circuit detection.

**KL320x\_0000:** Temperature sensors with wire breakage and short-circuit detection.

**KL300x:** -10 V to 10 V.

**KL301x:** 0 mA to 20 mA with wire breakage and short-circuit detection.

**KL302x:** 4 mA to 20 mA with wire breakage and short-circuit detection.

**KL304x:** 0 mA to 20 mA with wire breakage and short-circuit detection.

**KL305x:** 4 mA to 20 mA with wire breakage and short-circuit detection.

**KL306x:** 0 V to 10 V.

**KL3132\_0000:** -10 V to +10 V.

**KL3142\_0000:** 0 mA to 20 mA with wire breakage and short-circuit detection.

**KL3152\_0000:** 4 mA to 20 mA with wire breakage and short-circuit detection.

**KL3162\_0000:** 0 V to +10 V.

**KL3172\_0000:** 0 V to +2 V.

**KL3172\_0500:** 0 V to +0.5 V.

**KL3172\_1000:** 0 V to +1.0 V.

**KL3182\_0000:** -2.0 V to +2.0 V.

**KL3404:** -10 V to +10 V.

**KL3464:** 0 V to +10 V.

**KL3408:** -10 V to +10 V.

**KL3468:** 0 V to +10 V.

**KL3444:** 0 mA to 20 mA with wire breakage and short-circuit detection.

**KL3454:** 4 mA to 20 mA with wire breakage and short-circuit detection.

**KL3448:** 0 mA to 20 mA with wire breakage and short-circuit detection.

**KL3458:** 4 mA to 20 mA with wire breakage and short-circuit detection.

## Requirements

| Development environment | Required library | Necessary function |
| --- | --- | --- |
| TwinCAT3.1 4022.16 | Tc3Building Automation Common from V1.0.4.3 | TF8040 | TwinCAT Building Automation from V1.0.5.0 |
