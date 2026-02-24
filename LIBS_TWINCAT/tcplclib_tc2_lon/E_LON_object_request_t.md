# E_LON_object_request_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_object\_request\_t

Used by: SNVT\_obj\_request

```
TYPE E_LON_object_request_t :  
(  
 eLON_RQ_NUL                   := -1,  
 eLON_RQ_NORMAL                := 0,  
 eLON_RQ_DISABLED              := 1,  
 eLON_RQ_UPDATE_STATUS         := 2,  
 eLON_RQ_SELF_TEST             := 3,  
 eLON_RQ_UPDATE_ALARM          := 4,  
 eLON_RQ_REPORT_MASK           := 5,  
 eLON_RQ_OVERRIDE              := 6,  
 eLON_RQ_ENABLE                := 7,  
 eLON_RQ_RMV_OVERRIDE          := 8,  
 eLON_RQ_CLEAR_STATUS          := 9,  
 eLON_RQ_CLEAR_ALARM           := 10,  
 eLON_RQ_ALARM_NOTIFY_ENABLED  := 11,  
 eLON_RQ_ALARM_NOTIFY_DISABLED := 12,  
 eLON_RQ_MANUAL_CTRL           := 13,  
 eLON_RQ_REMOTE_CTRL           := 14,  
 eLON_RQ_PROGRAM               := 15,  
 eLON_RQ_CLEAR_RESET           := 16,  
 eLON_RQ_RESET                 := 17,  
 eLON_RQ_CLEAR_LOG             := 18  
)  
END_TYPE
```

**eLON\_RQ\_NUL:**  Invalid Value

**eLON\_RQ\_NORMAL:**  Enable object and remove override

**eLON\_RQ\_DISABLED:**  Disable object

**eLON\_RQ\_UPDATE\_STATUS:**  Report object status

**eLON\_RQ\_SELF\_TEST:**  Perform object self-test

**eLON\_RQ\_UPDATE\_ALARM:**  Update alarm status

**eLON\_RQ\_REPORT\_MASK:**  Report status bit mask

**eLON\_RQ\_OVERRIDE:**  Override object

**eLON\_RQ\_ENABLE:**  Enable object

**eLON\_RQ\_RMV\_OVERRIDE:**  Remove object override

**eLON\_RQ\_CLEAR\_STATUS:**  Clear object status

**eLON\_RQ\_CLEAR\_ALARM:**  Clear object alarm

**eLON\_RQ\_ALARM\_NOTIFY\_ENABLED:**  Enable alarm notification

**eLON\_RQ\_ALARM\_NOTIFY\_DISABLED:**  Disable alarm notification

**eLON\_RQ\_MANUAL\_CTRL:**  Enable object for manual control

**eLON\_RQ\_REMOTE\_CTRL:**  Enable object for remote control

**eLON\_RQ\_PROGRAM:**  Enable programming of special configuration properties

**eLON\_RQ\_CLEAR\_RESET:**  Clear reset-complete flag (reset\_complete)

**eLON\_RQ\_RESET:**  Execute reset-sequence of object

**eLON\_RQ\_CLEAR\_LOG:**  Clear data log

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
