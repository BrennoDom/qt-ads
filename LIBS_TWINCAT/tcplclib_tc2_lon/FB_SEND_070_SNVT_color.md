# FB_SEND_070_SNVT_color

## Library
tcplclib_tc2_lon

## Category
Motion Control

# FB\_SEND\_070\_SNVT\_color

![20077469](/tcplclib_tc2_lon/1033/Images/gif/151314571__en-US__Web.gif)

This function block sends the following LON output variable (nvo):

**SNVT Name:** SNVT\_color.

**SNVT number:** 070.

**Description:** Color according to CIE standard (L\*,a\*,b).

## VAR\_INPUT

```
wNVIndex     : WORD;  
stValue      : ST_LON_SNVT_color;  
bStart       : BOOL;  
bSendInit    : BOOL := bSendInitDefault;  
bAuto        : BOOL := bAutoDefault;  
tMinSendTime : TIME := tMinSendTimeDefault;  
tMaxSendTime : TIME := tMaxSendTimeDefault;  
bDisabled    : BOOL := FALSE;
```

**wNVIndex:** Unique index. This index is required for binding the LON nodes. A maximum of 62 SNVTs are permitted per terminal (KL6401). Values between 0 and 61 are possible.

**stValue:** Structure of the data to be sent.

**stValue. rL\_star:** Min: 0 / Max: 100.0 / L\*

**stValue. rA\_star:** Min: -200.0 / Max: 200.0 / a\*

**stValue. rB\_star:** Min: -200.0 / Max: 200.0 / b\*

**bStart:** The function block starts sending when these variables have a positive edge (irrespective of "bAuto").

**bSendInit:** The function block automatically sends its values once after a PLC restart.

**bAuto:** [Automatic sending](ms-xhelp:///?Id=beckhoff-83d9-4e0f-87b8-3129214c5d3f) is selected when a value changes or the time "tMaxSendTime" has elapsed (polling).

**tMinSendTime:** Parameter for [automatic sending](ms-xhelp:///?Id=beckhoff-83d9-4e0f-87b8-3129214c5d3f). A new value is only sent once a minimum time has elapsed. This prevents continuous sending.

**tMaxSendTime:** Parameter for [automatic sending](ms-xhelp:///?Id=beckhoff-83d9-4e0f-87b8-3129214c5d3f). The value is sent when this time has elapsed, even if the minimum change in value (ValueLimit) was not reached (polling). The value 0 disables this function.

**bDisabled:** TRUE = deselection of the block

**wNVIndex:** Unique index. This index is required for binding the LON nodes. A maximum of 62 SNVTs are permitted per LON terminal. Values between 0 and 61 are possible.

**stValue:** Structure of the data to be sent (see [ST\_LON\_SNVT\_color](ms-xhelp:///?Id=beckhoff-7526-4a97-bbf1-07e1caccc77f)).

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
