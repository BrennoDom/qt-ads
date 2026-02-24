# UDINT_TO_LREALEX

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# UDINT\_TO\_LREALEX

![22746728](/tcplclib_tc2_utilities/1033/Images/gif/2210662667__Web.gif)

The conversion of unsigned numbers into floating point numbers of the type LREAL is not supported in TwinCAT 2 on the ARM platform. Unsigned numbers with the highest significant bit set may possibly be implicitly converted into negative floating point numbers. The function described here allows the explicit conversion of the type UDINT into a positive floating point number of the type LREAL in TwinCAT 2 (even if the highest significant bit was set and without compiler warning). You only need this function in order to be able to compile converted TwinCAT 2 projects without changes in TwinCAT 3.

Unsigned numbers of the type UDINT are always (implicitly and explicitly) converted into positive floating point numbers in TwinCAT3. For this reason this function can be dispensed with.

## FUNCTION UDINT\_TO\_LREALEX: LREAL

## VAR\_INPUT

```
VAR_INPUT  
    in : UDINT;  
END_VAR
```

**Sample:**

```
PROGRAM MAIN  
VAR  
    nUdint : UDINT := 16#FFFFFFFF;  
    fLreal : LREAL := 0.0;  
END_VAR
```

```
(*    fLreal value                                    |    Tc2.x ARM                |    Tc2.x X86         |    Tc3.x ARM, X86, X64 *)  
(*__________________________________________________________________________________________________________________________________*)  
fLreal := nUdint;                               (*    |     -1, Warning 1105*       |      +4294967295     |    +4294967295         *)  
fLreal := UDINT_TO_LREAL( nUdint );             (*    |     -1, Warning 1105*       |      +4294967295     |    +4294967295         *)  
fLreal := UDINT#16#FFFFFFFF;                    (*    |     -1, Warning 1105*       |      +4294967295     |    +4294967295         *)  
fLreal := 16#FFFFFFFF;                          (*    |     +4294967295             |      +4294967295     |    +4294967295         *)  
fLreal := UDINT_TO_LREALEX( nUdint );           (*    |     +4294967295             |      +4294967295     |    +4294967295         *)  
fLreal := UDINT_TO_LREALEX( UDINT#16#FFFFFFFF );(*    |     +4294967295             |      +4294967295     |    +4294967295         *)  
fLreal := UDINT_TO_LREALEX( 16#FFFFFFFF );      (*    |     +4294967295             |      +4294967295     |    +4294967295         *)  
(* -: not supported  *)  
(* TwinCAT 2.x Warning 1105*:warning: Conversion of unsigned integer to LREAL is not supported. The value is used as signed instead. *)
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
