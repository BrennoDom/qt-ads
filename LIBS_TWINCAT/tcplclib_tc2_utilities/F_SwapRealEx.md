# F_SwapRealEx

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_SwapRealEx

![45048586](/tcplclib_tc2_utilities/1033/Images/gif/35846283__en-US__Web.gif)

The memory representation of a REAL number in a Bus Terminal Controller (e.g. BC2000, BC3100, BC9000) differs from the memory representation of a REAL number in an x86/x64/ARM system (IPC or Embedded PC).  
To be able to represent a REAL number of a Bus Terminal Controller properly on an IPC, the Hi and Lo words of the REAL number must be interchanged. Under the programming environment this is already done in online or simulation mode. To be able to request the REAL data of a Bus Controller via the network ( ADS protocol, ADSDLL, AdsOcx etc. ) and represent them properly on an x86/x64/ARM IPC, the REAL data have to be converted into the correct format. This can be done on the Bus Terminal Controller side or the IPC side.

The function F\_SwapRealEx can be used to convert the REAL variables (e.g. variables to be read by a VB application or recorded with TwinCAT Scope View) into a suitable format on the PC side. The function changes the memory representation of the transferred *fVal* parameter (VAR\_IN\_OUT).

## FUNCTION F\_SwapRealEx: BOOL

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    fVal : REAL;  
END_VAR
```

**fVal**: The REAL value to be converted.

| Return parameter | Meaning |
| --- | --- |
| TRUE | No error |
| FALSE | Error during function execution |

**Example:**

See: [Example: Communication BC/BX<->PC/CX (F\_SwapRealEx).](ms-xhelp:///?Id=beckhoff-dec7-4808-a138-29c9c08ad04a)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
