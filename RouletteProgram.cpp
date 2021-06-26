/*
	Name: Hoa Ho
	Date: 27/03/21 19:51
	Description:  Roulete Program 
*/

#include<stdio.h>
#include <time.h>
#include <stdlib.h>

void showInstructions();
void makeBet(int *selectBetPtr, int *betTypePtr);
double getBetAmount();
int spinWheel();
double figureWinnings(int selectBet, int betType, double betMoney, int number);

int main()
{
	/*int number;
	srand(time(0));
	number = rand(); 
	number = (rand() % (max 36 - min 1 +1)) +min 1;*/

	int selectBet, betType, number;
	double betMoney = 0, profit;
	srand(time(0));	
	
	showInstructions();
	makeBet(&selectBet, &betType);
	betMoney = getBetAmount();
	
	number = spinWheel();
	printf("\n The number on the Roulette wheel is : %d", number);
	 
	profit = figureWinnings(selectBet, betType, betMoney, number);		
	
	if(profit > 0)		
		printf("\n You win $%.2lf", profit);		
	else		
		printf("\n You lost the bet !");
		
		
	return 0;
}

void showInstructions()
{
	printf("\n=========== Welcome to Roulette Game ===========");
	printf("\n--->Game Rules<---");
	printf("\n1. Bet on a specific number from range 0-36. Gain x36");
	printf("\n2. Bet on odd or even number. Gain x2");
	printf("\n3. Bet on a dozen number, first 1-12, second 13-24, third 25-36. Gain x3");
}

void makeBet(int *selectBetPtr, int *betTypePtr)
{
//	do
//	{
//		do
//		{
//			printf("\n\n\t--->Game Play<---");	
//			printf("\n\t 1. Bet on a number");
//			printf("\n\t 2. Bet on odd / even ");
//			printf("\n\t 3. Bet on a dozen");
//			printf("\n\nEnter your bet choice from [1-3]: ");
//			scanf("%d", selectBet);
//			clearerr(stdin);
//			if (selectBet<1 || selectBet>3)
//			{
//				printf("\nCharacters and float are not excepted! Please enter number in range of [1-3]");
//			}
//		}
		
//		while (selectBet<1 || selectBet>3 || ((status = getchar()) != EOF && status != '\n'))
//		{
//			clearerr(stdin);
//			do
//				status = getchar();
//			while (status != EOF && status != '\n');
//			clearerr(stdin);
//	        printf("\nCharacters and float are not excepted! Please enter number in range of [1-3]");
//	        printf("\nEnter the number of bet choice: ");
//	        scanf("%d", selectBet);
//		}
		
		
//	}while(selectBet<1 || selectBet>3);
	int selectBet, betType, status;
	while(1)
	{
		printf("\n\n\t--->Game Play<---");	
		printf("\n\t 1. Bet on a number");
		printf("\n\t 2. Bet on odd / even ");
		printf("\n\t 3. Bet on a dozen");
		printf("\n\nEnter your bet choice from [1-3]: ");
		scanf("%d", selectBetPtr);
		if(*selectBetPtr < 1 || *selectBetPtr > 3)
			printf("\n Invalid bet type. Enter from [1-3]");
		else
			break;
	}	
	switch(*selectBetPtr)
	{
		case 1:
		{
			while(1)		
			{	
				printf("\n=====You choose Bet on a specific number=====");
				printf("\nEnter the number that you want to bet on [1-36]: ");
				scanf("%d", betTypePtr);			
				if(*betTypePtr < 0 || *betTypePtr > 36)
				
					printf("\nIncorrect bet. Enter number in range of [1-36]");			
				else			
					break;		
			}
			break;
//			while (betAmount<1 || betAmount>36 || ((status = getchar()) != EOF && status != '\n'))
//			{
//				clearerr(stdin);
//				do
//					status = getchar();
//				while (status != EOF && status != '\n');
//				clearerr(stdin);
//		        printf("\nIncorrect number. Enter number in range of [1-36]");
//		        printf("\nEnter the number of bet choice: ");
//		        scanf("%d", betAmount);	
//			}
//			break;
		}
		case 2:
		{
			while(1)		
			{	
				printf("\n=====You choose Bet on odd/even number=====");
				printf("\n 1. Bet on odd");		
				printf("\n 2. Bet on even");		
				printf("\nEnter your bet choice [1-2]: ");		
				scanf("%d", betTypePtr);		
				if(*betTypePtr < 1 || *betTypePtr > 2)		
					printf("\nIncorrect bet. Enter [1-2] ");
				else		
					break;		
			}
			break;
		}
		
		case 3:
		{
			while(1)		
			{	
				printf("\n=====You choose Bet on dozen number=====");			
				printf("\n 1. First dozen 1 - 12");				
				printf("\n 2. Second dozen 13 - 24");			
				printf("\n 3. Third dozen 25 - 36");				
				printf("\nEnter your bet choice [1-3]: ");				
				scanf("%d", betTypePtr);				
				if(*betTypePtr < 1 || *betTypePtr > 3)				
					printf("\nIncorrect bet. Enter [1-3] ");				
				else				
					break;		
			}
			break;
		}
	}
}

double getBetAmount()
{
	double betMoney;
	while(1)
		{	
			printf("\n\nEnter the amount you want to bet: ");		
			scanf("%lf", &betMoney);
			if(betMoney < 1)		
				printf("\nIncorrect bet. Enter again. ");		
			else		
				break;	
		}	
	return betMoney;
}

int spinWheel()
{
	return (rand() % 37);
}

double figureWinnings(int selectBet, int betType, double betMoney, int number)
{
	double profit = 0;
	if(selectBet == 1) 
	{
		if(number == betType)	
		profit = 36 * betMoney;
	}
	else if(selectBet == 2)
	{
		if((betType == 1 && number % 2 == 1) || (betType == 2 && number % 2 == 0))
			profit = 2 * betMoney;
	}
	else
	{	
		if((selectBet == 1 && number >=1 && number <= 12) ||	
		   		(betType == 2 && number >=13 && number <= 24) ||	
		   		(betType == 3 && number >=25 && number <= 36) )
		
			profit = 3 * betMoney;
	}	
	return profit;
}