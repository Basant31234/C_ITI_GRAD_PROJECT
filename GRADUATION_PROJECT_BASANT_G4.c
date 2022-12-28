#include<stdio.h>
#include"size.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>

#include"BANK_ACCOUNT_BASANT_G4.h"




node* ptr_head=NULL;


void Open_Existing_Account()
{	
	uint8 z=1;
	uint64 len;
	bool is_true;
	uint64 Client_ID;
	uint8 Existing_Account_operation;
	//system("cls");
	printf("\n\n\t=============EXISTING ACCOUNT=============\n\n");
	
	print_node();
	//len =node_length();
	//printf("%d",len);
	
	
	printf("\nClient Bank Account ID: ");
	scanf("%llu",&Client_ID);
	
	system("cls");
	
	is_true=isCorrect_User( Client_ID);
	
	if(	is_true == 1 )
	{
		printf("\n 1-Make Transaction\n 2-Change Account Status\n 3-Get Cash\n 4-Deposit in Account\n 5-Return to main menu\n\nPlease choose the Operation number : ");
		scanf(" %c",&Existing_Account_operation);
		system("cls");
		
		switch(Existing_Account_operation)
		{
			case '1':		MAKE_TRANSACTION( Client_ID ); 		break;
			case '2':		Change_Account_Status( Client_ID);	break;
			case '3':		Get_Cash(Client_ID);				break;
			case '4':		Deposit_in_Account( Client_ID);		break;
			case '5':		z=0;								break;
		}
	}
	
	else	
	{	printf("WRONG USER");	}
	
							
	
	
}


void Client_window()
{	
	uint8 USER_operation;
	uint64 USER_ID;
	bool is_true_CUS;
	uint8 z=1;
	
	printf("\n\n\nClient Bank Account ID: ");
	scanf("%llu",&USER_ID);
	
	is_true_CUS=isCorrect_CUSTOMER( USER_ID);
			
	if( is_true_CUS == 1 )
	{
		printf("\n 1-Make Transaction\n 2-Change Account Password\n 3-Get Cash\n 4-Deposit in Account\n 5-Return to main menu\n\nPlease choose the Operation number : ");
		scanf(" %c",&USER_operation);
		system("cls");
		switch(USER_operation)
		{
			
			case '1':		MAKE_TRANSACTION( USER_ID ); 		break;
			case '2':		Change_PASS( USER_ID);				break;
			case '3':		Get_Cash( USER_ID);					break;
			case '4':		Deposit_in_Account( USER_ID);		break;
			case '5':		z=0;								break;
			default:		printf("Please choose the operation number");

		}
	
	}
	else
	{
	}
	
}


void Admin_Window()
{
	uint8 Choose_Admin_Operation;
	uint8 ADMIN_WINDOW=1;
	uint8 Admin_NAME [15] = "basant kariem";
	uint16 Admin_Pass = 1234;
	uint8 Input_Admin_NAME [15];
	uint16 Input_Admin_Pass ;
	
	
	printf(" \n\n\n=============TO ENTER THE ADMIN============= \n\n\n\n Please insert the Admin UserName : ");
	scanf(" %[^\n]%*c",&Input_Admin_NAME);
	printf(" Please insert the Admin Password : ");
	scanf(" %hu",&Input_Admin_Pass);
	
	if ( ( 0 == strcmpi(Admin_NAME,Input_Admin_NAME ) ) && Admin_Pass==Input_Admin_Pass )		 //to check if the admin is correct
	{
		while( ADMIN_WINDOW )
		{	system("cls");	
			printf("\n\n=============ADMIN WINDOW=============\n");
			printf(" \n\n\n 1-Create New Accout\n 2-Open Existing account\n 3-Exit system\n\nPlease choose the Operation number : ");
			scanf(" %c",&Choose_Admin_Operation);
			system("cls");	
				
			switch(Choose_Admin_Operation)
			{
				case '1':		Create_node(&ptr_head);				break;
				case '2':		Open_Existing_Account();			break;					
				case '3':		ADMIN_WINDOW=0;						break;				
				default:	printf("\n\nPlease choose the operation number");
			}
	
		}
	}
	else
	{
		printf("\n\n SORRY , YOU CANOT ACCESS THE ADMIN WINDOW !!\n TO MAIN MENU ------> PRESS [0] ");	//to back to main menu
		scanf(" %c",&Choose_Admin_Operation);
	}
}



