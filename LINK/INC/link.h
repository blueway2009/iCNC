#ifndef LINK_H
#define LINK_H

#include <stdio.h>
#include <string.h>

//int delByteSpace(char *bytePtr, int size);

enum OP_MODE {NULL_MODE=0,MEM_MODE,MDI_MODE, JOG_MODE ,WHEEL_MODE,TEACH_MODE,HOME_MODE};

enum AXIS{XPLUS,XMINUS,YPLUS,YMINUS,ZPLUS,ZMINUS };



#define DEC_TO_INTP_FIFO_LENGTH 100

// NC command
//*****************************************************************
enum LINE_CMD {NULL_CMD=0, G00_RAPID_MOTION,G01_MOTION_AT_FEED,
	G02_MOTION, G03_MOTION,
	G04_DWELL_TIME,  
	GO_REFERENCE_POINT, G100_U,G101_V, G102_W,
	M00,M01,M30_END};

// DEC_TO_INTP_BLOCK
//*****************************************************************

struct DEC_TO_INTP_BLOCK  // or NCBlock
{
	int			lineNumber;
	bool        lineNumberValid;

	LINE_CMD	lineCmd; //G00,G06,G07,G04,M30
	bool		G90G91Valid; //G91 true, G90 false:abs
	double		xyzCoordinate[3]; //XYZ 
	bool        xyzuvw;
	bool		xyzValid[3];  //clear at beginning, input:true

	double		speed;  //F
	double		dwellTime;

	bool		relAbs; //G91 true: real ;G90 false:abs
	int			terminate; //M30_End

	int         fileSize;
	int			feedOverride;

	int			clockwise;
};


struct REFERENCE_POINT
{
int axisPriority[3]; // xyz or uvw, 0: no; 1 first priority,
					 // [0][2][1] : z first go ref. point the y , x not
};


struct PROGRAM_END
{
	char programName[80]; 
	int programNumber; 
};

struct DWELL_TIME
{
	double value; // time in s
};

union RT_FUNCTION
{
	REFERENCE_POINT referencePoint;
	PROGRAM_END programEnd;
	DWELL_TIME dwellTime;
};

enum PLANE { XY, YZ, XZ};

enum DIRECTION { CW, CCW};

struct CIRCLE_INPUT
{
	enum PLANE plane; /* XY, YZ, XZ, main plane for circle */
	enum DIRECTION direction; /* cw or ccw */
	double iCenter; /* circle center correspond to x */
	double jCenter; /* circle center correspond to y */
	double kCenter; /* circle center correspond to z */
};

struct MOTION
{
	double feedrate;
	bool relative; // G90: false; G91:true
	bool m00;
	bool m01;

	double xyzCoordinate[3]; // end or goal position in xyz
	bool xyzValid[3]; // xyz coordinate value sent
	double uvwCoordinate[3]; // end or goal position in uvw
	bool uvwValid[3]; // uvw coordinate value sent
	CIRCLE_INPUT circleInput;
};

union MOTION_FUNCTION 
{
	MOTION motion;
	RT_FUNCTION rtFunction;
};


struct MMI_TO_SYS_DATA
{

	int  counter;
	bool ncFileValid;
	char ncFileName[200];
	/////////////////////////////

	bool feedHold;
	bool M01;
	bool singleBlock;
	int  feedOverride;
	bool uvwxyz;
	double  wheelRatio;

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

	AXIS axis;


};
//SYS_TO_MMI_DATA
//*****************************************************************
struct SYS_TO_MMI_DATA
{

	double xyzValue[3];
	bool   xyzValueValid[3];

	double axisValue[3];
	bool   axisValueValid[3];



};


struct DEC_TO_SYS_DATA {

};

struct SYS_TO_DEC_DATA {
	bool ncFileValid;
	char ncFileName[200];




};

struct INTP_TO_SYS_BLOCK {

};

enum FIFO_TYPE {
	DEC_TO_INTP = 0,
	SYS_TO_INTP = 1,
	OTHER_FIFO = 2
};

struct FIFO_HEAD{

	int wrIndex;
	int rdIndex;

	int sizeInBlock;
	int sizeInByte;

	FIFO_TYPE  type;
};


struct OTHER_FIFO_DATA{
	int foo;
};


struct OTHER_BLOCK_FIFO {
	FIFO_HEAD			headBlock;
	OTHER_FIFO_DATA		otherFIFOInfoHolder[DEC_TO_INTP_FIFO_LENGTH];
	bool				otherFIFODataValid[DEC_TO_INTP_FIFO_LENGTH];
};



struct DEC_TO_INTP_FIFO{
	FIFO_HEAD			headBlock;
	DEC_TO_INTP_BLOCK   decToIntpBlockInfoHolder[DEC_TO_INTP_FIFO_LENGTH];
	bool				decToIntpBlockValid[DEC_TO_INTP_FIFO_LENGTH];

};

//*******************************************************************
// RESET
//*******************************************************************
struct RESET_ORDER{
	
	bool resetSys;
	bool resetDec;
	bool resetIntp;
	bool resetMmi;
	bool reseting;



};

//*******************************************************************
// LINK_DATA
//*******************************************************************
struct  LINK_DATA
{
	MMI_TO_SYS_DATA mmiToSysBlock;
	SYS_TO_MMI_DATA sysToMmiBlock;

	SYS_TO_DEC_DATA sysToDecBlock;
	DEC_TO_SYS_DATA decToSysBlock;

	bool mmiToSysBlockValid ;
	bool sysToMmiBlockValid ;

	bool sysToDecBlockValid ;
	bool decToSysBlockValid ;

	DEC_TO_INTP_FIFO decToIntpFifo;

	INTP_TO_SYS_BLOCK intpToSysBlock;

	OP_MODE opMode;

	double vbMomt;

	bool M30ProgramEnd;
	bool M00Program;

	RESET_ORDER resetOrder;

	bool feedhold;
	bool singleBlock;
	bool M01;

	

	bool startValid;



	char jogPath[200];
};






void linkInit         (LINK_DATA* linkDataPtr);
void linkCtl         (LINK_DATA* linkDataPtr);
void linkClose        (LINK_DATA* linkDataPtr);
void linkReset        (LINK_DATA* linkDataPtr);

void linkMain         (LINK_DATA* linkDataPtr);

void linkInputUpdate  (LINK_DATA* linkDataPtr);
void linkOutputUpdate (LINK_DATA* linkDataPtr);

#endif
