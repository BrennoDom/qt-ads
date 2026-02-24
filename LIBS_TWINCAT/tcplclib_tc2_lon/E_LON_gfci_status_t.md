# E_LON_gfci_status_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_gfci\_status\_t

Used by: SNVT\_gfci\_status

```
TYPE E_LON_gfci_status_t :  
(  
  eLON_GFCI_NUL         := -1,  
  eLON_GFCI_UNKNOWN     := 0,  
  eLON_GFCI_NORMAL      := 1,  
  eLON_GFCI_TRIPPED     := 2,  
  eLON_GFCI_TEST_FAILED := 3,  
  eLON_GFCI_TEST_PASSED := 4,  
   eLON_GFCI_TEST_NOW   := 5  
)  
END_TYPE
```

**eLON\_GFCI\_NUL:**  Invalid Value

**eLON\_GFCI\_UNKNOWN:**  Unknown response

**eLON\_GFCI\_NORMAL:**  Normal GFCI operating condition

**eLON\_GFCI\_TRIPPED:**  A ground-fault has caused the GFCI to interrupt the circuit

**eLON\_GFCI\_TEST\_FAILED:**  The GFCI failed testing

**eLON\_GFCI\_TEST\_PASSED:**  The GFCI passed testing

**eLON\_GFCI\_TEST\_NOW:**  The GFCI needs to be tested

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
