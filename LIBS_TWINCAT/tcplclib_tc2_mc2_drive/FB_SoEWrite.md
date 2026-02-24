# FB_SoEWrite

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# FB\_SoEWrite

FB\_SoEWrite NetId  T\_AmsNetIDIdn  WORDElement  BYTEpSrcBuf  PVOIDBufLen  UDINTExecute  BOOLTimeout  TIMEPassword  ST\_SoE\_String↔Axis  Reference To AXIS\_REFBOOL  BusyBOOL  ErrorUINT  AdsErrIdUINT  SercosErrId

With the FB\_SoEWrite function block a parameter can be written.

## VAR\_INPUT

```
VAR_INPUT  
    NetId    : T_AmsNetId := '';  
    Idn      : WORD;  
    Element  : BYTE;  
    SrcBuf   : PVOID;  
    BufLen   : UDINT;  
    Execute  : BOOL;  
    Timeout  : TIME := DEFAULT_ADS_TIMEOUT;  
    Password : ST_SoE_String;  
END_VAR
```

**NetId**: string, which contains the AMS-Network ID of the PC. (Type: T\_AmsNetId)

**Idn**: parameter number to which FB\_SoERead refers, e.g. "S\_0\_IDNs + 47" for S-0-0047, see [AX5000 Idn description.](https://infosys.beckhoff.com/content/1033/ax5000_idn_description/1000167435.html?id=4832105759336828980)

**Element**: specifies which part of the parameter should be accessed, e.g. 16#40 is the value of the parameter. Usually there is only write access to the value, other components of the parameter are read-only.

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

**SrcBuf**: ADR() of the variable containing the value to be written.

**BufLen**: SIZEOF() of the variable containing the value to be written

**Execute**: the function block is enabled via a positive edge at this input.

**Timeout**: maximum time that must not be exceeded when the function block is executed.

**Password**: password as sercos string. Currently not used. The password must be written with FB\_SoEWritePassword.

|  |  |
| --- | --- |
| 60212448 | The Idns can be taken from the corresponding drive documentation. For the AX5000 from Beckhoff see [AX5000 Idn description.](https://infosys.beckhoff.com/content/1033/ax5000_idn_description/1000167435.html?id=4832105759336828980) |

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
END_VAR
```

**Busy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**Error**: This output is set after the Busy output has been reset when an error occurs in the transmission of the command.

**AdsErrId**: In the case of a set Error output returns the ADS error code of the last executed command

**SercosErrId**: In the case of a set Error output returns the Sercos error of the last executed command.

## Sample

```
fbWrite    : FB_SoEWrite;  
Idn        : WORD;  
Write      : BOOL;  
WriteValue : UINT;  
Password   : ST_SoE_String;  
(* NcAxis *)  
Axis       : AXIS_REF;   
  
IF Write THEN  
 Idn := S_0_IDNs + 33;  
 fbWrite(  
    Axis     := Axis,  
    Idn      := Idn,  
    Element  := 16#40,  
    pSrcBuf  := ADR(WriteValue),  
    BufLen   := SIZEOF(WriteValue),  
    Password := Password,  
    Execute  := TRUE,  
    Timeout  := DEFAULT_ADS_TIMEOUT,  
 );  
 IF NOT fbWrite.Busy THEN  
    fbWrite(Axis := Axis, Execute := FALSE);  
    Write := FALSE;  
 END_IF  
END_IF 
```

## Parameter access

Note that for some parameters, the additional items of information "ActualLength" & "MaxLength" are necessary for the parameter access.

In order to determine the parameters for which this is necessary, the attributes can be displayed in the parameter list of the Drive Manager via the context menu of the header.

![5041122](/tcplclib_tc2_mc2_drive/1033/Images/png/8995253387__Web.png)

If the fifth place from the right contains the value 4, 5, 6 or 7, then the additional items of information are also transmitted.

![45370106](/tcplclib_tc2_mc2_drive/1033/Images/png/8995255947__Web.png)

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
