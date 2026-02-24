# SetEntry

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# SetEntry

![17780525](/tcplclib_tc3_ba_common/1033/Images/gif/5714798475__Web.gif)

Replaces the existing data set with a new one by overwriting the internal memory area of the existing data set with the value of the new entry.

## VAR\_INPUT

```
diIndex   : DINT;  
pEntry    : PVOID;
```

**diIndex:** Index position of the data set to be replaced.

**pEntry:** Pointer to the entry to be removed.

## VAR\_OUTPUT

```
SetEntry    : BOOL;
```

**SetEntry:** Result of the function.
