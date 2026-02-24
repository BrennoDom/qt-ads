# Acceleration Feedforward

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Acceleration Feedforward

In addition to proportional feedback of the following error nearly all position controllers contain a proportional acceleration feedforward: The `K_a` factor. This acceleration feedforward should normally only be used in association with the proportional component of the position controller: The `K_v` factor. Acceleration feedforward control requires to adjust the axis for strict symmetry:

* When stationary, the following error is symmetrical about `0` (DAC offset).  
  Confer section [Automatic DAC Offset Adjustment](ms-xhelp:///?Id=beckhoff-e011-4d4c-8c0b-2286f7bde86d).
* When moving steadily, the following error is symmetrical about `0` (reference velocity).
* Set `K_v`.
* Measure the extreme value of the acceleration `a_+max` and the associated following error `d_+max` in the middle of the acceleration phase. Measure the extreme value of the deceleration `a_-max` and the associated following error `d_-max` in the middle of the braking phase.
* `K_a+ = K_v * d_+max / a_+max`,  
  `K_a- = K_v * d_-max / a_-max`,  
  `K_a = (K_a+ + K_a-) / 2`.
