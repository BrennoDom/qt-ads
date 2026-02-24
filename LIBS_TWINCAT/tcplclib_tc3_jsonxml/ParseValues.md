# ParseValues

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# ParseValues

This method starts the SAX reader parsing procedure. The JSON object to be parsed and a reference to a function block, which was derived from the interface ITcJsonSaxValues, are transferred as input parameters. This function block is then used for the callback methods of the SAX reader. What is special about this method is that exclusively values are taken into account in the callback methods, i.e. there are no OnKey() or OnStartObject() callbacks.

## Syntax

```
METHOD ParseValues : BOOL  
VAR_IN_OUT CONSTANT  
  sJson : STRING;  
END_VAR  
VAR_INPUT  
  ipHdl : ITcJsonSaxValues;  
END_VAR  
VAR_OUTPUT  
  hrErrorCode : HRESULT;  
END_VAR
```
