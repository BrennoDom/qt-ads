# Method ITcComObject:TcSetObjectId

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Appendix](ms-xhelp:///?Id=beckhoff-7a54-458a-984c-ff7aefcf1c19)
3. [Interfaces](ms-xhelp:///?Id=beckhoff-581c-4e1d-a450-dec7512fb73c)
4. [Interface ITComObject](ms-xhelp:///?Id=beckhoff-e24f-4dbb-8d7b-9a3f73a5f39f)
5. Method ITcComObject:TcSetObjectId

# Method ITcComObject:TcSetObjectId

The method TcSetObjectId sets object’s object ID to the given OTCID.

## Syntax

```
HRESULT TcSetObjectId( OTCID objId )
```

## Parameters

**objId:** (type: OTCID) The OTCID, which should be set.

## Return value

If successful, S\_OK ("0") or another positive value will be returned, cf. Return values. Extended messages refer in particular to the column HRESULT in [ADS Return Codes](ms-xhelp:///?Id=beckhoff-4780-452a-ab6b-bc4e8908f2c6).

At present, the return value is ignored by the TwinCAT tasks.

## Description

Indicates the success of the ID change.

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
