#ifndef CNC_H
#define CNC_H

#include <stdio.h>

#include "../../DEC/INC/dec.h"
#include "../../INTP/INC/intp.h"
#include "../../MMI/INC/mmi.h"
#include "../../SYS/INC/sys.h"
#include "../../LINK/INC/link.h"
#include "../../UTIL/INC/util.h"

struct CNC_DATA
{
	DEC_DATA decData;
	DEC_DATA *decDataPtr;

	INTP_DATA intpData;
	INTP_DATA *intpDataPtr;

	MMI_DATA mmiData;
	MMI_DATA *mmiDataPtr;

	SYS_DATA sysData;
	SYS_DATA *sysDataPtr;

	LINK_DATA linkData;
	LINK_DATA *linkDataPtr;

	bool chart1bool;

	bool chart2bool1;
	bool chart2bool2;
	bool chart2bool3;
	bool chart2bool4;
	bool chart2bool5;

};

int cncInit         (CNC_DATA* cncDataPtr);
int cncRTCtl         (CNC_DATA* cncDataPtr);
int cncNRTCtl         (CNC_DATA* cncDataPtr);


#endif