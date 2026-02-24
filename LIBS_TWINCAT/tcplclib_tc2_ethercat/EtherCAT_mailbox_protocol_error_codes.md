# EtherCAT mailbox protocol error codes

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Constants](ms-xhelp:///?Id=beckhoff-8c57-465e-a61b-d1685692b31b)
3. EtherCAT mailbox protocol error codes

# EtherCAT mailbox protocol error codes

## VAR\_GLOBAL CONSTANT

```
(* FoE mailbox protocol error codes *)  
EC_FOE_PROTERR_NOTDEFINED      : UDINT := 0;  
EC_FOE_PROTERR_NOTFOUND        : UDINT := 1;  
EC_FOE_PROTERR_ACCESS          : UDINT := 2;  
EC_FOE_PROTERR_DISKFULL        : UDINT := 3;  
EC_FOE_PROTERR_ILLEAGAL        : UDINT := 4;  
EC_FOE_PROTERR_PACKENO         : UDINT := 5;  
EC_FOE_PROTERR_EXISTS          : UDINT := 6;  
EC_FOE_PROTERR_NOUSER          : UDINT := 7;  
EC_FOE_PROTERR_BOOTSTRAPONLY   : UDINT := 8;  
EC_FOE_PROTERR_NOTINBOOTSTRAP  : UDINT := 9;  
EC_FOE_PROTERR_INVALIDPASSWORD : UDINT := 10;  
  
  
(* CoE mailbox protocol error codes *)  
EC_COE_PROTERR_TOGGLE : UDINT := 16#05030000; (* Toggle bit not alternated. *)  
EC_COE_PROTERR_TIMEOUT : UDINT := 16#05040000; (* SDO protocol timed out. *)  
EC_COE_PROTERR_CCS_SCS : UDINT := 16#05040001; (* Client/server command specifier not valid or unknown. *)  
EC_COE_PROTERR_BLK_SIZE : UDINT := 16#05040002; (* Invalid block size (block mode only). *)  
EC_COE_PROTERR_SEQNO : UDINT := 16#05040003; (* Invalid sequence number (block mode only). *)  
EC_COE_PROTERR_CRC : UDINT := 16#05040004; (* CRC error (block mode only). *)  
EC_COE_PROTERR_MEMORY : UDINT := 16#05040005; (* Out of memory. *)  
EC_COE_PROTERR_ACCESS : UDINT := 16#06010000; (* Unsupported access to an object. *)  
EC_COE_PROTERR_WRITEONLY : UDINT := 16#06010001; (* Attempt to read a write only object. *)  
EC_COE_PROTERR_READONLY : UDINT := 16#06010002; (* Attempt to write a read only object. *)  
EC_COE_PROTERR_INDEX : UDINT := 16#06020000; (* Object does not exist in the object dictionary. *)  
EC_COE_PROTERR_PDO_MAP : UDINT := 16#06040041; (* Object cannot be mapped to the PDO. *)  
EC_COE_PROTERR_PDO_LEN : UDINT := 16#06040042; (* The number and length of the objects to be mapped would exceed PDO length. *)  
EC_COE_PROTERR_P_INCOMP : UDINT := 16#06040043; (* General parameter incompatibility reason. *)  
EC_COE_PROTERR_I_INCOMP : UDINT := 16#06040047; (* General internal incompatibility in the device. *)  
EC_COE_PROTERR_HARDWARE : UDINT := 16#06060000; (* Access failed due to an hardware error. *)  
EC_COE_PROTERR_DATA_SIZE : UDINT := 16#06070010; (* Data type does not match, length of service parameter does not match *)  
EC_COE_PROTERR_DATA_SIZE1 : UDINT := 16#06070012; (* Data type does not match, length of service parameter too high *)  
EC_COE_PROTERR_DATA_SIZE2 : UDINT := 16#06070013; (* Data type does not match, length of service parameter too low *)  
EC_COE_PROTERR_OFFSET : UDINT := 16#06090011; (* Sub-index does not exist. *)  
EC_COE_PROTERR_DATA_RANGE : UDINT := 16#06090030; (* Value range of parameter exceeded (only for write access). *)  
EC_COE_PROTERR_DATA_RANGE1 : UDINT := 16#06090031; (* Value of parameter written too high. *)  
EC_COE_PROTERR_DATA_RANGE2 : UDINT := 16#06090032; (* Value of parameter written too low. *)  
EC_COE_PROTERR_MINMAX : UDINT := 16#06090036; (* Maximum value is less than minimum value. *)  
EC_COE_PROTERR_GENERAL : UDINT := 16#08000000; (* general error *)  
EC_COE_PROTERR_TRANSFER : UDINT := 16#08000020; (* Data cannot be transferred or stored to the application. *)  
EC_COE_PROTERR_TRANSFER1 : UDINT := 16#08000021; (* Data cannot be transferred or stored to the application because of local control. *)  
EC_COE_PROTERR_TRANSFER2 : UDINT := 16#08000022; (* Data cannot be transferred or stored to the application because of the present device state. *)  
EC_COE_PROTERR_DICTIONARY : UDINT := 16#08000023; (* Object dictionary dynamic generation fails or no object dictionary is present (e.g. object dictionary is generated from file and generation fails because of an file error). *)
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
