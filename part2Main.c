#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

extern int pop();
extern void push(int);
extern int isEmpty();

int main(int argc, char * argv[]){
  	int ch, popped, i;
	int array[26] = {0};

	while ((ch = getchar()) != EOF) 
	{
		if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
		continue;
	
	    else if(ch =='<')
		{
			ch  = getchar();
			if ((isalpha(ch)))
			{
				push(ch);
				array[ch-97]++;
			}
			else if(ch == '/')
			{
				ch  = getchar();
				if(isEmpty())
				{
					exit(1);
				}
				popped = pop();
				if(popped != ch)
				{
					printf("Not Valid");
					exit(1);
				}
			}
		} 
	}
	if(!(isEmpty()))
	{
		printf("Not Valid");
		exit(1);
	}
	else
	{
		printf("Valid\n");
		for(i = 0;i<26; i++)
		{
			if(array[i]>0)
				printf("%c\t%d\n",i+97, array[i] );
		}
		exit(0);
	}
}