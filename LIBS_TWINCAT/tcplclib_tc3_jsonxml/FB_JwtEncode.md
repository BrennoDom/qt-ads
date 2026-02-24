# FB_JwtEncode

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# FB\_JwtEncode

The function block enables the creation and signing of a JSON Web Token (JWT).

## Syntax

Definition:

```
FUNCTION_BLOCK FB_JwtEncode  
VAR_INPUT  
  bExecute       : BOOL;   
  sHeaderAlg     : STRING(46);  
  sPayload       : STRING(1023);  
  sKeyFilePath   : STRING(511);  
  tTimeout       : TIME;  
  pKey           : PVOID;  
  nKeySize       : UDINT;  
  nJwtSize       : UDINT;  
END_VAR  
VAR_IN_OUT CONSTANT  
  sJwt           : STRING;    
END_VAR  
VAR_OUTPUT  
  bBusy          : BOOL;  
  bError         : BOOL;  
  hrErrorCode    : HRESULT;  
  initStatus     : HRESULT;  
END_VAR
```

## 60968157 Inputs

| Name | Type | Description |
| --- | --- | --- |
| bExecute | BOOL | A rising edge activates processing of the function block. |
| sHeaderAlg | STRING(46) | The algorithm to be used for the JWT header, e.g. RS256. |
| sPayload | STRING(1023) | The JWT payload to be used. |
| sKeyFilePath | STRING(511) | Path to the private key to be used for the signature of the JWT. |
| tTimeout | TIME | ADS timeout, which is used internally for file access to the private key. |
| pKey | PVOID | Buffer for the private key to be read. |
| nKeySize | UDINT | Maximum size of the buffer. |
| sJwt | STRING | Contains the fully coded and signed JWT after the function block has been processed. |
| nJwtSize | UDINT | Size of the generated JWT including zero termination. |

## 11842506 Outputs

| Name | Type | Description |
| --- | --- | --- |
| bBusy | BOOL | Is TRUE as long as processing of the function block is in progress. |
| bError | BOOL | Becomes TRUE as soon as an error situation occurs. |
| hrErrorCode | HRESULT | Returns an error code if the `bError` output is set. An explanation of the possible error codes can be found in the Appendix. |
| initStatus | HRESULT | Returns an error code in case of a failed initialization of the function block. |

## Requirements

| TwinCAT version | Hardware | Libraries to be integrated |
| --- | --- | --- |
| TwinCAT 3.1, Build 4024.4 | x86, x64, ARM | Tc3\_JsonXml 3.3.6.0 |
