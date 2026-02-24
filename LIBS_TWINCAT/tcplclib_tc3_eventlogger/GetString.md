# GetString

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# GetString

![14944322](/tcplclib_tc3_eventlogger/1033/Images/png/5027173387__Web.png)

As soon as bBusy is FALSE and provided no error has occurred (bError = FALSE), the requested text can be fetched with this method.

## Syntax

```
METHOD GetString : BOOL  
VAR_INPUT  
    sResult : REFERENCE TO STRING;  
    nResult : UDINT;  
END_VAR
```

## 281173 Inputs

| Name | Type | Description |
| --- | --- | --- |
| sResult | REFERENCE TO STRING | Buffer variable for the requested text |
| nResult | UDINT | Buffer size in bytes |

## 2530563 Return value

| Name | Type | Description |
| --- | --- | --- |
| GetString | BOOL | Returns TRUE if the text could be assigned.  Returns FALSE if the text could not be completely assigned because the specified buffer variable is too small. |

## Example

The method may only be called if bBusy = FALSE and bError = FALSE signal that text is available.

```
IF NOT fb.bBusy AND NOT fb.bError THEN  
    bGetStringSuccess := fb.GetString(sText, SIZEOF(sText));  
END_IF
```