void Create_node(node** h_ptr_copy)
{
	uint8 name[30];
	uint8 address[50];
	uint16 age;
	uint64 Gua_ID=0;
	uint64 nat_ID=0;
	uint64  ID_copy;
	float32 balance;
	uint8 ADMIN_MENU;
	uint16 count;
	
	printf("\n\n\n=============CREATE NEW ACCOUNT=============\n\n");
	printf(" Please Enter The Client Date\n\n ");	
	
	printf(" Your name: ");	
	scanf(" %[^\n]%*c",&name); 
	
	printf("  Your address: ");	
	scanf(" %[^\n]%*c",&address);
	
	printf("  Your age: ");	
	scanf("%hu",&age);

	while ( (age < 0) || (age>90) )
	{
		printf("  YOUR AGE IS OUT OF RANGE !! Please try again\n  Your age: ");	
		scanf("%hu",&age);
	}
	
	
	if ( 21 > age && 0 < age)					 //to check if the client has a national id or need to enter the guardian national id
	{ 
		printf("  Your 14 Digit Guardian National ID: ");	
		scanf("%llu",&Gua_ID);
		
		do										//TO CHECK that the input Guardian National ID is 14 digit.
		{	count = 0;
			ID_copy = Gua_ID;
		
			while(ID_copy !=0)					
			{
				ID_copy /=10;
				count++;
			}
			
			if( count != 14 )
			{	
				printf("  Please try again \n Your 14  Guardian National ID: ");
				scanf("%llu",&Gua_ID);
			}
			
		}
		while ( count!= 14);
		}
	
	
	else
	{
		printf("  Your 14 Digit National ID: ");
		scanf("%llu",&nat_ID);
		
		do										//TO CHECK that the input National ID is 14 digit.
		{	count = 0;
			ID_copy = nat_ID;
		
			while(ID_copy !=0)					
			{
				ID_copy /=10;
				count++;
			}
			
			if( count != 14 )
			{	
				printf("  Please try again \n  Your 14  National ID: ");
				scanf("%llu",&nat_ID);
			}
			
		}
		while ( count!= 14);
		
	}


	printf("  Your Balance: ");
	scanf("%f",&balance);	

	printf("\n\n TO ADMIN MENU ------> PRESS [0] ");	//to back to main menu
	scanf(" %c",&ADMIN_MENU);
	
	
	// TO CREATE A NODE "CLIENT"
	
	node* first_address;
	first_address = ( node* ) calloc ( 1,sizeof(node) );
	node  *last = *h_ptr_copy;
	
	
	if( first_address !=NULL )
	{			 
		strcpy(	first_address -> name,name					);
		strcpy(	first_address -> address,address			);
		strcpy(	first_address -> account_state , "ACTIVE" 	);
		
		first_address -> nat_ID	 	   = nat_ID;
		first_address -> age  	 	   = age;
		first_address -> Gua_ID  	   = Gua_ID;
		first_address -> balance 	   = balance;
		
		srand(time(0));
		first_address -> bank_ID 	   = (rand() % (9999999999 - 1000000000 + 1)) + 1000000000;		 //RANDOM  10 DIGIT ID BANK
		first_address ->PASS		   = (rand() % (9999 - 1000 + 1)) + 1000; 						//RANDOM  4 DIGIT PASSWORD
	}
	
	
	if ( *h_ptr_copy == NULL )
	{
		*h_ptr_copy = first_address;
		return;
	}
	
	
	while (last->next != NULL)
		last = last->next;

	last->next = first_address;
	return ;
	
	
	
	
}



void print_node()
{	
	node* n=ptr_head;
	while( n != NULL )
		{	
			printf("\n\tName				: %s\n",    n ->name 	   		 );
			printf("\tAddress				: %s\n",    n ->address  		 );
			printf("\tNational ID			: %llu\n",  n ->nat_ID	 	 );
			printf("\tAge				: %hu\n",   n ->age  	  		 );
			printf("\tBank_ID				: %llu\n",  n ->bank_ID 	     );
			printf("\tAccount State			: %s\n",	 n ->account_state  );
			printf("\tGuardian National ID		: %llu\n",  n ->Gua_ID  	     );
			printf("\tBalance				: %0.1f\n", n ->balance  		 );
			printf("\tPASS				: %hu\n",	 n ->PASS  		 );
		    printf("\n\t==================================\n\n\n");
			n = n ->next;
		}	
	}
	
	
