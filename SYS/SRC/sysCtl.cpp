
#include <StdAfx.h>
#include "..\INC\sys.h"


void sysInit(LINK_DATA* linkDataPtr,SYS_DATA* sysDataPtr)
{	

	delByteSpace((char *)sysDataPtr, sizeof(SYS_DATA));


	sysDataPtr->linkDataPtr = linkDataPtr;

	sysDataPtr->sysResetState = SYS_RESET_IDLE;
}


void sysCtl(SYS_DATA* sysDataPtr)
{
	if(sysDataPtr->resetValid == true)
	{
		sysDataPtr->sysResetState = SYS_RESET_START;
		sysDataPtr->linkDataPtr->resetOrder.reseting = true;
		sysDataPtr->resetValid = false;
	}
	
	switch(sysDataPtr->sysResetState){
		case SYS_RESET_IDLE: 
			break;	
		case SYS_RESET_START:
			sysDataPtr->linkDataPtr->resetOrder.resetDec = true;
			sysDataPtr->linkDataPtr->resetOrder.resetIntp = true;
			sysDataPtr->linkDataPtr->resetOrder.resetMmi = true;
			sysInit(sysDataPtr->linkDataPtr,sysDataPtr);
			sysDataPtr->sysResetState = SYS_RESET_WAIT;
			break;			
		case SYS_RESET_WAIT:
			if(sysDataPtr->linkDataPtr->resetOrder.resetIntp == false  && sysDataPtr->linkDataPtr->resetOrder.resetDec == false && sysDataPtr->linkDataPtr->resetOrder.resetMmi == false)
			{				
				sysDataPtr->linkDataPtr->resetOrder.reseting = false;
				sysDataPtr->sysResetState = SYS_RESET_IDLE;

				linkInit(sysDataPtr->linkDataPtr);
				
			}
			break;

		}

	if(sysDataPtr->feedHold == true)
	{
		sysDataPtr->linkDataPtr->feedhold = true;
	}
	else
	{
		sysDataPtr->linkDataPtr->feedhold = false;
	}

	if(sysDataPtr->M01 == true)
	{
		sysDataPtr->linkDataPtr->M01 = true;
	}
	else
	{
		sysDataPtr->linkDataPtr->M01 = false;
	}


	if(sysDataPtr->singleBlock == true)
	{
		sysDataPtr->linkDataPtr->singleBlock  = true;
	}
	else
	{
		sysDataPtr->linkDataPtr->singleBlock  = false;
	}

	sysMain(sysDataPtr);
}

void sysClose(SYS_DATA* sysDataPtr)
{
	
}

void sysReset(SYS_DATA* sysDataPtr)
{

}