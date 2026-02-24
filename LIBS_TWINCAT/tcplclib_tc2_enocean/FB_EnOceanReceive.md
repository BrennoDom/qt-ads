# FB_EnOceanReceive

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# FB\_EnOceanReceive

![19718930](/tcplclib_tc2_enocean/1033/Images/gif/173335179__en-US__Web.gif)

The function block *FB\_EnOceanReceive()* is a receive block, which makes the telegrams sent by the EnOcean modules available in the structure *stEnOceanReceivedData*. This structure can then be analyzed with further blocks. The documentation for this blocks also includes sample programs, which illustrate the operating principle.

## VAR\_INPUT

```
bEnable : BOOL := FALSE;
```

**bEnable:** A positive signal at this input activates the block. A negative signal at the input disables the block functionality.

## VAR\_OUTPUT

```
bError                : BOOL := FALSE;  
nErrorId              : UDINT := 0;  
stEnOceanReceivedData : ST_EnOceanReceivedData;
```

**bError:** this output goes TRUE as soon as an error occurs. This error is described via the variable *nErrorId*.

**nErrorId:** Describes the error type (see [error codes](ms-xhelp:///?Id=beckhoff-b80a-476f-a411-558c74468ff6)).

**stEnOceanReceivedData:** This structure contains the received data (see [ST\_EnOceanReceivedData](ms-xhelp:///?Id=beckhoff-cc12-4397-a341-a293a6adc9d6)).

## VAR\_IN\_OUT

```
stEnOceanInData  : ST_EnOceanInData;  
stEnOceanOutData : ST_EnOceanOutData;
```

**stEnOceanInData:** Is linked with the input addresses of the KL6021-0023 in the System Manager (see [ST\_EnOceanInData](ms-xhelp:///?Id=beckhoff-ae21-4b2d-b5d2-d7c909ac2ad5)).

**stEnOceanOutData:** Is linked with the output addresses of the KL6021-0023 in the System Manager (see [ST\_EnOceanOutData](ms-xhelp:///?Id=beckhoff-001e-487a-a974-cb5121ba6e02)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
