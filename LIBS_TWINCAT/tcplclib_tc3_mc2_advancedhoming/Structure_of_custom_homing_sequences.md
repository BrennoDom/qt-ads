# Structure of custom homing sequences

## Library
tcplclib_tc3_mc2_advancedhoming

## Category
Motion Control

# Structure of custom homing sequences

User-specific homing sequences can be created in a simple manner from the available function blocks. Note that when doing so every sequence must always be ended by a finalizing FB so that, if necessary, modified parameters of the TwinCAT NC or the drive controller can be reconstructed and the "HomingState" is also changed correspondingly.
