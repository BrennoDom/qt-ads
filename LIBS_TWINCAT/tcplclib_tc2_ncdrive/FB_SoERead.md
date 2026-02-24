# FB_SoERead

## Library
tcplclib_tc2_ncdrive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-725e-4601-b0fd-30492204b699)
3. [General SoE](ms-xhelp:///?Id=beckhoff-6800-459e-a087-89077ab014ae)
4. [Function blocks for determining current values](ms-xhelp:///?Id=beckhoff-ae69-46e8-9eb6-77b109d205a7)
5. FB\_SoERead

# FB\_SoERead

![20756449](/tcplclib_tc2_ncdrive/1033/Images/gif/2302090635__Web.gif)

With the FB\_SoERead function block a parameter can be read.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId    : T_AmsNetId := '';  
    nIdn      : WORD;  
    nElement  : BYTE;   
    pDstBuf   : PVOID;  
    cbBufLen  : UDINT;  
    bExecute  : BOOL;  
    tTimeout  : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: String, which contains the AMS-Network ID of the PC (Type: T\_AmsNetId).

**nIdn**: Parameter number to which FB\_SoERead refers, e.g. "S\_0\_IDN + 33" for   
S-0-0033

**nElement**: Specifies which part of the parameter should be accessed, e.g. 16#40 is the value (Value) of the parameter.

```
EC_SOE_ELEMENT_DATASTATE :BYTE :=16#01;  
  
EC_SOE_ELEMENT_NAME :BYTE :=16#02;  
  
EC_SOE_ELEMENT_ATTRIBUTE :BYTE :=16#04;  
  
EC_SOE_ELEMENT_UNIT :BYTE :=16#08;  
  
EC_SOE_ELEMENT_MIN :BYTE :=16#10;  
  
EC_SOE_ELEMENT_MAX :BYTE :=16#20;  
  
EC_SOE_ELEMENT_VALUE :BYTE :=16#40;  
  
EC_SOE_ELEMENT_DEFAULT :BYTE :=16#80; 
```

**pDstBuf**: ADR() of the variables to which the value should be read.

**cbBufLen**: SIZEOF() of the variables to which the value should be read.

**bExecute**: The function block is enabled via a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    Axis : NCTOPLC_AXIS_REF;(* reference to NC axis *)  
END_VAR
```

**Axis**: Axis data structure of the type NCTOPLC\_AXIS\_REF.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy        : BOOL;  
    bError       : BOOL;  
    iAdsErrId    : UINT;  
    iSercosErrId : UINT;  
    dwAttribute  : DWORD;  
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**iAdsErrId**: In the case of a set bError output returns the ADS error code of the last executed command.

**iSercosErrId**: In the case of a set bError output returns the Sercos error of the last executed command.

**dwAttribute**: Returns the attributes of the Sercos parameter.

## Sample

```
fbRead : FB_SoERead;  
bRead : BOOL;  
iReadValue : UINT;  
(* NcAxis *)  
stNcToPlc AT %I* : NCTOPLC_AXLESTRUCT;  
  
IF bRead THEN  
 nIdn := S_0_IDN + 33;  
 fbRead(  
    Axis := stNcToPlc,  
    nIdn := nIdn,  
    nElement := 16#40,  
    pDstBuf := ADR(iReadValue),  
    cbBufLen := SIZEOF(iReadValue),  
    bExecute := TRUE,  
    tTimeout := DEFAULT_ADS_TIMEOUT,  
 );  
 IF NOT fbRead.bBusy THEN  
    fbRead(Axis := stNcToPlc, bExecute := FALSE);  
    bRead := FALSE;  
 END_IF  
END_IF 
```

[TwinCAT 3 | PLC Library: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
