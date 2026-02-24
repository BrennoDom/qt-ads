# E_KL6581_Err

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# E\_KL6581\_Err

Error messages.

```
TYPE E_KL6581_Err :  
(  
  NO_ERROR                 := 16#0,  
  KL6581_WrongTerminal     := 16#A,  
  KL6581_WatchdogError     := 16#10,  
  KL6581_NoComWithKL6581   := 16#11,  
  KL6581_idx_number_not_OK := 16#12,  
  KL6581_Switch_to_Stopp   := 16#13,  
  KL6581_not_ready         := 16#14,  
  KL6581_No_KL6853_Found   := 16#15,  
  KL6581_TransmissionError := 16#16  
)  
END_TYPE
```

**NO\_ERROR:** No error at the block.

**KL6581\_WrongTerminal:** Incorrect terminal connected.

**KL6581\_WatchdogError:** Timeout during initialization of block "FB\_KL6581".

**KL6581\_NoComWithKL6581:** This message usually means that there is no connection to the terminal. Terminal linked to the variables in the System Manager? Terminal plugged in incorrectly? Everything corrected, everything translated and re-read into the System Manager?

**KL6581\_idx\_number\_not\_OK:** The input variable *nIdx* of block [FB\_KL6581()](ms-xhelp:///?Id=beckhoff-45e5-4533-98ae-900c39c9c4dc) is greater than 64.

**KL6581\_Switch\_to\_Stopp:** The terminal has exited the data exchange with the KL6583. No EnOcean data was sent or received.

**KL6581\_not\_ready:** Internal message for the function blocks connected to the FB\_KL6581().

**KL6581\_No\_KL6853\_Found:** No KL6583 is connected to the KL6581, or the communication does not exist.

**KL6581\_TransmissionError:** Data could not sent; check the address of the KL6583, or KL6583 not ready for operation.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
