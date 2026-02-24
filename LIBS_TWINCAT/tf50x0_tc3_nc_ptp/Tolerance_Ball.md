# Tolerance Ball

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Tolerance Ball

[1][2][3][4]

|  |  |
| --- | --- |
| [1] | Glue dot. |

|  |  |
| --- | --- |
| [2] | Segment, geometrical element, here: line. |

|  |  |
| --- | --- |
| [3] | Tolerance ball. |

|  |  |
| --- | --- |
| [4] | Transition, smooth path. |

**Motivation**

|  |  |
| --- | --- |
| *Dynamical-* *Steadiness* | * Segment transitions that are not two times steadily differentiable with respect to their spatial coordinate lead to dynamic-unsteadinesses, if at this transition the path velocity is not reduced to *zero* value. * Segment transitions can be smoothed out using Bézier-splines leading to the dynamics for the whole path to be steady at the segment transition, even though path velocity differs from *zero*. |
| *Smoothening* | * Tolerance balls are used to smooth out dynamic unsteadiness at segment transitions. |
| *Faster* *Dynamics* | * Smoothening permitts faster dynamics. * The maximum segment transition velocity calculated by the system in advance has the value *VeloLink*. * The user can change the system parameter *C2* for C2-velocity reduction online. * The segment transition velocity has the value *C2 x VeloLink*. |

**Definition**

|  |  |
| --- | --- |
| *Segment Transition* | * For the smoothening a tolerance ball is placed around each segment transition. |
| *Permitted* *Path Deviation* | * Up to the extend that the path stays within the tolerance ball, this path may deviate from its predefined geometry within this tolerance ball. |

**Parameter**

|  |  |
| --- | --- |
| *Radius* | * The user adjusts the radius of the tolerance ball. |

**Range of Validity**

|  |  |
| --- | --- |
| *No* *Exact Halt,* *No Stop* | * The radius of the tolerance ball is valid modally for all segment transitions that at the segment transition do not imply an exact halt or a stop. |

**Algorithmic Behavior**

|  |  |
| --- | --- |
| *Adaptive* | * Automatically, the radii of the tolerance balls are set adaptively. |
| *Inhibit* *Overlap* | * Setting the radii adaptively prevents from overlap of the tolerance balls. Otherwise, especially for small segments an overlap of tolerance balls could occur. |
| *At the* *Segment Transition* | * Within the tolerance ball there is no override. * Entering the tolerance ball the path acceleration obtains *zero* value. * Entering the tolerance ball the path velocity obtains the value of the segement transition velocity. * Within the tolerance ball the path acceleration stays at *zero* value. * Within the tolerance ball the path velocity remains at the value of the segment transition velocity. * The override induced change of velocity level is interrupted within the tolerance ball and is continued after leaving the tolerance ball. |
