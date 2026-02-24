# Show1

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# Show1

![54578237](/tcplclib_tc3_ba_common/1033/Images/gif/5627216267__Web.gif)

Output of a message with a value to be formatted.

## VAR\_INPUT

```
dLogType      : DWORD;  
sLogCode      : T_MaxString;  
sLogText      : T_MaxString;  
tArg1         : T_Arg;  
bIgnoreBlock  : BOOL;
```

**dLogType:** Log type of the message to be displayed.

**sLogCode:** Optional, [context-related additional information](ms-xhelp:///?Id=beckhoff-2b2b-4f57-981c-df8988f69b1f).

**sLogText:** Content of the message.

**tArg1:** Value to be formatted (see T\_Arg).

**bIgnoreBlock:** Prevents the suppression of [cyclically repeated messages](ms-xhelp:///?Id=beckhoff-2b2b-4f57-981c-df8988f69b1f).

## VAR\_OUTPUT

```
Show1     : BOOL;
```

**Show1:** Indicator of whether a message was output (*TRUE*) or discarded (*FALSE*).
