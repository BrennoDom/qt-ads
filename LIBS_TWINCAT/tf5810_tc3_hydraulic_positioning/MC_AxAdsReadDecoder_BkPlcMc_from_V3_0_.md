# MC_AxAdsReadDecoder_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Parameter](ms-xhelp:///?Id=beckhoff-b417-4e0c-b473-d1906e164f8c)
4. MC\_AxAdsReadDecoder\_BkPlcMc (from V3.0)

# MC\_AxAdsReadDecoder\_BkPlcMc (from V3.0)

![29123463](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854863627__Web.gif)

The function block decodes ADS read accesses. The [ADS codes](ms-xhelp:///?Id=beckhoff-d319-45ac-96c4-54e861345d4c) are listed in the Knowledge Base.

```
VAR_INPUT  
    nFirstAxisIndex:    INT;  
    nLastAxisIndex:     INT;  
    bReset:             BOOL;  
    bValid:             BOOL;  
    sNetId:             STRING(80);  
    nPort:              UINT;  
    nInvokeId:          UDINT;  
    nIdxGroup:          UDINT;  
    nIdxOffs:           UDINT;  
    cbReadLen:          UDINT;  
    pAxItf:             POINTER TO Axis_Ref_BkPlcMc:=0;  
END_VAR
```

```
VAR_INOUT  
    DeadManCount:       UDINT;  
END_VAR
```

```
VAR_OUTPUT  
    bClear:             BOOL;  
    bPending:           BOOL;  
END_VAR
```

**nFirstAxisIndex**, **nLastAxisIndex**: This parameter is used to specify the dimensioning of the [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) array.

Note

Crash of PLC application

An incorrect specification at this point excludes some of the axes from the communication or results in **a crash of the PLC application** by triggering serious runtime errors (**Page Fault Exception**).

**bReset**, **bValid**: The signals are used to co-ordinate the decoder with the ADS server.

**sNetId**, **nPort**, **nInvokeId**: These values are required in order to generate the ADS response. They are supplied by an ADS server's ADS indication function block.

**nIdxGroup**, **nIdxOffs**, **cbReadLen**: These values are required in order to decode the access. They are supplied by an ADS server's ADS indication function block.

**pAxItf**: Here, the address of a variable or an array of variables of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

**bClear**: Indicates that an ADS access indicated with bValid should be acknowledged.

**bPending**: Indicates that an ADS access indicated with bValid is being processed.

## Behaviour of the function block

If, when the bValid signal is present, the function block indicates neither bClear nor bPending it has not decoded the combination of nIdxGroup and nIdxOffs, and has not generated a response. In such a case, the ADS server (if there is one) must call another decoder, or must generate a response with the appropriate error code.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
