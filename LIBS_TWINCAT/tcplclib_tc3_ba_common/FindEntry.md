# FindEntry

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# FindEntry

![56226836](/tcplclib_tc3_ba_common/1033/Images/gif/5714682507__Web.gif)

Determines the position of the specified entry in the array by comparing its content with the data sets of the array.

## VAR\_INPUT

```
pEntry    : PVOID;
```

**pEntry:** Pointer to the entry sought.

## VAR\_OUTPUT

```
FindEntry      : BOOL;  
diResultIndex  : DINT;
```

**FindEntry:** Result of the function.

**diResultIndex:** Index position of the entry added.
