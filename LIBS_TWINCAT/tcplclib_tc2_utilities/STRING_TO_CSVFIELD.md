# STRING_TO_CSVFIELD

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# STRING\_TO\_CSVFIELD

![65667169](/tcplclib_tc2_utilities/1033/Images/gif/35894283__en-US__Web.gif)

The function converts the value of a PLC string variable to a string data field in CSV format. Single quotation marks in the source string are replaced with double quotation marks. If the bQM parameter is set (QM = quotation marks) the outer quotation marks (around the CSV data field) are also added. If successful the function returns the convert string as the result. The function returns an empty string if an error occurred during the conversion, but only if the source string was not an empty string.

The function is usually used together with the function block [FB\_CSVMemBufferWriter](ms-xhelp:///?Id=beckhoff-aa85-4a67-bf7a-9380e201eead) to generate data sets in the PLC memory in CSV format. In the next step the memory content can be written to the file.

The source string must not contain binary data. Binary data with the value zero would terminate and truncate the string in the wrong place. To convert binary data please use the function: [ARG\_TO\_CSVFIELD](ms-xhelp:///?Id=beckhoff-2037-4b5d-879e-e8cb560a011f).

## FUNCTION STRING\_TO\_CSVFIELD: T\_MaxString

## VAR\_INPUT

```
VAR_INPUT  
    in  : T_MaxString;  
    bQM : BOOL;  
END_VAR
```

**in**: Source string whose value is to be converted into a data field in CSV format (type: T\_MaxString).

**bQM**: If this input is TRUE the enclosing quotation marks are added from the result string.

| bQM | Description | Source string | Result string | CSV-compliant |
| --- | --- | --- | --- | --- |
| FALSE | Source string without enclosing quotation marks should only contain letters and numbers. In this case the source string must not contain any non-printable control character, quotation mark, semicolon, comma (US CSV format) or binary data. |  |  |  |
| 'Module\_XA5' | 'Module\_XA5' | Yes |
| '123456' | '123456' | Yes |
| '' | '' | Yes |
| 'A""B' | 'A""""B' | No |
| 'A"B' | 'A""B' | No |
| ';' | ';' | No |
| '$R$N' | '$R$N' | No |
| 'AB$00CD' | 'AB' (string was truncated) | No |
| TRUE | A source string that is not enclosed in quotation marks should not contain any non-printable control character, quotation mark, semicolon or comma (US CSV format). Binary data are not permitted. | 'Module\_XA5' | '"Module\_XA5"' | Yes |
| '123456' | '"123456"' | Yes |  |
| '' | '""' | Yes |  |
| 'A""B' | '"A""""B"' | Yes |  |
| 'A"B' | '"A""B"' | Yes |  |
| ';' | '";"' | Yes |  |
| '$R$N' | '"$R$N"' | Yes |  |
| 'AB$00CD' | '"AB"' (String was truncated) | No |  |

**Example:**

```
PROGRAM MAIN  
VAR  
    s1 : STRING;  
    s2 : STRING;  
END_VAR
```

```
s1 := STRING_TO_CSVFIELD( 'Module_"ALFA_$05"_6', TRUE );  
s2 := STRING_TO_CSVFIELD( 'Module_50', FALSE );
```

The result:

s1 = '"Module\_""ALFA\_$05""\_6"'

s2 = 'Module\_50'

Further information can be found here: [Example: Writing/reading of a CSV file](ms-xhelp:///?Id=beckhoff-5087-4506-bf25-3cb1667c44bf).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
