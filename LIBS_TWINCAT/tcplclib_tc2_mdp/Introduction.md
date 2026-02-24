# Introduction

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. Introduction

# Introduction

|  |  |
| --- | --- |
| 45484537 | Update: Tc3\_IPCDiag libraryk  he TwinCAT 3 PLC library Tc2\_MDP is the predecessor to Tc3\_IPCDiag. With the new Tc3\_IPCDiag library the number of readable parameters has been increased and the user interface has been optimized. It is recommended to use the [Tc3\_IPCDiag library](https://infosys.beckhoff.de/index.php?content=../content/1033/tcplclib_tc3_ipcdiag/9007200729562635.html). Future extensions will no longer be performed in the Tc2\_MDP library. It is not recommended to use the Tc2\_MDP library for new projects. All functionalities of the Tc2\_MDP library can also be found in the new Tc3\_IPCDiag library. |

The TwinCAT 3 PLC library Tc2\_MDP is used by the Beckhoff IPC diagnostics. Details can be found in the documentation: [Beckhoff Device Manager](https://infosys.beckhoff.com/content/1033/devicemanager/index.html).

The available IPC diagnosis data are organized in the configuration area in so-called "Modules". A module contains all the data for a particular topic. The example applies to the IPC CPU.

![6707649](/tcplclib_tc2_mdp/1033/Images/png/2181765515__Web.png)

A module can in turn contain subcategories, so-called "Tables". A table organizes the detailed information that it contains in so-called "subindices". Since the contents of the list depend on the components existing in the current IPC, the list is generated dynamically – depending on what components the current PC contains, or what types of information it supports.

Example: Access to data on the mainboard requires a BIOS (and the corresponding hardware in the PC) that can supply these data.

A module therefore cannot be addressed via a fixed address. You first have to determine where exactly the module is located.

|  |  |
| --- | --- |
| 60368847 | Restricted access at the time of system start  MDP forms an interface to the hardware. This is independent of TwinCAT. MDP can be accessed from TwinCAT with the PLC library. This is done internally by means of ADS communication. The versatility of the hardware configuration justifies a different initialization phase of the MDP service. It is possible that first PLC cycles are executed while the MDP initialization is not yet completed.  Either the possible error outputs as well as timeouts of the function blocks from the library can be reacted and a new query can be triggered or the queries are executed deliberately delayed after the system start. It is recommended in the PLC program not to query values from the MDP immediately after the system start, but to consider a small waiting time. How large this should be depends on various parameters (such as the performance of your control computer), and can therefore not be given as a general rule. Typically it is in the range of 10-60 seconds. |

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
