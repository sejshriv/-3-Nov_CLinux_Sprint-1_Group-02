 /*************************************************************************
*
*  FILE NAME    : main.c
*
*  DESCRIPTION  : Main method of the Program
*
*  DATE      		NAME   		 REFERENCE          REASON
*
*  24-NOV-2022      GROUP 7   	New			   Initial Creation.
*
*  Copyright 2010, Aricent Technologies (Holdings) Ltd
*
**************************************************************************/

/*************************************************************************
                               MAIN FILES
*************************************************************************/
#include <common.h>
#include <cust.h>
#include <driver.h>
#include <trip.h>
/******************************************************************************
*
*       Function Name   : main
*
*       Description     : Calling all the function in main method
*
*       Returns         : Success 
*
*******************************************************************************/
int main()
{
	int ch = 0;
	int retVal = 1, flag=0;
        int _id;
	CUST *cc = NULL;
	CUST *headC = NULL;
	DRIVER *dd = NULL;
	DRIVER *headD = NULL;
	TRIP *tt= NULL;
	TRIP *headT = NULL;
	headC = loadCustDetails(cc);/*loading driver details from custmer detais*/
	headD = loadDriDetails(dd);/*loading Customer details from Driver details*/
        headT = loadTripDetails(tt);/*loading Customer details from Trip details*/
	while(1){
		ch = mainMenu();
		switch(ch)
		{
		      case 1:
				while(1)
				{
						ch = custMainMenu();
						switch(ch)
						{
							case 1:
								headC = signUpCust(headC,&_id);
								writeCustDetails(headC);
								break;
							case 2:
							    if(signInCust(headC) == 0)
								{
                       			                	printf("\n\tUser/password does not match db\n");
                                           
                    			                        }
								else
								{	
									
									if(retVal == 1)
									{
										while(1){
											ch = custMenu();
											switch(ch)
											{
												case 1:
													headT = bookTrip(headT,&_id);
													writeTripDetails(headT);
			  										printf("\n\tYour Booking is confirmed with following details\n");
	                  										printBook(headT, headC,headD, _id);
													break;
												case 2:
													dispDriver(headD);
													break;
													
												case 3:
													printf("\n\tEnter the Booking ID: ");
													scanf("%d",&_id);
													printBook(headT, headC,headD, _id);
													break;
												case 4:
													flag = 1; 
													break;
												default:
													printf("\nWrong Choice\n");

											}
										if(flag == 1)
										{
											flag = 0;
											break;
										}
									}
								}
								}
								break;
							case 3:
								writeCustDetails(headC);
								flag = 1;
								break;
							default:
								printf("\n\tSomething went wrong");
						}
					if(flag == 1)
					{
						flag = 0;
						break;
					}
				}
				break;
			case 2:
				ch = driverMenu();
				switch(ch)
				{
					case 1:
						headD = signUpDriver(headD,&_id);
						writeDriDetails(headD);
						break;
					case 2:
						if(signInDriver(headD) == 0)
						{
                       		printf("\n\tUser/password does not match db\n");

                    	}
						else
						{	
								
								if(retVal == 1)
								{
									while(1){
										ch = driverMainMenu();
										switch(ch)
										{
											case 1:
												updateDDetails(headD);
												dispDriver(headD);
												break;
											case 2:
												dispTrip(headT);
												break;
											case 3:
												markCompleteTrips(headT);
												break;
											case 4:
												flag = 1; 
												break;
											default:
												printf("\nWrong Choice\n");

										}
										if(flag == 1)
										{
											flag = 0;
											break;
										}
									}
							}
						}
							break;
					case 3:
						dispDriver(headD);
						writeDriDetails(headD);
						printf("\n\tReturning Back to MainMenu");
						break;
					default:
						printf("\n\tSomething went wrong");
				}
				
				break;
			case 3:
				printf("\n\t************************************\n");
				printf("\n\t             Thank You             \n\n");
				printf("\n\t**************************************\n");
				exit(EXIT_SUCCESS);
			default:
				printf("\n\tWrong Choice\n");

		}	
	}
	
	
	printf("\n\n");

	return 0;

}
