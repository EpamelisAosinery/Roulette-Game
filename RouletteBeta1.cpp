#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void showInstructions();
double getBetAmount();
void makeBet(int *, int *);
int spinWheel();
double figureWinnings(int, int, double, int);

int main()
{
	double bet_amount = 0, current_winnings;
	int main_choice, sub_choice;
	int number;
	char ch;

	/*
   	main_choice will be
	1 - for bet on specific number,	
	2 - odd/even ,	
	3 - dozen	
	   sub_choice will be	
	-the specific number when main_choice selected is 1
	-1 for option odd and 2 for option even , when main_choice selected is 2
	-1 for first 1-12 dozen, 2 for 13-24 dozen , 3 for 25-36 dozen, when main_choice is 3 */
	
	srand(time(NULL));
	showInstructions();

	while(1)
	{
	
		makeBet(&main_choice, &sub_choice);
		bet_amount = getBetAmount();		
		number = spinWheel();		
		printf("\n The number on the Roulette wheel is : %d", number);
	
		current_winnings = figureWinnings(main_choice, sub_choice, bet_amount, number);		
		
		if(current_winnings > 0)		
			printf("\n You win $%.2lf", current_winnings);		
		else		
			printf("\n You lost the bet !");
				  		
		printf("\n Do you wish to continue? y/n: ");		
		getchar(); //flush the newline		
		scanf("%c", &ch);		
		if(ch!='y' && ch != 'Y')		
			break;		
	}	
	printf("\n\n ********* Thank you for playing Roulette Game **********\n\n");
}

void showInstructions()
{
	printf("\n\t\t ****** Welcome to Roulette Game ******");	
	printf("\n\n Rules of the game - ");	
	printf("\n 1. You can bet on a specific number. In this case, payout is 36 times the bet amount.");	
	printf("\n 2. You can bet on odd or even number. In this case, payout is 2 times the bet amount.");	
	printf("\n 3. You can bet on a dozen, first 1-12, second 13-24, third 25 - 36. In this case, ");	
	printf("\n payout is 3 times the bet amount.");	
	printf("\n 4. The number zero does not count for odd or even or dozen, but can count as a number bet");	
	printf("\n\n Press <enter> to continue ... \n");
	
	getchar();

}

void makeBet(int *main_choice, int *sub_choice)
{
	int m, s;
	while(1)
	{
	printf("\n 1. Bet on a number");
	printf("\n 2. Bet on odd / even ");
	printf("\n 3. Bet on a dozen");
	printf("\n Enter your choice: ");
	scanf("%d", &m);
	if(m < 1 || m > 3)
		printf("\n Invalid menu choice !");
	else
		break;
	}
	switch(m)
	{
		case 1:	
			while(1)		
			{	
				printf("\n ------Betting on a number -------");		
				printf("\n Enter the number you want to bet on (0 - 36): ");			
				scanf("%d", &s);			
				if(s < 0 || s > 36)
				
					printf("\n Invalid number entered ! Try again...");			
				else			
					break;		
			}
			break;
	
		case 2:		
			while(1)		
			{		
				printf("\n ------Betting on odd / even -------");		
				printf("\n 1. Bet on odd");		
				printf("\n 2. Bet on even");		
				printf("\n Enter your choice (1-2): ");		
				scanf("%d", &s);		
				if(s < 1 || s > 2)		
					printf("\n Invalid choice entered ! Try again...");
				else		
					break;		
			}		
			break;
	
		case 3:	
			while(1)			
			{		
				printf("\n ------Betting on a dozen -------");				
				printf("\n 1. Bet on dozen 1 - 12");				
				printf("\n 2. Bet on dozen 13 - 24");			
				printf("\n 2. Bet on dozen 25 - 36");				
				printf("\n Enter your choice (1-3): ");				
				scanf("%d", &s);				
				if(s < 1 || s > 3)				
					printf("\n Invalid choice entered ! Try again...");				
				else				
					break;				
			}			
			break;		
	}	
	*main_choice = m;	
	*sub_choice = s;
}

double getBetAmount()
{
	double amt;
	while(1)
		{	
			printf("\n\n Enter bet amount: ");		
			scanf("%lf", &amt);
			if(amt < 1)		
				printf("\n Invalid bet amount ! Try again...");		
			else		
				break;	
		}	
	return amt;
}

int spinWheel()
{
	return ( rand() % 37); //return a number from 0-36
}

double figureWinnings(int main_choice, int sub_choice, double bet_amount, int number)
{
	double winnings = 0;
	if(main_choice == 1) //bet on a number
	{
		if(number == sub_choice)	
		winnings = 36 * bet_amount;
	}
	else if(main_choice == 2) //bet on odd/even
	{
		if((sub_choice == 1 && number % 2 == 1) || (sub_choice == 2 && number % 2 == 0) )
			winnings = 2 * bet_amount;
	}
	else //bet on dozen
	{	
		if((sub_choice == 1 && number >=1 && number <= 12) ||	
		   		(sub_choice == 2 && number >=13 && number <= 24) ||	
		   		(sub_choice == 3 && number >=25 && number <= 36) )
		
			winnings = 3 * bet_amount;
	}	
	return winnings;
}