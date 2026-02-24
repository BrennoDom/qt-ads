# E_LON_reg_val_unit_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_reg\_val\_unit\_t

Used by: SNVT\_reg\_val / SNVT\_reg\_val\_ts

```
TYPE E_LON_reg_val_unit_t :  
(  
  eLON_RVU_NUL   := -1,  
  eLON_RVU_NONE  := 0,  
  eLON_RVU_W     := 1,  
  eLON_RVU_KW    := 2,  
  eLON_RVU_MW    := 3,  
  eLON_RVU_GW    := 4,  
  eLON_RVU_VAR   := 5,  
  eLON_RVU_KVAR  := 6,  
  eLON_RVU_MVAR  := 7,  
  eLON_RVU_GVAR  := 8,  
  eLON_RVU_WH    := 9,  
  eLON_RVU_KWH   := 10,  
  eLON_RVU_MWH   := 11,  
  eLON_RVU_GWH   := 12,  
  eLON_RVU_VARH  := 13,  
  eLON_RVU_KVARH := 14,  
  eLON_RVU_MVARH := 15,  
  eLON_RVU_GVARH := 16,  
  eLON_RVU_V     := 17,  
  eLON_RVU_A     := 18,  
  eLON_RVU_COSF  := 19,  
  eLON_RVU_M3    := 20,  
  eLON_RVU_L     := 21,  
  eLON_RVU_ML    := 22,  
  eLON_RVU_USGAL := 23,  
  eLON_RVU_GJ    := 24,  
  eLON_RVU_MJ    := 25,  
  eLON_RVU_MCAL  := 26,  
  eLON_RVU_KCAL  := 27,  
  eLON_RVU_MBTU  := 28,  
  eLON_RVU_KBTU  := 29,  
  eLON_RVU_MJH   := 30,  
  eLON_RVU_MLS   := 31,  
  eLON_RVU_LS    := 32,  
  eLON_RVU_M3S   := 33,  
  eLON_RVU_C     := 34,  
  eLON_RVU_LH    := 35,  
  eLON_RVU_VA    := 36,  
  eLON_RVU_KVA   := 37,  
  eLON_RVU_MVA   := 38,  
  eLON_RVU_GVA   := 39,  
  eLON_RVU_VAH   := 40,  
  eLON_RVU_KVAH  := 41,  
  eLON_RVU_MVAH  := 42,  
  eLON_RVU_GVAH  := 43  
)  
END_TYPE
```

**eLON\_RVU\_NUL:**  invalid unit of measure (INVALID)

**eLON\_RVU\_NONE:**  no units specified ( )

**eLON\_RVU\_W:**  Watts (W)

**eLON\_RVU\_KW:**  kiloWatts (kW)

**eLON\_RVU\_MW:**  megaWatts (MW)

**eLON\_RVU\_GW:**  gigaWatts (GW)

**eLON\_RVU\_VAR:**  Volt-Amperes reactive (var)

**eLON\_RVU\_KVAR:**  kilo-Volt-Amperes reactive (kvar)

**eLON\_RVU\_MVAR:**  mega-Volt-Amperes reactive (Mvar)

**eLON\_RVU\_GVAR:**  giga-Volt-Amperes reactive (Gvar)

**eLON\_RVU\_WH:**  Watt-hour (Wh)

**eLON\_RVU\_KWH:**  kiloWatt-hour (kWh)

**eLON\_RVU\_MWH:**  megaWatt-hour (MWh)

**eLON\_RVU\_GWH:**  gigaWatt-hour (GWh)

**eLON\_RVU\_VARH:**  Volt-Amperes reactive -hour (varh)

**eLON\_RVU\_KVARH:**  kilo-Volt-Amperes reactive -hour (kvarh)

**eLON\_RVU\_MVARH:**  mega-Volt-Amperes reactive -hour (Mvarh)

**eLON\_RVU\_GVARH:**  giga-Volt-Amperes reactive -hour (Gvarh)

**eLON\_RVU\_V:**  Volts (V)

**eLON\_RVU\_A:**  Amps (A)

**eLON\_RVU\_COSF:**  (cosf)

**eLON\_RVU\_M3:**  cubic meters (m³)(cu.m)

**eLON\_RVU\_L:**  liters (l)

**eLON\_RVU\_ML:**  milliliters (ml)

**eLON\_RVU\_USGAL:**  U.S. Gallons (USG)

**eLON\_RVU\_GJ:**  giga-Joules (GJ)

**eLON\_RVU\_MJ:**  mega-Joules (MJ)

**eLON\_RVU\_MCAL:**  megacalories (Mcal)

**eLON\_RVU\_KCAL:**  kilocalories (kcal) / Calories (Cal)

**eLON\_RVU\_MBTU:**  mega-British thermal units (mBtu)

**eLON\_RVU\_KBTU:**  kilo-British thermal units (kBtu)

**eLON\_RVU\_MJH:**  mega-Joules per hour (MJ/h)

**eLON\_RVU\_MLS:**  milliliters per second (ml/s)

**eLON\_RVU\_LS:**  liters per second (l/s)

**eLON\_RVU\_M3S:**  cubic-meters per second (m³/s) (cu.m/s)

**eLON\_RVU\_C:**  (C)

**eLON\_RVU\_LH:**  liters per hour (l/h)

**eLON\_RVU\_VA:**  Volt-Amperes (VA)

**eLON\_RVU\_KVA:**  kiloVolt-Amperes (kVA)

**eLON\_RVU\_MVA:**  megaVolt-Amperes (MVA)

**eLON\_RVU\_GVA:**  gigaVolt-Amperes (GVA)

**eLON\_RVU\_VAH:**  Volt-Ampere hours (VAh)

**eLON\_RVU\_KVAH:**  kiloVolt-Ampere hours (kVAh)

**eLON\_RVU\_MVAH:**  megaVolt-Ampere hours (MVAh)

**eLON\_RVU\_GVAH:**  giga-Volt-Ampere hours (GVAh)

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
