/***************************************************************************
*                       MACROS
***************************************************************************/
#ifndef TRIP_H
#define TRIP_H
#define MAX 1024
/***************************************************************************
*                       HEADER FILES
***************************************************************************/
#include <common.h>
#include <cust.h>
#include <driver.h>

typedef struct tripDetails                    /*Structure for trip Details*/
{
	int _tid;                             /*trip id,customer id,driver id,status,source,destination & travel date*/
	int _cid;             
	int _did;
	int status;
	char src[20];
	char dst[20];
	char tdate[30];
	struct tripDetails *next;

}TRIP;
/***************************************************************************
*                       LOCAL FUNCTIONS
***************************************************************************/

TRIP *bookTrip(TRIP *, int *);                 
int checkDrv(TRIP *, DRIVER*, int);              /*Functions call*/
int checkCab(TRIP *, DRIVER*, int);
void printBook(TRIP*, CUST*, DRIVER*, int);
void dispTrip(TRIP *);
int markCompleteTrips(TRIP *);
int writeTripDetails(TRIP* );
TRIP* loadTripDetails();
int tokenizeTRIP(TRIP *, char *);

#endif
/*END OF MACRO*/

