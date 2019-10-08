#include "stdafx.h"
#include "../INC/link.h"

void linkMain(LINK_DATA* linkDataPtr)
{
	linkOutputUpdate( linkDataPtr);
	linkInputUpdate ( linkDataPtr);
}

void linkInputUpdate(LINK_DATA* linkDataPtr)
{
}

void linkOutputUpdate(LINK_DATA* linkDataPtr)
{
	//linkDataPtr->mmiToSysBlock = mmiDataPtr->mmiToSysBlock;
}