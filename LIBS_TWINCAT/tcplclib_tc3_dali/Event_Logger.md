# Event Logger

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Appendix](ms-xhelp:///?Id=beckhoff-799a-4543-a757-72ecd85fb150)
3. [Commissioning and diagnosis](ms-xhelp:///?Id=beckhoff-0748-4e01-bcff-c71c095ae5b7)
4. Event Logger

# Event Logger

The PLC library Tc3\_DALI supports the TwinCAT Event Logger for the output of messages. As a result, the developer is also shown errors without explicitly querying the error IDs of the individual instances in the PLC program.

The output of the messages can be influenced by a variable. It is located in the library Tc3\_DALI as a global variable:

```
  eEventTraceLevel    : TcEventSeverity := TcEventSeverity.Critical;
```

Each message is assigned to a level that indicates how serious it is. The levels Info, Warning, Error or Critical are available.The global variable eEventTraceLevel defines the level from which a message is displayed in the message window.

By default, the variable is initialized so that only messages that correspond to the Critical level are output. Since most messages of the Tc3\_DALI library are assigned to the Error level, these messages are not displayed. The Level Critical is rated more serious than the Level Error.

## PLC

The following instruction, which you can insert into your PLC program, outputs all messages of all function blocks from the Tc3\_DALI library. This is particularly helpful during development or commissioning.

```
  Tc3_DALI.GVL.eEventTraceLevel := TcEventSeverity.Verbose;
```

Each function block also contains a local variable that overrides the global variable setting for the corresponding instance. In the online view, the output of the messages can be defined individually for each instance:

![8859419](/tcplclib_tc3_dali/1033/Images/png/5977121419__Web.png)

## Watch List

In addition to the extension of the PLC program, you can create a watch list in which the global variable *eEventTraceLevel* can be changed.

:   1. Create the watch list.  
    ![12625908](/tcplclib_tc3_dali/1033/Images/gif/6794646795__Web.gif)

:   2. Select the global variable *eEventTraceLevel*.  
    ![46524311](/tcplclib_tc3_dali/1033/Images/gif/6794649739__Web.gif)  
    The default setting of the variable can be seen in the **documentation** area of the input assistant.  
    ![16065622](/tcplclib_tc3_dali/1033/Images/gif/6794652683__Web.gif)

* After adding the variable to the watch list you can change its value via a drop-down menu.  
  ![10372872](/tcplclib_tc3_dali/1033/Images/gif/6794655627__Web.gif)

## Displaying the messages

The messages are displayed in the TwinCAT **Logged Events** window (see chapter [Event Logger](https://infosys.beckhoff.com/content/1033/tc3_eventlogger/27021602616987915.html)).

![26246992](/tcplclib_tc3_dali/1033/Images/png/5977124363__en-US__Web.png)

All messages are stored in a ring buffer in the TwinCAT controller. The size of the ring buffer can be adapted in the TwinCAT options. This has the advantage that messages are saved even if the TwinCAT project is not open in Visual Studio.

![34896342](/tcplclib_tc3_dali/1033/Images/png/5977127307__Web.png)

In addition, the messages can also be displayed in the **Output** window.

![45631627](/tcplclib_tc3_dali/1033/Images/png/9007205231871243__en-US__Web.png)

Make sure that **Show output from** is set to **TwinCAT**.

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
