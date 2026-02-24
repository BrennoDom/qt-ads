# E_LON_Parameter_Datatypes

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_Parameter\_Datatypes

Enums SNVT types

```
TYPE E_LON_Parameter_Datatypes :  
(  
  eEmpty               := 0,  
  eSNVT_amp            := 1,  
  eSNVT_amp_mil        := 2,  
  eSNVT_angle          := 3,  
  eSNVT_angle_vel      := 4,  
  eSNVT_btu_kilo       := 5,  
  eSNVT_btu_mega       := 6,  
  eSNVT_char_ascii     := 7,  
  eSNVT_count          := 8,  
  eSNVT_count_inc      := 9,  
  eSNVT_date_cal       := 10,  
  eSNVT_date_day       := 11,  
  eSNVT_date_time      := 12,  
  eSNVT_elec_kwh       := 13,  
  eSNVT_elec_whr       := 14,  
  eSNVT_flow           := 15,  
  eSNVT_flow_mil       := 16,  
  eSNVT_length         := 17,  
  eSNVT_length_kilo    := 18,  
  eSNVT_length_micr    := 19,  
  eSNVT_length_mil     := 20,  
  eSNVT_lev_cont       := 21,  
  eSNVT_lev_disc       := 22,  
  eSNVT_mass           := 23,  
  eSNVT_mass_kilo      := 24,  
  eSNVT_mass_mega      := 25,  
  eSNVT_mass_mil       := 26,  
  eSNVT_power          := 27,  
  eSNVT_power_kilo     := 28,  
  eSNVT_ppm            := 29,  
  eSNVT_press          := 30,  
  eSNVT_res            := 31,  
  eSNVT_res_kilo       := 32,  
  eSNVT_sound_db       := 33,  
  eSNVT_speed          := 34,  
  eSNVT_speed_mil      := 35,  
  eSNVT_str_asc        := 36,  
  eSNVT_str_int        := 37,  
  eSNVT_telcom         := 38,  
  eSNVT_temp           := 39,  
  eSNVT_time_passed    := 40,  
  eSNVT_vol            := 41,  
  eSNVT_vol_kilo       := 42,  
  eSNVT_vol_mil        := 43,  
  eSNVT_volt           := 44,  
  eSNVT_volt_dbmv      := 45,  
  eSNVT_volt_kilo      := 46,  
  eSNVT_volt_mil       := 47,  
  eSNVT_amp_f          := 48,  
  eSNVT_angle_f        := 49,  
  eSNVT_angle_vel_f    := 50,  
  eSNVT_count_f        := 51,  
  eSNVT_count_inc_f    := 52,  
  eSNVT_flow_f         := 53,  
  eSNVT_length_f       := 54,  
  eSNVT_lev_cont_f     := 55,  
  eSNVT_mass_f         := 56,  
  eSNVT_power_f        := 57,  
   eSNVT_ppm_f         := 58,  
  eSNVT_press_f        := 59,  
  eSNVT_res_f          := 60,  
  eSNVT_sound_db_f     := 61,  
  eSNVT_speed_f        := 62,  
  eSNVT_temp_f         := 63,  
  eSNVT_time_f         := 64,  
  eSNVT_vol_f          := 65,  
  eSNVT_volt_f         := 66,  
  eSNVT_btu_f          := 67,  
  eSNVT_elec_whr_f     := 68,  
  eSNVT_config_src     := 69,  
  eSNVT_color          := 70,  
  eSNVT_grammage       := 71,  
  eSNVT_grammage_f     := 72,  
  eSNVT_file_req       := 73,  
  eSNVT_file_status    := 74,  
  eSNVT_freq_f         := 75,  
  eSNVT_freq_hz        := 76,  
  eSNVT_freq_kilohz    := 77,  
  eSNVT_freq_milhz     := 78,  
  eSNVT_lux            := 79,  
  eSNVT_ISO_7811       := 80,  
  eSNVT_lev_percent    := 81,  
  eSNVT_multiplier     := 82,  
  eSNVT_state          := 83,  
  eSNVT_time_stamp     := 84,  
  eSNVT_zerospan       := 85,  
  eSNVT_magcard        := 86,  
  eSNVT_elapsed_tm     := 87,  
  eSNVT_alarm          := 88,  
  eSNVT_currency       := 89,  
  eSNVT_file_pos       := 90,  
  eSNVT_muldiv         := 91,  
  eSNVT_obj_request    := 92,  
  eSNVT_obj_status     := 93,  
  eSNVT_preset         := 94,  
  eSNVT_switch         := 95,  
  eSNVT_trans_table    := 96,  
  eSNVT_override       := 97,  
  eSNVT_pwr_fact       := 98,  
  eSNVT_pwr_fact_f     := 99,  
  eSNVT_density        := 100,  
  eSNVT_density_f      := 101,  
  eSNVT_rpm            := 102,  
  eSNVT_hvac_emerg     := 103,  
  eSNVT_angle_deg      := 104,  
  eSNVT_temp_p         := 105,  
  eSNVT_temp_setpt     := 106,  
  eSNVT_time_sec       := 107,  
  eSNVT_hvac_mode      := 108,  
  eSNVT_occupancy      := 109,  
  eSNVT_area           := 110,  
  eSNVT_hvac_overid    := 111,  
  eSNVT_hvac_status    := 112,  
  eSNVT_press_p        := 113,  
  eSNVT_address        := 114,  
  eSNVT_scene          := 115,  
  eSNVT_scene_cfg      := 116,  
  eSNVT_setting        := 117,  
  eSNVT_evap_state     := 118,  
  eSNVT_therm_mode     := 119,  
  eSNVT_defr_mode      := 120,  
  eSNVT_defr_term      := 121,  
  eSNVT_defr_state     := 122,  
  eSNVT_time_min       := 123,  
  eSNVT_time_hour      := 124,  
  eSNVT_ph             := 125,  
  eSNVT_ph_f           := 126,  
  eSNVT_chlr_status    := 127,  
  eSNVT_tod_event      := 128,  
  eSNVT_smo_obscur     := 129,  
  eSNVT_fire_test      := 130,  
  eSNVT_temp_ror       := 131,  
  eSNVT_fire_init      := 132,  
  eSNVT_fire_indcte    := 133,  
  eSNVT_time_zone      := 134,  
  eSNVT_earth_pos      := 135,  
  eSNVT_reg_val        := 136,  
  eSNVT_reg_val_ts     := 137,  
  eSNVT_volt_ac        := 138,  
  eSNVT_amp_ac         := 139,  
  
  eSNVT_turbidity      := 143,  
  eSNVT_turbidity_f    := 144,  
  eSNVT_hvac_type      := 145,  
  eSNVT_elec_kwh_l     := 146,  
  eSNVT_temp_diff_p    := 147,  
  eSNVT_ctrl_req       := 148,  
  eSNVT_ctrl_resp      := 149,  
  eSNVT_ptz            := 150,  
  eSNVT_privacyzone    := 151,  
  eSNVT_pos_ctrl       := 152,  
  eSNVT_enthalpy       := 153,  
  eSNVT_gfci_status    := 154,  
  eSNVT_motor_state    := 155,  
  eSNVT_pumpset_mn     := 156,  
  eSNVT_ex_control     := 157,  
  eSNVT_pumpset_sn     := 158,  
  eSNVT_pump_sensor    := 159,  
  eSNVT_abs_humid      := 160,  
  eSNVT_flow_p         := 161,  
  eSNVT_dev_c_mode     := 162,  
  eSNVT_valve_mode     := 163,  
  eSNVT_alarm_2        := 164,  
  eSNVT_state_64       := 165,  
  eSNVT_nv_type        := 166,  
  
  eSNVT_ent_opmode     := 168,  
  eSNVT_ent_state      := 169,  
  eSNVT_ent_status     := 170,  
  eSNVT_flow_dir       := 171,  
  eSNVT_hvac_satsts    := 172,  
  eSNVT_dev_status     := 173,  
  eSNVT_dev_fault      := 174,  
  eSNVT_dev_maint      := 175,  
  eSNVT_date_event     := 176,  
  eSNVT_sched_val      := 177,  
  eSNVT_sec_state      := 178,  
  eSNVT_sec_status     := 179,  
  eSNVT_sblnd_state    := 180,  
  eSNVT_rac_ctrl       := 181,  
  eSNVT_rac_req        := 182,  
  eSNVT_count_32       := 183,  
  eSNVT_clothes_w_c    := 184,  
  eSNVT_clothes_w_m    := 185,  
  eSNVT_clothes_w_s    := 186,  
  eSNVT_clothes_w_a    := 187,  
  eSNVT_multiplier_s   := 188,  
  eSNVT_switch_2       := 189,  
  eSNVT_color_2        := 190,  
  eSNVT_log_status     := 191,  
  eSNVT_time_stamp_p   := 192,  
  eSNVT_log_fx_request := 193,  
  eSNVT_log_fx_status  := 194,  
  eSNVT_log_request    := 195,  
  eSNVT_enthalpy_d     := 196,  
  eSNVT_amp_ac_mil     := 197,  
  eSNVT_time_hour_p    := 198,  
  eSNVT_lamp_status    := 199,  
  eSNVT_environment    := 200,  
  eSNVT_geo_loc        := 201  
)  
END_TYPE
```

