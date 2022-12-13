/*************************************************************************
*
*  FILE NAME    : driver.c
*
*  DESCRIPTION  : Perform the function of Driver
*
*  DATE     	 NAME  		  REFERENCE          REASON
*
*  24-NOV-2022  GROUP 7    	New       Initial Creation.
*
*  Copyright 2010, Aricent Technologies (Holdings) Ltd
*
**************************************************************************/

/*************************************************************************
*                               HEADER FILES
*************************************************************************/
#include <common.h>
#include <driver.h>

/******************************************************************************
*
*       Function Name   : driverMainMenu
*
*       Description     : Showing the menu in Driver Page
*
*       Returns         : Success 
*
*******************************************************************************/

int driverMainMenu()
{
	int ch = 0;
	printf("\n\t===============Customer Trip Menu==========\n");
	printf("\n\tPress,");
	printf("\n\t1. Update or Manage");
	printf("\n\t2. Check Booked cab details");
	printf("\n\t3. Mark complete trip");
	printf("\n\t4. Return Back to Main Menu");
	printf("\n\tChoice: ");
	scanf("%d",&ch);
	return ch;
}


/******************************************************************************
*
*       Function Name   : signUpDriver
*
*       Description     : This function use for Sing up the Driver
*
*       Returns         : Success 
*
*******************************************************************************/

DRIVER* signUpDriver(DRIVER *head,int * _id)
{
	int ch;
	DRIVER *newNode = NULL;
	DRIVER *tmpNode = NULL;
	tmpNode = head;

	newNode = (DRIVER*)malloc(sizeof(DRIVER));
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
	printf("\n\tEnter Driver Details,");
	printf("\n\tID: ");
	scanf("%d",&newNode->_id);
	printf("\n\tName: ");
	getchar();
	scanf("%[^\n]s", newNode->name);

	printf("\n\tGender: ");
	getchar();
	scanf("%c",&newNode->gender);
	printf("\n\tPhone Number: ");
	scanf("%d",&newNode->phone);
	printf("\n\tCAB Details");
	printf("\n\tChoose Car Model: ");
	printf("\n\t1. Alto ");
	printf("\n\t2. Mahindra");
	printf("\n\t3. Honda");
	printf("\n\tChoice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			strcpy(newNode->CAR.carModel,"Alto");
			break;
		case 2:
			strcpy(newNode->CAR.carModel,"Mahindra");
			break;
		case 3:
			strcpy(newNode->CAR.carModel,"Honda");
			break;
		default:
			strcpy(newNode->CAR.carModel,"Alto");

	}
	
	printf("\n\tCar Reg No: ");
	getchar();
	scanf("%[^\n]s",newNode->CAR.carRegNo);
	printf("\n\tUser Name: ");
	scanf("%s", newNode->dName);
	printf("\n\tPassword: ");
	scanf("%s",newNode->dPasswd);
	*_id = newNode->_id;
	return tmpNode;
}


/******************************************************************************
*
*       Function Name   : signInDriver
*
*       Description     : This function use for Sing in the Driver
*
*       Returns         : Success or Failure
*
*******************************************************************************/

