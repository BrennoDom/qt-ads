# FB_TcClearLoggedEventsSettings

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# FB\_TcClearLoggedEventsSettings

![12469873](/tcplclib_tc3_eventlogger/1033/Images/png/10408509963__Web.png)

Provides the functionality to specify which events should be removed from the cache.

## Syntax

Definition:

```
FUNCTION_BLOCK FB_TcClearLoggedEventsSettings IMPLEMENTS I_TcClearLoggedEventsSettings
```

## 45119994 Methods

| Name | Definition location | Description |
| --- | --- | --- |
| AddFilter | Local | Method for adding a filter. Returns `S_OK` if successful. |
| Clear | Local | Method for clearing the settings. Returns `S_OK` if successful. |
| SetLimit | Local | Indicates the number of events to be cleared. The limit is applied after sorting and filtering. Returns `S_OK` if successful. |
| SetSorting | Local | Sets the sort order for the query. Returns `S_OK` if successful. |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024.17 | PC or CX (x64, x86, ARM) | Tc3\_EventLogger (>= v3.1.27.0) |

Further Information

* [AddFilter](ms-xhelp:///?Id=beckhoff-5e09-482a-8c04-66722bdc5481)
* [Clear](ms-xhelp:///?Id=beckhoff-cbc0-462e-8b9e-58aae8f1f592)
* [SetLimit](ms-xhelp:///?Id=beckhoff-8b18-4f88-93e5-3a00eff16481)
* [SetSorting](ms-xhelp:///?Id=beckhoff-80fe-4423-9ec8-4706c0e9cb20)
