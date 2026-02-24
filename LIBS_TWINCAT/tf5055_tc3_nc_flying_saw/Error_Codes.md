# Error Codes

## Library
tf5055_tc3_nc_flying_saw

## Category
Motion Control

1. [TF5055 TC3 NC Flying Saw](ms-xhelp:///?Id=beckhoff-70fc-458e-9475-9aee1787ddfa)
2. [Appendix](ms-xhelp:///?Id=beckhoff-7e2a-4647-ab0c-5d5be376b169)
3. Error Codes

# Error Codes

|  |  |
| --- | --- |
| 9160681 | If you have set GearInPos.SyncMode.GearInSync\_OpMask\_DetailedErrorCodes := TRUE, the flying saw checks return the detailed messages described below. Otherwise the error number 42DF is output in all checking cases. |

## Checks for position limits

| Error (hex) | Error (Dec) | Description |
| --- | --- | --- |
| 4372 | 17266 | The synchronization profile would violate the lower end position of the slave.  15337269  Check when GearInSync\_CheckMask\_MinPos is active. |
| 4373 | 17267 | The synchronization profile would violate the upper end position of the slave.  3817695  Check when GearInSync\_CheckMask\_MaxPos is active. |
| 4374 | 17268 | The synchronization profile would violate the user limit position Options.PositionLimitMin.  34359256  Check when GearInSync\_CheckMask\_OptionalMinPos is active. |
| 4375 | 17269 | The synchronization profile would violate the user limit position Options.PositionLimitMax.  40797849  Check when GearInSync\_CheckMask\_OptionalMaxPos is active. |

## Checks for position overshoots/undershoots

| Error (hex) | Error (Dec) | Description |
| --- | --- | --- |
| 4376 | 17270 | The synchronization point lies under the starting point. As a result, the profile swings under both the start position and the synchronous position.  31636323  Check when GearInSync\_CheckMask\_UndershootPos is active. |
| 4377 | 17271 | The synchronization profile would swing back under the slave start position of the flying saw.  16291455  Check when GearInSync\_CheckMask\_UndershootPos is active. |
| 4378 | 17272 | The synchronization point lies under the starting point. The synchronization profile would swing beyond the slave start position of the flying saw.  12405375  Check when GearInSync\_CheckMask\_OvershootPos is active. |
| 4379 | 17273 | The synchronization profile would swing beyond the slave synchronous position of the flying saw.  44539515  Check when GearInSync\_CheckMask\_OvershootPos is active. |

## Checks for maximum velocity

| Error (hex) | Error (Dec) | Description |
| --- | --- | --- |
| 437A | 17274 | The maximum velocity of the synchronization profile is higher than the maximum velocity of the slave axis.  65311315  Check when GearInSync\_CheckMask\_MaxVelo is active. |
| 437B | 17275 | The maximum velocity of the synchronization profile is higher than the maximum velocity of the slave axis.  50930930  Check when GearInSync\_CheckMask\_MaxVelo is active. |

## Checks for velocity overshoots

| Error (hex) | Error (Dec) | Description |
| --- | --- | --- |
| 437C | 17276 | The maximum velocity of the synchronization profile would be higher than the synchronous velocity.  (Positive direction of travel and starting velocity lower than synchronous velocity)  55725192  Check when GearInSync\_CheckMask\_OvershootVelo is active. |
| 437D | 17277 | The maximum velocity of the synchronization profile would be higher than the starting velocity and synchronous velocity.  (Positive direction of travel and starting velocity higher than synchronous velocity)  31764686  Check when GearInSync\_CheckMask\_OvershootVelo is active. |
| 437E | 17278 | The maximum velocity of the synchronization profile would be higher than the synchronous velocity.  (Negative direction of travel and starting velocity lower than synchronous velocity)  17446726  Check when GearInSync\_CheckMask\_OvershootVelo is active |
| 437F | 17279 | The maximum velocity of the synchronization profile would be higher than the starting velocity and synchronous velocity.  (Negative direction of travel and starting velocity higher than synchronous velocity)  22802807  Check when GearInSync\_CheckMask\_OvershootVelo is active. |

## Checks for velocity undershoots

| Error (hex) | Error (Dec) | Description |
| --- | --- | --- |
| 4380 | 17280 | The minimum velocity of the synchronization profile lies below the synchronous velocity.  (Positive direction of travel and starting velocity higher than synchronous velocity)  3898676  Check when GearInSync\_CheckMask\_UndershootVelo is active. |
| 4381 | 17281 | The minimum velocity of the synchronization profile lies below the starting velocity.  (Positive direction of travel and starting velocity lower than synchronous velocity)  35088084  Check when GearInSync\_CheckMask\_UndershootVelo is active. |
| 4382 | 17282 | The minimum velocity of the synchronization profile lies below the synchronous velocity.  (Negative direction of travel and starting velocity higher than synchronous velocity)  47357306  Check when GearInSync\_CheckMask\_UndershootVelo is active. |
| 4383 | 17283 | The minimum velocity of the synchronization profile lies below the starting velocity.  (Negative direction of travel and starting velocity lower than synchronous velocity)  23562574  Check when GearInSync\_CheckMask\_UndershootVelo is active. |

## Checks for reversal of the direction of travel

| Error (hex) | Error (Dec) | Description |
| --- | --- | --- |
| 4386 | 17286 | The velocity of the flying saw swings below zero; the motion is reversed.  If the slave is already moving in the opposite direction at the beginning, it is not regarded as UndershootVeloZero.  (Master moves in the positive direction)  10736577  29520332  Check when GearInSync\_CheckMask\_UndershootVeloZero is active. |
| 4387 | 17287 | The velocity of the flying saw swings below zero; the motion is reversed.  If the slave is already moving in the opposite direction at the beginning, it is not regarded as UndershootVeloZero.  (Master moves in the negative direction)  64356400  42336695  Check when GearInSync\_CheckMask\_UndershootVeloZero is active. |

## Checks for maximum acceleration

| Error (hex) | Error (Dec) | Description |
| --- | --- | --- |
| 4388 | 17288 | The maximum acceleration of the synchronization profile would be higher than the maximum acceleration of the slave axis.  Check when GearInSync\_CheckMask\_MaxAcc is active. |
| 4389 | 17289 | The maximum deceleration of the synchronization profile would be higher than the maximum deceleration of the slave axis.  Check when GearInSync\_CheckMask\_MaxDec is active. |

## Checks for the maximum jerk

| Error (hex) | Error (Dec) | Description |
| --- | --- | --- |
| 438A | 17290 | The maximum jerk of the synchronization profile would be higher than the maximum jerk of the slave axis.  Check when GearInSync\_CheckMask\_MaxJerk is active (check the SlaveJerkMax). |
| 438B | 17291 | The maximum jerk of the synchronization profile would be higher than the maximum jerk of the slave axis.  Check when GearInSync\_CheckMask\_MaxJerk is active (check the SlaveJerkMin). |

[TF5055 | TwinCAT 3 NC Flying Saw](ms-xhelp:///?Id=beckhoff-70fc-458e-9475-9aee1787ddfa)
