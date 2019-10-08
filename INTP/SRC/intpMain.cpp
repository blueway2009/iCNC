#include "stdafx.h"
#include "../INC/intp.h"
#include "../../LINK/INC/link.h"
#include <math.h>

#include "..\..\DRV\INC\stepMotorDRV.h"
#include "..\..\DEF\switch.h"


int intpMain(INTP_DATA* intpDataPtr)
{
	intpOutputUpdate( intpDataPtr);
	intpInputUpdate ( intpDataPtr);
	

	switch(intpDataPtr->intpState){
		case INTP_IDLE:
			intpIdle(intpDataPtr);
			break;			
		case INTP_PRE:
			intpPre(intpDataPtr);
			break;
		case INTP_EXE:
			intpExe(intpDataPtr);
			break;
		case INTP_END:
			intpEnd(intpDataPtr);
			break;
		case INTP_DWELL:
			intpDwell(intpDataPtr);
			break;
		case INTP_JOG_UVW:
			intpJogUvw(intpDataPtr);
			break;
		case INTP_JOG_EXE:
			intpJogExe(intpDataPtr);
			break;
		case INTP_M00:
			intpM00(intpDataPtr);
			break;
		case INTP_M01:
			intpM01(intpDataPtr);
			break;
		case INTP_M30:
			intpM30(intpDataPtr);
			break;
		case INTP_PAUSE:
			intpPause(intpDataPtr);
			break;
		case INTP_RESET:
			intpReset(intpDataPtr);
			break;
		case INTP_ERROR:
			intpError(intpDataPtr);
			break;			
		default:
			intpError(intpDataPtr);
	}

	
	return 1;
}

