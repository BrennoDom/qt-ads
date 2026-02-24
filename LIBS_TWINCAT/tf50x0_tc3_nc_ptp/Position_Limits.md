# Position Limits

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Position Limits

The section "Limits for positions" shows how a collision can be prevented and how, for example, the software limit switch or the position lag monitoring can be enabled.

|  |  |
| --- | --- |
| 6648223 | Purely functional settings are explained in the section "Limits for positions"; these are not safety functions in the sense of safety technology. |

## NC axis: Parameters

![59834015](/tf50x0_tc3_nc_ptp/1033/Images/png/2833827851__Web.png)![1635228](/tf50x0_tc3_nc_ptp/1033/Images/png/2833981451__Web.png)

## Collision-prevention measures

|  |  |
| --- | --- |
| Note | |
| If the commissioning is not carried out correctly, this can lead to a collision and damage.   * Activate the software limit switch. * Activate the position lag monitoring. * Use freely rotating axes for initial commissioning. | |

|  |  |
| --- | --- |
| Note | |
| An incorrect scaling factor and an incorrect direction of rotation can cause damage.   * Inside the IO configuration, double-click the servo drive for which you wish to open the Drive Manager. * Set the scaling factor and the direction of rotation in the Drive Manager. | |

## Activating the software limit switches

:   1. Select the NC axis for which you wish to activate the software limit switches.
:   2. Open the **Parameters** dialog for this NC axis.
:   3. Set the value of the parameter Limit Switches: Soft Position Limit Minimum Monitoring [1] to `TRUE`.   
    To do this, use the associated drop-down box in the table column Offline Value.
:   4. Set the value of the parameter Limit Switches: Soft Position Limit Maximum Monitoring [2] to `TRUE`.   
     To do this, use the associated drop-down box in the table column Offline Value.
:   5. With the parameter Limit Switches: Minimum Position [4] for the smallest position value that can be driven to, set a value that allows sufficient freedom of movement while ruling out the possibility of a collision.
:   6. With the parameter Limit Switches: Maximum Position [5] for the largest position value that can be driven to, set a value that allows sufficient freedom of movement while ruling out the possibility of a collision.

:   You have activated the software limit switches for the selected NC axis.

## Activating the position lag monitoring

:   1. Select the NC axis for which you wish to activate the software limit switches.
:   2. Open the **Parameters** dialog for this NC axis.
:   3. For the parameter Monitoring: Position Lag Monitoring [3], set the value `TRUE`.  
    To do this, use the associated drop-down box in the table column Offline Value.
:   4. With the parameter Monitoring: Maximum Position Lag Value [6], set a value for the largest permissible position lag that allows sufficient control freedom while ruling out the possibility of a collision.  
    The default value is usually OK.
:   5. For the parameter Monitoring: Maximum Position Lag Value [7], set a value that allows sufficient control freedom while ruling out the possibility of a collision.  
    The default value is usually OK.

:   You have activated the position lag monitoring for the selected NC axis.
