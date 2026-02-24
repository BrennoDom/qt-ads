# Samples

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. Samples

# Samples

|  |  |
| --- | --- |
| 1660480 | Update: Tc3\_IPCDiag libraryk  he TwinCAT 3 PLC library Tc2\_MDP is the predecessor to Tc3\_IPCDiag. With the new Tc3\_IPCDiag library the number of readable parameters has been increased and the user interface has been optimized. It is recommended to use the [Tc3\_IPCDiag library](https://infosys.beckhoff.de/index.php?content=../content/1033/tcplclib_tc3_ipcdiag/9007200729562635.html). Future extensions will no longer be performed in the Tc2\_MDP library. It is not recommended to use the Tc2\_MDP library for new projects. All functionalities of the Tc2\_MDP library can also be found in the new Tc3\_IPCDiag library. |

The section [Querying CPU data (generic)](ms-xhelp:///?Id=beckhoff-2f62-4420-a862-28bd6bdb1935) describes a sample program for reading the CPU data of the IPC diagnostics via the generic function block FB\_MDP\_ReadElement. It is designed in such a way that it can be easily extended with the basic knowledge of the MDP information model for access to other IPC diagnosis modules. The sample for [Querying the fan status (generic)](ms-xhelp:///?Id=beckhoff-867a-4d03-a5aa-d9bdd3ab68e1) is based on the sample program for querying the CPU data.

The section [Querying CPU data (specific)](ms-xhelp:///?Id=beckhoff-1801-4b92-bfa2-515f342c3357) describes a sample program for reading the CPU data of the IPC diagnostics via the specific function block FB\_MDP\_CPU\_Read. The sample cannot be extended for access to other IPC diagnostic modules, e.g. fan data.

Further sample programs are described in the sections [Reading IPC serial numbers](ms-xhelp:///?Id=beckhoff-07eb-450f-853d-70aa66ae6ea0) and [Setting the IP address](ms-xhelp:///?Id=beckhoff-a294-49d5-a38c-1f82fb65edb5).

Further Information

* [Querying CPU data (generic)](ms-xhelp:///?Id=beckhoff-2f62-4420-a862-28bd6bdb1935)
* [Querying CPU data (specific)](ms-xhelp:///?Id=beckhoff-1801-4b92-bfa2-515f342c3357)
* [Querying the fan state (generic)](ms-xhelp:///?Id=beckhoff-867a-4d03-a5aa-d9bdd3ab68e1)
* [Reading IPC serial numbers](ms-xhelp:///?Id=beckhoff-07eb-450f-853d-70aa66ae6ea0)
* [Setting the IP address](ms-xhelp:///?Id=beckhoff-a294-49d5-a38c-1f82fb65edb5)

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