bool isCorrect_User( uint64 Client_ID_copy)
{	
	uint8 flag=1;
	uint8 ADMIN_MENU;
	node* head_copy = ptr_head;
	while( head_copy != NULL )
		{
			if( head_copy ->bank_ID == Client_ID_copy )
			{
				printf("\n\n\t=============WELCOME  %s=============\n\n", head_copy ->name );
				flag=0;
				return 1;
			}
			head_copy = head_copy ->next;
		}	
		if(flag==1)
		{
			printf("\n\n\t**WRONG USER !!**");
			printf("\n\n\t TO ADMIN MENU ------> PRESS [0] ");	//to back to main menu
			scanf(" %c",&ADMIN_MENU);
			return 0;
		}
		
}	
	

bool isCorrect_CUSTOMER( uint64 USER_ID_Copy )
{	
	uint8 flag=1;
	uint8 ADMIN_MENU;
	node* head_copy = ptr_head;
	uint16 PASSWORD;
	
	printf("Client Bank Account Password: ");
	scanf("%hu",&PASSWORD);
	
	while( head_copy != NULL )
		{
			if( (head_copy ->bank_ID == USER_ID_Copy) && (head_copy ->PASS == PASSWORD))
			{
				printf("\n\n**WELCOME : %s**\n\n", head_copy ->name );
				flag=0;
				return 1;
			}
			head_copy = head_copy ->next;
		}	
		if(flag==1)
		{
			printf("\n\n\t**WRONG USER !!**");
			printf("\n\n TO ADMIN MENU ------> PRESS [0] ");	//to back to main menu
			scanf(" %c",&ADMIN_MENU);
			return 0;
		}
		
}	
	

void MAKE_TRANSACTION( uint64 Client_ID_copy)	
	
{	
	
	printf("\n\n\t=============MAKE_TRANSACTION=============n\n\n");

	node* head_copy = ptr_head;
	node* head_copy_2 = ptr_head;
	
	uint64 bank_ID_TRANSFER;
	float32 Transaction_money;
	uint8 can_transfer=0;
	uint8 ADMIN_MENU;
	printf("Bank Account ID TO TRANSFER TO IT: ");
	scanf("%llu",&bank_ID_TRANSFER);
	
	printf("amount of money: ");
	scanf("%f",&Transaction_money);
	
	
	while( head_copy != NULL && can_transfer==0)
	{
		if( ((head_copy ->bank_ID )== Client_ID_copy ) && ((head_copy ->balance )>= Transaction_money ) && (strcmpi(head_copy -> account_state , "ACTIVE" ) == 0 ))
		{
			can_transfer=1;
		}
		
		else
		{
			head_copy = head_copy ->next;
		}
	}
	
	while((( head_copy_2) != NULL) && (can_transfer==1) && (strcmpi(head_copy_2 -> account_state , "ACTIVE" ) == 0 ))
	{
	
		if( head_copy_2 ->bank_ID == bank_ID_TRANSFER  && can_transfer==1)
		{
				(head_copy   ->balance) -= Transaction_money;
				(head_copy_2 ->balance) += Transaction_money;
				printf("Balance of 			  : %0.1f\n", head_copy ->balance  		 );
				printf("Balance 			  : %0.1f\n", head_copy_2 ->balance  		 );
				can_transfer=0;
				printf("***THE Transaction IS DONE SUCCESSFULLY***\n\n");
		}
		
		else
		{
		head_copy_2 = head_copy_2 ->next;
		}
	}	
		
	
	printf("\n\n TO ADMIN MENU ------> PRESS [0] ");	//to back to main menu
	scanf(" %c",&ADMIN_MENU);
	
	
}
	
	
void Change_Account_Status( uint64 Client_ID_copy)
{
	uint8 account;
	uint8 ADMIN_MENU;
	printf("\n\n\t=============CHANGE ACCOUNT STATUS=============\n");
	
	node* head_copy_2 = ptr_head;
	
	while (( head_copy_2 != NULL) && ((head_copy_2 ->bank_ID )!= Client_ID_copy))
	{
		head_copy_2 = head_copy_2 ->next;
	
	}
		
	if( head_copy_2 -> bank_ID == Client_ID_copy)
	{
		printf(" \n 1- Set Account to Active State\n 2- Set Account to Restricted State\n 3- Set Account to Closed\n\n Please choose the Operation number : ");
		scanf(" %c",&account);
		
		switch (account)
		{
			case '1':
		
				strcpy(head_copy_2 -> account_state , "ACTIVE" );
				printf("\n\tYOUR ACCOUNT IS ACTIVATED.");
				break;

			case '2':
				
				strcpy(head_copy_2 -> account_state , "RESTRICTED" );
				printf("\n\tYOUR ACCOUNT IS RESTRICTED.");
				break;
			
			
			case '3':
				strcpy(head_copy_2 -> account_state , "CLOSED" );
				printf("\n\tYOUR ACCOUNT IS CLOSED.");
				break;
			
			default:
				printf(" PLEASE CHOOSE THE RIGHT NUMBER FOR THE OPERATION !");
				
		}
		
		
			
	}
	
	printf("\n\n TO ADMIN MENU ------> PRESS [0] ");	//to back to main menu
	scanf(" %c",&ADMIN_MENU);
	
	
}
	

