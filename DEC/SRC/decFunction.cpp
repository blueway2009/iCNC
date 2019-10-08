#include "StdAfx.h"

#include <stdio.h>
#include <stdlib.h>

#include "../INC/dec.h"


int nFunction	(DEC_DATA  *decDataPtr)
{
	if(decDataPtr->markN ==true)
	{

	}
	decDataPtr->markN = true;
	decDataPtr->asciiPtr++;					//pass the first char 'N'	
	decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);  //pass the space if there is
	if(isDigit(decDataPtr->asciiPtr))
	{
		decDataPtr->lineNumber = atoi(decDataPtr->asciiPtr); 	//turn the integer into true number
		decDataPtr->lineNumberValid = true; 	//true!!
	}
	else
	{

	}
	decDataPtr->asciiPtr = passDigit(decDataPtr->asciiPtr); //pass all the number after the 'N'
	decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);  //pass the space
	return 1;
}
int gFunction	(DEC_DATA  *decDataPtr)
{
	int gCmd;
	decDataPtr->markG = true;
	decDataPtr->asciiPtr++; 	//pass the first char 'G'
	decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);
	if(isDigit(decDataPtr->asciiPtr))
	{
		gCmd= atoi(decDataPtr->asciiPtr); 	//turn the integer into true number
	}
	else
	{

	}
	decDataPtr->asciiPtr = passDigit(decDataPtr->asciiPtr);
	decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);

	switch (gCmd)
	{
	case 0:
		decDataPtr->lineCmd = G00_RAPID_MOTION;
		decDataPtr->markG = false;
		if(*decDataPtr->asciiPtr=='G')
		{
			gFunction(decDataPtr);
		}

		break;
	case 1:
		decDataPtr->lineCmd = G01_MOTION_AT_FEED;
		decDataPtr->markG = false;
		if(*decDataPtr->asciiPtr=='G')
		{
			gFunction(decDataPtr);
		}

		break;

	case 4:
		decDataPtr->lineCmd = G04_DWELL_TIME;
		if(*decDataPtr->asciiPtr=='X')
		{
			decDataPtr->asciiPtr++;
			decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);
			if(isDigit(decDataPtr->asciiPtr))
			{
			decDataPtr->dwellTime= atoi(decDataPtr->asciiPtr);
			}
			decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);
			decDataPtr->asciiPtr = passFloat(decDataPtr->asciiPtr);	
		}
		else
		{

		}		
		break;

	case 90:
		decDataPtr->relAbs = false; //G90->false		
		break;
	case 91:
		decDataPtr->relAbs = true;	//G91->true	
		break;
	case 100:
		decDataPtr->lineCmd = G100_U;
		if(*decDataPtr->asciiPtr=='X')
		{
			decDataPtr->asciiPtr++;
			decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);
			if(isDigit(decDataPtr->asciiPtr))
			{
				decDataPtr->clockwise= atoi(decDataPtr->asciiPtr);
			}
			decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);
			decDataPtr->asciiPtr = passFloat(decDataPtr->asciiPtr);	
		}
		else
		{
		}
		break;
	case 101:
		decDataPtr->lineCmd = G101_V;
		if(*decDataPtr->asciiPtr=='X')
		{
			decDataPtr->asciiPtr++;
			decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);
			if(isDigit(decDataPtr->asciiPtr))
			{
				decDataPtr->clockwise= atoi(decDataPtr->asciiPtr);
			}
			decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);
			decDataPtr->asciiPtr = passFloat(decDataPtr->asciiPtr);	
		}
		else
		{
		}
		break;
	case 102:
		decDataPtr->lineCmd = G102_W;
		if(*decDataPtr->asciiPtr=='X')
		{
			decDataPtr->asciiPtr++;
			decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);
			if(isDigit(decDataPtr->asciiPtr))
			{
				decDataPtr->clockwise= atoi(decDataPtr->asciiPtr);
			}
			decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);
			decDataPtr->asciiPtr = passFloat(decDataPtr->asciiPtr);	
		}
		else
		{
		}
		break;

	default:
		decDataPtr->decState = DEC_ERROR;
	}
	return 1;
}
int fFunction	(DEC_DATA  *decDataPtr)
{
	decDataPtr->markF = false;
	decDataPtr->asciiPtr++;
	if(decDataPtr->lineCmd == G01_MOTION_AT_FEED)
	{
		decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);
		if(isDigit(decDataPtr->asciiPtr))
		{
			decDataPtr->speed= atoi(decDataPtr->asciiPtr);
		}
		decDataPtr->asciiPtr = passFloat(decDataPtr->asciiPtr);		
		decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);

	}
	else
	{
	}
	return 1;
}
int mFunction	(DEC_DATA  *decDataPtr)
{
	decDataPtr->markM = true;
	decDataPtr->asciiPtr++;
	if(isDigit(decDataPtr->asciiPtr))
	{
		decDataPtr->terminate = atoi(decDataPtr->asciiPtr);
	}


	if(decDataPtr->terminate == 0)
	{
		decDataPtr->lineCmd = M00;
	}

	if(decDataPtr->terminate == 1)
	{
		decDataPtr->lineCmd = M01;
	}
	if(decDataPtr->terminate == 30)
	{
		decDataPtr->lineCmd = M30_END;
		decDataPtr->decState = DEC_IDLE;
		fclose(decDataPtr->ncFilePtr);
	}
	decDataPtr->asciiPtr = passFloat(decDataPtr->asciiPtr);
	decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);
	return 1;
}
int coordFunction (DEC_DATA  *decDataPtr)   //還沒完成
{

	if(*decDataPtr->asciiPtr=='X' ||*decDataPtr->asciiPtr=='Y' ||*decDataPtr->asciiPtr=='Z' )
	{
		decDataPtr->xyzuvw =true;

	}
	if(*decDataPtr->asciiPtr=='U' ||*decDataPtr->asciiPtr=='V' ||*decDataPtr->asciiPtr=='W' )
	{
		decDataPtr->xyzuvw =false;
	}

	if(*decDataPtr->asciiPtr=='X' || *decDataPtr->asciiPtr=='U' )
	{
		if(decDataPtr->markX ==true)
		{
		}
		decDataPtr->markX = true;
		decDataPtr->asciiPtr++; 
		decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);
		if(isFloat(decDataPtr->asciiPtr))
		{
			decDataPtr->xyzCoordinate[0] = atof(decDataPtr->asciiPtr);
			decDataPtr->xyzValid[0] = true;
		}
		decDataPtr->asciiPtr = passFloat(decDataPtr->asciiPtr);
		decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);
	}

	if(*decDataPtr->asciiPtr=='Y' ||*decDataPtr->asciiPtr=='V' )
	{

		if(decDataPtr->markY ==true)
		{
		}
		decDataPtr->markY = true;
		decDataPtr->asciiPtr++; 
		decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);
		if(isFloat(decDataPtr->asciiPtr))
		{
			decDataPtr->xyzCoordinate[1] = atof(decDataPtr->asciiPtr);
			decDataPtr->xyzValid[1] = true;
		}
		decDataPtr->asciiPtr = passFloat(decDataPtr->asciiPtr);
		decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);
	}

	if(*decDataPtr->asciiPtr=='Z' ||*decDataPtr->asciiPtr=='W')
	{
		if(decDataPtr->markZ ==true)
		{
		}
		decDataPtr->markZ = true;
		decDataPtr->asciiPtr++; 
		decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);
		if(isFloat(decDataPtr->asciiPtr))
		{
			decDataPtr->xyzCoordinate[2] = atof(decDataPtr->asciiPtr);
			decDataPtr->xyzValid[2] = true;
		}
		decDataPtr->asciiPtr = passFloat(decDataPtr->asciiPtr);
		decDataPtr->asciiPtr = passSpace(decDataPtr->asciiPtr);
	}




	return 1;
}
int endOfLine	(DEC_DATA  *decDataPtr)
{

	return 1;
}







