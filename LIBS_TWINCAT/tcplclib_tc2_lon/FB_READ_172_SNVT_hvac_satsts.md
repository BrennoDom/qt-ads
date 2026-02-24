# FB_READ_172_SNVT_hvac_satsts

## Library
tcplclib_tc2_lon

## Category
Motion Control

# FB\_READ\_172\_SNVT\_hvac\_satsts

![3143429](/tcplclib_tc2_lon/1033/Images/gif/151016971__en-US__Web.gif)

This function block receives the following LON input variable (nvi):

**SNVT Name:** SNVT\_hvac\_satsts.

**SNVT number:** 172.

**Description:** HVAC saturation status.

0 in a field means that plant (device) linked to the field is not saturated or does not reach the limit stop before the required set value is reached.

1 in a field means that plant (device) linked to the field is saturated or reaches the limit stop before the required set value is not reached.

## VAR\_INPUT

```
wNVIndex  : WORD;  
bDisabled : BOOL := FALSE;
```

**wNVIndex:** Unique index. This is required for binding the LON nodes. A maximum of 62 SNVTs are permitted per LON terminal. Values between 0 and 61 are possible.

**bDisabled:** TRUE = deselection of the block.

## VAR\_OUPUT

```
stValue  : ST_LON_SNVT_hvac_satsts;  
bNewData : BOOL;  
bError   : BOOL;  
eError   : E_LON_ERROR;
```

**stValue:** Structure of the received data (see [ST\_LON\_SNVT\_hvac\_satsts](ms-xhelp:///?Id=beckhoff-d2d2-4700-96ff-0bcbe7d5bc44)).

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
