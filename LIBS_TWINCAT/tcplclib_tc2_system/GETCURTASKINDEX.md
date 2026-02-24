# GETCURTASKINDEX

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [General function blocks](ms-xhelp:///?Id=beckhoff-8c7f-4e24-ae22-527914ce956b)
4. GETCURTASKINDEX

# GETCURTASKINDEX

![38292076](/tcplclib_tc2_system/1033/Images/png/9007199285905163__Web.png)

The function block GETCURTASKINDEX determines the task index of the task in which it is currently called.

To differentiate whether the current call occurs in the real-time context or from a cyclic PLC task, see the documentation for the [GETCURTASKINDEXEX](ms-xhelp:///?Id=beckhoff-01f2-4b64-99ee-9d3ec8ca9d34) function. For example, the automatic call of FB\_init methods during initialization does not occur from a cyclic PLC task.

## VAR\_INPUT

```
VAR_INPUT  
(*none*)  
END_VAR
```

## VAR\_OUTPUT

```
VAR_OUTPUT  
    index : BYTE;  
END_VAR
```

**index**: Returns the current task index of the calling task (1..4).

**Example of calling the block in FBD:**

![9084369](/tcplclib_tc2_system/1033/Images/png/31167371__en-US__Web.png)

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
