# E_LON_ERROR

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_ERROR

Library error messages

|  |  |
| --- | --- |
| 17300225 | The NV index in the PLC is not compared with the NV index (column Id) in the KS2000 during sending. Wrong/invalid values can be sent if the indices do not match. |

Sending without binding does no result in an error message.

```
TYPE E_LON_ERROR :  
(  
  eLON_no_Error                                                                := 0,  
  eLON_Value_out_of_range                                                      := 1,  
  eLON_Terminal_not_ready                                                      := 2,  
  eLON_Wrong_SNVT_Typ                                                          := 3,  
  eLON_Wrong_wNVIndex                                                          := 4,  
  eKL6401_Wrong_Terminal                                                       := 5,  
  eKL6401_Error                                                                := 6,  
  eKL6401_Terminal_is_not_initialized                                          := 7,  
  
  eLON_L_star_Out_of_range                                                     := 50,  
  eLON_A_star_Out_of_range                                                     := 51,  
  eLON_B_star_Out_of_range                                                     := 52,  
  
  eLON_eRequest_Out_of_range                                                   := 55,  
  
  eLON_wYear_Out_of_range                                                      := 66,  
  eLON_wMonth_Out_of_range                                                     := 67,  
  eLON_wDay_Out_of_range                                                       := 68,  
  eLON_wHour_Out_of_range                                                      := 69,  
  eLON_wMinute_Out_of_range                                                    := 70,  
  eLON_wSecond_Out_of_range                                                    := 71,  
  eLON_wMillisecond_Out_of_range                                               := 72,  
  
  eLON_rZero_Out_of_range                                                      := 80,  
  eLON_rSpan_Out_of_range                                                      := 81,  
  
  eLON_arrValue01_Out_of_range                                                 := 85,  
  eLON_arrValue02_Out_of_range                                                 := 86,  
  eLON_arrValue03_Out_of_range                                                 := 87,  
  eLON_arrValue04_Out_of_range                                                 := 88,  
  eLON_arrValue05_Out_of_range                                                 := 89,  
  eLON_arrValue06_Out_of_range                                                 := 90,  
  eLON_arrValue07_Out_of_range                                                 := 91,  
  eLON_arrValue08_Out_of_range                                                 := 92,  
  eLON_arrValue09_Out_of_range                                                 := 93,  
  
  eLON_arrValue10_Out_of_range                                                 := 100,  
  eLON_arrValue11_Out_of_range                                                 := 101,  
  eLON_arrValue12_Out_of_range                                                 := 102,  
  eLON_arrValue13_Out_of_range                                                 := 103,  
  eLON_arrValue14_Out_of_range                                                 := 104,  
  eLON_arrValue15_Out_of_range                                                 := 105,  
  eLON_arrValue16_Out_of_range                                                 := 106,  
  eLON_arrValue17_Out_of_range                                                 := 107,  
  eLON_arrValue18_Out_of_range                                                 := 108,  
  eLON_arrValue19_Out_of_range                                                 := 109,  
  
  eLON_arrValue20_Out_of_range                                                 := 115,  
  eLON_arrValue21_Out_of_range                                                 := 116,  
  eLON_arrValue22_Out_of_range                                                 := 117,  
  eLON_arrValue23_Out_of_range                                                 := 118,  
  eLON_arrValue24_Out_of_range                                                 := 119,  
  eLON_arrValue25_Out_of_range                                                 := 120,  
  eLON_arrValue26_Out_of_range                                                 := 121,  
  eLON_arrValue27_Out_of_range                                                 := 122,  
  eLON_arrValue28_Out_of_range                                                 := 123,  
  eLON_arrValue29_Out_of_range                                                 := 124,  
  
  eLON_arrValue30_Out_of_range                                                 := 130,  
  eLON_arrValue31_Out_of_range                                                 := 131,  
  eLON_arrValue32_Out_of_range                                                 := 132,  
  eLON_arrValue33_Out_of_range                                                 := 133,  
  eLON_arrValue34_Out_of_range                                                 := 134,  
  eLON_arrValue35_Out_of_range                                                 := 135,  
  eLON_arrValue36_Out_of_range                                                 := 136,  
  eLON_arrValue37_Out_of_range                                                 := 137,  
  eLON_arrValue38_Out_of_range                                                 := 138,  
  eLON_arrValue39_Out_of_range                                                 := 139,  
  eLON_arrValue40_Out_of_range                                                 := 140,  
  
  eLON_087uiDay_Out_of_range                                                   := 145,  
  eLON_087uiHour_Out_of_range                                                  := 146,  
  eLON_087uiMinute_Out_of_range                                                := 147,  
  eLON_087uiSecond_Out_of_range                                                := 148,  
  eLON_087uiMillisecond_Out_of_range                                           := 149,  
  
  eLON_ePriorty_level_Out_of_range                                             := 155,  
  eLON_eAlarm_type_Out_of_range                                                := 156,  
  
  eLON_Currency_Out_of_range                                                   := 160,  
  
  eLON_diRw_ptr_Out_of_range                                                   := 165,  
  
  eLON_Object_request_Out_of_range                                             := 170,  
  
  eLON_094eLearn_Out_of_range                                                  := 175,  
  eLON_094uiHour_Out_of_range                                                  := 176,  
  eLON_094uiMinute_Out_of_range                                                := 177,  
  eLON_094uiSecond_Out_of_range                                                := 178,  
  eLON_094uiMillisecond_Out_of_range                                           := 179,  
  
  eLON_095rValue_Out_of_range                                                  := 185,  
  eLON_095siState_Out_of_range                                                 := 186,  
  
  eLON_byInterp_pts_0_to_1_Out_of_range                                        := 190,  
  eLON_byInterp_pts_1_to_2_Out_of_range                                        := 191,  
  eLON_byInterp_pts_2_to_3_Out_of_range                                        := 192,  
  eLON_byInterp_pts_3_to_4_Out_of_range                                        := 193,  
  eLON_byInterp_pts_4_to_5_Out_of_range                                        := 194,  
  eLON_byInterp_pts_5_to_6_Out_of_range                                        := 195,  
  eLON_byInterp_pts_6_to_0_Out_of_range                                        := 196,  
  
  eLON_rOccupied_cool_Out_of_range                                             := 200,  
  eLON_rStandby_cool_Out_of_range                                              := 201,  
  eLON_rUnoccupied_cool_Out_of_range                                           := 202,  
  eLON_rOccupied_heat_Out_of_range                                             := 203,  
  eLON_rStandby_heat_Out_of_range                                              := 204,  
  eLON_rUnoccupied_heat_Out_of_range                                           := 205,  
  
  eLON_111rPercent_Out_of_range                                                := 210,  
  eLON_111eState_Out_of_range                                                  := 211,  
  
  eLON_eMode_Out_of_range                                                      := 215,  
  eLON_rHeat_output_primary_Out_of_range                                       := 216,  
  eLON_rHeat_output_secondary_Out_of_range                                     := 217,  
  eLON_rCool_output_Out_of_range                                               := 218,  
  eLON_rEcon_output_Out_of_range                                               := 219,  
  eLON_rFan_output_Out_of_range                                                := 220,  
  
  eLON_115eFunction_Out_of_range                                               := 225,  
  
  eLON_eFunction_Out_of_range                                                  := 226,  
  eLON_rSetting_Out_of_range                                                   := 227,  
  eLON_rRotation_Out_of_range                                                  := 228,  
  eLON_rFade_time_Out_of_range                                                 := 229,  
  eLON_rDelay_time_Out_of_range                                                := 230,  
  
  eLON_eChlr_run_mode_Out_of_range                                             := 235,  
  eLON_echlr_op_mode_Out_of_range                                              := 236,  
  
  eLON_eNext_state_Out_of_range                                                := 240,  
  eLON_eCurrent_state_Out_of_range                                             := 241,  
  
  eLON_diSecond_time_offset_Out_of_range                                       := 245,  
  eLON_eType_of_description_Out_of_range                                       := 246,  
  eLON_byHour_of_start_DST_Out_of_range                                        := 250,  
  eLON_byMinute_of_start_DST_Out_of_range                                      := 251,  
  eLON_bySecond_of_start_DST_Out_of_range                                      := 252,  
  eLON_byHour_of_end_DST_Out_of_range                                          := 260,  
  eLON_byMinute_of_end_DST_Out_of_range                                        := 261,  
  eLON_bySecond_of_end_DST_Out_of_range                                        := 262,  
  eLON_stStart_DST_uiG_day_of_start_DST_Out_of_range                           := 263,  
  eLON_stStart_DST_uiJ_day_of_start_DST_Out_of_range                           := 264,  
  eLON_stStart_DST_stM_start_DST_byMonth_of_start_DST_Out_of_range             := 265,  
  eLON_stStart_DST_stM_start_DST_byWeek_of_start_DST_Out_of_range              := 266,  
  eLON_stStart_DST_stM_start_DST_eDateday_of_start_DST_Out_of_range            := 267,  
  eLON_stEnd_DST_uiG_day_of_end_DST_Out_of_range                               := 268,  
  eLON_stEnd_DST_uiJ_day_of_end_DST_Out_of_range                               := 269,  
  eLON_stEnd_DST_stM_end_DST_byMonth_of_end_DST_Out_of_range                   := 270,  
  eLON_stEnd_DST_stM_end_DST_byWeek_of_end_DST_Out_of_range                    := 271,  
  eLON_stEnd_DST_stM_end_DST_eDateday_of_end_DST_Out_of_range                  := 272,  
  
  eLON_byLatitude_deg_Out_of_range                                             := 280,  
  eLON_rLatitude_min_Out_of_range                                              := 281,  
  eLON_bylongitude_deg_Out_of_range                                            := 282,  
  eLON_rLongitude_min_Out_of_range                                             := 283,  
  
  eLON_byNr_decimals_Out_of_range                                              := 290,  
  eLON_eUnit_Out_of_range                                                      := 291,  
  
  eLON_137eUnit_Out_of_range                                                   := 295,  
  eLON_137byNr_decimals_Out_of_range                                           := 296,  
  eLON_137byStatus_Out_of_range                                                := 297,  
  eLON_137uiYear_Out_of_range                                                  := 298,  
  eLON_137uiMonth_Out_of_range                                                 := 299,  
  eLON_137uiDay_Out_of_range                                                   := 300,  
  eLON_137uiHour_Out_of_range                                                  := 301,  
  eLON_137uiMinute_Out_of_range                                                := 302,  
  eLON_137uiSecond_Out_of_range                                                := 303,  
  
  eLON_bySender_prio_Out_of_range                                              := 310,  
  
  eLON_eStatus_Out_of_range                                                    := 315,  
  eLON_stSender_uiID_Out_of_range                                              := 316,  
  eLON_stSender_stRange_uiLower_Out_of_range                                   := 317,  
  eLON_stSender_stRange_uiUpper_Out_of_range                                   := 318,  
  eLON_uiController_id_Out_of_range                                            := 319,  
  
  eLON_ePan_dir_Out_of_range                                                   := 325,  
  eLON_rPan_speed_Out_of_range                                                 := 326,  
  eLON_eTilt_dir_Out_of_range                                                  := 327,  
  eLON_rTilt_speed_Out_of_range                                                := 328,  
  eLON_eZoom_Out_of_range                                                      := 329,  
  eLON_rZoom_speed_Out_of_range                                                := 330,  
  
  eLON_eAction_Out_of_range                                                    := 335,  
  
  eLON_byController_prio_Out_of_range                                          := 340,  
  eLON_152eFunction_Out_of_range                                               := 341,  
  eLON_152eAction_Out_of_range                                                 := 342,  
  eLON_stValue_stAbspos_rZoom_Out_of_range                                     := 343,  
  eLON_stValue_stAbspos_rTilt_Out_of_range                                     := 344,  
  eLON_stValue_stAbspos_rPan_Out_of_range                                      := 345,  
  
  eLON_eMain_pump_Out_of_range                                                 := 350,  
  eLON_eBooster_pump_Out_of_range                                              := 351,  
  eLON_ePriority_level_Out_of_range                                            := 352,  
  eLON_eProcess_ready_Out_of_range                                             := 353,  
  eLON_eEmergency_stop_activated_Out_of_range                                  := 354,  
  eLON_eMain_pump_drive_enabled_Out_of_range                                   := 355,  
  eLON_eBooster_pump_drive_enabled_Out_of_range                                := 356,  
  eLON_eMaintenance_required_Out_of_range                                      := 357,  
  
  eLON_eControl_status_Out_of_range                                            := 365,  
  eLON_stControl_device_addr_byDomain_length_Out_of_range                      := 366,  
  eLON_stControl_device_addr_bySubnet_Out_of_range                             := 367,  
  eLON_stControl_device_addr_byNode_Out_of_range                               := 368,  
  
  eLON_rExhaust_temperature_Out_of_range                                       := 375,  
  eLON_rExhaust_pressure_Out_of_range                                          := 376,  
  eLON_rShaft_seal_purge_pressure_Out_of_range                                 := 377,  
  eLON_rSupply_voltage_Out_of_range                                            := 378,  
  eLON_eCoolant_flow_low_Out_of_range                                          := 379,  
  eLON_eDilution_active_Out_of_range                                           := 380,  
  eLON_eBallast_dilution_active_Out_of_range                                   := 381,  
  eLON_eInlet_purge_dilution_active_Out_of_range                               := 382,  
  eLON_eExhaust_dilution_active_Out_of_range                                   := 383,  
  eLON_eDilution_flow_Out_of_range                                             := 384,  
  eLON_ePower_supply_on_Out_of_range                                           := 385,  
  
  eLON_rRotational_speed_Out_of_range                                          := 390,  
  eLON_rBody_temperature_Out_of_range                                          := 391,  
  eLON_rMotor_external_temperature_Out_of_range                                := 392,  
  eLON_rMotor_internal_temperature_Out_of_range                                := 393,  
  eLON_eMotor_overloaded_Out_of_range                                          := 394,  
  eLON_eOil_level_low_Out_of_range                                             := 395,  
  eLON_ePhase_imbalance_detected_Out_of_range                                  := 396,  
  eLON_rCurrent_usage_Out_of_range                                             := 397,  
  eLON_rPower_usage_Out_of_range                                               := 398,  
  eLON_eTemperature_control_Out_of_range                                       := 399,  
  eLON_eElectromagnetic_brake_active_Out_of_range                              := 400,  
  eLON_eFriction_brake_active_Out_of_range                                     := 401,  
  eLON_eGas_brake_active_Out_of_range                                          := 402,  
  
  eLON_164iMilliseconds_Out_of_range                                           := 410,  
  eLON_164ePriority_level_Out_of_range                                         := 411,  
  eLON_164eAlarm_type_Out_of_range                                             := 412,  
  
  eLON_byType_scope_Out_of_range                                               := 420,  
  eLON_uiType_index_Out_of_range                                               := 421,  
  eLON_eType_category_Out_of_range                                             := 422,  
  eLON_byType_length_Out_of_range                                              := 423,  
  
  eLON_eCmd_fb_Out_of_range                                                    := 430,  
  
  eLON_byManufacturer_Out_of_range                                             := 435,  
  
  eLON_eDevice_select_Out_of_range                                             := 440,  
  
  eLON_stPos_eFunction_Out_of_range                                            := 445,  
  eLON_stPos_rSetting_Out_of_range                                             := 446,  
  eLON_stPos_rRotation_Out_of_range                                            := 447,  
  eLON_eCmd_source_Out_of_range                                                := 448,  
  eLON_eError_code_Out_of_range                                                := 449,  
  
  eLON_181stAddr_talk_eAudio_sensor_type_Out_of_range                          := 455,  
  eLON_181stAddr_talk_byCar_id_Out_of_range                                    := 456,  
  eLON_181stAddr_talk_byLocation_Out_of_range                                  := 457,  
  eLON_181stAddr_talk_byUnit_id_Out_of_range                                   := 458,  
  eLON_181stAddr_init_eAudio_sensor_type_Out_of_range                          := 459,  
  eLON_181stAddr_init_byCar_id_Out_of_range                                    := 450,  
  eLON_181stAddr_init_byLocation_Out_of_range                                  := 461,  
  eLON_181stAddr_init_byUnit_id_Out_of_range                                   := 462,  
  eLON_181eAudio_type_Out_of_range                                             := 463,  
  eLON_181byAudio_line_Out_of_range                                            := 464,  
  eLON_181stAddr_dest_stP2p_eAudio_sensor_type_Out_of_range                    := 465,  
  eLON_181stAddr_dest_stP2p_byCar_id_Out_of_range                              := 466,  
  eLON_181stAddr_dest_stP2p_byLocation_Out_of_range                            := 467,  
  eLON_181stAddr_dest_stP2p_byUnit_id_Out_of_range                             := 468,  
  
  eLON_stAddr_dest_stP2p_eAudio_sensor_type_Out_of_range                       := 475,  
  eLON_stAddr_dest_stP2p_byCar_id_Out_of_range                                 := 476,  
  eLON_stAddr_dest_stP2p_byLocation_Out_of_range                               := 477,  
  eLON_stAddr_dest_stP2p_byUnit_id_Out_of_range                                := 478,  
  eLON_stAddr_init_eAudio_sensor_type_Out_of_range                             := 479,  
  eLON_stAddr_init_byCar_id_Out_of_range                                       := 480,  
  eLON_stAddr_init_byLocation_Out_of_range                                     := 481,  
  eLON_stAddr_init_byUnit_id_Out_of_range                                      := 482,  
  eLON_eAudio_type_Out_of_range                                                := 483,  
  
  eLON_eCycle_Out_of_range                                                     := 490,  
  eLON_eSubcycle_Out_of_range                                                  := 491,  
  eLON_stFunction_eProgram_Out_of_range                                        := 492,  
  eLON_stFunction_stWash_eLoad_level_Out_of_range                              := 493,  
  eLON_stFunction_stWash_ePrewash_Out_of_range                                 := 494,  
  eLON_stFunction_stRinse_eOption_Out_of_range                                 := 495,  
  eLON_stFunction_stRinse_byRepeat_Out_of_range                                := 496,  
  eLON_stFunction_stSpin_eHold_Out_of_range                                    := 497,  
  eLON_stFunction_stDry_byTemp_Out_of_range                                    := 498,  
  eLON_stFunction_stDry_stDuration_eDryness_Out_of_range                       := 499,  
  
  
  eLON_186eCycle_Out_of_range                                                  := 505,  
  eLON_186eSubcycle_Out_of_range                                               := 506,  
  eLON_stWasher_command_data_eCycle_Out_of_range                               := 507,  
  eLON_stWasher_command_data_eSubcycle_Out_of_range                            := 508,  
  eLON_stWasher_command_data_stFunction_eProgram_Out_of_range                  := 509,  
  eLON_stWasher_command_data_stFunction_stWash_eLoad_level_Out_of_range        := 510,  
  eLON_stWasher_command_data_stFunction_stWash_ePrewash_Out_of_range           := 511,  
  eLON_stWasher_command_data_stFunction_stRinse_eOption_Out_of_range           := 512,  
 eLON_stWasher_command_data_stFunction_stRinse_byRepeat_Out_of_range            := 513,  
  eLON_stWasher_command_data_stFunction_stSpin_eHold_Out_of_range              := 514,  
  eLON_stWasher_command_data_stFunction_stDry_byTemp_Out_of_range              := 515,  
  eLON_stWasher_command_data_stFunction_stDry_stDuration_eDryness_Out_of_range := 516,  
  
  eLON_eState_Out_of_range                                                     := 518,  
  eLON_stSetting_rValue_Out_of_range                                           := 519,  
  eLON_stSetting_rChange_Out_of_range                                          := 520,  
  eLON_stSetting_rMultiplier_Out_of_range                                      := 521,  
  eLON_stSetting_iAngle_Out_of_range                                           := 522,  
  eLON_stSetting_byGroup_number_Out_of_range                                   := 523,  
  eLON_stSetting_siFan_level_Out_of_range                                      := 524,  
  
  eLON_stColor_value_stCIE1931_lumen_rX_Out_of_range                           := 525,  
  eLON_stColor_value_stCIE1931_lumen_rY_Out_of_range                           := 526,  
  eLON_stColor_value_stCIE1931_lumen_udiAbsolute_Y_Out_of_range                := 527,  
  eLON_stColor_value_stCIE1931_percent_rX_Out_of_range                         := 528,  
  eLON_stColor_value_stCIE1931_percent_rY_Out_of_range                         := 529,  
  eLON_stColor_value_stCIE1931_percent_rPercent_Y_Out_of_range                 := 530,  
  eLON_stColor_value_uiColor_temperature_Out_of_range                          := 531,  
  
  eLON_191eStatus_Out_of_range                                                 := 535,  
  eLON_uiLog_number_Out_of_range                                               := 536,  
  eLON_rLevel_Out_of_range                                                     := 537,  
  eLON_stCurrent_notify_time_rHundredths_Out_of_range                          := 538,  
  eLON_stPrevious_notify_time_rHundredths_Out_of_range                         := 539,  
  
  eLON_rHundredths_Out_of_range                                                := 545,  
  
  eLON_stStart_time_rHundredths_Out_of_range                                   := 550,  
  eLON_stEnd_time_rHundredths_Out_of_range                                     := 551,  
  
  eLON_rComplete_Out_of_range                                                  := 565,  
  
  eLON_stTime_actual_rHundredths_Out_of_range                                  := 570,  
  eLON_stTime_previous_rHundredths_Out_of_range                                := 571,  
  
  eLON_lrEnergy_Out_of_range                                                   := 585,  
  eLON_rPowerFactor_Out_of_range                                               := 586,  
  eLON_rPower_Out_of_range                                                     := 587,  
  eLON_rBallastTemp_Out_of_range                                               := 588,  
  
  eLON_lrLongitude_Out_of_range                                                := 595,  
  eLON_lrLatitude_Out_of_range                                                 := 596  
)  
END_TYPE
```

