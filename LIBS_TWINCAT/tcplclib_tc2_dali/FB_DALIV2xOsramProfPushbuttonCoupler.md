# FB_DALIV2xOsramProfPushbuttonCoupler

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Third-party function blocks](ms-xhelp:///?Id=beckhoff-3be5-46f6-9609-796403dd277e)
5. [Osram](ms-xhelp:///?Id=beckhoff-fa65-48df-983a-fc5ad4abfc00)
6. FB\_DALIV2xOsramProfPushbuttonCoupler

# FB\_DALIV2xOsramProfPushbuttonCoupler

![52733512](/tcplclib_tc2_dali/1033/Images/gif/4528355339__Web.gif)

|  |  |
| --- | --- |
| 4839561 | This function block is used as an example and is not included in the library. The function block can be downloaded as an export file and imported into the desired project. Adjustments can be made as required. |

This function block evaluates the status of the digital input of the Osram DALI Professional Pushbutton Coupler. This function block can also be used to initialize the DALI control units.

The DALI control unit has a short address. The device does not fully comply with the IEC 62386 standard and uses a company-specific protocol instead.

TwinCAT 3 PLCopenXML file download: [FB\_DALIV2xOsramProfPushbuttonCoupler.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_dali/Resources/zip/9007203783126923.zip)

## VAR\_INPUT

```
bInitialize       : BOOL := FALSE;  
nAddr             : BYTE;
```

**bInitialize:** The DALI controller is initialized via a positive edge at this input. The parameters are written to the DALI control unit, which must be accessible via the short addresses *nPIRAddr* and *nLSAddr*. The output *bInitializing* is TRUE during initialization.

**nAddr**: Short address of the DALI control unit.

Further details about the parameters can be found in the manufacturer's documentation.

## VAR\_OUTPUT

```
bInitializing     : BOOL;  
bError            : BOOL;  
nErrorId          : UDINT;  
nDeviceStatus     : BYTE;  
bPushbutton       : BOOL;
```

**bInitializing:** This output is TRUE during initialization.

**bError**: This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *nErrorId*.

**nErrorId**: Contains the command-specific error code of the most recently executed command. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

**nDeviceStatus**: Before the initialization, the status of the DALI control unit is queried and output to this output.

**bPushbutton:** This output indicates the actual value of the digital input.

## VAR\_IN\_OUT

```
stCommandBuffer   : ST_DALIV2CommandBuffer;
```

**stCommandBuffer**: Reference to the internal structure for communication with the function block [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250) (KL6821).

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.4 | Tc2\_DALI from v3.6.2.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
