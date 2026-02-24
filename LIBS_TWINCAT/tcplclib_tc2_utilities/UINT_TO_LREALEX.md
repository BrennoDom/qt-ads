# UINT_TO_LREALEX

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# UINT\_TO\_LREALEX

![3393965](/tcplclib_tc2_utilities/1033/Images/gif/2210665739__Web.gif)

The conversion of unsigned numbers into floating point numbers of the type LREAL is not supported in TwinCAT 2 on the ARM platform. Unsigned numbers with the highest significant bit set may possibly be implicitly converted into negative floating point numbers. The function described here allows the explicit conversion of the type UINT into a positive floating point number of the type LREAL in TwinCAT 2 (even if the highest significant bit was set and without compiler warning). You only need this function in order to be able to compile converted TwinCAT 2 projects without changes in TwinCAT 3.

Unsigned numbers of the type UINT are always (implicitly and explicitly) converted into positive floating point numbers in TwinCAT3. For this reason this function can be dispensed with.

## FUNCTION UINT\_TO\_LREALEX: LREAL

## VAR\_INPUT

```
VAR_INPUT  
    in : UINT;  
END_VAR
```

**Sample:**

```
PROGRAM MAIN  
VAR  
    nUint  : UINT  := 16#FFFF;  
    fLreal : LREAL := 0.0;  
END_VAR
```

```
(*    fLreal value                                    |    Tc2.x ARM                |    Tc2.x X86         |    Tc3.x ARM, X86, X64 *)  
(*__________________________________________________________________________________________________________________________________*)  
fLreal := nUint;                                (*    |     +65535, Warning 1105*   |      +65535          |    +65535              *)  
fLreal := UINT_TO_LREAL( nUint );               (*    |     +65535, Warning 1105*   |      +65535          |    +65535              *)  
fLreal := UINT#16#FFFF;                         (*    |     +65535, Warning 1105*   |      +65535          |    +65535              *)  
fLreal := 16#FFFF;                              (*    |     +65535                  |      +65535          |    +65535              *)  
fLreal := UINT_TO_LREALEX( nUint );             (*    |     +65535                  |      +65535          |    +65535              *)  
fLreal := UINT_TO_LREALEX( UINT#16#FFFF );      (*    |     +65535                  |      +65535          |    +65535              *)  
fLreal := UINT_TO_LREALEX( 16#FFFF );           (*    |     +65535                  |      +65535          |    +65535              *)  
(* -: not supported  *)  
(* TwinCAT 2.x Warning 1105*:warning: Conversion of unsigned integer to LREAL is not supported. The value is used as signed instead. *)
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
