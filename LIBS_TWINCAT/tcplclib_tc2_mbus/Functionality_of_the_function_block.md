# Functionality of the function block

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [M-Bus](ms-xhelp:///?Id=beckhoff-da58-4a1f-8f86-2cb29e0d2232)
3. [Bulletin](ms-xhelp:///?Id=beckhoff-867f-4d59-be31-26fe64fe0f45)
4. Functionality of the function block

# Functionality of the function block

Three methods for reading M-Bus meters are offered:

1. The variable **tMinSendTime**> t#0s of the meter block is used to read the meter automatically once the time has elapsed. The variable is internally preset to t#2s.
2. A positive edge of the variable **bStart** of the meter block triggers one reading of the meter.
3. A positive edge of the variables **bStart** of the block [FB\_MBUS\_KL6781()](ms-xhelp:///?Id=beckhoff-2b5d-4be4-b4d2-353673675260) triggers one reading of all meters.

If several meter blocks receive a start command at the same time, they are started in the order in which they are called in the PLC.

The variable **bReady** becomes TRUE for one cycle once the block has received the data.

**bError** becomes TRUE if an error has occurred. This error is described with [eError](ms-xhelp:///?Id=beckhoff-4cab-465a-91d8-d2f9ff9e69d9).

To read the meter after a start/ restart of the PLC, set the variable **bReadInit** to TRUE; otherwise to FALSE. Internally this variable is preset to TRUE.

**eBaudrate:** This variable is internally preset to 2400 baud. To read the meter with this baud rate (2400 baud), this variable does not have to be set explicitly. If the baud rate is changed, the KL6781 is adjusted automatically. This makes it possible to read meters with different baud rates in an M-Bus network. The baud rate of the meters is not changed. They must be able to operate with the baud rate specified here. Some meters operate with automatic baud rate detection. For further information please refer to the user guide of the meter.

**bSND\_NKE:** Internally this variable is preset to TRUE. SND\_NKE is a special telegram to the slave. This telegram triggers an initialization of the receiver. This telegram is important for meters, which send several telegrams. These meters respond to a SND\_NKE with the first telegram. If TRUE, the SND\_NK telegram is sent before the actual query. If FALSE, the SND\_NKE telegram is not sent.

**bDisabled =**TRUE can be used to interrupt processing of the block. If a meter query is in progress, it is completed.

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
