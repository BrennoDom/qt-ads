# F_CheckMemoryArea

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [General functions](ms-xhelp:///?Id=beckhoff-1e7a-48a5-88e7-caf74e14975e)
4. F\_CheckMemoryArea

# F\_CheckMemoryArea

![66621782](/tcplclib_tc2_system/1033/Images/png/4012977931__Web.png)

The function returns information about the memory area in which the requested variable with the specified size is located. A return value of type [E\_TcMemoryArea](ms-xhelp:///?Id=beckhoff-2493-4665-b9a2-00e426ae65e4) is used for this purpose.

## FUNCTION F\_CheckMemoryArea: E\_TcMemoryArea

```
VAR_INPUT  
    pData : PVOID;  
    nSize : UDINT;  
END_VAR
```

**pData**: Memory address of the variable

**nSize:** Size of the variable in bytes

## Example

```
PROGRAM MAIN  
VAR  
    nCounter : USINT;  
    eMemAreaStatic : E_TcMemoryArea;  
    pDynamicVariable : POINTER TO LREAL;  
    eMemAreaDynamic : E_TcMemoryArea;  
    pNull : PVOID := 0;  
    eMemAreaUnknown : E_TcMemoryArea;  
END_VAR  
-------------------------------------------------------------------  
  
nCounter := nCounter + 1;  
eMemAreaStatic := F_CheckMemoryArea( pData:=ADR(nCounter), nSize:=SIZEOF(nCounter) );  
  
IF nCounter = 100 THEN  
    pDynamicVariable := __NEW(LREAL);  
    IF pDynamicVariable <> 0 THEN  
        pDynamicVariable^ := 7 * 4.5;   
        eMemAreaDynamic := F_CheckMemoryArea( pData:=pDynamicVariable, nSize:=SIZEOF(LREAL) );  
        __DELETE(pDynamicVariable);  
    END_IF  
END_IF  
  
eMemAreaUnknown := F_CheckMemoryArea( pData:=pNull, nSize:=1 );
```

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_System (system) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
