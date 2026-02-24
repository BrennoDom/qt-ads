# Compare

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# Compare

This method checks two iterators for equality.

## Syntax

```
METHOD Compare : BOOL  
VAR_INPUT  
  it1 : SXmlIterator;  
  it2 : SXmlIterator;  
END_VAR
```

Sample call:

```
bResult := fbXml.Compare(xmlIt1, xmlIt2);
```
