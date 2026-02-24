# FB_JsonDomParser

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# FB\_JsonDomParser

This function block is derived from the same internal function block as [FB\_JsonDynDomParser](ms-xhelp:///?Id=beckhoff-85be-402e-9fed-62d04ba17e78) and thus offers the same interface.

The two derived function blocks differ only in their internal memory management. FB\_JsonDomParser is optimized for the fast and efficient parsing and creation of JSON documents that are only changed a little. The function block [FB\_JsonDynDomParser](ms-xhelp:///?Id=beckhoff-85be-402e-9fed-62d04ba17e78) is recommended for JSON documents to which many changes are made.

|  |  |
| --- | --- |
| 1501966WARNING | |
| Use of router memory  The function block occupies new memory with each change, e.g. with the methods SetObject() or SetJson(). As a result, the amount of router memory used can grow enormously after repeated actions. This allocated memory is only released again by calling the method [NewDocument](ms-xhelp:///?Id=beckhoff-2b09-45c4-b624-958d17168ccc)(). | |

|  |  |
| --- | --- |
| 13517702 | Strings in UTF-8 format  The variables of type STRING used here are based on the UTF-8 format. This STRING formatting is common for MQTT communication as well as for JSON documents.  In order to be able to receive special characters and texts from a wide range of languages, the character set in the Tc3\_IotBase and Tc3\_JsonXml libraries is not limited to the typical character set of the data type STRING. Instead, the Unicode character set in UTF-8 format is used in conjunction with the data type STRING.  If the ASCII character set is used, there is no difference between the typical formatting of a STRING and the UTF-8 formatting of a STRING.  Further information on the UTF-8 STRING format and available display and conversion options can be found in the [documentation for the Tc2\_Utilities PLC library](https://infosys.beckhoff.de/content/1033/tcplclib_tc2_utilities/63050398266130955.html?id=4885121777342449589). |

## Requirements

| TwinCAT version | Hardware | Libraries to be integrated |
| --- | --- | --- |
| TwinCAT 3.1, Build 4022 | x86, x64, ARM | Tc3\_JsonXml |

Further Information

* [AddArrayMember](ms-xhelp:///?Id=beckhoff-fd10-468b-a87a-6690d05ab0de)
* [AddBase64Member](ms-xhelp:///?Id=beckhoff-6ffa-4e23-b709-748475a458a9)
* [AddBoolMember](ms-xhelp:///?Id=beckhoff-6198-4493-9032-6167e2dc480c)
* [AddDateTimeMember](ms-xhelp:///?Id=beckhoff-ddf8-4717-a84a-db39d325410c)
* [AddDcTimeMember](ms-xhelp:///?Id=beckhoff-1188-4ccc-90c4-0a4dd7b5cbfb)
* [AddDoubleMember](ms-xhelp:///?Id=beckhoff-dd9d-4b31-aaf2-01a82afb5eb6)
* [AddFileTimeMember](ms-xhelp:///?Id=beckhoff-69db-425e-951d-bc5fefa74ad4)
* [AddHexBinaryMember](ms-xhelp:///?Id=beckhoff-7367-43f7-88d7-e45b76646ff3)
* [AddInt64Member](ms-xhelp:///?Id=beckhoff-beae-4c39-9f6d-28d6c797bddd)
* [AddIntMember](ms-xhelp:///?Id=beckhoff-793e-4203-be49-45bfa800a246)
* [AddJsonMember](ms-xhelp:///?Id=beckhoff-dd85-4d16-9e1a-c791937e7a4e)
* [AddNullMember](ms-xhelp:///?Id=beckhoff-c407-4af5-ab81-bdb966d44f9d)
* [AddObjectMember](ms-xhelp:///?Id=beckhoff-2105-4f35-9c4c-5aef10aa2625)
* [AddStringMember](ms-xhelp:///?Id=beckhoff-de4a-4d4b-a594-2ea44517d09e)
* [AddUint64Member](ms-xhelp:///?Id=beckhoff-c1fa-4959-9c82-96d2300d2cba)
* [AddUintMember](ms-xhelp:///?Id=beckhoff-9302-4201-9dd2-5d6bd42ef2b6)
* [ArrayBegin](ms-xhelp:///?Id=beckhoff-c2e3-405e-87c9-29f1084edf5f)
* [ArrayEnd](ms-xhelp:///?Id=beckhoff-a422-40a3-8352-7056c09225a7)
* [ClearArray](ms-xhelp:///?Id=beckhoff-042b-4c06-9a14-7da97cfb70b4)
* [CopyDocument](ms-xhelp:///?Id=beckhoff-00b2-4576-b0b0-79eeef7b627f)
* [CopyJson](ms-xhelp:///?Id=beckhoff-340a-4cdf-9849-4ba31a3c104e)
* [CopyString](ms-xhelp:///?Id=beckhoff-0044-44a5-8039-ac56a5957117)
* [FindMember](ms-xhelp:///?Id=beckhoff-3b15-42d9-81b8-648f6556d428)
* [FindMemberPath](ms-xhelp:///?Id=beckhoff-921c-4e05-809d-4f46935ce512)
* [GetArraySize](ms-xhelp:///?Id=beckhoff-6666-4058-87fa-af9aeaf05105)
* [GetArrayValue](ms-xhelp:///?Id=beckhoff-5a5c-4ebb-8c1d-18f3496cbad4)
* [GetArrayValueByIdx](ms-xhelp:///?Id=beckhoff-38b1-41f2-96b0-69239b0ab6d3)
* [GetBase64](ms-xhelp:///?Id=beckhoff-84b1-4544-bb55-bb08eb2a9ad0)
* [GetBool](ms-xhelp:///?Id=beckhoff-c6e1-4ee3-b93d-d33600391618)
* [GetDateTime](ms-xhelp:///?Id=beckhoff-6140-40d3-915c-e673a9bec01d)
* [GetDcTime](ms-xhelp:///?Id=beckhoff-9ee4-487f-83ef-685d1bb9d5f5)
* [GetDocument](ms-xhelp:///?Id=beckhoff-c60f-484f-86ed-122cd9843004)
* [GetDocumentLength](ms-xhelp:///?Id=beckhoff-6f96-4d71-a8ca-4e0c013e3ca5)
* [GetDocumentRoot](ms-xhelp:///?Id=beckhoff-4573-4d82-adb6-0040cfc90a68)
* [GetDouble](ms-xhelp:///?Id=beckhoff-f929-40b7-b62d-cfc0177ca8d3)
* [GetFileTime](ms-xhelp:///?Id=beckhoff-dc31-4fa0-9853-172c3cc8de5a)
* [GetHexBinary](ms-xhelp:///?Id=beckhoff-81fd-4b43-a0c9-0a5f2ab5468c)
* [GetInt](ms-xhelp:///?Id=beckhoff-93a6-4a29-84c0-82c692cf425d)
* [GetInt64](ms-xhelp:///?Id=beckhoff-d714-427b-8c86-8d87f143c3f6)
* [GetJson](ms-xhelp:///?Id=beckhoff-13cd-40fd-a255-27ecdc56b6fa)
* [GetJsonLength](ms-xhelp:///?Id=beckhoff-d93c-47da-8884-fc04d8cc5719)
* [GetMaxDecimalPlaces](ms-xhelp:///?Id=beckhoff-ddb9-4ff1-8643-d1f9437eb9ff)
* [GetMemberName](ms-xhelp:///?Id=beckhoff-f7b9-46b4-89ec-2ffd77af3dcc)
* [GetMemberValue](ms-xhelp:///?Id=beckhoff-dc9a-4a31-a436-1dd9c8b76cea)
* [GetString](ms-xhelp:///?Id=beckhoff-7181-456e-9e72-1e5f645a1fbf)
* [GetStringLength](ms-xhelp:///?Id=beckhoff-ec98-4e57-8883-d8d6077d2b62)
* [GetType](ms-xhelp:///?Id=beckhoff-c091-461f-869a-cbb688769213)
* [GetUint](ms-xhelp:///?Id=beckhoff-469f-43ca-ad89-ac8279c437cd)
* [GetUint64](ms-xhelp:///?Id=beckhoff-cf85-4029-b130-7b5ac366db18)
* [HasMember](ms-xhelp:///?Id=beckhoff-7ffd-49e7-849c-00cdc63638ee)
* [IsArray](ms-xhelp:///?Id=beckhoff-df92-4b08-bf5d-d3b70278c2db)
* [IsBase64](ms-xhelp:///?Id=beckhoff-f1cf-4757-9fc9-66b9753a95b2)
* [IsBool](ms-xhelp:///?Id=beckhoff-be32-4741-8aec-b07168e3c91a)
* [IsDouble](ms-xhelp:///?Id=beckhoff-7ee6-465b-8592-5edfa8c222eb)
* [IsFalse](ms-xhelp:///?Id=beckhoff-4140-4eec-a36c-ab1ff6b7c2a5)
* [IsHexBinary](ms-xhelp:///?Id=beckhoff-1abd-4fc8-b944-106cc5a38729)
* [IsInt](ms-xhelp:///?Id=beckhoff-15f1-49d2-9802-01f78ba7b77f)
* [IsInt64](ms-xhelp:///?Id=beckhoff-fd79-48a7-be2e-a13d338f7a8c)
* [IsISO8601TimeFormat](ms-xhelp:///?Id=beckhoff-9937-4973-992f-e1436895f4f3)
* [IsNull](ms-xhelp:///?Id=beckhoff-42a6-4536-addb-6dc100811e7d)
* [IsNumber](ms-xhelp:///?Id=beckhoff-c604-446c-b69f-ef7238dd9252)
* [IsObject](ms-xhelp:///?Id=beckhoff-175f-4d7e-af77-ed7ca112f21f)
* [IsString](ms-xhelp:///?Id=beckhoff-2084-4a17-895e-da615256f47b)
* [IsTrue](ms-xhelp:///?Id=beckhoff-ef59-43ba-b736-cd515410cfff)
* [IsUint](ms-xhelp:///?Id=beckhoff-6a9a-4506-9fd6-cc6260372c2e)
* [IsUint64](ms-xhelp:///?Id=beckhoff-b0ec-452f-af12-9fbe22489da1)
* [LoadDocumentFromFile](ms-xhelp:///?Id=beckhoff-65c5-4cad-9a1f-10c2fe551cc9)
* [MemberBegin](ms-xhelp:///?Id=beckhoff-daf6-49bc-93df-76aeba47c789)
* [MemberEnd](ms-xhelp:///?Id=beckhoff-37de-4242-91f9-d599d4da6fa2)
* [NewDocument](ms-xhelp:///?Id=beckhoff-2b09-45c4-b624-958d17168ccc)
* [NextArray](ms-xhelp:///?Id=beckhoff-6f79-4307-b2fc-58066482f63d)
* [ParseDocument](ms-xhelp:///?Id=beckhoff-ae13-433c-9b83-a8e52f29abd2)
* [PushbackBase64Value](ms-xhelp:///?Id=beckhoff-cdd9-45c0-b355-b7533c1588fa)
* [PushbackBoolValue](ms-xhelp:///?Id=beckhoff-2fbc-4f74-b3f3-5d905409a4f9)
* [PushbackDateTimeValue](ms-xhelp:///?Id=beckhoff-be94-4bad-9454-8630c8c68510)
* [PushbackDcTimeValue](ms-xhelp:///?Id=beckhoff-72a2-4a75-8534-a362e5339939)
* [PushbackDoubleValue](ms-xhelp:///?Id=beckhoff-d0d1-414d-97ea-3c89b8506d2e)
* [PushbackFileTimeValue](ms-xhelp:///?Id=beckhoff-826b-4505-a5ae-b50e6baeea3e)
* [PushbackHexBinaryValue](ms-xhelp:///?Id=beckhoff-baf4-45c8-a58e-a3a076d488d1)
* [PushbackInt64Value](ms-xhelp:///?Id=beckhoff-930e-483c-a92f-ca3912458428)
* [PushbackIntValue](ms-xhelp:///?Id=beckhoff-f882-43b0-8a9f-b147bed39ea1)
* [PushbackJsonValue](ms-xhelp:///?Id=beckhoff-5161-435e-b384-40a94fca6477)
* [PushbackNullValue](ms-xhelp:///?Id=beckhoff-d04c-482f-bda7-45960f0ae28e)
* [PushbackStringValue](ms-xhelp:///?Id=beckhoff-042f-4f06-8902-0b12089d8147)
* [PushbackUint64Value](ms-xhelp:///?Id=beckhoff-0f5f-4c81-a9aa-d86f791d7646)
* [PushbackUintValue](ms-xhelp:///?Id=beckhoff-6233-4d7a-bda5-28e5e5477b00)
* [RemoveAllMembers](ms-xhelp:///?Id=beckhoff-3ddb-4b0c-9dac-0ce9373789f6)
* [RemoveArray](ms-xhelp:///?Id=beckhoff-714f-4a16-bb49-37216c82e301)
* [RemoveMember](ms-xhelp:///?Id=beckhoff-59d8-4c9e-814c-d6ce8ce6da35)
* [RemoveMemberByName](ms-xhelp:///?Id=beckhoff-e2bd-4c30-94bb-08a2fba4f935)
* [SaveDocumentToFile](ms-xhelp:///?Id=beckhoff-4678-4fc0-9b17-4c5a547256c2)
* [SetArray](ms-xhelp:///?Id=beckhoff-5efd-4f88-b425-40a2a638550c)
* [SetBase64](ms-xhelp:///?Id=beckhoff-6414-4efb-948e-c2acecf7e349)
* [SetBool](ms-xhelp:///?Id=beckhoff-996e-4cd9-928c-c46dcf7a6261)
* [SetDateTime](ms-xhelp:///?Id=beckhoff-9df5-4c42-b5cf-adcef5e4bd19)
* [SetDcTime](ms-xhelp:///?Id=beckhoff-eda4-4c2f-8ca8-08c5ce5d890c)
* [SetDouble](ms-xhelp:///?Id=beckhoff-d1a6-4dfc-9bd9-09b954810b03)
* [SetFileTime](ms-xhelp:///?Id=beckhoff-3c6f-48b9-84e0-b8624fd684db)
* [SetHexBinary](ms-xhelp:///?Id=beckhoff-009b-4c1b-a739-c2528881c3c9)
* [SetInt](ms-xhelp:///?Id=beckhoff-8fca-40e1-bfc8-f84518f82792)
* [SetInt64](ms-xhelp:///?Id=beckhoff-81cc-4922-b5c2-42a673bdc6c6)
* [SetJson](ms-xhelp:///?Id=beckhoff-c3a3-4ee5-8a3c-56a499fd7f31)
* [SetMaxDecimalPlaces](ms-xhelp:///?Id=beckhoff-4482-48b8-9eaa-75d4a95a41e1)
* [SetNull](ms-xhelp:///?Id=beckhoff-60c1-4b5f-a20e-a8fbb238f866)
* [SetObject](ms-xhelp:///?Id=beckhoff-ede1-4881-8470-26094a7f5e2e)
* [SetString](ms-xhelp:///?Id=beckhoff-92d4-49de-9d55-d2a5aa11ffe3)
* [SetUint](ms-xhelp:///?Id=beckhoff-d322-432b-834b-81e689a408d7)
* [SetUint64](ms-xhelp:///?Id=beckhoff-d85e-4fde-ba93-c31d5a560349)