**eLON\_no\_Error:** No error is pending.

**eLON\_Value\_out\_of\_range:** The input variable "Value" is outside the permitted range. The value was not sent. "Value" can have different formats with corresponding prefix (e.g. LREAL = lrValue).

**eLON\_Terminal\_not\_ready:** The function block "FB\_LON\_KL6401" passes through an initialization step chain (query terminal type, query firmware etc.) when the PLC is started. This message is issued as along as the initialization is in progress. If an error is pending after a PLC reset, the controller should be de-energized once.

**eLON\_Wrong\_SNVT\_Typ:** The received SNVT type does not match the SNVT type of the addressed NV index (input variable "wId").

**eLON\_Wrong\_wNVIndex:** Incorrect NV index.

**eKL6401\_Wrong\_Terminal:** No KL6401 was detected.

**eKL6401\_Error:** The function block "FB\_LON\_KL6401" has an error. The error code is shown at output "dwErrorKL".

**eKL6401\_Terminal\_is\_not\_initialized:** The terminal is not initialized. This message usually means that there is no connection to the terminal. Terminal linked to the variables in the System Manager? Terminal plugged in incorrectly? Everything corrected, everything translated and re-read into the System Manager?

**eLON\_L\_star\_Out\_of\_range:** SNVT 70 / The input variable "stValue.L\_star" is outside the permitted range. The value was not sent.

