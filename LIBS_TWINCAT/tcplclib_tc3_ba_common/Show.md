# Show

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# Show

![28433869](/tcplclib_tc3_ba_common/1033/Images/gif/5624992779__Web.gif)

Output of a simple message.

## VAR\_INPUT

```
dLogType      : DWORD;  
sLogCode      : T_MaxString;  
sLogText      : T_MaxString;  
bIgnoreBlock  : BOOL;
```

**dLogType:** Log type of the message to be displayed.

**sLogCode:** Optional, [context-related additional information](ms-xhelp:///?Id=beckhoff-2b2b-4f57-981c-df8988f69b1f).

**sLogText:** Content of the message.

**bIgnoreBlock:** Prevents the suppression of [cyclically repeated messages](ms-xhelp:///?Id=beckhoff-2b2b-4f57-981c-df8988f69b1f).

## VAR\_OUTPUT

```
Show     : BOOL;
```

**Show:** Indicator of whether a message was output (*TRUE*) or discarded (*FALSE*).
