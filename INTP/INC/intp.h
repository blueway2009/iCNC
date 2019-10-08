#ifndef INTP_H
#define INTP_H

#include <stdio.h>
#include <string.h>

#include "../../LINK/INC/link.h"
#include "../../UTIL/INC/util.h"

enum INTP_STATE{INTP_IDLE=1, INTP_PRE, INTP_FACTORS,INTP_EXE,  INTP_END,  INTP_DWELL,  INTP_JOG_UVW, INTP_M00, INTP_M01,
	INTP_M30, INTP_JOG_EXE,INTP_PAUSE, INTP_RESET, INTP_ERROR};
enum INTP_RESET_STATE{INTP_RESET_IDLE, INTP_RESET_EXE, INTP_RESET_CLOSE};
enum INTP_FEED_HOLD_STATE{INTP_FEED_HOLD_IDLE, INTP_FEED_HOLD_EXE};


#define DEC_TO_INTP_FIFO_LENGTH 100

#define pi 3.14159265358979323846

//aMax a = 0.98 *1000 = 980 (mm/s^2)
//980 * 0.02 = 19.6 = 20.0
//1 cyclingTime 0.02 s

#define fMax 20.0
#define vbStep 1.5
#define cyclingTime 0.02
#define length1 75.0
#define length2 75.0

#define elementTime 1
#define timeInteval 20 //real time

enum SLOPE_STATE
{	SLOPE_NULL=0, SLOPE_IDLE, SLOPE_ACCE, SLOPE_CONST, SLOPE_PEAK,
	SLOPE_DECE, SLOPE_END, SLOPE_HOLD};

typedef struct
{
	SLOPE_STATE slopeState;

	int check;
	int residualCheck;
	double		vbEx;

	double      totalLength;
	double      constLength;

	double      residualLength;

	double      deltaLength;
	double      vbPeak;
	double      extraLength;

	double		totalLengthReset;

	double      feedrate;
	double      vbMomt;

	double		stepLength;
	
	int acceCounter;
	int deceCounter;
	int feedCounter;
	int counter;

	bool        resetHold;
	bool		feedHold;
	bool        intpEnd;
	
	double triArea;
	double recArea;

} SLOPE_DATA;

typedef struct 
{	
	INTP_STATE intpState;
	INTP_RESET_STATE intpResetState;
	INTP_FEED_HOLD_STATE intpFeedHoldState;

	double	xyzStart[3];
	double	xyzEnd[3];
	double	xyzNew[3];
	double	xyzOld[3];
	double	xyzRelative[3];

	double	uvwStart[3];
	double	uvwEnd[3];
	double	uvwNew[3];
	double	uvwOld[3];
	double	uvwRelative[3];

	double increment[3];

	double	point1[2];
	double  zero[2];

	//////slope///////////
	double      totalLength; //sum+residual
	double      residualLength;

	double  feedrate;
	double  stepLength;

	double	deltaLength;
	double	ijkCenter[3];
	double	theta[3];

	double		xyzEndtemp[3];
	double		uvwEndtemp[3];

	INTP_TO_SYS_BLOCK intpToSysBlock;

	DEC_TO_INTP_BLOCK decToIntpBlock;

	LINK_DATA		linkData;
	LINK_DATA		*linkDataPtr;

	SLOPE_DATA		slopeData;
	SLOPE_DATA		*slopeDataPtr;

	LINE_CMD lineCmd;

	double a;
	double b;
	double alpha;
	double beta;
	double theta1;
	double theta2;
	double thetaOld1;
	double thetaOld2;
	double distFromOrigin;

	int acceCounter;
	int deceCounter;
	int feedCounter;
	int counter;

	int dwellCounter;

	double ratio;

	int initCounter;

	bool jog[3];
	double xyzIncrement[3];
	double checkCos;

} INTP_DATA;

void intpInit         (LINK_DATA* linkDataPtr,INTP_DATA* intpDataPtr);
int intpCtl         (INTP_DATA* intpDataPtr);
int intpClose        (INTP_DATA* intpDataPtr);

int intpMain         (INTP_DATA* intpDataPtr);

void intpInputUpdate  (INTP_DATA* intpDataPtr);
void intpOutputUpdate (INTP_DATA* intpDataPtr);

int intpIdle(INTP_DATA *intpDataPtr);
int intpPre(INTP_DATA* intpDataPtr);
int intpExe(INTP_DATA* intpDataPtr);
int intpEnd(INTP_DATA* intpDataPtr);
int intpDwell(INTP_DATA* intpDataPtr);
int intpM00(INTP_DATA* intpDataPtr);
int intpM01(INTP_DATA* intpDataPtr);
int intpM30(INTP_DATA* intpDataPtr);
int intpJogUvw(INTP_DATA* intpDataPtr);
int intpJogExe(INTP_DATA* intpDataPtr);
int intpPause(INTP_DATA* intpDataPtr);
int intpReset(INTP_DATA* intpDataPtr);
int intpError(INTP_DATA* intpDataPtr);

int slopeInit(SLOPE_DATA *slopeDataPtr);
int slopePlan(SLOPE_DATA *slopeDataPtr);
int slope(SLOPE_DATA *intpDataPtr);

int slopeNull(SLOPE_DATA *slopeDataPtr);
int slopeIdle(SLOPE_DATA *slopeDataPtr);
int slopeAcce(SLOPE_DATA *slopeDataPtr);
int slopeConst(SLOPE_DATA *slopeDataPtr);
int slopeDece(SLOPE_DATA *slopeDataPtr);
int slopeHold(SLOPE_DATA *slopeDataPtr);
int slopeEnd(SLOPE_DATA *slopeDataPtr);

#endif