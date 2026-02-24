# FB_CX7000_LED_WD

## Library
tcplclib_tc2_systemcx

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
2. [Function Blocks](ms-xhelp:///?Id=beckhoff-ec9d-42ff-9fdd-c53aca476e55)
3. FB\_CX7000\_LED\_WD

# FB\_CX7000\_LED\_WD

The function block allows the use of the WD LED on the CX7000. The function block is immediately active with the call and controls the WD LED via the mode.

You can use the WD LED of the CX7000 to make the states of the PLC program, communication or other indications externally visible. The WD LED has two colors, red and green. If both colors are switched on, the LED lights up yellow. You can turn on the LED and/or make it flash.

|  |  |
| --- | --- |
| 64714441 | User-specific function of the LEDs  Due to the user-specific usability of the LEDs, Beckhoff Support cannot know the meaning of a flashing code and cannot support the customer.    * Document the function of the LEDs for your customers, |

## VAR\_INPUT

| Name | Type | Description |
| --- | --- | --- |
| bEnable | BOOL | The function block controls the LED as soon as and as long as the input is TRUE. |
| eLED | E\_CX7000\_LED | LED mode |
| tFlashingTimeP1 | TIME | Time for the first pulse (>= 200 ms) |
| tFlashingTimeP2 | TIME | Time for the second pulse (>= 200 ms) |

## VAR\_OUTPUT

| Name | Type | Description |
| --- | --- | --- |
| bError | BOOL | The function block has an error. |
| nErrorID | UDINT | ADS Error Code Example:  DEVICE\_SRVNOTSUPP: the image version of the CX7000 does not support this feature. An update (>=35695) is necessary. |

Note

Function block can only be used for CX7000

The function block can and must only be used for the CX7000.

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024.22 | CX (x86, x64, ARM) | Tc2\_SystemCX (System) >= 3.4.7.0 |

[TwinCAT 3 | PLC Library: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
