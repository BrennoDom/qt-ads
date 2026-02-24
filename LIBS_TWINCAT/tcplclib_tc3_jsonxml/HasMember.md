# HasMember

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# HasMember

This method checks whether a certain property is present in the DOM memory. If the property is present the method returns TRUE, otherwise it returns FALSE.

## Syntax

```
METHOD HasMember : BOOL  
VAR_INPUT  
  v : SJsonValue;  
END_VAR  
VAR_IN_OUT CONSTANT  
  member : STRING;  
END_VAR
```

Sample call:

```
bHasMember := fbJson.HasMember(jsonDoc, 'PropertyName');
```