void Get_Cash(uint64 Client_ID_copy )
{	

	printf("\n\n\t=============GET CASH=============\n");
	
	float32 get_money;
	node* head_copy_2 = ptr_head;
	uint8 ADMIN_MENU;
	
	printf("\n\n Please Enter The Amount Of Money: ");
	scanf("%f",&get_money);
	
	
	while (( head_copy_2 != NULL) && (head_copy_2 ->bank_ID )!= Client_ID_copy )
	{
		head_copy_2 = head_copy_2 ->next;
	}
	
	if( head_copy_2 -> balance >= get_money && ((strcmpi(head_copy_2 -> account_state , "ACTIVE")) ==0))
	{	
		head_copy_2->balance -= get_money;
		printf("\n\t THE TRASFERRING IS SUCCESSFULLY DONE !");
	}
	else
	{
		printf("\n\t THE TRASFERRING IS FAILED!");
	}
	
	printf("\n\n TO ADMIN MENU ------> PRESS [0] ");	//to back to main menu
	scanf(" %c",&ADMIN_MENU);
}
	

	
void Deposit_in_Account(uint64 Client_ID_copy )
{
	printf("\n\n\t=============DEPOSIT IN ACCOUNT=============\n");
	
	float32 add_money;
	node* head_copy_2=ptr_head;
	uint8 ADMIN_MENU;
	
	printf("\n\n Please Enter The Added Money: ");
	scanf("%f",&add_money);
	
	
	while (( head_copy_2 != NULL) && (head_copy_2 ->bank_ID )!= Client_ID_copy )
	{
		head_copy_2 = head_copy_2 ->next;
	}
	
		if( (strcmpi(head_copy_2 -> account_state , "ACTIVE")) ==0)
		{
			head_copy_2->balance += add_money;
			printf("\n\t ADDING CASH IS SUCCESSFULLY DONE !");
		}
		else
		{
			printf("\n\t ADDING CASH IS FAILED !");
		}
	
	printf("\n\n TO ADMIN MENU ------> PRESS [0] ");	//to back to main menu
	scanf(" %c",&ADMIN_MENU);
}
	
	
	
void Change_PASS(uint64 USER_ID)
{
	
	printf("\n\n\t=============CHANGE PASSWORD=============\n");
	
	uint16 Old_Password;
	uint8 ADMIN_MENU;
	node* head_copy_2=ptr_head;
	
	printf("Please Enter The Old Password:");
	scanf("%hu",&Old_Password);
	

	while (( head_copy_2 != NULL) && ((head_copy_2 ->bank_ID )!= USER_ID ))
	{
		head_copy_2 = head_copy_2 -> next;
	}

	
	if( (head_copy_2 -> PASS) == Old_Password)
	{	
		printf("Please Enter The New Password: ");
		scanf("%hu", &(head_copy_2 -> PASS));
		printf("THE PASSWORD IS CHANGED SUCCESsSFULLY  !");
	}
	else
	{
		printf("THE PASSWORD IS NOT CORRECT !");
	}
	
	printf("\n\n TO ADMIN MENU ------> PRESS [0] ");	//to back to main menu
	scanf(" %c",&ADMIN_MENU);
}
	
 
uint64 node_length ()
{
	uint64 length=1; //to count the last node.
	node * h_ptr = ptr_head;
	if (h_ptr == NULL)
	{
		return 0;
	}
	
	node* temp = h_ptr;
	while((temp -> next) != NULL)
	{
		length++;
		
		temp = (temp -> next);
	}
	
	return length;
}











