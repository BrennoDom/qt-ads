# FB_EL6851Communication

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# FB\_EL6851Communication

![15834086](/tcplclib_tc2_dmx/1033/Images/gif/9007199309948043__en-US__Web.gif)

|  |  |
| --- | --- |
| 8289053 | Outdated  This function block is outdated. Use [FB\_EL6851CommunicationEx()](ms-xhelp:///?Id=beckhoff-6a9b-4d50-8a01-d179a95958e3) instead. |

The EL6851 should always be accessed via this block. This applies both to the transmission of the cyclic DMX data and to the transmission of the RDM commands.

If data is to be transmitted cyclically to the DMX devices, then set the *bEnableSendingData* input to TRUE, the *bSetCycleMode* input to TRUE, the *bSendDefaultData* input to FALSE and the *uiDataLength* input to the corresponding length (in bytes). The data to be transmitted can be specified via the *arrProcessData* variable.

If RDM commands are to be transmitted, then set the *bEnableSendingData* input to FALSE and the *bSetCycleMode* input to FALSE. The blocks for the DMX/RDM commands do not directly access the EL6851 process image, but store the individual DMX/RDM commands in a buffer instead. The FB\_EL6851Communication() block reads the commands sequentially from this buffer and forwards them to the EL6851. This prevents multiple blocks accessing the EL6851 process image at the same time. The buffer in which the DMX/RDM commands are stored is contained in a variable of type ST\_DMXCommandBuffer. There is one instance of the FB\_EL6851Communication() block and one variable of type ST\_DMXCommandBuffer per EL6851.

The extent to which the buffer is utilized can be determined from the outputs of the block. If the buffer is regularly overflowing, you should analyze the level of utilization of the PLC task with the aid of the TwinCAT System Manager.

The function block FB\_EL6851Communication() can be called in a separate faster task, if necessary. In this case, the faster task in which the FB\_EL6851Communication() block is called should have a higher priority than the TASK in which the block for the RDM commands is called.

Examples for both operating modes can be found in the appendix.

## Remarks concerning the IDs of DMX devices

Each DMX device has a unique, fixed, 48-bit long address, also called Unique ID or UID for short. This address is composed of the manufacturer ID (16-bit) and the device ID (32-bit). The manufacturer ID identifies the manufacturer of the device and is issued by the ESTA ([Entertainment Services and Technology Association](http://www.esta.org)). A list of all known manufacturer IDs can be found at [http://www.esta.org/tsp/working\_groups/CP/mfctrIDs.php](http://www.esta.org). The device ID is freely specified by the manufacturer. This is intended to ensure that each UID exists only once worldwide. The UID cannot normally be changed. The ESTA has given Beckhoff Automation the manufacturer ID 0x4241. Since the DMX master also has a UID, this should be specified in accordance with the ESTA (*wSourceManufacturerId* input).

## VAR\_INPUT

```
wSourceManufacturerId : WORD := 16#42_41;  
dwSourceDeviceId      : DWORD := 16#12_13_14_15;  
bEnableSendingData    : BOOL := TRUE;  
bSetCycleMode         : BOOL := TRUE;  
bSendDefaultData      : BOOL;  
uiDataLength          : UINT;  
dwOptions             : DWORD;
```

**wSourceManufacturerId:** Unique manufacturer Id of the DMX device. Should be 0x4241 according to the ESTA.

**dwSourceDeviceId:** Unique device Id of the DMX device. Can be freely assigned.

**bEnableSendingData:** If the terminal is in cycle mode (CycleMode output = TRUE), then transmission can be activated (TRUE) or blocked (FALSE) with this block.

**bSetCycleMode:** Activates the cycle mode. The cyclic process data can be transmitted to the DMX devices in cycle mode. Cycle mode must be deactivated in order to transmit the RDM/DMX commands.

**bSendDefaultData:** The standard values will be transmitted in cycle mode if this input is active (TRUE).

**uiDataLength:** This input is only relevant if cycle mode is active. It indicates the length of the DMX512 frame in bytes.

**dwOptions:** Options (currently not used).

## VAR\_OUTPUT

```
bError                     : BOOL;  
udiErrorId                 : UDINT;  
bCycleMode                 : BOOL;  
byBufferDemandMeter        : BYTE;  
byBufferMaximumDemandMeter : BYTE;  
uiBufferOverflowCounter    : UINT;  
bLineIsBusy                : BOOL;
```

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *udiErrorId*. Only valid if *bBusy* is FALSE.

**udiErrorId:** Contains the command-specific error code of the most recently executed command. Only valid if *bBusy* is FALSE (see [error codes](ms-xhelp:///?Id=beckhoff-7467-42b5-96f4-eb6c6efdbb2f)).

**bCycleMode:** Is TRUE if cycle mode is active (see also *bSetCycleMode* input).

**byBufferDemandMeter:** Occupancy of the respective buffer (0 - 100%).

**byBufferMaximumDemandMeter:** previous maximum occupancy of the respective buffer (0 - 100%).

**uiBufferOverflowCounter:** Number of buffer overflows to date.

**bLineIsBusy:** This output is set as long as the FB\_EL6851Communication() block is processing DMX/RDM commands.

## VAR\_IN\_OUT

```
stEL6851InData  : ST_EL6851InData;  
stEL6851OutData : ST_EL6851OutData;  
stCommandBuffer : ST_DMXCommandBuffer;  
arrProcessData  : ARRAY [1..512] OF BYTE;
```

**stEL6851InData:** Structure in the EL6851 input process image. It is used for communication between the EL6851 and the PLC (see [ST\_EL6851InData](ms-xhelp:///?Id=beckhoff-704b-4c86-93bf-311ddb3da2c8)).

**stEL6851OutData:** Structure in the EL6851 output process image. It is used for communication between the PLC and the EL6851 (see [ST\_EL6851OutData](ms-xhelp:///?Id=beckhoff-328e-47de-9cc1-599ac43987c4)).

**stCommandBuffer:** reference to the structure for communication (buffer) with the [FB\_KL6851Communication()](ms-xhelp:///?Id=beckhoff-e0f5-4e32-bcef-0f966cb91ec9) function block (see [ST\_DMXCommandBuffer](ms-xhelp:///?Id=beckhoff-b046-4e82-a9e9-879db0644a35)).

**arrProcessData:** The data that are to be transmitted cyclically to the DMX devices are transferred to the block via this variable. Cycle mode must be active for this to take place (see also *bSetCycleMode* input).

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
