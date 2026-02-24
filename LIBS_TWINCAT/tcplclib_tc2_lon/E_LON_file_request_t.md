# E_LON_file_request_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_file\_request\_t

Used by: SNVT\_file\_req

```
TYPE E_LON_file_request_t :  
(  
  eLON_FR_NUL                := -1,  
  eLON_FR_OPEN_TO_SEND       := 0,  
  eLON_FR_OPEN_TO_RECEIVE    := 1,  
  eLON_FR_CLOSE_FILE         := 2,  
  eLON_FR_CLOSE_DELETE_FILE  := 3,  
  eLON_FR_DIRECTORY_LOOKUP   := 4,  
  eLON_FR_OPEN_TO_SEND_RA    := 5,  
  eLON_FR_OPEN_TO_RECEIVE_RA := 6  
)  
END_TYPE
```

**eLON\_FR\_NUL:**  Invalid Value

**eLON\_FR\_OPEN\_TO\_SEND:**  Sequential access read

**eLON\_FR\_OPEN\_TO\_RECEIVE:**  Sequential access write

**eLON\_FR\_CLOSE\_FILE:**  Close and save file

**eLON\_FR\_CLOSE\_DELETE\_FILE:**  Close and delete file

**eLON\_FR\_DIRECTORY\_LOOKUP:**  Retrieve directory entry

**eLON\_FR\_OPEN\_TO\_SEND\_RA:**  Random access read

**eLON\_FR\_OPEN\_TO\_RECEIVE\_RA:**  Random access write

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
