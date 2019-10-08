#include <stdafx.h>
#include <stdio.h>
#include "..\INC\intp.h"
#include "..\..\UTIL\INC\util.h"
#include  <math.h>
int slopeInit(SLOPE_DATA *slopeDataPtr)
{
	delByteSpace((char *)slopeDataPtr, sizeof(SLOPE_DATA));

	return 1;
};


int slopePlan(SLOPE_DATA *slopeDataPtr)
{
	slopeDataPtr->counter =0;
	slopeDataPtr->slopeState =  SLOPE_NULL;
	slopeDataPtr->vbMomt = 0;
	slopeDataPtr->check = 0;
	slopeDataPtr->residualCheck=0;

	if(slopeDataPtr->totalLength ==0)
	{
		slopeDataPtr->acceCounter = 0;
		slopeDataPtr->deceCounter = 0;
		slopeDataPtr->feedCounter = 0;
		slopeDataPtr->residualLength = slopeDataPtr->totalLength;
	}
	if(slopeDataPtr->totalLength >= slopeDataPtr->stepLength)
	{
		if(slopeDataPtr->feedrate * cyclingTime > slopeDataPtr->stepLength )
		{
			slopeDataPtr->acceCounter = int(slopeDataPtr->feedrate / vbStep);
				if(slopeDataPtr->feedrate / vbStep - slopeDataPtr->acceCounter == 0)
				{
					slopeDataPtr->acceCounter--;
				}
			

			slopeDataPtr->constLength = slopeDataPtr->totalLength - (slopeDataPtr->acceCounter)*(slopeDataPtr->acceCounter+1)*(slopeDataPtr->stepLength)- (slopeDataPtr->feedrate)*(cyclingTime);
			
			if(slopeDataPtr->constLength >=0)
			{			
				slopeDataPtr->feedCounter = int((slopeDataPtr->constLength )/(slopeDataPtr->feedrate*cyclingTime)) +1;
				slopeDataPtr->deceCounter = slopeDataPtr->acceCounter;
				slopeDataPtr->residualLength = slopeDataPtr->constLength -  (int((slopeDataPtr->constLength )/(slopeDataPtr->feedrate*cyclingTime)) ) *(slopeDataPtr->feedrate*cyclingTime);

			}

			else
			{
				slopeDataPtr->acceCounter = int(sqrt(slopeDataPtr->totalLength /slopeDataPtr->stepLength))-1;		
				slopeDataPtr->deceCounter = slopeDataPtr->acceCounter;
				slopeDataPtr->feedrate = int(sqrt(slopeDataPtr->totalLength/slopeDataPtr->stepLength)) * vbStep;
				
				if(slopeDataPtr->totalLength - slopeDataPtr->acceCounter*slopeDataPtr->acceCounter == 0)
				{
					slopeDataPtr->feedCounter = 1;
					slopeDataPtr->residualLength = 0;
				}
				else
				{
					slopeDataPtr->triArea = slopeDataPtr->acceCounter * (slopeDataPtr ->acceCounter +1) * slopeDataPtr ->stepLength ;
					slopeDataPtr->recArea = 1 * slopeDataPtr->feedrate * cyclingTime ;

					slopeDataPtr->feedCounter = 1 + int(   ( slopeDataPtr->totalLength - slopeDataPtr->triArea - slopeDataPtr->recArea )/ (slopeDataPtr->feedrate * cyclingTime   ));
					slopeDataPtr->residualLength =  slopeDataPtr->totalLength - slopeDataPtr->triArea - slopeDataPtr->feedCounter * slopeDataPtr->recArea ; 
				}


			}
			

		}
		else
		{
			slopeDataPtr->acceCounter =0;
			slopeDataPtr->deceCounter =0;
			slopeDataPtr->feedCounter = int(slopeDataPtr->totalLength / (slopeDataPtr->feedrate* cyclingTime));
			slopeDataPtr->residualLength = slopeDataPtr->totalLength - int(slopeDataPtr->totalLength / (slopeDataPtr->feedrate* cyclingTime))* (slopeDataPtr->feedrate* cyclingTime);
		}

		if(slopeDataPtr->residualLength >0)
		{
			slopeDataPtr->deceCounter++;
		}
	}
	if( 0 < slopeDataPtr->totalLength && slopeDataPtr->totalLength < slopeDataPtr->stepLength)  //totalLength is too small and only need a cyclingTime    // DECE
	{

		slopeDataPtr->acceCounter = 0;
		slopeDataPtr->deceCounter = 1;
		slopeDataPtr->feedCounter = 0;
		slopeDataPtr->residualLength = slopeDataPtr->totalLength;

	}
	

	if(slopeDataPtr->acceCounter >0)
	{
	slopeDataPtr->slopeState = SLOPE_ACCE;	
	}
	if(slopeDataPtr->acceCounter ==0)
	{
		slopeDataPtr->slopeState = SLOPE_CONST;
	}
	if(slopeDataPtr->acceCounter ==0 && slopeDataPtr->feedCounter ==0)
	{
		slopeDataPtr->slopeState = SLOPE_DECE;
	}
	if(slopeDataPtr->acceCounter ==0 && slopeDataPtr->feedCounter ==0 && slopeDataPtr->deceCounter ==0)
	{
		slopeDataPtr->slopeState = SLOPE_END;
	}


	return 1;
}

