# WCONCAT

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [String functions (WSTRING)](ms-xhelp:///?Id=beckhoff-a835-44eb-81fb-fe5e0a1d71e0)
3. WCONCAT

# WCONCAT

![66361692](/tcplclib_tc2_standard/1033/Images/png/2261068811__Web.png)

Concatenation (combination) of two WSTRINGs.

## FUNCTION WCONCAT: WSTRING (255)

```
VAR_INPUT  
    STR1 : WSTRING(255) (*Head part of the concatenated result*)  
    STR2 : WSTRING(255) (*Tail part of the concatenated result*)  
END_VAR
```

Example in IL:

```
LD “SUSI“  
WCONCAT “WILLI“  
ST Var1 (*Result is “SUSIWILLI“*)
```

Example in ST:

```
Var1 := WCONCAT (“SUSI“,“WILLI“);
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
