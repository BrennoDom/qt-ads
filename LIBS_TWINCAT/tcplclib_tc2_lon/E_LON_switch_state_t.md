# E_LON_switch_state_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_switch\_state\_t

Used by: SNVT\_switch\_2

```
TYPE E_LON_switch_state_t :  
(  
  eLON_SW_NUL                  := -1,  
  eLON_SW_SET_OFF              := 0,  
  eLON_SW_SET_ON               := 1,  
  eLON_SW_REPORT_OFF           := 2,  
  eLON_SW_REPORT_ON            := 3,  
  eLON_SW_TOGGLE_STATE         := 4,  
  eLON_SW_SET_LEVEL            := 5,  
  eLON_SW_INCREASE_LEVEL       := 6,  
  eLON_SW_DECREASE_LEVEL       := 7,  
  eLON_SW_RECALL_SCENE         := 8,  
  eLON_SW_STORE_SCENE          := 9,  
  eLON_SW_LEARN_SCENE          := 10,  
  eLON_SW_SET_OCCUPIED         := 11,  
  eLON_SW_SET_UNOCCUPIED       := 12,  
  eLON_SW_SET_MULTIPLIER       := 13,  
  eLON_SW_ENABLE_GROUP         := 14,  
  eLON_SW_DISABLE_GROUP        := 15,  
  eLON_SW_WINK                 := 16,  
  eLON_SW_RESET                := 17,  
  eLON_SW_RESET_ENERGY_USAGE   := 18,  
  eLON_SW_RESET_RUNTIME        := 19,  
  eLON_SW_INCREASE_HUE         := 20,  
  eLON_SW_DECREASE_HUE         := 21,  
  eLON_SW_SET_BUTTON           := 22,  
  eLON_SW_SET_FAN_UP           := 32,  
  eLON_SW_SET_FAN_DOWN         := 33,  
  eLON_SW_TOGGLE_FAN_DIRECTION := 34,  
  eLON_SW_INCREASE_FAN_LEVEL   := 35,  
  eLON_SW_DECREASE_FAN_LEVEL   := 36,  
  eLON_SW_SET_FAN_ON           := 37,  
  eLON_SW_SET_FAN_OFF          := 38,  
  eLON_SW_TOGGLE_FAN_STATE     := 39,  
  eLON_SW_MOVE_OPEN            := 48,  
  eLON_SW_MOVE_CLOSED          := 49,  
  eLON_SW_SET_ANGLE            := 50,  
  eLON_SW_ROTATE_OPEN          := 51,  
  eLON_SW_ROTATE_CLOSED        := 52,  
  eLON_SW_STOP                 := 53,  
  eLON_SW_SET_STANDBY          := 54,  
  eLON_SW_TOGGLE_STANDBY       := 55,  
  eLON_SW_SET_POSITION         := 56,  
  eLON_SW_REPORT_POSITION      := 57,  
  eLON_SW_REPORT_FAN_LEVEL     := 58  
)  
END_TYPE
```

**eLON\_SW\_NUL:**  Invalid value

**eLON\_SW\_SET\_OFF:**  Set the state to off; ignored for blinds, drapes, shades, and fans

**eLON\_SW\_SET\_ON:**  Set the state to on; ignored for blinds, drapes, shades, and fans

**eLON\_SW\_REPORT\_OFF:**  Report that the state is off; output only; ignored for input

**eLON\_SW\_REPORT\_ON:**  Report that the state is on; output only; ignored for input

**eLON\_SW\_TOGGLE\_STATE:**  Toggle on-off state; same action as SW\_SET\_OFF if the on/off state was on, and SW\_SET\_ON if the on/off state was off; ignored for blinds, drapes, shades, and fans

**eLON\_SW\_SET\_LEVEL:**  Set the level to the specified value; ignored for blinds, drapes, shades, and fans

**eLON\_SW\_INCREASE\_LEVEL:**  Increase the level by the specified value; ignored for blinds, drapes, shades, and fans

**eLON\_SW\_DECREASE\_LEVEL:**  Decrease the level by the specified amount; ignored for blinds, drapes, shades, and fans

**eLON\_SW\_RECALL\_SCENE:**  Recall the state and level from the specified scene

**eLON\_SW\_STORE\_SCENE:**  Store setting for the specified scene

**eLON\_SW\_LEARN\_SCENE:**  Learn setting for the specified scene

**eLON\_SW\_SET\_OCCUPIED:**  Set the occupancy state

**eLON\_SW\_SET\_UNOCCUPIED:**  Clear the occupancy state

**eLON\_SW\_SET\_MULTIPLIER:**  Set a multiplier for the level for 60 minutes; ignored for blinds, drapes, shades, and fans

**eLON\_SW\_ENABLE\_GROUP:**  Enable a group; all groups are enabled by default

**eLON\_SW\_DISABLE\_GROUP:**  Disable a group

**eLON\_SW\_WINK:**  Blink state (toggle on-off state; pause; toggle on-off state again

**eLON\_SW\_RESET:**  Reset scene definitions, multiplier, occupancy state, group enable flags, and settings to factory defaults

**eLON\_SW\_RESET\_ENERGY\_USAGE:**  Reset energy usage value to zero

**eLON\_SW\_RESET\_RUNTIME:**  Reset runtime value to zero

**eLON\_SW\_INCREASE\_HUE:**  Increase color hue

**eLON\_SW\_DECREASE\_HUE:**  Decrease color hue

**eLON\_SW\_SET\_BUTTON:**  Trigger the actions for pressing and releasing the button specified in the value field

**eLON\_SW\_SET\_FAN\_UP:**  Set ceiling fan direction to up, with specified level

**eLON\_SW\_SET\_FAN\_DOWN:**  Set ceiling fan direction to down, with specified level

**eLON\_SW\_TOGGLE\_FAN\_DIRECTION:**  Toggle fan up-down direction

**eLON\_SW\_INCREASE\_FAN\_LEVEL:**  Increase fan speed by the setting

**eLON\_SW\_DECREASE\_FAN\_LEVEL:**  Decrease fan speed by the setting

**eLON\_SW\_SET\_FAN\_ON:**  Set the fan state to on

**eLON\_SW\_SET\_FAN\_OFF:**  Set the fan state to off

**eLON\_SW\_TOGGLE\_FAN\_STATE:**  Toggle the fan on-off state

**eLON\_SW\_MOVE\_OPEN:**  Move blinds, drapes, or shades open by the setting

**eLON\_SW\_MOVE\_CLOSED:**  Move blinds, drapes, or shades closed by the setting

**eLON\_SW\_SET\_ANGLE:**  Set the rotation angle of blinds to the setting

**eLON\_SW\_ROTATE\_OPEN:**  Rotate blinds open by the setting

**eLON\_SW\_ROTATE\_CLOSED:**  Rotate blinds closed by the setting

**eLON\_SW\_STOP:**  Stop any motion of blinds, drapes, or shades

**eLON\_SW\_SET\_STANDBY:**  Set Standby mode

**eLON\_SW\_TOGGLE\_STANDBY:**  Toggle the standby state

**eLON\_SW\_SET\_POSITION:**  Set blinds, drapes, or shades to the specified position; 100% is fully open, 0% is fully closed

**eLON\_SW\_REPORT\_POSITION:**  Report the position of blinds, drapes, or shades output only; ignored for input

**eLON\_SW\_REPORT\_FAN\_LEVEL:**  Report the fan speed in percent of full level output only; ignored for input

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
