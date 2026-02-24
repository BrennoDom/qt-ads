# MC_BufferMode

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Motion](ms-xhelp:///?Id=beckhoff-2107-47ed-8b8e-b9259019655e)
4. MC\_BufferMode

# MC\_BufferMode

This data type is used with various function blocks of the Motion Control library. BufferMode is used to specify how successive motion commands are to be processed.

```
TYPE MC_BufferMode :  
 (  
    MC_Aborting,  
    MC_Buffered,  
    MC_BlendingLow,  
    MC_BlendingPrevious,  
    MC_BlendingNext,  
    MC_BlendingHigh  
 );  
END_TYPE
```

|  |  |
| --- | --- |
| 57177053 | A second function block is always required to use the BufferMode. It is not possible to trigger a move function block with new parameters while it is active. |

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-8c0b-4b22-91c9-62cc025540bd)

**Examples:**

In the following example, a move command is used to move an axis from position P0 to P1 and then to P2. The second command is issued during the movement to P1, but before the braking ramp with different BufferModes. The reference point for the different velocity profiles is always P1. The mode specifies the velocity v1 or v2 at this point.

![44831437](/tcplclib_tc2_mc2/1033/Images/png/9007199325099403__en-US__Web.png)

Since the speed of the first command is lower than the second, the modes BlendingLow/BlendingPrevious and BlendingHigh/BlendingNext have the same result.

The difference in the next example is that the speed of the second command is lower than the first. Now, the modes BlendingLow/BlendingNext and BlendingHigh/BlendingPrevious are equivalent.

![829755](/tcplclib_tc2_mc2/1033/Images/png/18014399559118475__en-US__Web.png)

The velocity profiles described here assume that the following command is issued in time, i.e. before the braking ramp of the first command. Otherwise, blending is implemented as best as possible.

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
