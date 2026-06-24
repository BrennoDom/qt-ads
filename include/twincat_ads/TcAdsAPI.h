///////////////////////////////////////////////////////////////////////////////
// This is a part of the Beckhoff TwinCAT Software Development Kit.
// Copyright (C) Beckhoff Automation GmbH
// All rights reserved.
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Prototypes and Definitions for non C++ Applications
////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "TcAdsDef.h"

#define ADSAPIERR_NOERROR			0x0000

////////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
extern "C"
{
#endif

TCADSDLL_EXPORT
ads_i32 TCADSDLL_API AdsGetDllVersion( void );

TCADSDLL_EXPORT
ads_i32	TCADSDLL_API AdsPortOpen( void );

TCADSDLL_EXPORT
ads_i32	TCADSDLL_API AdsPortClose( void );

TCADSDLL_EXPORT
ads_i32	TCADSDLL_API AdsGetLocalAddress( AmsAddr*	pAddr );
 
TCADSDLL_EXPORT
ads_i32 TCADSDLL_API AdsSyncWriteReq(	AmsAddr*	pServerAddr,	// Ams address of ADS server
														ads_ui32	indexGroup,		//	index group in ADS server interface
														ads_ui32	indexOffset,            // index offset in ADS server interface
														ads_ui32	length,			// count of bytes to write
														void*		pData				// pointer to the client buffer
							);

TCADSDLL_EXPORT
ads_i32 TCADSDLL_API AdsSyncReadReq( AmsAddr*	pAddr,						// Ams address of ADS server
													ads_ui32		indexGroup,		//	index group in ADS server interface
													ads_ui32		indexOffset,	// index offset in ADS server interface
													ads_ui32		length,			// count of bytes to read
													void*			pData				// pointer to the client buffer
							);

TCADSDLL_EXPORT
ads_i32 TCADSDLL_API AdsSyncReadReqEx( AmsAddr*	pAddr,						// Ams address of ADS server
													ads_ui32		indexGroup,		//	index group in ADS server interface
													ads_ui32		indexOffset,	// index offset in ADS server interface
													ads_ui32		length,			// count of bytes to read
													void*			pData,			// pointer to the client buffer
													ads_ui32*	pcbReturn		// count of bytes read
							);

TCADSDLL_EXPORT
ads_i32 TCADSDLL_API AdsSyncReadWriteReq( AmsAddr* pAddr,					// Ams address of ADS server
															ads_ui32 indexGroup,			//	index group in ADS server interface
															ads_ui32 indexOffset,			// index offset in ADS server interface
															ads_ui32 cbReadLength,		// count of bytes to read
															void*		pReadData,						// pointer to the client buffer
															ads_ui32 cbWriteLength, 		// count of bytes to write
															void*		pWriteData						// pointer to the client buffer
							);											

TCADSDLL_EXPORT
ads_i32 TCADSDLL_API AdsSyncReadWriteReqEx( AmsAddr* pAddr,					// Ams address of ADS server
															ads_ui32		indexGroup,			//	index group in ADS server interface
															ads_ui32		indexOffset,			// index offset in ADS server interface
															ads_ui32		cbReadLength,		// count of bytes to read
															void*			pReadData,						// pointer to the client buffer
															ads_ui32		cbWriteLength, 		// count of bytes to write
															void*			pWriteData,						// pointer to the client buffer
															ads_ui32*	pcbReturn			// count of bytes read
							);											

TCADSDLL_EXPORT
ads_i32 TCADSDLL_API AdsSyncReadDeviceInfoReq( AmsAddr*		pAddr,	// Ams address of ADS server
															 char*			pDevName,// fixed length string (16 Byte)
															 AdsVersion*	pVersion	// client buffer to store server version
										 );

TCADSDLL_EXPORT
ads_i32 TCADSDLL_API AdsSyncWriteControlReq( AmsAddr*		pAddr,	   // Ams address of ADS server
															ads_ui16		adsState, // index group in ADS server interface
															ads_ui16		deviceState,// index offset in ADS server interface
															ads_ui32		length,	// count of bytes to write
															void*			pData		// pointer to the client buffer
									  );

TCADSDLL_EXPORT
ads_i32 TCADSDLL_API AdsSyncReadStateReq( AmsAddr*	pAddr,				// Ams address of ADS server
														  ads_ui16*	pAdsState,	// pointer to client buffer
														  ads_ui16*	pDeviceState// pointer to the client buffer
								  );							          


TCADSDLL_EXPORT
ads_i32 TCADSDLL_API AdsSyncAddDeviceNotificationReq(	AmsAddr*	pAddr, 	// Ams address of ADS server
																		ads_ui32 indexGroup, //	index group in ADS server interface
																		ads_ui32 indexOffset,//	index offset in ADS server interface
																		AdsNotificationAttrib* pNoteAttrib,	// attributes of notification request
																		PAdsNotificationFuncEx pNoteFunc,		// address of notification callback
																		ads_ui32 hUser,						// user handle
																		ads_ui32 *pNotification			// pointer to notification handle (return value)
													);
TCADSDLL_EXPORT
ads_i32 TCADSDLL_API AdsSyncDelDeviceNotificationReq(	AmsAddr*	pAddr,// Ams address of ADS server
									ads_ui32 hNotification // notification handle
													);

TCADSDLL_EXPORT
ads_i32 TCADSDLL_API AdsSyncSetTimeout(	ads_i32 nMs ); // Set timeout in ms


TCADSDLL_EXPORT
ads_i32 TCADSDLL_API AdsGetLastError( void );

/// register callback
TCADSDLL_EXPORT
ads_i32 TCADSDLL_API AdsAmsRegisterRouterNotification (PAmsRouterNotificationFuncEx pNoteFunc );

/// unregister callback
TCADSDLL_EXPORT
ads_i32 TCADSDLL_API AdsAmsUnRegisterRouterNotification ();


TCADSDLL_EXPORT
ads_i32  TCADSDLL_API AdsSyncGetTimeout(ads_i32 *pnMs ); // client buffer to store timeout

TCADSDLL_EXPORT
ads_i32 TCADSDLL_API AdsAmsPortEnabled(ads_bool *pbEnabled);


////////////////////////////////////////////////////////////////////////////////////////////////////
// new Ads functions for multithreading applications
TCADSDLL_EXPORT
ads_i32 TCADSDLL_API AdsPortOpenEx( );

TCADSDLL_EXPORT
ads_i32	TCADSDLL_API AdsPortCloseEx( ads_i32 port );

TCADSDLL_EXPORT
ads_i32	TCADSDLL_API AdsGetLocalAddressEx(ads_i32 port, AmsAddr*	pAddr );
 
TCADSDLL_EXPORT
ads_i32 TCADSDLL_API AdsSyncWriteReqEx( ads_i32	port,				// Ams port of ADS client
							AmsAddr*		pServerAddr,	// Ams address of ADS server
							ads_ui32		indexGroup,		//	index group in ADS server interface
							ads_ui32		indexOffset,	// index offset in ADS server interface
							ads_ui32		length,			// count of bytes to write
							void*			pData				// pointer to the client buffer
							 );

TCADSDLL_EXPORT
ads_i32 TCADSDLL_API AdsSyncReadReqEx2( ads_i32	port,				// Ams port of ADS client
							AmsAddr*		pServerAddr,	// Ams address of ADS server
							ads_ui32		indexGroup,		//	index group in ADS server interface
							ads_ui32		indexOffset,	// index offset in ADS server interface
							ads_ui32		length,			// count of bytes to read
							void*			pData,				// pointer to the client buffer
							ads_ui32*	pcbReturn		// count of bytes read
							);


TCADSDLL_EXPORT
ads_i32  TCADSDLL_API AdsSyncReadWriteReqEx2( ads_i32	port,		// Ams port of ADS client
							AmsAddr*		pServerAddr,	// Ams address of ADS server
							ads_ui32		indexGroup,		//	index group in ADS server interface
							ads_ui32		indexOffset,	// index offset in ADS server interfaceunsigned	short
							ads_ui32		cbReadLength,	// count of bytes to read
							void*			pReadData,		// pointer to the client buffer
							ads_ui32		cbWriteLength, // count of bytes to write
							void*			pWriteData,		// pointer to the client buffer
							ads_ui32*	pcbReturn		// count of bytes read
							);											

TCADSDLL_EXPORT
ads_i32  TCADSDLL_API AdsSyncReadDeviceInfoReqEx( ads_i32 port,		// Ams port of ADS client
										 AmsAddr*		pServerAddr,	// Ams address of ADS server
										 char*			pDevName,		// fixed length string (16 Byte)
										 AdsVersion*	pVersion			// client buffer to store server version
										 );

TCADSDLL_EXPORT
ads_i32  TCADSDLL_API AdsSyncWriteControlReqEx( ads_i32 port,			// Ams port of ADS client
										AmsAddr*			pServerAddr,	// Ams address of ADS server
										ads_ui16			adsState,		// index group in ADS server interfsace
										ads_ui16			deviceState,	// index offset in ADS server interface
										ads_ui32			length,			// count of bytes to write
										void*				pData				// pointer to the client buffer
										);

TCADSDLL_EXPORT
ads_i32  TCADSDLL_API AdsSyncReadStateReqEx( ads_i32 port,			// Ams port of ADS client
								  AmsAddr*			pServerAddr,	// Ams address of ADS server
								  ads_ui16*	pAdsState,		// pointer to client buffer
								  ads_ui16*	pDeviceState	// pointer to the client buffer
								  );							          


TCADSDLL_EXPORT
ads_i32  TCADSDLL_API AdsSyncAddDeviceNotificationReqEx(	ads_i32 port,				// Ams port of ADS client
													AmsAddr*			pServerAddr,					// Ams address of ADS ser
													ads_ui32			indexGroup,						//	index group in ADS server interface
													ads_ui32			indexOffset,					//	index offset in ADS server interface
													AdsNotificationAttrib* pNoteAttrib,			// attributes of notification request
													PAdsNotificationFuncEx pNoteFunc,			// address of notification callback
													ads_ui32			hUser,							// user handle
													ads_ui32*		pNotification					// pointer to notification handle (return value)
													);
TCADSDLL_EXPORT
ads_i32  TCADSDLL_API AdsSyncDelDeviceNotificationReqEx( ads_i32 port,							// Ams port of ADS client
													AmsAddr*			pServerAddr,					// Ams address of ADS ser
													ads_ui32			hNotification					// notification handle
													);

TCADSDLL_EXPORT
ads_i32  TCADSDLL_API AdsSyncSetTimeoutEx(ads_i32 port, // Ams port of ADS client
														ads_i32 nMs ); // Set timeout in ms

TCADSDLL_EXPORT
ads_i32  TCADSDLL_API AdsSyncGetTimeoutEx(ads_i32 port,   // Ams port of ADS client
														ads_i32 *pnMs ); // client buffer to store timeout

TCADSDLL_EXPORT
ads_i32 TCADSDLL_API AdsAmsPortEnabledEx(ads_i32 nPort, ads_bool *pbEnabled);

TCADSDLL_EXPORT
ads_i32 TCADSDLL_API AdsAmsRegisterRouterNotificationEx2(ads_i32 nPort, PAmsRouterNotificationFuncEx3 pNoteFunc, void* hUser);

TCADSDLL_EXPORT
ads_i32 TCADSDLL_API AdsAmsUnRegisterRouterNotificationEx2(ads_i32 nPort);

#ifdef __cplusplus
} // extern "C"
#endif
