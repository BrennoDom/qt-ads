///////////////////////////////////////////////////////////////////////////////
// This is a part of the Beckhoff TwinCAT Software Development Kit.
// Copyright (C) Beckhoff Automation GmbH
// All rights reserved.
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Prototypes and Definitions for ADS communication
////////////////////////////////////////////////////////////////////////////////
#pragma once

#ifdef POSIX
	#include <stdint.h>

	typedef int64_t			ads_i64;
	typedef int					ads_i32;
	typedef unsigned int		ads_ui32;
#else
	typedef __int64			ads_i64;
	typedef long				ads_i32;
	typedef unsigned long	ads_ui32;
#endif

typedef char				ads_i8;
typedef unsigned char	ads_ui8;
typedef unsigned short	ads_ui16;
typedef int					ads_bool;

#ifndef POSIX
	#ifndef TCADSDLL_EXPORT
	#define TCADSDLL_EXPORT	__declspec( dllimport )
	#endif
	#ifndef TCADSDLL_API
	#define TCADSDLL_API		__stdcall
	#endif
#else
	#ifndef TCADSDLL_EXPORT
	#define TCADSDLL_EXPORT
	#endif
	#ifndef TCADSDLL_API
	#define TCADSDLL_API
	#endif
#endif //!POSIX

#ifndef HAS_ADS_H

#ifndef	ANYSIZE_ARRAY
#define	ANYSIZE_ARRAY					1
#endif

#define	ADS_FIXEDNAMESIZE				16

#define	AMSPORT_ROUTER             1
#define	AMSPORT_R0_TCOMSERVER      10
#define	AMSPORT_LOGGER             100
#define	AMSPORT_R0_RTIME           200
#define	AMSPORT_R0_TRACE           (AMSPORT_R0_RTIME+90)
#define	AMSPORT_R0_IO              300
#define	AMSPORT_R0_SPS             400
#define	AMSPORT_R0_NC              500
#define	AMSPORT_R0_ISG             550
#define	AMSPORT_R0_PCS             600
#define	AMSPORT_R0_PLC             801
#define	AMSPORT_R0_PLC_RTS1        801
#define	AMSPORT_R0_PLC_RTS2        811
#define	AMSPORT_R0_PLC_RTS3        821
#define	AMSPORT_R0_PLC_RTS4        831
#define	AMSPORT_R0_RTS             850

////////////////////////////////////////////////////////////////////////////////
// ADS reserved index groups
#define ADSIGRP_SYMTAB						0xF000
#define ADSIGRP_SYMNAME						0xF001
#define ADSIGRP_SYMVAL						0xF002

#define ADSIGRP_SYM_HNDBYNAME				0xF003
#define ADSIGRP_SYM_VALBYNAME				0xF004
#define ADSIGRP_SYM_VALBYHND				0xF005
#define ADSIGRP_SYM_RELEASEHND			0xF006
#define ADSIGRP_SYM_INFOBYNAME			0xF007
#define ADSIGRP_SYM_VERSION				0xF008
#define ADSIGRP_SYM_INFOBYNAMEEX			0xF009

#define ADSIGRP_SYM_DOWNLOAD				0xF00A
#define ADSIGRP_SYM_UPLOAD					0xF00B
#define ADSIGRP_SYM_UPLOADINFO			0xF00C

#define ADSIGRP_SYMNOTE						0xF010	// notification of named handle

#define ADSIGRP_IOIMAGE_RWIB				0xF020		// read/write input byte(s)
#define ADSIGRP_IOIMAGE_RWIX				0xF021		// read/write input bit
#define ADSIGRP_IOIMAGE_RWOB				0xF030		// read/write output byte(s)
#define ADSIGRP_IOIMAGE_RWOX				0xF031		// read/write output bit
#define ADSIGRP_IOIMAGE_CLEARI			0xF040		// write inputs to null
#define ADSIGRP_IOIMAGE_CLEARO			0xF050		// write outputs to null

