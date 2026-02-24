# Tc2_DALI and Tc3_DALI in the same project

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Appendix](ms-xhelp:///?Id=beckhoff-799a-4543-a757-72ecd85fb150)
3. Tc2\_DALI and Tc3\_DALI in the same project

# Tc2\_DALI and Tc3\_DALI in the same project

The Tc2\_DALI library can be used for porting existing TwinCAT 2 projects to TwinCAT 3. At source code level, the TwinCAT 2 DALI library is compatible with the TwinCAT 3 Tc2\_DALI library, which significantly simplifies the transfer of TwinCAT 2 projects to TwinCAT 3.

In contrast, the TwinCAT 3 library Tc3\_DALI is a completely new development, which has been optimized for TwinCAT 3 and adapted to DALI-2. In this way it was possible to improve the performance and to simplify handling of the function blocks further.

|  |  |
| --- | --- |
| 58730959 | For new projects the Tc3\_DALI library should therefore be used if possible. |

This can lead to a situation where the Tc2\_DALI library is used in a TwinCAT 3 project, this project is subsequently extended and the Tc3\_DALI library is to be used for this purpose.

The following section illustrates how a KL6821 with the Tc2\_DALI library and a further KL6821 with the Tc3\_DALI library are operated in a TwinCAT 3 project.

The function blocks of the Tc2\_DALI and Tc3\_DALI libraries cannot be mixed on the same Bus Terminal. Each library must have exclusive access to a KL6821 or KL6811.

Add both libraries to the TwinCAT 3 project:

![58816586](/tcplclib_tc3_dali/1033/Images/png/9843852683__Web.png)

The necessary variables must be created for each terminal and linked with the KL6821. In this example, the global variable list has the name *GVL*.

```
VAR_GLOBAL  
    // Tc2_DALI  
    stKL6821InDataTc2 AT %I* : Tc2_DALI.ST_KL6821InData;  
    stKL6821OutDataTc2 AT %Q* : Tc2_DALI.ST_KL6821OutData;  
    stCommandBufferKL6821 : Tc2_DALI.ST_DALIV2CommandBuffer;  
  
    // Tc3_DALI  
    stKL6821InDataTc3 AT %I* : Tc3_DALI.ST_KL6821InData;  
    stKL6821OutDataTc3 AT %Q* : Tc3_DALI.ST_KL6821OutData;  
END_VAR
```

Since the structures for linking the Bus Terminal have the same name in both libraries, the namespace must be prefixed. Although the structures have the same name in both libraries, they have different data types within the TwinCAT 3 type system. The namespace ensures that the appropriate data type from the respective library is used. For better readability, the namespace was also specified for the structure for the command buffer (*ST\_DALIV2CommandBuffer*) from the Tc2\_DALI library. Strictly speaking this would not be necessary at this point, because the identifier *ST\_DALIV2CommandBuffer* only occurs in the Tc2\_DALI library.

The namespace of a library is displayed in the **Properties** window.

![59587228](/tcplclib_tc3_dali/1033/Images/png/9843855627__Web.png)

By convention, the namespace of the Beckhoff library is the same as the name of the library.

Next, the function block that is called by the communication task is created. In this function block, an instance of FB\_KL6821Communication is called for each terminal, among other things. The namespace must also be specified here, since each library contains a function block with the name FB\_KL6821Communication.

```
            PROGRAM Communication  
VAR  
    // Tc2_DALI  
    fbKL6821CommunicationTc2 : Tc2_DALI.FB_KL6821Communication;  
  
    // Tc3_DALI  
    fbKL6821CommunicationTc3 : Tc3_DALI.FB_KL6821Communication;  
END_VAR  
  
// Tc2_DALI  
fbKL6821CommunicationTc2(stInData := GVL.stKL6821InDataTc2,  
stOutData := GVL.stKL6821OutDataTc2,  
stCommandBuffer := GVL.stCommandBufferKL6821);  
  
// Tc3_DALI               
fbKL6821CommunicationTc3(stInData := GVL.stKL6821InDataTc3,  
stOutData := GVL.stKL6821OutDataTc3);
```

When calling the respective function blocks for sending the DALI commands or for receiving the events, in most cases it is not necessary to specify the namespace. In the Tc2\_DALI library all elements have the prefix *DALIV2* while in the Tc3\_DALI the prefix *DALI* is used.

You can download the sample project from here:[Tc2\_Tc3\_DALI.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc3_dali/Resources/zip/9843858059.zip)

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
