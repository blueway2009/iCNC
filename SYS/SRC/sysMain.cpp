#include "stdafx.h"
#include < stdio.h >
#include "../INC/sys.h"
#include  <math.h>

void sysMain(SYS_DATA* sysDataPtr)
{



	sysInputUpdate ( sysDataPtr);
	sysOutputUpdate( sysDataPtr);
}

void sysInputUpdate(SYS_DATA* sysDataPtr)
{

	if(sysDataPtr->linkDataPtr->mmiToSysBlockValid==true)
	{
		for(int i = 0 ; i <3 ; i++)
		{
			if(sysDataPtr->linkDataPtr->mmiToSysBlock.axisPlusValid[i] ==true)
			{
				sysDataPtr->axisPlusButton[i]=sysDataPtr->linkDataPtr->mmiToSysBlock.axisPlusButton[i];  //LINK TO SYS
				sysDataPtr->axisPlusValid[i] = true;
				sysDataPtr->linkDataPtr->mmiToSysBlock.axisPlusValid[i]=false;
			}
			if(sysDataPtr->linkDataPtr->mmiToSysBlock.axisMinusValid[i] ==true)
			{
				sysDataPtr->axisMinusButton[i]=sysDataPtr->linkDataPtr->mmiToSysBlock.axisMinusButton[i];  //LINK TO SYS
				sysDataPtr->axisMinusValid[i] = true;
				sysDataPtr->linkDataPtr->mmiToSysBlock.axisMinusValid[i]=false;
			}

		}

		sysDataPtr->feedHold=sysDataPtr->linkDataPtr->mmiToSysBlock.feedHold; 
		sysDataPtr->M01=sysDataPtr->linkDataPtr->mmiToSysBlock.M01; 
		sysDataPtr->singleBlock=sysDataPtr->linkDataPtr->mmiToSysBlock.singleBlock; 
		sysDataPtr->feedOverride=sysDataPtr->linkDataPtr->mmiToSysBlock.feedOverride; 
		sysDataPtr->uvwxyz=sysDataPtr->linkDataPtr->mmiToSysBlock.uvwxyz; 
		sysDataPtr->wheelRatio=sysDataPtr->linkDataPtr->mmiToSysBlock.wheelRatio;
		sysDataPtr->axis=sysDataPtr->linkDataPtr->mmiToSysBlock.axis; 

		if(sysDataPtr->linkDataPtr->mmiToSysBlock.ncFileValid == true)
		{
			strcpy_s(sysDataPtr->ncFileName , 200, sysDataPtr->linkDataPtr->mmiToSysBlock.ncFileName );
			sysDataPtr->ncFileValid = true;
			sysDataPtr->linkDataPtr->mmiToSysBlock.ncFileValid = false;
		}

		if(sysDataPtr->linkDataPtr->mmiToSysBlock.startValid ==true)
		{
			sysDataPtr->startButton = sysDataPtr->linkDataPtr->mmiToSysBlock.startButton;
			sysDataPtr->startValid = true;
			sysDataPtr->linkDataPtr->mmiToSysBlock.startValid = false;
		}

		if(sysDataPtr->linkDataPtr->mmiToSysBlock.resetValid ==true)
		{
			sysDataPtr->resetButton = sysDataPtr->linkDataPtr->mmiToSysBlock.resetButton;
			sysDataPtr->resetValid = true;
			sysDataPtr->linkDataPtr->mmiToSysBlock.resetValid = false;
		}

		if(sysDataPtr->linkDataPtr->mmiToSysBlock.teachStartValid ==true)
		{
			sysDataPtr->teachStartButton = sysDataPtr->linkDataPtr->mmiToSysBlock.teachStartButton;
			sysDataPtr->teachStartValid = true;
			sysDataPtr->linkDataPtr->mmiToSysBlock.teachStartValid = false;
		}

		if(sysDataPtr->linkDataPtr->mmiToSysBlock.recordValid ==true)
		{
			sysDataPtr->startButton = sysDataPtr->linkDataPtr->mmiToSysBlock.recordButton;
			sysDataPtr->recordValid = true;
			sysDataPtr->linkDataPtr->mmiToSysBlock.recordValid = false;
		}

		if(sysDataPtr->linkDataPtr->mmiToSysBlock.teachEndValid ==true)
		{
			sysDataPtr->teachEndButton = sysDataPtr->linkDataPtr->mmiToSysBlock.teachEndButton;
			sysDataPtr->teachEndValid = true;
			sysDataPtr->linkDataPtr->mmiToSysBlock.teachEndValid = false;
		}

		if(sysDataPtr->linkDataPtr->mmiToSysBlock.emergencyStopValid ==true)
		{
			sysDataPtr->emergencyStopButton = sysDataPtr->linkDataPtr->mmiToSysBlock.emergencyStopButton;
			sysDataPtr->emergencyStopValid = true;
			sysDataPtr->linkDataPtr->mmiToSysBlock.emergencyStopValid = false;
		}
	
		sysDataPtr->linkDataPtr->mmiToSysBlockValid =false;
	}




}

