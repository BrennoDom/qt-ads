# Globale_Variablen_MBUS

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [GLVs](ms-xhelp:///?Id=beckhoff-453b-401b-8790-5f0f931ea1d1)
4. Globale\_Variablen\_MBUS

# Globale\_Variablen\_MBUS

If they are declared in the program, a warning message is generated during program compilation, since the constant already exists. This warning can be ignored.

```
VAR_GLOBAL CONSTANT  
  cMBUS_MaxData      := 40,  
  cMBUS_MaxTelegrams := 2,  
  cMBUS_MaxDataParam := 10,  
END_VAR
```

**cMBUS\_MaxData:**  The constant applies to all instances of the blocks [FB\_MBUS\_General()](ms-xhelp:///?Id=beckhoff-8e90-4a30-8684-e4959275ff37), [FB\_MBUS\_General\_Ext()](ms-xhelp:///?Id=beckhoff-7616-46e1-8f68-e6176732685e) and [FB\_MBUS\_General\_Param()](ms-xhelp:///?Id=beckhoff-ac86-411d-8af8-85905f72b0e0). It indicates the maximum data volume expected in a meter telegram.

**cMBUS\_MaxTelegrams:** The constant applies to all instances of the [FB\_MBUS\_General\_Ext block()](ms-xhelp:///?Id=beckhoff-7616-46e1-8f68-e6176732685e). It indicates the maximum number of telegrams to be expected.

**cMBUS\_MaxDataParam:**  The constant applies to all instances of the [FB\_MBUS\_General\_Param blocks()](ms-xhelp:///?Id=beckhoff-ac86-411d-8af8-85905f72b0e0). It indicates the maximum number of values to be displayed by the instances of block [FB\_MBUS\_General\_Param()](ms-xhelp:///?Id=beckhoff-ac86-411d-8af8-85905f72b0e0).

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
