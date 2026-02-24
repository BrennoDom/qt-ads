# Fast Axis Stop

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Fast Axis Stop

## Fast Axis Stop

![33461405](/tf50x0_tc3_nc_ptp/1033/Images/png/3360100235__Web.png)![32717189](/tf50x0_tc3_nc_ptp/1033/Images/png/3360103435__Web.png)![26019245](/tf50x0_tc3_nc_ptp/1033/Images/png/3360119435__Web.png)

Usually a stop is triggered by PLC code using `MC_Stop`. However, there are special applications within that the time delay of stop has to be as small as possible. Within this situation the input Drive.Inputs.In.nState4 comes into play triggering a stop directly without being mapped via the PLC process image.

![32846614](/tf50x0_tc3_nc_ptp/1033/Images/png/3360091787__Web.png)

Drive Status 4 (manually linked):
  
0x80 (1000 0000) = Fast Axis Stop (digital IO interrupt)

**Variable nState4**

The variable Drive.Inputs.In.nState4 can be mapped to any event source. Note its data type `USINT` and the bit nState4.7 being responsible for the Fast Axis Stop.

**Fast Axis Stop**

For an axis the Fast Axis Stop is performed when its Drive.Inputs.In.nState4.7 variable exhibits the signal type that is selected within the drop-down list "Fast Axis Stop Signal Type (optional)" and differs from “OFF (default)”.

**Signal Type**

The “Fast Axis Stop Signal Type (optional)” enumeration specifies six elements:

* OFF (default)
    
  For any signal type that the Drive.Inputs.In.nState4.7 variable exhibits no Fast Axis Stop is performed.
* Rising Edge
    
  A Fast Axis Stop is performed when the Drive.Inputs.In.nState4.7 bit exhibits a rising edge.
* Falling Edge
    
  A Fast Axis Stop is performed when the Drive.Inputs.In.nState4.7 bit exhibits a falling edge.
* Both Edges
    
  A Fast Axis Stop is performed when the Drive.Inputs.In.nState4.7 bit exhibits a rising edge and a falling edge, respectively. Alternatively, a Fast Axis Stop is performed when the Drive.Inputs.In.nState4.7 bit exhibits a falling edge and a rising edge, respectively.
* High Active
    
  A Fast Axis Stop is performed when the Drive.Inputs.In.nState4.7 bit appears high active.
* Low Active
    
  A Fast Axis Stop is performed when the Drive.Inputs.In.nState4.7 bit appears low active.

**Optional**

An optional fast axis parameter has to differ from zero to be applied when a Fast Axis Stop is performed.

**Acceleration, Deceleration, Jerk**

When a Fast Axis Stop is performed on the corresponding axis within the boundaries prescribed by the “Maximum Dynamics” the “Fast Acceleration (optional)” float value accelerates the axis, the “Fast Deceleration (optional)” float value decelerates the axis and the “Fast Jerk (optional)” float value is applied.  
When a Fast Axis Stop is not performed, not any fast axis parameter is applied.

## Additional Information: `MC_Stop`

Following

* [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc) or  
  https://infosys.beckhoff.com/content/1033/tcplclib\_tc2\_mc2/index.html

you can find further information on `MC_Stop`.
