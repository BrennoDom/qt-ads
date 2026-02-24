# MC_AxUtiAverageDerivative_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Utilities](ms-xhelp:///?Id=beckhoff-05d5-4e7a-847c-eea5a0277852)
5. [Filters](ms-xhelp:///?Id=beckhoff-389e-4cef-894c-4e355003dfea)
6. MC\_AxUtiAverageDerivative\_BkPlcMc (from V3.0)

# MC\_AxUtiAverageDerivative\_BkPlcMc (from V3.0)

![64745266](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854841739__Web.gif)

The function block determines the derivative of a value through numeric differentiation over more than one cycle.

```
VAR_INPUT  
    Input:      LREAL:=0.0;  
    MinIdx:     DINT:=0;  
    MaxIdx:     DINT:=0;  
    pBuffer:    POINTER TO LREAL:=0;  
END_VAR
```

```
VAR_OUTPUT  
    Output:     LREAL:=0.0;  
    Error:      BOOL:=FALSE;  
    ErrorID:    UDINT:=0;  
END_VAR
```

```
VAR_INOUT  
    Axis:       Axis_Ref_BkPlcMc;  
END_VAR
```

**Input**: The raw value of the parameter to be filtered.

**MinIdx**: The index of the first filter buffer element to be used.

**MaxIdx**: The index of the last filter buffer element to be used.

**pBuffer**: The address of the first filter buffer element.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

**Output**: The filtered value.

**Error**: This output indicates problems with the transferred parameters.

**ErrorID**: In the event of an error, coded information about the type of problem is reported here.

## Behaviour of the function block

With each call the function block checks the address of the filter buffer **pBuffer** and the indices of the elements **MinIdx** and **MaxIdx** to be used. **If the transferred values are obviously nonsensical, the system responds with Error** and coded information in ErrorID. Otherwise, with each call **Input** is entered in the filter buffer, and the average value of the modification over the set of values available in the buffer is formed and returned as **Output**.

|  |  |
| --- | --- |
| 45836489 | The set of values for averaging contains (MaxIdx - MinIdx + 1) values. The measuring time is determined by multiplication of this number with the cycle time. |

|  |  |
| --- | --- |
| 9875225 | The principle of sliding averaging leads to a delay amounting to half the measuring time. If the filtered parameter can be used in a control loop, the resulting frequency-dependent phase shift can lead to restrictions for the parameter selection. |

|  |  |
| --- | --- |
| 21768161 | The function block has no way to fully check the transferred values of pBuffer, MinIdx and MaxIdx. The user must ensure that these values can be used safely. Otherwise may behave in an unpredictable manner (overwriting of memory) or abortion of the PLC operation. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
