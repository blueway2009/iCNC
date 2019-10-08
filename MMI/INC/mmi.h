#ifndef MMI_H
#define MMI_H

#include <stdio.h>
#include "../../LINK/INC/link.h"
#include "../../UTIL/INC/util.h"
#include <string.h>

enum MMI_RESET_STATE
{
	MMI_RESET_IDLE=0,MMI_RESET_START
};





struct MMI_DATA
{
	MMI_RESET_STATE mmiResetState;

	bool ncFileValid;
	char ncFileName[200];

	bool mdiInputValid;
	char mdiInput[200];

	bool XButtonCheck[3];
	bool XYZButtonCheck[6];
	bool feedHold;
	bool M01;
	bool singleBlock;

	int  feedOverride;
	bool uvwxyz;
	double  wheelRatio;

	bool startValid;
	bool startButton;

	bool resetValid;
	bool resetButton;

	AXIS axis;

	bool teachStartValid;
	bool teachStartButton;

	bool recordValid;
	bool recordButton;

	bool teachEndValid;
	bool teachEndButton;

	bool emergencyStopValid;
	bool emergencyStopButton;

	bool axisPlusValid[3];	
	bool axisPlusButton[3];
	int  axisPlusDistance[3];

	bool axisMinusValid[3];	
	bool axisMinusButton[3];
	int  axisMinusDistance[3];

	bool formInput;



	LINK_DATA *linkDataPtr;
	int  counter;

	MMI_TO_SYS_DATA mmiToSysBlock;
	SYS_TO_MMI_DATA sysToMmiBlock;

} ;



void mmiInit         (LINK_DATA* linkDataPtr, MMI_DATA* mmiDataPtr);
void mmiCtl         (MMI_DATA* mmiDataPtr);
void mmiClose        (MMI_DATA* mmiDataPtr);
void mmiReset        (MMI_DATA* mmiDataPtr);

void mmiMain         (MMI_DATA* mmiDataPtr);

void mmiToSysUpdate  (MMI_DATA* mmiDataPtr);
void sysToMmiUpdate  (MMI_DATA* mmiDataPtr);

void mmiToFormUpdate(MMI_DATA* mmiDataPtr);
void formToMmiUpdate(MMI_DATA* mmiDataPtr);


#endif