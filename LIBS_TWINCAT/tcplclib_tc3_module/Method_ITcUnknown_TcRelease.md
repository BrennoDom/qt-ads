# Method ITcUnknown:TcRelease

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Appendix](ms-xhelp:///?Id=beckhoff-7a54-458a-984c-ff7aefcf1c19)
3. [Interfaces](ms-xhelp:///?Id=beckhoff-581c-4e1d-a450-dec7512fb73c)
4. [Interface ITcUnknown](ms-xhelp:///?Id=beckhoff-c839-4bdf-98ea-b60f82d20e77)
5. Method ITcUnknown:TcRelease

# Method ITcUnknown:TcRelease

This method decrements the reference counter.

## Syntax

```
ULONG  TcRelease( )
```

## Return Value

Resulting reference count value.

## Description

Decrements the reference counter and returns the new value.

If reference counter gets zero, object deletes itself.

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
