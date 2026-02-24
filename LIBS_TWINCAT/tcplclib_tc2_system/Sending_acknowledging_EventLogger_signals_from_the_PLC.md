# Sending/acknowledging EventLogger signals from the PLC

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Samples](ms-xhelp:///?Id=beckhoff-de33-4d86-9a67-3b99efbaded7)
3. Sending/acknowledging EventLogger signals from the PLC

# Sending/acknowledging EventLogger signals from the PLC

The example demonstrates the use of the ADSLOGEVENT function block.

The complete sources for the example application can be unpacked here: [AdsLogEventExample.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_system/Resources/zip/711421451__en-US.zip)

## Step by step sequence

**Configuration of an event:**

Parameterisation of [EventConfigData](ms-xhelp:///?Id=beckhoff-bac3-4d2a-abb0-b049c48a76c8) structure

**Transfer of parameters:**

Generate an address of a structure, an array or a single variable with ADR operator at EventDataAddress. Determine the length of the structure, array or single variable using the SIZEOF operator and apply it to the EventDataLength input. If, for example, a structure with an INT and an LREAL variable is to be transferred with the event, then a structure must be created with these two components and instanced. The address and the length of this instance must be transferred.

**Setting an event:**

Rising edge at the Event input

**Resetting an event:**

Falling edge at the Event input

**To acknowledge an events:**

Rising edge at the Quit input

**Complete deletion of the instance:**

The contents of the instance are completely deleted with a rising edge at the FbCleanup input. An existing event from the EventLogger is not directly deleted by this.

After an event has been sent to the EventLogger, the [status of the event](ms-xhelp:///?Id=beckhoff-c946-481f-b039-a29293e727aa) changes visibly at the Eventstate output.

## Calling the ADSLOGEVENT function block

```
PROGRAM MAIN  
VAR  
    FB_Event1   : ADSLOGEVENT;  
    CfgEvent    : TcEvent;  
    Eventdata   : ParaStruct;  
    EventState  : UDINT;  
    bEvent      : BOOL;  
    bQuit       : BOOL;           
END_VAR  
VAR CONSTANT  
    TCEventDataFormatString : STRING:='%f%d';  
    TcEventTimeOut     : TIME:=T#1s;  
END_VAR
```

![48735027](/tcplclib_tc2_system/1033/Images/png/31285771__en-US__Web.png)

## Declaration Part

```
PROGRAM MAIN  
VAR  
    CfgEvent                : TcEvent;  
    fbEvent                 : ADSLOGEVENT;  
    bSetEvent               : BOOL;(* Rising edge sets event *)  
  
    eventData               : ST_EventData;  
    TcEventDataFormatString : STRING    := '%f%d';  
END_VAR
```

## Implementation

```
CfgEvent.Class := TCEVENTCLASS_ALARM;  
CfgEvent.Prio := 2;  
CfgEvent.Id := 1;  
CfgEvent.SourceId := 100;  
CfgEvent.bQuitRequired := TRUE;  
CfgEvent.DataFormatStrAddress := ADR(TcEventDataFormatString);  
CfgEvent.Flags := TCEVENTFLAG_LOG OR TCEVENTFLAG_SRCID OR TCEVENTFLAG_AUTOFMTALL;  
CfgEvent.StreamType := TCEVENTSTREAM_SIMPLE;  
CfgEvent.ProgId :='TcEventFormatter.TcXMLFormatter' ;  
  
eventData.rVal     := 2.65;  
eventData.iVal    := 3;  
  
fbEvent( NETID:= '',  
        PORT:= 110,  
        Event:= bSetEvent,  
        EventConfigData:= CfgEvent,  
        EventDataAddress := ADR(eventData) ,  
        EventDataLength := SIZEOF(eventData),  
        TMOUT:= t#3s);
```

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