int signInDriver(DRIVER *head)
{
	DRIVER _dri;
	int flag =0;
	printf("\n\tEnter User Name:");
	getchar();
	scanf("%[^\n]",_dri.dName);
	printf("\n\tEnter User Passwrd:");
	getchar();
	scanf("%[^\n]",_dri.dPasswd);
	while(head != NULL)
	{
		if((strcmp(head->dName, _dri.dName)==0)&&(strcmp(head->dPasswd, _dri.dPasswd)==0))
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
*       Function Name   : dispDriver
*
*       Description     : Display the driver
*
*       Returns         : Success 
*
*******************************************************************************/

void dispDriver(DRIVER *head)
{
	DRIVER _dd;
	printf("\n\tEnter driver id :");
	getchar();
	scanf("%d",&_dd._id);
	while(head != NULL)
	{
		if(head->_id == _dd._id)
		{
			printf("\n\tDriver ID:%d",head->_id);
			printf("\n\tDriver Name:%s",head->name);
			printf("\n\tGender:%c",head->gender);
			printf("\n\tPhone No:%d",head->phone);
			printf("\n\tCar Model:%s",head->CAR.carModel);
			printf("\n\tCar Reg No:%s",head->CAR.carRegNo);
			
		}
		head = head->next;
	}
}


/******************************************************************************
*
*       Function Name   : updateDDetails
*
*       Description     : This function used to update the details of driver
*
*       Returns         : Success 
*
*******************************************************************************/

int updateDDetails(DRIVER *head)
{
	DRIVER _dd;
	int flag = 0;
	int ch=0;
	printf("\n\tEnter your id to update:");
	getchar();
	scanf("%d",&_dd._id);
	while(head != NULL)
	{
		if(head->_id == _dd._id)
		{
			printf("\n\tChoose: ");
			printf("\n\t1. upadte name ");
			printf("\n\t2. update phone number");
			printf("\n\t3. update driver user name");
			printf("\n\t4. update driver passwrd");
			printf("\n\t5. update cab reg no");
			printf("\n\t6. Update car model");
			printf("\n\tChoice: ");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					printf("\n Enter name to update:");
					getchar();
					scanf("%[^\n]s",_dd.name);
					strcpy(head->name,_dd.name);
					break;
				case 2:
					printf("\n Enter phone number to update:");
					getchar();
					scanf("%d",&_dd.phone);
					head->phone = _dd.phone;
					break;
				case 3:
					printf("\n Enter user name to update:");
					getchar();
					scanf("%[^\n]s",_dd.dName);
					strcpy(head->dName,_dd.dName);
					break;
				case 4:
					printf("\n Enter user passwrd to update:");
					getchar();
					scanf("%[^\n]s",_dd.dPasswd);
					strcpy(head->dPasswd,_dd.dPasswd);
					break;
				case 5:
			       	        printf("\n\tUpdate Car Reg No: ");
					getchar();
					scanf("%[^\n]s",_dd.CAR.carRegNo);
					strcpy(head->CAR.carRegNo,_dd.CAR.carRegNo);
					break;
				case 6:
				        printf("\n\tUpdate Car Model: ");
					getchar();
					scanf("%[^\n]s",_dd.CAR.carModel);
					strcpy(head->CAR.carModel,_dd.CAR.carModel);
					break;
			}
			ch =0;
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
*       Function Name   : writeDriDetails
*
*       Description     : Writting driver details
*
*       Returns         : Success or Failure
*
*******************************************************************************/


int writeDriDetails(DRIVER* head)
{
	FILE *fp = NULL;

	fp = fopen("./data/driver.txt","w+");
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
		fprintf(fp," %d, %s, %c, %d, %s, %s, %s, %s\n",head->_id,head->name,head->gender,head->phone,head->CAR.carModel,head->CAR.carRegNo,head->dName, head->dPasswd);
		head = head->next;
	}
	fclose(fp);
	return 0;
	
}


/******************************************************************************
*
*       Function Name   : loadDriDetails
*
*       Description     : Loading Driver details
*
*       Returns         : Success 
*
*******************************************************************************/

DRIVER* loadDriDetails()
{
	FILE *fp = NULL;
	DRIVER *newNode = NULL;
	DRIVER *head = NULL;
	DRIVER *dri; 
	int _fSize = 0;
	char tmpBuff[1024] = {'\0', };
	
	fp = fopen("./data/driver.txt","r+");
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
				newNode = (DRIVER *)malloc(sizeof(DRIVER));
				newNode->next = NULL;
				head = newNode;
				dri = newNode;
				tokenizeDRIVER(newNode, tmpBuff);
						
			}
			else /* rest of the records */
			{
				newNode = (DRIVER *)malloc(sizeof(DRIVER));
				newNode->next = NULL;
				dri->next = newNode;
				tokenizeDRIVER(newNode, tmpBuff);
				dri = dri->next;	
			}
			memset(tmpBuff,'\0', MAX);
			

		}

	}

	fclose(fp);
	return head;
}


/******************************************************************************
*
*       Function Name   : tokenizeDRIVER
*
*       Description     : Tokenize the data by comma
*
*       Returns         : Success 
*
*******************************************************************************/

int tokenizeDRIVER(DRIVER *dri, char *tmpBuff)
{
	char *tokens;
	if(tmpBuff != NULL)
	{
		tokens = strtok(tmpBuff, ",");
		dri->_id = atoi(tokens);
		tokens = strtok(tmpBuff, ",");
		removeLeading(tokens,dri->name);
		tokens = strtok(tmpBuff, ",");
		dri->gender =  atoi(tokens);
		tokens = strtok(tmpBuff, ",");
		dri->phone = atoi(tokens);
		tokens = strtok(tmpBuff, ",");
		removeLeading(tokens,dri->CAR.carModel);
		tokens = strtok(tmpBuff, ",");
		removeLeading(tokens,dri->CAR.carRegNo);
		tokens = strtok(tmpBuff, ",");
		removeLeading(tokens,dri->dName);
		tokens = strtok(tmpBuff, ",");
		removeLeading(tokens,dri->dPasswd);

	}
	return 0;
}
