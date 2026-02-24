# Drive reference ST_DriveRef

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. Drive reference ST\_DriveRef

# Drive reference ST\_DriveRef

The drive is accessed via a drive reference. Within the library, the ST\_DriveRef structure is used for this with the NetID as a string. Since the NetID usually exists as a byte array at I/O level, a structure ST\_PlcDriveRef with the NetID as a byte array is additionally provided. The two structures must be transferred into each other.

## Structure ST\_PlcDriveRef

```
TYPE ST_PlcDriveRef :  
STRUCT  
    aNetId     : T_AmsNetIdArr; (* AmsNetId (array[0..5] of bytes) of the EtherCAT master device.*)  
    nSlaveAddr : UINT; (* Address of the slave device.*)  
    nDriveNo   : BYTE; (* Drive number*)  
    nDriveType : BYTE; (* Drive type*)  
END_STRUCT  
END_TYPE
```

## Structure ST\_DriveRef

```
TYPE ST_DriveRef :  
STRUCT  
    sNetId     : T_AmsNetId; (* AmsNetId (string(23)) of the EtherCAT master device.*)  
    nSlaveAddr : UINT; (* Address of the slave device.*)  
    nDriveNo   : BYTE; (* Drive number*)  
    nDriveType : BYTE; (* Drive type*)  
END_STRUCT  
END_TYPE
```

## Mapping the drive reference to the PLC

The drive reference can be mapped to the PLC in the System Manager. To do this, allocate an instance of the structure ST\_PlcDriveRef as AT %I\*. Subsequently, link aNetID to netId, nSlaveAddr to port and nDriveNo to Chn0 (A) or Chn1 (B). In the case of multiple-channel drives both channels refer to the same netId and port number, since it is an EtherCAT slave.

![33379675](/tcplclib_tc2_drive/1033/Images/png/2362716555__Web.png)

## Transfer of ST\_PlcDriveRef and ST\_DriveRef

The function blocks in the library Tc2\_Drive use an instance of the structure ST\_DriveRef. Unlike the structure ST\_PlcDriveRef, NetID is expected to be T\_AmsNetId (i.e. STRING(23)). To convert the byte array, use the F\_CreateAmsNetId() function of the PLC Lib Tc2\_System.

```
stDriveRef.sNetId     := F_CreateAmsNetId(stPlcDriveRef.aNetId);  
stDriveRef.nSlaveAddr := stPlcDriveRef.nSlaveAddr;  
stDriveRef.nDriveNo   := stPlcDriveRef.nDriveNo;  
stDriveRef.nDriveType := stPlcDriveRef.nDriveType;
```

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
