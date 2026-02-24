# GetEntryEx

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# GetEntryEx

![58079852](/tcplclib_tc3_ba_common/1033/Images/gif/5714729867__Web.gif)

Determines a pointer to the internal memory of the specified data set.

## VAR\_INPUT

```
diIndex       : DINT;
```

**diIndex:** Index position of the data set to be output.

## VAR\_OUTPUT

```
GetEntryEx     : BOOL;  
pMemoryPtr     : POINTER TO PVOID;
```

**GetEntry:** Result of the function.

**pMemoryPtr:** Pointer that is to be used to output the data set.
