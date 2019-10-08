#include <StdAfx.h>
#include "..\INC\util.h"

// GENERAL USE
//*****************************************************************

int delByteSpace(char *bytePtr, int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		*bytePtr=0; // byte for byte to clear memory
		bytePtr++;
	}
	return 1;
} //delByteSpace()


bool isDigit(char *charPtr)
{
	//test if is a digit one of 0, 1, 2... 9
	if(('0'<= *charPtr)&& (*charPtr <= '9'))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isFloat(char *charPtr)
{
	if((('0'<= *charPtr)&& (*charPtr <= '9')) || (*charPtr == '+')|| (*charPtr == '-'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

char *passSpace(char *charPtr)
{
	while(*charPtr == ' ' || *charPtr == '\t')
	{
		charPtr++;
	}
	return charPtr;
}
char *passDigit(char *charPtr)
{
	while(('0'<= *charPtr)&& (*charPtr <= '9'))
	{
		charPtr++;
	}
	return charPtr;
}
char *passFloat(char *charPtr)
{
	while((('0'<= *charPtr)&& (*charPtr <= '9')) || (*charPtr == '+')|| (*charPtr == '-')|| (*charPtr == '.'))
	{
		charPtr++;
	}
	return charPtr;
}


// FIFO
//*****************************************************************

void initFIFO(FIFO_HEAD* FIFOHeadPtr, FIFO_TYPE type)
{
	FIFOHeadPtr->type		= type;
	FIFOHeadPtr->rdIndex	= 0;
	FIFOHeadPtr->wrIndex	= 0;

	switch(type){
	case FIFO_TYPE::DEC_TO_INTP:
		FIFOHeadPtr->sizeInByte  = sizeof(DEC_TO_INTP_BLOCK);
		FIFOHeadPtr->sizeInBlock = DEC_TO_INTP_FIFO_LENGTH;

		for(int i = 0; i< 100 ; i++){
			((DEC_TO_INTP_FIFO*)FIFOHeadPtr)->decToIntpBlockValid[i]= false;
		}
		break;
	case FIFO_TYPE::OTHER_FIFO:
		FIFOHeadPtr->sizeInByte = sizeof(OTHER_BLOCK_FIFO);
		FIFOHeadPtr->sizeInBlock = DEC_TO_INTP_FIFO_LENGTH;

		for(int i=0 ; i< 100 ; i++)
		{
			((OTHER_BLOCK_FIFO*)FIFOHeadPtr)->otherFIFODataValid[i]=false;
		}
		break;
	default:
		break;
	}
}
bool writeFIFO(FIFO_HEAD* FIFOHeadPtr, void *blockPtr)
{
	switch(FIFOHeadPtr->type){
		case FIFO_TYPE::DEC_TO_INTP:
			if(((DEC_TO_INTP_FIFO*)FIFOHeadPtr)->decToIntpBlockValid[FIFOHeadPtr->wrIndex] == false) { 
				((DEC_TO_INTP_FIFO*)FIFOHeadPtr)->decToIntpBlockInfoHolder[FIFOHeadPtr->wrIndex] = *(DEC_TO_INTP_BLOCK*)blockPtr;
				((DEC_TO_INTP_FIFO*)FIFOHeadPtr)->decToIntpBlockValid[FIFOHeadPtr->wrIndex] = true;
				FIFOHeadPtr->wrIndex++;

				// IF FIFO IS FULL
				if(FIFOHeadPtr->wrIndex>= FIFOHeadPtr->sizeInBlock){
					FIFOHeadPtr->wrIndex = 0;
				}
				return true;
			} else
				return false;
		case FIFO_TYPE::OTHER_FIFO:
			if(((OTHER_BLOCK_FIFO*)FIFOHeadPtr)->otherFIFODataValid[FIFOHeadPtr->wrIndex] == false) {
				((OTHER_BLOCK_FIFO*)FIFOHeadPtr)->otherFIFOInfoHolder[FIFOHeadPtr->wrIndex] = *(OTHER_FIFO_DATA*)blockPtr;
				((OTHER_BLOCK_FIFO*)FIFOHeadPtr)->otherFIFODataValid[FIFOHeadPtr->wrIndex] = true;
				FIFOHeadPtr->wrIndex++;

				if(FIFOHeadPtr->wrIndex >= FIFOHeadPtr ->sizeInBlock){
					FIFOHeadPtr ->wrIndex = 0;
				}
				return true;
			} else
				return false;
	}
}


bool readFIFO(FIFO_HEAD* FIFOHeadPtr, void *blockPtr)
	{switch(FIFOHeadPtr->type) {
	case FIFO_TYPE::DEC_TO_INTP:
		if(((DEC_TO_INTP_FIFO*)FIFOHeadPtr)->decToIntpBlockValid[FIFOHeadPtr->rdIndex] == true) {
			*((DEC_TO_INTP_BLOCK*)blockPtr) = ((DEC_TO_INTP_FIFO*)FIFOHeadPtr)->decToIntpBlockInfoHolder[FIFOHeadPtr->rdIndex];
			((DEC_TO_INTP_FIFO*)FIFOHeadPtr)->decToIntpBlockValid[FIFOHeadPtr->rdIndex] = false;
			FIFOHeadPtr->rdIndex++;

			if(FIFOHeadPtr->rdIndex >= FIFOHeadPtr->sizeInBlock) {
				FIFOHeadPtr->rdIndex = 0;
			}

			return true;
		} else
			return false;
		break;
	case FIFO_TYPE::OTHER_FIFO:
		if(((OTHER_BLOCK_FIFO*)FIFOHeadPtr)->otherFIFODataValid[FIFOHeadPtr->rdIndex] == true) {
			*((OTHER_FIFO_DATA*)blockPtr) = ((OTHER_BLOCK_FIFO*)FIFOHeadPtr)->otherFIFOInfoHolder[FIFOHeadPtr->rdIndex];
			((OTHER_BLOCK_FIFO*)FIFOHeadPtr)->otherFIFODataValid[FIFOHeadPtr->rdIndex] = false;
			FIFOHeadPtr->rdIndex = false;

			if(FIFOHeadPtr->rdIndex >= FIFOHeadPtr->sizeInBlock) {
				FIFOHeadPtr->rdIndex = 0;
			}

			return true;
		} else
			return false;
		break;
	}
}
bool resetFIFO(FIFO_HEAD* FIFOHeadPtr)
{
	return true;
}