**eEmpty:**

**eSNVT\_amp:** SNVT\_amp

**eSNVT\_amp\_mil:** SNVT\_amp\_mil

**eSNVT\_angle:** SNVT\_angle

**eSNVT\_angle\_vel:** SNVT\_angle\_vel

**eSNVT\_btu\_kilo:** SNVT\_btu\_kilo

**eSNVT\_btu\_mega:** SNVT\_btu\_mega

**eSNVT\_char\_ascii:** SNVT\_char\_ascii

**eSNVT\_count:** SNVT\_count

**eSNVT\_count\_inc:** SNVT\_count\_inc

**eSNVT\_date\_cal:** SNVT\_date\_cal

**eSNVT\_date\_day:** SNVT\_date\_day

**eSNVT\_date\_time:** SNVT\_date\_time

**eSNVT\_elec\_kwh:** SNVT\_elec\_kwh

**eSNVT\_elec\_whr:** SNVT\_elec\_whr

**eSNVT\_flow:** SNVT\_flow

**eSNVT\_flow\_mil:** SNVT\_flow\_mil

**eSNVT\_length:** SNVT\_length

**eSNVT\_length\_kilo:** SNVT\_length\_kilo

**eSNVT\_length\_micr:** SNVT\_length\_micr

**eSNVT\_length\_mil:** SNVT\_length\_mil

