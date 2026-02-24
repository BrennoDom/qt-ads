# Basic interface function blocks

## Library
tcplclib_tc2_eib

## Category
Motion Control

# Basic interface function blocks

| Description | \_Rec | \_Send | | | | |
| --- | --- | --- | --- | --- | --- | --- |
| \_Send | First Cycle | Delta, min. Send Time | Polling | Auto/manual |
| EIB\_BIT | [yes](ms-xhelp:///?Id=beckhoff-e0d2-465e-893a-befc7f575db9) | [yes](ms-xhelp:///?Id=beckhoff-69e1-4893-8975-1ddfe5cd0175) | no | yes, 200 msec | no | Auto |
| EIB\_BIT\_MANUAL | no | [yes](ms-xhelp:///?Id=beckhoff-da68-4899-aedb-14619951ecd2) | no | no | no | Manual |
| EIB\_BIT\_CONTROL | [yes](ms-xhelp:///?Id=beckhoff-941d-4f01-ae6a-041da7f8058b) | [yes](ms-xhelp:///?Id=beckhoff-5a14-40ac-a579-44195b4191a4) | no | yes, 200 msec | no | Auto |
| EIB\_3BIT\_CONTROL | [yes](ms-xhelp:///?Id=beckhoff-db5f-41e3-bf1a-1b3a7c376699) | [yes](ms-xhelp:///?Id=beckhoff-5c94-4615-a8cc-0496ec87fbc7) | no | yes, 200 msec | no | Auto |
| EIB\_8BIT\_SIGN | [yes](ms-xhelp:///?Id=beckhoff-deef-49ab-9729-a30453259374) | [yes](ms-xhelp:///?Id=beckhoff-e786-4d93-8439-7ae8c7cb93c5) | no | yes, 1 sec | no | Auto |
| EIB\_8BIT\_SIGN\_EX | no | [yes](ms-xhelp:///?Id=beckhoff-e7a4-44c6-a7e7-bd81aeb9bf3b) | yes | yes, 200 msec | yes | Auto/manual |
| EIB\_8BIT\_UNSIGN | [yes](ms-xhelp:///?Id=beckhoff-9b52-4b87-af1a-4148dbab6a44) | [yes](ms-xhelp:///?Id=beckhoff-8793-4e7a-afdd-6eabf256722c) | no | yes, 1 sec | no | Auto |
| EIB\_8BIT\_UNSIGN\_EX | no | [yes](ms-xhelp:///?Id=beckhoff-bda1-4a81-a276-7eb9feaf5245) | yes | yes, 200 msec | yes | Auto/manual |
| EIB\_2OCTETE\_SIGN | [yes](ms-xhelp:///?Id=beckhoff-672d-42c8-b39b-2f62c2a89c97) | [yes](ms-xhelp:///?Id=beckhoff-0b30-4765-96d2-02397ccecfcc) | no | yes, 1 sec | no | Auto |
| EIB\_2OCTETE\_UNSIGN | [yes](ms-xhelp:///?Id=beckhoff-494d-4795-b5c9-78e7d75b22be) | [yes](ms-xhelp:///?Id=beckhoff-63cf-4023-a598-5794f8f9e27b) | no | yes, 1 sec | no | Auto |
| EIB\_2OCTETE\_FLOAT | [yes](ms-xhelp:///?Id=beckhoff-5a28-4112-9fb1-3b8b880209f4) | [yes](ms-xhelp:///?Id=beckhoff-881a-4a5d-9fff-0161c8793084) | no | yes, 1 sec | no | Auto |
| EIB\_TIME | [yes](ms-xhelp:///?Id=beckhoff-32fc-4191-bd1c-bd39943233f0) | [yes](ms-xhelp:///?Id=beckhoff-6644-4775-9e88-0dcd46fb190e) | yes | no | yes, 5 min | Auto |
| EIB\_DATE | [yes](ms-xhelp:///?Id=beckhoff-eb33-4bdd-bdd2-c55bbe0f2c3f) | [yes](ms-xhelp:///?Id=beckhoff-4a95-47cc-89f6-789cfe983bfa) | yes | no | yes, 5 min | Auto |
| EIB\_4OCTETE\_SIGN | [yes](ms-xhelp:///?Id=beckhoff-6326-40ac-8a56-2637a5f81851) | [yes](ms-xhelp:///?Id=beckhoff-e986-419d-8c91-47992ead3135) | no | yes, 1 sec | no | Auto |
| EIB\_4OCTETE\_UNSIGN | [yes](ms-xhelp:///?Id=beckhoff-165b-4666-b36d-d7fa59a339bd) | [yes](ms-xhelp:///?Id=beckhoff-ff14-48eb-9825-cc3f730c07bb) | no | yes, 1 sec | no | Auto |
| EIB\_4OCTETE\_FLOAT | [yes](ms-xhelp:///?Id=beckhoff-98a1-4908-9b17-b60986d019e9) | [yes](ms-xhelp:///?Id=beckhoff-29b8-4256-b233-c63a6678e799) | no | yes, 1 sec | no | Auto |
| EIB\_READ | no | [yes](ms-xhelp:///?Id=beckhoff-4786-45a1-a0ac-8c8b9694df83) | no | no | no | Manual |
| EIB\_ALL\_DATA\_TYPES | [yes](ms-xhelp:///?Id=beckhoff-b43e-4a50-9fdd-a2ae09fdc168) | [yes](ms-xhelp:///?Id=beckhoff-72e9-447a-a778-667967893caa) | no | yes, variable | yes, variable | Auto/manual |

**\_Rec:** yes - receiving is supported, no - receiving is not supported

**\_Send:** yes - sending is supported, no - sending is not supported

**First Cycle:** An EIB telegram is sent when the block is first called

**Delta, min. Send Time:** An EIB telegram is only sent in the event of a change in data. The parameter "min. send time" is used to activate a "send filter". It does not extend the response time for the first relative change in input, but is active for subsequent changes. The "min. Send Time" (send delay time) describes the minimum interval required between sending of two telegrams. The "min. Send Time" reduces bus communication and ensures that send instructions from other blocks can also transmit their EIB telegrams.

![42887128](/tcplclib_tc2_eib/1033/Images/gif/187833739__en-US__Web.gif)

**Polling:** The data are automatically sent at the specified interval, even if the data did not change

**Auto/Manual:** Auto - data are automatically sent when the block is called; Manual - data are only sent the block requests this
