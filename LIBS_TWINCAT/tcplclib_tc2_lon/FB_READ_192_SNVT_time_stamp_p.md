# FB_READ_192_SNVT_time_stamp_p

## Library
tcplclib_tc2_lon

## Category
Motion Control

# FB\_READ\_192\_SNVT\_time\_stamp\_p

![53855148](/tcplclib_tc2_lon/1033/Images/gif/151074571__en-US__Web.gif)

This function block receives the following LON input variable (nvi):

**SNVT Name:** SNVT\_time\_stamp\_p.

**SNVT number:** 192.

**Description:** Precise timestamp (seconds). Timestamp with a resolution of a hundredth second.

## VAR\_INPUT

```
wNVIndex  : WORD;  
bDisabled : BOOL := FALSE;
```

**wNVIndex:** Unique index. This is required for binding the LON nodes. A maximum of 62 SNVTs are permitted per LON terminal. Values between 0 and 61 are possible.

**bDisabled:** TRUE = deselection of the block.

## VAR\_OUTPUT

```
stValue  : TIMESTRUCT;  
bNewData : BOOL;  
bError   : BOOL;  
eError   : E_LON_ERROR;
```

**stValue:** Structure of the received data (see TIMESTRUCT).

**bNewData:** Becomes TRUE for 1 cycle when the block has received data.

**bError:** This output goes TRUE as soon as an error occurs. This error is described via the variable *eError*.

**eError:** This output outputs an error code in the event of an error (see [E\_LON\_ERROR](ms-xhelp:///?Id=beckhoff-ad05-4d5c-a4ac-eed1f05a18f2)). bError goes TRUE at the same time.

## VAR\_IN\_OUT

```
stLON_Com : ST_LON_Communication;
```

**stLON\_Com :** This structure is used to link [FB\_LON\_KL6401()](ms-xhelp:///?Id=beckhoff-cce2-44f9-8642-d620dc9ab975) with the send/receive function (see [ST\_LON\_Communication](ms-xhelp:///?Id=beckhoff-2ad7-4b6a-944d-a82a3e3847ef)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
