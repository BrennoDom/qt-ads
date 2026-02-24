# FindAndSplitChar

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FindAndSplitChar

![58132325](/tcplclib_tc2_utilities/1033/Images/png/8245765515__Web.png)

The function splits a string into two strings.

The character string is searched for a separator (e.g. "\") from left to right. The strings on both sides of this first occurrence of the separator are output.

The search direction can be changed with the parameter bSearchFromRight so that the string is searched from right to left.

The function stops the checking of the input length after 10000 characters (`Parameterlist.cMaxCharacters`) in order to avoid an infinite loop.

## FUNCTION FindAndSplitChar : BOOL

The return value is TRUE if the separator was found and the division and output of the strings was successful.

## VAR\_INPUT

```
VAR_INPUT  
    sSeparatorChar    : STRING(1);  
    pSrcString        : POINTER TO STRING;  
    pLeftString       : POINTER TO STRING;  
    nLeftSize         : UDINT;  
    pRightString      : POINTER TO STRING;  
    nRightSize        : UDINT;  
    bSearchFromRight  : BOOL;  
END_VAR
```

**sSeparatorChar:** Character representing the separator.

**pSrcString:** Pointer to the STRING variable that represents the source string.

**pLeftString:** Pointer to the STRING variable to which the separated left-hand string is to be output.

**nLeftSize:** Maximum size of the separated left string.

**pRightString:** Pointer to the STRING variable to which the separated right-hand string is to be output.

**nRightSize:** Maximum size of the separated right string.

**bSearchFromRight**: If the input is set, the search direction changes so that the string is searched for the separator from right to left.

## Sample "Splitting into several substrings":

This sample shows how to split a string ''machines/machine1/module2/data/tx' into several strings ['machines', 'machine1', 'module2', 'data', 'tx']. To this end the function FindAndSplitChar() is called repeatedly in a loop.

```
PROGRAM MAIN  
VAR  
    sSrc         : STRING(255) := 'machines/machine1/module2/data/tx';  
    aSplit       : ARRAY[1..cMax] OF STRING(255);  
    bResultSplit : BOOL;  
    i            : UDINT;  
END_VAR  
VAR CONSTANT  
    cMax         : UDINT := 9;  
END_VAR
```

```
aSplit[1] := sSrc;  
FOR i:=1 TO cMax-1 DO  
    bResultSplit := FindAndSplitChar( sSeparatorChar := '/',  pSrcString := ADR(aSplit[i]),   
                                      pLeftString    := ADR(aSplit[i]),   nLeftSize  := SIZEOF(aSplit[i]),   
                                      pRightString   := ADR(aSplit[i+1]), nRightSize := SIZEOF(aSplit[i+1]),  
                                      bSearchFromRight := FALSE );  
    IF NOT bResultSplit THEN  
        EXIT;  
    END_IF  
END_FOR
```

## Sample "Merging several strings":

This sample shows how to combine several strings ['machines', 'machine1', 'module2', 'data', 'tx'] into one string 'machines/machine1/module2/data/tx'.

```
PROGRAM MAIN  
VAR  
    sSeparator    : STRING(1) := '/';  
    aSplit        : ARRAY[1..cMax] OF STRING(255) := ['machines', 'machine1', 'module2', 'data', 'tx'];  
    sJoined       : STRING(255);  
    bResultConcat : BOOL;  
    i             : UDINT;  
END_VAR  
VAR CONSTANT  
    cMax          : UDINT := 5;  
END_VAR
```

```
sJoined := aSplit[1];  
FOR i:=1 TO cMax-1 DO  
    bResultConcat := CONCAT2(pSrcString1 := ADR(sJoined), pSrcString2 := ADR(sSeparator), pDstString := ADR(sJoined), nDstSize := SIZEOF(sJoined));  
    IF NOT bResultConcat THEN  
        EXIT;  
    END_IF  
    bResultConcat := CONCAT2(pSrcString1 := ADR(sJoined), pSrcString2 := ADR(aSplit[i+1]), pDstString := ADR(sJoined), nDstSize := SIZEOF(sJoined));  
    IF NOT bResultConcat THEN  
        EXIT;  
    END_IF  
END_FOR
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4024.11 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >=3.3.39.0 |
