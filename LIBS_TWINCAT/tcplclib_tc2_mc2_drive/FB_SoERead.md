# FB_SoERead

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# FB\_SoERead

FB\_SoERead NetId  T\_AmsNetIDIdn  WORDElement  BYTEpDstBuf  PVOIDBufLen  UDINTExecute  BOOLTimeout  TIME↔Axis  Reference To AXIS\_REFBOOL  BusyBOOL  ErrorUINT  AdsErrIdUINT  SercosErrIdDWORD  Attribute

With the FB\_SoERead function block a parameter can be read.

By default, attributes and values are read in parallel.

Should the call generate an ADS error on a third-party device, the lack of support for this faster parameter access method may be the cause.

In this case, the function block [FB\_SoESetDataAccessMode](ms-xhelp:///?Id=beckhoff-25c9-41a4-b48c-ab58d18eb760) can be used to switch to the slower sequential access method, if required.

## VAR\_INPUT

```
VAR_INPUT  
    NetId    : T_AmsNetId := '';  
    Idn      : WORD;  
    Element  : BYTE;   
    pDstBuf  : PVOID;  
    BufLen   : UDINT;  
    Execute  : BOOL;  
    Timeout  : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NetId**: string, which contains the AMS-Network ID of the PC. (Type: T\_AmsNetId)

**Idn**: parameter number to which FB\_SoERead refers, e.g. "S\_0\_IDNs + 33" for S-0-0033

**Element**: specifies which part of the parameter should be accessed, e.g. 16#40 is the value of the parameter.

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

**BufLen**: SIZEOF() of the variables to which the value should be read.

**Execute**: the function block is enabled via a positive edge at this input.

**Timeout**: maximum time that must not be exceeded when the function block is executed.

|  |  |
| --- | --- |
| 2107829 | The Idns can be taken from the corresponding drive documentation. For the AX5000 from Beckhoff see [AX5000 Idn description.](https://infosys.beckhoff.com/content/1033/ax5000_idn_description/1000167435.html?id=4832105759336828980) |

## VAR\_IN\_OUT

```
VAR_IN_OUT  
   Axis : AXIS_REF;  
END_VAR
```

**Axis**: The axis data structure of type AXIS\_REF addresses an axis unambiguously within the system. Among other things it contains the current status of the axis such as the position, the velocity and the error state.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    Busy        : BOOL;  
    Error       : BOOL;  
    AdsErrId    : UINT;  
    SercosErrId : UINT;  
    Attribute   : DWORD;  
END_VAR
```

**Busy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**Error**: This output is set after the Busy output has been reset when an error occurs in the transmission of the command.

**AdsErrId**: In the case of a set Error output returns the ADS error code of the last executed command.

**SercosErrId**: In the case of a set Error output returns the Sercos error of the last executed command.

**Attributes**: Returns the attributes of the Sercos parameter.

## Sample

```
fbRead    : FB_SoERead;  
Read      : BOOL;  
Idn       : WORD;  
ReadValue : UINT;  
(* NcAxis *)  
Axis : AXIS_REF;   
  
IF Read THEN  
 Idn := S_0_IDNs + 33;  
 fbRead(  
    Axis    := Axis,  
    Idn     := Idn,  
    Element := 16#40,  
    pDstBuf := ADR(ReadValue),  
    BufLen  := SIZEOF(ReadValue),  
    Execute := TRUE,  
    Timeout := DEFAULT_ADS_TIMEOUT,  
 );  
 IF NOT fbRead.Busy THEN  
    fbRead(Axis := Axis, Execute := FALSE);  
    Read := FALSE;  
 END_IF  
END_IF 
```

## Parameter access

Note that for some parameters, the additional items of information "ActualLength" & "MaxLength" are necessary for the parameter access.

In order to determine the parameters for which this is necessary, the attributes can be displayed in the parameter list of the Drive Manager via the context menu of the header.

![18970462](/tcplclib_tc2_mc2_drive/1033/Images/png/8995253387__Web.png)

If the fifth place from the right contains the value 4, 5, 6 or 7, then the additional items of information are also transmitted.

![36516433](/tcplclib_tc2_mc2_drive/1033/Images/png/8995255947__Web.png)

The structure to read out the serial number (S-0-0432) then looks like this:

```
TYPE ST_SerialNumber:  
STRUCT  
    ActualLength : UINT;  
    MaxLength    : UINT;  
    SerialNumber : T_MaxString;  
END_STRUCT  
END_TYPE
```
