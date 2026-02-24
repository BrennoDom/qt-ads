# FindEntryPtr

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# FindEntryPtr

![30936422](/tcplclib_tc3_ba_common/1033/Images/gif/5714807435__Web.gif)

Determines the position of an entry in the array by comparing its address with the addresses stored in the array.

## VAR\_INPUT

```
pEntry    : PVOID;
```

**pEntry:** Pointer to the entry sought.

## VAR\_OUTPUT

```
FindEntryPtr    : BOOL;  
diResultIndex  : DINT;
```

**FindEntryPtr:** Result of the function.

**diResultIndex:** Index position of the entry sought.
