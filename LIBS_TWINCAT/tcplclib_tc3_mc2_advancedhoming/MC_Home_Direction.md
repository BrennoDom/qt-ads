# MC_Home_Direction

## Library
tcplclib_tc3_mc2_advancedhoming

## Category
Motion Control

# MC\_Home\_Direction

```
TYPE MC_Home_Direction :  
(  
    mcPositiveDirection := 1,  
    mcNegativeDirection := 3,  
    mcSwitchPositive    := 5,  
    mcSwitchNegative    := 7  
);  
END_TYPE
```

| Name | Description |
| --- | --- |
| mcPositiveDirection | Movement always starts in the logically positive direction of movement. The movement direction can be reversed on reaching a movement range limit sensor or on reaching the precondition and when using mcRisingEdgeInverse or mcFallingEdgeInverse for the input of the type MC\_Switch\_Mode existing in some function blocks. |
| mcNegativeDirection | Movement always starts in the logically negative direction of movement. The movement direction can be reversed on reaching a movement range limit sensor or on reaching the precondition and when using mcRisingEdgeInverse or mcFallingEdgeInverse for the input of the type MC\_Switch\_Mode existing in some function blocks. |
| mcSwitchPositive | The direction of movement at the start depends on the current switching state of the sensor.   * If the switching state of the sensor is OFF, the movement starts in logical positive direction of movement * If the switching state of the sensor is ON, the movement starts in the logically negative direction.   The movement direction can be reversed on reaching a movement range limit sensor or when the sensor switching state changes. |
| mcSwitchNegative | The direction of movement at the start depends on the current switching state of the sensor.   * If the switching state of the sensor is OFF, the movement starts in logical negative direction of movement. * If the switching state of the sensor is ON, the movement starts in the logically negative direction.   The movement direction can be reversed on reaching a movement range limit sensor or when the sensor switching state changes. |
