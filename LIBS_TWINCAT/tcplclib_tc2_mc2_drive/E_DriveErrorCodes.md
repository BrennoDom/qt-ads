# E_DriveErrorCodes

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# E\_DriveErrorCodes

```
TYPE E_DriveErrorCodes :(  
   MC_Error_MaxNcPositionOverrun            := 16#4BB0  
   MC_Error_MaxPositionOffsetOverrun        := 16#4BB1  
   MC_Error_MinNcPositionUnderrun           := 16#4BB2  
   MC_Error_MinPositionOffsetUnderrun       := 16#4BB3  
   MC_Error_WrongTargetForFeedbackOrMemory  := 16#4BB4  
   MC_Error_PositionReinitializationFailed  := 16#4BB5  
   MC_Error_CommandRejectedNoResponse       := 16#4BB6  
   MC_Error_CommandRejectedWithResponse     := 16#4BB7  
) UDINT;  
END_TYPE
```
