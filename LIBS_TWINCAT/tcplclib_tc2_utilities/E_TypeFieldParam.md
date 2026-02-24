# E_TypeFieldParam

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# E\_TypeFieldParam

String format type field.

```
TYPE E_TypeFieldParam :  
(  
    TYPEFIELD_UNKNOWN := 0,  
    TYPEFIELD_B, (* b or B: binary number *)  
    TYPEFIELD_O, (* o or O: octal number *)  
    TYPEFIELD_U, (* u or U: unsigned decimal number *)  
    TYPEFIELD_C, (* c or C: one ASCII character *)  
    TYPEFIELD_F, (* f or F: float number ( normalized format )*)  
    TYPEFIELD_D, (* d or D: signed decimal number *)  
    TYPEFIELD_S, (* s or S: string *)  
    TYPEFIELD_XU, (* X: hecadecimal number (upper case characters )*)  
    TYPEFIELD_XL, (* x: hecadecimal number (lower case characters )*)  
    TYPEFIELD_EU, (* E: float number ( scientific format ) *)  
    TYPEFIELD_EL (* e: float number ( scientific format ) *)  
);  
END_TYPE
```

| Value | Meaning |
| --- | --- |
| TYPEFIELD\_UNKNOWN | Unknown or not initialized |
| TYPEFIELD\_B | b or B: Binary number |
| TYPEFIELD\_O | o or O: octal number |
| TYPEFIELD\_U | u or U: Unsigned decimal number |
| TYPEFIELD\_C | c or C: ASCII character |
| TYPEFIELD\_F | f or F: floating-point number (normalized representation) |
| TYPEFIELD\_D | d or D: signed decimal number |
| TYPEFIELD\_S | s or S: String |
| TYPEFIELD\_XU | X: hexadecimal number (upper case characters) |
| TYPEFIELD\_XL | x: hexadecimal number (lower case characters) |
| TYPEFIELD\_EU | E: floating-point number (scientific representation) |
| TYPEFIELD\_EL | e: floating-point number (scientific representation) |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
