````markdown
# ST_DriveAddress

```
TYPE ST_DriveAddress :
STRUCT
    NetID               : T_AmsNetId;     (* AMS NetID of the drive as a string *)
    NetIdBytes          : T_AmsNetIdArr;  (* AMS NetID of the drive as a byte array (same information as NetID) *)
    SlaveAddress        : T_AmsPort;      (* slave address of the drive connected to a bus master *)
    Channel             : BYTE;           (* channel number of the drive *)
    {attribute 'hide'}
    _pad1               : ARRAY[0..2] OF BYTE;
    (* new since 2013-04-04 - just available with versions after this date, otherwise zero *)
    NcDriveId           : DWORD;          (* ID [1..255] of the NC software drive of an axis *)
    NcDriveIndex        : DWORD;          (* index [0..9] of the NC software drive of an axis *)
    NcDriveType         : E_NcDriveType;  (* type enumeration of the NC software drive of an axis *)
    NcEncoderId         : DWORD;          (* ID [1..255] of the NC software encoder of an axis *)
    NcEncoderIndex      : DWORD;          (* index [0..9] of the NC software encoder of an axis *)
    NcEncoderType       : E_NcEncoderType;(* type enumeration of the NC encoder drive of an axis *)
    NcAxisId            : DWORD;          (* ID [1..255] of the NC axis *)
    NcAxisType          : E_NcAxisType;   (* type enumeration of the NC axis *)
    (* new since 2016-04-11 - just available with versions after this date, otherwise zero *)
    TcDriveObjectId     : OTCID;
    TcEncoderObjectId   : OTCID;
    TcAxisObjectId      : OTCID;
END_STRUCT
END_TYPE
```
````
