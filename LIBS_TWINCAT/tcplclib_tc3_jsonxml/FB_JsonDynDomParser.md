# FB_JsonDynDomParser

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# FB\_JsonDynDomParser

This function block is derived from the same internal function block as [FB\_JsonDomParser](ms-xhelp:///?Id=beckhoff-a17a-4054-98b8-8bd8d4525aee) and thus offers the same interface.

The two derived function blocks differ only in their internal memory management. FB\_JsonDynDomParser is optimized for JSON documents to which many changes are made. It releases the allocated memory again after the execution of an action, e.g. for the methods SetObject() or SetJson().

|  |  |
| --- | --- |
| 54550461 | Strings in UTF-8 format  The variables of type STRING used here are based on the UTF-8 format. This STRING formatting is common for MQTT communication as well as for JSON documents.  In order to be able to receive special characters and texts from a wide range of languages, the character set in the Tc3\_IotBase and Tc3\_JsonXml libraries is not limited to the typical character set of the data type STRING. Instead, the Unicode character set in UTF-8 format is used in conjunction with the data type STRING.  If the ASCII character set is used, there is no difference between the typical formatting of a STRING and the UTF-8 formatting of a STRING.  Further information on the UTF-8 STRING format and available display and conversion options can be found in the [documentation for the Tc2\_Utilities PLC library](https://infosys.beckhoff.de/content/1033/tcplclib_tc2_utilities/63050398266130955.html?id=4885121777342449589). |

## Requirements

| TwinCAT version | Hardware | Libraries to be integrated |
| --- | --- | --- |
| TwinCAT 3.1, Build 4024.7 | x86, x64, ARM | Tc3\_JsonXml 3.3.8.0 |
