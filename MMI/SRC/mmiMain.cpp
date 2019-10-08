#include "stdafx.h"
#include "string.h"
#include "../INC/mmi.h"



void mmiMain(MMI_DATA* mmiDataPtr)
{
	mmiToSysUpdate( mmiDataPtr);
	mmiToFormUpdate( mmiDataPtr);
	sysToMmiUpdate( mmiDataPtr);
	formToMmiUpdate( mmiDataPtr); //這樣寫對嗎?!!
	return;
}

void mmiToSysUpdate(MMI_DATA* mmiDataPtr)  //output
{
	if(mmiDataPtr->formInput == true)
	{

	

		if(mmiDataPtr->linkDataPtr->mmiToSysBlockValid==false)
		{
			mmiDataPtr->linkDataPtr->mmiToSysBlock.feedHold = mmiDataPtr->feedHold;
			mmiDataPtr->linkDataPtr->mmiToSysBlock.M01 = mmiDataPtr->M01;
			mmiDataPtr->linkDataPtr->mmiToSysBlock.singleBlock = mmiDataPtr->singleBlock;
			mmiDataPtr->linkDataPtr->mmiToSysBlock.feedOverride = mmiDataPtr->feedOverride;
			mmiDataPtr->linkDataPtr->mmiToSysBlock.uvwxyz = mmiDataPtr->uvwxyz;
			mmiDataPtr->linkDataPtr->mmiToSysBlock.wheelRatio = mmiDataPtr->wheelRatio;
			mmiDataPtr->linkDataPtr->mmiToSysBlock.axis = mmiDataPtr->axis;

			if(mmiDataPtr->ncFileValid == true)
			{
				strcpy_s(mmiDataPtr->linkDataPtr->mmiToSysBlock.ncFileName , 200, mmiDataPtr->ncFileName);   //strcpy_s
				mmiDataPtr->linkDataPtr->mmiToSysBlock.ncFileValid = true;
				mmiDataPtr->ncFileValid = false;
			}

			if(mmiDataPtr->startValid ==true)
			{
				mmiDataPtr->linkDataPtr->mmiToSysBlock.startButton = mmiDataPtr->startButton; // MMI TO LINK
				mmiDataPtr->linkDataPtr->mmiToSysBlock.startValid = true;
				mmiDataPtr->startValid = false;
			}

			if(mmiDataPtr->resetValid ==true)
			{
				mmiDataPtr->linkDataPtr->mmiToSysBlock.resetButton = mmiDataPtr->resetButton; // MMI TO LINK
				mmiDataPtr->linkDataPtr->mmiToSysBlock.resetValid = true;
				mmiDataPtr->resetValid = false;
			}

			if(mmiDataPtr->teachStartValid ==true)
			{
				mmiDataPtr->linkDataPtr->mmiToSysBlock.teachStartButton = mmiDataPtr->teachStartButton; // MMI TO LINK
				mmiDataPtr->linkDataPtr->mmiToSysBlock.teachStartValid = true;
				mmiDataPtr->teachStartValid = false;
			}

			if(mmiDataPtr->recordValid ==true)
			{
				mmiDataPtr->linkDataPtr->mmiToSysBlock.recordButton = mmiDataPtr->recordButton; // MMI TO LINK
				mmiDataPtr->linkDataPtr->mmiToSysBlock.recordValid = true;
				mmiDataPtr->recordValid = false; 
			}

			if(mmiDataPtr->teachEndValid ==true)
			{
				mmiDataPtr->linkDataPtr->mmiToSysBlock.teachEndButton = mmiDataPtr->teachEndButton; // MMI TO LINK
				mmiDataPtr->linkDataPtr->mmiToSysBlock.teachEndValid = true;
				mmiDataPtr->teachEndValid = false;
			}

			if(mmiDataPtr->emergencyStopValid ==true)
			{
				mmiDataPtr->linkDataPtr->mmiToSysBlock.emergencyStopButton = mmiDataPtr->emergencyStopButton; // MMI TO LINK
				mmiDataPtr->linkDataPtr->mmiToSysBlock.emergencyStopValid = true;
				mmiDataPtr->emergencyStopValid = false;
			}
			for(int i = 0 ; i <3 ; i++)
			{
				if(mmiDataPtr->axisPlusValid[i] ==true)
				{
					mmiDataPtr->linkDataPtr->mmiToSysBlock.axisPlusButton[i]=mmiDataPtr->axisPlusButton[i]; // MMI TO LINK
					mmiDataPtr->linkDataPtr->mmiToSysBlock.axisPlusValid[i]=true;
					mmiDataPtr->axisPlusValid[i] = false;
				}
				if(mmiDataPtr->axisMinusValid[i] ==true)
				{
					mmiDataPtr->linkDataPtr->mmiToSysBlock.axisMinusButton[i]=mmiDataPtr->axisMinusButton[i]; // MMI TO LINK
					mmiDataPtr->linkDataPtr->mmiToSysBlock.axisMinusValid[i]=true;
					mmiDataPtr->axisMinusValid[i] = false;
				}


			}



			mmiDataPtr->linkDataPtr->mmiToSysBlockValid =true;
		}

		mmiDataPtr->formInput = false;
	}
}

void sysToMmiUpdate(MMI_DATA* mmiDataPtr)
{

	if(mmiDataPtr->linkDataPtr->sysToMmiBlockValid==false)
		return;
	else
	{
		mmiDataPtr->sysToMmiBlock=mmiDataPtr->linkDataPtr->sysToMmiBlock;
		mmiDataPtr->linkDataPtr->sysToMmiBlockValid =false;

	}








}

void mmiToFormUpdate(MMI_DATA* mmiDataPtr)
{

}


void formToMmiUpdate(MMI_DATA* mmiDataPtr)
{

}