int intpIdle(INTP_DATA *intpDataPtr){


	if(readFIFO(&intpDataPtr->linkDataPtr->decToIntpFifo.headBlock, &intpDataPtr->decToIntpBlock) == true)
	{
		switch(intpDataPtr->decToIntpBlock.lineCmd)
		{
		case G00_RAPID_MOTION:
			intpDataPtr->intpState = INTP_PRE;
			break;
		case G01_MOTION_AT_FEED:
			intpDataPtr->intpState = INTP_PRE;
			break;
		case G02_MOTION:
			intpDataPtr->intpState = INTP_PRE;
			break;
		case G03_MOTION:
			intpDataPtr->intpState = INTP_PRE;
			break;
		case G04_DWELL_TIME:
			intpDataPtr->intpState = INTP_DWELL;
			intpDataPtr->dwellCounter =0;
			break;
		case G100_U:
			intpDataPtr->intpState = INTP_JOG_UVW;
			break;
		case G101_V:
			intpDataPtr->intpState = INTP_JOG_UVW;
			break;
		case G102_W:
			intpDataPtr->intpState = INTP_JOG_UVW;
			break;
		case GO_REFERENCE_POINT:
			//??
			break;
		case M00:
			intpDataPtr->intpState = INTP_M00;
			break;
		case M01:
			intpDataPtr->intpState = INTP_M01;
			break;

		case M30_END:
			intpDataPtr->intpState = INTP_M30;
			break;
		default:
			intpDataPtr->intpState = INTP_ERROR;
		}

	}



	return 1;
}
int intpPre(INTP_DATA* intpDataPtr){

	intpDataPtr->stepLength = vbStep *  cyclingTime;

	/////////////////////////////
	//check G00 or G01
	/////////////////////////////
	if(intpDataPtr->decToIntpBlock.lineCmd == G00_RAPID_MOTION)
	{
		intpDataPtr->feedrate = fMax;
	}
	if(intpDataPtr->decToIntpBlock.lineCmd == G01_MOTION_AT_FEED)
	{
		intpDataPtr->feedrate = intpDataPtr -> decToIntpBlock.speed;
	}

	intpDataPtr->slopeDataPtr = &intpDataPtr->slopeData;


	for(int i=0; i<3 ; i++)
	{
		intpDataPtr->xyzStart[i] = intpDataPtr->xyzNew[i];
		intpDataPtr->uvwStart[i] = intpDataPtr->uvwNew[i];
	}


	/////////////////////////////
	//check if is xyz
	//check rel or abs
	/////////////////////////////
	if(intpDataPtr->decToIntpBlock.xyzuvw==true)//XYZ
	{
		if(intpDataPtr->decToIntpBlock.relAbs == true) //RELATIVE
		{
			for(int i=0; i<3 ; i++)
			{
				if(intpDataPtr->decToIntpBlock.xyzValid[i] == false)
				{
					intpDataPtr->decToIntpBlock.xyzCoordinate[i] = 0;
				}
				intpDataPtr->xyzEnd[i] = intpDataPtr->xyzStart[i] + intpDataPtr->decToIntpBlock.xyzCoordinate[i];
				intpDataPtr->xyzRelative[i] = intpDataPtr->decToIntpBlock.xyzCoordinate[i];			
			}		
		}
		else   //ABSOLUTE
		{
			for(int i=0; i<3 ; i++)
			{
				if(intpDataPtr->decToIntpBlock.xyzValid[i] == false)
				{
					intpDataPtr->decToIntpBlock.xyzCoordinate[i] = intpDataPtr->xyzEnd[i];
				}
				intpDataPtr->xyzEnd[i] = intpDataPtr->decToIntpBlock.xyzCoordinate[i];
				intpDataPtr->xyzRelative[i] = intpDataPtr->decToIntpBlock.xyzCoordinate[i] - intpDataPtr->xyzStart[i];
			}		
		}	

	}

	else
	{
		if(intpDataPtr->decToIntpBlock.relAbs == true) //RELATIVE
		{
			for(int i=0; i<3 ; i++)
			{
				if(intpDataPtr->decToIntpBlock.xyzValid[i] == false)
				{
					intpDataPtr->decToIntpBlock.xyzCoordinate[i] = 0;
				} 
			}
			intpDataPtr->xyzEnd[0] =length1 * cos(( intpDataPtr->uvwStart[0] + intpDataPtr->decToIntpBlock.xyzCoordinate[0] ) *pi/180)+ length2 * cos(( intpDataPtr->uvwStart[1] + intpDataPtr->decToIntpBlock.xyzCoordinate[1] )*pi/180);
			intpDataPtr->xyzEnd[1] =length1 * sin(( intpDataPtr->uvwStart[0] + intpDataPtr->decToIntpBlock.xyzCoordinate[0] ) *pi/180)+ length2 * sin(( intpDataPtr->uvwStart[1] + intpDataPtr->decToIntpBlock.xyzCoordinate[1] )*pi/180);
			intpDataPtr->xyzEnd[2] =intpDataPtr->xyzStart[2] + intpDataPtr->decToIntpBlock.xyzCoordinate[2];

			for(int i=0; i<3 ; i++)
			{
				intpDataPtr->xyzRelative[i] = intpDataPtr->xyzEnd[i] - intpDataPtr->xyzStart[i];
			}	

		}
		else   //ABSOLUTE
		{
			for(int i=0; i<3 ; i++)
			{
				if(intpDataPtr->decToIntpBlock.xyzValid[i] == false)
				{
					intpDataPtr->decToIntpBlock.xyzCoordinate[i] = intpDataPtr->uvwEnd[i];
				}
			}	
			intpDataPtr->xyzEnd[0] = length1 * cos(intpDataPtr->decToIntpBlock.xyzCoordinate[0]*pi/180)+ length2 * cos(intpDataPtr->decToIntpBlock.xyzCoordinate[1]*pi/180);
			intpDataPtr->xyzEnd[1] = length1 * sin(intpDataPtr->decToIntpBlock.xyzCoordinate[0]*pi/180)+ length2 * sin(intpDataPtr->decToIntpBlock.xyzCoordinate[1]*pi/180);
			intpDataPtr->xyzEnd[2] = intpDataPtr->decToIntpBlock.xyzCoordinate[2];

			for(int i=0; i<3 ; i++)
			{
				intpDataPtr->xyzRelative[i] = intpDataPtr->xyzEnd[i] - intpDataPtr->xyzStart[i];
			}	

		}	
	}

	intpDataPtr->totalLength =	sqrt(intpDataPtr->xyzRelative[0] *intpDataPtr->xyzRelative[0] +intpDataPtr->xyzRelative[1] *intpDataPtr->xyzRelative[1]+intpDataPtr->xyzRelative[2] *intpDataPtr->xyzRelative[2] );

	intpDataPtr->intpState = INTP_EXE;
	intpDataPtr->slopeDataPtr->feedrate = intpDataPtr->feedrate ;
	intpDataPtr->slopeDataPtr->totalLength = intpDataPtr->totalLength;
	intpDataPtr->slopeDataPtr->residualLength = intpDataPtr->residualLength;
	intpDataPtr->slopeDataPtr->stepLength = intpDataPtr->stepLength;

	slopePlan(intpDataPtr->slopeDataPtr);


	return 1;
}

