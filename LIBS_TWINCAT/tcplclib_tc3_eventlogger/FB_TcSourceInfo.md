# FB_TcSourceInfo

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# FB\_TcSourceInfo

![19546120](/tcplclib_tc3_eventlogger/1033/Images/png/5031416971__Web.png)

The source information of an event can be defined with this function block.

## Syntax

Definition:

```
FUNCTION_BLOCK FB_TcSourceInfo IMPLEMENTS I_TcSourceInfo
```

## 41697354 Interfaces

| Type | Description |
| --- | --- |
| [I\_TcSourceInfo](ms-xhelp:///?Id=beckhoff-11ec-4c62-aae5-5ff3ab304cf2) | Provides read methods and read properties of a source information. |

## 39731869 Methods

| Name | Definition location | Description |
| --- | --- | --- |
| [Clear](ms-xhelp:///?Id=beckhoff-07f9-4c06-8383-ce8b21b14405) | Local | Resets the source information. |
| [ExtendName](ms-xhelp:///?Id=beckhoff-7e2d-4bb2-b491-beea0a2fbe4d) | Local | Appends the transferred string to the name. |
| [ResetToDefault](ms-xhelp:///?Id=beckhoff-c2d3-42cf-bd93-98de3436a35d) | Local | Sets the properties to default values.  sName is initialized with the symbol name of the instanced function block.  nId is initialized with the object ID of the PLC instance.  If the instance of FB\_TcSourceInfo is hidden with the attribute "hide", no symbol name can be created internally for the default behavior. |
| [EqualsTo](ms-xhelp:///?Id=beckhoff-ea49-4990-bca2-40cfd601b715) | [I\_TcSourceInfo](ms-xhelp:///?Id=beckhoff-11ec-4c62-aae5-5ff3ab304cf2) | Compares an instance with another instance. |

## 22042507 Properties

| Name | Type | Access | Definition location | Description |
| --- | --- | --- | --- | --- |
| guid | GUID | Get | [I\_TcSourceInfo](ms-xhelp:///?Id=beckhoff-11ec-4c62-aae5-5ff3ab304cf2) | Returns the GUID of the source information. |
| guid | GUID | SET | Local | Sets the GUID as source information. |
| nId | UDINT | Get | [I\_TcSourceInfo](ms-xhelp:///?Id=beckhoff-11ec-4c62-aae5-5ff3ab304cf2) | Returns the ID of the source information. |
| nId | UDINT | SET | Local | Sets the ID of the source information. |
| sName | STRING(ParameterList.cSourceNameSize-1) | Get | [I\_TcSourceInfo](ms-xhelp:///?Id=beckhoff-11ec-4c62-aae5-5ff3ab304cf2) | Returns the name of the source information. |
| sName | STRING(ParameterList.cSourceNameSize-1) | SET | Local | Sets the name of the source information |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4022.20 | PC or CX (x64, x86, ARM) | Tc3\_EventLogger |

Further Information

* [Clear](ms-xhelp:///?Id=beckhoff-07f9-4c06-8383-ce8b21b14405)
* [ExtendName](ms-xhelp:///?Id=beckhoff-7e2d-4bb2-b491-beea0a2fbe4d)
* [ResetToDefault](ms-xhelp:///?Id=beckhoff-c2d3-42cf-bd93-98de3436a35d)
