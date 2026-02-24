# Part 202 (emergency lighting)

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [High-Level commands](ms-xhelp:///?Id=beckhoff-19b2-4bc9-a63f-87f11156498e)
5. Part 202 (emergency lighting)

# Part 202 (emergency lighting)

## Function blocks

| Name | Description |
| --- | --- |
| [FB\_DALIV2EmergencyLightingDT](ms-xhelp:///?Id=beckhoff-a611-4d4d-90ef-22ec6809a6cb) | This function block is for the duration test of a DALI emergency lighting device. At the end of the test the test results are written over a FIFO buffer (IN-OUT variable *fbStringRingBuffer*), which in turn is read by the *FB\_DALIV2FileLogging()* function block into a file. |
| [FB\_DALIV2EmergencyLightingFT](ms-xhelp:///?Id=beckhoff-febc-43ea-b3c4-53171564dc99) | This function block is for the function test of a DALI emergency lighting device. At the end of the test the test results are written over a FIFO buffer (IN-OUT variable *fbStringRingBuffer*), which in turn is read by the *FB\_DALIV2FileLogging()* function block into a file. |
| [FB\_DALIV2FileLogging](ms-xhelp:///?Id=beckhoff-2c11-4d44-b03f-e99682517c40) | This function block reads the respective FIFO buffers (IN-OUT variable *fbStringRingBuffer*) written in the *FB\_DALIV2EmergencyLightingFT()* and *FB\_DALIV2EmergencyLightingDT()* function blocks and writes the contents into a log file. |
| [FB\_DALIV2GetSettingsType01](ms-xhelp:///?Id=beckhoff-8166-4d88-b88f-b1af3ba7f622) | This function block reads the variables (BATTERY CHARGE, DURATION TEST RESULT, LAMP EMERGENCY TIME…) from all emergency lighting control gears in a DALI line and stores them in a structure. |
| [FB\_DALIV2SetSettingsType01](ms-xhelp:///?Id=beckhoff-0046-4141-b058-3587fd261c6f) | This function block initializes the variables (EMERGENCY LEVEL, FUNCTION TEST DELAY TIME, DURATION TEST DELAY TIME…) of all emergency lighting control gears in a DALI line with the values that are stored in a structure. |

Further Information

* [FB\_DALIV2EmergencyLightingDT](ms-xhelp:///?Id=beckhoff-a611-4d4d-90ef-22ec6809a6cb)
* [FB\_DALIV2EmergencyLightingFT](ms-xhelp:///?Id=beckhoff-febc-43ea-b3c4-53171564dc99)
* [FB\_DALIV2FileLogging](ms-xhelp:///?Id=beckhoff-2c11-4d44-b03f-e99682517c40)
* [FB\_DALIV2GetSettingsType01](ms-xhelp:///?Id=beckhoff-8166-4d88-b88f-b1af3ba7f622)
* [FB\_DALIV2SetSettingsType01](ms-xhelp:///?Id=beckhoff-0046-4141-b058-3587fd261c6f)

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
