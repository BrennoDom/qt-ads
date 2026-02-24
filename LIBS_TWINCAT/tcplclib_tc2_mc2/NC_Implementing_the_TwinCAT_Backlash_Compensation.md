# NC Implementing the TwinCAT Backlash Compensation

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Appendix](ms-xhelp:///?Id=beckhoff-cdf2-455c-a8c9-c0f6b150df73)
3. [NC Backlash Compensation](ms-xhelp:///?Id=beckhoff-67c2-4819-9161-d59c0787cef9)
4. NC Implementing the TwinCAT Backlash Compensation

# NC Implementing the TwinCAT Backlash Compensation

Overview of the effect of the backlash compensation differentiating by type of backlash and reference position (left or right edge):

* **Positive backlash**: Drive resp. external encoder has no backlash – backlash value is positive.
* **Negative backlash:** Additional external encoder has a backlash – backlash value is negative.

|  | Implementation and effect of backlash compensation |
| --- | --- |
| **Reference position at the left edge**  11442060 | **Backlash compensation in negative direction**  **Positive direction:**   * No manipulation   **Negative direction:**   * Manipulation of the current position +backlash * Manipulation of the required position -backlash |
| **Reference position at the right edge**  35869679 | **Backlash compensation in positive direction**  **Positive direction:**   * Manipulation of the required position -backlash * Manipulation of the required position +backlash   **Negative direction:**   * No manipulation |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
