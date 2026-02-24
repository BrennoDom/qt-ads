# GetEntry

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# GetEntry

![36279478](/tcplclib_tc3_ba_common/1033/Images/gif/5714725387__Web.gif)

Copies the contents of the data set to a certain position in the specified memory area.

## VAR\_INPUT

```
diIndex       : DINT;  
pResultEntry  : PVOID;
```

**diIndex:** Index position of the data set to be output.

**pResultEntry:** Pointer to the memory area that is to be used to output the data record.

## VAR\_OUTPUT

```
GetEntry       : BOOL;
```

**GetEntry:** Result of the function.
