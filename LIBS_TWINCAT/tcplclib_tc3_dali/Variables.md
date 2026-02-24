# Variables

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Commands](ms-xhelp:///?Id=beckhoff-e647-4709-92f0-6dc69db8d17c)
5. [Part 209 (color/color temperature control)](ms-xhelp:///?Id=beckhoff-d816-4de1-bd09-5e02b92cfc27)
6. Variables

# Variables

Every DALI control gear for color/color temperature control has a certain number of variables (parameters ) from which it is possible to read a variety of information or to modify individual parameters.

Some variables can be read directly by DALI commands (e.g. [FB\_DALI209QueryColourStatus](ms-xhelp:///?Id=beckhoff-bf40-4ec1-9ae2-4b4f83c3bbdc)). The function block [FB\_DALI209QueryColourValue](ms-xhelp:///?Id=beckhoff-4ad3-452c-886e-35d8b4c38cbf) can be used to read further variables.

| Name | Reset value | Scope | Size | [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7) | Comment |
| --- | --- | --- | --- | --- | --- |
| temporaryX-Coordinate | 65535 | 0…65535 | 2 bytes | 0, 2 |  |
| reportX-Coordinate | 65535 | 0…65535 | 2 bytes | 0 |  |
| [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7) | No change | 0…65535 | 2 bytes | 0 |  |
| temporaryY-Coordinate | 65535 | 0…65535 | 2 bytes | 0, 2 |  |
| reportY-Coordinate | 65535 | 0…65535 | 2 bytes | 0 |  |
| [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7) | No change | 0…65535 | 2 bytes | 0 |  |
| temporaryColourTemperatureTc | 65535 | 1…65535 | 2 bytes | 1 |  |
| report olourTemperatureTc | 65535 | 1…65535 | 2 bytes | 1 |  |
| [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7) | No change | 1…65535 | 2 bytes | 1 |  |
| colourTemperatureTcCoolest | *colourTemperatureTcPhysicalCoolest* | *colourTemperatureTcPhysicalCoolest* … *colourTemperatureTcWarmest*, 65535 | 2 bytes | 1 | Read only |
| colourTemperatureTcWarmest | *colourTemperatureTcPhysicalWarmest* | *colourTemperatureTcCoolest* … *colourTemperatureTcPhysicalWarmest*, 65535 | 2 bytes | 1 | Read only |
| colourTemperatureTcPhysicalCoolest | No change | 1 … *colourTemperatureTcPhysicalWarmest*, 65535 | 2 bytes | 1 | Read only |
| colourTemperatureTcPhysicalWarmest | No change | *colourTemperatureTcPhysicalCoolest* … 65534, 65535 | 2 bytes | 1 | Read only |
| temporaryPrimaryNDimlevel | 65535 | 0...65535 | 2 bytes | 2 |  |
| reportPrimaryNDimlevel | 65535 | 0…65535 | 2 bytes | 2 |  |
| primaryNDimlevel | No change | 0…65535 | 2 bytes | 2 |  |
| x-CoordinatePrimaryN | No change | 0…65535 | 2 bytes | 0, 2 | Read only |
| y-CoordinatePrimaryN | No change | 0…65535 | 2 bytes | 0, 2 | Read only |
| tyPrimary | No change | 0…65535 | 2 bytes | 0, 2 | Read only |
| temporaryRedDimlevel | 255 | 0…255 | 1 byte | 3 |  |
| reportRedDimlevel | 255 | 0…255 | 1 byte | 3 |  |
| [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7) | No change | 0…255 | 1 byte | 3 |  |
| temporaryGreenDimlevel | 255 | 0…255 | 1 byte | 3 |  |
| reportGreenDimlevel | 255 | 0…255 | 1 byte | 3 |  |
| [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7) | No change | 0…255 | 1 byte | 3 |  |
| temporaryBlueDimlevel | 255 | 0…255 | 1 byte | 3 |  |
| reportBlueDimlevel | 255 | 0…255 | 1 byte | 3 |  |
| [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7) | No change | 0…255 | 1 byte | 3 |  |
| temporaryWhiteDimlevel | 255 | 0…255 | 1 byte | 3 |  |
| reportWhiteDimlevel | 255 | 0…255 | 1 byte | 3 |  |
| [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7) | No change | 0…255 | 1 byte | 3 |  |
| temporaryAmberDimlevel | 255 | 0…255 | 1 byte | 3 |  |
| reportAmberDimlevel | 255 | 0…255 | 1 byte | 3 |  |
| [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7) | No change | 0…255 | 1 byte | 3 |  |
| temporaryFreecolourDimlevel | 255 | 0…255 | 1 byte | 3 |  |
| reportFreecolourDimlevel | 255 | 0…255 | 1 byte | 3 |  |
| [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7) | No change | 0…255 | 1 byte | 3 |  |
| temporaryRGBWFControl | 255 | 0…255 | 1 byte | 3 |  |
| report RGBWF Control | 255 | 0…255 | 1 byte | 3 |  |
| [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7) | No change | 0…255 | 1 byte | 3 |  |
| [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7) | 16#0102\_0304\_0506 | 16#0000\_0000\_0000 … 16#0606\_0606\_0606 | 6 bytes | 3 | Read only  MSB: Channel 0  LSB: Channel 5 |
| [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7) | 255 | 16#10, 16#20, 16#40, 16#80, 16#FF | 1 byte | 0, 1, 2, 3 |  |
| [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7) | 255 | 16#10, 16#20, 16#40, 16#80, 16#FF | 1 byte | 0, 1, 2, 3 |  |
| [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7) | 65535 | 16#10, 16#20, 16#40, 16#80, 16#FF | 1 byte | 0, 1, 2, 3 | Read only |
| scene0-15ColourValue | 65535 | 0…65535 | 32 bytes…192 bytes | 0, 1, 2, 3 | Read only |
| [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7) | Manufacturer-dependent | 16#10, 16#20, 16#40, 16#80, 16#FF | 1 byte | 0, 1, 2, 3 | Read only |
| powerOnColourValue | Manufacturer-dependent | 0…65535 | 2 bytes…12 bytes | 0, 1, 2, 3 | Read only |
| [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7) | Manufacturer-dependent | 16#10, 16#20, 16#40, 16#80, 16#FF | 1 byte | 0, 1, 2, 3 | Read only |
| systemFailureColourValue | Manufacturer-dependent | 0…65535 | 2 bytes…12 bytes | 0, 1, 2, 3 | Read only |
| [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7) | 2#XX00\_0001 | 2#XX00\_0000, 2#XX00\_0001 | 1 byte | 0, 1, 2, 3 |  |
| [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7) | No change | 0…255 | 1 byte | 0, 1, 2, 3 |  |
| [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7) | No change | 0…255 | 1 byte | 0, 1, 2, 3 | Read only |

? or X: not specified

In the case of 1-byte values the value 255 is also called MASK.

In the case of 2-byte values the value 65535 is also called MASK.

**Necessary color representation**

Specifies the color representation that the DALI control gear must support so that it contains the appropriate variables:

| Value | Description |
| --- | --- |
| 0 | xy coordinates |
| 1 | Color temperature Tc |
| 2 | Primary (color) N |
| 3 | RGBWAF |

## x-Coordinate

Chromaticity coordinate x in the xy color type

The *x-Coordinate* is specified in [MIREK\_TO\_KELVIN](ms-xhelp:///?Id=beckhoff-d40f-4323-8b07-c2c0144e10e7).

It can vary from 0 Mirek (0 K) to 65534 Mirek (15.26 K).

At a value of 65535 (MASK), the value is not defined.

## y-Coordinate

Chromaticity coordinate y in the xy color type

The *y-Coordinate* is specified in [MIREK\_TO\_KELVIN](ms-xhelp:///?Id=beckhoff-d40f-4323-8b07-c2c0144e10e7).

It can vary from 0 Mirek (0 K) to 65534 Mirek (15.26 K).

At a value of 65535 (MASK), the value is not defined.

## colourTemperatureTc

The variable *colourTemperatureTc* defines the color temperature. It is adjustable in the range between *colourTemperatureTcWarmest* and *colourTemperatureTcCoolest*.

The *colourTemperatureTc* is specified in [MIREK\_TO\_KELVIN](ms-xhelp:///?Id=beckhoff-d40f-4323-8b07-c2c0144e10e7).

It can vary from 1 Mirek (1,000,000 K) to 65534 Mirek (15.265 K).

## dimlevel

Setting of the dimming level of the corresponding color (red, green, blue, white, amber or a freely selectable color) from 0 to 255.

## assignedColour

The association between output channel and color is defined in the *assignedColour* variable. Each byte contains the color of the corresponding channel. The function block FB\_DALI209QueryAssignedColour can be used to read out the value.

| Value | Description |
| --- | --- |
| 0 | No color assigned |
| 1 | Red |
| 2 | Green |
| 3 | Blue |
| 4 | White |
| 5 | Amber |
| 6 | Freely selectable color |

## colourType

The *colourType* variable defines the color representations supported by the DALI control gear. The function block [FB\_DALI209QueryColourValue](ms-xhelp:///?Id=beckhoff-4ad3-452c-886e-35d8b4c38cbf) can be used to read out the values.

| E\_DALIColourType | Description |
| --- | --- |
| XyCoordinate | xy coordinates |
| ColourTemperatureTc | Color temperature Tc |
| PrimaryNDimlevel | Primary (color) N |
| RGBWAFControl | RGBWAF |
| MASK | No color change |

## colourStatus

*colourStatus* contains information about the current status of the DALI control gear.

The function block [FB\_DALI209QueryColourStatus](ms-xhelp:///?Id=beckhoff-bf40-4ec1-9ae2-4b4f83c3bbdc) can be used to read out the values

| Bit | Description |
| --- | --- |
| 0 | xy coordinate color point is outside the valid range. |
| 1 | Color temperature Tc lies outside the valid range |
| 2 | Automatic calibration is active. |
| 3 | Automatic calibration was successful. |
| 4 | Color representation xy-coordinate active. |
| 5 | Color representation color temperature Tc active. |
| 6 | Color representation primary N active. |
| 7 | Color representation RGBWAF active. |

## gearFeatures/Status

gearFeatures*/Status* contains information about the current status of the DALI control gear.

The function block [FB\_DALI209QueryGearFeaturesStatus](ms-xhelp:///?Id=beckhoff-d30c-47a5-9332-24da343c569c) can be used to read out the values. The function block [FB\_DALI209StoreGearFeaturesStatus](ms-xhelp:///?Id=beckhoff-2380-410d-a19e-9ce565d8f7b5) can be used to write the values.

| Bit | Description |
| --- | --- |
| 0 | Automatic activation |
| 1…5 | Reserved |
| 6 | Automatic calibration is supported |
| 7 | Restoration of the automatic calibration is supported |

## RGBWAFControl

*RGBWAFControl* contains further information about the assignment between output channel and color.

| Bit | Description |
| --- | --- |
| 0 | Output channel 0 / red |
| 1 | Output channel 1 / green |
| 2 | Output channel 2 / blue |
| 3 | Output channel 3 / white |
| 4 | Output channel 4 / amber |
| 5 | Output channel 5 / free selectable color |
| 6…7 | 00 = channel control 01 = color control 10 = standardized color control 11 = reserved |

## colourTypeFeatures

*colourTypeFeatures* defines the color representations supported by the DALI control gear. The values can be read out using the [FB\_DALI209QueryColourTypeFeatures](ms-xhelp:///?Id=beckhoff-fa18-4f40-937a-e3a48f92906a) function block.

| Bit | Description |
| --- | --- |
| 0 | The DALI control gear supports color representation through xy coordinates. |
| 1 | The DALI control gear supports color representation through color temperature Tc. |
| 2…4 | Number of primary colors supported by the DALI control gear. A value of 0 means that this color representation by primary colors is not supported. |
| 5…7 | Number of RGBWAF channels supported by the DALI control gear. A value of 0 means that this color representation by RGBWAF is not supported. |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
