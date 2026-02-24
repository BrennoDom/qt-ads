# E_DMXSlotDefinition

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# E\_DMXSlotDefinition

```
TYPE E_DMXSlotDefinition :  
(  
  eDMXSlotDefinitionIntensity       := 16#0001,  
  eDMXSlotDefinitionIntensityMaster := 16#0002,  
  eDMXSlotDefinitionPan             := 16#0101,  
  eDMXSlotDefinitionTilt            := 16#0102,  
  eDMXSlotDefinitionColorWheel      := 16#0201,  
  eDMXSlotDefinitionColorSubCyan    := 16#0202,  
  eDMXSlotDefinitionColorSubYellow  := 16#0203,  
  eDMXSlotDefinitionColorSubMagenta := 16#0204,  
  eDMXSlotDefinitionColorAddRed     := 16#0205,  
  eDMXSlotDefinitionColorAddGreen   := 16#0206,  
  eDMXSlotDefinitionColorAddBlue    := 16#0207,  
  eDMXSlotDefinitionColorCorrection := 16#0208,  
  eDMXSlotDefinitionColorScroll     := 16#0209,  
  eDMXSlotDefinitionColorSemaphore  := 16#0210,  
  eDMXSlotDefinitionStaticGoboWheel := 16#0301,  
  eDMXSlotDefinitionRotoGoboWheel   := 16#0302,  
  eDMXSlotDefinitionPrismWheel      := 16#0303,  
  eDMXSlotDefinitionEffectsWheel    := 16#0304,  
  eDMXSlotDefinitionBeamSizeIris    := 16#0401,  
  eDMXSlotDefinitionEdge            := 16#0402,  
  eDMXSlotDefinitionFrost           := 16#0403,  
  eDMXSlotDefinitionStrobe          := 16#0404,  
  eDMXSlotDefinitionZoom            := 16#0405,  
  eDMXSlotDefinitionFramingShutter  := 16#0406,  
  eDMXSlotDefinitionShutterRotate   := 16#0407,  
  eDMXSlotDefinitionDouser          := 16#0408,  
  eDMXSlotDefinitionBarnDoor        := 16#0409,  
  eDMXSlotDefinitionLampControl     := 16#0501,  
  eDMXSlotDefinitionFixtureControl  := 16#0502,  
  eDMXSlotDefinitionFixtureSpeed    := 16#0503,  
  eDMXSlotDefinitionMacro           := 16#0504,  
  eDMXSlotDefinitionUndefined       := 16#FFFF  
);  
END_TYPE
```

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
