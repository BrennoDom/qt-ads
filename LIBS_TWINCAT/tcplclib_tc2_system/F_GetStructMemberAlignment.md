# F_GetStructMemberAlignment

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [General functions](ms-xhelp:///?Id=beckhoff-1e7a-48a5-88e7-caf74e14975e)
4. F\_GetStructMemberAlignment

# F\_GetStructMemberAlignment

![22047016](/tcplclib_tc2_system/1033/Images/png/9007199286077963__Web.png)

The function returns information about used data struct member alignment setting. The alignment is affecting the way data structure elements are arranged in computer memory.

## FUNCTION F\_GetStructMemberAlignment : BYTE

```
VAR_INPUT  
    (* no input parameter *)  
END_VAR
```

| Return value | Description |
| --- | --- |
| 1 | 1 byte alignment (e.g. TwinCAT v2.11, x86 target platform) |
| 2 | 2 byte alignment |
| 4 | 4 byte alignment (e.g. TwinCAT v2.11, ARM target platform) |
| 8 | 8 byte alignment |

The following examples show the arrangement of the data structure elements in the memory, depending on the memory alignment employed.

?? := Padding byte

**Example 1**

```
TYPE ST_TEST1  
STRUCT  
    ui8 : BYTE := 16#FF;(* FF *)  
    f64 : LREAL := 1234.5678;(* AD FA 5C 6D 45 4A 93 40 *)  
END_STRUCT  
END_TYPE  
  
test1 : ST_TEST1;
```

| Alignment | SIZEOF(test1) | Memory contents |
| --- | --- | --- |
| 1 byte | 9 | FF AD FA 5C 6D 45 4A 93 40 |
| 2 byte | 10 | FF ?? AD FA 5C 6D 45 4A 93 40 |
| 4 byte | 12 | FF ?? ?? ?? AD FA 5C 6D 45 4A 93 40 |
| 8 byte | 16 | FF ?? ?? ?? ?? ?? ?? ?? AD FA 5C 6D 45 4A 93 40 |

**Example 2**

Converting the order of the structure elements changes the arrangement of the padding bytes. These are now added at the end.

```
TYPE ST_TEST2  
STRUCT  
    f64 : LREAL := 1234.5678;(* AD FA 5C 6D 45 4A 93 40 *)  
    ui8 : BYTE := 16#FF;(* FF *)  
END_STRUCT  
END_TYPE  
  
test2 : ST_TEST2;
```

| Alignment | SIZEOF(test2) | Memory contents |
| --- | --- | --- |
| 1 byte | 9 | AD FA 5C 6D 45 4A 93 40 FF |
| 2 byte | 10 | AD FA 5C 6D 45 4A 93 40 FF ?? |
| 4 byte | 12 | AD FA 5C 6D 45 4A 93 40 FF ?? ?? ?? |
| 8 byte | 16 | AD FA 5C 6D 45 4A 93 40 FF ?? ?? ?? ?? ?? ?? ?? ?? |

**Example 3**

In the case of 2, 4 and 8 byte alignment, the elements ui32 and f64 are already suitably aligned, so that no padding bytes need to be added.

```
TYPE ST_TEST3  
STRUCT  
    ui8  : BYTE := 16#FF;(* FF *)  
    ui16 : WORD := 16#1234;(* 34 12 *)  
    ui32 : DWORD := 16#AABBCCDD;(* DD CC BB AA *)  
    f64  : LREAL := 1234.5678;(* AD FA 5C 6D 45 4A 93 40 *)  
END_STRUCT  
END_TYPE  
  
test3 : ST_TEST3;
```

| Alignment | SIZEOF(test3) | Memory contents |
| --- | --- | --- |
| 1 byte | 15 | FF 34 12 DD CC BB AA AD FA 5C 6D 45 4A 93 40 |
| 2 byte | 16 | FF ?? 34 12 DD CC BB AA AD FA 5C 6D 45 4A 93 40 |
| 4 byte | 16 | FF ?? 34 12 DD CC BB AA AD FA 5C 6D 45 4A 93 40 |
| 8 byte | 16 | FF ?? 34 12 DD CC BB AA AD FA 5C 6D 45 4A 93 40 |

**Example 4**

```
TYPE ST_A1  
STRUCT  
    ui8  : BYTE := 16#FF;(* FF *)  
    ui32 : DWORD := 16#AABBCCDD;(* DD CC BB AA *)  
    rsv  : BYTE := 16#EE;(* EE *)  
END_STRUCT  
END_TYPE  
  
TYPE ST_A2  
STRUCT  
    ui16 : WORD := 16#1234;(* 34 12 *)  
    ui8  : BYTE := 16#55;(* 55 *)  
END_STRUCT  
END_TYPE  
  
TYPE ST_TEST4  
STRUCT  
    a1 : ST_A1;  
    a2 : ST_A2;  
END_STRUCT  
END_TYPE  
  
test4 : ST_TEST4;
```

| Alignment | SIZEOF(test4) | SIZEOF(test4.a1) | a1/a2 padding bytes | SIZEOF(test4.a2) | Memory contents |
| --- | --- | --- | --- | --- | --- |
| 1 byte | 9 | 6 | - | 3 | FF DD CC BB AA EE 34 12 55 |
| 2 byte | 12 | 8 | - | 4 | FF ?? DD CC BB AA EE ?? 34 12 55 ?? |
| 4 byte | 16 | 12 | - | 4 | FF ?? ?? ?? DD CC BB AA EE ?? ?? ?? 34 12 55 ?? |
| 8 byte | 16 | 12 | - | 4 | FF ?? ?? ?? DD CC BB AA EE ?? ?? ?? 34 12 55 ?? |

**Example 5**

```
TYPE ST_D1  
STRUCT  
    ui16 : WORD := 16#1234;(* 34 12 *)  
    ui8 : BYTE := 16#55;(* 55 *)  
END_STRUCT  
END_TYPE  
  
TYPE ST_D2  
STRUCT  
    ui8 : BYTE := 16#FF;(* FF *)  
    f64 : LREAL := 1234.5678;(* AD FA 5C 6D 45 4A 93 40 *)  
    rsv : BYTE := 16#EE;(* EE *)  
END_STRUCT  
END_TYPE  
  
TYPE ST_TEST5  
STRUCT  
    d1 : ST_D1;  
    d2 : ST_D2;  
END_STRUCT  
END_TYPE  
  
test5 : ST_TEST5;
```

| Alignment | SIZEOF(test5) | SIZEOF(test5.d1) | d1/d2 padding bytes | SIZEOF(test5.d2) | Memory contents |
| --- | --- | --- | --- | --- | --- |
| 1 byte | 13 | 3 | - | 10 | 34 12 55 FF AD FA 5C 6D 45 4A 93 40 EE |
| 2 byte | 16 | 4 | - | 12 | 34 12 55 ?? FF ?? AD FA 5C 6D 45 4A 93 40 EE ?? |
| 4 byte | 20 | 4 | - | 16 | 34 12 55 ?? FF ?? ?? ?? AD FA 5C 6D 45 4A 93 40 EE ?? ?? ?? |
| 8 byte | 32 | 4 | 4 | 24 | 34 12 55 ?? ?? ?? ?? ?? FF ?? ?? ?? ?? ?? ?? ?? AD FA 5C 6D 45 4A 93 40 EE ?? ?? ?? ?? ?? ?? ?? |

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
