# Instance variables

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Commands](ms-xhelp:///?Id=beckhoff-e647-4709-92f0-6dc69db8d17c)
5. [Part 103 (control devices)](ms-xhelp:///?Id=beckhoff-9bac-4896-8ced-1a399a3b5aad)
6. Instance variables

# Instance variables

Each DALI control device has at least one and a maximum of 32 instances (see variable *numberOfInstances*). Each instance has a certain number of instance variables (parameters), irrespective of the other instances. These instance variables are used to configure the respective instance in the DALI control device and thus influence its behavior. The values of the instance variables are stored in the respective DALI control device.

| Name | Reset value | Scope | Size | Comment |
| --- | --- | --- | --- | --- |
| [instanceActive](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470) | No change | TRUE, FALSE | 1-bit |  |
| [instanceType](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470) | No change | 0…31 | 1 byte | Read only |
| [resolution](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470) | No change | 1…255 | 1 byte | Read only |
| [inputValue](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470) | No change | 0…(2N-1) | N bytes (max. 32 bytes) |  |
| [eventFilter](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470) | 16#FF\_FF\_FF | 16#00\_00\_00…16#FF\_FF\_FF | 3 bytes |  |
| [eventScheme](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470) | *E\_DALIEventScheme.Instance* | *E\_DALIEventScheme.Instance … E\_DALIEventScheme.InstanceGroup* | 1 byte |  |
| [eventPriority](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470) | No change | *E\_DALIEventPriority.Low … E\_DALIEventPriority.MiddleHigh* | 1 byte |  |
| [instanceError](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470) | FALSE | TRUE, FALSE | 1-bit |  |

?: undetermined

N: resolution

a: Other values can be defined for individual instance types. Details can be taken from the IEC 62386-3xx standard.

## instanceActive

The variable indicates whether sending of events has been enabled for the respective instance.

If the variable is FALSE, the instance does not send any events. This variable has no effect on the DALI commands sent to the instance by other DALI controllers. These will be answered even if *instanceActive* is FALSE.

The function block [FB\_DALI103EnableInstance](ms-xhelp:///?Id=beckhoff-7824-465e-9463-912949d8f525) is used to enable sending of events, the function block [FB\_DALI103DisableInstance](ms-xhelp:///?Id=beckhoff-ce00-42a0-92ca-e2f655a4e298) is used to disable it.

## instanceType

The variable contains the respective instance type of an instance.

| Instance type | IEC 62386- | Application |
| --- | --- | --- |
| 0 | 103 | General application and control devices; not defined further |
| 1-31 | 301-331 | These IEC 62386-3xx parts describe instance types from 301 to 331 |

The instance type (see [E\_DALIInstanceType](ms-xhelp:///?Id=beckhoff-186e-46e4-8111-9f352e67fd22)) of an instance can be read using the function block [FB\_DALI103QueryInstanceType](ms-xhelp:///?Id=beckhoff-e51b-432b-8768-4fb4fa811948).

## resolution

The variable indicates the resolution of [inputValue](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470).

The resolution corresponds to the number of bits through which the input value is mapped.

The function block [FB\_DALI103QueryResolution](ms-xhelp:///?Id=beckhoff-dc1a-4ac7-8842-31c4c4213b35) can be used to read the resolution.

## inputValue

The variable outputs the input value of an instance.

The number of bits in which the input value is mapped can be queried through the variable [resolution](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470).

The input value can be read out with the function block [FB\_DALI103QueryInputValue](ms-xhelp:///?Id=beckhoff-768b-4158-b74d-1fc0e326479a).

## eventFilter

The event filter enables or disables specific events for each instance. The meanings of the individual bits for the respective instance types can be found here:

Part 301 (push buttons) – [Introduction](ms-xhelp:///?Id=beckhoff-9269-4225-99b2-0eb0584f7ebf)

Part 302 (absolute encoder) - [Introduction](ms-xhelp:///?Id=beckhoff-071c-4f95-9a92-c586d5868580)

Part 303 (occupancy sensors) - [Introduction](ms-xhelp:///?Id=beckhoff-5860-45ad-91f4-6edf1ff97245)

Part 304 (light sensors) - [Introduction](ms-xhelp:///?Id=beckhoff-9545-4680-9025-766fb391cf97)

The function block [FB\_DALI103QueryEventFilter](ms-xhelp:///?Id=beckhoff-b116-4640-b754-a51c69135ba2) can be used to read the value of the event filter; the function block [FB\_DALI103SetEventFilter](ms-xhelp:///?Id=beckhoff-249c-427a-a93a-d90128ef79ea) can be used to write to it.

## eventScheme

The variable contains the event scheme for the respective instance of a control device.

| *E\_DALIEventScheme* | Description |
| --- | --- |
| Instance | Instance addressing with instance type and number. |
| Device | Device addressing with short address and instance type. |
| DeviceInstance | Device/instance addressing with short address and instance number. |
| DeviceGroup | Device group addressing with device group and instance type. |
| InstanceGroup | Instance group addressing with instance group and type. |

The function block [FB\_DALI103QueryEventScheme](ms-xhelp:///?Id=beckhoff-e89b-4e93-a719-aef51359535a) can be used to read the event scheme; the function block [FB\_DALI103SetEventScheme](ms-xhelp:///?Id=beckhoff-9d45-48fb-b8ed-6e7f1640c9f9) can be used to write to it.

## eventPriority

Different [Priorities](ms-xhelp:///?Id=beckhoff-148c-47d0-8dfa-40aaee9e21c6) for sending events can be configured for each instance. The device function blocks use the following default values for event priorities:

| *E\_DALIEventPriority* | Application |
| --- | --- |
| MiddleHigh |  |
| Middle | Part 301 (push button), Part 302 (absolute encoder), Part 303 (occupancy sensor) |
| MiddleLow | Part 304 (light sensors) |
| Low |  |

The value of the event priority can be read with the function block [FB\_DALI103QueryEventPriority](ms-xhelp:///?Id=beckhoff-ba98-4135-9e43-dde6081599c9) and written with the function block [FB\_DALI103SetEventPriority](ms-xhelp:///?Id=beckhoff-25e0-4e02-8809-532503d52c6e).

## instanceError

The variable indicates whether an instance of a control device has detected an error.

In this case, the bit is TRUE.

The variable can be read out with the aid of the function block [FB\_DALI103QueryInstanceStatus](ms-xhelp:///?Id=beckhoff-5523-4b13-bd93-224785af7b76).

The function block [FB\_DALI103QueryInstanceError](ms-xhelp:///?Id=beckhoff-0cc6-4cfd-9d8c-561846f1a4db) provides more detailed information about the present error. The output depends on the manufacturer.

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