**eLON\_A\_star\_Out\_of\_range:** SNVT 70 / The input variable "stValue.A\_star" is outside the permitted range. The value was not sent.

**eLON\_B\_star\_Out\_of\_range:** SNVT 70 / The input variable "stValue.B\_star" is outside the permitted range. The value was not sent.

**eLON\_eRequest\_Out\_of\_range:** SNVT 73 / The input variable "stValue.eRequest" is outside the permitted range. The value was not sent.

**eLON\_wYear\_Out\_of\_range:** SNVT 084 / 088 / The input variable "stValue.wYear" is outside the permitted range. The value was not sent.

**eLON\_wMonth\_Out\_of\_range:** SNVT 084 / 088 / The input variable "stValue.wMonth" is outside the permitted range. The value was not sent.

**eLON\_wDay\_Out\_of\_range:** SNVT 084 / 088 / The input variable "stValue.wDay" is outside the permitted range. The value was not sent.

**eLON\_wHour\_Out\_of\_range:** SNVT 084 / 088 / The input variable "stValue.wHour" is outside the permitted range. The value was not sent.

**eLON\_wMinute\_Out\_of\_range:** SNVT 084 / 088 / The input variable "stValue.wMinute" is outside the permitted range. The value was not sent.

**eLON\_wSecond\_Out\_of\_range:** SNVT 084 / 088 / The input variable "stValue.wSecond" is outside the permitted range. The value was not sent.

**eLON\_wMillisecond\_Out\_of\_range:** SNVT 73 / The input variable "stValue.wMillisecond" is outside the permitted range. The value was not sent.

**eLON\_rZero\_Out\_of\_range:** SNVT 085 / The input variable "stValue.rZero" is outside the permitted range. The value was not sent.

**eLON\_rSpan\_Out\_of\_range:** SNVT 085 / The input variable "stValue.rSpan" is outside the permitted range. The value was not sent.

**eLON\_arrValue01\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[1]" is outside the permitted range. The value was not sent.

**eLON\_arrValue02\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[2]" is outside the permitted range. The value was not sent.

**eLON\_arrValue03\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[3]" is outside the permitted range. The value was not sent.

**eLON\_arrValue04\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[4]" is outside the permitted range. The value was not sent.

**eLON\_arrValue05\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[5]" is outside the permitted range. The value was not sent.

**eLON\_arrValue06\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[6]" is outside the permitted range. The value was not sent.

**eLON\_arrValue07\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[7]" is outside the permitted range. The value was not sent.

**eLON\_arrValue08\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[8]" is outside the permitted range. The value was not sent.

**eLON\_arrValue09\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[9]" is outside the permitted range. The value was not sent.

**eLON\_arrValue10\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[10]" is outside the permitted range. The value was not sent.

**eLON\_arrValue11\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[11]" is outside the permitted range. The value was not sent.

**eLON\_arrValue12\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[12]" is outside the permitted range. The value was not sent.

**eLON\_arrValue13\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[13]" is outside the permitted range. The value was not sent.

**eLON\_arrValue14\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[14]" is outside the permitted range. The value was not sent.

**eLON\_arrValue15\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[15]" is outside the permitted range. The value was not sent.

**eLON\_arrValue16\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[16]" is outside the permitted range. The value was not sent.

**eLON\_arrValue17\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[17]" is outside the permitted range. The value was not sent.

