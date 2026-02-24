# CSVFIELD_TO_STRING

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# CSVFIELD\_TO\_STRING

![65794642](/tcplclib_tc2_utilities/1033/Images/gif/35727883__en-US__Web.gif)

The function converts a data field in CSV data field format that is present as a source string into a value in PLC string format. Double quotation marks in the data field are replaced with simple quotation marks. If the bQM parameter is set (QM = quotation marks) the outer quotation marks (around the data field) are removed from the source string. If successful the function returns the convert string as the result. The function returns an empty string if an error occurred during the conversion, but only if the source string was not an empty string.

The function is usually used together with the function block [FB\_CSVMemBufferReader](ms-xhelp:///?Id=beckhoff-1a3d-4151-8c6a-22708123ce55) in order to read (interpret) data sets that are stored in the PLC memory in CSV format. Before this operation the CSV data sets are usually read from a file into the PLC memory. The source string must not contain binary data. Binary data with the value zero would terminate and truncate the string in the wrong place. To convert data fields with binary data please use the function: [CSVFIELD\_TO\_ARG](ms-xhelp:///?Id=beckhoff-ecdd-4181-86b0-997b40f67d70).

## FUNCTION CSFIELD\_TO\_STRING: T\_MaxString

## VAR\_INPUT

```
VAR_INPUT  
    in  : T_MaxString;  
    bQM : BOOL;  
END_VAR
```

**in**: Source string with a data field in CSV format that is to be converted into a value in PLC string format (type: T\_MaxString).

**bQM**: If this input is TRUE the enclosing quotation marks are removed from the source string.

| bQM | Description | Source string | Result string | CSV-compliant |
| --- | --- | --- | --- | --- |
| FALSE | Source string without enclosing quotation marks should only contain letters and numbers. In this case the source string must not contain any non-printable control character, quotation marks, semicolons, commas (US CSV format) or binary data. | 'Module\_XA5'  '123456'  '' | 'Module\_XA5'  '123456'  '' | Yes  Yes  Yes |
| 'A""""B' | 'A""B' | No |
| 'A""B' | 'A"B' | No |
| ';' | ';' | No |
| '$R$N' | '$R$N' | No |
| 'AB$00CD' | 'AB' (string was truncated) | No |
| TRUE | A source string that is not enclosed in quotation marks should not contain any non-printable control character, quotation mark, semicolon or comma (US CSV format). Binary data are not permitted. | '"Module\_XA5"' | 'Module\_XA5' | Yes |
| '"123456"' | '123456' | Yes |  |
| '""' | '' | Yes |  |
| '"A""""B"' | 'A""B' | Yes |  |
| '"A""B"' | 'A"B' | Yes |  |
| '";"' | ';' | Yes |  |
| '"$R$N"' | '$R$N' | Yes |  |
| '"AB$00CD"' | 'AB' (string was truncated) | No |  |

**Example:**

```
PROGRAM MAIN  
VAR  
    s1 : STRING;  
    s2 : STRING;  
END_VAR
```

```
s1 := CSVFIELD_TO_STRING( '"ab_$04_$05_cd-""ALFA""_5"', TRUE );  
s2 := CSVFIELD_TO_STRING( 'Module_50', FALSE );
```

The result:

s1 = 'ab\_$04\_$05\_cd-"ALFA"\_5'

s2 = 'Module\_50'

Further information can be found here: [Example: Writing/reading of a CSV file](ms-xhelp:///?Id=beckhoff-5087-4506-bf25-3cb1667c44bf).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
