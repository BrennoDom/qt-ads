# F_SplitDpv1WriteResPkg

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [Profibus DPV1 (Sinamics)](ms-xhelp:///?Id=beckhoff-405b-4f91-aab8-55ebb5095cec)
4. F\_SplitDpv1WriteResPkg

# F\_SplitDpv1WriteResPkg

![48932206](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314197259__Web.png)

The “F\_SplitDpv1WriteResPkg” function creates a DPV1 telegram for an [FB\_Dpv1Write](ms-xhelp:///?Id=beckhoff-e930-429d-a47a-b9c453f530fd) of one or more parameters of a drive or the controller unit of a Sinamics Profidrive (Profidrive Specification 3.1). Since Profidrives use the Motorola format and IPCs the Intel format, the function automatically swaps the byte order of parameters with data types with more than one byte in the DPV1 telegram.

The function returns the actual length of the DPV1 telegram in bytes (max. 240 bytes).

## FUNCTION F\_SplitDpv1WriteResPkg : USINT

## VAR\_INPUT

```
VAR_INPUT  
    pDpv1ResData : POINTER TO ARRAY [1..iMAX_DPV1_SIZE] OF BYTE;(* DPV1 write response *)  
END_VAR
```

**pDpv1ResData**: Pointer to an array of 240 bytes containing the DPV1 write response telegram. This telegram is evaluated by the function.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    stDpv1Parameter     : ARRAY [1..iMAX_DPV1_PARAMS] OF ST_Dpv1ParamAddrEx;(* list of parameters *)  
    stDpv1ValueHeaderEx : ARRAY [1..iMAX_DPV1_PARAMS] OF ST_Dpv1ValueHeaderEx;(* list of values *)  
END_VAR
```

**stDpv1Parameter**: Array of 39 parameters that were added to the DPV1 write telegram (type: [ST\_Dpv1ParamAddrEx](ms-xhelp:///?Id=beckhoff-9a8b-431a-966f-b96159493f14)).

**stDpv1ValueHeaderEx**: Array of 39 parameter values that were read from the drive (type: [ST\_Dpv1ValueHeaderEx](ms-xhelp:///?Id=beckhoff-9b58-428b-b8ab-b5208c6219f5)).

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86) | Beckhoff FC310x PCI, CX1500-M310, EL6731 | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
