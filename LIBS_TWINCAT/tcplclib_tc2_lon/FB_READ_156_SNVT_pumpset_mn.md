# FB_READ_156_SNVT_pumpset_mn

## Library
tcplclib_tc2_lon

## Category
Motion Control

# FB\_READ\_156\_SNVT\_pumpset\_mn

![46712854](/tcplclib_tc2_lon/1033/Images/gif/150968971__en-US__Web.gif)

This function block receives the following LON input variable (nvi):

**SNVT Name:** SNVT\_pumpset\_mn.

**SNVT number:** 156.

**Description:** Pump group (main pump, auxiliary pump, priority, ready, emergency off, main pump activated, auxiliary pump activated, maintenance request). Synchronized vacuum pumps.

## VAR\_INPUT

```
wNVIndex  : WORD;  
bDisabled : BOOL := FALSE;
```

**wNVIndex:** Unique index. This is required for binding the LON nodes. A maximum of 62 SNVTs are permitted per LON terminal. Values between 0 and 61 are possible.

**bDisabled:** TRUE = deselection of the block.

## VAR\_OUTPUT

```
stValue  : ST_LON_SNVT_pumpset_mn;  
bNewData : BOOL;  
bError   : BOOL;  
eError   : E_LON_ERROR;
```

**stValue:** Structure of the received data (see [ST\_LON\_SNVT\_pumpset\_mn](ms-xhelp:///?Id=beckhoff-6e2b-4202-9e15-a183c4c7599a)).

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
