# Show2

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# Show2

![21442089](/tcplclib_tc3_ba_common/1033/Images/gif/5627425547__Web.gif)

Output of a message with two values to be formatted.

## VAR\_INPUT

```
dLogType      : DWORD;  
sLogCode      : T_MaxString;  
sLogText      : T_MaxString;  
tArg1         : T_Arg;  
tArg2         : T_Arg;  
bIgnoreBlock  : BOOL;
```

**dLogType:** Log type of the message to be displayed.

**sLogCode:** Optional, [context-related additional information](ms-xhelp:///?Id=beckhoff-2b2b-4f57-981c-df8988f69b1f).

**sLogText:** Content of the message.

**tArg1:** First value to be formatted (see T\_Arg).

**tArg2:** Second value to be formatted (see T\_Arg).

**bIgnoreBlock:** Prevents the suppression of [cyclically repeated messages](ms-xhelp:///?Id=beckhoff-2b2b-4f57-981c-df8988f69b1f).

## VAR\_OUTPUT

```
Show2     : BOOL;
```

**Show2:** Indicator of whether a message was output (*TRUE*) or discarded (*FALSE*).