#define ADSIGRP_DEVICE_DATA				0xF100		// state, name, etc...
#define ADSIOFFS_DEVDATA_ADSSTATE		0x0000		// ads state of device
#define ADSIOFFS_DEVDATA_DEVSTATE		0x0002		// device state

// ADS Error codes
#define	ERR_ADSERRS					0x0700

////////////////////////////////////////////////////////////////////////////////
// ADS error codes
#define ADSERR_NOERR							0x00
//
#define ADSERR_DEVICE_ERROR				(0x00+ERR_ADSERRS) // Error class < device error >
#define ADSERR_DEVICE_SRVNOTSUPP			(0x01+ERR_ADSERRS) // Service is not supported by server
#define ADSERR_DEVICE_INVALIDGRP 		(0x02+ERR_ADSERRS) // invalid indexGroup
#define ADSERR_DEVICE_INVALIDOFFSET		(0x03+ERR_ADSERRS) // invalid indexOffset
#define ADSERR_DEVICE_INVALIDACCESS		(0x04+ERR_ADSERRS) // reading/writing not permitted
#define ADSERR_DEVICE_INVALIDSIZE		(0x05+ERR_ADSERRS) // parameter size not correct
#define ADSERR_DEVICE_INVALIDDATA		(0x06+ERR_ADSERRS) // invalid parameter value(s)
#define ADSERR_DEVICE_NOTREADY			(0x07+ERR_ADSERRS) // device is not in a ready state
#define ADSERR_DEVICE_BUSY					(0x08+ERR_ADSERRS) // device is busy
#define ADSERR_DEVICE_INVALIDCONTEXT	(0x09+ERR_ADSERRS) // invalid context (must be InWindows)
#define ADSERR_DEVICE_NOMEMORY			(0x0A+ERR_ADSERRS) // out of memory
#define ADSERR_DEVICE_INVALIDPARM		(0x0B+ERR_ADSERRS) // invalid parameter value(s)
#define ADSERR_DEVICE_NOTFOUND			(0x0C+ERR_ADSERRS) // not found (files, ...)
#define ADSERR_DEVICE_SYNTAX				(0x0D+ERR_ADSERRS) // syntax error in comand or file
#define ADSERR_DEVICE_INCOMPATIBLE		(0x0E+ERR_ADSERRS) // objects do not match
#define ADSERR_DEVICE_EXISTS				(0x0F+ERR_ADSERRS) // object already exists
#define ADSERR_DEVICE_SYMBOLNOTFOUND	(0x10+ERR_ADSERRS) // symbol not found
#define ADSERR_DEVICE_SYMBOLVERSIONINVALID	(0x11+ERR_ADSERRS) // symbol version invalid
#define ADSERR_DEVICE_INVALIDSTATE		(0x12+ERR_ADSERRS) // server is in invalid state
#define ADSERR_DEVICE_TRANSMODENOTSUPP	(0x13+ERR_ADSERRS) // AdsTransMode not supported
#define ADSERR_DEVICE_NOTIFYHNDINVALID	(0x14+ERR_ADSERRS) // Notification handle is invalid
#define ADSERR_DEVICE_CLIENTUNKNOWN		(0x15+ERR_ADSERRS) // Notification client not registered	
#define ADSERR_DEVICE_NOMOREHDLS			(0x16+ERR_ADSERRS) // no more notification handles	
#define ADSERR_DEVICE_INVALIDWATCHSIZE	(0x17+ERR_ADSERRS) // size for watch to big	
#define ADSERR_DEVICE_NOTINIT				(0x18+ERR_ADSERRS) // device not initialized	
#define ADSERR_DEVICE_TIMEOUT				(0x19+ERR_ADSERRS) // device has a timeout
#define ADSERR_DEVICE_NOINTERFACE		(0x1A+ERR_ADSERRS) // query interface failed
#define ADSERR_DEVICE_INVALIDINTERFACE	(0x1B+ERR_ADSERRS) // wrong interface required
#define ADSERR_DEVICE_INVALIDCLSID		(0x1C+ERR_ADSERRS) // class ID is invalid
#define ADSERR_DEVICE_INVALIDOBJID		(0x1D+ERR_ADSERRS) // object ID is invalid
#define ADSERR_DEVICE_PENDING				(0x1E+ERR_ADSERRS) // request is pending
#define ADSERR_DEVICE_ABORTED				(0x1F+ERR_ADSERRS) // request is aborted
#define ADSERR_DEVICE_WARNING				(0x20+ERR_ADSERRS) // signal warning
#define ADSERR_DEVICE_INVALIDARRAYIDX	(0x21+ERR_ADSERRS) // invalid array index
//
#define ADSERR_CLIENT_ERROR				(0x40+ERR_ADSERRS) // Error class < client error >
#define ADSERR_CLIENT_INVALIDPARM		(0x41+ERR_ADSERRS) // invalid parameter at service call
#define ADSERR_CLIENT_LISTEMPTY			(0x42+ERR_ADSERRS) // polling list	is empty
#define ADSERR_CLIENT_VARUSED				(0x43+ERR_ADSERRS) // var connection already in use
#define ADSERR_CLIENT_DUPLINVOKEID		(0x44+ERR_ADSERRS) // invoke id in use
#define ADSERR_CLIENT_SYNCTIMEOUT		(0x45+ERR_ADSERRS) // timeout elapsed
#define ADSERR_CLIENT_W32ERROR			(0x46+ERR_ADSERRS) // error in win32 subsystem
#define ADSERR_CLIENT_TIMEOUTINVALID	(0x47+ERR_ADSERRS) // ?
#define ADSERR_CLIENT_PORTNOTOPEN		(0x48+ERR_ADSERRS) // ads dll
#define ADSERR_CLIENT_NOAMSADDR			(0x49+ERR_ADSERRS) // ads dll 
#define ADSERR_CLIENT_SYNCINTERNAL		(0x50+ERR_ADSERRS) // internal error in ads sync 
#define ADSERR_CLIENT_ADDHASH				(0x51+ERR_ADSERRS) // hash table overflow 
#define ADSERR_CLIENT_REMOVEHASH			(0x52+ERR_ADSERRS) // key not found in hash table 
#define ADSERR_CLIENT_NOMORESYM			(0x53+ERR_ADSERRS) // no more symbols in cache 
#define ADSERR_CLIENT_SYNCRESINVALID	(0x54+ERR_ADSERRS) // invalid response received 
#define ADSERR_CLIENT_SYNCPORTLOCKED	(0x55+ERR_ADSERRS) // sync port is locked 


