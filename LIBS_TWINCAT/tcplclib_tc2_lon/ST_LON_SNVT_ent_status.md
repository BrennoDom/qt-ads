# ST_LON_SNVT_ent_status

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_ent\_status

Used by: SNVT\_ent\_status

```
TYPE ST_LON_SNVT_ent_status :  
STRUCT  
  bUnlocked        : BOOL;  
  bLocked          : BOOL;  
  bSecurity_locked : BOOL;  
  bClosed          : BOOL;  
  bOpen            : BOOL;  
  bIn_alarm        : BOOL;  
  bIn_error_cond   : BOOL;  
  bOpen_pre_alarm  : BOOL;  
  bOpen_alarm      : BOOL;  
  bService_alarm   : BOOL;  
  bTamper          : BOOL;  
  bEntry_req       : BOOL;  
  bExit_req        : BOOL;  
  bKey_req         : BOOL;  
  bSafety_ext_req  : BOOL;  
  bEmergency_req   : BOOL;  
  bUnable_lock     : BOOL;  
  bUnable_unlock   : BOOL;  
  bStuck           : BOOL;  
  bForced_open     : BOOL;  
  bForced_close    : BOOL;  
  bOpening         : BOOL;  
  bClosing         : BOOL;  
  bMoving          : BOOL;  
  bStopped         : BOOL;  
  bSafety_alarm    : BOOL;  
  bUnknown_state   : BOOL;  
  eCmd_fb          : E_LON_ent_opmode_cmd_t;  
END_STRUCT  
END_TYPE
```

**bUnlocked:** Unlocked device (boolean). Device is in unlocked position.

**bLocked:** Locked device (boolean). Device is in locked position.

**bSecurity\_locked:** Security locked (boolean). Device is in a security-driven locked position.

**bClosed:** Closed device (boolean). Device is in a closed position.

**bOpen:** Open device (boolean). Device is in an open position.

**bIn\_alarm:** In alarm state (boolean). The device is in the alarm state.

**bIn\_error\_cond:** In error condition (boolean). Device has an error condition.

**bOpen\_pre\_alarm:** Open device, pre-alarm (boolean). Device is open, and in warning state.

**bOpen\_alarm:** Open Device, alarm state (boolean). Device is open, and in not-closed alarm state.

**bService\_alarm:** Service alarm (boolean). Device needs service.

**bTamper:** Tamper mode (boolean). Device has detected tamper.

**bEntry\_req:** Entry request pending (boolean). Device has a pending entry request.

**bExit\_req:** Exit request pending (boolean). Device has a pending exit request.

**bKey\_req:** Key request pending (boolean). Device has a pending key request.

**bSafety\_ext\_req:** Safety-exit request pending (boolean). Device has a pending safety-exit request.

**bEmergency\_req:** Emergency-exit request pending (boolean). Device has a pending emergency-exit request.

**bUnable\_lock:** Unable to lock (boolean). Device is unable to close and/or lock.

**bUnable\_unlock:** Unable to unlock (boolean). Device is unable to open and/or unlock.

**bStuck:** Device is stuck (boolean). Device is unable to move.

**bForced\_open:** Forced-open Device (boolean). Device is/was forced to go to an open position.

**bForced\_close:** Forced-closed Device (boolean). Device is/was forced to go to a closed position.

**bOpening:** Device is opening (boolean). Device is currently opening from a closed position.

**bClosing:** Device is closing (boolean). Device is currently closing from an open position.

**bMoving:** Device is in motion (boolean). Device is currently changing position.

**bStopped:** Device Stopped (boolean). The device is stopped and can be moved manually.

**bSafety\_alarm:** Safety-alarm (boolean). Device is in a safety-alarm state.

**bUnknown\_state:** Unknown state (boolean). The state of the device is currently unknown.

**eCmd\_fb:** Command feedback (entry command names) (see [E\_LON\_ent\_opmode\_cmd\_t](ms-xhelp:///?Id=beckhoff-1293-4757-9c4e-7b2d4f72cd9a)). Feedback of requested-operation-mode of device.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
