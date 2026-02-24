# DCF77_TIME

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# DCF77\_TIME

|  |  |
| --- | --- |
| 20364417 | This function block is superseded by the [DCF77\_TIME\_EX](ms-xhelp:///?Id=beckhoff-bf0d-4830-baf2-cbf3f6769bd3) function block. |

![49062032](/tcplclib_tc2_utilities/1033/Images/png/9007199290171275__Web.png)

The "DCF77\_TIME" function block can be used to decode the DCF-77 radio clock signal. A rising edge at the RUN input starts the decoding process, which continues as long as the RUN input remains set. In the worst case, the function block requires a maximum of 1 minute to synchronize itself, plus a further minute to decode the data for the following minute. It is waiting, during that time, for the missing 59th second marker. Internally the function block is sampling the DCF-77 signal. In order to be able to sample the edges without error the function block should be called once in each PLC cycle. Satisfactory results can be obtained with a cycle time of <= 25 ms. If the DCF-77 signal is absent or faulty, the ERR output is set TRUE, and a corresponding error code is set at the ERRID output. The ERR and ERRID outputs are reset the next time a correct signal is received. Some receivers provide an inverted DCF-77 signal. In such cases the signal must first be inverted before being passed to the DCF\_PULSE input. When operating without errors, the current time is updated at the CDT output every minute. When this is happening, the READY output is set to TRUE for one PLC cycle in the first second (second zero). At this time the DCF-77 time at the CDT output is valid, and can be evaluated by the PLC program. The READY output is only set if no error was detected in the data for the following minute. The transferred parity bits are used for error detection. When reception is poor 100% error-free identification cannot be guaranteed, in the event of two defective (inverse) bits the function block cannot detect an error and will set the READY output to TRUE. In order to obtain reliable time information additional safeguards have to be implemented, e.g. redundancy analysis of the time information in consecutive minutes.

A simple plausibility check of two consecutive telegrams is implemented in the DCF77\_TIME function block. This functionality can be activated via a global Boolean variable for all instances of the DCF77\_TIME block. When the plausibility check is activated the first synchronization is extended by a further minute to a maximum of 3 minutes.

```
GLOBAL_DCF77_SEQUENCE_CHECK : BOOL := FALSE;(* TRUE = Enable plausibility check (two telegrams are checked), FALSE = Disable check *)
```

Errors that occur during reception are registered by the function block. The ERRCNT output is an error counter. This counter indicates the number of errors that have occurred since the last correctly received signal. The counter is reset the next time a signal is correctly received.

## Time code

During each minute, the numbers that encode the year, month, day, day of the week, hour and minute are transmitted in BCD format through pulse modulation of the second marks. The transmitted information always describes the subsequent minute. A second marker is transmitted each second. A second marker with a duration of 0.1 s represents a binary zero, while a duration of 0.2 s represents binary one. The information is extended with 3 check bits. No second marker is transmitted for the 59th second, and a receiver can use this "gap" to synchronize itself.

The length of the short and long pulse signals can be configured via a global variable. If the signal is poor the pulse widths are smaller. The receiver specification usually contains information about the minimum and maximum pulse for the two logic signals, with the higher value expected for higher field strengths and the lower value for low field strengths or in the event of interference. Problems may also occur near the sender (where the field strength is very large) if the pulse width of the logic zero becomes excessive. For this reason a fixed limit is set for differentiating between zero and one, depending on the receiver specification. **Check the specification of the receiver used and configure the impulse length accordingly.**

```
GLOBAL_DCF77_PULSE_SPLIT : TIME := T#140ms;(* 0 == pulse < 140ms, 1 == pulse > 140 *)
```

E.g.: the Atmel T4227 specification (time code receive) contains the following pulse length specification:  
100 ms pulses (zero): Min: 70 ms, typical: 95 ms, max: **130 ms**200 ms pulses (one): min **170 ms**, typical 195 ms, max 235 ms  
For this IC a limit value of 150 ms would be ideal (130 + ( ( 170 ms - 130 ms ) / 2 )).

**Tip:**

If the configured limit value for the impulse length is too small, short impulses are detected as long. Conversely, if the configured limit value is too small, long impulses are detected as short. If the checksum is correct, the receiver cannot detect these errors. In the first case the receiver may supply times that are in future range, in the second case the times may be in the past.

## VAR\_INPUT

```
VAR_INPUT  
    DCF_PULSE : BOOL;  
    RUN       : BOOL;  
END_VAR
```

**DCF\_PULSE**: The DCF-77 signal.

**RUN**: A rising edge at this input initializes the function block and starts decoding the DCF-77 signal. If this input is reset, the decoding process is stopped.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY  : BOOL;  
    ERR   : BOOL;  
    ERRID : UDINT;  
    ERRCNT: UDINT;  
    READY : BOOL;  
    CDT   : DATE_AND_TIME;  
END_VAR
```

**BUSY**: This output is set when the function block is activated.

**ERR**: This output is set when an error occurs in the decoding.

**ERRID**: Supplies the error number when the ERR output is set.

**ERRCNT**: The number of errors that have occurred since the last correctly received signal.

**READY**: If this output is set, the data at the CDT output is valid.

**CDT**: The DCF-77 time in DATE\_AND\_TIME format.

| Error Codes | Error description |
| --- | --- |
| 0 | No error |
| 0x100 | Timeout error. Possibly because no DCF-77 signal is detected. |
| 0x200 | Parity error. Incorrect bits were detected in the received data. |
| 0x300 | Faulty data received. Since the parity check can only detect one incorrect bit, the received data is checked again for validity (this error code will be generated, for instance, if month = 13). |
| 0x400 | The last decoding cycle was too long. This error can occur when reception is poor (not enough second markers were received). |
| 0x500 | The last decoding cycle was too short. This error can occur when reception is poor (additional edges were received). |

**Example:**

If data are received error-free, a TwinCAT software clock (RTC) is synchronized with the radio time in the sample application.

```
PROGRAM P_DCF77_TIME  
VAR  
    bDcfPulse    : BOOL;  
    fbDcf        : DCF77_TIME;  
    bBusy        : BOOL;  
    bError       : BOOL;  
    nErrID       : UDINT;  
    nErrCnt      : UDINT;  
    bDcfValid    : BOOL;  
    tDcfDT       : DT;  
    fbRtc        : RTC;  
    bRtcValid    : BOOL;  
    tRtcDT       : DT;  
END_VAR
```

**Online View:**

![38905106](/tcplclib_tc2_utilities/1033/Images/gif/35433483__Web.gif)

See also description of the [DCF77\_TIME\_EX](ms-xhelp:///?Id=beckhoff-bf0d-4830-baf2-cbf3f6769bd3) function block.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
