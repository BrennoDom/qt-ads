# FB_JsonReadWriteDataType

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# FB\_JsonReadWriteDataType

In order to use UTF-8 characters, e.g. in the automatic generation of metadata via the function block [FB\_JsonReadWriteDataType](ms-xhelp:///?Id=beckhoff-f490-4761-8e30-016d582c5cd8), the check box for the support of UTF-8 in the symbolism must be activated in the TwinCAT project. To do this, double-click on **SYSTEM** in the project tree, open the **Settings** tab and activate the corresponding check box.

![56511253](/tcplclib_tc3_jsonxml/1033/Images/png/4382966027__en-US__Web.png)

|  |  |
| --- | --- |
| 38839231 | Strings in UTF-8 format  The variables of type STRING used here are based on the UTF-8 format. This STRING formatting is common for MQTT communication as well as for JSON documents.  In order to be able to receive special characters and texts from a wide range of languages, the character set in the Tc3\_IotBase and Tc3\_JsonXml libraries is not limited to the typical character set of the data type STRING. Instead, the Unicode character set in UTF-8 format is used in conjunction with the data type STRING.  If the ASCII character set is used, there is no difference between the typical formatting of a STRING and the UTF-8 formatting of a STRING.  Further information on the UTF-8 STRING format and available display and conversion options can be found in the [documentation for the Tc2\_Utilities PLC library](https://infosys.beckhoff.de/content/1033/tcplclib_tc2_utilities/63050398266130955.html?id=4885121777342449589). |

## Requirements

| TwinCAT version | Hardware | Libraries to be integrated |
| --- | --- | --- |
| TwinCAT 3.1, Build 4022 | x86, x64, ARM | Tc3\_JsonXml |

Further Information

* [AddJsonKeyPropertiesFromSymbol](ms-xhelp:///?Id=beckhoff-e5bd-4cd5-944d-d438f51cb1c2)
* [AddJsonKeyValueFromSymbol](ms-xhelp:///?Id=beckhoff-91cf-4d61-b6d9-d5ae3709e447)
* [AddJsonValueFromSymbol](ms-xhelp:///?Id=beckhoff-597f-4ea9-9ad5-f3a511f46039)
* [CopyJsonStringFromSymbol](ms-xhelp:///?Id=beckhoff-3456-4a55-91b6-0b1233176ae1)
* [CopyJsonStringFromSymbolProperties](ms-xhelp:///?Id=beckhoff-8662-42a9-8a44-899f75c3890e)
* [CopySymbolNameByAddress](ms-xhelp:///?Id=beckhoff-c25c-4b4b-9465-61d0bc9d84aa)
* [GetDataTypeNameByAddress](ms-xhelp:///?Id=beckhoff-1b55-444f-8df2-7ba054e3bdbc)
* [GetJsonFromSymbol](ms-xhelp:///?Id=beckhoff-dcc8-4add-9905-fe0687b0af11)
* [GetJsonStringFromSymbol](ms-xhelp:///?Id=beckhoff-45ce-4ada-a597-52b121003285)
* [GetJsonStringFromSymbolProperties](ms-xhelp:///?Id=beckhoff-ceff-4869-8b88-95b131683393)
* [GetSizeJsonStringFromSymbol](ms-xhelp:///?Id=beckhoff-6ad4-4a73-b5f2-a37ab71c10d0)
* [GetSizeJsonStringFromSymbolProperties](ms-xhelp:///?Id=beckhoff-a9e4-4037-94cd-d8dc79ec9a26)
* [GetSymbolNameByAddress](ms-xhelp:///?Id=beckhoff-6ed7-4d0f-8cae-80e618b2b806)
* [SetSymbolFromJson](ms-xhelp:///?Id=beckhoff-93b2-41e2-96ac-2bf784abdb7f)
