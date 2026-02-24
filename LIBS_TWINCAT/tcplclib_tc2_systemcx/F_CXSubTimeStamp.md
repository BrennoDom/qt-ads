# F_CXSubTimeStamp

## Library
tcplclib_tc2_systemcx

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
2. [Functions](ms-xhelp:///?Id=beckhoff-48c8-4ac6-bc46-6e026efec7f3)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-b9c9-4bdc-9c56-d28accda9e89)
4. F\_CXSubTimeStamp

# F\_CXSubTimeStamp

|  |  |
| --- | --- |
| 15834086 | For subtraction TwinCAT3.1 also offers 64-bit data types (LINT/ULINT, LWORD) that can be executed directly (A-B) or there are TC2-compatible functions for 64-bit operations that should be used as an alternative to F\_CXSubTimeStamp. |

![8289053](/tcplclib_tc2_systemcx/1033/Images/png/9007199440679563__Web.png)

The function F\_CXSubTimeStamp executes a 64-bit subtraction time stamp A - time stamp B and converts the result to µs. The required 64-bit time stamps with 100 ns resolution can be read from the system with the function block GETCPUCOUNTER.

If the difference between time stamp A and time stamp B is negative or greater than 4294967295 us, the maximum value 4294967295 us is returned. This corresponds to 71 minutes, 34 seconds, 967 milliseconds and 295 microseconds. In such cases the function UInt64Sub64() from TcUtilities.lib can be used to execute a complete 64-bit subtraction with 64-bit result in [100 ns].

## **FUNCTION F\_CXSubTimeStamp: UDINT**

```
VAR_INPUT  
    nTimeStampLoDW_A : UDINT; (* 2*32 bit time stamp A: low DWORD *)  
    nTimeStampHiDW_A : UDINT; (* 2*32 bit time stamp A: high DWORD *)  
    nTimeStampLoDW_B : UDINT; (* 2*32 bit time stamp B: low DWORD *)  
    nTimeStampHiDW_B : UDINT; (* 2*32 bit time stamp B: high DWORD *)  
END_END_VAR
```

**nTimeStampLoDW\_A**: lower 32bit of time stamp A.

**nTimeStampHiDW\_A**: upper 32bit of time stamp A.

**nTimeStampLoDW\_B**: lower 32bit of time stamp B.

**nTimeStampHiDW\_B**: upper 32bit of time stamp B.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 | CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7 :TC TR x86, WEC7: TC CE7 ARMV7) | Tc2\_SystemCX |

[TwinCAT 3 | PLC Library: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
