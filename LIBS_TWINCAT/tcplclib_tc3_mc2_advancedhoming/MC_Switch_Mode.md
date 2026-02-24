# MC_Switch_Mode

## Library
tcplclib_tc3_mc2_advancedhoming

## Category
Motion Control

# MC\_Switch\_Mode

```
TYPE MC_Switch_Mode :  
(  
    mcOn                  := 1,  
    mcOff                 := 2,  
    mcRisingEdge          := 3,  
    mcFallingEdge         := 4,  
    mcEdgeSwitchPositive  := 5,  
    mcEdgeSwitchNegative  := 6,  
    mcRisingEdgeInverse   := 11,  
    mcFallingEdgeInverse  := 12  
) UDINT;  
END_TYPE
```

Condition for the sensor signal to stop the step function.

| Name | Description |
| --- | --- |
| mcOn | Sensor is ON. |
| mcOff | Sensor is OFF. |
| mcRisingEdge | Rising edge in resulting direction for sensor signal OFF. |
| mcFallingEdge | Falling edge in resulting direction for sensor signal OFF. |
| mcEdgeSwitchPositive | Edge depends on moving direction. Rising edge in positive moving direction. Falling edge in negative direction. |
| mcEdgeSwitchNegative | Edge depends on moving direction. Falling edge in positive moving direction. Rising edge in negative direction. |
| mcRisingEdgeInverse | Rising edge in opposite resulting direction for sensor signal OFF. |
| mcFallingEdgeInverse | Falling edge in opposite resulting direction for sensor signal OFF. |
