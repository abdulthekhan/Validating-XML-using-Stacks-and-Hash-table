#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

extern char *  pop();
extern void push(char *);
extern int isEmpty();
extern void init();
extern void add(char *, int );
extern void printResult();

int main(int argc, char * argv[])
{
    int ch;
    char temp[100], temp2[100];
    init();
    
    while ((ch = getchar()) != EOF) 
	{
		if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
	    continue;
		else if(ch=='<')
		{
			ch  = getchar();
				if ((isalpha(ch)))
				{	
					char *str;
					int i=0;
				while(ch!='>')
				{
					temp[i]=ch;
					i++;
					ch= getchar();
		}
		temp[i]='\0';
		str =(char *) malloc(i);
		strcpy(str, temp);
		push(str);
		add(str,i);
		
	    }
	    else if(ch == '/')
		{		
		int i=0;
		ch  = getchar();
		
		while(ch!='>')
		{
		    temp[i]=ch;
		    ch=getchar();
		    i++;
		}
		temp[i]= '\0';
		if(isEmpty() != 0)
		{
		    strcpy (temp2, pop());
		    if(strcmp(temp, temp2) != 0)
			{
				printf("Not Valid\n");
				exit(1);
		    }
		}
		else
		{
		    printf(" Not Valid\n");
		    exit(1);
		}
	    }
	}
    }
    if(isEmpty() ==0)
	{
	    printf("Valid\n");
	    printResult();
	    exit(0);
    }
    printf("Not Valid\n");
    exit(1);
}