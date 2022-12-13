/***************************************************************************
*                       MACROS
***************************************************************************/
#ifndef CUST_H
#define CUST_H
#define MAX 1024
/***************************************************************************
*                       STRUCTURES
***************************************************************************/



typedef struct customer                  /*Structure of type Customer*/
{                          
	int _id;                         /*initialization of variables*/
	int phone;
	char name[20];
	char gender;
	char cName[20];
	char cPasswd[20];
	struct customer *next;

}CUST;
/***************************************************************************
*                       LOCAL FUNCTIONS
***************************************************************************/
int custMenu();                           /*Function call*/
CUST* signUpCust(CUST *,int *);
int signInCust(CUST *);
void dispCust(CUST *);
int writeCustDetails(CUST*);
CUST* loadCustDetails();
int tokenizeCUST(CUST *, char *);

#endif
/*END OF MACRO*/



