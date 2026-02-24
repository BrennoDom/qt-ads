# Torque and Acceleration Scaling

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Torque and Acceleration Scaling

![46232835](/tf50x0_tc3_nc_ptp/1033/Images/png/3458616971__Web.png)![13442339](/tf50x0_tc3_nc_ptp/1033/Images/png/3458620171__Web.png)![53872188](/tf50x0_tc3_nc_ptp/1033/Images/png/3458623371__Web.png)

This group of parameters creates an optional acceleration as a servo control that is supposed to act before a lag distance evolves. It may set e.g. a torque value.

## Input Scaling Factor (Actual Torque)

The gain factor for the optional servo control.

## Input P-T1 Filter Time (Actual Torque)

Time for the P-T1 filter. This time comes as an input to the P-T1 filter.

## Input P-T1 Filter (Actual Torque Derivative)

Derivative of the actual torque to be scaled. This derivative comes as an input to the P-T1 filter.

Consult section [PT1 Filter](ms-xhelp:///?Id=beckhoff-603d-4393-806e-9faf331d20fd) for more information on a PT1 filter.

![15087649](/tf50x0_tc3_nc_ptp/1033/Images/png/3458616971__Web.png)![1571113](/tf50x0_tc3_nc_ptp/1033/Images/png/3458620171__Web.png)![14140023](/tf50x0_tc3_nc_ptp/1033/Images/png/3458693771__Web.png)![60151347](/tf50x0_tc3_nc_ptp/1033/Images/png/3458690571__Web.png)

## Output Scaling Factor (Torque)

Sometimes an optional output scaling for torque is needed.

## Output Delay (Torque)

The output of the torque value can be delayed by the Output Delay (Torque) time.

## Output Scaling Factor (Acceleration)

Sometimes an optional output scaling for acceleration is needed. (E.g. for NC acceleration feedforward. Consult section [Acceleration Feedforward](ms-xhelp:///?Id=beckhoff-ab53-49d4-aa94-e8195f14f93e) for more information on acceleration feedforward.)

## Output Delay (Acceleration)

The output of the acceleration value can be delayed by the Output Delay (Acceleration) time.
