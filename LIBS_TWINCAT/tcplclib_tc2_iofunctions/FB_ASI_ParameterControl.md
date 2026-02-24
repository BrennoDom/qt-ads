# FB_ASI_ParameterControl

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [ASI master terminal](ms-xhelp:///?Id=beckhoff-eee2-417f-9360-0c5cf67a2427)
4. FB\_ASI\_ParameterControl

# FB\_ASI\_ParameterControl

![58129833](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314171659__Web.png)

The FB\_ASI\_ParameterControl realizes the background communication between the ASI master terminal and the individual blocks of the Lib.

|  |  |
| --- | --- |
| 53406450 | Call the block  This block must always be called cyclically |

```
VAR_IN_OUT  
    stParameterBuffer : ST_ParameterBuffer;  
    stParameter_IN    : ST_Parameter_IN;  
    stParameter_OUT   : ST_Parameter_OUT;  
END_VAR
```

**stParameterBuffer**: Data buffer for the background communication (type: [ST\_ParameterBuffer](ms-xhelp:///?Id=beckhoff-24d8-4a67-bc8c-6e338fc526cd)).

**stParameter\_IN**: Input data from the ASI terminal (type: [ST\_Parameter\_IN](ms-xhelp:///?Id=beckhoff-605e-4da9-9a46-e5b65b21794c)).

**stParameter\_OUT**: Input data from the ASI terminal (type: [ST\_Parameter\_OUT](ms-xhelp:///?Id=beckhoff-ed18-40be-a42e-4558b79a69a9)).

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86) | ASI master terminal | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
