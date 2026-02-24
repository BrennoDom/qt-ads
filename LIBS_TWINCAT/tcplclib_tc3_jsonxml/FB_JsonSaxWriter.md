# FB_JsonSaxWriter

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# FB\_JsonSaxWriter

|  |  |
| --- | --- |
| 21192109 | Strings in UTF-8 format  The variables of type STRING used here are based on the UTF-8 format. This STRING formatting is common for MQTT communication as well as for JSON documents.  In order to be able to receive special characters and texts from a wide range of languages, the character set in the Tc3\_IotBase and Tc3\_JsonXml libraries is not limited to the typical character set of the data type STRING. Instead, the Unicode character set in UTF-8 format is used in conjunction with the data type STRING.  If the ASCII character set is used, there is no difference between the typical formatting of a STRING and the UTF-8 formatting of a STRING.  Further information on the UTF-8 STRING format and available display and conversion options can be found in the [documentation for the Tc2\_Utilities PLC library](https://infosys.beckhoff.de/content/1033/tcplclib_tc2_utilities/63050398266130955.html?id=4885121777342449589). |

## Requirements

| TwinCAT version | Hardware | Libraries to be integrated |
| --- | --- | --- |
| TwinCAT 3.1, Build 4022 | x86, x64, ARM | Tc3\_JsonXml |

Further Information

* [AddBase64](ms-xhelp:///?Id=beckhoff-a9ce-4399-a30c-aa7978071eea)
* [AddBool](ms-xhelp:///?Id=beckhoff-4987-4198-a109-c220487314f2)
* [AddDateTime](ms-xhelp:///?Id=beckhoff-fa38-4fe4-9774-dec1ced44c38)
* [AddDcTime](ms-xhelp:///?Id=beckhoff-0793-451c-ba69-c2c47709d934)
* [AddDint](ms-xhelp:///?Id=beckhoff-fe49-492a-ae41-c5b47a6a4eed)
* [AddFileTime](ms-xhelp:///?Id=beckhoff-1217-4ef1-8e83-ec030c1a1bf4)
* [AddHexBinary](ms-xhelp:///?Id=beckhoff-d872-4ce2-898c-06c63eea5ba1)
* [AddKey](ms-xhelp:///?Id=beckhoff-60aa-4221-b3cc-a3999a39c931)
* [AddKeyBool](ms-xhelp:///?Id=beckhoff-4e4c-4c9c-9af3-d5e5458c1fdd)
* [AddKeyDateTime](ms-xhelp:///?Id=beckhoff-45a8-41fe-a383-df8903215c11)
* [AddKeyDcTime](ms-xhelp:///?Id=beckhoff-c10e-4def-9849-c9a47a79fce1)
* [AddKeyFileTime](ms-xhelp:///?Id=beckhoff-e132-4a97-9944-5bccd48f3d85)
* [AddKeyLreal](ms-xhelp:///?Id=beckhoff-5f43-42b7-9e2e-cfcc82825974)
* [AddKeyNull](ms-xhelp:///?Id=beckhoff-5cc1-4f98-b764-62a20d24d4bb)
* [AddKeyNumber](ms-xhelp:///?Id=beckhoff-ceb8-4958-8d03-d1e7f32f0b20)
* [AddKeyString](ms-xhelp:///?Id=beckhoff-a1aa-4c34-a22a-8daf86e0a108)
* [AddLint](ms-xhelp:///?Id=beckhoff-e838-4cf7-afc5-13f5b4f7300a)
* [AddLreal](ms-xhelp:///?Id=beckhoff-cf49-4346-aac8-5752f4911032)
* [AddNull](ms-xhelp:///?Id=beckhoff-8c18-44b1-a94e-441e1268e707)
* [AddRawArray](ms-xhelp:///?Id=beckhoff-2fe9-4bc0-a137-ce4534cefa0b)
* [AddRawObject](ms-xhelp:///?Id=beckhoff-c5b8-418a-bcb3-e95f21f07362)
* [AddReal](ms-xhelp:///?Id=beckhoff-0cfa-4540-bf42-f72d6fffcf1a)
* [AddString](ms-xhelp:///?Id=beckhoff-a2f5-4bdb-9b0f-ccefcf966e2e)
* [AddUdint](ms-xhelp:///?Id=beckhoff-8897-44ec-9ff0-56711f711950)
* [AddUlint](ms-xhelp:///?Id=beckhoff-2007-4a7a-ac10-7939b4eea349)
* [CopyDocument](ms-xhelp:///?Id=beckhoff-6c51-4674-8126-3404475ef039)
* [EndArray](ms-xhelp:///?Id=beckhoff-1b55-4235-ab6c-425b397b1f61)
* [EndObject](ms-xhelp:///?Id=beckhoff-8346-4949-aff1-5703aca94c93)
* [GetDocument](ms-xhelp:///?Id=beckhoff-a179-4fe4-93fa-3420edc1a451)
* [GetDocumentLength](ms-xhelp:///?Id=beckhoff-a1f9-46de-b00f-e79c136f8871)
* [GetMaxDecimalPlaces](ms-xhelp:///?Id=beckhoff-32fe-43d9-9aba-b9342bc13ff3)
* [ResetDocument](ms-xhelp:///?Id=beckhoff-ba8e-4ab5-bd38-3c042250086c)
* [SetMaxDecimalPlaces](ms-xhelp:///?Id=beckhoff-32a1-4ee0-a992-fa1ff3d1baf1)
* [StartArray](ms-xhelp:///?Id=beckhoff-4c25-47cb-92d7-d54fe05cb802)
* [StartObject](ms-xhelp:///?Id=beckhoff-beb4-406f-8098-656eb8462c19)