int intpExe(INTP_DATA* intpDataPtr){

	if(intpDataPtr->slopeDataPtr->counter <= intpDataPtr->slopeDataPtr->acceCounter + intpDataPtr->slopeDataPtr->feedCounter + intpDataPtr->slopeDataPtr->deceCounter)
	{	
		slope(intpDataPtr->slopeDataPtr);

		intpDataPtr->linkDataPtr->vbMomt = intpDataPtr->slopeDataPtr->vbMomt;


		intpDataPtr->slopeDataPtr->deltaLength = intpDataPtr->slopeDataPtr->vbMomt * cyclingTime ;

		if(intpDataPtr->slopeDataPtr->totalLength ==0)
		{
			for(int i = 0 ; i<3 ; i++)
			{
				intpDataPtr->xyzOld[i] = intpDataPtr->xyzNew[i] ;
				intpDataPtr->xyzNew[i] = intpDataPtr->xyzNew[i] ;
			}
		}
		else
		{
			for(int i = 0 ; i<3 ; i++)
			{
				intpDataPtr->xyzOld[i] = intpDataPtr->xyzNew[i] ;
				intpDataPtr->xyzNew[i] = intpDataPtr->xyzNew[i] + intpDataPtr->xyzRelative[i]*(intpDataPtr->slopeDataPtr->deltaLength / intpDataPtr->slopeDataPtr->totalLength);
			}
		}

		for(int i = 0 ; i<3 ; i++)
		{
			intpDataPtr->uvwOld[i] = intpDataPtr->uvwNew[i] ;
		}

		intpDataPtr->alpha = atan2(intpDataPtr->xyzNew[1],intpDataPtr->xyzNew[0])  *   180.0 / pi;
		intpDataPtr->distFromOrigin = intpDataPtr->xyzNew[0]*intpDataPtr->xyzNew[0]+intpDataPtr->xyzNew[1]*intpDataPtr->xyzNew[1];
		
		intpDataPtr->checkCos = (length1*length1+length2*length2-intpDataPtr->distFromOrigin)/(2*length1*length2);

		if((length1*length1+length2*length2-intpDataPtr->distFromOrigin)/(2*length1*length2) >1)
		{
			intpDataPtr->checkCos =1;
		}
		if((length1*length1+length2*length2-intpDataPtr->distFromOrigin)/(2*length1*length2) <-1)
		{
			intpDataPtr->checkCos =-1;
		}
		
		intpDataPtr->beta = acos(intpDataPtr->checkCos ) *  180.0 / pi;

		intpDataPtr->theta1 =  intpDataPtr->alpha - (180 -intpDataPtr->beta)/2;
		intpDataPtr->theta2 =  2 * intpDataPtr->alpha  - intpDataPtr->theta1;


		if (intpDataPtr->theta1 > 180)
		{
			intpDataPtr->theta1 = intpDataPtr->theta1 -360;
		}
		if (intpDataPtr->theta1 < -180)
		{
			intpDataPtr->theta1 = intpDataPtr->theta1 +360;
		}

		if (intpDataPtr->theta2 > 180)
		{
			intpDataPtr->theta2 = intpDataPtr->theta2 -360;
		}
		if (intpDataPtr->theta2 < -180)
		{
			intpDataPtr->theta2  = intpDataPtr->theta2 +360;
		}

		intpDataPtr->a =(intpDataPtr->theta1-intpDataPtr->uvwNew[0])*(intpDataPtr->theta1-intpDataPtr->uvwNew[0]) ;
		intpDataPtr->b =(intpDataPtr->theta2-intpDataPtr->uvwNew[0])*(intpDataPtr->theta2-intpDataPtr->uvwNew[0]) ;


		if(intpDataPtr->a  >=  intpDataPtr->b)
		{
			intpDataPtr->uvwNew[0] = intpDataPtr->theta2;
			intpDataPtr->uvwNew[1] = intpDataPtr->theta1;
			intpDataPtr->uvwNew[2] = intpDataPtr->xyzNew[2];
			if(abs(intpDataPtr->uvwNew[0]-intpDataPtr->uvwOld[0]) >90 )
			{
				intpDataPtr->uvwNew[0] = intpDataPtr->theta1;
				intpDataPtr->uvwNew[1] = intpDataPtr->theta2;
			}
		}
		if(intpDataPtr->a  <  intpDataPtr->b)
		{
			intpDataPtr->uvwNew[0] = intpDataPtr->theta1;
			intpDataPtr->uvwNew[1] = intpDataPtr->theta2;
			intpDataPtr->uvwNew[2] = intpDataPtr->xyzNew[2];
			if(abs(intpDataPtr->uvwNew[0]-intpDataPtr->uvwOld[0]) >90 )
			{
				intpDataPtr->uvwNew[0] = intpDataPtr->theta2;
				intpDataPtr->uvwNew[1] = intpDataPtr->theta1;
			}
		}

		for (int i = 0 ; i < 3 ; i++)
		{
			if(intpDataPtr->uvwNew[i]-intpDataPtr->uvwOld[i] > 180)
			{
				intpDataPtr->uvwOld[i] = intpDataPtr->uvwOld[i] +360;
			}
			if(intpDataPtr->uvwNew[i]-intpDataPtr->uvwOld[i] < -180)
			{
				intpDataPtr->uvwOld[i] = intpDataPtr->uvwOld[i] -360;
			}

			intpDataPtr->increment[i] = intpDataPtr->uvwNew[i]-intpDataPtr->uvwOld[i];
		}//end for

	

		// send to motion card when we use HD_TIMER


#if HD_TIMER
		putAxisValue(0, int(intpDataPtr->increment[0]  / 0.0018));
		putAxisValue(1, int(intpDataPtr->increment[1]  / 0.0018));
		putAxisValue(2, int(intpDataPtr->increment[2]  / 0.0025));
#endif

		intpDataPtr->point1[0] = length1*cos(intpDataPtr->uvwNew[0] * pi/180);
		intpDataPtr->point1[1] = length1*sin(intpDataPtr->uvwNew[0] * pi/180);

	}
	else
	{


#if HD_TIMER
		putAxisValue(0, 0);
		putAxisValue(1, 0);
		putAxisValue(2, 0);
#endif
	
		if(intpDataPtr->slopeDataPtr->feedHold ==true)
		{
			intpDataPtr->intpState = INTP_PAUSE;
		}
		else
		{
			intpDataPtr->intpState = INTP_IDLE;
		}

		for(int i = 0 ; i<3 ; i++)
		{
			intpDataPtr->xyzEnd[i] = intpDataPtr->xyzNew[i];
			intpDataPtr->uvwEnd[i] = intpDataPtr->uvwNew[i];
		}
	}


	return 1;
}
int intpEnd(INTP_DATA* intpDataPtr){
	return 1;
}

