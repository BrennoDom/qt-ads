# PT1 Filter

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# PT1 Filter

A PT1 filter is a transfer function that performs convex interpolation between a new value `x_n` and an old value (from one cycle before) `x_a`. The filter time parameter, a nonnegative value in the unit of seconds, has to be entered into the calculation. If `I = SAF cycle time / (SAF cycle time + filter time)`, then `x = I * x_n + (1-I) * x_a`. The filter time should be finite. For the filter time being a positive value `I` resides within the open interval from `0` to `1`. If the filter time is close to `0.0`, the new value has a high weighting. If the filter time is long, the older value has a relatively high weighting.
