# E_LDongleStatus

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# E\_LDongleStatus

```
TYPE E_LDongleStatus :  
(  
    eLDT_Unknown      : UDINT,  
    eLDT_OK           : UDINT,  
    eLDT_Pending      : UDINT,  
    eLDT_Invalid      : UDINT,  
    eLDT_NoConnection : UDINT  
);  
END_TYPE
```

| Value | Meaning |
| --- | --- |
| eLDT\_Unknown | License dongle status unknown |
| eLDT\_OK | License dongle was successfully validated |
| eLDT\_Pending | Validation of the license dongle is running |
| eLDT\_Invalid | License dongle is invalid |
| eLDT\_NoConnection | No connection to the license dongle |
