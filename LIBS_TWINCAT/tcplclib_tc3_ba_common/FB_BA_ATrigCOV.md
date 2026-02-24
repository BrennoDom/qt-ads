# FB_BA_ATrigCOV

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# FB\_BA\_ATrigCOV

![21367612](/tcplclib_tc3_ba_common/1033/Images/gif/9007204873486091__Web.gif)

The function block monitors the value *xValue* for changes (Change of Value).

|  |  |
| --- | --- |
| 58090788 | The monitored value is independent of the data type (ANY). For reasons of performance, however, only data types smaller than or equal to 4 bytes are supported! |

## VAR\_INPUT

```
xValue      : ANY;  
bForce      : BOOL;
```

**xValue:** Value to be monitored.

**bForce:** Forces a positive comparison ("bQ=TRUE").

## VAR\_OUTPUT

```
bReady     : BOOL;  
bQ         : BOOL;
```

**bReady:** Indicates operability:

If *xValue* is valid.  
Correct value assignment and observance of the permissible data type size.

Memory is initialized.  
The comparison can be made at the earliest after one cycle, as the internal memory first has to be initialized with the value *xValue*.

**bQ:** Result of the last comparison (*TRUE* if the value has changed).

## Requirements

| Development environment | Required library | Necessary function |
| --- | --- | --- |
| TwinCAT3.1 4022.16 | Tc3Building Automation Common from V1.0.4.3 | TF8040 | TwinCAT Building Automation from V1.0.5.0 |
