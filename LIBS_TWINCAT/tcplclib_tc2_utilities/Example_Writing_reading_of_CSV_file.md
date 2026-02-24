# Example: Writing/reading of CSV file

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# Example: Writing/reading of CSV file

Here you can unpack the complete sources for the project example: [CSVExample.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_utilities/Resources/zip/9007200058342155.zip)

CSV files generated with the project example:

Data fields without binary data: [TextModeGen.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_utilities/Resources/zip/9007200058345995.zip)  
Data fields contain binary data: [BinaryModeGen.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_utilities/Resources/zip/18014399312912907.zip) (please note that this file requires special software for correct interpretation)

CSV stands for comma-separated values. The following documentation describes how CSV files can be written and read with the aid of auxiliary PLC CSV functions. CSV files, which are basically text files, can store simply structured data sets that can be used for data exchange between two systems. This format enables storage of tables or lists of different lengths. A table row corresponds to a data set (or row) in the CSV file. A table cell corresponds to a data field in the CSV file.

## General information on the supported CSV format

* Files in CSV format should have the extension **.csv**.
* The CRLF character (CR = Carriage Return, LF= Line Feed) is used to separate the individual data sets (rows) (Windows operating systems), i.e. each data set must be followed by a CRLF.
* The CSV file must end with a CRLF character.
* Binary data must be enclosed in single quotation marks. If no single quotation marks are used the data field may only contain numbers and/or letters.
* Data fields containing special characters/control characters are enclosed in double quotation marks. If the data field contains a double quotation mark a second double quotation mark is added.
* A special character is used for separating data fields (columns). The standard separator for the individual data fields used by the auxiliary functions is a semicolon. In Germany and Europe a semicolon used as a data field separator, in the USA a comma tends to be used. The separator can be changed from semicolon to comma via the global PLC variable **DEFAULT\_CSV\_FIELD\_SEP**.
* Each data set should have the same number of data fields (columns).

Basic configuration of a CSV file with n columns and n rows (the CRLF characters are usually not visible and are indicated in the diagram with the letters **CRLF**).

```
"Field1Record1";"Field2Record1"; ... ;"Field(n)Record1"CRLF  
"Field1Record2";"Field2Record2"; ... ;"Field(n)Record2"CRLF  
  
...  
  
"Field1Record(n)";"Field2Record(n)";    ... ;"Field(n)Record(n)"CRLF
```

## Available function blocks and functions

* [STRING\_TO\_CSVFIELD](ms-xhelp:///?Id=beckhoff-1943-47a0-a7c9-12bc3a3fad05), [ARG\_TO\_CSVFIELD](ms-xhelp:///?Id=beckhoff-2037-4b5d-879e-e8cb560a011f): converts PLC data in a data field to CSV format;
* [CSVFIELD\_TO\_STRING](ms-xhelp:///?Id=beckhoff-bac9-42bb-a52d-ef0812cb7833), [CSVFIELD\_TO\_ARG](ms-xhelp:///?Id=beckhoff-ecdd-4181-86b0-997b40f67d70): converts data field in CSV format to PLC data;
* [FB\_CSVMemBufferWriter](ms-xhelp:///?Id=beckhoff-aa85-4a67-bf7a-9380e201eead): generates data sets in a byte buffer from several data fields;
* [FB\_CSVMemBufferReader](ms-xhelp:///?Id=beckhoff-1a3d-4151-8c6a-22708123ce55): splits data sets in a byte buffer into individual data fields;

## Write/read CSV file in text mode or binary mode

A CSV file can be read or written in text or binary mode with the aid of the PLC function blocks for file access. Depending on the selected mode there are differences with advantages and disadvantages.

**In 99% of cases the CSV files can be read/written in text mode. Binary mode is only required in rare cases.**

|  | Text mode | Binary mode |
| --- | --- | --- |
| Function block for the file read access | **FB\_FileGets** (special feature: During read access this block automatically removes the CR character at the end before the last data set. The character has to be restored/re-inserted to ensure that the FB\_CSVMemBufferReader block can interpret such a data set) | **FB\_FileRead** |
| Function block for file write access | **FB\_FilePuts** (special feature: During write access this block automatically adds a CR character at the end before the last data set. However, the FB\_CSVMemBufferWriter also generates the CR characters. In order to avoid duplication of the character in the CSV file it must be removed from the buffer before the write access) | **FB\_FileWrite** |
| Programming effort | Smaller | Greater |
| Special characters, non-printable control characters in the data field | Not permitted | Permitted |
| Maximum data set length that can be written/read | Limited to 253 characters (data set + CRLF), i.e. the data set length must not exceed 253 characters. | The maximum data set length is theoretically unlimited. |
| A complete data set can be written with the function block for write access | Yes | Yes |
| A complete data set can be read with the function block for read access | Yes A data set in a pure text file ends with CRLF. In such a file CRLF indicates the end of a line. The FB\_FileGets function block reads the data up to CRLF. | No |
| Binary data in a data field | Not permitted | Permitted |
| Auxiliary functions for conversion of PLC data into CSV format and vice versa | [CSVFIELD\_TO\_STRING](ms-xhelp:///?Id=beckhoff-bac9-42bb-a52d-ef0812cb7833) [STRING\_TO\_CSVFIELD](ms-xhelp:///?Id=beckhoff-1943-47a0-a7c9-12bc3a3fad05) | [CSVFIELD\_TO\_ARG](ms-xhelp:///?Id=beckhoff-ecdd-4181-86b0-997b40f67d70) [ARG\_TO\_CSVFIELD](ms-xhelp:///?Id=beckhoff-2037-4b5d-879e-e8cb560a011f) |
| Supported PLC variable types that can be written/read directly | T\_MaxString (STRING with 255 characters), other data types must first be converted to string and then read/written as a data field in string format. | Any data types can be written/read |
| Sample code | P\_TextModeRead() P\_TextModeWrite() | P\_BinaryModeRead() P\_BinaryModeWrite() |

## Example project

The project example actually contains 4 examples: 2 for write/read access in text mode (preferred) and 2 for write/read access in binary mode (rare):

P\_TextModeRead();

P\_TextModeWrite();

P\_BinaryModeRead();

P\_BinaryModeWrite();

Basic program sequence for reading a CSV file in text mode:

Step 1: Open the CSV file in text mode (FB\_FileOpen). If successful go to step 2.

Step 2: Read a row with the function block FB\_FileGets. Append a CR character (see notes in the table). If successful go to step 3 go, otherwise go to step 4 (the end of the file was reached or an error has occurred).

Step 3: Parse the read row with the function block FB\_CSVMemBufferReader. The individual data fields are read. Then go to step 2 and read the next row. Repeat steps 2 and 3 until the end of the file is reached or an error occurs.

Step 4: Close the CSV file (FB\_FileClose).

Basic program sequence for writing a CSV file in text mode.

Step 1: Open the CSV file in text mode (FB\_FileOpen). If successful go to step 2.

Step 2: Use the function block FB\_CSVMemBufferWriter to generate a new data set. The individual data fields are written into a buffer. This buffer may be a larger string. Remove the CR character at the end of the data set and go to step 3.

Step 3: Write a row with the function block FB\_FilePuts. Repeat steps 2 and 3 until all data sets have been written. Then go to step 4.

Step 4: Close the file (FB\_FileClose).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
