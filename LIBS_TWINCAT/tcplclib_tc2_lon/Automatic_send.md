# Automatic send

## Library
tcplclib_tc2_lon

## Category
Motion Control

# Automatic send

Automatic sending is enabled with the input variable **bAuto**. The variable must be TRUE during the whole interval over which the block is to send independently.

The following three parameters (VAR\_INPUT) can be used to influence automatic sending.

**MaxSendTime** : TIME;

This value enables transfers of values at regular intervals. The value is sent once the time has elapsed, irrespective of any change in value.

**ValueLimit** : This value can have the following formats: **(r/lr/ui/i)ValueLimit** : REAL / LREAL / UINT / INT.

The value is only sent if the absolute value of the change since the last transfer is greater than this parameter. If this value is 0, sending takes place after each change in value (even very small changes). E

Please note: The variable "ValueLimit" is not used for "Enums" and "Structures". In this case sending takes place after each change in value.

**tMinSendTime** : TIME;

The function block starts sending after **tMinSendTime** at the earliest. This parameter can be used to limit the number of telegrams in situations where the values change very quickly (to reduce the network load). If the value is t#0s, sending takes place after each change in value (see ValueLimit).

![18651996](/tcplclib_tc2_lon/1033/Images/gif/151714571__en-US__Web.gif)
