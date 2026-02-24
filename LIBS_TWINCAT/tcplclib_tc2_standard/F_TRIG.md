# F_TRIG

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-e7be-4338-8e06-ae5851914a22)
3. [Trigger](ms-xhelp:///?Id=beckhoff-334d-418e-a4b1-6bbcecdb9ff6)
4. F\_TRIG

# F\_TRIG

![15047603](/tcplclib_tc2_standard/1033/Images/png/74429323__Web.png)

Detector for a Falling Edge

## VAR\_INPUT

```
VAR_INPUT  
     CLK : BOOL; (* Signal to detect *)  
END_VAR
```

## VAR\_OUTPUT

```
VAR_OUTPUT  
     Q : BOOL; (* Edge detected *)  
END_VAR
```

The output Q will remain FALSE as long as the input variable CLK returns TRUE. As soon as CLK returns FALSE, Q will return TRUE. This means each time the function is called up, Q will return FALSE until CLK has a rising followed by a falling edge.

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
