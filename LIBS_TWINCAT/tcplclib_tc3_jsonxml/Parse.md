# Parse

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# Parse

This method starts the SAX reader parsing procedure. The JSON object to be parsed and a reference to a function block, which was derived from the interface ITcJsonSaxHandler, are transferred as input parameters. This function block is then used for the callback methods of the SAX reader.

## Syntax

```
METHOD Parse : BOOL  
VAR_IN_OUT CONSTANT  
  sJson : STRING;  
END_VAR  
VAR_INPUT  
  ipHdl : ITcJsonSaxHandler;  
END_VAR  
VAR_OUTPUT  
  hrErrorCode : HRESULT;  
END_VAR
```
