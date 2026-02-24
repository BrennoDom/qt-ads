# I_TcSourceInfo

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# I\_TcSourceInfo

This interface defines properties for an item of source information.

## 29995926 Methods

| Name | Description |
| --- | --- |
| [EqualsTo](ms-xhelp:///?Id=beckhoff-ea49-4990-bca2-40cfd601b715) | Compares an instance with source information with another instance. |

## 1527883 Properties

| Name | Type | Access | Description |
| --- | --- | --- | --- |
| guid | GUID | Get | Returns the GUID of the source information. |
| nId | UDINT | Get | Returns the ID of the source information. |
| sName | STRING(ParameterList.cSourceNameSize-1) | Get | Returns the name of the source information. |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4022.20 | PC or CX (x64, x86, ARM) | Tc3\_EventLogger |

Further Information

* [EqualsTo](ms-xhelp:///?Id=beckhoff-ea49-4990-bca2-40cfd601b715)
