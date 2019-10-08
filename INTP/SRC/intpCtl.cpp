
#include <StdAfx.h>
#include <stdlib.h>
#include <math.h>

#include "..\INC\intp.h"



void intpInit(LINK_DATA* linkDataPtr,INTP_DATA* intpDataPtr)
{
	intpDataPtr->slopeDataPtr = &intpDataPtr->slopeData; 
	slopeInit(intpDataPtr->slopeDataPtr);


	if(	intpDataPtr->initCounter ==1)
	{
		intpDataPtr->linkDataPtr = linkDataPtr;

		intpDataPtr->intpState =  INTP_IDLE;
		intpDataPtr->intpResetState =  INTP_RESET_IDLE;

		intpDataPtr->xyzStart[0] = intpDataPtr->xyzNew[0];
		intpDataPtr->xyzStart[1] = intpDataPtr->xyzNew[1];
		intpDataPtr->xyzStart[2] = intpDataPtr->xyzNew[2];

		intpDataPtr->uvwStart[0] = intpDataPtr->uvwNew[0];
		intpDataPtr->uvwStart[1] = intpDataPtr->uvwNew[1];
		intpDataPtr->uvwStart[2] = intpDataPtr->uvwNew[2];

		intpDataPtr->point1[0] = intpDataPtr->point1[0];
		intpDataPtr->point1[1] = intpDataPtr->point1[1];

		for(int i = 0; i < 3; i++)
		{
			intpDataPtr->uvwRelative[i] = 0;

			intpDataPtr->xyzNew[i] = intpDataPtr->xyzNew[i];
			intpDataPtr->xyzEnd[i] = intpDataPtr->xyzNew[i];
			intpDataPtr->xyzOld[i] = intpDataPtr->xyzNew[i];

			intpDataPtr->uvwNew[i] = intpDataPtr->uvwNew[i];
			intpDataPtr->uvwEnd[i] = intpDataPtr->uvwNew[i];
			intpDataPtr->uvwOld[i] = intpDataPtr->uvwNew[i];
		}
	}
	
	else
	{
		intpDataPtr->linkDataPtr = linkDataPtr;

		intpDataPtr->intpState =  INTP_IDLE;
		intpDataPtr->intpResetState =  INTP_RESET_IDLE;
		intpDataPtr->intpFeedHoldState= INTP_FEED_HOLD_IDLE;

		intpDataPtr->xyzStart[0] = 75.0;
		intpDataPtr->xyzStart[1] = 75.0;
		intpDataPtr->xyzStart[2] = 00.0;

		intpDataPtr->uvwStart[0] = 0.0;
		intpDataPtr->uvwStart[1] = 90.0;
		intpDataPtr->uvwStart[2] = 00.0;

		intpDataPtr->point1[0] = 75.0;
		intpDataPtr->point1[1] = 0.0;

		intpDataPtr->zero[0] = 0.0;
		intpDataPtr->zero[1] = 0.0;

		for(int i = 0; i < 3; i++)
		{
			intpDataPtr->uvwRelative[i] = 0;

			intpDataPtr->xyzNew[i] = intpDataPtr->xyzStart[i];
			intpDataPtr->xyzEnd[i] = intpDataPtr->xyzStart[i];
			intpDataPtr->xyzOld[i] = intpDataPtr->xyzStart[i];

			intpDataPtr->uvwNew[i] = intpDataPtr->uvwStart[i];
			intpDataPtr->uvwEnd[i] = intpDataPtr->uvwStart[i];
			intpDataPtr->uvwOld[i] = intpDataPtr->uvwStart[i];
		}

			intpDataPtr->decToIntpBlock.lineCmd = G00_RAPID_MOTION ;
			intpDataPtr->decToIntpBlock.feedOverride = 20;
			intpDataPtr->decToIntpBlock.relAbs = true;
			intpDataPtr->decToIntpBlock.xyzCoordinate[0] = 0.0;
			intpDataPtr->decToIntpBlock.xyzCoordinate[1] = 0.0;
			intpDataPtr->decToIntpBlock.xyzCoordinate[2] = 0.0;
			intpDataPtr->decToIntpBlock.xyzValid[0] = true;
			intpDataPtr->decToIntpBlock.xyzValid[1] = true;
			intpDataPtr->decToIntpBlock.xyzValid[2] = true;
	}

	intpDataPtr->stepLength = vbStep *  cyclingTime;



	intpDataPtr->initCounter =1;
}


int intpCtl(INTP_DATA* intpDataPtr)
{


	switch(intpDataPtr->intpFeedHoldState){
	case INTP_FEED_HOLD_IDLE:
		if(intpDataPtr->linkDataPtr->feedhold )
		{
			intpDataPtr->slopeDataPtr->feedHold = true; 
			intpDataPtr->intpFeedHoldState = INTP_FEED_HOLD_EXE;
		}

		break; 
	case INTP_FEED_HOLD_EXE:
		if(intpDataPtr->linkDataPtr->feedhold ==false)
		{
			intpDataPtr->slopeDataPtr->feedHold = false; 
			intpDataPtr->intpFeedHoldState = INTP_FEED_HOLD_IDLE;
		}

		break;

	}


		switch(intpDataPtr->intpResetState){
		case INTP_RESET_IDLE:
			
			if(intpDataPtr->linkDataPtr->resetOrder.resetIntp==true)
			{
				intpDataPtr->intpResetState = INTP_RESET_EXE;
				intpDataPtr->slopeDataPtr->resetHold = true; 
			}
			else
			{
				intpDataPtr->intpResetState = INTP_RESET_IDLE;
			}
			break;	
		case INTP_RESET_EXE:
			if(intpDataPtr->slopeDataPtr->vbMomt == 0)
			{
				intpDataPtr->slopeDataPtr->resetHold = false; 
				intpDataPtr->intpState = INTP_RESET;
				intpDataPtr->intpResetState = INTP_RESET_CLOSE;
			}
			break;
		case INTP_RESET_CLOSE:
			intpDataPtr->linkDataPtr->resetOrder.resetIntp = false;
								
				for(int i = 0 ; i< 3 ; i++)
				{
					intpDataPtr->xyzStart[i]=0;
					intpDataPtr->xyzEnd[i]=0;
					intpDataPtr->xyzOld[i]=0;
					intpDataPtr->xyzRelative[i]=0;
					intpDataPtr->uvwStart[i]=0;
					intpDataPtr->uvwEnd[i]=0;
					intpDataPtr->uvwOld[i]=0;
					intpDataPtr->uvwRelative[i]=0;
					intpDataPtr->increment[i]=0;
					intpDataPtr->ijkCenter[i]=0;
					intpDataPtr->theta[i]=0;
				}

				intpInit(intpDataPtr->linkDataPtr,intpDataPtr);

				intpDataPtr->intpResetState = INTP_RESET_IDLE;
			break;

		}
	
	

	intpMain(intpDataPtr);
	return 1;
}

int intpClose(INTP_DATA* intpDataPtr)
{
	return 1;
}


