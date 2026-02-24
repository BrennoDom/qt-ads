# FB_Send_RPS_SwitchAuto

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# FB\_Send\_RPS\_SwitchAuto

![30479771](/tcplclib_tc2_enocean/1033/Images/gif/173386379__en-US__Web.gif)

This block sends EnOcean telegrams in the format of a button. The value of *bData* is sent with a positive edge of *bStart*. The signal "Release button" is sent once the time *t\_SwitchDelay* has elapsed.

## VAR\_INPUT

```
bStart        : BOOL;  
bData         : BOOL;  
by_Node       : BYTE;  
t_SwitchDelay : TIME := T#100ms;  
nRockerID     : INT;  
nEnOceanID    : BYTE;  
str_KL6581    : STR_KL6581;
```

**bStart:** A rising edge sends the data.

**bData:** Value to be transmitted.

**by\_Node:** Address of the KL6583 module to which the telegram is to be sent (valid values: 1...8).

**t\_SwitchDelay:** How long the button has to be pressed.

**nRockerID:** Button number, valid values 0 to 3.

**nEnOceanID:** Virtual EnOcean ID. A value of 0…127 is added to the real EnOcean ID (valid values: 0...127).

**str\_KL6581:** Is linked with the data structure of block [FB\_KL6581()](ms-xhelp:///?Id=beckhoff-45e5-4533-98ae-900c39c9c4dc) (see [STR\_KL6581](ms-xhelp:///?Id=beckhoff-5a94-43ed-9608-18055618a879)).

## VAR\_OUTPUT

```
bBusy    : BOOL;  
bError   : BOOL;  
iErrorID : E_KL6581_Err;
```

**bBusy:** The block is active. No new data can be sent at this stage.

**bError:** this output goes TRUE as soon as an error occurs. This error is described via the *iErrorId* variable.

**iErrorID:** Describes the error type (see [E\_KL6581\_Err](ms-xhelp:///?Id=beckhoff-3415-4c23-8a89-721c05c3fbe1)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
