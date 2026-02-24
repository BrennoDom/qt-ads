# Secondary address

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [M-Bus](ms-xhelp:///?Id=beckhoff-da58-4a1f-8f86-2cb29e0d2232)
3. [Bulletin](ms-xhelp:///?Id=beckhoff-867f-4d59-be31-26fe64fe0f45)
4. Secondary address

# Secondary address

Like the primary address, the secondary address is used to identify the terminal device. Like the primary address, the secondary address is used to identify the terminal device. The identification number alone can be used to form 100 million different values. In addition, it is not necessary to allocate primary addresses.

A secondary address has the following structure, according to the M-Bus standard:  
**Ident no.:** 4 bytes / 8-digit BCD device ID data  
**Manufacturer code:** 2 bytes / manufacturer code  
**Version:** 1 byte / generation number of the manufacturer  
**Medium:** 1 byte / medium

To use secondary addressing, set the primary address to 253.

The secondary address is transferred to the function block via the structure "stSecAdr" ([ST\_MBUS\_SecAdr](ms-xhelp:///?Id=beckhoff-a78a-4fca-b07d-b2756fa9e090)).

The manufacturer code, version and medium are internally preset to 16#FF, so that these values do not have to be specified explicitly.

**Sample calls:**

```
stSecAdr1.udiIdNumber    := 16#12345678;  
stSecAdr1.uiManufacturer := 16#FFFF;  
stSecAdr1.usiMedium      := 16#FF;  
stSecAdr1.usiVersion     := 16#FF;  
fbmeter(  
  usiAddress           := 253,  
  stSecAdr.udiIdNumber := stSecAdr1,  
  stCom                := stComKL6781_1);
```

**or**

```
fbmeter.stSecAdr.udiIdNumber := 16#12345678;  
fbmeter(  
  usiAddress := 253,  
  stCom      := stComKL6781_1);
```

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
