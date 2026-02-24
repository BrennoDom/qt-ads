# Data type MC_InterpolationType

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Data type](ms-xhelp:///?Id=beckhoff-61cc-4984-82a9-77a1e817705f)
3. Data type MC\_InterpolationType

# Data type MC\_InterpolationType

Interpolation mode for position tables (cam plates). Position tables consist of a list of master and slave positions between which interpolation can take place in different ways.

The interpolation type is not used for extended cam plates (motion functions).

```
TYPE MC_InterpolationType :  
(  
   (* linear 2 point interpolation *)  
   MC_INTERPOLATIONTYPE_LINEAR             := 0,  
  
   (* no longer supported - 4 point interpolation (for equidistant tables only) *)  
   MC_INTERPOLATIONTYPE_4POINT             := 1,  
  
   (* spline interpolation (tangential or cyclic depending on table) *)  
   MC_INTERPOLATIONTYPE_SPLINE             := 2,  
  
   (* moving cubic spline interpolation with n sampling points ('local spline') *)  
   MC_INTERPOLATIONTYPE_SLIDINGSPLINE      := 3  
);  
END_TYPE
```

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
