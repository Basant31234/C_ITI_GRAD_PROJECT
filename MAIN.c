#include <stdio.h>
#include"size.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>

#include"BANK_ACCOUNT_BASANT_G4.h"





void main(void)
{
	uint8 Choose_Window;
	uint8 MAIN_MENU=1;
	uint8 ADMIN_WINDOW=1;

	
		
	
	
	while (MAIN_MENU )
	{	
		system("cls");
		printf("\n\n=============WELCOME TO ITI BANK=============\n\n\n Please Choose Your Window :\n\n For Admin window      press[1]\n For Client window     press[2]\n For Close window      press[3]\n\n\nPlease Enter Your Choose : ");
		scanf(" %c",&Choose_Window);
		system("cls");

		switch (Choose_Window)
			{
				case '1':			Admin_Window();		break;
				case '2':			Client_window();	break;
				case '3':			MAIN_MENU=0;		break;
				
			}	
			
			
	}
		
	
}









