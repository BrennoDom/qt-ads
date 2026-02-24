# E_LDevType

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# E\_LDevType

```
TYPE E_LDevType :  
(  
    eLDT_Unknown        : UDINT,  
    eLDT_Beckhoff       : UDINT,  
    eLDT_GenericPC      : UDINT,  
    eLDT_TerminalDongle : UDINT,  
    eLDT_UsbDongle      : UDINT  
);  
END_TYPE
```

| Value | Meaning |
| --- | --- |
| eLDT\_Unknown | Device type is unknown. |
| eLDT\_Beckhoff | Beckhoff device (e.g. IPC, CX, …) |
| eLDT\_GenericPC | Third-party PC |
| eLDT\_TerminalDongle | License Key Terminal, e.g. EL6070 |
| eLDT\_UsbDongle | License key USB stick, e.g. C9900-L100 |
