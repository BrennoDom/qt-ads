# GetEntryExPtr

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# GetEntryExPtr

![9992350](/tcplclib_tc3_ba_common/1033/Images/gif/5714850315__Web.gif)

Outputs a pointer to the memory address of the requested entry.

## VAR\_INPUT

```
diIndex    : DINT;
```

**diIndex:** Index position of the entry to be output.

## VAR\_OUTPUT

```
GetEntryExPtr    : BOOL;  
pEntryPtr        : POINTER TO PVOID;
```

**GetEntryExPtr:** Result of the function.

**pEntryPtr:** Pointer that is to be used to output the entry.