**eSNVT\_lev\_cont:** SNVT\_lev\_cont

**eSNVT\_lev\_disc:** SNVT\_lev\_disc

**eSNVT\_mass:** SNVT\_mass

**eSNVT\_mass\_kilo:** SNVT\_mass\_kilo

**eSNVT\_mass\_mega:** SNVT\_mass\_mega

**eSNVT\_mass\_mil:** SNVT\_mass\_mil

**eSNVT\_power:** SNVT\_power

**eSNVT\_power\_kilo:** SNVT\_power\_kilo

**eSNVT\_ppm:** SNVT\_ppm

**eSNVT\_press:** SNVT\_press

**eSNVT\_res:**  SNVT\_res

**eSNVT\_res\_kilo:**  SNVT\_res\_kilo

**eSNVT\_sound\_db:**  SNVT\_sound\_db

**eSNVT\_speed:**  SNVT\_speed

**eSNVT\_speed\_mil:**  SNVT\_speed\_mil

**eSNVT\_str\_asc:**  SNVT\_str\_asc

**eSNVT\_str\_int:**  SNVT\_str\_int

**eSNVT\_telcom:**  SNVT\_telcom

**eSNVT\_temp:**  SNVT\_temp

**eSNVT\_time\_passed:**  SNVT\_time\_passed

