# CSVFIELD_TO_ARG

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# CSVFIELD\_TO\_ARG

![66962839](/tcplclib_tc2_utilities/1033/Images/gif/35731083__en-US__Web.gif)

The function converts the value from a data field in CSV format which is present as byte buffer into a PLC variable. Double quotation marks in the data field are replaced with simple quotation marks. If the bQM parameter is set (QM = quotation marks) the outer quotation marks (around the data field) are removed from the input data. If successful the function returns the length of the converted data. In the event of an error or if the length of the input data is zero the function returns the value zero. The application must ensure the PLC target variable is large enough to accommodate the value.

The function is usually used together with the function block [FB\_CSVMemBufferReader](ms-xhelp:///?Id=beckhoff-1a3d-4151-8c6a-22708123ce55) in order to read (parse) data sets that are stored in the PLC memory in CSV format. Before this operation the CSV data sets are usually read from a file into the PLC memory. In contrast to the [CSVFIELD\_TO\_STRING](ms-xhelp:///?Id=beckhoff-bac9-42bb-a52d-ef0812cb7833) function this function can also be used to convert CSV data fields with binary data into PLC variables.

## FUNCTION CSVFIELD\_TO\_ARG: UDINT

## VAR\_INPUT

```
VAR_INPUT  
    pInput   : POINTER TO BYTE;  
    cbInput  : UDINT;  
    bQM      : BOOL;  
    out      : T_Arg;  
END_VAR
```

**pInput**: Start address (pointer) to a byte buffer containing the data field to be converted in CSV format. The address can be determined with the ADR operator.

**cbInput**: Length of the data field to be converted in bytes. The length can be determined with the SIZEOF operator.

**bQM:** If this input is TRUE the enclosing quotation marks are removed from the field data.

**out :** PLC target variable into which the value of the data field is to be written (type: [T\_Arg](ms-xhelp:///?Id=beckhoff-9414-4e02-83ee-fc21ca340682)).

**Example:**

See example in the documentation for the [ARG\_TO\_CSVFIELD](ms-xhelp:///?Id=beckhoff-2037-4b5d-879e-e8cb560a011f) function block.

Further information can be found here: [Example: Writing/reading of a CSV file](ms-xhelp:///?Id=beckhoff-5087-4506-bf25-3cb1667c44bf).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
