# EIB

## Library
tcplclib_tc2_eib

## Category
Motion Control

# EIB

Working with the EIB Bus Terminal requires function blocks, which are described in this documentation.

Three different modes are available from firmware version B1 and library V3, which can be enabled in the KL6301 function block.

Mode 0: 4 filters, each with 64 group entries (compatible with firmware B0 )

Mode 1: 8 filters, each with 32 group entries

Mode 2: 8 filters, each with 32 inverted group entries

Mode 100: Monitor function (all group address telegrams can be received, the KL6301 sends no ACK). Sending is disabled in this mode.

|  |  |
| --- | --- |
| 32841145 | Mode 1 and 100  Mode 1 and 100 can only be used with the basic function blocks from the Tc2\_EIB library. |

## Sending

The KL6301 sends data individually. This means that a Data variable sent to the KL6301 is sent to the EIB network individually. Subsequent EIB data can only be transferred to the KL6301 after a successful transfer. Two types of EIB telegrams can be sent:

* WRITE\_GROUP for writing data to other EIB devices
* READ\_GROUP\_REQ for requesting data from other EIB devices

## Receiving

The KL6301 has a maximum of 8 filter addresses. These filters filter the EIB group addresses. Only EIB telegrams entered in the filter are visible in the process image and are acknowledged.

A filter may contain up to 64 group addresses. With 4 filters multiplied with 64 entries a total of 256 group addresses are available. With 8 filters multiplied with 32 entries a total of 256 group addresses are available. The system is configured via a function block. The group addresses are loaded and are immediately active when the Bus Terminal is initialized.

At least one filter has to be parameterized. The data type is not significant for the filter setting.

## Monitor function

No filters must be set if mode 100 is enabled. The filters EIB\_GROUP\_FILTER are simply left empty and not written.
