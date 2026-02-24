# ST_CamSwitchOptions

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# ST\_CamSwitchOptions

| Name | Type | Description |
| --- | --- | --- |
| EncoderIndex | UINT | If more than one encoder is connected to the axis, the encoder index [0 – 9] can be defined here. The first encoder has the index 0.  No subindex can be specified for Path function blocks that refer to multiple interpolated axes. |
| UseAcceleration | BOOL | UseAcceleration can be set to TRUE in order to incorporate the acceleration of the axis into the position calculation. UseAcceleration can be advantageous if the setpoint values of the acceleration can be used. UseAcceleration may be disadvantageous with encoder axes that supply a noisy position signal, because the acceleration is also erroneous. |
