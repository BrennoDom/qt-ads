# E_LON_telcom_states_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_telcom\_states\_t

Used by: SNVT\_telcom

```
TYPE E_LON_telcom_states_t :  
(  
  eLON_TEL_NUL       := -1,  
  eLON_TEL_NOTINUSE  := 0,  
  eLON_TEL_OFFHOOK   := 1,  
  eLON_TEL_DIALING   := 2,  
  eLON_TEL_DIALCOMP  := 3,  
  eLON_TEL_RINGBACK  := 4,  
  eLON_TEL_INCOMING  := 5,  
  eLON_TEL_RINGING   := 6,  
  eLON_TEL_ANSWERED  := 7,  
  eLON_TEL_CONNECTED := 8,  
  eLON_TEL_TALKING   := 9,  
  eLON_TEL_HANGINGUP := 10,  
  eLON_TEL_HUNGUPX   := 11,  
  eLON_TEL_HOLD      := 12,  
  eLON_TEL_UNHOLD    := 13,  
  eLON_TEL_RELEASE   := 14,  
  eLON_TEL_FULLDUP   := 15,  
  eLON_TEL_BLOCKED   := 16,  
  eLON_TEL_CWAIT     := 17,  
  eLON_TEL_DESTBUSY  := 18,  
  eLON_TEL_NETBUSY   := 19,  
  eLON_TEL_ERROR     := 20  
)  
END_TYPE
```

**eLON\_TEL\_NUL:**  Invalid Value

**eLON\_TEL\_NOTINUSE:**  "Null State (U0)" not in use

**eLON\_TEL\_OFFHOOK:**  "Call Initiated (U1)"

**eLON\_TEL\_DIALING:**  "Overlap Sending (U2)"

**eLON\_TEL\_DIALCOMP:**  "Outgoing Call Proceeding (U3)"

**eLON\_TEL\_RINGBACK:**  "Call Delivered (U4)" hearing ringback

**eLON\_TEL\_INCOMING:**  "Call Present (U6)" incoming call has not yet started ringing (only on ISDN line)

**eLON\_TEL\_RINGING:**  "Call Received (U7)" incoming call when the user has indicated alerting but has not yet answered

**eLON\_TEL\_ANSWERED:**  "Connect Request (U8)" user has answered the call and is waiting to be awarded the call

**eLON\_TEL\_CONNECTED:**

**eLON\_TEL\_TALKING:**  "Active (U10)" two parties are exchanging data

**eLON\_TEL\_HANGINGUP:**  "Disconnect Request (U11)" user has hung up

**eLON\_TEL\_HUNGUPX:**  "Disconnect Indication (U12)" the other side hung up

**eLON\_TEL\_HOLD:**  "Suspend Request (U15)" user has requested the network suspend the call

**eLON\_TEL\_UNHOLD:**  "Resume Request (U17)" resume a held call (usually go back to TEL\_TALKING)

**eLON\_TEL\_RELEASE:**  "Release Request (U19)" user has requested the network to release

**eLON\_TEL\_FULLDUP:**  "Overlap Receiving (U25)" user has acknowledged the call and is prepared to receive additional

**eLON\_TEL\_BLOCKED:**  connection with blocking, (call-waiting disabled)

**eLON\_TEL\_CWAIT:**  call-waiting coming in

**eLON\_TEL\_DESTBUSY:**  destination busy

**eLON\_TEL\_NETBUSY:**  problem, network

**eLON\_TEL\_ERROR:**  problem, non-network

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
