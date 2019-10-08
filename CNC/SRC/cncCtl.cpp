#include <StdAfx.h>

#include "..\INC\cnc.h"

int cncInit (CNC_DATA *cncDataPtr)
{
	cncDataPtr->decDataPtr = &cncDataPtr -> decData;
	cncDataPtr->intpDataPtr = &cncDataPtr -> intpData;
	cncDataPtr->mmiDataPtr = &cncDataPtr -> mmiData;
	cncDataPtr->sysDataPtr = &cncDataPtr -> sysData;
	cncDataPtr->linkDataPtr = &cncDataPtr -> linkData;

	decInit(cncDataPtr->linkDataPtr, cncDataPtr -> decDataPtr);
	intpInit(cncDataPtr->linkDataPtr, cncDataPtr -> intpDataPtr);
	mmiInit(cncDataPtr->linkDataPtr, cncDataPtr -> mmiDataPtr);
	sysInit(cncDataPtr->linkDataPtr, cncDataPtr -> sysDataPtr);
	linkInit(cncDataPtr->linkDataPtr);
	return 0 ;
}


int cncCtl(void)
{
	return 1;
}


int cncRTCtl         (CNC_DATA* cncDataPtr)
{
	intpCtl(cncDataPtr->intpDataPtr);
	return 1;
}
int cncNRTCtl         (CNC_DATA* cncDataPtr)
{
	mmiCtl(cncDataPtr->mmiDataPtr);
	sysCtl(cncDataPtr->sysDataPtr);
	decCtl(cncDataPtr->decDataPtr);
	return 1;
}