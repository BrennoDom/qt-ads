# SetEntryPtr

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# SetEntryPtr

![4074007](/tcplclib_tc3_ba_common/1033/Images/gif/5714859275__Web.gif)

Replaces an existing entry by a new one by overwriting the memory address of the existing entry with the memory address of the new entry.

## VAR\_INPUT

```
diIndex   : DINT;  
pEntry    : PVOID;
```

**diIndex:** Index position of the entry to be replaced.

**pEntry:** Pointer to the entry to be replaced.

## VAR\_OUTPUT

```
SetEntryPtr    : BOOL;
```

**SetEntryPtr:** Result of the function.
