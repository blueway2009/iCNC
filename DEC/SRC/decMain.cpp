#include "stdafx.h"
#include "../INC/dec.h"

#include <stdio.h>
#include <stdlib.h>

int decMain(DEC_DATA* decDataPtr)
{
	decToSysUpdate( decDataPtr);
	sysToDecUpdate( decDataPtr);

	switch (decDataPtr->decState)
	{
	case DEC_IDLE:
		decIdle(decDataPtr);
		break;
	case DEC_OPEN_NC_FILE:
		decOpenNCFile(decDataPtr);
		break;
	case DEC_PRE:
		decPre(decDataPtr);
		break;
	case DEC_LINE_LOOP:
		decLineLoop(decDataPtr);
		break;
	case DEC_END_OF_LINE:
		decEndOfLine(decDataPtr);
		break;
	case DEC_WRITE_BLOCK:
		decWriteBlock(decDataPtr); //,linkDataPtr 
		break;
	case DEC_SENT_TO_FIFO:
		decSentToFIFO(decDataPtr);
		break;
	case DEC_M30_WAIT:
		decM30Wait(decDataPtr);
		break;
	case DEC_ERROR:
		decError(decDataPtr);
		break;
	}


	return 1;
}//decMain

int decToSysUpdate(DEC_DATA* decDataPtr)
{	
	return 1;
}

int sysToDecUpdate(DEC_DATA* decDataPtr)
{	
	//////////////////////////////////////////
	// Data 的東西丟到 Block
	if(decDataPtr->linkDataPtr->sysToDecBlockValid==true)  //如果Data有資料更新就做動
	{
		decDataPtr->sysToDecBlock = decDataPtr->linkDataPtr->sysToDecBlock;
		decDataPtr->linkDataPtr->sysToDecBlockValid =false;  //更新了，改成沒有資料更新
	}

	//////////////////////////////////////////
	// Block 的東西丟到 SYS
	if(decDataPtr->sysToDecBlock.ncFileValid == true)
	{
		strcpy_s(decDataPtr->ncFileName , 200, decDataPtr->sysToDecBlock.ncFileName);
		decDataPtr->ncFileValid = true;
		decDataPtr->sysToDecBlock.ncFileValid =  false;
	}

	return 1;
}