int intpDwell(INTP_DATA* intpDataPtr){

	intpDataPtr->dwellCounter++;

	if(intpDataPtr->dwellCounter  < (intpDataPtr->decToIntpBlock.dwellTime/cyclingTime) )
	{
		intpDataPtr->intpState = INTP_DWELL;
		intpDataPtr->slopeDataPtr->vbMomt =0;

	}
	else
	{
		intpDataPtr->intpState = INTP_IDLE;
	}

#if HD_TIMER
	putAxisValue(0, 0);
	putAxisValue(1, 0);
	putAxisValue(2, 0);
#endif

	return 1;
}

int intpM00(INTP_DATA* intpDataPtr){

	intpDataPtr->linkDataPtr->M00Program = true;

	if(intpDataPtr->linkDataPtr->startValid)	
	{
		intpDataPtr->intpState = INTP_IDLE;
		intpDataPtr->linkDataPtr->startValid=false;
		intpDataPtr->linkDataPtr->M00Program = false;
	}
	return 1;
}
int intpM01(INTP_DATA* intpDataPtr){


	if(intpDataPtr->linkDataPtr->M01)
	{
		if(intpDataPtr->linkDataPtr->startValid )
		{
			intpDataPtr->linkDataPtr->startValid = false;
			intpDataPtr->intpState = INTP_IDLE;
		}
		else
		{
			intpDataPtr->intpState = INTP_M01;
		}
	}
	else
	{
		intpDataPtr->intpState = INTP_IDLE;
	}


	return 1;
}
int intpM30(INTP_DATA* intpDataPtr){

	intpDataPtr->linkDataPtr->M30ProgramEnd = true;



	if(intpDataPtr->linkDataPtr->resetOrder.resetIntp == true)  ///////////////
	{
		intpDataPtr->intpState = INTP_RESET;
		intpDataPtr->linkDataPtr->M30ProgramEnd = false;
	}
	else
	{
		intpDataPtr->intpState = INTP_IDLE;
	}


	return 1;
}

