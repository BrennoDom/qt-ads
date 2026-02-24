# FB_BA_LogMessage

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# FB\_BA\_LogMessage

![17161430](/tcplclib_tc3_ba_common/1033/Images/gif/9007204872444811__Web.gif)

The function block outputs messages in the TwinCAT display window.

The symbol path of the function block is inserted for each message to be output so that the user can recognize the calling function block instance by the message.

|  |  |
| --- | --- |
| 20235143 | Instances of this function block **cannot** be called explicitly.  Separate functions are available for various application cases, which are described in the following section of this documentation. |

|  |  |
| --- | --- |
| 47898561 | The functionality to output messages is provided by the ADSLOGDINT function, which is used internally. |

## VAR\_OUTPUT

```
sResult     : T_MaxSTRING;
```

**sResult:** Content of the message last output.

## Application

**Context-related additional information**

The developer has the possibility to output an abbreviation in each message.

Using this abbreviation, messages can be localized more easily in the source code (e.g. when searching for the abbreviation using the search function).

**Suppression of cyclically repeated messages**

In order to suppress the cyclic output of the same message, the current log code is compared with the log code used last. If the two values correspond, the output of the message is suppressed, which conversely means that different successive messages would be displayed.

This behavior can be influenced with the *bIgnoreBlock* option from the Show function:

*TRUE* prevents the suppression of a cyclically repeated message.

**Example 1:**

The example function *DoWork()* outputs a warning in row 150:

```
FUNCTION_BLOCK FB_TEST  
VAR  
  fbLogMsg   : FB_LogMessage;  
END_VAR
```

```
FUNCTION DoWork
```

```
fbLogMsg.Show(ADSLOG_MSGTYPE_WARN, 'DW150', 'Function not ready.', FALSE;
```

**Example 2:**

The example function *Init()* outputs an error message in row 80 that could be [FB\_BA\_LogMessage](ms-xhelp:///?Id=beckhoff-2b2b-4f57-981c-df8988f69b1f):

```
FUNCTION_BLOCK FB_TEST  
VAR  
  fbLogMsg   : FB_LogMessage;  
  iState     : INT := 0;  
  sDevice    : STRING := ‘CX9020’;  
END_VAR
```

```
FUNCTION Init
```

```
fbLogMsg.Show1(ADSLOG_MSGTYPE_ERROR, 'I80', ‘device %s has an  Invalid state “%d”.', F_STRINGEx(sDevice), F_INT(iState), TRUE;
```

## Requirements

| Development environment | Required library | Necessary function |
| --- | --- | --- |
| TwinCAT3.1 4022.16 | Tc3Building Automation Common from V1.0.4.3 | TF8040 | TwinCAT Building Automation from V1.0.5.0 |

Further Information

* [Show](ms-xhelp:///?Id=beckhoff-9d4e-4997-a1a6-97ff321e7e1b)
* [Show1](ms-xhelp:///?Id=beckhoff-f075-40be-922a-b7b8594d000d)
* [Show2](ms-xhelp:///?Id=beckhoff-1547-48c6-8d53-6a09970449df)
* [Show3](ms-xhelp:///?Id=beckhoff-2d3e-4179-801e-0ad96a7021d8)
* [Show4](ms-xhelp:///?Id=beckhoff-d237-460b-8dfa-6d3c3478d782)
* [Show5](ms-xhelp:///?Id=beckhoff-1a43-47b6-a3d5-35161874f9fa)
