# F_IOPortWrite

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [I/O port access](ms-xhelp:///?Id=beckhoff-d412-4c54-83d8-aeba44740875)
4. F\_IOPortWrite

# F\_IOPortWrite

![48268995](/tcplclib_tc2_system/1033/Images/png/18014398540828555__Web.png)

The function F\_IOPortWrite can be used to write to an I/O position with a width of eSize. See also description of the [F\_IOPortRead](ms-xhelp:///?Id=beckhoff-9617-4ab4-9104-1144027677af) function.

Note

Hardware damage

A direct hardware access is not a problem, as long as data is only read. Write access can result in crashes and/or destroy the hardware or the data on the storage media. This function can damage the hardware to such an extent that it is no longer bootable.

## FUNCTION F\_IOPortWrite : BOOL

```
VAR_INPUT  
    nAddr  : UDINT;  
    eSize  : E_IOAccessSize;  
    nValue : DWORD;  
END_VAR
```

**nAddr**: I/O Port address.

**eSize**: [Number of data bytes](ms-xhelp:///?Id=beckhoff-d76e-4614-835e-a2a0d0a0341d) to be written.

**nValue**: Value to be written.

| Return value | Description |
| --- | --- |
| TRUE | No error |
| FALSE | Error |

**Sample code in ST:**

In the following example a PLC Function block for direct control of a PC speaker is implemented with the aid of the I/O -Port functions.

Interface:

```
FUNCTION_BLOCK FB_Speaker  
(* Sample code from: "PC INTERN 2.0", ISBN 3-89011-331-1, Data Becker *)  
VAR_INPUT  
    freq     : DWORD := 10000; (* Frequency [Hz] *)  
 tDuration   : TIME := T#1s; (* Tone duration *)  
    bExecute : BOOL; (* Rising edge starts function block execution *)  
END_VAR  
VAR_OUTPUT  
    bBusy  : BOOL;  
    bError : BOOL;  
    nErrID : UDINT;  
END_VAR  
VAR  
    fbTrig : R_TRIG;  
    nState : BYTE;  
    sts61H : DWORD;  
    cnt42H : DWORD;  
    cntLo  : DWORD;  
    cntHi  : DWORD;  
    timer  : TON;  
END_VAR
```

Implementation:

```
fbTrig( CLK := bExecute );  
CASE nState OF  
0:  
IF fbTrig.Q THEN  
    bBusy := TRUE;  
    bError := FALSE;  
    nErrID := 0;  
    timer( IN := FALSE );  
  
    IF F_IOPortWrite( 16#43, NoOfByte_Byte, 182 ) THEN  
  
        cnt42H := 1193180 / freq;  
        cntLo := cnt42H AND 16#FF;  
        cntHi := SHR( cnt42H, 8 ) AND 16#FF;  
  
        F_IOPortWrite( 16#42, NoOfByte_Byte, cntLo ); (* LoByte *)  
        F_IOPortWrite( 16#42, NoOfByte_Byte, cntHi ); (* HiByte *)  
  
        timer( IN := TRUE, PT := tDuration );  
  
        sts61H := F_IOPortRead( 16#61, NoOfByte_Byte );  
        sts61H := sts61H OR 2#11;  
        F_IOPortWrite( 16#61, NoOfByte_Byte, sts61H ); (* speaker ON *)  
  
        nState := 1;  
    ELSE  
        nState := 100;  
    END_IF  
END_IF  
  
1:  
timer( );  
IF timer.Q THEN  
  
    sts61H := F_IOPortRead( 16#61, NoOfByte_Byte );  
    sts61H := sts61H AND 2#11111100;  
    F_IOPortWrite( 16#61, NoOfByte_Byte, sts61H ); (* speaker off *)  
    bBusy := FALSE;  
    nState := 0;  
END_IF  
  
100:  
bBusy := FALSE;  
bError := TRUE;  
nErrID := 16#8000;  
nState := 0;  
  
END_CASE  
   
Test application:  
  
PROGRAM MAIN  
VAR  
    fbSpeaker : FB_Speaker;  
    bStart : BOOL;  
END_VAR  
   
  
fbSpeaker( freq:= 5000,  
tDuration:= t#1s,  
bExecute:= bStart );
```

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
