# Setpoint Generator

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Setpoint Generator

![38732217](/tf50x0_tc3_nc_ptp/1033/Images/png/3362626059__Web.png)![13045638](/tf50x0_tc3_nc_ptp/1033/Images/png/3362629259__Web.png)![50301879](/tf50x0_tc3_nc_ptp/1033/Images/png/3362632459__Web.png)

## Setpoint Generator Type

The only available option is “7 Phases (optimized)”.

![50063735](/tf50x0_tc3_nc_ptp/1033/Images/png/3362626059__Web.png)![47920438](/tf50x0_tc3_nc_ptp/1033/Images/png/3362629259__Web.png)![28630766](/tf50x0_tc3_nc_ptp/1033/Images/png/3362635659__Web.png)

## Velocity Override Type

Reduced (iterated): The override is based on the maximum velocity of the profile calculated by the setpoint generator. Confer to parameter description at “MOTION | NC-Task 1 SAF | Axes | Axis 1 | Maximum Dynamics | [Maximum Velocity](ms-xhelp:///?Id=beckhoff-40af-439d-a23e-40da5efead15)”.

Original (iterated): The override is based on the maximum parameterized velocity of the actual command currently performed. Thus, it can happen that e.g. 80 percent override and 100 percent override result in the same nominal velocity.

Look at section [Path Override (Interpreter Override Types)](ms-xhelp:///?Id=beckhoff-3be7-4fd0-b323-0de696cbf5c3) for more information on path override.
