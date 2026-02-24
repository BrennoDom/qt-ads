# E_PositionOffsetMemory

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# E\_PositionOffsetMemory

```
TYPE E_PositionOffsetMemory :(  
 ePositionOffsetMemory_Encoder := 0  
 ePositionOffsetMemory_Drive   := 1  
) BYTE;  
END_TYPE
```

**ePositionOffsetMemory\_Encoder:** As memory for the new position offset the motor name plate of the encoder is selected.

**ePositionOffsetMemory\_Drive:** As memory for the new positions offset the internal memory of the drive is selected.
