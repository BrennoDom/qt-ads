# Configuring a Node Connector

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# Configuring a Node Connector

Configuring for `MC_SetCoordinateTransform` is illustrated at the example of a pallet located relative to the `WCS` or `MCS` coordinate system.

|  |  |
| --- | --- |
| 43960571 | Node connector objects  Node connector objects are used by MC\_SetCoordinateTransform and MC\_TrackConveyorBelt. Instead of coordinate frames, node connector objects are addressed by the PLC as representatives. |

## Example

To introduce a coordinate transform using `MC_SetCoordinateTransform:`

:   1. Insert an `MC` Group.  
       
    ![60100823](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5528916747__Web.png)

![4036497](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/8896650891__Web.png)

:   2. Insert a Node Connector.  
       
    ![36328474](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5863287947__Web.png)

![58520811](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/8947348235__Web.png)

:   3. Insert a Coordinate Frame.  
       
    ![56925253](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/8947350155__Web.png)

:   4. Enter relevant Node Connector Parameters - in this example the end node refers to the pallet object identification.  
       
    ![42565233](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5529080587__Web.png)

![47542785](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5863290507__Web.png)

:   5. Enter relevant Coordinate Frame Parameters.  
       
    ![25231885](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5863252107__Web.png)

:   6. Link the inserted Node Connector to the `PLC.`  
       
    ![25760373](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5863246987__Web.png)  
       
    ![30516772](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5863159947__Web.png)  
       
    ![6215498](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5779192203__Web.png)  
       
    ![55939488](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5863244427__Web.png)  
       
    ![33693352](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5863293067__Web.png)

:   Finally‚ you can insert the `MC_SetCoordinateTransform` function block.  
       
    ![34804713](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5863308427__Web.png)

|  |  |
| --- | --- |
| 44806966 | The axis group AxisGroup is linked with the Pick-and-Place function blocks. |

|  |  |
| --- | --- |
| 609510 | For axis movements a move command has to be programmed, e.g. MovePath. |
