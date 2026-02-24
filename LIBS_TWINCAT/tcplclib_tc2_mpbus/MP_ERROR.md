# MP_ERROR

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [DUTs](ms-xhelp:///?Id=beckhoff-ec1f-451d-a0f5-4c656574c991)
4. [Enums](ms-xhelp:///?Id=beckhoff-a688-45f4-907e-ed52c85f5141)
5. MP\_ERROR

# MP\_ERROR

Library error messages

```
TYPE MP_ERROR :  
(  
  NO_MP_ERROR                         := 0,  
  WRONG_TERMINAL                      := 1,  
  NO_ANSWER_FROM_KL6771               := 2,  
  WRONG_MP_ADDRESS_IS_0               := 10,  
  WRONG_MP_ADDRESS                    := 11,  
  WRONG_SET_POINT                     := 21,  
  MP_BUS_TIMEOUT_NO_ANSWER_FROM_SLAVE := 25,  
  KL6771_TIME_OUT                     := 31,  
  MP_ADDRESS_IS_IN_USE                := 32,  
  MP_DISABLED                         := 33,  
  MP_BUS_ERROR                        := 87,  
  MP_NO_ANSWER_ON_EVENT               := 88,  
  MP_NO_ANSWER                        := 89,  
  MP_COM_BREAK                        := 90,  
  MP_LENGTH_PARITY_ERROR              := 98,  
  MP_CROSS_PARITY_ERROR               := 99,  
  MP_MASTER_CONFLICT_ERROR            := 101,  
  MP_GAP_TIMEOUT_ERROR                := 102,  
  MP_NO_ANSWER_SLAVE                  := 103,  
  MP_ANSWER_ERROR_FLAG                := 110,  
  MP_ANSWER_WRONG_LEN                 := 111,  
  MP_ANSWER_WRONG_TELEG               := 112  
)  
END_TYPE
```

**NO\_MP\_ERROR:** No error

**WRONG\_TERMINAL:** Incorrect terminal connected

**NO\_ANSWER\_FROM\_KL6771:** No response from KL6771. This message usually means that there is no connection to the terminal. Terminal linked to the variables in the System Manager? Terminal plugged in incorrectly? Everything revised, compiled and read again in the System Manager?

**WRONG\_MP\_ADDRESS\_IS\_0:** MP-Bus address is 0. Only addresses between 1 and 8 are allowed.

**WRONG\_MP\_ADDRESS:** MP-Bus address is >8. Only addresses between 1 and 8 are allowed.

**WRONG\_SET\_POINT:** Incorrect setpoint

**MP\_BUS\_TIMEOUT\_NO\_ANSWER\_FROM\_SLAVE:** MP-Bus timeout, no response from slave

**KL6771\_TIME\_OUT:** KL6771 Timeout

**MP\_ADDRESS\_IS\_IN\_USE:** MP-Bus address is in use

**MP\_DISABLED:** MP-Bus locked

**MP\_BUS\_ERROR:** MP-Bus error

**MP\_NO\_ANSWER\_ON\_EVENT:** MP-Bus no response to an event

**MP\_NO\_ANSWER:** MP-Bus no response

**MP\_COM\_BREAK:** -MP-Bus abort communication

**MP\_LENGTH\_PARITY\_ERROR:** MP-Bus length parity error

**MP\_CROSS\_PARITY\_ERROR:** MP-Bus cross parity error

**MP\_MASTER\_CONFLICT\_ERROR:** MP-Bus MASTER\_CONFLICT\_ERROR

**MP\_GAP\_TIMEOUT\_ERROR:** MP-Bus GAP Timeout

**MP\_NO\_ANSWER\_SLAVE:** MP-Bus no response from slave

**MP\_ANSWER\_ERROR\_FLAG:** MP-Bus error bit in response telegram is set

**MP\_ANSWER\_WRONG\_LEN:** MP-Bus wrong telegram length

**MP\_ANSWER\_WRONG\_TELEG:** MP-Bus wrong telegram received.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MPBus from 3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
