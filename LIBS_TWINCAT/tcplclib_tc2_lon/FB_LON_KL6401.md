# FB_LON_KL6401

## Library
tcplclib_tc2_lon

## Category
Motion Control

# FB\_LON\_KL6401

![55844233](/tcplclib_tc2_lon/1033/Images/gif/150495371__en-US__Web.gif)

## Application

This function block is used for sending / receiving LON SNVTs via Bus Terminal KL6401. An instance of this block is required for each terminal. One instance can send or receive up to 62 SNVTs.

The FB must be tied to the send/receive blocks via the VAR\_IN\_OUT structure [stLON\_Com](ms-xhelp:///?Id=beckhoff-2ad7-4b6a-944d-a82a3e3847ef).

Restrictions:

* This function block may only be called once for each KL6401!
* It must be called in the same task as the send and receive function blocks!
* In the PLC project this block may only be called once per cycle!

## VAR\_INPUT

```
bResetMaxBuffer : BOOL;  
bDisabled       : BOOL := FALSE;
```

**bResetMaxBuffer:** Deletes the value *rMaxBuffer* for the maximum utilization of the send buffer.

**bDisabled:** TRUE = deselection of the block.

## VAR\_OUTPUT

```
bReady      : BOOL;  
bBusy       : BOOL;  
bTimeOut    : BOOL;  
bError      : BOOL;  
eError      : E_LON_ERROR;  
dwErrorKL   : DWORD;  
byLONState  : BYTE;  
stKL6401    : ST_KL6401;  
arrNeuronID : ARRAY [0..5] OF BYTE;  
arrProgID   : ARRAY [0..7] OF BYTE;  
wFW         : WORD;  
byActBuffer : BYTE;  
rActBuffer  : REAL;  
rMaxBuffer  : REAL;
```

**bReady:** The initialization is complete.

**bBusy:** The output is TRUE as long as values are sent.

**bTimeOut:** Timeout during initialization.

**bError:** This output goes TRUE as soon as an error occurs. This error is described via the variable *eError*.

**eError:** This output outputs an error code in the event of an error (see [E\_LON\_ERROR](ms-xhelp:///?Id=beckhoff-ad05-4d5c-a4ac-eed1f05a18f2)). *bError* goes TRUE at the same time.

**dwErrorKL:**  [Error ID](ms-xhelp:///?Id=beckhoff-7966-45a6-ae22-1bf539925dd5) of the function block. In this case the variable *eError* has the value "eKL6401\_Error". bError goes TRUE at the same time.

**byLONState:** LON status.

**stKL6401:** Structure for the configuration (for future applications) (see [ST\_KL6401](ms-xhelp:///?Id=beckhoff-9b5a-4da5-aa2a-d08b8536eb34)).

**arrNeuronID:** Neuron ID of the terminal (supported from firmware 4C).

**arrProgID:** Program ID of the terminal (supported from firmware 4C).

**wFW:** Terminal firmware (supported from firmware 4C).

**byActBuffer:** Number of instructions in the send buffer.

**rActBuffer:** Current utilization of the send buffer in percent.

**rMaxBuffer:** Maximum utilization of the send buffer in percent. The value can be cancelled with the input variable *bResetMaxBuffer*.

## VAR\_IN\_OUT

```
stParameter_IN         : ST_LON_Parameter_IN_36B;  
stParameter_OUT        : ST_LON_Parameter_OUT_36B;  
stLON_Com              : ST_LON_Communication;
```

**stParameter\_IN :** Input variable of the hardware (see [ST\_LON\_Parameter\_IN\_36B](ms-xhelp:///?Id=beckhoff-0ba5-4029-a0b0-b0c0cf8a1688)).

**stParameter\_OUT :** Output variable of the hardware (see [ST\_LON\_Parameter\_OUT\_36B](ms-xhelp:///?Id=beckhoff-6069-47e0-ba59-c455c7544910)).

**stLON\_Com :** This structure is used to link the function block with the send/receive function blocks (see [ST\_LON\_Communication](ms-xhelp:///?Id=beckhoff-2ad7-4b6a-944d-a82a3e3847ef)). The actual sending and receiving is realized in this function block. The send/receive blocks only deal with preparation/evaluation of the data.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