int intpJogUvw(INTP_DATA* intpDataPtr){

	if(intpDataPtr->decToIntpBlock.lineCmd == G100_U)
	{
		intpDataPtr->jog[0] =true;
	}
	else
	{
		intpDataPtr->jog[0] =false;
	}
	if(intpDataPtr->decToIntpBlock.lineCmd == G101_V)
	{
		intpDataPtr->jog[1] =true;
	}
	else
	{
		intpDataPtr->jog[1] =false;
	}
	if(intpDataPtr->decToIntpBlock.lineCmd == G102_W)
	{
		intpDataPtr->jog[2] =true;
	}
	else
	{
		intpDataPtr->jog[2] =false;
	}
	intpDataPtr->slopeDataPtr = &intpDataPtr->slopeData;

	//現在開始的點等於剛剛結束的點
	for(int i=0; i<3 ; i++)
	{
		intpDataPtr->xyzStart[i] = intpDataPtr->xyzNew[i];
		intpDataPtr->uvwStart[i] = intpDataPtr->uvwNew[i];
	}


	intpDataPtr->intpState = INTP_JOG_EXE;

	intpDataPtr->slopeDataPtr->feedrate = fMax;

	intpDataPtr->slopeDataPtr->acceCounter = int(fMax /vbStep);
	intpDataPtr->slopeDataPtr->deceCounter = int(fMax /vbStep);
	intpDataPtr->slopeDataPtr->feedCounter = 1000;

	intpDataPtr->slopeDataPtr->slopeState = SLOPE_ACCE;

	return 1;
}
int intpJogExe(INTP_DATA* intpDataPtr){

	if(intpDataPtr->slopeDataPtr->counter <= intpDataPtr->slopeDataPtr->acceCounter + intpDataPtr->slopeDataPtr->feedCounter + intpDataPtr->slopeDataPtr->deceCounter)
	{	
		slope(intpDataPtr->slopeDataPtr);

		intpDataPtr->linkDataPtr->vbMomt = intpDataPtr->slopeDataPtr->vbMomt;


		intpDataPtr->slopeDataPtr->deltaLength = intpDataPtr->slopeDataPtr->vbMomt * cyclingTime ;

		for(int i = 0 ; i<3 ; i++)
		{
			if(intpDataPtr->jog[i]==true)
			{
				intpDataPtr->increment[i] = atan2(intpDataPtr->slopeDataPtr->deltaLength,length1)*   180.0 / pi;
			}
			else
			{
				intpDataPtr->increment[i] =0;
			}

			if(intpDataPtr->decToIntpBlock.clockwise==1)  //定義順時針 1 = 順 = 負
			{
				intpDataPtr->increment[i] = -intpDataPtr->increment[i];
			}
		}

		for(int i = 0 ; i<3 ; i++)
		{
			intpDataPtr->xyzOld[i] = intpDataPtr->xyzNew[i] ;
			intpDataPtr->uvwOld[i] = intpDataPtr->uvwNew[i] ;

			intpDataPtr->uvwNew[i] = intpDataPtr->uvwNew[i] +intpDataPtr->increment[i];
		}

		intpDataPtr->xyzNew[0] = length1 * cos((intpDataPtr->uvwNew[0]+intpDataPtr->increment[0])*pi/180) + length2 * cos((intpDataPtr->uvwNew[1]+intpDataPtr->increment[1])*pi/180);
		intpDataPtr->xyzNew[1] = length1 * sin((intpDataPtr->uvwNew[0]+intpDataPtr->increment[0])*pi/180) + length2 * sin((intpDataPtr->uvwNew[1]+intpDataPtr->increment[1])*pi/180);
		intpDataPtr->xyzNew[2] = intpDataPtr->uvwNew[2] + intpDataPtr->increment[2];

#if HD_TIMER
		putAxisValue(0, int(intpDataPtr->increment[0]  / 0.0018));
		putAxisValue(1, int(intpDataPtr->increment[1]  / 0.0018));
		putAxisValue(2, int(intpDataPtr->increment[2]  / 0.0025));
#endif

		intpDataPtr->point1[0] = length1*cos(intpDataPtr->uvwNew[0] * pi/180);
		intpDataPtr->point1[1] = length1*sin(intpDataPtr->uvwNew[0] * pi/180);

	}
	else
	{
#if HD_TIMER
		putAxisValue(0, 0);
		putAxisValue(1, 0);
		putAxisValue(2, 0);
#endif

		if(intpDataPtr->slopeDataPtr->feedHold ==true)
		{
			intpDataPtr->intpState = INTP_PAUSE;
		}
		else
		{
			intpDataPtr->intpState = INTP_IDLE;
				
			for(int i=0; i<3; i++)
			{
				intpDataPtr->xyzEndtemp[i]=intpDataPtr->xyzEnd[i];
				intpDataPtr->uvwEndtemp[i]=intpDataPtr->uvwEnd[i];
			}

		}

		for(int i = 0 ; i<3 ; i++)
		{
			intpDataPtr->xyzEnd[i] = intpDataPtr->xyzNew[i];
			intpDataPtr->uvwEnd[i] = intpDataPtr->uvwNew[i];

			if(intpDataPtr->uvwNew[i] >180 )
			{
				intpDataPtr->uvwNew[i]= intpDataPtr->uvwNew[i] -360;
			}
			if(intpDataPtr->uvwNew[i] < -180)
			{
				intpDataPtr->uvwNew[i]= intpDataPtr->uvwNew[i] +360;
			}

		}
	}


	return 1;
}

int intpPause(INTP_DATA* intpDataPtr){


	if(intpDataPtr->slopeDataPtr->feedHold == false)	
	{

		intpDataPtr->intpState = INTP_PRE;
	}
	return 1;
}
int intpReset(INTP_DATA* intpDataPtr){



	return 1;
}
int intpError(INTP_DATA* intpDataPtr){
	return 1;
}


void intpInputUpdate(INTP_DATA* intpDataPtr)
{

}

void intpOutputUpdate(INTP_DATA* intpDataPtr)
{
}