# F_CreateDpv1ReadReqPkgPNET

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [Profinet DPV1 (Sinamics)](ms-xhelp:///?Id=beckhoff-38a9-44b2-a8a7-a6b5d32d9089)
4. F\_CreateDpv1ReadReqPkgPNET

# F\_CreateDpv1ReadReqPkgPNET

![36771698](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314200459__Web.png)

The “F\_CreateDpv1ReadReqPkg” function creates a DPV1 telegram for an [FB\_Dpv1ReadPNET](ms-xhelp:///?Id=beckhoff-c72a-4bed-aac7-74dd2de891f5) of one or more parameters of a drive or the controller unit of a Sinamics Profidrive (Profidrive Specification 3.1) that is connected via Profinet. Since Profidrives use the Motorola format and IPCs the Intel format, the function automatically swaps the byte order of parameters with data types with more than one byte in the DPV1 telegram.

The function returns the actual length of the DPV1 telegram in bytes (max. 240 bytes).

## FUNCTION F\_CreateDpv1ReadReqPkgPNET : USINT

## VAR\_INPUT

```
VAR_INPUT  
    pDpv1ReqData : POINTER TO ARRAY [1..iMAX_DPV1_SIZE] OF BYTE;(* DPV1 read request *)  
    iNumOfParams : USINT; (* 1..39; else: reserved *)  
    iDriveId     : USINT;  
END_VAR
```

**pDpv1ReqData**: Pointer to an array of 240 bytes containing the DPV1 read telegram. This telegram is created by the function.

**iNumOfParams**: Number of parameters to be read (1 to 39). A further limitation is the telegram size of 240 bytes.

**iDriveID**: The ID is 1 for the controller unit, 2 for the drive object A and 3 for the drive object B of a double/triple drive. The drive ID is set in the starter software. 1 – 16 is possible.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    stDpv1Parameter : ARRAY [1..iMAX_DPV1_PARAMS] OF ST_Dpv1ParamAddrEx;(* list of parameters *)  
END_VAR
```

**stDpv1Parameter**: Array of 39 parameters to be added to the DPV1 read telegram (type: [ST\_Dpv1ParamAddrEx](ms-xhelp:///?Id=beckhoff-9a8b-431a-966f-b96159493f14)).

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86) | Beckhoff EL6632 | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
