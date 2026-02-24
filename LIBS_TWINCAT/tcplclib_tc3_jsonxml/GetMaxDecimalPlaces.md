# GetMaxDecimalPlaces

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetMaxDecimalPlaces

This method returns the current setting for MaxDecimalPlaces. This influences the number of decimal places in the case of floating point numbers.

## Syntax

```
METHOD GetMaxDecimalPlaces : DINT
```

Sample call:

```
nDec := fbJson.GetMaxDecimalPlaces();
```
