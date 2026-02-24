# Example ResultMessage

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# Example ResultMessage

This example illustrates the use of the TwinCAT 3 EventLogger with function blocks. Firstly, it demonstrates how an output on a function block can be utilized in order to use the event information as an extended return. Secondly, it demonstrates how to carry out the parameterization so that the messages are only output via the TwinCAT 3 EventLogger in certain cases.

Download: [Tc3EventLogger\_ResultMessageSample.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc3_eventlogger/Resources/zip/5288319115.zip)

The example consists of two function blocks:

* FB\_MathCalculation: This function block offers two methods and two properties that always output messages at the output ipResultMessage and additionally send them via the EventLogger if a trace level is exceeded.

+ Addition() method: adds two numbers and sends a message in case of overflow
+ Divison() method: divides two numbers after checking. Sends a message in case of division by 0.
+ Property bTraceLevelDefault: indicates whether the trace level is to be observed locally on the function block or whether to use a trace level library, which exists in the GVL in the example.
+ Property eTraceLevel: the methods only send the message via the EventLogger if the severity is greater than or equal to this property.

* FB\_Control: this function block shows the use of the FB\_MathCalculation function block within another function block. The Execute method of the FB\_Control thereby uses the FB\_MathCalculation.Divison() and handles the message further itself as error code.
