# dwErrorKL

## Library
tcplclib_tc2_lon

## Category
Motion Control

# dwErrorKL

| Return parameter dwErrorKL | FW | Meaning |
| --- | --- | --- |
| 0000 0000hex |  | No error |
| 0000 0001hex |  | Write access to a read parameter |
| 0000 0004hex |  | Undefined parameter |
| 0000 0005hex |  | Illegal value for parameter |
| 0000 0007hex |  | Undefined slot |
| 0000 0008hex |  | Error when reading the NV parameter |
| 0000 0009hex |  | Checksum error when downloading the LON configuration |
| 0000 0010hex | from FW5 | OUTGOING\_MSG\_FAILED |
| 0000 0011hex | from FW5 | OUTGOING\_MSG\_LATE\_ACK |
| 0000 0012hex | from FW5 | OUTGOING\_MSG\_MALFORMED |
| 0000 0013hex | from FW5 | NEURON\_QUERY\_FAILED |
| 0000 0014hex | from FW5 | NEURON\_UPDATE\_FAILED |
| 0000 000Ahex |  | Fault with the upload of a LON configuration |
| 0000 0Cxxhex |  | An SNVT variable that is to be written has not arrived, xx corresponds to the SNVT index number |
| 0000 0Exxhex |  | NV index is not an output. The PLC attempts to write to an NV index that was not defined as an output with the KS2000 (nvo). xx corresponds to the SNVT index number |
| 0000 0Fxxhex |  | Confirmation of the LON telegram to be written has arrived too late (> 1500 ms), xx corresponds to the SNVT index number |
| 0000 400xhex | from FW5 | NEURON\_MGMT\_ERROR. x corresponds to the API code |
