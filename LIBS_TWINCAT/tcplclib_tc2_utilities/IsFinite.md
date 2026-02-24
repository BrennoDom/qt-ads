# IsFinite

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# IsFinite

![6101690](/tcplclib_tc2_utilities/1033/Images/gif/35875083__en-US__Web.gif)

The function IsFinite() returns TRUE, if its argument has a finite value (INF < x < +INF). The function returns FALSE, if the argument is infinite or NaN (NaN = Not a number). IsFinite() checks whether the formatting of an LREAL or REAL variable complies with IEEE.

INF numbers may occur in a runtime system if the result of a mathematical operation falls outside the range that can be represented. E.g.:

```
PROGRAM MAIN  
VAR  
    fSingle : REAL := 12.34;  
END_VAR
```

```
(*Cyclic called program code*)  
fSingle := fSingle*2;
```

NaN numbers may occur in the runtime system if their actual formatting (memory content) was overwritten through illegal access (e.g. by using the MEMCPY of MEMSET functions). E.g.:

```
PROGRAM MAIN  
VAR  
    fSingle : REAL := 12.34;  
END_VAR
```

```
(*Cyclic called program code*)  
MEMSET( ADR( fSingle ), 16#FF, SIZEOF( fSingle ) ); (* Invalid initialization of REAL variable *)
```

Calling a conversion function with an NaN or INF number as parameter causes an FPU exception on a PC system (x86,x64). This exception subsequently leads to the PLC being stopped. The function IsFinite() enables the value of the variables to be checked, and therefore the FPU exception to be avoided and program execution to be continued.

## FUNCTION IsFinite: BOOL

## VAR\_INPUT

```
VAR_INPUT  
    x : T_Arg;  
END_VAR
```

**x**: An auxiliary structure with information about the REAL or LREAL variables to be checked (type: [T\_Arg](ms-xhelp:///?Id=beckhoff-9414-4e02-83ee-fc21ca340682)). The structure parameters have to be generated when IsFinite() is called from auxiliary functions [F\_REAL](ms-xhelp:///?Id=beckhoff-9458-453d-8ade-48d9876779e4) or [F\_LREAL](ms-xhelp:///?Id=beckhoff-c525-4b79-9cef-7e093c2ed20f) and transferred as parameters.

**Example 1:**

In the following example, the formatting of a REAL and an LREAL variable is checked, and an FPU exception is avoided.

```
PROGRAM MAIN  
VAR  
    fSingle         : REAL := 12.34;  
    fDouble         : LREAL := 56.78;  
    singleAsString  : STRING;  
    doubleAsString  : STRING;  
END_VAR
```

```
fSingle := fSingle*2;  
IF IsFinite( F_REAL( fSingle ) ) THEN  
    singleAsString := REAL_TO_STRING( fSingle );  
ELSE  
    (* report error !*)  
    fSingle := 12.34;  
END_IF  
  
fDouble := fDouble*2;  
IF IsFinite( F_LREAL( fDouble ) ) THEN  
    doubleAsString := LREAL_TO_STRING( fDouble );  
ELSE  
    (* report error !*)  
    fDouble := 56.78;  
END_IF
```

**Example 2:**

In the following case, an FPU exception cannot be avoided through checking with IsFinite():

```
PROGRAM MAIN  
VAR  
    bigFloat   : LREAL := 3.0E100;  
    smallDigit : INT;  
END_VAR
```

```
IF IsFinite( F_LREAL( bigFloat ) ) THEN  
    smallDigit := LREAL_TO_INT( bigFloat );  
END_IF
```

While the bigFloat variable has the right formatting, the variable value is too large for conversion into an INT type. An exception is triggered on a PC system (x86,x64), and the runtime system is stopped.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
