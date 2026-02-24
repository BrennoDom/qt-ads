# ST_LON_SNVT_obj_status

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_obj\_status

Used by: SNVT\_obj\_status

```
TYPE ST_LON_SNVT_obj_status :  
STRUCT  
  uiObject_id            : UINT;  
  bInvalid_id            : BOOL;  
  bInvalid_request       : BOOL;  
  bDisabled              : BOOL;  
  bOut_of_limits         : BOOL;  
  bOpen_circuit          : BOOL;  
  bOut_of_service        : BOOL;  
  bMechanical_fault      : BOOL;  
  bFeedback_failure      : BOOL;  
  bOver_range            : BOOL;  
  bUnder_range           : BOOL;  
  bElectrical_fault      : BOOL;  
  bUnable_to_measure     : BOOL;  
  bComm_failure          : BOOL;  
  bFail_self_test        : BOOL;  
  bSelf_test_in_progress : BOOL;  
  bLocked_out            : BOOL;  
  bManual_control        : BOOL;  
  bIn_alarm              : BOOL;  
  bIn_override           : BOOL;  
  bReport_mask           : BOOL;  
  bProgramming_mode      : BOOL;  
  bProgramming_fail      : BOOL;  
  bAlarm_notify_disabled : BOOL;  
  bReset_complete        : BOOL;  
  byReserved2            : BYTE;  
END_STRUCT  
END_TYPE
```

**uiObject\_id:** Min: 0 / Max: 65535 / Object ID (object index).

**bInvalid\_id:** Invalid-ID flag (boolean).

**bInvalid\_request:** Invalid-request flag (boolean).

**bDisabled:** Disabled flag (boolean).

**bOut\_of\_limits:** Out-of-limits flag (boolean).

**bOpen\_circuit:** Open-circuit flag (boolean).

**bOut\_of\_service:** Out-of-service flag (boolean).

**bMechanical\_fault:** Mechanical-fault flag (boolean).

**bFeedback\_failure:** Feedback-failure flag (boolean).

**bOver\_range:** Over-range flag (boolean).

**bUnder\_range:** Under-range flag (boolean).

**bElectrical\_fault:** Electrical-fault flag (boolean).

**bUnable\_to\_measure:** Unable-to-measure flag (boolean).

**bComm\_failure:** Communications-failure flag (boolean).

**bFail\_self\_test:** Failed-self-test flag (boolean).

**bSelf\_test\_in\_progress:** Self-test-in-progress flag (boolean).

**bLocked\_out:** Locked-out flag (boolean).

**bManual\_control:** Manual-control flag (boolean).

**bIn\_alarm:** Input-alarm flag (boolean).

**bIn\_override:** Input-override flag (boolean).

**bReport\_mask:** Report-mask flag (boolean).

**bProgramming\_mode:** Programming-mode flag (boolean).

**bProgramming\_fail:** Programming-fail flag (boolean).

**bAlarm\_notify\_disabled:** Alarm-notify-disabled flag (boolean).

**bReset\_complete:** Reset (boolean).

**byReserved2:** This field is reserved.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
