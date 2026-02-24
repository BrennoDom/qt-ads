# FB_AdsReadEvents

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_AdsReadEvents

![64826129](/tcplclib_tc2_utilities/1033/Images/png/9007200780338315__Web.png)

The function block queries the active messages of the EventLogger via ADS and makes them available in the form of an array aEvents. To display the messages in the visualization element Event table, the array aEvents has to be entered in its property Message data array.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId             : T_AMSNetId;  
    bReadEvents        : BOOL;  
    nLanguageId        : DWORD;  
    eDateAndTimeFormat : E_DateAndTimeFormat;  
    tRefreshTime       : TIME  
    tTimeout           : TIME  
END_VAR
```

**sNetId:** AmsNetID of the device, from which the messages of the EventLogger are to be queried. If the messages are to be read locally, an empty string can be specified.

**bReadEvents:** The input can be used to enable reading of the messages. When the enable is reset, the error outputs (bError and nErrId) are also reset.

**nLanguageId:** (Language Id) Defines the language in which message texts are displayed.

**eDateAndTimeFormat:** Defines the timestamp format. The available options are:

* de\_De – German spelling: dd.MM.yyyy hh:mm:ss (24 h)
* en\_GB – British spelling: dd/MM/yyyy hh:mm:ss (12 h)
* en\_US – American spelling: MM/dd/yyyy hh:mm:ss (12 h)

**tRefreshTime:** Defines the time interval, after which the message query is repeated.

**tTimeout:** Defines the time interval, after which a timeout error is triggered.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    aEvents         : ARRAY[1..80] OF ST_ReadEvent;  
    nNumberOfEvents : UDINT;  
    bBusy           : BOOL;  
    bDone           : BOOL;  
    bError          : BOOL  
    nErrorId        : UDINT;  
END_VAR
```

**aEvents:** This array is used by the function block to make the read messages available. The array can store a maximum of 80 messages.

**nNumberOfEvents:** Indicates the number of messages currently stored in the array aEvents.

**bBusy:** Indicates whether the function block is carrying out an operation.

**bDone:** TRUE, if the function block is not busy at present, but has carried out at least one operation.

**bError:** Indicates whether an error has occurred.

**nErrorId:** Specifies the error number.
