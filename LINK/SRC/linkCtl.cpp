
#include <StdAfx.h>
#include "..\INC\link.h"

#include "..\..\UTIL\INC\util.h"


int linkCtl(void)
{
//linkMain();
return 1;
} //linkCtl()

void linkInit(LINK_DATA* linkDataPtr)
{
	OP_MODE tempMode = linkDataPtr->opMode;
	delByteSpace((char *)linkDataPtr, sizeof(LINK_DATA));
	 linkDataPtr->opMode =tempMode;

	linkDataPtr->mmiToSysBlockValid = false;
	linkDataPtr->sysToDecBlockValid = false;
	linkDataPtr->mmiToSysBlockValid = false;

}


void linkCtl(LINK_DATA* linkDataPtr)
{
	linkMain(linkDataPtr);
}

void linkClose(LINK_DATA* linkDataPtr)
{
	
}

void linkReset(LINK_DATA* linkDataPtr)
{

}