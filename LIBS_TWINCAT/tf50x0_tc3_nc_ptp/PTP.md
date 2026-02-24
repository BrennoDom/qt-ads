# PTP

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# PTP

PTP stands for point-to-point. PTP axis functionality is a control process for **one-dimensional positioning** of axes, in particular servo axes, but also other types of axes. One-dimensional does not necessarily mean linear. It simply means that one component is interpolated in some specified coordinate system (Cartesian coordinates, polar coordinates).

PTP is a licence level for basic axis numerical control. PTP forms the basis of the whole of TwinCAT NC, because at **system start-up** the axes are normally in PTP mode, and thus are position controlled. The extended TwinCAT NC functionalities are achieved on the basis of the PTP modes by reconfiguration (FIFO, NCI) or by coupling (all slave types).
