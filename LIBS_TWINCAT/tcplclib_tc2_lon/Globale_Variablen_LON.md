# Globale_Variablen_LON

## Library
tcplclib_tc2_lon

## Category
Motion Control

# Globale\_Variablen\_LON

Default values for all send function blocks

```
VAR_GLOBAL CONSTANT  
    tMinSendTimeDefault := t#1000ms,  
    tMaxSendTimeDefault := t#0s,  
    bAutoDefault     := FALSE,  
    bSendInitDefault := FALSE,  
END_VAR
```

**tMinSendTimeDefault:** Default value for all send function blocks Applies to [automatic mode](ms-xhelp:///?Id=beckhoff-83d9-4e0f-87b8-3129214c5d3f). The modified value is sent once after this time has elapsed.

**tMaxSendTimeDefault:** Default value for all send function blocks Applies to [automatic mode](ms-xhelp:///?Id=beckhoff-83d9-4e0f-87b8-3129214c5d3f). The value is sent once this time has elapsed, irrespective of any change in value.

**bAutoDefault:** Default value for all send function blocks Switching on [automatic mode](ms-xhelp:///?Id=beckhoff-83d9-4e0f-87b8-3129214c5d3f).

**bSendInitDefault:** Default value for all send function blocks After switching on the data is sent once.
