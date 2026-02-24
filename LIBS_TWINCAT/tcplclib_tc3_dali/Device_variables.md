# Device variables

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Commands](ms-xhelp:///?Id=beckhoff-e647-4709-92f0-6dc69db8d17c)
5. [Part 103 (control devices)](ms-xhelp:///?Id=beckhoff-9bac-4896-8ced-1a399a3b5aad)
6. Device variables

# Device variables

Each DALI control device has a certain number of device variables (parameters). These device variables are used to configure the DALI control device and thus influence its behavior. The values of the device variables are stored in the respective DALI control device.

| Name | Reset value | Scope | Size | Comment |
| --- | --- | --- | --- | --- |
| [shortAddress](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) | No change | 0…63, 255 | 1 byte | 255 (MASK): no address |
| [searchAddress](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) | 16#FF\_FF\_FF | 16#00\_00\_00…16#FF\_FF\_FF | 3 bytes |  |
| [randomAddress](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) | 16#FF\_FF\_FF | 16#00\_00\_00…16#FF\_FF\_FF | 3 bytes |  |
| [DTR0](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) | No change | 0…255 | 1 byte |  |
| [DTR1](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) | No change | 0…255 | 1 byte |  |
| [DTR2](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) | No change | 0…255 | 1 byte |  |
| [numberOfInstances](ms-xhelp:///?Id=beckhoff-37b2-43d4-abe8-716d667040d6) | No change | 0…32 | 1 byte | Read only |
| [operatingMode](ms-xhelp:///?Id=beckhoff-37b2-43d4-abe8-716d667040d6) | No change | 0, 128…255 | 1 byte |  |
| [quiescentMode](ms-xhelp:///?Id=beckhoff-37b2-43d4-abe8-716d667040d6) | DISABLED | ENABLED, DISABLED | 1-bit |  |
| [applicationActive](ms-xhelp:///?Id=beckhoff-37b2-43d4-abe8-716d667040d6) | No change | TRUE, FALSE | 1-bit |  |
| [powerCycleSeen](ms-xhelp:///?Id=beckhoff-37b2-43d4-abe8-716d667040d6) | FALSE | TRUE, FALSE | 1-bit |  |
| [applicationControllerError](ms-xhelp:///?Id=beckhoff-37b2-43d4-abe8-716d667040d6) | FALSE | TRUE, FALSE | 1-bit |  |
| [inputDeviceError](ms-xhelp:///?Id=beckhoff-37b2-43d4-abe8-716d667040d6) | FALSE | TRUE, FALSE | 1-bit |  |
| [resetState](ms-xhelp:///?Id=beckhoff-37b2-43d4-abe8-716d667040d6) | TRUE | TRUE, FALSE | 1-bit |  |

?: undetermined

## shortAddress

The short address is stored in this variable. A valid short address lies in the range between 0 and 63. With a value of 255 (MASK), the short address is considered deleted. The short address is set with the function block [FB\_DALI103SetShortAddress](ms-xhelp:///?Id=beckhoff-4845-4f80-86fd-328f393a9156).

## searchAddress

The search address is only required for the assignment of short addresses.

## randomAddress

The random address, also known as the long address, is only required when short addresses are assigned. The function block [FB\_DALI103QueryRandomAddress](ms-xhelp:///?Id=beckhoff-12b2-4d9f-b47f-c3e214b2cfd8) can be used to read out the 3 bytes of the random address.

## DTR0-DTR2

Data Transfer Registers (DTR) 0 to 2 serve as buffer for the execution of various DALI commands.

The DTRs are used by different function blocks. The description of the respective function block indicates which DTRs are used.

Examples for the DTR0 are the query command [FB\_DALI103QueryContentDTR0](ms-xhelp:///?Id=beckhoff-2f7c-48b9-b6b8-0cce989cd3d6) and the command for writing [FB\_DALI103SetDTR0](ms-xhelp:///?Id=beckhoff-be3b-41b6-a103-fd1ad691505c).

## numberOfInstances

The variable indicates how many instances a DALI control device supports. A device has at least one and a maximum of 32 instances.

The number of instances is queried with the function block [FB\_DALI103QueryNumberOfInstances](ms-xhelp:///?Id=beckhoff-0fe2-4959-b893-45198336d2ac). The type of instance is queried with the function block [FB\_DALI103QueryInstanceType](ms-xhelp:///?Id=beckhoff-e51b-432b-8768-4fb4fa811948).

## operatingMode

The variable indicates the current operating mode of the DALI control device. The value 0 characterizes the standard operating mode, i.e. the device behaves according to its specification.

The operating modes 0 to 127 are reserved and must not be used.

The operating modes 128 to 255 are vendor-specific.

The function block [FB\_DALI103QueryOperatigMode](ms-xhelp:///?Id=beckhoff-21c9-44d9-b043-7babe68bc547) can be used to read the operating mode from the DALI control device, the function block [FB\_DALI103SetOperatingMode](ms-xhelp:///?Id=beckhoff-9d88-4d6a-9ff8-4103f770fea5) can be used to change it.

## quiescentMode

The variable indicates whether the DALI control device is in quiescent mode. If the variable is TRUE, no commands and events are passed on.

The mode is time-limited to 15 min +/- 1.5 min.

The function block [FB\_DALI103StartQuiescentMode](ms-xhelp:///?Id=beckhoff-b39b-4ed5-b3dc-c36a9a682dc6) can be used to start the mode, the function block [FB\_DALI103StopQuiescentMode](ms-xhelp:///?Id=beckhoff-dbf7-4637-9440-598a33d6135b) can be used to terminate it prematurely.

## applicationActive

The variable specifies whether the application controller (DALI controller) is active.

According to IEC 62386-103, DALI control devices can contain one or more input devices and optionally a DALI controller. If a DALI controller is contained within a DALI control device, it can independently send DALI commands to other control devices and/or control gears (see [DALI](ms-xhelp:///?Id=beckhoff-7090-4d8c-9e10-2e356c321516)).

If the application controller is disabled, it does not send any DALI telegrams other than the Power Cycle Notification.

The application controller can be enabled with the function block [FB\_DALI103EnableApplicationController](ms-xhelp:///?Id=beckhoff-24f9-47f7-b488-e8ef3480abfe) and disabled with the function block [FB\_DALI103DisableApplicationController](ms-xhelp:///?Id=beckhoff-ec1b-4eb6-b019-6fad0aa23ab5).

## powerCycleSeen

The variable indicates whether the DALI control device was supplied with power.

In this case, the bit is TRUE.

The variable can be read out with the aid of the function block [FB\_DALI103QueryDeviceStatus](ms-xhelp:///?Id=beckhoff-6627-47e1-a3c0-69bbc9ef0397).

## applicationControllerError

This variable specifies whether an application controller (DALI controller) of a DALI control device has detected an error.

In this case, the bit is TRUE.

If the DALI control device does not contain an application controller, this variable is always FALSE.

The variable can be read out with the aid of the function block [FB\_DALI103QueryDeviceStatus](ms-xhelp:///?Id=beckhoff-6627-47e1-a3c0-69bbc9ef0397).

## inputDeviceError

The variable indicates whether a DALI control device has detected an error on an input device.

In this case, the bit is TRUE.

The variable can be read out with the aid of the function block [FB\_DALI103QueryDeviceStatus](ms-xhelp:///?Id=beckhoff-6627-47e1-a3c0-69bbc9ef0397).

The function block [FB\_DALI103QueryInputDeviceError](ms-xhelp:///?Id=beckhoff-26b2-4b9f-be98-341776621760) provides more detailed information about the present error. The output depends on the manufacturer.

## resetState

The variable indicates whether all device and instance variables have been set to their reset value (see table above).

In this case, the bit is TRUE.

The variable can be read out with the aid of the function block [FB\_DALI103QueryDeviceStatus](ms-xhelp:///?Id=beckhoff-6627-47e1-a3c0-69bbc9ef0397).

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
