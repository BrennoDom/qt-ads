# Runtime messages

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. Runtime messages

# Runtime messages

| Value (hex) | Value (dec) | Text ID | Description |
| --- | --- | --- | --- |
| 0x0000 | 0 | NoError | No error. |
| 0x0001 | 1 | NoResponseFromTheDALITerminal | No response from the DALI terminal. |
| 0x0002 | 2 | NoResponseFromTheDALIDevice | No response from the DALI device. |
| 0x0003 | 3 | CommandBufferOverflow | Overflow of the command buffer. |
| 0x0004 | 4 | NoAnswerFromTheCommunicationBlock | No response from the communication block. |
| 0x0005 | 5 | DALICollisionDetectedOnTheBackwardChannel | DALI collision detected on the backward channel: During the transfer of a DALI telegram, a collision with the send data of another DALI slave was detected. |
| 0x0006 | 6 | DALICollisionDetectedOnTheForwardChannel | DALI collision detected on the forward channel: During the transfer of a DALI telegram, a collision with the send data of another DALI master was detected. The error also occurs as soon as the 24 V supply is missing at the power contacts of the KL6811. |
| 0x0007 | 7 | OverloadOfTheInternalDALIPowerSupplyUnitOfTheBusTerminal\_BusUnderVoltage | When using the internal DALI power supply of the Bus Terminal: overload of the internal DALI power supply of the Bus Terminal (bus undervoltage). |
| 0x0008 | 8 | PowerSupplyUnitFaultDetected | When using the internal DALI power supply unit: Power supply unit fault detected. |
| 0x0009 | 9 | TheProcessImageWasDisabledByDI1OrDI2 | The process image of the KL6821 was disabled by the DI1 or DI2 inputs of the terminal. |
| 0x000A | 10 | ShortCircuitDetectedOnTheDALIBus | The 24 V DC supply voltage at connections 1 and 5 of the KL6821 is missing, or a short circuit has been detected on the DALI bus. |
| 0x000B | 11 | CollisionErrorOnTheDALIBus | A collision on the DALI bus was detected while a DALI command was sent. |
| 0x000C | 12 | ItemInReceiveBufferIsInvalid | The entry in the receive buffer of the KL6821 is invalid. |
| 0x000D | 13 | TheInterfaceToTheCommunicationBufferIsNotInitialized | The interface pointer to the communication buffer is not initialized. |
| 0x000E | 14 | TheCommandBuffersHaveBeenBlockedForLongerThanPermitted | The command buffer has been blocked for longer than permitted. |
| 0x000F | 15 | TheTerminalHasReturnedAnErrorDuringInternalAddressing | During internal addressing, the terminal has returned an error. |
| 0x0010 | 16 | DuringInternalAddressingTheTerminalHasDetectedAShortCircuitOnTheBus | During internal addressing, the terminal has detected a short circuit on the bus. |
| 0x0011 | 17 | DuringInternalAddressingTheTerminalHasDetectedThatThereIsNoFurtherShortAddressAvailable | During internal addressing, the terminal has detected that there is no free short address available. |
| 0x0012 | 18 | DuringInternalAddressingTheTerminalHasDetectedThatSeveralDevicesHaveTheSameLongAddress | During internal addressing, the terminal has detected that several devices have the same long address. |
| 0x0013 | 19 | InternalAddressingHasFailed3Times | The internal addressing failed three times. |
| 0x0014 | 20 | TimeoutDuringInternalAddressing | Timeout for internal addressing. The terminal has not sent a response following the start of internal addressing. |
| 0x0015 | 21 | NoResponseFromTheDALIDeviceInstance | No response from the instance of the DALI device. |
| 0x0016 | 22 | TheKL6811DoesNotSupportThisDALICommand | The KL6811 supports only 16-bit commands (IEC 62386-102 and IEC 62386-2xx). |
| 0x0017 | 23 | ErrorDuringTheConfigurationOfTheTerminal | An error occurred during configuration of the terminal. |
| 0x0018 | 24 | NoResponseFromTheDALIDevice2 | No response from the DALI device. |
| 0x0019 | 25 | NoFreeShortAddressAvailable | There is no further free short address available. |
| 0x001A | 26 | ErrorDuringAddressing | An error occurred during addressing. |
| 0x00B9 | 185 | ParameterSensitivityOccupancyPartial3Part303LiesOutsideOfTheValidRange | Parameter *nSensitivityN* lies outside the valid range (1…100). |
| 0x00BA | 186 | ParameterSensitivityOccupancyPartial2Part303LiesOutsideOfTheValidRange | Parameter *nSensitivityN* lies outside the valid range (0…3). |
| 0x00BB | 187 | ParameterExtendedFadeTimeBaseLiesOutsideOfTheValidRange | Parameter *eExtendedFadeTimeBase* lies outside the valid range (0...15). |
| 0x00BC | 188 | ParameterExtendedFadeTimeMultiplierLiesOutsideOfTheValidRange | Parameter *eExtendedFadeTimeMultiplier* lies outside the valid range (0...4). |
| 0x00BD | 189 | ParameterDeadtimeLiesOutsideOfTheValidRange | Parameter *tDeadtime* lies outside of the valid range (T#3S...T#3600S). |
| 0x00CB | 190 | ParameterHysteresisLiesOutsideOfTheValidRange2 | Parameter *nHysteresis* lies outside of the valid range (0...25 %). |
| 0x00CC | 191 | ParameterDeadtimeTimerLiesOutsideOfTheValidRange | Parameter *nDeadtimeTimer* lies outside the valid range (0...12750 ms). |
| 0x00CD | 192 | ParameterHoldTimerLiesOutsideOfTheValidRange | Parameter *nHoldTimer* lies outside of the valid range (1...2538 ms). |
| 0x00C1 | 193 | ParameterStuckTimerLiesOutsideOfTheValidRange | Parameter *nStuckTimer* lies outside the valid range (5...255 s). |
| 0x00C2 | 194 | ParameterShortLiesOutsideOfTheValidRange | Parameter *nShort* lies outside the valid range (tShortMin...255). |
| 0x00C3 | 195 | ParameterShortTimerPart301LiesOutsideOfTheValidRange | Parameter *nShortTimerN* lies outside the valid range (tShortMin...5100 ms). |
| 0x00C4 | 196 | ParameterShortTimerLiesOutsideOfTheValidRange | Parameter *nShortTimer* lies outside the valid range (tShortMin...5100 ms). |
| 0x00C5 | 197 | ParameterDoubleTimerPart301LiesOutsideOfTheValidRange | Parameter *nDoubleTimerN* lies outside of the valid range (0, tDoubleMin...2000 ms). |
| 0x00C6 | 198 | ParameterDoubleTimerLiesOutsideOfTheValidRange | Parameter *nDoubleTimer* lies outside of the valid range (0, tDoubleMin...2000 ms). |
| 0x00C7 | 199 | ParameterRepeatTimerLiesOutsideOfTheValidRange | Parameter *nRepeatTimer* lies outside the valid range (100...2000 ms). |
| 0x00C8 | 200 | ParameterEventSchemeLiesOutsideOfTheValidRange | Parameter *eEventScheme* lies outside of the valid range (0...4). |
| 0x00C9 | 201 | ParameterAddressIsAGroupAddressAndLiesOutsideOfTheValidRange2 | Parameter *nAddress* is a group address and lies outside the valid range (0...31). |
| 0x00CA | 202 | ParameterEventPriorityDeviceLiesOutsideOfTheValidRange | Parameter *eEventPriorityN* lies outside of the valid range (E\_DALIEventPriority.MiddleHigh…E\_DALIEventPriority.Low). |
| 0x00CB | 203 | ParameterALSCorrectionFactorPart304LiesOutsideOfTheValidRange | Parameter *nALSxCorrectionFactorN* lies outside the valid range (1...50). |
| 0x00CC | 204 | ParameterRoomCorrectionFactorPart304LiesOutsideOfTheValidRange | Parameter *nRoomCorrectionFactorN* lies outside the valid range (5...200). |
| 0x00CD | 205 | ParameterSwitchOnLevelLiesOutsideOfTheValidRange | Parameter *nSwitchOnLevel* lies outside the valid range (*nMinLevel...nMaxLevel*). |
| 0x00CE | 206 | ParameterHysteresisPart304LiesOutsideOfTheValidRange | Parameter *nHysteresisN* lies outside of the valid range (0...25 %). |
| 0x00CF | 207 | ParameterDeadtimeTimerPart304LiesOutsideOfTheValidRange | Parameter *nDeadtimeTimerN* lies outside the valid range (0...12750 ms). |
| 0x00D0 | 208 | ParameterSensitivityOccupancyPartialPart303LiesOutsideOfTheValidRange | Parameter *nSensitivityN* lies outside the valid range (1…5). |
| 0x00D1 | 209 | ParameterSensitivityOccupancyPercentPart303LiesOutsideOfTheValidRange | Parameter *nSensitivityN* lies outside the valid range (0...100 %). |
| 0x00D2 | 210 | ParameterDetectionRangeOccupancyPart303LiesOutsideOfTheValidRange | Parameter *nDetectionRangeN* lies outside the valid range (0...100 %). |
| 0x00D3 | 211 | ParameterHoldTimerPart303LiesOutsideOfTheValidRange | Parameter *nHoldTimerN* lies outside of the valid range (1...2538 ms). |
| 0x00D4 | 212 | ParameterDeadtimeTimerPart303LiesOutsideOfTheValidRange | Parameter *nDeadtimeTimerN* lies outside the valid range (0...12750 ms). |
| 0x00D5 | 213 | ParameterHysteresisLiesOutsideOfTheValidRange3 | Parameter *nHysteresis* lies outside of the valid range (1...65535). |
| 0x00D6 | 214 | ParameterDeadtimeTimerPart302LiesOutsideOfTheValidRange | Parameter *nDeadtimeTimerN* lies outside the valid range (0...12750 ms). |
| 0x00D7 | 215 | ParameterStuckTimerPart301LiesOutsideOfTheValidRange | Parameter *nStuckTimerN* lies outside the valid range (5...255 ms). |
| 0x00D8 | 216 | ParameterRepeatTimerPart301LiesOutsideOfTheValidRange | Parameter *nRepeatTimerN* lies outside the valid range (100...2000 ms). |
| 0x00D9 | 217 | ParameterUpSwitchOffThresholdLiesOutsideOfTheValidRange | Parameter *nUpSwitchOffThreshold* lies outside the valid range (1...255). |
| 0x00DA | 218 | ParameterUpSwitchOnThresholdLiesOutsideOfTheValidRange | Parameter *nUpSwitchOnThreshold* lies outside the valid range (1...255). |
| 0x00DB | 219 | ParameterLevelMemoryModeLiesOutsideOfTheValidRange | Parameter *nLevelMemoryMode* lies outside the valid range (1…254). |
| 0x00DC | 220 | ParameterMinLevelIsGreaterThanMaxLevel | Parameter *nMinLevel* is greater than *nMaxLevel.* |
| 0x00DD | 221 | ParameterReferenceDeviceAddressLiesOutsideOfTheValidRange | Parameter *nReferenceDeviceAddress* lies outside the valid range (0...63). |
| 0x00DE | 222 | ErrorDuringReadingOffsetFromMemoryBank | An error occurred while reading an offset from the memory bank. |
| 0x00DF | 223 | ParameterSubRangeStartLiesOutsideOfTheValidRange | Parameter *nSubRangeStart* lies outside the valid range. |
| 0x00E0 | 224 | ErrorReadingMemoryBankDTR0IsWrong | An error occurred while reading out a memory bank. The value of DTR0 is not as expected. |
| 0x00E1 | 225 | ParameterSubRangeEndLiesOutsideOfTheValidRange | Parameter *nSubRangeEnd* lies outside the valid range. |
| 0x00E2 | 226 | ReadCommandReturnedTMASK | The DALI device returns TMASK. The value is not currently available. |
| 0x00E3 | 227 | ReadCommandReturnedMASK | The DALI device returns MASK. The value is not available. |
| 0x00E4 | 228 | ParameterInternalControlGearReferenceTemperatureLiesOutsideOfTheValidRange | Parameter *nInternalControlGearReferenceTemperature* lies outside the valid range (-60…193 °C). |
| 0x00E5 | 229 | ParameterLightSourceOnTimeResettableLiesOutsideOfTheValidRange | Parameter *nLightSourceOnTimeResettable* lies outside the valid range (0…4294967293 s). |
| 0x00E6 | 230 | ParameterLightSourceStartCounterResettableLiesOutsideOfTheValidRange | Parameter *nLightSourceStartCounterResettable* lies outside the valid range (0…16777213). |
| 0x00E7 | 231 | ParameterRatedMedianUsefulLifeOfLuminaireLiesOutsideOfTheValidRange | Parameter *nRatedMedianUsefulLifeOfLuminaire* lies outside the valid range (0…253). |
| 0x00E8 | 232 | ParameterRatedMedianUsefulLightSourceStartsLiesOutsideOfTheValidRange | Parameter *nRatedMedianUsefulLightSourceStarts* lies outside the valid range (0…65533) |
| 0x00E9 | 233 | ParameterInstanceNumberLiesOutsideOfTheValidRange | Parameter *nInstanceNumber* lies outside of the valid range (0…31). |
| 0x00EA | 234 | ParameterShortAddressLiesOutsideOfTheValidRange2 | Parameter *nShortAddress* lies outside the valid range (0…63). |
| 0x00EB | 235 | ParameterSubRangeEndIsLessThanSubRangeStart | Parameter *nSubRangeEnd* is smaller than *nSubRangeStart*. |
| 0x00EE | 238 | ParameterEventPriorityLiesOutsideOfTheValidRange | Parameter *eEventPriority* lies outside of the valid range (E\_DALIEventPriority.MiddleHigh…E\_DALIEventPriority.Low). |
| 0x00EF | 239 | ParameterShortAddressLiesOutsideOfTheValidRange | Parameter *nShortAddress* lies outside the valid range (0…63, 255). |
| 0x00F0 | 240 | ParameterAddressInfoInstanceGroupLiesOutsideOfTheValidRange | Parameter *nAddressInfo1*/*nAddressInfo2* defines an instance group and lies outside of the valid range (0…31). |
| 0x00F1 | 241 | ParameterAddressInfoDeviceGroupLiesOutsideOfTheValidRange | Parameter *nAddressInfo1*/*nAddressInfo2* defines a device group and lies outside of the valid range (0…31). |
| 0x00F2 | 242 | ParameterAddressInfoShortAddressLiesOutsideOfTheValidRange | Parameter *nAddressInfo1*/*nAddressInfo2* defines a short address and lies outside of the valid range (0…63). |
| 0x00F3 | 243 | ParameterAddressInfoInstanceNumberLiesOutsideOfTheValidRange | Parameter *nAddressInfo1*/*nAddressInfo2* defines an instance number and lies outside of the valid range (0…31). |
| 0x00F4 | 244 | ParameterAddressInfoInstanceTypeLiesOutsideOfTheValidRange | Parameter *nAddressInfo1*/*nAddressInfo2* defines an instance type and lies outside of the valid range (0…31). |
| 0x00F5 | 245 | ParameterHysteresisLiesOutsideOfTheValidRange | Parameter *nHysteresis* lies outside of the valid range (0...25). |
| 0x00F6 | 246 | ParameterHoldLiesOutsideOfTheValidRange | Parameter *nHold* lies outside of the valid range (0…254). |
| 0x00F7 | 247 | ParameterDoubleLiesOutsideOfTheValidRange | Parameter *nDouble* lies outside of the valid range (0, *tDoubleMin*…100). |
| 0x00F8 | 248 | ParameterRepeatLiesOutsideOfTheValidRange | Parameter *nRepeat* lies outside the valid range (5…100). |
| 0x00F9 | 249 | ParameterStuckLiesOutsideOfTheValidRange | Parameter *nStuck* lies outside the valid range (5…255). |
| 0x00FA | 250 | ParameterResolutionLiesOutsideOfTheValidRange | Parameter *nResolution* lies outside the valid range (1…64). |
| 0x00FB | 251 | ParameterEventFilterLiesOutsideOfTheValidRange | Parameter *nEventFilter* lies outside of the valid range (16#00\_0000…16#FF\_FFFF). |
| 0x00FC | 252 | ParameterChangeAddressListIsEmpty | Parameter *aChangeAddressList* is empty. |
| 0x00FD | 253 | ParameterChangeAddressListContainsAnInvalidShortAddressEntry | Parameter *aChangeAddressList* contains an invalid short address entry. |
| 0x00FE | 254 | ParameterChangeAddressListContainsADoubleListEntryInTheShortAddresses | Parameter *aChangeAddressList* contains a duplicate list item for the short addresses. |
| 0x00FF | 255 | ParameterChangeAddressListContainsAnEntryForANewShortAddressWhichIsAlreadyAssigned | Parameter *aChangeAddressList* contains an entry for a new short address that is assigned to a device that is not affected by changes. The addresses have been changed back. |
| 0x0100 | 256 | ParameterMaxResponseTableEntriesLiesOutsideOfTheValidRange | Parameter *cMaxResponseTableEntries* lies outside the valid range (2…250). |
| 0x0101 | 257 | ParameterMaxEventTableEntriesLiesOutsideOfTheValidRange | Parameter *cMaxEventTableEntries* lies outside the valid range (2…250). |
| 0x0102 | 258 | ParameterTimeoutLockCommandBuffersLiesOutsideOfTheValidRange | The parameter *cTimeoutLockCommandBuffers* lies outside of the valid range (2…120 s). |
| 0x0103 | 259 | ParameterMaxCommandBufferEntriesLiesOutsideOfTheValidRange | The parameter *cMaxCommandBufferEntries* lies outside of the valid range (2…250). |
| 0x0104 | 260 | ParameterDataFrameTypeLiesOutsideTheValidRange | Parameter *eDataFrameType* lies outside of the valid range. |
| 0x0105 | 261 | ParameterAddressTypeLiesOutsideOfTheValidRange | Parameter *eAddressType* lies outside of the valid range. |
| 0x0106 | 262 | ParameterAddressIsAShortAddressAndLiesOutsideOfTheValidRange | Parameter *nAddress* is a short address and lies outside the valid range (0...63). |
| 0x0107 | 263 | ParameterAddressIsAGroupAddressAndLiesOutsideOfTheValidRange | Parameter *nAddress* is a group address and lies outside the valid range (0…15). |
| 0x0108 | 264 | ParameterCommandPriorityLiesOutsideOfTheValidRange | Parameter *eCommandPriority* lies outside of the valid range. |
| 0x0109 | 265 | ParameterInstanceAddressTypeLiesOutsideTheValidRange | Parameter *eInstanceAddressType* lies outside of the valid range. |
| 0x010A | 266 | ParameterInstanceAddressIsAInstanceNumberAndLiesOutsideOfTheValidRange | Parameter *nInstanceAddress* is an instance number and lies outside the valid range (0…31). |
| 0x010B | 267 | ParameterInstanceAddressIsAInstanceGroupAndLiesOutsideOfTheValidRange | Parameter *nInstanceAddress* is an instance group and lies outside the valid range (0…31). |
| 0x010C | 268 | ParameterInstanceAddressIsAInstanceTypeAndLiesOutsideOfTheValidRange | Parameter *nInstanceAddress* is an instance type and lies outside the valid range (0…31). |
| 0x010D | 269 | ParameterInstanceAddressIsAFeatureOnInstanceNumberLevelAndLiesOutsideOfTheValidRange | Parameter *nInstanceAddress* is a function at instance number level and lies outside the valid range (0…31). |
| 0x010E | 270 | ParameterInstanceAddressIsAFeatureOnInstanceGroupLevelAndLiesOutsideOfTheValidRange | Parameter *nInstanceAddress* is a function at instance group level and lies outside the valid range (0…31). |
| 0x010F | 271 | ParameterInstanceAddressIsAFeatureOnInstanceTypeLevelAndLiesOutsideOfTheValidRange | Parameter *nInstanceAddress* is a function at instance type level and lies outside the valid range (0…31). |
| 0x0110 | 272 | ParameterGroupLiesOutsideOfTheValidRange | Parameter *nGroup* lies outside of the valid range (0…15). |
| 0x0111 | 273 | ParameterSceneLiesOutsideOfTheValidRange | Parameter *nScene* lies outside the valid range (0…15). |
| 0x0112 | 272 | ParameterFadeTimeLiesOutsideOfTheValidRange | Parameter *nFadeTime* lies outside of the valid range (0…15). |
| 0x0113 | 275 | ParameterFadeRateLiesOutsideOfTheValidRange | Parameter *nFadeRate* lies outside of the valid range (1…15). |
| 0x0114 | 276 | ParameterNewShortAddressLiesOutsideOfTheValidRange | Parameter *nNewShortAddress* lies outside of the valid range (0…63, 255). |
| 0x0115 | 277 | ParameterStartWithShortAddressLiesOutsideOfTheValidRange | Parameter *nStartWithShortAddress* lies outside the valid range (0…63). |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
