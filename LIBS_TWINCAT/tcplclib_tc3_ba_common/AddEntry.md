# AddEntry

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# AddEntry

![36073588](/tcplclib_tc3_ba_common/1033/Images/gif/5714674187__Web.gif)

Creates a new data set at the end of the array and copies the content of the specified entry to the internal memory.

## VAR\_INPUT

```
pEntry    : PVOID;
```

**pEntry:** Pointer to the entry to be added.

## VAR\_OUTPUT

```
AddEntry       : BOOL;  
diResultIndex  : DINT;
```

**AddEntry:** Result of the function.

**diResultIndex:** Index position of the entry added.