**eLON\_arrValue18\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[18]" is outside the permitted range. The value was not sent.

**eLON\_arrValue19\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[19]" is outside the permitted range. The value was not sent.

**eLON\_arrValue20\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[20]" is outside the permitted range. The value was not sent.

**eLON\_arrValue21\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[21]" is outside the permitted range. The value was not sent.

**eLON\_arrValue22\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[22]" is outside the permitted range. The value was not sent.

**eLON\_arrValue23\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[23]" is outside the permitted range. The value was not sent.

**eLON\_arrValue24\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[24]" is outside the permitted range. The value was not sent.

**eLON\_arrValue25\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[25]" is outside the permitted range. The value was not sent.

**eLON\_arrValue26\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[26]" is outside the permitted range. The value was not sent.

**eLON\_arrValue27\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[27]" is outside the permitted range. The value was not sent.

**eLON\_arrValue28\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[28]" is outside the permitted range. The value was not sent.

**eLON\_arrValue29\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[29]" is outside the permitted range. The value was not sent.

**eLON\_arrValue30\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[30]" is outside the permitted range. The value was not sent.

**eLON\_arrValue31\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[31]" is outside the permitted range. The value was not sent.

**eLON\_arrValue32\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[32]" is outside the permitted range. The value was not sent.

**eLON\_arrValue33\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[33]" is outside the permitted range. The value was not sent.

**eLON\_arrValue34\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[34]" is outside the permitted range. The value was not sent.

**eLON\_arrValue35\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[35]" is outside the permitted range. The value was not sent.

**eLON\_arrValue36\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[36]" is outside the permitted range. The value was not sent.

**eLON\_arrValue37\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[37]" is outside the permitted range. The value was not sent.

**eLON\_arrValue38\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[38]" is outside the permitted range. The value was not sent.

**eLON\_arrValue39\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[39]" is outside the permitted range. The value was not sent.

**eLON\_arrValue40\_Out\_of\_range:** SNVT 086 / The input variable "arrValue[40]" is outside the permitted range. The value was not sent.

**eLON\_087uiDay\_Out\_of\_range:** SNVT 087 / The input variable "stValue.uiDay" is outside the permitted range. The value was not sent.

**eLON\_087uiHour\_Out\_of\_range:** SNVT 087 / The input variable "stValue.uiHour" is outside the permitted range. The value was not sent.

**eLON\_087uiMinute\_Out\_of\_range:** SNVT 087 / The input variable "stValue.uiMinute" is outside the permitted range. The value was not sent.

**eLON\_087uiSecond\_Out\_of\_range:** SNVT 087 / The input variable "stValue.uiSecond" is outside the permitted range. The value was not sent.

**eLON\_087uiMillisecond\_Out\_of\_range:** SNVT 087 / The input variable "stValue.uiMillisecond" is outside the permitted range. The value was not sent.

**eLON\_ePriorty\_level\_Out\_of\_range:** SNVT 088 / The input variable "stValue.ePriorty\_level" is outside the permitted range. The value was not sent.

**eLON\_eAlarm\_type\_Out\_of\_range:** SNVT 088 / The input variable "stValue.eAlarm\_type" is outside the permitted range. The value was not sent.

**eLON\_Currency\_Out\_of\_range:** SNVT 089 / The input variable "stValue.Currency" is outside the permitted range. The value was not sent.

**eLON\_diRw\_ptr\_Out\_of\_range:** SNVT 090 / The input variable "stValue.diRw\_ptr" is outside the permitted range. The value was not sent.

**eLON\_Object\_request\_Out\_of\_range:** SNVT 092 / The input variable "stValue.Object\_request" is outside the permitted range. The value was not sent.

**eLON\_094eLearn\_Out\_of\_range:** SNVT 094 / The input variable "stValue.eLearn" is outside the permitted range. The value was not sent.

**eLON\_094uiHour\_Out\_of\_range:** SNVT 094 / The input variable "stValue.uiHour" is outside the permitted range. The value was not sent.

**eLON\_094uiMinute\_Out\_of\_range:** SNVT 094 / The input variable "stValue.uiMinute" is outside the permitted range. The value was not sent.

**eLON\_094uiSecond\_Out\_of\_range:** SNVT 094 / The input variable "stValue.uiSecond" is outside the permitted range. The value was not sent.

**eLON\_094uiMillisecond\_Out\_of\_range:** SNVT 094 / The input variable "stValue.uiMillisecond" is outside the permitted range. The value was not sent.

**eLON\_095rValue\_Out\_of\_range:** SNVT 095 / The input variable "stValue.rValue" is outside the permitted range. The value was not sent.

**eLON\_095siState\_Out\_of\_range:** SNVT 095 / The input variable "stValue.siState" is outside the permitted range. The value was not sent.

**eLON\_byInterp\_pts\_0\_to\_1\_Out\_of\_range:** SNVT 096 / The input variable "stValue.byInterp\_pts\_0\_to\_1" is outside the permitted range. The value was not sent.

**eLON\_byInterp\_pts\_1\_to\_2\_Out\_of\_range:** SNVT 096 / The input variable "stValue.byInterp\_pts\_1\_to\_2" is outside the permitted range. The value was not sent.

**eLON\_byInterp\_pts\_2\_to\_3\_Out\_of\_range:** SNVT 096 / The input variable "stValue.byInterp\_pts\_2\_to\_3" is outside the permitted range. The value was not sent.

**eLON\_byInterp\_pts\_3\_to\_4\_Out\_of\_range:** SNVT 096 / The input variable "stValue.byInterp\_pts\_3\_to\_4" is outside the permitted range. The value was not sent.

**eLON\_byInterp\_pts\_4\_to\_5\_Out\_of\_range:** SNVT 096 / The input variable "stValue.byInterp\_pts\_4\_to\_5" is outside the permitted range. The value was not sent.

**eLON\_byInterp\_pts\_5\_to\_6\_Out\_of\_range:** SNVT 096 / The input variable "stValue.byInterp\_pts\_5\_to\_6" is outside the permitted range. The value was not sent.

**eLON\_byInterp\_pts\_6\_to\_0\_Out\_of\_range:** SNVT 096 / The input variable "stValue.byInterp\_pts\_6\_to\_0" is outside the permitted range. The value was not sent.

**eLON\_rOccupied\_cool\_Out\_of\_range:** SNVT 106 / The input variable "stValue.rOccupied\_cool" is outside the permitted range. The value was not sent.

**eLON\_rStandby\_cool\_Out\_of\_range:** SNVT 106 / The input variable "stValue.rStandby\_cool" is outside the permitted range. The value was not sent.

**eLON\_rUnoccupied\_cool\_Out\_of\_range:** SNVT 106 / The input variable "stValue.rUnoccupied\_cool" is outside the permitted range. The value was not sent.

**eLON\_rOccupied\_heat\_Out\_of\_range:** SNVT 106 / The input variable "stValue.rOccupied\_heat" is outside the permitted range. The value was not sent.

**eLON\_rStandby\_heat\_Out\_of\_range:** SNVT 106 / The input variable "stValue.rStandby\_heat" is outside the permitted range. The value was not sent.

**eLON\_rUnoccupied\_heat\_Out\_of\_range:** SNVT 106 / The input variable "stValue.rUnoccupied\_heat" is outside the permitted range. The value was not sent.

**eLON\_111rPercent\_Out\_of\_range:** SNVT 111 / The input variable "stValue.rPercent" is outside the permitted range. The value was not sent.

**eLON\_111eState\_Out\_of\_range:** SNVT 111 / The input variable "stValue.eState" is outside the permitted range. The value was not sent.

**eLON\_eMode\_Out\_of\_range:** SNVT 112 / The input variable "stValue.eMode" is outside the permitted range. The value was not sent.

**eLON\_rHeat\_output\_primary\_Out\_of\_range:** SNVT 112 / The input variable "stValue.rHeat\_output\_primary" is outside the permitted range. The value was not sent.

**eLON\_rHeat\_output\_secondary\_Out\_of\_range:** SNVT 112 / The input variable "stValue.rHeat\_output\_secondary" is outside the permitted range. The value was not sent.

**eLON\_rCool\_output\_Out\_of\_range:** SNVT 112 / The input variable "stValue.rCool\_output" is outside the permitted range. The value was not sent.

**eLON\_rEcon\_output\_Out\_of\_range:** SNVT 112 / The input variable "stValue.rEcon\_output" is outside the permitted range. The value was not sent.

**eLON\_rFan\_output\_Out\_of\_range:** SNVT 112 / The input variable "stValue.rFan\_output" is outside the permitted range. The value was not sent.

**eLON\_115eFunction\_Out\_of\_range:** SNVT 115 / The input variable "stValue.eFunction" is outside the permitted range. The value was not sent.

**eLON\_eFunction\_Out\_of\_range:** SNVT 116 / 117 / The input variable "stValue.eFunction" is outside the permitted range. The value was not sent.

**eLON\_rSetting\_Out\_of\_range:** SNVT 116 / 117 / The input variable "stValue.rSetting" is outside the permitted range. The value was not sent.

