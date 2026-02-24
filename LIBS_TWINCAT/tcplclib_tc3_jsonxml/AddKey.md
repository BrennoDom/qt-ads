# AddKey

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddKey

This method adds a new property key at the current position of the SAX writer. The value of the new property is usually set afterwards. This can be done using one of the following methods, for example: [AddBase64](ms-xhelp:///?Id=beckhoff-a9ce-4399-a30c-aa7978071eea), [AddBool](ms-xhelp:///?Id=beckhoff-4987-4198-a109-c220487314f2), [AddDateTime](ms-xhelp:///?Id=beckhoff-fa38-4fe4-9774-dec1ced44c38), [AddDcTime](ms-xhelp:///?Id=beckhoff-0793-451c-ba69-c2c47709d934), [AddDint](ms-xhelp:///?Id=beckhoff-fe49-492a-ae41-c5b47a6a4eed), [AddFileTime](ms-xhelp:///?Id=beckhoff-1217-4ef1-8e83-ec030c1a1bf4), [AddHexBinary](ms-xhelp:///?Id=beckhoff-d872-4ce2-898c-06c63eea5ba1), [AddLint](ms-xhelp:///?Id=beckhoff-e838-4cf7-afc5-13f5b4f7300a), [AddLreal](ms-xhelp:///?Id=beckhoff-cf49-4346-aac8-5752f4911032), [AddNull](ms-xhelp:///?Id=beckhoff-8c18-44b1-a94e-441e1268e707), [AddRawArray](ms-xhelp:///?Id=beckhoff-2fe9-4bc0-a137-ce4534cefa0b), [AddRawObject](ms-xhelp:///?Id=beckhoff-c5b8-418a-bcb3-e95f21f07362), [AddReal](ms-xhelp:///?Id=beckhoff-0cfa-4540-bf42-f72d6fffcf1a), [AddString](ms-xhelp:///?Id=beckhoff-a2f5-4bdb-9b0f-ccefcf966e2e), [AddUdint](ms-xhelp:///?Id=beckhoff-8897-44ec-9ff0-56711f711950), [AddUlint](ms-xhelp:///?Id=beckhoff-2007-4a7a-ac10-7939b4eea349).

## Syntax

```
METHOD AddKey  
VAR_IN_OUT CONSTANT  
  key : STRING;  
END_VAR
```

Sample call:

```
fbJson.AddKey('PropertyName');
```
