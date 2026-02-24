# Error codes overview

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Error Codes](ms-xhelp:///?Id=beckhoff-d04b-4b23-afee-c6539244fc0e)
3. Error codes overview

# Error codes overview

The function blocks of the Tc2\_MDP library have an *nErrID output*. This value is 4 bytes in size and returns the error code in the event of an error. *nErrID* is comprised of two parts:

| **Error Group** (MSB) 2 Byte | **Error Code** 2 Byte (LSB) |
| --- | --- |
| 0x EC80 | [E\_MDP\_ErrCodesPLC](ms-xhelp:///?Id=beckhoff-9dd5-4e16-9b18-7673085c0933) |
| 0x ECA6 | [MDP general error](https://infosys.beckhoff.de/content/1033/devicemanager/36028797282007179.html?id=3679686968781788561) |
| 0x ECA7 | [MDP API error](https://infosys.beckhoff.de/content/1033/devicemanager/36028797282007179.html?id=3679686968781788561) |
| 0x ECA8 | [ADS error](https://infosys.beckhoff.de/content/1033/devicemanager/36028797282007179.html?id=3679686968781788561) |
| 0x ECAF | [MDP module specific error](https://infosys.beckhoff.de/content/1033/devicemanager/36028797282007179.html?id=3679686968781788561) |

The function block [FB\_MDP\_SplitErrorID](ms-xhelp:///?Id=beckhoff-31e3-4fca-99f1-27e6522e172c) enables the automatic separation of the variable *nErrID* into error group and error code.

## Error Group

The fault group describes the type of error that has occurred. The different groups are listed in the enumeration [E\_MDP\_ErrGroup](ms-xhelp:///?Id=beckhoff-267d-40a2-917e-1b453e1e2694).  
 All errors generated within the PLC library have the error group 0xEC80.

## Error Code

The error code describes the specific error.  
For errors within the PLC library with the error group 0xEC80, the identifiers are listed in the enumeration [E\_MDP\_ErrCodesPLC](ms-xhelp:///?Id=beckhoff-9dd5-4e16-9b18-7673085c0933). A description of the other error codes can be found in the documentation of the IPC diagnostics in the section on error messages.

|  |  |
| --- | --- |
| 7641038 | General MDP-dependent errors are output in the error group 16#ECA6 “General error codes”. These errors sometimes indicate that an element from the module element list is not available. Example: 16#ECA60105 "No data available" If, in the case of a general or specific function block (see access options), several elements are queried at the same time and one of these elements is not available or exhibits an error, then the output variable iErrPos indicates the index position (0..n) at which the error occurred for the first time. All elements below this index were queried successfully and are indicated despite the generation of an error at the output. |

## Example:

*nErrID* = 0x ECA8 0745

The error group is 0x ECA8, therefore it is an Ads error.  
The error code is 0x 0745, therefore it is a timeout error.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_MDP |

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