**eLON\_rRotation\_Out\_of\_range:** SNVT 116 / 117 / The input variable "stValue.rRotation" is outside the permitted range. The value was not sent.

**eLON\_rFade\_time\_Out\_of\_range:** SNVT 116 / The input variable "stValue.rFade\_time" is outside the permitted range. The value was not sent.

**eLON\_rDelay\_time\_Out\_of\_range:** SNVT 116 / The input variable "stValue.rDelay\_time" is outside the permitted range. The value was not sent.

**eLON\_eChlr\_run\_mode\_Out\_of\_range:** SNVT 127 / The input variable "stValue.eChlr\_run\_mode" is outside the permitted range. The value was not sent.

**eLON\_echlr\_op\_mode\_Out\_of\_range:** SNVT 127 / The input variable "stValue.echlr\_op\_mode" is outside the permitted range. The value was not sent.

**eLON\_eNext\_state\_Out\_of\_range:** SNVT 128 / The input variable "stValue.eNext\_state" is outside the permitted range. The value was not sent.

**eLON\_eCurrent\_state\_Out\_of\_range:** SNVT 128 / The input variable "stValue.eCurrent\_state" is outside the permitted range. The value was not sent.

**eLON\_diSecond\_time\_offset\_Out\_of\_range:** SNVT 134 / The input variable "stValue.diSecond\_time\_offset" is outside the permitted range. The value was not sent.

**eLON\_eType\_of\_description\_Out\_of\_range:** SNVT 134 / The input variable "stValue.eType\_of\_description" is outside the permitted range. The value was not sent.

**eLON\_byHour\_of\_start\_DST\_Out\_of\_range:** SNVT 134 / The input variable "stValue.byHour\_of\_start\_DST" is outside the permitted range. The value was not sent.

**eLON\_byMinute\_of\_start\_DST\_Out\_of\_range:** SNVT 134 / The input variable "stValue.byMinute\_of\_start\_DST" is outside the permitted range. The value was not sent.

**eLON\_bySecond\_of\_start\_DST\_Out\_of\_range:** SNVT 134 / The input variable "stValue.bySecond\_of\_start\_DST" is outside the permitted range. The value was not sent.

**eLON\_byHour\_of\_end\_DST\_Out\_of\_range:** SNVT 134 / The input variable "stValue.byHour\_of\_end\_DST" is outside the permitted range. The value was not sent.

**eLON\_byMinute\_of\_end\_DST\_Out\_of\_range:** SNVT 134 / The input variable "stValue.byMinute\_of\_end\_DST" is outside the permitted range. The value was not sent.

**eLON\_bySecond\_of\_end\_DST\_Out\_of\_range:** SNVT 134 / The input variable "stValue.bySecond\_of\_end\_DST" is outside the permitted range. The value was not sent.

**eLON\_stStart\_DST\_uiG\_day\_of\_start\_DST\_Out\_of\_range:** SNVT 134 / The input variable "stValue.stStart\_DST.uiG\_day\_of\_start\_DST" is outside the permitted range. The value was not sent.

**eLON\_stStart\_DST\_uiJ\_day\_of\_start\_DST\_Out\_of\_range:** SNVT 134 / The input variable "stValue.stStart\_DST.uiJ\_day\_of\_start\_DST" is outside the permitted range. The value was not sent.

**eLON\_stStart\_DST\_stM\_start\_DST\_byMonth\_of\_start\_DST\_Out\_of\_range:** SNVT 134 / The input variable "stValue.stStart\_DST.stM\_start\_DST.byMonth\_of\_start\_DST" is outside the permitted range. The value was not sent.

**eLON\_stStart\_DST\_stM\_start\_DST\_byWeek\_of\_start\_DST\_Out\_of\_range:** SNVT 134 / The input variable "stValue.stStart\_DST.stM\_start\_DST.byWeek\_of\_start\_DST" is outside the permitted range. The value was not sent.

**eLON\_stStart\_DST\_stM\_start\_DST\_eDateday\_of\_start\_DST\_Out\_of\_range:** SNVT 134 / The input variable "stValue.stStart\_DST.stM\_start\_DST.eDateday\_of\_start\_DST" is outside the permitted range. The value was not sent.

**eLON\_stEnd\_DST\_uiG\_day\_of\_end\_DST\_Out\_of\_range:** SNVT 134 / The input variable "stValue.stEnd\_DST.uiG\_day\_of\_end\_DST" is outside the permitted range. The value was not sent.

**eLON\_stEnd\_DST\_uiJ\_day\_of\_end\_DST\_Out\_of\_range:** SNVT 134 / The input variable "stValue.stEnd\_DST.uiJ\_day\_of\_end\_DST" is outside the permitted range. The value was not sent.

**eLON\_stEnd\_DST\_stM\_end\_DST\_byMonth\_of\_end\_DST\_Out\_of\_range:** SNVT 134 / The input variable "stValue.stEnd\_DST.stM\_end\_DST.byMonth\_of\_end\_DST" is outside the permitted range. The value was not sent.

**eLON\_stEnd\_DST\_stM\_end\_DST\_byWeek\_of\_end\_DST\_Out\_of\_range:** SNVT 134 / The input variable "stValue.stEnd\_DST.stM\_end\_DST.byWeek\_of\_end\_DST" is outside the permitted range. The value was not sent.

**eLON\_stEnd\_DST\_stM\_end\_DST\_eDateday\_of\_end\_DST\_Out\_of\_range:** SNVT 134 / The input variable "stValue.stEnd\_DST.stM\_end\_DST.eDateday\_of\_end\_DST" is outside the permitted range. The value was not sent.

**eLON\_byLatitude\_deg\_Out\_of\_range:** SNVT 135 / The input variable "stValue.byLatitude" is outside the permitted range. The value was not sent.

**eLON\_rLatitude\_min\_Out\_of\_range:** SNVT 135 / The input variable "stValue.rLatitude" is outside the permitted range. The value was not sent.

**eLON\_bylongitude\_deg\_Out\_of\_range:** SNVT 135 / The input variable "stValue.bylongitude\_deg" is outside the permitted range. The value was not sent.

**eLON\_rLongitude\_min\_Out\_of\_range:** SNVT 135 / The input variable "stValue.rLongitude\_min" is outside the permitted range. The value was not sent.

**eLON\_byNr\_decimals\_Out\_of\_range:** SNVT 136 / The input variable "stValue.byNr\_decimals" is outside the permitted range. The value was not sent.

**eLON\_eUnit\_Out\_of\_range:** SNVT 136 / The input variable "stValue.eUnit" is outside the permitted range. The value was not sent.

**eLON\_137eUnit\_Out\_of\_range:** SNVT 137 / The input variable "stValue.eUnit" is outside the permitted range. The value was not sent.

**eLON\_137byNr\_decimals\_Out\_of\_range:** SNVT 137 / The input variable "stValue.byNr\_decimals" is outside the permitted range. The value was not sent.

**eLON\_137byStatus\_Out\_of\_range:** SNVT 137 / The input variable "stValue.byStatus" is outside the permitted range. The value was not sent.

**eLON\_137uiYear\_Out\_of\_range:** SNVT 137 / The input variable "stValue.uiYear" is outside the permitted range. The value was not sent.

**eLON\_137uiMonth\_Out\_of\_range:** SNVT 137 / The input variable "stValue.uiMonth" is outside the permitted range. The value was not sent.

**eLON\_137uiDay\_Out\_of\_range:** SNVT 137 / The input variable "stValue.uiDay" is outside the permitted range. The value was not sent.

**eLON\_137uiHour\_Out\_of\_range:** SNVT 137 / The input variable "stValue.uiHour" is outside the permitted range. The value was not sent.

**eLON\_137uiMinute\_Out\_of\_range:** SNVT 137 / The input variable "stValue.uiMinute" is outside the permitted range. The value was not sent.

**eLON\_137uiSecond\_Out\_of\_range:** SNVT 137 / The input variable "stValue.uiSecond" is outside the permitted range. The value was not sent.

**eLON\_bySender\_prio\_Out\_of\_range:** SNVT 148 / The input variable "stValue.bySender\_prio" is outside the permitted range. The value was not sent.

**eLON\_eStatus\_Out\_of\_range:** SNVT 149 / The input variable "stValue.eStatus" is outside the permitted range. The value was not sent.

**eLON\_stSender\_uiID\_Out\_of\_range:** SNVT 149 / The input variable "stValue.stSender.uiID" is outside the permitted range. The value was not sent.

**eLON\_stSender\_stRange\_uiLower\_Out\_of\_range:** SNVT 149 / The input variable "stValue.stSender.stRange.uiLower" is outside the permitted range. The value was not sent.

**eLON\_stSender\_stRange\_uiUpper\_Out\_of\_range:** SNVT 149 / The input variable "stValue.stSender.stRange.uiUpper" is outside the permitted range. The value was not sent.

