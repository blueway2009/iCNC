#include <stdafx.h>
#include "..\INC\mmi.h"


void mmiInit(LINK_DATA* linkDataPtr,MMI_DATA* mmiDataPtr)
{
	mmiDataPtr->linkDataPtr = linkDataPtr;
}


void mmiCtl(MMI_DATA* mmiDataPtr)
{
	switch(mmiDataPtr->mmiResetState){
	case MMI_RESET_IDLE:
		if(mmiDataPtr->linkDataPtr->resetOrder.resetMmi)
		{
			mmiDataPtr->mmiResetState = MMI_RESET_START; 
		}
		else
		{
			mmiDataPtr->mmiResetState = MMI_RESET_IDLE;
		}
		break;		
	case MMI_RESET_START:

		for(int i = 0 ; i< 200 ; i++)
		{
			mmiDataPtr->ncFileName[i] =0;
		}

		mmiDataPtr->ncFileValid =0;


		mmiDataPtr->feedHold =0;
		mmiDataPtr->M01 =0;
		mmiDataPtr->singleBlock =0;
		mmiDataPtr->feedOverride =0;
		mmiDataPtr->wheelRatio =0;

		mmiDataPtr->startValid =0;
		mmiDataPtr->startButton =0;

		mmiDataPtr->resetValid =0;
		mmiDataPtr->resetButton =0;

		mmiDataPtr->teachStartValid =0;
		mmiDataPtr->teachStartButton =0;

		mmiDataPtr-> recordValid =0;
		mmiDataPtr-> recordButton =0;

		mmiDataPtr->teachEndValid =0;
		mmiDataPtr->teachEndButton =0;

		mmiDataPtr->emergencyStopValid =0;
		mmiDataPtr->emergencyStopButton =0;

		mmiDataPtr->axis =XPLUS;

		mmiDataPtr->formInput =0;

		mmiDataPtr->XButtonCheck[0] =0;
		mmiDataPtr->XButtonCheck[1] =0;
		mmiDataPtr->XButtonCheck[2] =0;

		mmiDataPtr->XYZButtonCheck[0]=0;
		mmiDataPtr->XYZButtonCheck[1]=0;
		mmiDataPtr->XYZButtonCheck[2]=0;
		mmiDataPtr->XYZButtonCheck[3]=0;
		mmiDataPtr->XYZButtonCheck[4]=0;
		mmiDataPtr->XYZButtonCheck[5]=0;

		mmiDataPtr->mmiResetState = MMI_RESET_IDLE;
		mmiDataPtr->linkDataPtr->resetOrder.resetMmi = false;
		break;
	}


	mmiMain(mmiDataPtr);
}

void mmiClose(MMI_DATA* mmiDataPtr)
{
	
}

void mmiReset(MMI_DATA* mmiDataPtr)
{

}

