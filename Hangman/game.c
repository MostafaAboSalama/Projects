#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>  
#include <time.h>

#include "english_words.h"

int game(void);

extern const char *englishWords[];

int main()
{
	game();
	
	return 0;
}


int game(void)
{
	srand(time(NULL));
    int randomNumber = rand() % 101; 
   // printf("Random number: %d\n", randomNumber);
	//printf("%s\n", englishWords[randomNumber]);
	//printf("%d\n", strlen(englishWords[randomNumber]));
	printf("\nHangman Game\n\n");
	char size = strlen(englishWords[randomNumber]);
	char* answer = (char*)malloc(size * sizeof(char));
	for(int i=0; i<size; i++)
	{
		answer[i] = '-';
	}
	answer[size] = '\0';
	printf("(%s)\n", answer);
	char ch;
	int count = 0;
	
	while(count < 10)
	{
		printf("\nEnter a character : ");
		ch = getch(); // use gethchar();
		for(int i=0; i<size; i++)
		{
			if(englishWords[randomNumber][i] == ch)
			{
				answer[i] = ch;
			}
		}
		printf("\n\n(%s)\n", answer);
		
		if(strcmp(answer, englishWords[randomNumber]) == 0)
		{
			printf("\nWIIIIIN\n");
			return 1;
		}
		
		printf(" ______________\n");
		printf("|              |\n");
		printf("| %d tries left |\n", (9-count));
		//printf("|             |\n");
		printf("|______________|\n");
		count++;
	}
	
	if(count == 10)
	{
		printf("\nMan is Executed :(	\"Answer was %s\".\n",englishWords[randomNumber]);
		//printf("Answer was %s.\n",englishWords[randomNumber]); 
	}
	
	
	return 0;
}

