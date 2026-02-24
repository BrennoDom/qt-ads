# Interface ITcUnknown

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Appendix](ms-xhelp:///?Id=beckhoff-7a54-458a-984c-ff7aefcf1c19)
3. [Interfaces](ms-xhelp:///?Id=beckhoff-581c-4e1d-a450-dec7512fb73c)
4. Interface ITcUnknown

# Interface ITcUnknown

ITcUnknown defines the reference counting as well as querying a reference to a more specific interface.

## Syntax

```
TCOM_DECL_INTERFACE("00000001-0000-0000-e000-000000000064", ITcUnknown)
```

Declared in: TcInterfaces.h

Required include: -

## 30791836 Methods

| Name | Description |
| --- | --- |
| [TcAddRef](ms-xhelp:///?Id=beckhoff-07a1-4115-966e-a7a178034c9a) | Increments the reference counter. |
| [TcQueryInterface](ms-xhelp:///?Id=beckhoff-0307-4398-bf34-c55ac2ddec56) | Query of the reference to an implemented interface via the IID. |
| [TcRelease](ms-xhelp:///?Id=beckhoff-628b-4d96-a812-40e9069d8ec3) | Decrements the reference counter. |

## Remarks

Every TcCOM interface is directly or indirectly derived from ITcUnknown. As a consequence every TcCOM module class implements ITcUnknown, because it is derived from ITComObject.

The default implementation for ITcUnknown will delete the object if its last reference is released. Therefore an interface pointer must not be dereferenced after TcRelease() has been called.

Further Information

* [Method ITcUnknown:TcAddRef](ms-xhelp:///?Id=beckhoff-07a1-4115-966e-a7a178034c9a)
* [Method ITcUnknown:TcQueryInterface](ms-xhelp:///?Id=beckhoff-0307-4398-bf34-c55ac2ddec56)
* [Method ITcUnknown:TcRelease](ms-xhelp:///?Id=beckhoff-628b-4d96-a812-40e9069d8ec3)

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
