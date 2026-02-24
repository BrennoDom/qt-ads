# Introduction

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Commands](ms-xhelp:///?Id=beckhoff-e647-4709-92f0-6dc69db8d17c)
5. [Part 253 (diagnostics and maintenance)](ms-xhelp:///?Id=beckhoff-1ee7-4b72-9f2a-5e21a4214c0a)
6. Introduction

# Introduction

In specifications that go beyond the current DALI-2 standard, the [Digital Illumination Interface Alliance](https://www.digitalilluminationinterface.org) (DiiA) describes additional DALI parts for the operation of intelligent luminaires.

These new parts are combined under the term D4i (DALI inside of luminaires).

The current library supports Parts 251 (DT50), 252 (DT51) and 253 (DT52).

These parts contain functions that can be forwarded to the higher-level DALI network for evaluation and control.

They describe the location, type and format of the data in the memory banks of the DALI control gears. In addition, they describe the exchange of data with DALI control devices.

## Part 253 – Diagnostics and maintenance

Part 252 writes additional memory banks in which diagnostic and maintenance data can be read and partly specified.

Memory bank 205 contains information on diagnostics and maintenance of the DALI control gear.

Memory bank 206 contains information on the diagnostics and maintenance of the light source.

Memory bank 207 contains maintenance information on the luminaire.

This information is obligatory and is provided by DALI control gears that support Part 253.

The entire contents of memory banks 205, 206 and 207 are read via the function block [FB\_DALI102ReadMemoryBank](ms-xhelp:///?Id=beckhoff-5b05-4a6d-99fe-7e473b13d0d9).

Part 253 also provides the function blocks described below for reading the individual parameters.

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
