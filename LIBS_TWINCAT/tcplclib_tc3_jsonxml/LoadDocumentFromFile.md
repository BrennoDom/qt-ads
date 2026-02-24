# LoadDocumentFromFile

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# LoadDocumentFromFile

This method loads an XML document from a file. The absolute path to the file is transferred to the method as input parameter.

A rising edge on the input parameter bExec triggers the loading procedure. The asynchronous process is terminated as soon as the reference bExec is set back to FALSE from the method. When the process ends, the return value of the method indicates for one call whether the loading of the file was successful (TRUE) or failed (FALSE).

## Syntax

```
METHOD LoadDocumentFromFile : BOOL  
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
IF bLoad THEN  
  bLoaded := fbXml.LoadDocumentFromFile('C:\Test.xml', bLoad);  
END_IF
```
