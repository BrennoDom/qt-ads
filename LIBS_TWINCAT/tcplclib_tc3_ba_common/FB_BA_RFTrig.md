# FB_BA_RFTrig

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# FB\_BA\_RFTrig

![53055045](/tcplclib_tc3_ba_common/1033/Images/gif/9007204969259659__Web.gif)

Function block for the detection of a rising or falling edge on a Boolean variable. The use of the separate function blocks R\_TRIG and F\_TRIG can be avoided with the block.

## VAR\_INPUT

```
bValue    : BOOL;
```

**bValue:** Value to be monitored.

## VAR\_OUTPUT

```
Q        : BOOL;  
Qr       : BOOL;  
Qf       : BOOL;
```

**Q:** *TRUE* if an edge is detected.

**Qr:** Result of the last comparison (*TRUE* as soon as the monitored value changes from *FALSE* to *TRUE*).

**Qf:** Result of the last comparison (*TRUE* as soon as the monitored value changes from *TRUE* to *FALSE*).

## Requirements

| Development environment | Required library | Necessary function |
| --- | --- | --- |
| TwinCAT3.1 4022.16 | Tc3Building Automation Common from V1.0.4.3 | TF8040 | TwinCAT Building Automation from V1.0.5.0 |