**eSNVT\_vol:**  SNVT\_vol

**eSNVT\_vol\_kilo:**  SNVT\_vol\_kilo

**eSNVT\_vol\_mil:**  SNVT\_vol\_mil

**eSNVT\_volt:**  SNVT\_volt

**eSNVT\_volt\_dbmv:**  SNVT\_volt\_dbmv

**eSNVT\_volt\_kilo:**  SNVT\_volt\_kilo

**eSNVT\_volt\_mil:**  SNVT\_volt\_mil

**eSNVT\_amp\_f:**  SNVT\_amp\_f

**eSNVT\_angle\_f:**  SNVT\_angle\_f

**eSNVT\_angle\_vel\_f:**  SNVT\_angle\_vel\_f

**eSNVT\_count\_f:**  SNVT\_count\_f

**eSNVT\_count\_inc\_f:**  SNVT\_count\_inc\_f

**eSNVT\_flow\_f:**  SNVT\_flow\_f

**eSNVT\_length\_f:**  SNVT\_length\_f

**eSNVT\_lev\_cont\_f:**  SNVT\_lev\_cont\_f

**eSNVT\_mass\_f:**  SNVT\_mass\_f

**eSNVT\_power\_f:**  SNVT\_power\_f

**eSNVT\_ppm\_f:**  SNVT\_ppm\_f

**eSNVT\_press\_f:**  SNVT\_press\_f

**eSNVT\_res\_f:**  SNVT\_res\_f

**eSNVT\_sound\_db\_f:**  SNVT\_sound\_db\_f

**eSNVT\_speed\_f:**  SNVT\_speed\_f

**eSNVT\_temp\_f:**  SNVT\_temp\_f

**eSNVT\_time\_f:**  SNVT\_time\_f

**eSNVT\_vol\_f:**  SNVT\_vol\_f

**eSNVT\_volt\_f:**  SNVT\_volt\_f

**eSNVT\_btu\_f:**  SNVT\_btu\_f

**eSNVT\_elec\_whr\_f:**  SNVT\_elec\_whr\_f

**eSNVT\_config\_src:**  SNVT\_config\_src

**eSNVT\_color:**  SNVT\_color

**eSNVT\_grammage:**  SNVT\_grammage

**eSNVT\_grammage\_f:**  SNVT\_grammage\_f

**eSNVT\_file\_req:**  SNVT\_file\_req

**eSNVT\_file\_status:**  SNVT\_file\_status

**eSNVT\_freq\_f:**  SNVT\_freq\_f

**eSNVT\_freq\_hz:**  SNVT\_freq\_hz

**eSNVT\_freq\_kilohz:**  SNVT\_freq\_kilohz

**eSNVT\_freq\_milhz:**  SNVT\_freq\_milhz

**eSNVT\_lux:**  SNVT\_lux

**eSNVT\_ISO\_7811:**  SNVT\_ISO\_7811

**eSNVT\_lev\_percent:**  SNVT\_lev\_percent

**eSNVT\_multiplier:**  SNVT\_multiplier

**eSNVT\_state:**  SNVT\_state

**eSNVT\_time\_stamp:**  SNVT\_time\_stamp

**eSNVT\_zerospan:**  SNVT\_zerospan

**eSNVT\_magcard:**  SNVT\_magcard

**eSNVT\_elapsed\_tm:**  SNVT\_elapsed\_tm

**eSNVT\_alarm:**  SNVT\_alarm

**eSNVT\_currency:**  SNVT\_currency

**eSNVT\_file\_pos:**  SNVT\_file\_pos

**eSNVT\_muldiv:**  SNVT\_muldiv

