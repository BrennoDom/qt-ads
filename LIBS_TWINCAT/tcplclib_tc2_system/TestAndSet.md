# TestAndSet

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [General functions](ms-xhelp:///?Id=beckhoff-1e7a-48a5-88e7-caf74e14975e)
4. TestAndSet

# TestAndSet

![65880360](/tcplclib_tc2_system/1033/Images/png/18014398540822155__Web.png)

You can use this function to check and set a flag. There is no option to interrupt the process. This allows data accesses to be synchronized. The mode of operation of a semaphore can be achieved with TestAndSet.

If the function call is successful, the function returns TRUE and the desired data can be accessed. If the function call is unsuccessful, the function returns FALSE and the desired data cannot be accessed. In this case, an alternative treatment must be provided for.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    Flag : BOOL; (* Flag to check if TRUE or FALSE *)  
END_VAR
```

**Flag**: Boolean flag to be checked

* if it was FALSE, the flag was free and is set (and therefore blocked from now on), and the function returns TRUE
* if it was TRUE, the flag was already assigned (and therefore blocked), and the function returns FALSE

## Sample

```
VAR_GLOBAL  
    bGlobalTestFlag : BOOL;  
END_VAR
```

```
VAR  
    nLocalBlockedCounter : DINT;  
END_VAR
```

```
IF TestAndSet(GVL.bGlobalTestFlag) THEN  
    (* bGlobalTestFlag was FALSE, nobody was blocking, NOW  
    bGlobalTestFlag is set to TRUE and blocking others *)  
      
    (* ... *)  
      
    (* remove blocking by resetting the flag *)   
    GVL.bGlobalTestFlag := FALSE;  
ELSE  
    (* bGlobalTestFlag was TRUE, somebody is blocking *)  
    nLocalBlockedCounter := nLocalBlockedCounter + 1;  
      
    (* ... *)  
END_IF
```

## NEGATIVE sample

Caution is advised with a further encapsulation, e.g. in a function block, as this can destroy the desired atomic operation. Secure synchronization of data accesses can then no longer take place. In the following, a NEGATIVE sample is included that shows how the function may NOT be used. If two contexts were to request access at the same time in this implementation, both might assume that the access is allowed and simultaneous, unsecured accessing of the data would take place.

```
FUNCTION_BLOCK FB_MyGlobalLock  
VAR_INPUT  
    bLock    : BOOL; // set TRUE to lock & set FALSE to unlock  
END_VAR  
VAR_OUTPUT  
    bLocked : BOOL;  
END_VAR  
  
IF bLock THEN  
    TestAndSet(bLocked);  
ELSE // unlock  
    bLocked := FALSE;  
END_IF
```

```
IF NOT GVL.fbGlobalLock.bLocked THEN  
    GVL.fbGlobalLock(bLock := TRUE);  
      
    (* ... *)  
      
    GVL.fbGlobalLock(bLock := FALSE);  
END_IF
```

|  |  |
| --- | --- |
| 56052334 | The function block [FB\_IecCriticalSection](ms-xhelp:///?Id=beckhoff-d938-44ed-84ea-2ce43ce83b63) offers the application of critical sections as an alternative Mutex method. |

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
