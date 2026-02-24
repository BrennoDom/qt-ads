# PLC Library Overview

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. PLC Library Overview

# PLC Library Overview

Below there is an overview of the TF5050 TC3 MC Camming PLC Library.

## **Cam** Plates

| Function Block | Description |
| --- | --- |
| [MC\_CamTableSelect](ms-xhelp:///?Id=beckhoff-1df0-48d7-b6e5-d6dbff062d85) | Specifies a table and loads it into the NC. |
| [MC\_CamOut](ms-xhelp:///?Id=beckhoff-6d72-4acc-8c33-b64163fb43b6) | Deactivates a master-slave coupling. |
| [MC\_CamIn](ms-xhelp:///?Id=beckhoff-9d6c-4e6e-b012-23819a633f2e) | Activates master-slave coupling with a certain cam plate. |
| [MC\_CamScaling](ms-xhelp:///?Id=beckhoff-4b9c-4af2-8419-71548633a33c) | Scales a cam plate coupling. |

## **Multi Cam Plates**

| Function Block | Description |
| --- | --- |
| [MC\_CamIn\_V2](ms-xhelp:///?Id=beckhoff-b46a-4343-a1d4-b2c35fe9a410) | Several cam plates can be superimposed. |
| [MC\_CamAdd](ms-xhelp:///?Id=beckhoff-6fca-4811-bc4f-a4fc92d79f0f) | Adds a cam plate to a multi cam. |
| [MC\_CamExchange](ms-xhelp:///?Id=beckhoff-9234-4440-a20f-48dd96cece08) | Exchanges a cam in a multi cam. |
| [MC\_CamRemove](ms-xhelp:///?Id=beckhoff-0c2b-4e53-8b0a-6e5fd4702091) | Removes a cam from a multi cam environment. |
| [MC\_CamScaling\_V2](ms-xhelp:///?Id=beckhoff-9347-445d-91ef-73f53af948b2) | Scales a cam plate coupling. |

## **Motion Functions**

| Function Block | Description |
| --- | --- |
| [MC\_ReadMotionFunction](ms-xhelp:///?Id=beckhoff-e45d-44d5-9d5f-b31e740a1792) | Read the data of a motion function. |
| [MC\_ReadMotionFunctionPoint](ms-xhelp:///?Id=beckhoff-5a97-424d-aea0-3b99a361fbfb) | Read the data of a motion function interpolation point. |
| [MC\_WriteMotionFunction](ms-xhelp:///?Id=beckhoff-f4cf-455a-9065-f89bcc2425b4) | Write the data of a motion function into the NC. |
| [MC\_WriteMotionFunctionPoint](ms-xhelp:///?Id=beckhoff-7a01-4003-99d3-69e74c0ccf29) | Write the data of a motion function interpolation point. |
| [MC\_SetCamOnlineChangeMode](ms-xhelp:///?Id=beckhoff-d38a-4116-a7ad-dd65a8c72aaf) | Specifies the mode for write access to cam plate data. |
| [MC\_ReadMotionFunctionValues](ms-xhelp:///?Id=beckhoff-c700-4d39-8ab1-f177c91e11de) | Reads the interpolated data of a motion function in form of a table. |

## **Status**

| Function Block | Description |
| --- | --- |
| [MC\_ReadCamTableSlaveDynamics](ms-xhelp:///?Id=beckhoff-1c8e-4598-afe8-9a6bf2af2677) | Determines the slave dynamics at a certain point of a cam plate table. |
| [MC\_CamInfo](ms-xhelp:///?Id=beckhoff-a6a4-4e81-a1cb-507ce7b2b5c1) | Obtains data relating to the current state and current parameterization of a cam plate coupling. |
| [MC\_CamInfo\_V2](ms-xhelp:///?Id=beckhoff-bd35-4bb7-a1d9-84d9d9620b55) | Obtains data relating to the current state and current parameterization of a cam plate coupling. |
| [MC\_ReadCamTableCharacteristics](ms-xhelp:///?Id=beckhoff-4f88-45bd-9c22-bd1cfec30fd8) | Calculates and reads the characteristic parameters of a motion function. |
| [MC\_ReadCamTableMasterPosition](ms-xhelp:///?Id=beckhoff-d1e3-4bbb-a352-98a9c418a54a) | Calculates a master position for a given slave position. |

## Data Types

| Data Type | Description |
| --- | --- |
| [MC\_CAM\_ID](ms-xhelp:///?Id=beckhoff-db88-4e03-9507-2b4b8a069dc4) | Type definition for the table ID. |
| [MC\_CAM\_REF](ms-xhelp:///?Id=beckhoff-1365-4325-92ea-77764879dfc0) | Describes the data memory of a cam plate in a further PLC variable. |
| [MC\_CamActivationMode](ms-xhelp:///?Id=beckhoff-489c-4d73-9497-514dfe742957) | Specifies timing and type of change for a cam plate. |
| [MC\_CamScalingMode](ms-xhelp:///?Id=beckhoff-ec0d-401b-8d43-f6039df26ed1) | Contains type and scope of the scaling of a cam plate coupling, used by the function block MC\_CamScaling. |
| [MC\_CamInfoData](ms-xhelp:///?Id=beckhoff-f37e-4737-b6c4-07899b1bbe18) | Contains data on the current state of a cam plate coupling. |
| [MC\_InterpolationType](ms-xhelp:///?Id=beckhoff-cf32-4289-8aa5-acbf2b9c9914) | Interpolation mode for position tables. |
| [MC\_MotionFunctionPoint](ms-xhelp:///?Id=beckhoff-c619-429a-8502-a3ccba350b60) | Describes an interpolation point of a motion function. |
| [MC\_MotionFunctionPoint\_ID](ms-xhelp:///?Id=beckhoff-b237-49b4-ad56-4040271b6939) | Type definition for the point ID of the points of a motion function. |
| [MC\_MotionFunctionType](ms-xhelp:///?Id=beckhoff-1a9a-4aed-bd7e-de7471b50d0b) | Type definition for motion functions. |
| [MC\_MotionPointType](ms-xhelp:///?Id=beckhoff-49fd-4546-9c4b-ebc7b288d451) | Type definition for a table point. |
| [MC\_TableCharacValues](ms-xhelp:///?Id=beckhoff-7103-4726-99b3-7d60ecd94d04) | Type definition for the characteristic parameters of a motion function. |
| [MC\_TableErrorCodes](ms-xhelp:///?Id=beckhoff-2de7-4d77-9d1a-50c0ab9dea26) | Type definition of table error codes. |
| [MC\_TableType](ms-xhelp:///?Id=beckhoff-ab33-42a6-ae57-69a7ddde9748) | Type definition of table types. |
| [MC\_ValueSelectType](ms-xhelp:///?Id=beckhoff-6a4e-43db-990d-3d642d13a5c3) | Type definition for access to value tables with the function block MC\_ReadMotionFunctionValues. |
| [MC\_StartMode](ms-xhelp:///?Id=beckhoff-bb4a-4816-84ef-5a1abd389b8e) | Defines whether a cam plate is interpreted absolute to the origin of the axis coordinate system or relative to the coupling position. |
| [ST\_CamInOptions](ms-xhelp:///?Id=beckhoff-bdbf-4473-ad4e-c070929e8b61) | Data of type ST\_CamInOptions can optionally be transferred to the function block MC\_CamIn. |
| [CamMasterData](ms-xhelp:///?Id=beckhoff-9c3a-45c6-96bc-e3fdb70b1c3d) | Data of type CamMasterData are optionally transferred by function block MC\_ReadCamTableMasterPosition. |
| [MC\_CamOperationMode](ms-xhelp:///?Id=beckhoff-2312-4d6a-9c65-8194b8b2e23a) | Used for managing couplings with superimposed cam plates with the function block MC\_CamIn\_V2. |
| [ST\_CamScalingData](ms-xhelp:///?Id=beckhoff-2296-4707-bc2f-6b46959e6d52) | Contains information for scaling a cam plate, used with the function block MC\_CamIn\_V2. |

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
