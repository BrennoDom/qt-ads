# Characteristic curve measurement

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e)
3. [Commissioning](ms-xhelp:///?Id=beckhoff-89eb-40cd-9eeb-3b237fbc590a)
4. Characteristic curve measurement

# Characteristic curve measurement

The characteristic curve measurement ([MC\_AxUtiAutoIdent\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6e26-4519-a6b1-d0581db76054)) not only determines the characteristic curve itself, but also the reference velocity, the velocity ratio and the optional travel distance limits. For more information on the setting options, see the function block itself.

The reference velocity should be preset to an approximate plausible value. One possibility is to calculate the smaller cylinder area (A [mm²]) with the nominal volume flow (Qn [l/min)] of the valve:

Vref:= Qn\*1.000.000/60/ A

The **LinDef** tab can be used to implement various settings. Further information can be found here.

If this is activated, the AutoIdent function block starts by first determining the travel limits. The axis is then positioned at a distance of at least 10 % from the travel limits, in order to determine the overlap. Once this has been carried out successfully, the axis moves to the lower end and starts measuring. Depending on the available travel path, several measurements are carried out in each direction.

Once the characteristic curve has been successfully measured, it can be viewed in the **LinTab** tab. A successfully measured characteristic curve can be recognized by the fact that stParams.bLinTabAvaiable is TRUE.

The chapter Coverage and reference velocity should be skipped if the characteristic curve was measured successfully.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
