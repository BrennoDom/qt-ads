# Optional Position Command Output Smoothing Filter

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Optional Position Command Output Smoothing Filter

![52869820](/tf50x0_tc3_nc_ptp/1033/Images/png/3468204811__Web.png)![6066333](/tf50x0_tc3_nc_ptp/1033/Images/png/3468208011__Web.png)![54597003](/tf50x0_tc3_nc_ptp/1033/Images/png/3468211211__Web.png)

## Smoothing Filter Type and Smoothing Filter Time

When

* ‘OFF (default)’

is selected position command output smoothing is deactivated.

As filter types

* `‘Moving Average’` or
* `‘P-Tn’`

can be selected. Both modes refer to the position setpoint value.

`‘Moving Average’`: As an output the Moving Average Filter creates an average over a set of position setpoint values that comes as an input to the filter. Thereby, the Smoothing Filter Time prescribes the time interval over that the average spans. Values of the input set are created by position setpoint generation. Thus, the value generation frequency is determined by the cycle time of the task generating the setpoint values.  
When a new value is generated e.g. each 1ms and the Smoothing Filter Time is set to e.g. 20ms an average is taken over 20 values. Thereby, the influence of a setpoint value is perceptible for 20ms.

`‘P-Tn’`: As an output the P-Tn Filter creates an average over a set of position setpoint values that comes as an input to the filter. Thereby, the Smoothing Filter Time prescribes the time constant of the P-Tn Filter. Values of the input set are created by position setpoint generation. Thus, the value generation frequency is determined by the cycle time of the task generating the setpoint values.

## Smoothing Filter Order (P-Tn only)

The order of the employed P-Tn smoothing filter.

## Smoothing Filter

In some applications position command output smoothing is used to reduce vibrations of machine parts. This smoothing forms an additional filter that should be handled with care. This filter cannot be compensated by a static dead time.