**eSNVT\_obj\_request:**  SNVT\_obj\_request

**eSNVT\_obj\_status:**  SNVT\_obj\_status

**eSNVT\_preset:**  SNVT\_preset

**eSNVT\_switch:**  SNVT\_switch

**eSNVT\_trans\_table:**  SNVT\_trans\_table

**eSNVT\_override:**  SNVT\_override

**eSNVT\_pwr\_fact:**  SNVT\_pwr\_fact

**eSNVT\_pwr\_fact\_f:**  SNVT\_pwr\_fact\_f

**eSNVT\_density:**  SNVT\_density

**eSNVT\_density\_f:**  SNVT\_density\_f

**eSNVT\_rpm:**  SNVT\_rpm

**eSNVT\_hvac\_emerg:**  SNVT\_hvac\_emerg

**eSNVT\_angle\_deg:**  SNVT\_angle\_deg

**eSNVT\_temp\_p:**  SNVT\_temp\_p

**eSNVT\_temp\_setpt:**  SNVT\_temp\_setpt

**eSNVT\_time\_sec:**  SNVT\_time\_sec

**eSNVT\_hvac\_mode:**  SNVT\_hvac\_mode

**eSNVT\_occupancy:**  SNVT\_occupancy

**eSNVT\_area:**  SNVT\_area

**eSNVT\_hvac\_overid:**  SNVT\_hvac\_overid

**eSNVT\_hvac\_status:**  SNVT\_hvac\_status

**eSNVT\_press\_p:**  SNVT\_press\_p

**eSNVT\_address:**  SNVT\_address

**eSNVT\_scene:**  SNVT\_scene

**eSNVT\_scene\_cfg:**  SNVT\_scene\_cfg

**eSNVT\_setting:**  SNVT\_setting

**eSNVT\_evap\_state:**  SNVT\_evap\_state

**eSNVT\_therm\_mode:**  SNVT\_therm\_mode

**eSNVT\_defr\_mode:**  SNVT\_defr\_mode

**eSNVT\_defr\_term:**  SNVT\_defr\_term

**eSNVT\_defr\_state:**  SNVT\_defr\_state

**eSNVT\_time\_min:**  SNVT\_time\_min

**eSNVT\_time\_hour:**  SNVT\_time\_hour

**eSNVT\_ppm:**  SNVT\_ph

**eSNVT\_ph\_f:**  SNVT\_ph\_f

**eSNVT\_chlr\_status:**  SNVT\_chlr\_status

**eSNVT\_tod\_event:**  SNVT\_tod\_event

**eSNVT\_smo\_obscur:**  SNVT\_smo\_obscur

**eSNVT\_fire\_test:**  SNVT\_fire\_test

**eSNVT\_temp\_ror:**  SNVT\_temp\_ror

**eSNVT\_fire\_init:**  SNVT\_fire\_init

**eSNVT\_fire\_indcte:**  SNVT\_fire\_indcte

**eSNVT\_time\_zone:**  SNVT\_time\_zone

**eSNVT\_earth\_pos:**  SNVT\_earth\_pos

**eSNVT\_reg\_val:**  SNVT\_reg\_val

**eSNVT\_reg\_val\_ts:**  SNVT\_reg\_val\_ts

**eSNVT\_volt\_ac:**  SNVT\_volt\_ac

**eSNVT\_amp\_ac:**  SNVT\_amp\_ac

**eSNVT\_turbidity:**  SNVT\_turbidity

**eSNVT\_turbidity\_f:**  SNVT\_turbidity\_f

**eSNVT\_hvac\_type:**  SNVT\_hvac\_type

**eSNVT\_elec\_kwh\_l:**  SNVT\_elec\_kwh\_l

**eSNVT\_temp\_diff\_p:**  SNVT\_temp\_diff\_p

**eSNVT\_ctrl\_req:**  SNVT\_ctrl\_req

**eSNVT\_ctrl\_resp:**  SNVT\_ctrl\_resp