**eLON\_uiController\_id\_Out\_of\_range:** SNVT 149 / The input variable "stValue.uiController" is outside the permitted range. The value was not sent.

**eLON\_ePan\_dir\_Out\_of\_range:** SNVT 150 / The input variable "stValue." is outside the permitted range. The value was not sent.

**eLON\_rPan\_speed\_Out\_of\_range:** SNVT 150 / The input variable "stValue." is outside the permitted range. The value was not sent.

**eLON\_eTilt\_dir\_Out\_of\_range:** SNVT 150 / The input variable "stValue." is outside the permitted range. The value was not sent.

**eLON\_rTilt\_speed\_Out\_of\_range:** SNVT 150 / The input variable "stValue." is outside the permitted range. The value was not sent.

**eLON\_eZoom\_Out\_of\_range:** SNVT 150 / The input variable "stValue." is outside the permitted range. The value was not sent.

**eLON\_rZoom\_speed\_Out\_of\_range:** SNVT 150 / The input variable "stValue." is outside the permitted range. The value was not sent.

**eLON\_eAction\_Out\_of\_range:** SNVT 151 / The input variable "stValue.eAction" is outside the permitted range. The value was not sent.

**eLON\_byController\_prio\_Out\_of\_range:** SNVT 152 / The input variable "stValue.byController" is outside the permitted range. The value was not sent.

**eLON\_152eFunction\_Out\_of\_range:** SNVT 152 / The input variable "stValue.eFunction" is outside the permitted range. The value was not sent.

**eLON\_152eAction\_Out\_of\_range:** SNVT 152 / The input variable "stValue.eAction" is outside the permitted range. The value was not sent.

**eLON\_stValue\_stAbspos\_rZoom\_Out\_of\_range:** SNVT 152 / The input variable "stValue.stValue.stAbspos.rZoom" is outside the permitted range. The value was not sent.

**eLON\_stValue\_stAbspos\_rTilt\_Out\_of\_range:** SNVT 152 / The input variable "stValue.stValue.stAbspos.rTilt" is outside the permitted range. The value was not sent.

**eLON\_stValue\_stAbspos\_rPan\_Out\_of\_range:** SNVT 152 / The input variable "stValue.stValue.stAbspos.rPan" is outside the permitted range. The value was not sent.

**eLON\_eMain\_pump\_Out\_of\_range:** SNVT 156 / The input variable "stValue.eMain\_pump" is outside the permitted range. The value was not sent.

**eLON\_eBooster\_pump\_Out\_of\_range:** SNVT 156 / The input variable "stValue.eBooster\_pump" is outside the permitted range. The value was not sent.

**eLON\_ePriority\_level\_Out\_of\_range:** SNVT 156 / The input variable "stValue.ePriority\_level" is outside the permitted range. The value was not sent.

**eLON\_eProcess\_ready\_Out\_of\_range:** SNVT 156 / The input variable "stValue.eProcess\_ready" is outside the permitted range. The value was not sent.

**eLON\_eEmergency\_stop\_activated\_Out\_of\_range:** SNVT 156 / The input variable "stValue.eEmergency\_stop\_activated" is outside the permitted range. The value was not sent.

**eLON\_eMain\_pump\_drive\_enabled\_Out\_of\_range:** SNVT 156 / The input variable "stValue.eMain\_pump\_drive\_enabled" is outside the permitted range. The value was not sent.

**eLON\_eBooster\_pump\_drive\_enabled\_Out\_of\_range:** SNVT 156 / The input variable "stValue.eBooster\_pump\_drive\_enabled" is outside the permitted range. The value was not sent.

**eLON\_eMaintenance\_required\_Out\_of\_range:** SNVT 156 / The input variable "stValue.eMaintenance\_required" is outside the permitted range. The value was not sent.

**eLON\_eControl\_status\_Out\_of\_range:** SNVT 157 / The input variable "stValue.eControl\_status" is outside the permitted range. The value was not sent.

**eLON\_stControl\_device\_addr\_byDomain\_length\_Out\_of\_range:** SNVT 157 / The input variable "stValue.stControl\_device\_addr.byDomain\_length" is outside the permitted range. The value was not sent.

**eLON\_stControl\_device\_addr\_bySubnet\_Out\_of\_range:** SNVT 157 / The input variable "stValue.stControl\_device\_addr.bySubnet" is outside the permitted range. The value was not sent.

**eLON\_stControl\_device\_addr\_byNode\_Out\_of\_range:** SNVT 157 / The input variable "stValue.stControl\_device\_addr.byNode" is outside the permitted range. The value was not sent.

**eLON\_rExhaust\_temperature\_Out\_of\_range:** SNVT 158 / The input variable "stValue.rExhaust\_temperature" is outside the permitted range. The value was not sent.

**eLON\_rExhaust\_pressure\_Out\_of\_range:** SNVT 158 / The input variable "stValue.rExhaust\_pressure" is outside the permitted range. The value was not sent.

**eLON\_rShaft\_seal\_purge\_pressure\_Out\_of\_range:** SNVT 158 / The input variable "stValue.rShaft\_seal\_purge\_pressure" is outside the permitted range. The value was not sent.

**eLON\_rSupply\_voltage\_Out\_of\_range:** SNVT 158 / The input variable "stValue.rSupply\_voltage" is outside the permitted range. The value was not sent.

**eLON\_eCoolant\_flow\_low\_Out\_of\_range:** SNVT 158 / The input variable "stValue.eCoolant\_flow\_low" is outside the permitted range. The value was not sent.

**eLON\_eDilution\_active\_Out\_of\_range:** SNVT 158 / The input variable "stValue.eDilution\_active" is outside the permitted range. The value was not sent.

**eLON\_eBallast\_dilution\_active\_Out\_of\_range:** SNVT 158 / The input variable "stValue.eBallast\_dilution\_active" is outside the permitted range. The value was not sent.

**eLON\_eInlet\_purge\_dilution\_active\_Out\_of\_range:** SNVT 158 / The input variable "stValue.eInlet\_purge\_dilution\_active" is outside the permitted range. The value was not sent.

**eLON\_eExhaust\_dilution\_active\_Out\_of\_range:** SNVT 158 / The input variable "stValue.eExhaust\_dilution\_active" is outside the permitted range. The value was not sent.

**eLON\_eDilution\_flow\_Out\_of\_range:** SNVT 158 / The input variable "stValue.eDilution\_flow" is outside the permitted range. The value was not sent.

**eLON\_ePower\_supply\_on\_Out\_of\_range:** SNVT 158 / The input variable "stValue.ePower\_supply\_on" is outside the permitted range. The value was not sent.

**eLON\_rRotational\_speed\_Out\_of\_range:** SNVT 159 / The input variable "stValue.rRotational\_speed" is outside the permitted range. The value was not sent.

**eLON\_rBody\_temperature\_Out\_of\_range:** SNVT 159 / The input variable "stValue.rBody" is outside the permitted range. The value was not sent.

**eLON\_rMotor\_external\_temperature\_Out\_of\_range:** SNVT 159 / The input variable "stValue.rMotor\_external\_temperature" is outside the permitted range. The value was not sent.

**eLON\_rMotor\_internal\_temperature\_Out\_of\_range:** SNVT 159 / The input variable "stValue.eMotor\_overloaded" is outside the permitted range. The value was not sent.

**eLON\_eMotor\_overloaded\_Out\_of\_range:** SNVT 159 / The input variable "stValue." is outside the permitted range. The value was not sent.

**eLON\_eOil\_level\_low\_Out\_of\_range:** SNVT 159 / The input variable "stValue.ePhase\_imbalance\_detected" is outside the permitted range. The value was not sent.

**eLON\_ePhase\_imbalance\_detected\_Out\_of\_range:** SNVT 159 / The input variable "stValue." is outside the permitted range. The value was not sent.

**eLON\_rCurrent\_usage\_Out\_of\_range:** SNVT 159 / The input variable "stValue.rCurrent\_usage" is outside the permitted range. The value was not sent.

**eLON\_rPower\_usage\_Out\_of\_range:** SNVT 159 / The input variable "stValue.Power\_usage" is outside the permitted range. The value was not sent.

**eLON\_eTemperature\_control\_Out\_of\_range:** SNVT 159 / The input variable "stValue.eElectromagnetic\_brake\_active" is outside the permitted range. The value was not sent.

**eLON\_eElectromagnetic\_brake\_active\_Out\_of\_range:** SNVT 159 / The input variable "stValue." is outside the permitted range. The value was not sent.

**eLON\_eFriction\_brake\_active\_Out\_of\_range:** SNVT 159 / The input variable "stValue.eFriction\_brake\_active" is outside the permitted range. The value was not sent.

**eLON\_eGas\_brake\_active\_Out\_of\_range:** SNVT 159 / The input variable "stValue.eGas\_brake\_active" is outside the permitted range. The value was not sent.

**eLON\_164iMilliseconds\_Out\_of\_range:** SNVT 164 / The input variable "stValue.iMilliseconds" is outside the permitted range. The value was not sent.

