# Long set

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [M-Bus](ms-xhelp:///?Id=beckhoff-da58-4a1f-8f86-2cb29e0d2232)
3. [Bulletin](ms-xhelp:///?Id=beckhoff-867f-4d59-be31-26fe64fe0f45)
4. Long set

# Long set

Data is sent to the M-bus device with a long set. The long set is composed of a maximum of 255 bytes and is transferred to the counter with the [FB\_MBUS\_General\_Send()](ms-xhelp:///?Id=beckhoff-7b44-4f8f-aefc-9ad31e83ecd2) block.

Structure of the protocol:

| Byte | Long set | Description | Assignment in the "FB\_MBUS\_General\_Send" block |
| --- | --- | --- | --- |
| 1 | Start character | 68hex | Is added in the block |
| 2 | L field | Length of user data plus 3 | Is added in the block |
| 3 | L field | Length of user data plus 3 | Is added in the block |
| 4 | Start character | 68hex | Is added in the block |
| 5 | **C field** | Function field | Is transferred to the **"byC\_Field"** input variable |
| 6 | **A field** | Primary address of the M-Bus device | Is transferred to the **"usiAddress"** input variable |
| 7 | **CI Field** | Identifier field | Is transferred to the **"byCI\_Field"** input variable |
| 8..x | **User data (0..240)** | User data | Are transferred to the **‘arrData’** input variable |
| x+1 | Checksum | Checksum | Is added in the block |
| x+2 | Stop character | 16hex | Is added in the block |

Only the bytes marked in bold letters need to be transferred to the block.

The user data in the ‘arrData’ array must contain ‘16hex’ as the last character. It is important to ensure that the subsequent bytes are empty.

**Sample:** Changing the primary address at address 14, old address is 0

(\*Transfer of user data\*)

fbSend.arrData[0]:=16#01; (\*DIF / Data format 8 -bit integer\*)  
fbSend.arrData[1]:=16#7A; (\*VIF / Change address\*)  
fbSend.arrData[2]:=14; (\*New address = 14\*)  
fbSend.arrData[3]:=16#16; (\*Do not transfer stop character/checksum; they will be calculated in the block\*)

fbSend.byC\_Field:=16#53; (\*C field\*)   
fbSend.byCI\_Field:=16#51; (\*CI field\*)   
fbSend.usiAddress:=0; (\*Old address\*)

fbSend(iComId:=1, (\*Block call\*)  
bStart:=bStart,  
bInit:=TRUE);

Sending is started with the ‘bStart’ variable.

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
