# FB_SEND_093_SNVT_obj_status

## Library
tcplclib_tc2_lon

## Category
Motion Control

# FB\_SEND\_093\_SNVT\_obj\_status

![44497505](/tcplclib_tc2_lon/1033/Images/gif/151384971__en-US__Web.gif)

This function block sends the following LON output variable (nvo):

**SNVT Name:** SNVT\_obj\_status.

**SNVT number:** 093.

**Description:** Object status (ID, status (4 byte)).

## VAR\_INPUT

```
wNVIndex     : WORD;  
stValue      : ST_LON_SNVT_obj_status;  
bStart       : BOOL;  
bSendInit    : BOOL := bSendInitDefault;  
bAuto        : BOOL := bAutoDefault;  
tMinSendTime : TIME := tMinSendTimeDefault;  
tMaxSendTime : TIME := tMaxSendTimeDefault;  
bDisabled    : BOOL := FALSE;
```

**wNVIndex:** Unique index. This index is required for binding the LON nodes. A maximum of 62 SNVTs are permitted per terminal (KL6401). Values between 0 and 61 are possible.

**stValue. uiObject\_id:** Min: 0 / Max: 65535 / Object ID (object index).

**stValue. bInvalid\_id:** Invalid-ID flag (boolean).

**stValue. bInvalid\_request:** Invalid-request flag (boolean).

**stValue. bDisabled:** Disabled flag (boolean).

**stValue. bOut\_of\_limits:** Out-of-limits flag (boolean).

**stValue. bOpen\_circuit:** Open-circuit flag (boolean).

**stValue. bOut\_of\_service:** Out-of-service flag (boolean).

**stValue. bMechanical\_fault:** Mechanical-fault flag (boolean).

**stValue. bFeedback\_failure:** Feedback-failure flag (boolean).

**stValue. bOver\_range:** Over-range flag (boolean).

**stValue. bUnder\_range:** Under-range flag (boolean).

**stValue. bElectrical\_fault:** Electrical-fault flag (boolean).

**stValue. bUnable\_to\_measure:** Unable-to-measure flag (boolean).

**stValue. bComm\_failure:** Communications-failure flag (boolean).

**stValue. bFail\_self\_test:** Failed-self-test flag (boolean).

**stValue. bSelf\_test\_in\_progress:** Self-test-in-progress flag (boolean).

**stValue. bLocked\_out:** Locked-out flag (boolean).

**stValue. bManual\_control:** Manual-control flag (boolean).

**stValue. bIn\_alarm:** Input-alarm flag (boolean).

**stValue. bIn\_override:** Input-override flag (boolean).

**stValue. bReport\_mask:** Report-mask flag (boolean).

**stValue. bProgramming\_mode:** Programming-mode flag (boolean).

**stValue. bProgramming\_fail:** Programming-fail flag (boolean).

**stValue. bAlarm\_notify\_disabled:** Alarm-notify-disabled flag (boolean).

**stValue. bReset\_complete:** Reset (boolean).

**stValue. byReserved2:** This field is reserved.

**bStart:** The function block starts sending when these variables have a positive edge (irrespective of "bAuto").

**bSendInit:** The function block automatically sends its values once after a PLC restart.

**bAuto:** [Automatic sending](ms-xhelp:///?Id=beckhoff-83d9-4e0f-87b8-3129214c5d3f) is selected when a value changes or the time "tMaxSendTime" has elapsed (polling).

**tMinSendTime:** Parameter for [automatic sending](ms-xhelp:///?Id=beckhoff-83d9-4e0f-87b8-3129214c5d3f). A new value is only sent once a minimum time has elapsed. This prevents continuous sending.

**tMaxSendTime:** Parameter for [automatic sending](ms-xhelp:///?Id=beckhoff-83d9-4e0f-87b8-3129214c5d3f). The value is sent when this time has elapsed, even if the minimum change in value (ValueLimit) was not reached (polling). The value 0 disables this function.

**bDisabled:** TRUE = deselection of the block

**wNVIndex:** Unique index. This index is required for binding the LON nodes. A maximum of 62 SNVTs are permitted per LON terminal. Values between 0 and 61 are possible.

**stValue:** Structure of the data to be sent (see [ST\_LON\_SNVT\_obj\_status](ms-xhelp:///?Id=beckhoff-f7e3-4050-a11a-9c377f7c725c)).

**bStart:** A positive edge starts the send process (irrespective of *bAuto*).

**bSendInit:** Automatically sends the value once when the PLC restarts.

**bAuto:** [Automatic sending](ms-xhelp:///?Id=beckhoff-83d9-4e0f-87b8-3129214c5d3f) is selected when a value changes or the time *tMaxSendTime* has elapsed (polling).

**tMinSendTime:** Parameter for [automatic sending](ms-xhelp:///?Id=beckhoff-83d9-4e0f-87b8-3129214c5d3f). A new value is sent when this time has elapsed at the earliest, to prevent continuous sending.

**tMaxSendTime:** Parameter for [automatic sending](ms-xhelp:///?Id=beckhoff-83d9-4e0f-87b8-3129214c5d3f). The value is sent after this time has elapsed at the latest. The value 0 disables this function.

**bDisabled:** TRUE = deselection of the block.

## VAR\_OUTPUT

```
bBusy     : BOOL;  
bError    : BOOL;  
eError    : E_LON_ERROR;  
dwErrorKL : DWORD;
```

**bBusy:** The *bBusy* output is TRUE as long as values are sent.

**bError:** This output goes TRUE as soon as an error occurs. This error is described via the variable *eError*.

**eError:** This output outputs an error code in the event of an error (see [E\_LON\_ERROR](ms-xhelp:///?Id=beckhoff-ad05-4d5c-a4ac-eed1f05a18f2)). bError goes TRUE at the same time.

**dwErrorKL:** Error ID of the function block [FB\_LON\_KL6401](ms-xhelp:///?Id=beckhoff-cce2-44f9-8642-d620dc9ab975)() (see [dwErrorKL](ms-xhelp:///?Id=beckhoff-7966-45a6-ae22-1bf539925dd5)). In this case the variable *eError* has the value eKL6401\_Error. bError goes TRUE at the same time.

## VAR\_IN\_OUT

```
stLON_Com : ST_LON_Communication;
```

**stLON\_Com :** This structure is used to link [FB\_LON\_KL6401()](ms-xhelp:///?Id=beckhoff-cce2-44f9-8642-d620dc9ab975) with the send/receive function (see [ST\_LON\_Communication](ms-xhelp:///?Id=beckhoff-2ad7-4b6a-944d-a82a3e3847ef)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
