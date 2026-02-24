# ExtendName

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# ExtendName

![40612608](/tcplclib_tc3_eventlogger/1033/Images/png/5027138827__Web.png)

This method extends the name.

## Syntax

```
METHOD ExtendName : BOOL  
VAR_INPUT  
    sExtension : STRING(255);  
END_VAR
```

## 29969153 Inputs

| Name | Type | Description |
| --- | --- | --- |
| sExtension | STRING(255) | Text to be appended to the right. |

## 1286929 Return value

| Name | Type | Description |
| --- | --- | --- |
| ExtendName | BOOL | Returns TRUE if the concatenation was successful.  Returns FALSE if the resulting character string is longer than the output character string and doesn't fit in the given output buffer. The memory requirement for the resulting string is then larger than that for the output string. The string is then truncated. |
