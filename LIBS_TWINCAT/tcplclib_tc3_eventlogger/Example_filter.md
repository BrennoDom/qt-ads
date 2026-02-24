# Example filter

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# Example filter

This sample illustrates the application of the TwinCAT 3 EventLogger for receiving messages. The focus is on the filter functions in order to process the right messages in a targeted manner.

Download: [Tc3EventLogger\_FilterSample.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc3_eventlogger/Resources/zip/10400437387.zip)

The sample has four components:

* A number of different messages are sent, demonstrating the selection of messages in different filters.
* One component shows how to discard from the cache messages that are specified by a filter.
* Another component illustrates the export of cached messages to a CSV file. Here, too, the filters are used to program which messages are to be selected.
* Another component illustrates the general principle of receiving messages sent in real-time and receiving of EtherCAT emergency messages.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024.17 | PC or CX (x64, x86, ARM) | Tc3\_EventLogger (>= v3.1.27.0) |
