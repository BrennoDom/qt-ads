# Overview

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [Expanded ADS function blocks](ms-xhelp:///?Id=beckhoff-e61a-44cc-ad9b-6f5534fc93c0)
4. Overview

# Overview

The expanded ADS function blocks make it possible to create a client-server communication between an ADS device and a PLC task. With the ADS device it can be a case of a Windows application (uses the AdsDLL/AdsOcx) or another PLC run-time system. Communication between the ADS device and the PLC task is processed using the following service primitives:

* Request
* Indication
* Response
* Confirmation

Communication between an ADS device and a PLC task proceeds as follows: an ADS device sends a request to the target device (PLC task). This request is registered in the target device by an indication. The target device (PLC task) thereupon carries out a corresponding service. The service to be carried out is encoded via the index-group/offset parameter. Next the PLC sends a response to the ADS device. The response is registered as confirmation by the ADS source device.

Only one instance of the indication and response function block can meaningfully be used per PLC task (one instance of ADSREADIND, ADSREADRES, ADSWRITEIND, ADSWRITERES, ADSRDWRTIND and ADSRDWRTRES ). Corresponding with the available ADS services: READ, WRITE and READ & WRITE there is an appropriate indication or response function block for each service.

## Expanded ADS function blocks

| Service | Name | Description |
| --- | --- | --- |
| READ | [ADSREADIND](ms-xhelp:///?Id=beckhoff-acb7-4e42-9597-04eceb756e88) | ADSREAD-Indication. |
| [ADSREADRES](ms-xhelp:///?Id=beckhoff-520f-4a5f-af41-00b24055b72d) | ADSREAD-Response |
| WRITE | [ADSWRITEIND](ms-xhelp:///?Id=beckhoff-0914-4a6d-a6d4-7c012e1fa0bc) | ADSWRITE-Indication |
| [ADSWRITERES](ms-xhelp:///?Id=beckhoff-0928-434d-a060-a06dd97eeaec) | ADSWRITE-Response |
| READ & WRITE | [ADSRDWRTIND](ms-xhelp:///?Id=beckhoff-663a-4da6-baf6-93c855d25a89) | ADS-READ & WRITE-Indication |
| [ADSRDWRTRES](ms-xhelp:///?Id=beckhoff-e9ef-4641-bda5-d8e542e65944) | ADS-READ & WRITE-Response |

The ADS devices are addressed via a port address and a network address (NETID).

Port address of the PLC task = \_TaskInfo.AdsPort

**Comments:**

* In order for a request to be routed to the PLC task, the highest-value bit, e.g. IG:=0x80000001, must be entered in the index group parameter when the request is made.
* Each PLC task has 3 Fifos (ADSREADIND Fifo, ADSWRITEIND Fifo and ADSRDWRTIND Fifo), in which incoming requests (indications) are stored temporarily.  
   Each Fifo can store up to 10 indications until they have been processed (until a response was sent). If, for example, 12 ADSREAD requests are sent to a PLC task simultaneously, 10 requests are stored in the Fifo as indications and two are acknowledged (discarded) with ADS error message 1814 (0x716). In this case, the error code should be analysed and the two failed ADSREAD requests repeated if necessary. The indications are retrieved individually from the associated Fifo by calling the ADSxxxxxxIND instance. Only then can new indications be stored successfully in the Fifo.

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