void sysOutputUpdate(SYS_DATA* sysDataPtr)
{

	switch (sysDataPtr->linkDataPtr->opMode)
	{
	case MEM_MODE:
		if(sysDataPtr->startValid ==true)
		{
			if(sysDataPtr->ncFileValid == true)
			{
				strcpy_s(sysDataPtr->sysToDecBlock.ncFileName , 200, sysDataPtr->ncFileName );
				sysDataPtr->sysToDecBlock.ncFileValid = true; 

				sysDataPtr->ncFileValid = false;
				sysDataPtr->linkDataPtr->mmiToSysBlock.ncFileValid  = false;
			}
			else
			{
				sysDataPtr->linkDataPtr->startValid =true;
			}

			sysDataPtr->startValid =false;
			sysDataPtr->linkDataPtr->mmiToSysBlock.startValid =false;
		}
		break;

	case MDI_MODE:
		if(sysDataPtr->startValid ==true)
		{
			if(sysDataPtr->ncFileValid == true)
			{
				strcpy_s(sysDataPtr->sysToDecBlock.ncFileName , 200, sysDataPtr->ncFileName );
				sysDataPtr->sysToDecBlock.ncFileValid = true;

				sysDataPtr->ncFileValid = false;
				sysDataPtr->linkDataPtr->mmiToSysBlock.ncFileValid  = false;
			}
			else
			{
			}

			sysDataPtr->startValid =false;
			sysDataPtr->linkDataPtr->mmiToSysBlock.startValid =false;
		}






		break;
	case JOG_MODE:

		  sysDataPtr->xLimit = int(sqrt(150*150 - sysDataPtr->xyzNew[1] * sysDataPtr->xyzNew[1] ));
		  sysDataPtr->yLimit = int(sqrt(150*150 - sysDataPtr->xyzNew[0] * sysDataPtr->xyzNew[0] ));
		  sysDataPtr->zLimit = 100.00;

		for(int i = 0 ; i <3 ; i++)
		{
			if(sysDataPtr->axisPlusValid[i] == true)
			{
				if(sysDataPtr->axisPlusButton[i] == true)
				{
					FILE * pathFile;
					pathFile = fopen("path.txt","w");

					if(i ==0){
						fprintf(pathFile,"N100 G00 G90 X%lf \nM30",sysDataPtr->xLimit);
					}
					if(i ==1){
						fprintf(pathFile,"N100 G00 G90 Y%lf \nM30",sysDataPtr->yLimit);
					}
					if(i ==2){
						fprintf(pathFile,"N100 G00 G90 Z%lf \nM30",sysDataPtr->zLimit);
					}

					if(sysDataPtr->uvwxyz)
					{
						if(i ==0){
							fprintf(pathFile,"N100 G100 X0");
						}
						if(i ==1){
							fprintf(pathFile,"N100 G101 X0");
						}
						if(i ==2){
							fprintf(pathFile,"N100 G102 X0");
						}
					}

					fclose(pathFile);
					strcpy_s(sysDataPtr->sysToDecBlock.ncFileName,200,"path.txt");
					sysDataPtr->sysToDecBlock.ncFileValid = true;

					sysDataPtr->ncFileValid = false;
					sysDataPtr->linkDataPtr->mmiToSysBlock.ncFileValid  = false;


				}
				else
				{
					sysDataPtr->resetValid = true;
				}
				sysDataPtr->axisPlusValid[i] = false;
				sysDataPtr->linkDataPtr->mmiToSysBlock.axisPlusValid[i] = false;
			}


			if(sysDataPtr->axisMinusValid[i] == true)
			{
				if(sysDataPtr->axisMinusButton[i] == true)
				{

					FILE * pathFile;
					pathFile = fopen("path.txt","w");

					if(i ==0){
						fprintf(pathFile,"N100 G00 G90 X%lf\nM30",-sysDataPtr->xLimit);
					}
					if(i ==1){
						fprintf(pathFile,"N100 G00 G90 Y%lf\nM30",-sysDataPtr->yLimit);
					}
					if(i ==2){
						fprintf(pathFile,"N100 G00 G90 Z%lf\nM30",0);
					}


					if(sysDataPtr->uvwxyz)
					{
						if(i ==0){
							fprintf(pathFile,"N100 G100 X1");
						}
						if(i ==1){
							fprintf(pathFile,"N100 G101 X1");
						}
						if(i ==2){
							fprintf(pathFile,"N100 G102 X1");
						}
					}
					fclose(pathFile);
					strcpy_s(sysDataPtr->sysToDecBlock.ncFileName,200,"path.txt");
					sysDataPtr->sysToDecBlock.ncFileValid = true;


					sysDataPtr->ncFileValid = false;
					sysDataPtr->linkDataPtr->mmiToSysBlock.ncFileValid  = false;
				}
				else
				{
					sysDataPtr->resetValid = true;
				}
				sysDataPtr->axisMinusValid[i] = false;
				sysDataPtr->linkDataPtr->mmiToSysBlock.axisMinusValid[i] = false;
			}
		}
		break;	
	case HOME_MODE:

		if(sysDataPtr->startValid ==true)
		{
			FILE * pathFile;
			pathFile = fopen("path.txt","w");
			fprintf(pathFile,"N100 G00 G90 X75 Y75 Z0 \nM30");

			fclose(pathFile);
			strcpy_s(sysDataPtr->sysToDecBlock.ncFileName,200,"path.txt");
			sysDataPtr->sysToDecBlock.ncFileValid = true;


			sysDataPtr->ncFileValid = false;
			sysDataPtr->linkDataPtr->mmiToSysBlock.ncFileValid  = false;
			
			sysDataPtr->startValid =false;
			sysDataPtr->linkDataPtr->mmiToSysBlock.startValid =false;
		}

		break;
	case WHEEL_MODE:

		sysDataPtr->linkDataPtr->startValid=sysDataPtr->startValid;

		if(sysDataPtr->startValid ==true)
		{
			FILE * pathFile;
			pathFile = fopen("path.txt","w");
			switch(sysDataPtr->axis)
			{
			case XPLUS:
				fprintf(pathFile,"N100 G00 G91 X%lf\nM30",sysDataPtr->wheelRatio);
				break;
			case XMINUS:
				fprintf(pathFile,"N100 G00 G91 X%lf\nM30",sysDataPtr->wheelRatio);
				break;
			case YPLUS:
				fprintf(pathFile,"N100 G00 G91 Y%lf\nM30",sysDataPtr->wheelRatio);
				break;
			case YMINUS:
				fprintf(pathFile,"N100 G00 G91 Y%lf\nM30",sysDataPtr->wheelRatio);
				break;
			case ZPLUS:
				fprintf(pathFile,"N100 G00 G91 Z%lf\nM30",sysDataPtr->wheelRatio);
				break;
			case ZMINUS:
				fprintf(pathFile,"N100 G00 G91 Z%lf\nM30",sysDataPtr->wheelRatio);
				break;
			}
			fclose(pathFile);
			strcpy_s(sysDataPtr->sysToDecBlock.ncFileName,200,"path.txt");
			sysDataPtr->sysToDecBlock.ncFileValid = true;


			sysDataPtr->ncFileValid = false;
			sysDataPtr->linkDataPtr->mmiToSysBlock.ncFileValid  = false;

			sysDataPtr->startValid =false;
			sysDataPtr->linkDataPtr->mmiToSysBlock.startValid =false;
		}



		break;

	}


	if(sysDataPtr->linkDataPtr->sysToDecBlockValid==false)
	{
		sysDataPtr->linkDataPtr->sysToDecBlock = sysDataPtr->sysToDecBlock;
		sysDataPtr->linkDataPtr->sysToDecBlockValid =true;
	}

}