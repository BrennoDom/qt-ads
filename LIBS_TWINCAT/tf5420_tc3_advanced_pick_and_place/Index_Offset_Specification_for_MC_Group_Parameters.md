# Index Offset Specification for MC Group Parameters

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# Index Offset Specification for MC Group Parameters

Port 501: `AMSPORT_R0_NCSAF: UINT := 501;`.  
The Object ID (OID) of the MC group must be designated as the index group.

| Index offset (Hex) | Access | Group type | Data Type | Phys. unit | Definition range | Description | Comments |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 0x5030084 | Read | MC Group | LREAL | mm | >=0 | Remaining distance of the current segment. | Only available for MC Group with Pick-and-Place from V3.1.6.27 |
| 0x5030085 | Read | MC Group | LREAL | s | >=0 | Remaining time for the current segment. | Only available for MC Group with Pick-and-Place from V3.1.6.27 |
