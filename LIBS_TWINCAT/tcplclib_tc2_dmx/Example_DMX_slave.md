# Example: DMX slave

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# Example: DMX slave

## Receipt of 64 bytes of data by each of two DMX slaves (EL6851-0010)

[Files](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_dmx/Resources/zip/18014399087890699.zip) for TwinCAT 3.1.

Arrays with 64 bytes each in full configuration (all PDOs selected):

![25151854](/tcplclib_tc2_dmx/1033/Images/gif/578412811__en-US__Web.gif)

An EL6851-0010 can read max. 512 bytes (64 bytes in each one of eight arrays, see fig. 1). The arrays can be assigned in the TwinCAT XAE (*Process data* tab) via the PDO 0x1C13.

**Example:**

DMX channels 1 - 64 -- > Index 0x1A01

DMX channels 65 - 128 -- > Index 0x1A02

....

DMX channels 449 - 512 -- > Index 0x1A08

* DMX channels 1 - 64 (default) by selection of PDO 0x1A01:
![25040094](/tcplclib_tc2_dmx/1033/Images/gif/578415243__en-US__Web.gif)* DMX channels 65 - 128 by selection of PDO 0x1A02:

![24034261](/tcplclib_tc2_dmx/1033/Images/gif/578416907__en-US__Web.gif)

In the example program the first DMX Slave receives the first 64 bytes sent and the second slave the next 64 bytes (figs. 2 + 3; it is also possible for one EL6851-0010 to receive the entire 128 bytes, the division is chosen deliberately in the example).

DMX status object:

![14981763](/tcplclib_tc2_dmx/1033/Images/gif/578418571__en-US__Web.gif)

In the DMX status object (index 0x6000, *DMX status*, Fig. 4) a copy counter is created with index 0x6000:11 (*channel length*).

**Example:**

If PDO 0x1A01 is activated, the value of *Channel length* is 64dec. If PDO 0x1A02 is activated, the value is 128dec. If both PDOs are activated (0x1A01 and 0x1A02) the value is likewise 128dec.

![618145](/tcplclib_tc2_dmx/1033/Images/gif/578420235__en-US__Web.gif)

DMX slave 1 receives 64 bytes of data on channel 1 of the first array (*DMX channels 1 - 64*)

DMX slave 2 receives 64 bytes of data on channel 1 of the second array (*DMX channels 65 - 128*)

The *Receive toggle* bit (index 0x6000:02) is evaluated and displayed in each case via the FB *bMonitorToggleBit* (Watchdog DMX Slave).
