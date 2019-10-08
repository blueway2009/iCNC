#include <StdAfx.h>

#include <stdio.h>
#include <stdlib.h>

#include "..\INC\dec.h"

int decCtl(void)
{

	return 1;
} 


//=============================================

int decInit(LINK_DATA* linkDataPtr, DEC_DATA  *decDataPtr)
{
	delByteSpace((char *)decDataPtr, sizeof(DEC_DATA));

	decDataPtr->decResetState =  DEC_RESET_IDLE;
	decDataPtr->decToIntpBlockPtr = & decDataPtr->decToIntpBlock;
	decDataPtr->linkDataPtr = linkDataPtr;

	int i;

	decDataPtr->decState = DEC_IDLE;
	decDataPtr->markN = false;
	decDataPtr->markG = false;
	decDataPtr->markF = false;
	decDataPtr->markX = false;
	decDataPtr->markY = false;
	decDataPtr->markZ = false;
	decDataPtr->relAbs = false;

	for(i=0; i<200; i++)
	{
	decDataPtr->line[i]=0;
	}

	decDataPtr->asciiPtr = decDataPtr->line;  //?
	decDataPtr->lineNumber = 0;
	decDataPtr->lineCmd = NULL_CMD;
	decDataPtr->xyzCoordinate[0] = 0 ;
	decDataPtr->xyzCoordinate[1] = 0 ;
	decDataPtr->xyzCoordinate[2] = 0 ;
	decDataPtr->speed = 0 ;
	decDataPtr->dwellTime = 0 ;
	decDataPtr->terminate = 0 ;
	decDataPtr->xyzuvw =true;
	initFIFO(&decDataPtr->linkDataPtr->decToIntpFifo.headBlock, FIFO_TYPE::DEC_TO_INTP);

   return 1;
}


int decCtl(DEC_DATA* decDataPtr)
{
	switch(decDataPtr->decResetState){
	case DEC_RESET_IDLE:
		if(decDataPtr->linkDataPtr->resetOrder.resetDec)
		{
			decDataPtr->decResetState = DEC_RESET_START; 
		}
		else
		{
			decDataPtr->decResetState = DEC_RESET_IDLE;
		}
		break;		
	case DEC_RESET_START:
		decInit(decDataPtr->linkDataPtr,decDataPtr);
		decDataPtr->linkDataPtr->resetOrder.resetDec = false;
		decDataPtr->decResetState = DEC_RESET_IDLE;
		break;
	}


	decMain(decDataPtr);
	return 1;
}

int decClose(DEC_DATA* decDataPtr)
{
	return 1;
}

int decReset(DEC_DATA* decDataPtr)
{
	return 1;
}