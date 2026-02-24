# FB_TcArguments

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# FB\_TcArguments

![21180630](/tcplclib_tc3_eventlogger/1033/Images/png/5031420811__Web.png)

Arguments of an event can be defined with this function block. The ITcArguments interface is implemented for this.

## Syntax

Definition:

```
FUNCTION_BLOCK FB_TcArguments IMPLEMENTS I_TcArguments
```

## 56407950 Interfaces

| Type | Description |
| --- | --- |
| [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Defines the argument handling. |

## 37909503 Methods

| Name | Definition location | Description |
| --- | --- | --- |
| [AddBlob](ms-xhelp:///?Id=beckhoff-dbf6-4b39-b34a-e5e40a1f84fb) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Adds binary data as an argument. |
| [AddBool](ms-xhelp:///?Id=beckhoff-288e-430d-8215-39382dc68316) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Adds an argument of the type BOOL. |
| [AddByte](ms-xhelp:///?Id=beckhoff-7738-41cd-a1d8-8c8a09f1cd62) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Adds an argument of the type BYTE. |
| [AddDint](ms-xhelp:///?Id=beckhoff-13d7-46fa-a48d-fb8a3e67a204) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Adds an argument of the type DINT. |
| [AddDWord](ms-xhelp:///?Id=beckhoff-8d4c-4326-92d1-cb86f383ca85) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Adds an argument of the type DWORD. |
| [AddEventReferencId](ms-xhelp:///?Id=beckhoff-a34a-4a0c-b4cb-412239357c50) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Adds a reference to another event as an argument. |
| [AddEventReferenceIdGuid](ms-xhelp:///?Id=beckhoff-08ad-4777-b7e1-62449ef2ce88) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Adds a reference to another event as an argument. |
| [AddInt](ms-xhelp:///?Id=beckhoff-8c15-4c82-9236-8e02e35fd936) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Adds an argument of the type INT. |
| [AddLInt](ms-xhelp:///?Id=beckhoff-4c20-4914-b123-e3a2cc38140d) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Adds an argument of the type LINT. |
| [AddLReal](ms-xhelp:///?Id=beckhoff-0285-4d29-be39-36842a1bb2c6) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Adds an argument of the type LREAL. |
| [AddReal](ms-xhelp:///?Id=beckhoff-296b-48ae-a420-bdbc0aaa3a0a) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Adds an argument of the type REAL. |
| [AddSInt](ms-xhelp:///?Id=beckhoff-25a8-4b9c-b18a-2145bdd89577) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Adds an argument of the type SINT. |
| [AddString](ms-xhelp:///?Id=beckhoff-1f43-4210-abfd-38de7accfb39) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Adds an argument of the type STRING. |
| [AddUDint](ms-xhelp:///?Id=beckhoff-16d0-4938-9604-f7d014f89a91) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Adds an argument of the type UDINT. |
| [AddUInt](ms-xhelp:///?Id=beckhoff-6647-479b-bd42-972e6b0a7761) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Adds an argument of the type INT. |
| [AddULInt](ms-xhelp:///?Id=beckhoff-dbcb-4572-ab9b-2205792b6c49) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Adds an argument of the type ULINT. |
| [AddUSInt](ms-xhelp:///?Id=beckhoff-9b3e-4bc2-b3c1-850bd77191ac) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Adds an argument of the type USINT. |
| [AddWord](ms-xhelp:///?Id=beckhoff-26c9-4321-8ccd-9c3494b2451b) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Adds an argument of the type WORD. |
| [AddWString](ms-xhelp:///?Id=beckhoff-b17e-4e9f-9f21-b22ae887fa28) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Adds an argument of the type WSTRING. |
| [Clear](ms-xhelp:///?Id=beckhoff-5a8d-4fdf-bc9b-756a6fd8d6c1) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Removes all arguments. |
| [IsEmpty](ms-xhelp:///?Id=beckhoff-a80e-4e26-8a2a-76ea44106034) | Local | Checks whether arguments have been added. |

## 5641212 Properties

| Name | Type | Access | Description |
| --- | --- | --- | --- |
| nCount | UDINT | Get | Returns the number of transferred arguments. |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4022.20 | PC or CX (x64, x86, ARM) | Tc3\_EventLogger |

Further Information

* [IsEmpty](ms-xhelp:///?Id=beckhoff-a80e-4e26-8a2a-76ea44106034)