**eLON\_164ePriority\_level\_Out\_of\_range:** SNVT 164 / The input variable "stValue.ePriority\_level" is outside the permitted range. The value was not sent.

**eLON\_164eAlarm\_type\_Out\_of\_range:** SNVT 164 / The input variable "stValue.eAlarm" is outside the permitted range. The value was not sent.

**eLON\_byType\_scope\_Out\_of\_range:** SNVT 166 / The input variable "stValue.byType\_scope" is outside the permitted range. The value was not sent.

**eLON\_uiType\_index\_Out\_of\_range:** SNVT 166 / The input variable "stValue.uiType\_index" is outside the permitted range. The value was not sent.

**eLON\_eType\_category\_Out\_of\_range:** SNVT 166 / The input variable "stValue.eType\_category" is outside the permitted range. The value was not sent.

**eLON\_byType\_length\_Out\_of\_range:** SNVT 166 / The input variable "stValue.byType" is outside the permitted range. The value was not sent.

**eLON\_eCmd\_fb\_Out\_of\_range:** SNVT 170 / The input variable "stValue.eCmd\_fb" is outside the permitted range. The value was not sent.

**eLON\_byManufacturer\_Out\_of\_range:** SNVT 172 / The input variable "stValue.byManufacturer" is outside the permitted range. The value was not sent.

**eLON\_eDevice\_select\_Out\_of\_range:** SNVT 175 / The input variable "stValue.eDevice\_select" is outside the permitted range. The value was not sent.

**eLON\_stPos\_eFunction\_Out\_of\_range:** SNVT 180 / The input variable "stValue.stPos\_eFunction" is outside the permitted range. The value was not sent.

**eLON\_stPos\_rSetting\_Out\_of\_range:** SNVT 180 / The input variable "stValue.stPos.rSetting" is outside the permitted range. The value was not sent.

**eLON\_stPos\_rRotation\_Out\_of\_range:** SNVT 180 / The input variable "stValue.stPos.rRotation" is outside the permitted range. The value was not sent.

**eLON\_eCmd\_source\_Out\_of\_range:** SNVT 180 / The input variable "stValue.eCmd\_source" is outside the permitted range. The value was not sent.

**eLON\_eError\_code\_Out\_of\_range:** SNVT 180 / The input variable "stValue.\_eError\_code" is outside the permitted range. The value was not sent.

**eLON\_181stAddr\_talk\_eAudio\_sensor\_type\_Out\_of\_range:** SNVT 181 / The input variable "stValue.stAddr\_talk.eAudio\_sensor" is outside the permitted range. The value was not sent.

**eLON\_181stAddr\_talk\_byCar\_id\_Out\_of\_range:** SNVT 181 / The input variable "stValue.stAddr\_talk.byCar\_id" is outside the permitted range. The value was not sent.

**eLON\_181stAddr\_talk\_byLocation\_Out\_of\_range:** SNVT 181 / The input variable "stValue.stAddr\_talk.byLocation" is outside the permitted range. The value was not sent.

**eLON\_181stAddr\_talk\_byUnit\_id\_Out\_of\_range:** SNVT 181 / The input variable "stValue.stAddr\_talk.byUnit" is outside the permitted range. The value was not sent.

**eLON\_181stAddr\_init\_eAudio\_sensor\_type\_Out\_of\_range:** SNVT 181 / The input variable "stValue.stAddr\_init.eAudio\_sensor\_type" is outside the permitted range. The value was not sent.

**eLON\_181stAddr\_init\_byCar\_id\_Out\_of\_range:** SNVT 181 / The input variable "stValue.stAddr\_init.byCar" is outside the permitted range. The value was not sent.

**eLON\_181stAddr\_init\_byLocation\_Out\_of\_range:** SNVT 181 / The input variable "stValue.stAddr\_init.byLocation" is outside the permitted range. The value was not sent.

**eLON\_181stAddr\_init\_byUnit\_id\_Out\_of\_range:** SNVT 181 / The input variable "stValue.stAddr\_init.byUnit" is outside the permitted range. The value was not sent.

**eLON\_181eAudio\_type\_Out\_of\_range:** SNVT 181 / The input variable "stValue.eAudio\_type" is outside the permitted range. The value was not sent.

**eLON\_181byAudio\_line\_Out\_of\_range:** SNVT 181 / The input variable "stValue.byAudio\_line" is outside the permitted range. The value was not sent.

**eLON\_181stAddr\_dest\_stP2p\_eAudio\_sensor\_type\_Out\_of\_range:** SNVT 181 / The input variable "stValue.stAddr\_dest.stP2p.eAudio\_sensor\_type" is outside the permitted range. The value was not sent.

**eLON\_181stAddr\_dest\_stP2p\_byCar\_id\_Out\_of\_range:** SNVT 181 / The input variable "stValue.stAddr\_dest.stP2p.byLocation" is outside the permitted range. The value was not sent.

**eLON\_181stAddr\_dest\_stP2p\_byLocation\_Out\_of\_range:** SNVT 181 / The input variable "stValue." is outside the permitted range. The value was not sent.

**eLON\_181stAddr\_dest\_stP2p\_byUnit\_id\_Out\_of\_range:** SNVT 181 / The input variable "stValue.stAddr\_dest.stP2p.byUnit\_id" is outside the permitted range. The value was not sent.

**eLON\_stAddr\_dest\_stP2p\_eAudio\_sensor\_type\_Out\_of\_range:** SNVT 182 / The input variable "stValue.stAddr\_dest.stP2p.eAudio\_sensor\_type" is outside the permitted range. The value was not sent.

**eLON\_stAddr\_dest\_stP2p\_byCar\_id\_Out\_of\_range:** SNVT 182 / The input variable "stValue.stAddr\_dest.stP2p.byCar" is outside the permitted range. The value was not sent.

**eLON\_stAddr\_dest\_stP2p\_byLocation\_Out\_of\_range:** SNVT 182 / The input variable "stValue.stAddr\_dest.stP2p.byLocation" is outside the permitted range. The value was not sent.

**eLON\_stAddr\_dest\_stP2p\_byUnit\_id\_Out\_of\_range:** SNVT 182 / The input variable "stValue.stAddr\_init.eAudio\_sensor\_type" is outside the permitted range. The value was not sent.

**eLON\_stAddr\_init\_eAudio\_sensor\_type\_Out\_of\_range:** SNNT 182 / The input variable "stValue.stAddr\_init.byCar\_id" is outside the permitted range. The value was not sent.

**eLON\_stAddr\_init\_byCar\_id\_Out\_of\_range:** SNVT 182 / The input variable "stValue." is outside the permitted range. The value was not sent.

**eLON\_stAddr\_init\_byLocation\_Out\_of\_range:** SNVT 182 / The input variable "stValue.stAddr\_init.byLocation" is outside the permitted range. The value was not sent.

**eLON\_stAddr\_init\_byUnit\_id\_Out\_of\_range:** SNVT 182 / The input variable "stValue.stAddr\_init.byUnit\_id" is outside the permitted range. The value was not sent.

**eLON\_eAudio\_type\_Out\_of\_range:** SNVT 182 / The input variable "stValue.eAudio\_type" is outside the permitted range. The value was not sent.

**eLON\_eCycle\_Out\_of\_range:** SNVT 184 / The input variable "stValue.eCycle" is outside the permitted range. The value was not sent.

**eLON\_eSubcycle\_Out\_of\_range:** SNVT 184 / The input variable "stValue.eSubcycle" is outside the permitted range. The value was not sent.

**eLON\_stFunction\_eProgram\_Out\_of\_range:** SNVT 184 / The input variable "stValue.stFunction.eProgram" is outside the permitted range. The value was not sent.

**eLON\_stFunction\_stWash\_eLoad\_level\_Out\_of\_range:** SNVT 184 / The input variable "stValue.stFunction.stWash\_eLoad\_level" is outside the permitted range. The value was not sent.

**eLON\_stFunction\_stWash\_ePrewash\_Out\_of\_range:** SNVT 184 / The input variable "stValue.stFunction.stWash.ePrewash" is outside the permitted range. The value was not sent.

**eLON\_stFunction\_stRinse\_eOption\_Out\_of\_range:** SNVT 184 / The input variable "stValue.stFunction.stRinse.eOption" is outside the permitted range. The value was not sent.

**eLON\_stFunction\_stRinse\_byRepeat\_Out\_of\_range:** SNVT 184 / The input variable "stValue.stFunction.stRinse.byRepeat" is outside the permitted range. The value was not sent.

**eLON\_stFunction\_stSpin\_eHold\_Out\_of\_range:** SNVT 184 / The input variable "stValue.stFunction.stSpin.eHold" is outside the permitted range. The value was not sent.

**eLON\_stFunction\_stDry\_byTemp\_Out\_of\_range:** SNVT 184 / The input variable "stValue.stFunction.stDry.byTemp" is outside the permitted range. The value was not sent.

