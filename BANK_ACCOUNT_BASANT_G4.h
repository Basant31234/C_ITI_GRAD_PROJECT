

#ifndef BANK_ACCOUNT_BASANT_G4_h
#define BANK_ACCOUNT_BASANT_G4_h



typedef struct client{
	
	uint8 name[30];
	uint8 address[50];
	uint64 nat_ID;
	uint16 age;
	uint64 bank_ID;
	uint64 Gua_ID;
	uint8 account_state[30];
	float32 balance;
	uint16 PASS;
	
	struct client * next;	
	
}node;





void Open_Existing_Account();								 //TO ENTER THE EXISTIG ACCOUNTS OPTIONS

void Client_window();										//TO ENTER THE CLIENT WINDOWS AND ITS CASES

void Admin_Window(); 										//TO ENTER THE ADMIN WINDOWS 

void Create_node(node** h_ptr_copy); 						//TO CREATE THE ACCOUNTS AND INITALISE THIER VALUES

void print_node(); 											//TO PRINT THE EXISTING ACCOUNTS

bool isCorrect_User( uint64 Client_ID_copy); 				//TO MAKE ADMIN CHECH IF THE ID OF CLIENT IS EXISTING .

bool isCorrect_CUSTOMER( uint64 USER_ID_Copy );  			//TO MAKE CLIENT CHECK IF HIS ENTRY ID IS CORRECT .

void MAKE_TRANSACTION( uint64 Client_ID_copy);				//TO MAKE TRANSACTION FROM THE ADMIN OR CLIENT MENUS .

void Change_Account_Status( uint64 Client_ID_copy);			//TO CHECK THE CLIENT'S ACCOUNT STATE.

void Get_Cash(uint64 Client_ID_copy );						//TO GET CASH FROM THE ADMIN OR CLIENT MENUS.

void Deposit_in_Account(uint64 Client_ID_copy );			//TO MAKE DEPOSITE FROM THE ADMIN OR CLIENT MENUS.

void Change_PASS(uint64 USER_ID);							//TO MAKE CLIENT CHANGE HIS PASSWORD.

uint64 node_length ();										//TO KNOW THE NUMBER OF CLIENTS.







#endif