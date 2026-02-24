# Example programs

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. Example programs

# Example programs

## Electronic Cam Tables

The example program couples a master and a slave axis via cam plates. During the coupled movement cam plates are switched, individual sampling points of a cam plate are modified, and the cam plate is scaled.

The example program requires the Tc2\_MC2\_Camming library and operates fully in simulation mode. Progress can be monitored in the included TwinCAT Measurement project.

Click here to save the example program:

[Sample Camming.zip](https://infosys.beckhoff.com/content/1033/tf5050_tc3_nc_camming/Resources/zip/9007201825006347.zip)

## Rotary Knife and Registration

The sample uses a rotational knife to cut sheets of a defined length. For this purpose the circumference speed must be synchronized with the web while cutting a sheet. The rotation knife must the accelerator or deceleration since the circumference of the knife is different from the sheet length. Registration marks are used to synchronize with the product. The knife is continuously adjusted to compensate small differences caused by temperature or stretching.

An electronic cam table is used to synchronize the rotational knife with the material. The cam table is a normalized cam table defined with a length of 360°. The tool moves over a full turn while the cam table is executed and the cut position is defined as 0°. The circumference speed is synchronous from 270° to 30°. The range from 30° to 270° is used to adjust the operation to the actual distance of registration marks.

[Sample Rotary Knife.zip](https://infosys.beckhoff.com/content/1033/tf5050_tc3_nc_camming/Resources/zip/9007201825008011.zip)

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