#pragma	pack( push, 1)
typedef struct AmsNetId_
{
	ads_ui8 b[6];

} AmsNetId, *PAmsNetId;

typedef struct
{
	AmsNetId	netId;
	ads_ui16 port;
} AmsAddr, *PAmsAddr;

typedef	struct 
{
	ads_ui8		version;
	ads_ui8		revision;
	ads_ui16		build;
} AdsVersion;

typedef	AdsVersion*	PAdsVersion;

////////////////////////////////////////////////////////////////////////////////
typedef enum nAdsTransMode
{
	ADSTRANS_NOTRANS		=0,
	ADSTRANS_CLIENTCYCLE	=1,
	ADSTRANS_CLIENT1REQ	=2,
	ADSTRANS_SERVERCYCLE	=3,
	ADSTRANS_SERVERONCHA	=4
}ADSTRANSMODE;

typedef enum nAdsState
{
	ADSSTATE_INVALID			=0,
	ADSSTATE_IDLE				=1,
	ADSSTATE_RESET				=2,
	ADSSTATE_INIT				=3,
	ADSSTATE_START				=4,
	ADSSTATE_RUN				=5,
	ADSSTATE_STOP				=6,
	ADSSTATE_SAVECFG			=7,
	ADSSTATE_LOADCFG			=8,
	ADSSTATE_POWERFAILURE	=9,
	ADSSTATE_POWERGOOD		=10,
	ADSSTATE_ERROR				=11,
	ADSSTATE_SHUTDOWN			=12,
	ADSSTATE_SUSPEND			=13,
	ADSSTATE_RESUME			=14,
	ADSSTATE_CONFIG		   =15,	// system is in config mode
	ADSSTATE_RECONFIG		   =16,	// system should restart in config mode
	ADSSTATE_MAXSTATES
} ADSSTATE;

