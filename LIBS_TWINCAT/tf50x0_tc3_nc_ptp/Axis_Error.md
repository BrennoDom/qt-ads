# Axis Error

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Axis Error

The variables `axis.Status.Error` and `axis.Status.ErrorID` belong to the `ST_AxisStatus` data structure.

The boolean variable `axis.Status.Error` displays the StateDWord bit 31 and refers to the axis error state. When the boolean variable `axis.Status.Error` is `TRUE`, it indicates that there is an error for the axis.

The variable `axis.Status.ErrorID` of data type `UDINT` refers to the error ID of the reported error and displays the axis error code.
