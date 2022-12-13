/*************************************************************************
*
*  FILE NAME    : cust.c
*
*  DESCRIPTION  : Perform the function of Customer
*
*  DATE     	 NAME   	 REFERENCE          REASON
*	
*  24-NOV-2022  GROUP 7  		  New       Initial Creation.
*
*  Copyright 2010, Aricent Technologies (Holdings) Ltd
*
**************************************************************************/

/*************************************************************************
*                               HEADER FILES
*************************************************************************/
#include <common.h>
#include <cust.h>

/******************************************************************************
*
*       Function Name   : custMenu
*
*       Description     : Showing the menu in Customer Page 
*
*       Returns         : Success 
*
*******************************************************************************/

int custMenu()
{
	int ch = 0;
	printf("\n\t===============Customer Trip Menu==========\n");
	printf("\n\tPress,");
	printf("\n\t1. Book Trip");
	printf("\n\t2. Check Driver and Cab Details");
	printf("\n\t3. Print Booking Details");
	printf("\n\t4. Return Back to Main Menu");
	printf("\n\tChoice: ");
	scanf("%d",&ch);
	return ch;
}

/******************************************************************************
*
*       Function Name   : signUpCust
*
*       Description     : This function use for Sing up the customer
*
*       Returns         : Success 
*
*******************************************************************************/

CUST * signUpCust(CUST *head,int * _id)
{
	CUST *newNode = NULL;
	CUST *tmpNode = NULL;
	tmpNode = head;

	newNode = (CUST*)malloc(sizeof(CUST));
	newNode->next = NULL;
	
	if(head == NULL)
	{
		tmpNode = newNode;
		head = newNode;
	}
	else
	{
		while(head->next != NULL){
			head = head->next;
		}
		head->next = newNode;
		head = head->next;
	}

	printf("\n\tEnter Customer Details,");
	printf("\n\tID: ");
	scanf("%d",&newNode->_id);
	printf("\n\tName: ");
	getchar();
	scanf("%[^\n]s",newNode->name);
	printf("\n\tPhone Number: ");
	scanf("%d", &newNode->phone);
	printf("\n\tGender: ");
	getchar();
	scanf("%c",&newNode->gender);
	printf("\n\tUser Name: ");
	scanf("%s",newNode->cName);
	printf("\n\tPassword: ");
	scanf("%s",newNode->cPasswd);
	*_id = newNode->_id;

	return tmpNode;
}

/******************************************************************************
*
*       Function Name   : signInCust
*
*       Description     : This function use for Sing as the customer
*
*       Returns         : Success 
*
*******************************************************************************/

int signInCust(CUST *head)
{
	CUST _cust;
	int flag =0;
	printf("\n\tEnter User Name:");
	getchar();
	scanf("%[^\n]",_cust.cName);
	printf("\n\tEnter User Passwrd:");
	getchar();
	scanf("%[^\n]",_cust.cPasswd);
	while(head != NULL)
	{
		if((strcmp(head->cName, _cust.cName)==0)&&(strcmp(head->cPasswd, _cust.cPasswd)==0))
		{
			flag = 1;
			break;
		}
		head = head->next;
	}

	if(flag == 1)
		return 1;
	return 0;
}

/******************************************************************************
*
*              Function Name   : dispCust
*     
*		Description     : Display the customer
*
*		Returns         : Success 
*
*******************************************************************************/

void dispCust(CUST *head)
{
	while(head != NULL)
	{
		printf("\n\t%d",head->_id);
		head = head->next;
	}
}


/******************************************************************************
*
*		Function Name   : writeCustDetails
*       
*		Description     : Writting Customer details
*       
*		Returns         : Success 
*
*******************************************************************************/

int writeCustDetails(CUST* head)
{
	FILE *fp = NULL;

	fp = fopen("./data/cust.txt","w+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}
	fseek(fp, 0L, SEEK_END);
	if(head == NULL){
		printf("\n\t No Records Present\n");
		
	}
	while(head != NULL){
		fprintf(fp," %d, %s, %d, %c, %s, %s\n",head->_id,head->name,head->phone, head->gender, head->cName, head->cPasswd);
		head = head->next;
	}
	fclose(fp);
	return 0;
}

/******************************************************************************
*
*       Function Name   : loadCustDetails
*
*       Description     : Loading Customer details
*
*       Returns         : Success 
*
*******************************************************************************/

CUST* loadCustDetails()
{
	FILE *fp = NULL;
	CUST *newNode = NULL;
	CUST *head = NULL;
	CUST *cust; 
	int _fSize = 0;
	char tmpBuff[1024] = {'\0', };
	
	fp = fopen("./data/cust.txt","r+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return NULL;
	}

	fseek(fp, 0L, SEEK_SET);
	fseek(fp, 0L, SEEK_END);
	_fSize = ftell(fp);
	
	if(_fSize == 0) /* No records */
	{
		head = NULL;
	}
	else
	{
		fseek(fp, 0L, SEEK_SET);
		memset(tmpBuff,'\0', MAX);
		
		while(fgets(tmpBuff, MAX, fp)){
			
			if(head == NULL) /* first record */
			{
				newNode = (CUST *)malloc(sizeof(CUST));
				newNode->next = NULL;
				head = newNode;
				cust = newNode;
				tokenizeCUST(newNode, tmpBuff);
						
			}
			else /* rest of the records */
			{
				newNode = (CUST *)malloc(sizeof(CUST));
				newNode->next = NULL;
				cust->next = newNode;
				tokenizeCUST(newNode, tmpBuff);
				cust = cust->next;	
			}
			memset(tmpBuff,'\0', MAX);
			

		}

	}

	fclose(fp);
	return head;
}


/******************************************************************************
*
*       Function Name   : tokenizeCUST
*
*       Description     : Tokenise the data by comma
*
*       Returns         : Success 
*
*******************************************************************************/

int tokenizeCUST(CUST *cust, char *tmpBuff)
{
	char *tokens;
	if(tmpBuff != NULL){
		tokens = strtok(tmpBuff,",");
		cust->_id = atoi(tokens);
		tokens = strtok(tmpBuff,",");
		removeLeading(tokens,cust->name);
		tokens = strtok(tmpBuff,",");
		cust->phone = atoi(tokens);
		tokens = strtok(tmpBuff,",");
		cust->gender =  atoi(tokens);
		tokens = strtok(tmpBuff,",");
		removeLeading(tokens,cust->cName);
		tokens = strtok(tmpBuff,",");
		removeLeading(tokens,cust->cPasswd);
	}
	return 0;
}
