# Configure for MC_TrackConveyorBelt

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# Configure for MC\_TrackConveyorBelt

To track a conveyor belt using `MC_TrackConveyorBelt:`

:   1. Insert an `MC` Group.  
       
    ![5485596](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5528916747__Web.png)

![49370368](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/8896650891__Web.png)

:   2. Insert a Node Connector.

![41680131](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/8947352075__Web.png)

:   3. Insert a Coordinate Frame.  
       
    ![39576862](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5863200907__Web.png)

:   4. Insert Conveyor Tracking. Firstly, a Coordinate Frame has been created. Secondly, the Conveyor Tracking Object has to be added as a child element to the Coordinate Frame created previously.  
       
    ![20647442](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/8947355915__Web.png)

![51609257](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/8947370635__Web.png)

:   5. Enter relevant Node Connector Parameters - the end node refers to the conveyor tracking object identification.  
       
    ![61830130](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5529080587__Web.png)

![19600264](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5863285387__Web.png)

:   6. Enter relevant Coordinate Frame Parameters.  
       
    ![42184651](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5529029387__Web.png)

![44117540](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5863254667__Web.png)

:   7. Enter relevant Conveyor Tracking Parameters.

![61513540](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/9142249099__Web.png)

The Default Tracking Behavior specifies whether, after `InSync` has been reached for the first time, the tracking movement is still limited by the specified dynamic limits (`InSync` may be lost again) or synchronization is forced (even if the dynamic limits need to be violated in order to do so).

:   8. Link the Node Connector to the `PLC.`  
       
    ![16750948](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5863193227__Web.png)  
       
    ![16540805](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5863157387__Web.png)  
       
    ![14649520](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5779176843__Web.png)  
       
    ![64736823](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5863165067__Web.png)  
       
    ![45760497](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5863162507__Web.png)

:   Finally‚ you can insert the `MC_TrackConveyorBelt` function block.  
       
    ![9191297](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5863310987__Web.png)
