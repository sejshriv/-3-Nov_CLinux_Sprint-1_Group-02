/***********************************************************
** FILENAME : common.c
**
** DESCRIPTION: Perform the function for Main Menu Customer Menu Driver Menu 
**
** Revision History :
** DATE                NAME            REFERENCE          REASON
** ----------------------------------------------------------------------
** 24 NOV 2022         GROUP 7       	 New        Initial Creation
**
**
** Copyright @ 2019 Altran Group All Rights Reserved
**
***********************************************************/
#include <common.h>

/******************************************************************************
*
*       Function Name   : mainMenu
*
*       Description     : Display the Main Menu
*
*       Returns         : Success 
*
*******************************************************************************/

int mainMenu()
{
	int ch;
	printf("\n\t*******************************************************\n");
	printf("\n\t            WELCOME TO CAB MANAGEMENT SYSTEM           \n");
	printf("\n\t*******************************************************\n");
	printf("\n\t==================Main Menu========================\n");
	printf("\n\tEnter,");
	printf("\n\t1. Customer");
	printf("\n\t2. Cab Driver");
	printf("\n\t3. Exit");
	printf("\n\tChoice: ");
	scanf("%d",&ch);
	return ch;
}


/******************************************************************************
*
*       Function Name   : custMainMenu
*
*       Description     : Display the Customer Main Menu
*
*       Returns         : Success 
*
*******************************************************************************/

int custMainMenu()
{
	int ch;
	printf("\n\t==================Customer's Menu========================\n");
	printf("\n\tEnter,");
	printf("\n\t1. SignUp");
	printf("\n\t2. SignIn");
	printf("\n\t3. Exit");
	printf("\n\tChoice: ");
	scanf("%d",&ch);
	return ch;	
}

/******************************************************************************
*
*       Function Name   : driverMenu
*
*       Description     : Display the Driver Menu
*
*       Returns         : Success 
*
*******************************************************************************/


int driverMenu()
{
	int ch;
	printf("\n\t==================Driver's Menu========================\n");
	printf("\n\tEnter,");
	printf("\n\t1. SignUp");
	printf("\n\t2. SignIn");
	printf("\n\t3. Exit");
	printf("\n\tChoice: ");
	scanf("%d",&ch);
	return ch;
}

/******************************************************************************
*
*       Function Name   : removeLeading
*
*       Description     : Removing the space
*
*       Returns         : Success 
*
*******************************************************************************/

void removeLeading(char *str, char *str1)
{
    int idx = 0, j, k = 0;
 
    /* Iterate String until last */
    /* leading space character*/
    while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n')
    {
        idx++;
    }
 
    /* Run a for loop from index until the original */
    /* string ends and copy the content of str to str1*/
    for (j = idx; str[j] != '\0'; j++)
    {
        str1[k] = str[j];
        k++;
    }
 
    /* Insert a string terminating character */
    /* at the end of new string */
    str1[k] = '\0';
 
}

/******************************************************************************
*
*       Function Name   : removeTrailing
*
*       Description     : Removing the space
*
*       Returns         : Success 
*
*******************************************************************************/

void removeTrailing(char *str)
{
	if((str[strlen(str)-1] == ' ' || str[strlen(str)-1] == '\t' || str[strlen(str)-1] == '\n'))
    {
    	str[strlen(str)-1] = '\0';
    }

}