**eLON\_stFunction\_stDry\_stDuration\_eDryness\_Out\_of\_range:** SNVT 184 / The input variable "stValue.stFunction.stDry.stDuration.eDryness" is outside the permitted range. The value was not sent.

**eLON\_186eCycle\_Out\_of\_range:** SNVT 186 / The input variable "stValue.eCycle" is outside the permitted range. The value was not sent.

**eLON\_186eSubcycle\_Out\_of\_range:** SNVT 186 / The input variable "stValue.eSubcycle" is outside the permitted range. The value was not sent.

**eLON\_stWasher\_command\_data\_eCycle\_Out\_of\_range:** SNVT 186 / The input variable "stValue.stWasher\_command\_data.eCycle" is outside the permitted range. The value was not sent.

**eLON\_stWasher\_command\_data\_eSubcycle\_Out\_of\_range:** SNVT 186 / The input variable "stValue.stWasher\_command\_data.eSubcycle" is outside the permitted range. The value was not sent.

**eLON\_stWasher\_command\_data\_stFunction\_eProgram\_Out\_of\_range:** SNVT 186 / The input variable "stValue.stWasher\_command\_data.stFunction.eProgram" is outside the permitted range. The value was not sent.

**eLON\_stWasher\_command\_data\_stFunction\_stWash\_eLoad\_level\_Out\_of\_range:** SNVT 186 / The input variable "stValue.stWasher\_command\_data.stFunction.stWash.eLoad" is outside the permitted range. The value was not sent.

**eLON\_stWasher\_command\_data\_stFunction\_stWash\_ePrewash\_Out\_of\_range:**  SNVT 186 / The input variable "stValue.stWasher\_command\_data.stFunction.stWash.ePrewash" is outside the permitted range. The value was not sent.

**eLON\_stWasher\_command\_data\_stFunction\_stRinse\_eOption\_Out\_of\_range:** SNVT 186 / The input variable "stValue.stWasher\_command\_data.stFunction.stRinse.eOption" is outside the permitted range. The value was not sent.

**eLON\_stWasher\_command\_data\_stFunction\_stRinse\_byRepeat\_Out\_of\_range:** SNVT 186 / The input variable "stValue.stWasher\_command\_data.stFunction.stRinse.byRepeat" is outside the permitted range. The value was not sent.

**eLON\_stWasher\_command\_data\_stFunction\_stSpin\_eHold\_Out\_of\_range:** SNVT 186 / The input variable "stValue.stWasher\_command\_data.stFunction.stSpin.eHold" is outside the permitted range. The value was not sent.

**eLON\_stWasher\_command\_data\_stFunction\_stDry\_byTemp\_Out\_of\_range:** SNVT 186 / The input variable "stValue.stWasher\_command\_data.stFunction.stDry.byTemp" is outside the permitted range. The value was not sent.

**eLON\_stWasher\_command\_data\_stFunction\_stDry\_stDuration\_eDryness\_Out\_of\_range:** SNVT 186 / The input variable "stValue.stWasher\_command\_data.stFunction.stDry.stDuration.eDryness" is outside the permitted range. The value was not sent.

**eLON\_eState\_Out\_of\_range:** SNVT 189 / The input variable "stValue.eState" is outside the permitted range. The value was not sent.

**eLON\_stSetting\_rValue\_Out\_of\_range:** SNVT 189 / The input variable "stValue.stSettings.rValue" is outside the permitted range. The value was not sent.

**eLON\_stSetting\_rChange\_Out\_of\_range:** SNVT 189 / The input variable "stValue.stSettings.rChange" is outside the permitted range. The value was not sent.

**eLON\_stSetting\_rMultiplier\_Out\_of\_range:** SNVT 189 / The input variable "stValue.stSettings.rMultiplier" is outside the permitted range. The value was not sent.

**eLON\_stSetting\_iAngle\_Out\_of\_range:** SNVT 189 / The input variable "stValue.stSettings.iAngle" is outside the permitted range. The value was not sent.

**eLON\_stSetting\_byGroup\_number\_Out\_of\_range:** SNVT 189 / The input variable "stValue.stSettings.byGroup\_number" is outside the permitted range. The value was not sent.

**eLON\_stSetting\_siFan\_level\_Out\_of\_range:** SNVT 189 / The input variable "stValue.stSettings.siFan\_level" is outside the permitted range. The value was not sent.

**eLON\_stColor\_value\_stCIE1931\_lumen\_rX\_Out\_of\_range:** SNVT 190 / The input variable "stValue.stColor\_value.stCIE1931\_lumen.rX" is outside the permitted range. The value was not sent.

**eLON\_stColor\_value\_stCIE1931\_lumen\_rY\_Out\_of\_range:** SNVT 190 / The input variable "stValue.stColor\_value.stCIE1931\_lumen.rY" is outside the permitted range. The value was not sent.

**eLON\_stColor\_value\_stCIE1931\_lumen\_udiAbsolute\_Y\_Out\_of\_range:** SNVT 190 / The input variable "stValue.stColor\_value.stCIE1931\_lumen.udiAbsolute\_Y" is outside the permitted range. The value was not sent.

**eLON\_stColor\_value\_stCIE1931\_percent\_rX\_Out\_of\_range:** SNVT 190 / The input variable "stValue.stColor\_value.stCIE1931\_percent.rX" is outside the permitted range. The value was not sent.

**eLON\_stColor\_value\_stCIE1931\_percent\_rY\_Out\_of\_range:** SNVT 190 / The input variable "stValue.stColor\_value.stCIE1931\_percent.rY" is outside the permitted range. The value was not sent.

**eLON\_stColor\_value\_stCIE1931\_percent\_rPercent\_Y\_Out\_of\_range:** SNVT 190 / The input variable "stValue.stColor\_value.stCIE1931\_percent.rPercent\_Y" is outside the permitted range. The value was not sent.

**eLON\_stColor\_value\_uiColor\_temperature\_Out\_of\_range:** SNVT 190 / The input variable "stValue.stColor\_value.uiColor\_temperature" is outside the permitted range. The value was not sent.

**eLON\_191eStatus\_Out\_of\_range:** SNVT 191 / The input variable "stValue.Status" is outside the permitted range. The value was not sent.

**eLON\_uiLog\_number\_Out\_of\_range:** SNVT 191 / The input variable "stValue.uiLog\_number" is outside the permitted range. The value was not sent.

**eLON\_rLevel\_Out\_of\_range:** SNVT 191 / The input variable "stValue.rLevel" is outside the permitted range. The value was not sent.

**eLON\_stCurrent\_notify\_time\_rHundredths\_Out\_of\_range:** SNVT 191 / The input variable "stValue.stCurrent\_notify\_time.rHundredths" is outside the permitted range. The value was not sent.

**eLON\_stPrevious\_notify\_time\_rHundredths\_Out\_of\_range:** SNVT 191 / The input variable "stValue.stPrevious\_notify\_time.rHundredths" is outside the permitted range. The value was not sent.

**eLON\_rHundredths\_Out\_of\_range:** SNVT 192 / The input variable "stValue.rHundredths" is outside the permitted range. The value was not sent.

**eLON\_stStart\_time\_rHundredths\_Out\_of\_range:** SNVT 193 / The input variable "stValue.stStart\_time.rHundredths" is outside the permitted range. The value was not sent.

**eLON\_stEnd\_time\_rHundredths\_Out\_of\_range:** SNVT 193 / The input variable "stValue.stEnd\_time.rHundredths" is outside the permitted range. The value was not sent.

**eLON\_rComplete\_Out\_of\_range:** SNVT 194 / The input variable "stValue.rComplete" is outside the permitted range. The value was not sent.

**eLON\_stTime\_actual\_rHundredths\_Out\_of\_range:** SNVT 199 / The input variable "stValue.stTime\_actual.rHundredths" is outside the permitted range. The value was not sent.

**eLON\_stTime\_previous\_rHundredths\_Out\_of\_range:** SNVT 199 / The input variable "stValue.stTime\_previous.rHundredths" is outside the permitted range. The value was not sent.

**eLON\_lrEnergy\_Out\_of\_range:** SNVT 200 / The input variable "stValue.lrEnergy" is outside the permitted range. The value was not sent.

**eLON\_rPowerFactor\_Out\_of\_range:** SNVT 200 / The input variable "stValue.rPowerFactor" is outside the permitted range. The value was not sent.

**eLON\_rPower\_Out\_of\_range:** SNVT 200 / The input variable "stValue.rPower" is outside the permitted range. The value was not sent.

**eLON\_rBallastTemp\_Out\_of\_range:** SNVT 200 / The input variable "stValue.rBallastTemp" is outside the permitted range. The value was not sent.

**eLON\_lrLongitude\_Out\_of\_range:** SNVT 201 / The input variable "stValue.lrLongitude" is outside the permitted range. The value was not sent.

**eLON\_lrLatitude\_Out\_of\_range:** SNVT 201 / The input variable "stValue.lrLatitude" is outside the permitted range. The value was not sent.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