**eSNVT\_ptz:**  SNVT\_ptz

**eSNVT\_privacyzone:**  SNVT\_privacyzone

**eSNVT\_pos\_ctrl:**  SNVT\_pos\_ctrl

**eSNVT\_enthalpy:**  SNVT\_enthalpy

**eSNVT\_gfci\_status:**  SNVT\_gfci\_status

**eSNVT\_motor\_state:**  SNVT\_motor\_state

**eSNVT\_pumpset\_mn:**  SNVT\_pumpset\_mn

**eSNVT\_ex\_control:**  SNVT\_ex\_control

**eSNVT\_pumpset\_sn:**  SNVT\_pumpset\_sn

**eSNVT\_pump\_sensor:**  SNVT\_pump\_sensor

**eSNVT\_abs\_humid:**  SNVT\_abs\_humid

**eSNVT\_flow\_p:**  SNVT\_flow\_p

**eSNVT\_dev\_c\_mode:**  SNVT\_dev\_c\_mode

**eSNVT\_valve\_mode:**  SNVT\_valve\_mode

**eSNVT\_alarm\_2:**  SNVT\_alarm\_2

**eSNVT\_state\_64:**  SNVT\_state\_64

**eSNVT\_nv\_type:**  SNVT\_nv\_type

**eSNVT\_ent\_opmode:**  SNVT\_ent\_opmode

**eSNVT\_ent\_state:**  SNVT\_ent\_state

**eSNVT\_ent\_status:**  SNVT\_ent\_status

**eSNVT\_flow\_dir:**  SNVT\_flow\_dir

**eSNVT\_hvac\_satsts:**  SNVT\_hvac\_satsts

**eSNVT\_dev\_status:**  SNVT\_dev\_status

**eSNVT\_dev\_fault:**  SNVT\_dev\_fault

**eSNVT\_dev\_maint:**  SNVT\_dev\_maint

**eSNVT\_date\_event:**  SNVT\_date\_event

**eSNVT\_sched\_val:**  SNVT\_sched\_val

**eSNVT\_sec\_state:**  SNVT\_sec\_state

**eSNVT\_sec\_status:**  SNVT\_sec\_status

**eSNVT\_sblnd\_state:**  SNVT\_sblnd\_state

**eSNVT\_rac\_ctrl:**  SNVT\_rac\_ctrl

**eSNVT\_rac\_req:**  SNVT\_rac\_req

**eSNVT\_count\_32:**  SNVT\_count\_32

**eSNVT\_clothes\_w\_c:**  SNVT\_clothes\_w\_c

**eSNVT\_clothes\_w\_m:**  SNVT\_clothes\_w\_m

**eSNVT\_clothes\_w\_s:**  SNVT\_clothes\_w\_s

**eSNVT\_clothes\_w\_a:**  SNVT\_clothes\_w\_a

**eSNVT\_multiplier\_s:**  SNVT\_multiplier\_s

**eSNVT\_switch\_2:**  SNVT\_switch\_2

**eSNVT\_color\_2:**  SNVT\_color\_2

**eSNVT\_log\_status:**  SNVT\_log\_status

**eSNVT\_time\_stamp\_p:**  SNVT\_time\_stamp\_p

**eSNVT\_log\_fx\_request:**  SNVT\_log\_fx\_request

**eSNVT\_log\_fx\_status:**  SNVT\_log\_fx\_status

**eSNVT\_log\_request:**  SNVT\_log\_request

**eSNVT\_enthalpy\_d:**  SNVT\_enthalpy\_d

**eSNVT\_amp\_ac\_mil:**  SNVT\_amp\_ac\_mil

**eSNVT\_time\_hour\_p:**  SNVT\_time\_hour\_p

**eSNVT\_lamp\_status:**  SNVT\_lamp\_status

**eSNVT\_environment:**  SNVT\_environment

**eSNVT\_geo\_loc:**  SNVT\_geo\_loc

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
