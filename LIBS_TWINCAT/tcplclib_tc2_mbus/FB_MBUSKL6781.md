# FB_MBUSKL6781

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [POUs](ms-xhelp:///?Id=beckhoff-22fb-41cd-a51c-d1597d45a6ca)
4. FB\_MBUSKL6781

# FB\_MBUSKL6781

![34566005](/tcplclib_tc2_mbus/1033/Images/gif/174839051__en-US__Web.gif)

This function block is used to read M-Bus devices via the Bus Terminal KL6781.

The block can only be used in conjunction with at least one **counter block**.

An instance of this block required for each KL6781 terminal.

At 2400 baud the maximum **task time** for this block is 10 ms. If higher task times are required, this block must be processed in a separate fast task.

## VAR\_INPUT

```
usiRetries : USINT;  
bStart     : BOOL;  
bDisabled  : BOOL := FALSE;
```

**usiRetries:** Number of repetitions in the event of errors

**bStart:** A positive edge at this input triggers one reading of all meters.

**bDisabled:** TRUE = deselection of the block

## VAR\_OUTPUT

```
bBusy  : BOOL;  
bReady : BOOL;  
bError : BOOL;  
eError : E_MBUS_ERROR;
```

**bBusy:** The *bBusy* output is TRUE while the meter is being read.

**bReady:** The *bReady* output is TRUE for one cycle, once meter reading is completed.

**bError:** this output goes TRUE as soon as an error occurs. This error is described via the variable *eError*.

**eError:** In the event of an error the output issues an error code (see [E\_MBUS\_ERROR](ms-xhelp:///?Id=beckhoff-4cab-465a-91d8-d2f9ff9e69d9)). *bError* goes TRUE at the same time.

## VAR\_IN\_OUT

```
stComIn  : ST_KL6781inData22B;  
stComOut : ST_KL6781outData22B;  
stCom    : ST_MBUS_Communication;
```

**stComIn:** Process image of the inputs (see [ST\_KL6781inData22B](ms-xhelp:///?Id=beckhoff-3864-4b56-a8e1-e0e0bc651d5b)).

**stComOut:** Process image of the outputs (see [ST\_KL6781outData22B](ms-xhelp:///?Id=beckhoff-acb7-4dc6-ba15-ec9ae0ee390e)).

**stCom:** This structure is used to link the block with the meter blocks (see [ST\_MBUS\_Communication](ms-xhelp:///?Id=beckhoff-c554-4dbc-b2f4-dac10e7c746d)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MBus from 3.3.4.0 |

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
