# Communication Monitor

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Appendix](ms-xhelp:///?Id=beckhoff-799a-4543-a757-72ecd85fb150)
3. [Commissioning and diagnosis](ms-xhelp:///?Id=beckhoff-0748-4e01-bcff-c71c095ae5b7)
4. Communication Monitor

# Communication Monitor

The TwinCAT 3 Extension *TwinCAT Communication Monitor* contains a diagnostic window in which the DALI commands sent and the DALI events of the Tc3\_DALI library are displayed.

## Installation with TwinCAT XAE (TCXaeShell)

If you use the TwinCAT XAE Shell, perform the following steps to install the *TwinCAT Communication Monitor*:

* If you are using a 32-bit operating system, create the folder *TwinCAT Communication Monitor* under the following path:  
  *C:\Program Files\Beckhoff\TcXaeShell\Common7\IDE\Extensions\Beckhoff Automation GmbH.*
* For a 64-bit operating system, the folder must be created under: *C:\Program Files (x86)\Beckhoff\TcXaeShell\Common7\IDE\Extensions\Beckhoff Automation GmbH*.
* Download the *TwinCAT Communication Monitor* from the following link and save the \*.vsix file that it contains locally:  
  [TcCommunicationMonitorVSIX\_V1.1.0.0.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc3_dali/Resources/zip/9260769675.zip)
* Rename the \*.vsix file to a \*.zip file.
* Copy the contents of the previously renamed file to the newly created folder.
* Check that the following security settings are set correctly for all files:
* ![8031464](/tcplclib_tc3_dali/1033/Images/png/10946124555__Web.png)
* Restart TwinCAT XAE (TcXaeShell).

## Installation with Visual Studio

Download the TwinCAT Communication Monitor from the following link and save the \*.vsix file that it contains locally:

[TcCommunicationMonitorVSIX\_V1.1.0.0.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc3_dali/Resources/zip/9260769675.zip)

The *TwinCAT Communication Monitor* is installed by double-clicking the *TcCommunicationMonitorVSIX\_V1.1.0.0.vsix* file.

## Start the DALI TwinCAT Communication Monitor

After the *TwinCAT Communication Monitor* has been installed, the *DALI Monitor* entry is available under the *TwinCAT* menu item.

![5174319](/tcplclib_tc3_dali/1033/Images/png/9007205231856907__Web.png)

After starting the *DALI Monitor*, select the instance of the desired communication function block ([FB\_KL6811Communication](ms-xhelp:///?Id=beckhoff-6f44-4cb3-aafe-45421409fcd8) or [FB\_KL6821Communication](ms-xhelp:///?Id=beckhoff-37ef-403f-bac1-40d77b04945d)). All telegrams sent by the respective instance are then displayed in the *DALI Monitor*.

![46568871](/tcplclib_tc3_dali/1033/Images/png/9007205231859467__Web.png)

In addition to the timestamp, address, DALI command and command priority, the instance path is also displayed. This indicates from where within the PLC program the DALI command was sent.

To display the telegrams, it is not necessary that the corresponding TwinCAT project has been loaded. Since the data exchange between the PLC program and the *DALI Monitor* was realized via ADS, it is sufficient if the TwinCAT router was correctly configured.

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
