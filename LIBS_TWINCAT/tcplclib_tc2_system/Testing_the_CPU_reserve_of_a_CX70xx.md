# Testing the CPU reserve of a CX70xx

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Samples](ms-xhelp:///?Id=beckhoff-de33-4d86-9a67-3b99efbaded7)
3. Testing the CPU reserve of a CX70xx

# Testing the CPU reserve of a CX70xx

This example is a test project for testing the CPU reserve of a CX70xx. The included function block `FB_Test_CPU_Performance` measures the CPU reserve you have with your application. The function block reads the current CPU power and cycle time. The function block then increases the CPU load until the CX7k no longer operates in real time. Then it reduces the load again until a stable real time is reached. The function block then determines the CPU power and the cycle time and offsets them against the time and load taken at the start of the measurement and gives you the delta. Use the function block for test purposes only and not in a real environment.

If the CPU reserve is greater than 20%, you can make the task cycle time faster than the one currently in use. The advantages of a faster task are faster reaction to inputs and, depending on the program content, a faster application. A few milliseconds can add up to increase the output of a machine. A reserve power of 20 % is ideal.

The sources for the sample project can be unpacked here: [TC\_CX70xx\_Test\_Performance.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_system/Resources/zip/11298888331.zip)

|  |  |
| --- | --- |
| 27245651 | Falsified measurement result  If the function block is used in a low-priority task, the result is falsified and the real data cannot be determined. Due to the long measurement, the slow tasks are also taken into account.    * If possible, always use the function block in the fastest high-priority task. |

|  |  |
| --- | --- |
| 43884268 | Loops or program sections not run through during the measurement falsify the measurement  Loops, multiple tasks and thus strongly fluctuating cycle times cause a strongly fluctuating CPU load.    * Set the TimeOut of the function block to a larger value, because the function block searches for the highest CPU load and then takes longer than with a constant CPU load. |

|  |  |
| --- | --- |
| 59414099 | Aborting the measurement  The function block can only be used if there are no real-time violations in your configuration. If the function block reads out real-time violations already at start-up, the function block aborts the measurement. |

Information on the function block `FB_Test_CPU_Performance`:

## VAR\_INPUT

| Name | Type | Description |
| --- | --- | --- |
| bExecute | BOOL | A positive edge activates the function block. |
| tTimeOut | TIME | Time to stop the measurement if exceeded. |

## VAR\_OUTPUT

| Name | Type | Description |
| --- | --- | --- |
| bBusy | BOOL | The function block is active and working. |
| bError | BOOL | The function block has an error. |
| nErrorID | UDINT | ADS error code |
| nCpuLoadReserve | UDINT | Reserve of CPU in [%] |
| fCycleTimeReserve | LREAL | Cycle time reserve in [ms] |

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024.22 | PC or CX (x86, x64, ARM) | Tc2\_System (system) >= 3.4.25.0 |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
