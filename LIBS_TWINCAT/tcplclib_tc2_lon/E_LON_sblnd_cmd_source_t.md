# E_LON_sblnd_cmd_source_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_sblnd\_cmd\_source\_t

Used by: SNVT\_sblnd\_state

```
TYPE E_LON_sblnd_cmd_source_t :  
(  
  eLON_SBCS_NUL              := -1,  
  eLON_SBCS_LOCAL            := 0,  
  eLON_SBCS_GROUP            := 1,  
  eLON_SBCS_WIND_SPEED       := 2,  
  eLON_SBCS_SUN_LUX          := 3,  
  eLON_SBCS_RAIN             := 4,  
  eLON_SBCS_FROST            := 5,  
  eLON_SBCS_DAWN             := 6,  
  eLON_SBCS_DUSK             := 7,  
  eLON_SBCS_OUTSIDE_TEMP     := 8,  
  eLON_SBCS_INDOOR_TEMP      := 9,  
  eLON_SBCS_OUTDOOR_RH       := 10,  
  eLON_SBCS_INDOOR_RH        := 11,  
  eLON_SBCS_ILLUM_LEVEL      := 12,  
  eLON_SBCS_SCENE            := 13,  
  eLON_SBCS_GLOBAL           := 14,  
  eLON_SBCS_WINDOW_CONTACT   := 15,  
  eLON_SBCS_AUTOMODE_CHANGED := 16,  
  eLON_SBCS_OVERRIDE         := 17,  
  eLON_SBCS_EMERGENCY        := 18,  
  eLON_SBCS_MAINTENANCE      := 19,  
  eLON_SBCS_INTRUSION        := 20,  
  eLON_SBCS_TERMINAL_LOAD    := 21,  
  eLON_SBCS_ALARM            := 22,  
  eLON_SBCS_OCC_SENSOR       := 23,  
  eLON_SBCS_OCC_MAN_CMD      := 24,  
  eLON_SBCS_GLARE            := 25,  
  eLON_SBCS_ALARM_2          := 26,  
  eLON_SBCS_NOTIFY           := 27,  
  eLON_SBCS_ELEVATION        := 28,  
  eLON_SBCS_AZIMUTH          := 29,  
  eLON_SBCS_SET_OVERRIDE     := 30,  
  eLON_SBCS_SET_MAINTENANCE  := 31,  
  eLON_SBCS_TIMER            := 32,  
  eLON_SBCS_UNKNOWN          := 127  
)  
END_TYPE
```

**eLON\_SBCS\_NUL:**  Invalid value

**eLON\_SBCS\_LOCAL:**  Local

**eLON\_SBCS\_GROUP:**  Group

**eLON\_SBCS\_WIND\_SPEED:**  Wind speed

**eLON\_SBCS\_SUN\_LUX:**  Sun lux level

**eLON\_SBCS\_RAIN:**  Rain

**eLON\_SBCS\_FROST:**  Frost

**eLON\_SBCS\_DAWN:**  Dawn

**eLON\_SBCS\_DUSK:**  Dusk

**eLON\_SBCS\_OUTSIDE\_TEMP:**  Outside temperature

**eLON\_SBCS\_INDOOR\_TEMP:**  Indoor temperature

**eLON\_SBCS\_OUTDOOR\_RH:**  Outdoor relative humidity

**eLON\_SBCS\_INDOOR\_RH:**  Indoor relative humidity

**eLON\_SBCS\_ILLUM\_LEVEL:**  Illumination level

**eLON\_SBCS\_SCENE:**  Scene

**eLON\_SBCS\_GLOBAL:**  Global

**eLON\_SBCS\_WINDOW\_CONTACT:**  Window contact

**eLON\_SBCS\_AUTOMODE\_CHANGED:**  Auto-mode changed

**eLON\_SBCS\_OVERRIDE:**  Override

**eLON\_SBCS\_EMERGENCY:**  Emergency

**eLON\_SBCS\_MAINTENANCE:**  Maintenance

**eLON\_SBCS\_INTRUSION:**  Intrusion

**eLON\_SBCS\_TERMINAL\_LOAD:**  Terminal load

**eLON\_SBCS\_ALARM:**  Alarm

**eLON\_SBCS\_OCC\_SENSOR:**  Occupancy sensor

**eLON\_SBCS\_OCC\_MAN\_CMD:**  Occupancy manual command

**eLON\_SBCS\_GLARE:**  Glare

**eLON\_SBCS\_ALARM\_2:**  Alarm 2

**eLON\_SBCS\_NOTIFY:**  Notify

**eLON\_SBCS\_ELEVATION:**  Elevation

**eLON\_SBCS\_AZIMUTH:**  Azimuth

**eLON\_SBCS\_SET\_OVERRIDE:**  Set override

**eLON\_SBCS\_SET\_MAINTENANCE:**  Set maintenance

**eLON\_SBCS\_TIMER:**  Timer

**eLON\_SBCS\_UNKNOWN:**  Unknown command source

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
