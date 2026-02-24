# Host Byte Order / Network Byte Order

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# Host Byte Order / Network Byte Order

The byte order is fixed in network protocols. This is called the Network Byte Order. The natural byte order in the TwinCAT system is called the Host Byte Order. In most cases, the required Network Byte Order corresponds to the Big Endian Format (MOTOROLA). However, the TwinCAT PLC system uses the Little Endian Format (Intel). So that the error-free exchange of data between the TwinCAT PLC system and a different platform can take place, the byte order in the application program must be converted accordingly.

Data that is to be transmitted via a network protocol from the TwinCAT system (host) to an external system can be converted to the network format using the following functions:

* [HOST\_TO\_BE16](ms-xhelp:///?Id=beckhoff-f6fc-4047-97bf-a66787d0d8d8)
* [HOST\_TO\_BE32](ms-xhelp:///?Id=beckhoff-706b-46e7-8747-879dc4157971)
* [HOST\_TO\_BE64](ms-xhelp:///?Id=beckhoff-3e6a-47f3-aadc-00e83a8d0b2b)
* [HOST\_TO\_BE64EX](ms-xhelp:///?Id=beckhoff-43ac-4948-a550-deb02c3ef4d1)
* [HOST\_TO\_BE128](ms-xhelp:///?Id=beckhoff-c4ad-4026-8310-169569227dca)

Conversely, the received network data (external system) can be converted to the host format (TwinCAT system) using the following functions:

* [BE16\_TO\_HOST](ms-xhelp:///?Id=beckhoff-530b-4690-affe-d6162a0bfb24)
* [BE32\_TO\_HOST](ms-xhelp:///?Id=beckhoff-43e6-4fe6-b8ff-a557e6fb42e7)
* [BE64\_TO\_HOST](ms-xhelp:///?Id=beckhoff-cb16-4469-adc1-2ff1bc3d0b4d)
* [BE64\_TO\_HOSTEX](ms-xhelp:///?Id=beckhoff-5ea2-41be-9273-2c55a25f0fca)
* [BE128\_TO\_HOST](ms-xhelp:///?Id=beckhoff-3863-469a-ae0c-5161412fd06a)
