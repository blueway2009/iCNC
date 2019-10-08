#ifndef DEC_H
#define DEC_H

#include <stdio.h>
#include "../../LINK/INC/link.h"
#include "../../UTIL/INC/util.h"
#include <string.h>

enum DEC_RESET_STATE
{
	DEC_RESET_IDLE=0,DEC_RESET_START
};


enum DEC_STATE {DEC_NULL, DEC_IDLE, DEC_OPEN_NC_FILE, DEC_PRE,
	DEC_LINE_LOOP, DEC_END_OF_LINE, DEC_WRITE_BLOCK,
	DEC_SENT_TO_FIFO, DEC_M30_WAIT,DEC_ERROR};

struct DEC_DATA
{
	DEC_RESET_STATE decResetState;

	LINK_DATA linkData;
	LINK_DATA *linkDataPtr;

	bool ncFileValid;
	char ncFileName[200];
	int  counter;

	DEC_STATE	decState;
	char		line[200];
	char		jogPath[200];
	char		*asciiPtr; // point to the first one

	char        *buffer;
	FILE		*ncFilePtr;

	bool		markN;
	bool		markG;
	bool		markM;
	bool		markF;
	bool		markX;
	bool		markY;
	bool		markZ;
	
	int			lineNumber;
	bool		lineNumberValid;

	LINE_CMD	lineCmd; //G00,G06,G07,G04,M30

	int			clockwise;

	int         fileSize;

	bool        xyzuvw;
	double		xyzCoordinate[3];  //XYZ
	bool		xyzValid[3];

	double		speed;
	double		dwellTime;

	bool		relAbs; //G91 true: rel ;G90 false:abs
	int			terminate; //M30_End

	int  feedOverride;

	DEC_TO_INTP_FIFO	decToIntpFifo;
	DEC_TO_INTP_BLOCK	decToIntpBlock;
	DEC_TO_INTP_BLOCK   *decToIntpBlockPtr;

	DEC_TO_SYS_DATA decToSysBlock;
	SYS_TO_DEC_DATA sysToDecBlock;

};


int nFunction		(DEC_DATA  *decDataPtr);
int gFunction		(DEC_DATA  *decDataPtr);
int fFunction		(DEC_DATA  *decDataPtr);
int mFunction		(DEC_DATA  *decDataPtr);
int coordFunction	(DEC_DATA  *decDataPtr);
int endOfLine		(DEC_DATA  *decDataPtr);

int decIdle			(DEC_DATA* decDataPtr);
int decOpenNCFile	(DEC_DATA* decDataPtr);
int decPre			(DEC_DATA* decDataPtr);
int decLineLoop		(DEC_DATA* decDataPtr);
int decEndOfLine	(DEC_DATA* decDataPtr);
int decWriteBlock	(DEC_DATA* decDataPtr); //, LINK_DATA* linkDataPtr
int decSentToFIFO	(DEC_DATA* decDataPtr);
int decM30Wait		(DEC_DATA* decDataPtr);
int decError		(DEC_DATA* decDataPtr);

int decMain         (DEC_DATA* decDataPtr);

int decInit			(LINK_DATA* linkDataPtr, DEC_DATA* decDataPtr);
int decCtl			(DEC_DATA* decDataPtr);
int decReset		(DEC_DATA* decDataPtr);
int decClose		(DEC_DATA* decDataPtr);

int decToSysUpdate  (DEC_DATA* decDataPtr);
int sysToDecUpdate  (DEC_DATA* decDataPtr);

#endif