int slopeNull(SLOPE_DATA *slopeDataPtr){


	return 1;
}
int slopeIdle(SLOPE_DATA *slopeDataPtr){
	return 1;
}
int slopeAcce(SLOPE_DATA *slopeDataPtr){

	slopeDataPtr->counter++;

	slopeDataPtr->vbMomt = slopeDataPtr->vbMomt + vbStep;

	if(slopeDataPtr->counter == slopeDataPtr->acceCounter)
	{
		slopeDataPtr->slopeState = SLOPE_CONST;

		if(slopeDataPtr->feedCounter ==0)
		{
			slopeDataPtr->slopeState = SLOPE_DECE;
		}

	}
	return 1;
}
int slopeConst(SLOPE_DATA *slopeDataPtr){

	slopeDataPtr->counter++;

	if(slopeDataPtr->totalLength >= slopeDataPtr->stepLength)
	{
		slopeDataPtr->vbMomt = slopeDataPtr->feedrate;
		
	}
	else
	{
		slopeDataPtr->vbMomt = slopeDataPtr->totalLength / cyclingTime;
	}
	if(slopeDataPtr->counter == slopeDataPtr->acceCounter + slopeDataPtr->feedCounter)
	{
		slopeDataPtr->slopeState = SLOPE_DECE;
	}

	return 1;

}

int slopeDece(SLOPE_DATA *slopeDataPtr){

	slopeDataPtr->counter++;
	slopeDataPtr->check++;
	
	if(slopeDataPtr->check==1)
	{
		slopeDataPtr->vbMomt = slopeDataPtr->acceCounter * vbStep;
	}
	else
	{
		slopeDataPtr->vbMomt = slopeDataPtr->vbMomt - vbStep;
	}

	if(slopeDataPtr->residualCheck==1)
	{
		slopeDataPtr->vbMomt = slopeDataPtr->vbEx ;
		slopeDataPtr->residualCheck++;
	}


	if(slopeDataPtr->residualLength > slopeDataPtr->vbMomt * cyclingTime)
	{
		slopeDataPtr->vbEx = slopeDataPtr->vbMomt;
		slopeDataPtr->vbMomt = slopeDataPtr->residualLength / cyclingTime;
		slopeDataPtr->residualLength =0;
		slopeDataPtr->residualCheck++;
	}

	if(slopeDataPtr->counter == slopeDataPtr->acceCounter + slopeDataPtr->feedCounter + slopeDataPtr->deceCounter)
	{
		slopeDataPtr->slopeState = SLOPE_END;
	}
	return 1;
}
int slopeHold(SLOPE_DATA *slopeDataPtr){

	slopeDataPtr->vbMomt = slopeDataPtr->vbMomt - vbStep ;
	if(slopeDataPtr->resetHold ==true && slopeDataPtr->vbMomt <= 0)
	{
		slopeDataPtr->vbMomt = 0;
		slopeDataPtr->resetHold = false;
	}
	if(slopeDataPtr->feedHold ==true && slopeDataPtr->vbMomt <= 0)
	{
		slopeDataPtr->vbMomt = 0;	

	}

	return 1;
}
int slopeEnd(SLOPE_DATA *slopeDataPtr){

	slopeDataPtr->counter++;
	slopeDataPtr->vbMomt = 0;

	slopeDataPtr->acceCounter =0;
	slopeDataPtr->feedCounter =0;
	slopeDataPtr->deceCounter =0;



	return 1;

}


int slope(SLOPE_DATA *slopeDataPtr){

	if  (slopeDataPtr->resetHold == true || slopeDataPtr->feedHold == true) 
	{
		if (slopeDataPtr->vbMomt > 0)
		{
			slopeDataPtr->slopeState = SLOPE_HOLD;
		}
		else
		{
			slopeDataPtr->slopeState = SLOPE_END;
		}
	}



		switch (slopeDataPtr->slopeState)
		{
		case 	SLOPE_NULL:
			slopeNull(slopeDataPtr);
			break;
		case 	SLOPE_IDLE:
			slopeIdle(slopeDataPtr);
			break;
		case 	SLOPE_ACCE:
			slopeAcce(slopeDataPtr);
			break;
		case 	SLOPE_CONST:
			slopeConst(slopeDataPtr);
			break;
		case 	SLOPE_DECE:
			slopeDece(slopeDataPtr);
			break;
		case	SLOPE_HOLD:
			slopeHold(slopeDataPtr);
			break;
		case 	SLOPE_END:
			slopeEnd(slopeDataPtr);
			break;

		}
	
		return 1;
}