int decIdle	(DEC_DATA* decDataPtr)
{	

	if(decDataPtr->ncFileValid == true) 
	{
		decDataPtr->decState = DEC_OPEN_NC_FILE;
		
		decDataPtr->ncFileValid =false;
		decDataPtr->sysToDecBlock.ncFileValid=false;
		decDataPtr->linkDataPtr->sysToDecBlock.ncFileValid =false;
	}

	return 1;
}
int decOpenNCFile	(DEC_DATA* decDataPtr)  
{
	decDataPtr->ncFilePtr = fopen (decDataPtr->ncFileName,"r");
	if(decDataPtr->ncFilePtr != NULL )
	{
		fseek(decDataPtr->ncFilePtr, 0 , SEEK_SET);
		int startPosition = ftell(decDataPtr->ncFilePtr);

		fseek(decDataPtr->ncFilePtr, 0 , SEEK_END);
		int endPosition = ftell(decDataPtr->ncFilePtr);

		decDataPtr->fileSize =endPosition - startPosition;

		fseek(decDataPtr->ncFilePtr,0,SEEK_SET);


		decDataPtr->decState = DEC_PRE;
	}
	else
	{

	}
	
	return 1;
}
int decPre	(DEC_DATA* decDataPtr)
{
	if ( fgets(decDataPtr->line, 200, decDataPtr->ncFilePtr) == NULL)
	{
		decDataPtr->decState = DEC_ERROR;	
		return -1;	
	}
	else
	{
		decDataPtr->decState = DEC_LINE_LOOP;	
		decDataPtr->asciiPtr = decDataPtr->line;  // point at the first char
	}

	return 1;
}
int decLineLoop	(DEC_DATA* decDataPtr)
{
	while (decDataPtr->decState ==DEC_LINE_LOOP)
	{
		switch(*(decDataPtr->asciiPtr))
		{
			case 'N':
				nFunction(decDataPtr);
				break;
			case 'G':
				gFunction(decDataPtr);
				break;
			case 'F':
				fFunction(decDataPtr);
				break;
			case 'M':
				mFunction(decDataPtr);
				break;
			case 'X': case 'Y': case 'Z':
				coordFunction(decDataPtr);
				break;
			case 'U': case 'V': case 'W':
				coordFunction(decDataPtr);
				break;

			case '\0': case '\n':
				decDataPtr->decState = DEC_END_OF_LINE;
				break;
		}
	}
	decDataPtr->decState = DEC_END_OF_LINE;
	return 1;
}
int decEndOfLine (DEC_DATA* decDataPtr)
{
	decDataPtr->decState = DEC_WRITE_BLOCK;
	return 1;
}
int decWriteBlock (DEC_DATA* decDataPtr)
{
	decDataPtr->decToIntpBlockPtr->lineCmd = decDataPtr->lineCmd;
	decDataPtr->decToIntpBlockPtr->dwellTime = decDataPtr->dwellTime;
	decDataPtr->decToIntpBlockPtr->relAbs = decDataPtr->relAbs;
	decDataPtr->decToIntpBlockPtr->speed = decDataPtr->speed;
	decDataPtr->decToIntpBlockPtr->terminate = decDataPtr->terminate;
	decDataPtr->decToIntpBlockPtr->fileSize= decDataPtr->fileSize;
	decDataPtr->decToIntpBlockPtr->xyzuvw= decDataPtr->xyzuvw;
	decDataPtr->decToIntpBlockPtr->clockwise= decDataPtr->clockwise;
	for(int i = 0 ; i<3 ; i++)
	{
		decDataPtr->decToIntpBlockPtr->xyzCoordinate[i] = decDataPtr->xyzCoordinate[i];
		decDataPtr->decToIntpBlockPtr->xyzValid[i] = decDataPtr->xyzValid[i];
	}


	decDataPtr->decState = DEC_SENT_TO_FIFO;


	return 1;
}
int decSentToFIFO (DEC_DATA* decDataPtr)
{
	
	if(writeFIFO(&decDataPtr->linkDataPtr->decToIntpFifo.headBlock, &decDataPtr->decToIntpBlock) == true){
		if(decDataPtr->lineCmd == M30_END)
		{
			decDataPtr->decState = DEC_M30_WAIT;
		}
		else
		{
			decDataPtr->decState = DEC_PRE;
		}

		decDataPtr->dwellTime = 0;
		decDataPtr->relAbs = false;
		decDataPtr->speed = 0;
		decDataPtr->terminate = 0;
		decDataPtr->fileSize =  0;
		decDataPtr->lineCmd = NULL_CMD;
		decDataPtr->xyzCoordinate[0] = 0 ;
		decDataPtr->xyzCoordinate[1] = 0 ;
		decDataPtr->xyzCoordinate[2] = 0 ;
		decDataPtr->xyzValid[0] = false ;
		decDataPtr->xyzValid[1] = false ;
		decDataPtr->xyzValid[2] = false ;
		decDataPtr->xyzuvw = true ;
		decDataPtr->clockwise = false ;

		decDataPtr->decToIntpBlockPtr->dwellTime = 0;
		decDataPtr->decToIntpBlockPtr->relAbs = false;
		decDataPtr->decToIntpBlockPtr->speed = 0;
		decDataPtr->decToIntpBlockPtr->terminate = 0;
		decDataPtr->decToIntpBlockPtr->fileSize =  0;
		decDataPtr->decToIntpBlockPtr->lineCmd = NULL_CMD;
		decDataPtr->decToIntpBlockPtr->xyzCoordinate[0] = 0 ;
		decDataPtr->decToIntpBlockPtr->xyzCoordinate[1] = 0 ;
		decDataPtr->decToIntpBlockPtr->xyzCoordinate[2] = 0 ;
		decDataPtr->decToIntpBlockPtr->xyzValid[0] = false ;
		decDataPtr->decToIntpBlockPtr->xyzValid[1] = false ;
		decDataPtr->decToIntpBlockPtr->xyzValid[2] = false ;
		decDataPtr->decToIntpBlockPtr->clockwise = false ;

	}else
	{
		decDataPtr->decState = DEC_SENT_TO_FIFO;
	}
	

	return 1;
}
int decM30Wait	(DEC_DATA* decDataPtr)
{
	if(decDataPtr->linkDataPtr->startValid && decDataPtr->linkDataPtr->opMode == WHEEL_MODE)
	{
		decDataPtr->decState = DEC_IDLE;
	}

	if(decDataPtr->linkDataPtr->startValid && decDataPtr->linkDataPtr->opMode == HOME_MODE)
	{
		decDataPtr->decState = DEC_IDLE;
	}

	return 1;
}
int decError (DEC_DATA* decDataPtr)
{
	return 1;
}
