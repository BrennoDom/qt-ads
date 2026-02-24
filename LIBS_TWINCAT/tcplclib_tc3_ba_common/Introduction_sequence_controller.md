# Introduction – sequence controller

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# Introduction – sequence controller

In heating, ventilation and air-conditioning systems, it is often the case that several actuators, working in a so-called controller sequence, are used in order to achieve a control variable.

In the air conditioning system shown below, three actuators are involved in the regulation of the supply air temperature. In the project a dedicated sequence controller is instanced for each of these actuators.

During active control only one of these sequence controllers is active. The other, non-active controllers fix their control signal so that it is energetically optimal for the tempering of the inlet air temperature.

Depending on the direction of action of the individual controller, this means either the maximum or the minimum for the control value *lrY*.

If the effect of the active actuator (controller) is insufficient when reaching an end position, the active controller switches to the adjacent controller to the left or right.  
This then takes over control. The previously active controller remains at the end position of *lrYMax* or *lrYMin*, depending on the direction of action. This is repeated with the remaining actuators until the set value or the left or right end of the sequence is reached.

In the sequence of the illustrated air conditioning system, all actuators that influence the control variable are shown from left to right. At the far left is the actuator that enables the greatest possible increase in the supply air temperature; at the far right is the actuator that effects the greatest possible decrease in the supply air temperature.

Some actuators, such as a recirculating air flap or a heat recovery unit change their direction of action during operation. (indirect = heating, direct = cooling)

Actuators with varying direction of action, such as outside air flap, recirculating air flap or heat recovery unit, are only listed once.

* 1: Preheater controller
* 2: Mixed air controller
* 3: Cooler

## Schematic diagram

This plant is schematically represented as follows:

![64660974](/tcplclib_tc3_ba_common/1033/Images/gif/5017805835__en-US__Web.gif)

## Rules for creating a sequence

The following rules must be followed for creating the sequences; inlet air control is used as reference:

* The sequence controllers are numbered starting with the heating sequences with low ordinal numbers to the cooling sequences with high ordinal numbers.  
  ![45077859](/tcplclib_tc3_ba_common/1033/Images/gif/5017810571__en-US__Web.gif)
* A series of heating sequences should not include a cooling sequence. Similarly, a series of cooling sequences should not include a heating sequence. Sequences with reversal of direction of action for a mixed air system or heat recovery should be positioned between the heating and cooling sequences.  
  ![3047552](/tcplclib_tc3_ba_common/1033/Images/gif/5026826507__en-US__Web.gif)  
  In this diagram controller 4 would be placed incorrectly, if controller 5 changed to heating mode. Or: Controller 4 is correct, but controller 5 would have to be a pure cooling controller.   
  In both cases there would be two switches from heating to cooling.
* The set values within the sequence must be monotonically increasing. This requirement is a result of the switching behavior explained above: If the set value of a controller with a lower number is higher than the next higher one, the result could be continuous switching between the two controllers. As mentioned above, controllers with the same direction of action usually have the same set value.  
  SP1 ≤ SP2 ≤ SP3 ≤ SP4 ≤ SP5 ≤ SP6 ≤ SP7 ≤ SP8 ≤ SP9

## Sequence controllers in the PLC

The *TC3\_BA\_Common library* provides two function blocks for the implementation of a sequence controller in the PLC program:

The function block [FB\_BA\_SeqCtrl](ms-xhelp:///?Id=beckhoff-5f1e-4dd3-b036-9ec1a0438ff2): This function block provides an individual controller as part of a sequence of up to 16 controllers.

The function block [FB\_BA\_SeqLink](ms-xhelp:///?Id=beckhoff-d060-4ce8-9edc-114c51dff6a8): This function block is the control function block of the sequence and therefore only exists once per sequence. It decides which controller of the sequence is currently active and checks the sequence for certain error states, such as duplicate allocation of ordinal number at the controllers.

The structure variable [ST\_BA\_SeqLink](ms-xhelp:///?Id=beckhoff-a03c-4c29-895b-799bbd71e49e) is used to link the sequence controllers with the sequence linker [FB\_BA\_SeqLink](ms-xhelp:///?Id=beckhoff-d060-4ce8-9edc-114c51dff6a8).

This structure variable has to be declared once per sequence control.

The sequence control is enabled at input *bEn* of the function block [FB\_BA\_SeqLink](ms-xhelp:///?Id=beckhoff-d060-4ce8-9edc-114c51dff6a8). The variable *usiStartCtrl* is used to determine which controller is used as the first one after the start of control mode. In the example, the sequence controller with the no. 5 is assigned as the start controller. Switching from controller 5 to another controller in the sequence after restarting the control is blocked for the value of the input variable *udiIniSwiOvrDly\_sec*.

![27427975](/tcplclib_tc3_ba_common/1033/Images/gif/5026832395__Web.gif)
