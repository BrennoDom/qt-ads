# SaveDocumentToFile

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# SaveDocumentToFile

This method saves the current XML document in a file. The absolute path to the file is transferred to the method as input parameter.

A rising edge at the input parameter bExec triggers the saving procedure. The asynchronous process is terminated as soon as the reference bExec is set back to FALSE from the method. When the process ends, the return value of the method indicates for one call whether saving of the file was successful (TRUE) or failed (FALSE).

## Syntax

```
METHOD SaveDocumentToFile : BOOL  
VAR_IN_OUT CONSTANT  
  sFile : STRING;  
END_VAR  
VAR_INPUT  
  bExec : REFERENCE TO BOOL;  
END_VAR  
VAR_OUTPUT  
  hrErrorCode: HRESULT;  
END_VAR
```

Sample call:

```
IF bSave THEN  
  bSaved = fbXml.SaveDocumentToFile('C:\Test.xml', bSave);  
END_IF
```
