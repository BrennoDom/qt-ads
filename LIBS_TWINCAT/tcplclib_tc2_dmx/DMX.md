# DMX

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# DMX

DMX is the standard protocol for controlling professional stage and effect lighting equipment, which is used, for example, for the dynamic lighting of showrooms and salesrooms as well as for exclusive plays of light and color in prestigious buildings, such as hotels and event centers. Color mixing and brightness values are transmitted to DMX devices that are static light sources, whilst moving sources of light additionally receive spatial coordinates. EtherCAT’s high data transfer rate enables light settings to be updated at a higher rate, with the result that changes of light and color are perceived by the eye as being more harmonious. The EL6851 can be used to control DMX devices with three axes, such as scanners, moving heads or spotlights. TwinCAT function blocks enable implementation of the RDM protocol (**R**emote **D**evice **M**anagement) for internal diagnostics and parameterization in DMX.

The DMX master transmits new settings to the slaves cyclically at 250 kBaud in order to generate dynamic lighting changes and plays of color. In the DMX protocol, a maximum of 32 slaves are allowed in one strand without repeaters. The 512 byte long frame in the DMX protocol is termed a ‘universe’. 512 channels are available in it, each of which represents a device setting with 8-bit resolution, i.e. in 256 steps, e.g. for dimming, color, focus etc. In the case of moving light sources, additional settings such as inclination, swiveling and speed (with 8-bit or 16-bit resolution) occupy additional channels, so that the 512 channels are only indirectly sufficient for 32 devices. Furthermore, if the universe is fully utilized a frame will require 22 ms for internal DMX circulation, which means a refresh rate of 44 Hz. Light changes at this frequency are perceived to be inharmonious. The transitions only appear to be harmonious from a frequency of >200 Hz. The circulation period can be shortened by reducing the amount of user data. The optimum has proven to be a utilization of 64 bytes (frequency >300 Hz), with which 64 channels are available per universe.

![12695920](/tcplclib_tc2_dmx/1033/Images/gif/55203851__en-US__Web.gif)

The integration of several universes in a controller becomes simple with the EL6851: EtherCAT can transfer large amounts of data quickly, the EtherCAT protocol is retained until inside the terminal and the terminal supports various mapping sizes (64 to 512 bytes). Hence, if several master terminals are connected, each as its own universe, the time offset in transmitting from the controller to the master can be reduced significantly.
