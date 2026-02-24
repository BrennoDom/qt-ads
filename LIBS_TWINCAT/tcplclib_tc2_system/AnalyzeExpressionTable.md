# AnalyzeExpressionTable

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [IEC steps / SFC flags function blocks](ms-xhelp:///?Id=beckhoff-e138-4511-ac2b-c7d587159a12)
4. AnalyzeExpressionTable

# AnalyzeExpressionTable

![46564252](/tcplclib_tc2_system/1033/Images/png/9007201497607307__Web.png)

The function block can be used in PLC projects that use the SFC flags. No instances are generated. The corresponding PLC library must be integrated in the project. Further configuration requirements can be found in the following explanatory notes.

The AnalyzeExpression and AnalyzeExpressionTable function blocks can be used to analyze transitions and step-enabling conditions. If a transition is not triggered after a set time, the transition can be analyzed using these function blocks.

|  |  |
| --- | --- |
| 16425092 | The function blocks can only be used to analyze expressions or transitions that are implemented in the ST programming language. |

* AnalyzeExpression:

+ The function block outputs the result of the analysis, i.e. the reason why no switch has occurred (that is, which partial condition(s) is/are not fulfilled), bundled in a STRING. The variables that form the partial conditions are linked to one another by operators (e.g. `bVar1 AND (bVar2 OR bVar3)`).
+ The SFC flag "SFCErrorAnalyzation" is used for the output.

* AnalyzeExpressionTable:

+ The function block outputs all non-switching variables individually. The individual variables are recorded or output as array elements. The information listed for each array element includes the name, address, comment and current value of the variable.
+ The SFC flag "SFCErrorAnalyzationTable" is used for the output.

## Configuration requirements

The following settings are required to enable AnalyzeExpression or AnalyzeExpressionTable for SFC:

* Include the PLC library Tc2\_System.
* Declare the following variable in the SFC-POU:  
  `SFCEnableLimit: BOOL := TRUE;`
* In the Properties window, configure a maximum active time for the step(s) of the SFC diagram whose subsequent transition/switchover condition is to be analyzed (see also [SFC element properties](https://infosys.beckhoff.de/content/1033/tc3_plc_intro/9007201783222155.html)).
* Configure the SFC settings in the PLC project properties or in the POU properties (see also [SFC flags](ms-xhelp:///?Id=beckhoff-5e90-4c4c-8e66-0f7258b7ad12) and [Command Properties (PLC project) > Category SFC](ms-xhelp:///?Id=beckhoff-5e90-4c4c-8e66-0f7258b7ad12)):

+ **Flags** tab:  
  Check the **Active** and **Declare** check boxes for the following SFC flags:  
  SFCError, SFCEnableLimit, SFCErrorAnalyzation, SFCErrorAnalyzationTable
+ **Build** tab:  
  Enable the option **Calculate active transitions only**.

## Sample

The configurations mentioned above have been implemented in the following sample. For "Step1", the maximum active time was set to 1 s. If the associated outgoing transition "Trans\_ST" has not triggered after 1 s, this transition is analyzed by the function blocks AnalyzeExpression and AnalyzeExpressionTable. The variable SFCError is set to TRUE and the variable SFCErrorStep is given the value 'Step 1'.

The analysis results "SFCErrorAnalyzation" or "SFCErrorAnalyzationTable" indicate which (partial) expression has not yet been triggered, so that "Step1" can be exited.

The transition "Trans\_ST" consists of the expression

```
b1 AND (b2 OR b3);
```

* Situation 1: None of the three variables b1, b2, b3 is TRUE.

+ "SFCErrorAnalyzation" shows the analysis result 'b1 AND (b2 OR b3)'.
+ "SFCErrorAnalyzationTable" lists all three variables b1, b2, b3 with detailed variable information.
+ See also Figure 1.

* Situation 2: Variable b1 is set to TRUE. The analysis results change accordingly.

+ "SFCErrorAnalyzation" shows the analysis result '(b2 OR b3)'.
+ "SFCErrorAnalyzationTable" only lists the two variables b2 and b3 with the corresponding variable information.
+ See also Figure 2.

Figure 1:

![13608105](/tcplclib_tc2_system/1033/Images/png/6227499403__en-US__Web.png)

Figure 2:

![55364084](/tcplclib_tc2_system/1033/Images/png/6227502219__en-US__Web.png)

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
