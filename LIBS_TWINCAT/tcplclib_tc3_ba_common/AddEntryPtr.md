# AddEntryPtr

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# AddEntryPtr

![25807001](/tcplclib_tc3_ba_common/1033/Images/gif/5714802955__Web.gif)

Creates a new entry at the end of the array and copies its memory address (i.e. the address to which the pointer *pEntry* points) to the internal memory.

## VAR\_INPUT

```
pEntry    : PVOID;
```

**pEntry:** Pointer to the entry to be added.

## VAR\_OUTPUT

```
AddEntryPtr    : BOOL;  
diResultIndex  : DINT;
```

**AddEntryPtr:** Result of the function.

**diResultIndex:** Index position of the entry added.
