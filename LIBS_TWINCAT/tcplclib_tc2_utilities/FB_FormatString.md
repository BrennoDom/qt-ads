# FB_FormatString

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_FormatString

![64205424](/tcplclib_tc2_utilities/1033/Images/png/9007199290235275__Web.png)

This function block can be used for converting up to 10 arguments (similar to fprintf) into a string and formatting them according to the [format specification](ms-xhelp:///?Id=beckhoff-e500-4c67-ba3d-fe4b073be6e3). Formatting occurs in the same PLC cycle, i.e. the output string is available immediately after the FB was called.

## VAR\_INPUT

```
VAR_INPUT  
    sFormat   : T_MaxString;  
    arg1      : T_Arg;  
    arg2      : T_Arg;  
    arg3      : T_Arg;  
    arg4      : T_Arg;  
    arg5      : T_Arg;  
    arg6      : T_Arg;  
    arg7      : T_Arg;  
    arg8      : T_Arg;  
    arg9      : T_Arg;  
    arg10     : T_Arg;  
END_VAR
```

**sFormat**: Format specification as string (type: T\_MaxString)( e.g. '%+20.5f' or 'Measure X: %+..10d, Y: %+..10d' ).

arg1 to arg10: Arguments to be formatted (type: [T\_Arg](ms-xhelp:///?Id=beckhoff-9414-4e02-83ee-fc21ca340682)). The following auxiliary functions can be used for converting different types of PLC variables into the required data type [T\_Arg](ms-xhelp:///?Id=beckhoff-9414-4e02-83ee-fc21ca340682): [F\_BYTE](ms-xhelp:///?Id=beckhoff-d40f-4c2f-a0a9-d9581125e39f), [F\_WORD](ms-xhelp:///?Id=beckhoff-bf56-47a2-b979-8f8d1afba16a), [F\_DWORD](ms-xhelp:///?Id=beckhoff-08e6-4733-a65b-ffeb2bba9033), [F\_LWORD](ms-xhelp:///?Id=beckhoff-c9ce-42dd-99f5-1344a6bd2053), [F\_SINT](ms-xhelp:///?Id=beckhoff-b325-453e-ad3d-38b18f6a33da), [F\_INT](ms-xhelp:///?Id=beckhoff-8884-46d0-8401-e795f037a2cb), [F\_DINT](ms-xhelp:///?Id=beckhoff-a011-41ba-ac14-ddf227d9d3ec), [F\_LINT](ms-xhelp:///?Id=beckhoff-4138-4152-a8d3-6cd25a818ac9), [F\_USINT](ms-xhelp:///?Id=beckhoff-3296-4240-9ec5-2f84c4272563), [F\_UINT](ms-xhelp:///?Id=beckhoff-dc19-4c0e-9a2a-90a1c40e5430), [F\_UDINT](ms-xhelp:///?Id=beckhoff-9ba1-46a2-bb28-435ec870d7e2), [F\_ULINT](ms-xhelp:///?Id=beckhoff-3c34-4c70-a162-c672d8f68fa5), [F\_STRING](ms-xhelp:///?Id=beckhoff-6a77-44ce-a6fc-70c776b2fd5a), [F\_REAL](ms-xhelp:///?Id=beckhoff-9458-453d-8ade-48d9876779e4), [F\_LREAL](ms-xhelp:///?Id=beckhoff-c525-4b79-9cef-7e093c2ed20f).

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bError : BOOL;  
    nErrId : UDINT;  
    sOut   : T_MaxString;  
END_VAR
```

**bError**: This output is set if an error occurs during formatting.

**nErrId**: Returns the [format error code](ms-xhelp:///?Id=beckhoff-d559-4ad2-a5ba-469f9c5b3ce2) if the bError output is set.

**sOut**: If successful, this output returns the formatted output string (type: T\_MaxString)

**Example:**

```
PROGRAM MAIN  
VAR  
    fbFormat   : FB_FormatString;  
    iY         : DINT;  
    iX         : DINT;  
    bError     : BOOL;  
    nErrID     : UDINT;  
    sOut       : T_MaxString;  
END_VAR
```

```
iX := iX + 1;  
iY := iY + 1;  
fbFormat( sFormat := 'Measure X: %+.10d, Y: %+.10d', arg1 := F_DINT( iX ), arg2 := F_DINT( iY ), sOut => sOut, bError => bError, nErrID => nErrID );
```

The result:

sOut = 'Measure X: +0000000130, Y: +0000000130'

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
