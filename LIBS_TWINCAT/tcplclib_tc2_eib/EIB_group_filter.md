# EIB group filter

## Library
tcplclib_tc2_eib

## Category
Motion Control

# EIB group filter

The EIB group filters have to be parameterized before the KL6301 can enter data exchange mode. The filters are required for all data with a group address sent to the KL6301. Each group telegram that is also included in the filters is acknowledged and entered in the process data, i.e. it is visible in the function blocks. The KL6301 discards EIB telegrams with group addresses that are not included in the filter.

## Sample

Filter 1 group address 1/2/0 length: 20  
 All EIB telegrams with group address 1/2/0 - 1/2/19 pass through the filter

At least one filter has to be activated. A maximum of 4 filters are possible. Filter entries can have a length between 0 and 63. 0 means exactly 1 entry. 63 means that 64 group addresses are enabled.

![27134857](/tcplclib_tc2_eib/1033/Images/gif/187830539__en-US__Web.gif)

## Changes for Firmware B1 and library version V3

With firmware version B1 and TwinCAT library Tc2\_EIB (V3) instead of **4 filters also 8 filters** can be parameterized. But the maximum length of each filter is reduced from 64 to 32 entries per filter group. So the maximum of all group filters to be received is constant with 256.
