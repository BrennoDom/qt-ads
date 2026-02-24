# Show4

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# Show4

![59087616](/tcplclib_tc3_ba_common/1033/Images/gif/5681494283__Web.gif)

Output of a message with four values to be formatted.

## VAR\_INPUT

```
dLogType      : DWORD;  
sLogCode      : T_MaxString;  
sLogText      : T_MaxString;  
tArg1         : T_Arg;  
tArg2         : T_Arg;  
tArg3         : T_Arg;  
tArg4         : T_Arg;  
bIgnoreBlock  : BOOL;
```

**dLogType:** Log type of the message to be displayed.

**sLogCode:** Optional, [context-related additional information](ms-xhelp:///?Id=beckhoff-2b2b-4f57-981c-df8988f69b1f).

**sLogText:** Content of the message.

**tArg1:** First value to be formatted (see T\_Arg).

**tArg2:** Second value to be formatted (see T\_Arg).

**tArg3:** Second value to be formatted (see T\_Arg).

**tArg4:** Second value to be formatted (see T\_Arg).

**bIgnoreBlock:** Prevents the suppression of [cyclically repeated messages](ms-xhelp:///?Id=beckhoff-2b2b-4f57-981c-df8988f69b1f).

## VAR\_OUTPUT

```
Show4     : BOOL;
```

**Show4:** Indicator of whether a message was output (*TRUE*) or discarded (*FALSE*).
