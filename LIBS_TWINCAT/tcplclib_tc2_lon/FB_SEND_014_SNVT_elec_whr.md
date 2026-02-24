# FB_SEND_014_SNVT_elec_whr

## Library
tcplclib_tc2_lon

## Category
Motion Control

# FB\_SEND\_014\_SNVT\_elec\_whr

![40133923](/tcplclib_tc2_lon/1033/Images/gif/151141771__en-US__Web.gif)

This function block sends the following LON output variable (nvo):

**SNVT Name:** SNVT\_elec\_whr.

**SNVT number:** 014.

**Description:** Electric energy (W/h).

## VAR\_INPUT

```
wNVIndex     : WORD;  
rValue       : REAL;  
bStart       : BOOL;  
bSendInit    : BOOL := bSendInitDefault;  
bAuto        : BOOL := bAutoDefault;  
rValueLimit  : REAL := 1;  
tMinSendTime : TIME := tMinSendTimeDefault;  
tMaxSendTime : TIME := tMaxSendTimeDefault;  
bDisabled    : BOOL := FALSE;
```

**wNVIndex:** Unique index. This index is required for binding the LON nodes. A maximum of 62 SNVTs are permitted per LON terminal. Values between 0 and 61 are possible.

**rValue:** Min: 0 / Max: 6553.5.

**bStart:** A positive edge starts the send process (irrespective of *bAuto*).

**bSendInit:** Automatically sends the value once when the PLC restarts.

**bAuto:** [Automatic sending](ms-xhelp:///?Id=beckhoff-83d9-4e0f-87b8-3129214c5d3f) is selected when a value changes or the time *tMaxSendTime* has elapsed (polling).

**rValueLimit:** Parameter for [automatic sending](ms-xhelp:///?Id=beckhoff-83d9-4e0f-87b8-3129214c5d3f). The value is only sent if the change since the last transfer is greater than this parameter. If this value is 0, sending takes place after each change in value. This value is not available for enums and structures, where sending takes place after each change in value.

**tMinSendTime:** Parameter for [automatic sending](ms-xhelp:///?Id=beckhoff-83d9-4e0f-87b8-3129214c5d3f). A new value is sent when this time has elapsed at the earliest, to prevent continuous sending.

**tMaxSendTime:** Parameter for [automatic sending](ms-xhelp:///?Id=beckhoff-83d9-4e0f-87b8-3129214c5d3f). The value is sent when this time has elapsed at the latest, even if the minimum change in value (*rValueLimit*) was not reached (polling). The value 0 disables this function.

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
