# Priorities

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [DALI](ms-xhelp:///?Id=beckhoff-7090-4d8c-9e10-2e356c321516)
3. Priorities

# Priorities

Since DALI-2 is a multi-master bus system, simultaneous bus access of several DALI masters is controlled based on priorities. According to IEC 62386, all DALI-2 devices that can initiate sending of a DALI command (controllers) or sending of an event (input devices) on the DALI bus are referred to as masters. Under DALI-2, these are also referred to as control devices and are described in more detail in IEC 62386-103.

All DALI-2 devices of a DALI line must share the same data line. To avoid collisions during sending, the sending device checks whether the DALI bus has already been assigned. Sending takes place after a certain waiting time (settling time), once the DALI bus is free. For high-priority DALI commands the bus access takes place after a short waiting time, for low-priority commands the waiting time is longer. In other words, high-priority DALI commands are given preference over low-priority DALI commands.

DALI control gears are defined in IEC 62386-102. They are not capable of sending DALI commands or events independently. DALI control gears may only return the 8-bit backward frame to forward frames sent by a DALI controller (see also [Communication](ms-xhelp:///?Id=beckhoff-fc2e-4a51-b7bb-f4046e6f3fc0)). Since a DALI controller waits for the backward frame, the 8-bit backward frame has the shortest waiting time. This waiting time is shorter than for DALI commands with the highest priority. This means that DALI forward frames can be processed without interference from other DALI commands.

The priorities used by a DALI controller for sending the DALI commands are referred to as command priorities and are mapped by the data type [E\_DALICommandPriority](ms-xhelp:///?Id=beckhoff-0df2-4cc5-8ea6-5c4eb6040cf5). Command priorities can have 5 different values:

* **Low**: DALI-2 priority 5
* **Middle low**: DALI-2 priority 4
* **Middle**: DALI-2 priority 3
* **Middle high**: DALI-2 priority 2
* **High**: DALI-2 priority 1

Most function blocks referred to in chapter [Part 102 (control gears)](ms-xhelp:///?Id=beckhoff-4b6c-4c81-97bd-55dd3a8527c6) have the input *eCommandPriority*. This input is used to specify the priority with which the DALI commands are to be sent via the KL6821.

Events also have a priority (event priority), which is represented by the data type [E\_DALIEventPriority](ms-xhelp:///?Id=beckhoff-316e-4561-a92e-ebe8e78697d1). Event priorities can have 4 values in the range *Low* (DALI-2 priority 5) to *Middle high* (DALI-2 priority 2). The event priority is written as a parameter (see instance variable [Instance variables](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470)) into the respective instances of the DALI devices.

Priority *High* (DALI-2 priority 1) is only allowed for DALI-2 commands and cannot be used for events.

Tc3\_DALI uses the following default values for the priorities:

| **E\_DALICommandPriority/** **E\_DALIEventPriority** | **Application** |
| --- | --- |
| Low | - |
| MiddleLow | Light sensor events (Part 304).  All other DALI commands. |
| Middle | Events of push buttons (Part 301), absolute input devices (Part 302) and occupancy sensors (Part 303). |
| MiddleHigh | DALI commands for writing parameters and for addressing DALI devices. |
| High | DALI commands for transactions (from the second DALI command). |

When selecting priorities, care should always be taken to ensure that time-critical events that are important for switching the lighting have a higher priority than the DALI commands themselves. Non-system-critical DALI commands, such as the cyclic querying of states for the display in a visualization, should be sent with a lower priority.

Priorities for DALI commands ([E\_DALICommandPriority](ms-xhelp:///?Id=beckhoff-0df2-4cc5-8ea6-5c4eb6040cf5)) are supported from Tc3\_DALI V3.5.0.0. The KL6821 must contain firmware BD or later. Older firmware versions always send DALI commands with the priority *High*.

|  |  |
| --- | --- |
| 56487722 | Neither the KL6811 nor the Tc2\_DALI library support priorities for DALI commands. |

Priorities are always important in situations where input devices send events and DALI commands are sent in parallel via the KL6821. If no input devices are used, the priority of the DALI commands is of secondary importance, since in this case there is only one DALI master (the KL6821).

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
