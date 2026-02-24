# Tutorial

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# Tutorial

This tutorial illustrates the work steps from an empty TwinCAT project to a dispatched message. It depicts the properties of the TwinCAT 3 EventLogger described in the Technical Introduction section in the work sequence.

**Creating an event class in the TwinCAT type system**

:   A standard TwinCAT PLC project exists.

:   1. Double-click on **Type System** in the SYSTEM subtree and select the **Event Classes** tab in the editor which then opens. Open the context menu and select the **New** command.  
    ![25220152](/tcplclib_tc3_eventlogger/1033/Images/png/5249050891__Web.png)
:   The TMC editor opens.
:   2. Give the event class a name and enter a display text.  
    ![25654779](/tcplclib_tc3_eventlogger/1033/Images/png/5249052555__Web.png)
:   3. An event is already created below the event class. Give the event a name and enter a display text and the severity.  
    ![29566423](/tcplclib_tc3_eventlogger/1033/Images/png/5249054219__Web.png)
:   4. Save and, if applicable, close the event class.
:   The source code is provided in the PLC and is accessible under the TC\_EVENTS symbol.

**Adding the TC3\_EventLogger library**

:   5. Select the **Add Library** command in the context menu of the **References** object.
:   The **Add Library** dialog opens.
:   6. Select the library and confirm the dialog.  
    ![64771222](/tcplclib_tc3_eventlogger/1033/Images/png/5249055883__Web.png)

:   The library is added to the PLC project.

**Creating a PLC program**

:   1. Open the MAIN program of the PLC project in the editor by double-clicking.
:   2. Declare and initialize the variables bInit and bSend and declare an instance of the function block FB\_TcMessage:

```
PROGRAM MAIN  
VAR  
    bInit : BOOL := TRUE;   
    bSend : BOOL := TRUE;   
  
    fbMsg : FB_TcMessage;   
END_VAR
```

:   3. Implement the send procedure as shown in the code. The message is initialized once by means of the CreateEx method. Since the initialization requires dynamic resources it should not take place cyclically. The initialized message is subsequently sent using the Send method.

```
IF bInit THEN  
    bInit := FALSE;   
    fbMsg.CreateEx(TC_EVENTS.TutorialClass.TutorialEvent, 0);   
END_IF  
  
IF bSend THEN   
    bSend := FALSE;   
    fbMsg.Send(0);   
END_IF
```

:   4. Create the PLC project and start the PLC.

:   The result is shown in the LoggedEvents window in the TwinCAT 3 Engineering.  
    ![46070087](/tcplclib_tc3_eventlogger/1033/Images/png/5249057547__Web.png)
