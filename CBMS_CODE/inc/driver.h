/***************************************************************************
*                       MACROS
***************************************************************************/
#ifndef DRIVER_H
#define DRIVER_H
#define MAX 1024
/***************************************************************************
*                       STRUCTURES
***************************************************************************/
typedef struct driver                    /*Structure of driver type*/
{
	int _id;
	int phone;
	char name[20];
	char gender;
	char dName[20];
	char dPasswd[20];
	struct carDetails                 /*Nested Structure*/          
	{
		char carModel[20];
		char carRegNo[20];
	}CAR;
	struct driver *next;
}DRIVER;
/***************************************************************************
*                       LOCAL FUNCTIONS
***************************************************************************/

DRIVER* signUpDriver(DRIVER*, int *);        /*Function call*/
int signInDriver(DRIVER *);
void dispDriver(DRIVER *);
int updateDDetails(DRIVER *);
int driverMainMenu();
int writeDriDetails(DRIVER* );
DRIVER* loadDriDetails();
int tokenizeDRIVER(DRIVER *, char *);

#endif
/*END OF MACROS*/


