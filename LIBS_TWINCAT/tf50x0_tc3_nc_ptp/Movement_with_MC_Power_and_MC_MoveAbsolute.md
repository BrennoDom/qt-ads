# Movement with MC_Power and MC_MoveAbsolute

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Movement with MC\_Power and MC\_MoveAbsolute

In this section you will find out how to set the general software and controller enable and the enable for the positive and negative direction of travel for an axis and how to move to a target position.

## NC axis: Online

* After the TwinCAT system has been restarted in Run mode, the **Ready** and **NOT Moving** checkboxes are each checked in the **Status (log.)** group box in the **Online** dialog for the NC axis **Standard (Mapping via Encoder and Drive).**

|  |  |
| --- | --- |
| 9426010DANGER | |
| Risk of injury due to movement of axes!  The commissioning results in a movement of axes. There is a risk of injury to body parts. Keep an appropriate safety distance, and stay clear of the operating space. | |

## MAIN [Online]: MC\_Power

:   1. Log in the compiled PLC project with the **Login** button.
:   2. Start the PLC program with the **Start** button.
![17725233](/tf50x0_tc3_nc_ptp/1033/Images/png/2852136075__Web.png):   3. Open the online view for the `MAIN` program.
:   4. In the declaration part of the `MAIN` program, set the local variable `bEnable` to `TRUE`.

:   As a result, the general software and controller enable has been set for the `axis` and the feed enable has been issued for the positive and negative direction of travel.
:   In the **Online** dialog of the NC axis, the **Override** text box contains the percentage value `100.0000`, corresponding to the value of the variable `fOverride`.
:   In the **Online** dialog of the NC axis, the **Controller**, **Feed Fw** and **Feed Bw** checkboxes are checked in the **Enabling** group box.

![25309374](/tf50x0_tc3_nc_ptp/1033/Images/png/2833869451__Web.png)![26457778](/tf50x0_tc3_nc_ptp/1033/Images/png/2833872651__Web.png)

## MAIN [Online]: MC\_MoveAbsolute

:   The online view for the `MAIN` program is open.
:   The variable `bMove` has the value `FALSE`.

:   1. In the declaration part of the `MAIN` program, set the variable `bMove` to the value `TRUE`, thus generating a rising edge.

:   In the implementation part, this gives the `Execute` input of the MC\_MoveAbsolute function block a value of `TRUE` and a rising edge.
:   While moving, the **Online** dialog in the **Status (log.)** group box of the NC axis unchecks the **NOT Moving** checkbox and checks the **Moving Fw** and **Has Job** checkboxes.
:   When the NC axis has arrived at the target position, the **Moving Fw** and **Has Job** checkboxes are unchecked and the **NOT Moving** checkbox is checked again.
:   When the NC axis has arrived at the target position, the **In Target Pos.** and **In Pos. Range** checkboxes in the **Status (phys.)** group box will be checked.

While moving, the **Moving Fw** and **Has Job checkboxes in the Status (log.)** group box are checked.

![36793414](/tf50x0_tc3_nc_ptp/1033/Images/png/2833965451__Web.png)

When the NC axis has arrived at the target position, the **NOT Moving** checkbox in the **Status (log.)** group box is checked.

![62705275](/tf50x0_tc3_nc_ptp/1033/Images/png/2833968651__Web.png)

And the **In Target Pos.** und **In Pos. Range** checkboxes in the **Status (phys.)** group box are checked.

![27476571](/tf50x0_tc3_nc_ptp/1033/Images/png/2833971851__Web.png)

Set the variable `bMove` back to the value `FALSE` in order to be able to generate a new rising edge later if necessary.

## Resetting the software enable

:   1. Set the variable `bEnable` back to the value `FALSE`.

:   By doing this you cancel the feed enable for the positive direction of travel, the feed enable for the negative direction of travel and the general software and controller enable for the NC axis.
:   In the **Online** dialog of the NC axis, the value Override is reset to the value `0.0000`.
:   In the **Online** dialog of the NC axis, the **Controller**, **Feed Fw** and **Feed Bw** checkboxes in the **Enabling** group box are unchecked.

![45962549](/tf50x0_tc3_nc_ptp/1033/Images/png/2833978251__Web.png)![11009764](/tf50x0_tc3_nc_ptp/1033/Images/png/2833975051__Web.png)
