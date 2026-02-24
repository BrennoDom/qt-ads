# E_LON_file_status_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_file\_status\_t

Used by: SNVT\_file\_status

```
TYPE E_LON_file_status_t :  
(  
  eLON_FS_NUL            := -1,  
  eLON_FS_XFER_OK        := 0,  
  eLON_FS_LOOKUP_OK      := 1,  
  eLON_FS_OPEN_FAIL      := 2,  
  eLON_FS_LOOKUP_ERR     := 3,  
  eLON_FS_XFER_UNDERWAY  := 4,  
  eLON_FS_IO_ERR         := 5,  
  eLON_FS_TIMEOUT_ERR    := 6,  
  eLON_FS_WINDOW_ERR     := 7,  
  eLON_FS_AUTH_ERR       := 8,  
  eLON_FS_ACCESS_UNAVAIL := 9,  
  eLON_FS_SEEK_INVALID   := 10,  
  eLON_FS_SEEK_WAIT      := 11  
)  
END_TYPE
```

**eLON\_FS\_NUL:**  Invalid Value

**eLON\_FS\_XFER\_OK:**  File transfer successful

**eLON\_FS\_LOOKUP\_OK:**  Directory lookup successful

**eLON\_FS\_OPEN\_FAIL:**  Error on opening file

**eLON\_FS\_LOOKUP\_ERR:**  Error on directory lookup

**eLON\_FS\_XFER\_UNDERWAY:**  File transfer in progress

**eLON\_FS\_IO\_ERR:**  Error on reading/writing file

**eLON\_FS\_TIMEOUT\_ERR:**  File transfer timed out

**eLON\_FS\_WINDOW\_ERR:**  Window sequence error

**eLON\_FS\_AUTH\_ERR:**  Authentication failure

**eLON\_FS\_ACCESS\_UNAVAIL:**  Access mode not supported

**eLON\_FS\_SEEK\_INVALID:**  Random access beyond EOF

**eLON\_FS\_SEEK\_WAIT:**

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
