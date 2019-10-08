#ifndef SYS_H
#define SYS_H

#include <stdio.h>
#include "../../LINK/INC/link.h"
#include "../../UTIL/INC/util.h"
#include <string.h>

enum SYS_RESET_STATE
{
	SYS_RESET_IDLE=0,SYS_RESET_START, SYS_RESET_WAIT
};

struct SYS_DATA 
{
	LINK_DATA linkData;
	LINK_DATA *linkDataPtr;
	bool ncFileValid;
	
	char ncFileName[200];

	char jogPath[200];
	
	AXIS axis;

	int  counter;
	/////////////////////////////
	double xyzNew[3];
	double uvwNew[3];

	double xLimit;
	double yLimit;
	double zLimit;

	//OP_MODE opMode;
	bool feedHold;
	bool M01;
	bool singleBlock;
	int  feedOverride;
	bool uvwxyz;
	double  wheelRatio;

	int wheelCounter;

	bool axisPlusValid[3];
	bool  axisPlusButton[3];

	bool axisMinusValid[3];
	bool  axisMinusButton[3];


	bool startValid;
	bool startButton;

	bool resetValid;
	bool resetButton;

	bool teachStartValid;
	bool teachStartButton;

	bool recordValid;
	bool recordButton;

	bool teachEndValid;
	bool teachEndButton;

	bool emergencyStopValid;
	bool emergencyStopButton;

	MMI_TO_SYS_DATA mmiToSysBlock;
	SYS_TO_MMI_DATA sysToMmiBlock;

	DEC_TO_SYS_DATA decToSysBlock;
	SYS_TO_DEC_DATA sysToDecBlock;

	SYS_RESET_STATE sysResetState;


};

void sysInit         (LINK_DATA* linkDataPtr,SYS_DATA* sysDataPtr);
void sysCtl         (SYS_DATA* sysDataPtr);
void sysClose        (SYS_DATA* sysDataPtr);
void sysReset        (SYS_DATA* sysDataPtr);

void sysMain         (SYS_DATA* sysDataPtr);

void sysInputUpdate  (SYS_DATA* sysDataPtr);
void sysOutputUpdate (SYS_DATA* sysDataPtr);

#endif