typedef struct
{
	ads_ui32	cbLength;
	ADSTRANSMODE	nTransMode;
	ads_ui32	nMaxDelay;
	union
	{
		ads_ui32		nCycleTime;
		ads_ui32		dwChangeFilter;
	};
} AdsNotificationAttrib, *PAdsNotificationAttrib;

////////////////////////////////////////////////////////////////////////////////
typedef struct
{
	ads_ui32	hNotification;
	ads_i64	nTimeStamp;
	ads_ui32	cbSampleSize;
	unsigned	char	data[ANYSIZE_ARRAY];
} AdsNotificationHeader, *PAdsNotificationHeader;

////////////////////////////////////////////////////////////////////////////////

#define	ADSNOTIFICATION_PDATA( pAdsNotificationHeader )	\
	(	(ads_ui8*)	(((PAdsNotificationHeader)pAdsNotificationHeader->data )


////////////////////////////////////////////////////////////////////////////////
#define	ADSSYMBOLFLAG_PERSISTENT		0x00000001
#define	ADSSYMBOLFLAG_BITVALUE			0x00000002

typedef struct
{
	ads_ui32		entryLength;	// length of complete symbol entry
	ads_ui32		iGroup;			// indexGroup of symbol: input, output etc.
	ads_ui32		iOffs;			// indexOffset of symbol
	ads_ui32		size;				// size of symbol ( in bytes, 0 = bit )
	ads_ui32		dataType;		// adsDataType of symbol
	ads_ui32		flags;			// see above
	ads_ui16		nameLength;		// length of symbol name (excl. \0)
	ads_ui16		typeLength;		// length of type name (excl. \0)
	ads_ui16		commentLength;	// length of comment (excl. \0)
	// ADS_INT8		name[];			// name of symbol with terminating \0
	// ADS_INT8		type[];			// type name of symbol with terminating \0
	// ADS_INT8		comment[];		// comment of symbol with terminating \0
} AdsSymbolEntry, *PAdsSymbolEntry, **PPAdsSymbolEntry;


#define	PADSSYMBOLNAME(p)			((char*)(((PAdsSymbolEntry)p)+1))
#define	PADSSYMBOLTYPE(p)			(((char*)(((PAdsSymbolEntry)p)+1))+((PAdsSymbolEntry)p)->nameLength+1)
#define	PADSSYMBOLCOMMENT(p)		(((char*)(((PAdsSymbolEntry)p)+1))+((PAdsSymbolEntry)p)->nameLength+1+((PAdsSymbolEntry)p)->typeLength+1)

#define	PADSNEXTSYMBOLENTRY(pEntry)	(*((ads_ui32*)(((char*)pEntry)+((PAdsSymbolEntry)pEntry)->entryLength)) \
						? ((PAdsSymbolEntry)(((char*)pEntry)+((PAdsSymbolEntry)pEntry)->entryLength)): NULL)



////////////////////////////////////////////////////////////////////////////////
#define	ADSDATATYPEFLAG_DATATYPE		0x00000001
#define	ADSDATATYPEFLAG_DATAITEM		0x00000002

#define	ADSDATATYPE_VERSION_NEWEST		0x00000001

typedef struct
{
	  ads_ui32		lBound;		//
	  ads_ui32		elements;	//
} AdsDatatypeArrayInfo, *PAdsDatatypeArrayInfo;

typedef struct
{
	ads_ui32		entryLength;	// length of complete datatype entry
	ads_ui32		version;			// version of datatype structure
	ads_ui32		hashValue;		// hashValue of datatype to compare datatypes
	ads_ui32		typeHashValue;	// hashValue of base type
	ads_ui32		size;				// size of datatype ( in bytes )
	ads_ui32		offs;				// offs of dataitem in parent datatype ( in bytes )
	ads_ui32		dataType;		// adsDataType of symbol (if alias)
	ads_ui32		flags;			//
	ads_ui16		nameLength;		// length of datatype name (excl. \0)
	ads_ui16		typeLength;		// length of dataitem type name (excl. \0)
	ads_ui16		commentLength;	// length of comment (excl. \0)
	ads_ui16		arrayDim;		//
	ads_ui16		subItems;		//
	// ADS_INT8		name[];			// name of datatype with terminating \0
	// ADS_INT8		type[];			// type name of dataitem with terminating \0
	// ADS_INT8		comment[];		// comment of datatype with terminating \0
	// AdsDatatypeArrayInfo	array[];		// 
	// AdsDatatypeEntry		subItems[];	// 
} AdsDatatypeEntry, *PAdsDatatypeEntry, **PPAdsDatatypeEntry;

#define	PADSDATATYPENAME(p)			((PCHAR)(((PAdsDatatypeEntry)p)+1))
#define	PADSDATATYPETYPE(p)			(((PCHAR)(((PAdsDatatypeEntry)p)+1))+((PAdsDatatypeEntry)p)->nameLength+1)
#define	PADSDATATYPECOMMENT(p)		(((PCHAR)(((PAdsDatatypeEntry)p)+1))+((PAdsDatatypeEntry)p)->nameLength+1+((PAdsDatatypeEntry)p)->typeLength+1)
#define	PADSDATATYPEARRAYINFO(p)	(PAdsDatatypeArrayInfo)(((PCHAR)(((PAdsDatatypeEntry)p)+1))+((PAdsDatatypeEntry)p)->nameLength+1+((PAdsDatatypeEntry)p)->typeLength+1+((PAdsDatatypeEntry)p)->commentLength+1)

__inline PAdsDatatypeEntry AdsDatatypeStructItem(PAdsDatatypeEntry p, ads_ui16 iItem)
{
	ads_ui16 i;
	PAdsDatatypeEntry	pItem;
	if ( iItem >= p->subItems )
		return NULL;
	pItem = (PAdsDatatypeEntry)(((ads_ui8*)(p+1))+p->nameLength+p->typeLength+p->commentLength+3+p->arrayDim*sizeof(AdsDatatypeArrayInfo));
	for ( i=0; i < iItem; i++ )
		pItem = (PAdsDatatypeEntry)(((ads_ui8*)pItem)+pItem->entryLength);
	return pItem;
}

////////////////////////////////////////////////////////////////////////////////
typedef struct
{
	ads_ui32	nSymbols;
	ads_ui32	nSymSize;
} AdsSymbolUploadInfo, *PAdsSymbolUploadInfo;

////////////////////////////////////////////////////////////////////////////////
typedef struct
{
	ads_ui32	indexGroup;
	ads_ui32	indexOffset;
	ads_ui32	cbLength;
} AdsSymbolInfoByName, *PAdsSymbolInfoByName;

////////////////////////////////////////////////////////////////////////////////
typedef enum nAmsRouterEvent	//KlausBue 11/99 
{
	AMSEVENT_ROUTERSTOP		= 0,
	AMSEVENT_ROUTERSTART		= 1,
	AMSEVENT_ROUTERREMOVED	= 2
}AmsRouterEvent;
#pragma	pack( pop )

#ifndef ADS_CONST
#define ADS_CONST
#endif

#endif//HAS_ADS_H

typedef void (TCADSDLL_API *PAdsNotificationFuncEx)(ADS_CONST AmsAddr* pAddr, AdsNotificationHeader* pNotification, ads_ui32 hUser);
typedef void (TCADSDLL_API *PAmsRouterNotificationFuncEx)(ads_i32 nEvent);
typedef void (TCADSDLL_API *PAmsRouterNotificationFuncEx3)(ads_i32 nEvent, void* hUser);



