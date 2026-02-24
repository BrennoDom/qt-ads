# Data type MC_CAM_REF

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Data type](ms-xhelp:///?Id=beckhoff-61cc-4984-82a9-77a1e817705f)
3. Data type MC\_CAM\_REF

# Data type MC\_CAM\_REF

```
TYPE MC_CAM_REF :  
STRUCT  
   pArray      : UDINT;   
   ArraySize   : UDINT;   
   TableType   : MC_TableType;  
   NoOfRows    : UDINT;  
   NoOfColumns : UDINT;  
END_STRUCT  
END_TYPE
```

The data structure *MC\_CAM\_REF* describes the data memory of a cam plate in a further PLC variable (array).

The first parameter *pArray* is a pointer to a data structure containing the cam plate data. The data structure depends on the table type *nTableType*. The number of rows is entered in the component nNoOfRows, the number of columns in nNoOfCols (usually 1 or 2).

Example 1: Position table structure description

|  |  |
| --- | --- |
| **pArray** | Address of a two-dimensional array. The first column contains an ascending list of master positions. The second column contains the associated slave positions. The address can be assigned with the ADR function.  Example:  Table1: ARRAY[0..360, 0..1] OF LREAL;  pArray := ADR( Table1 ); |
| **ArraySize** | Storage capacity of the two-dimensional array, which can be determined with the SIZEOF function.  Example:  ArraySize := SIZEOF( Table1 ); |
| **TableType** | The table [type](ms-xhelp:///?Id=beckhoff-ab33-42a6-ae57-69a7ddde9748) is MC\_*TABLETYPE\_EQUIDISTANT*, if the master positions have the same distance  or  *MC\_TABLETYPE\_NONEQUIDISTANT* it the distance is variable. |
| **NoOfRows** | The number or rows corresponds to the number of table points. |
| **NoOfColumns** | The number of columns is 2. |

Example 2: Structure description of a motion function

|  |  |
| --- | --- |
| **pArray** | Address of a one-dimensional array of type [MC\_MotionFunctionPoint](ms-xhelp:///?Id=beckhoff-c619-429a-8502-a3ccba350b60). Each array element contains a description of a cam plate interpolation point.  Example:  MotionFunction: ARRAY[1..10] OF MC\_MotionFunctionPoint;  pArray := ADR( MotionFunction ); |
| **ArraySize** | Storage capacity of the one-dimensional array, which can be determined with the SIZEOF function.  Example:  ArraySize := SIZEOF( MotionFunction ); |
| **TableType** | The table type is *MC\_TABLETYPE\_MOTIONFUNCTION*. |
| **NoOfRows** | The number or rows corresponds to the number of table points. |
| **NoOfColumns** | The number of columns is 1. |

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
