# ST_TcPlcInputAnalog (from V3.0.44)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. ST\_TcPlcInputAnalog (from V3.0.44)

# ST\_TcPlcInputAnalog (from V3.0.44)

This structure contains variables for the evaluation of analog inputs.

```
                            TYPE ST_TcPlcInputAnalog :  
(* last modification: 20.02.2019 *)  
STRUCT  
    nADC:            DINT;  
    nOpState:        INT;   
    bWcState:        BOOL;  
END_STRUCT  
END_TYPE
```

**bWcState:** This signal indicates a problem with continuous data exchange with the terminal.

**nOpState:** This signal indicates the operating state of the terminal.

**nADC:** The actual value is displayed here.

|  |  |
| --- | --- |
| 24619602 | If this value is determined with a 16-bit terminal, it must be adapted. If it is a signed value (e.g. from a ±10 V terminal), it must be assigned with a type conversion INT\_TO\_DINT(). This automatically extends the sign to the upper 16 bits with the correct type. Otherwise negative values are interpreted as very large positive values. If only positive values occur, this can be omitted. In this case, direct mapping from 16 to 32 bit can be used, since the upper 16 bits remain unaffected. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
