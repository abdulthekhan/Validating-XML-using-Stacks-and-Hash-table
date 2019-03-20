#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<string.h>

#define HASH_TABLE_SIZE 1057
typedef struct Entry Entry, *EntryPtr;
struct Entry 
{
  	char * string;
  	int count;
};
Entry hash_table[HASH_TABLE_SIZE];
void init (){
	int i;
	for (i=0; i<HASH_TABLE_SIZE; i++)
	{
		hash_table[i].count=0;
	}
}
void add(char * tag, int num)
{
	int sum = 0, i;
	
	for(i=0 ; i< num;i++)
	{
		sum+= tag[i];
	}
	int key;

	key= sum%HASH_TABLE_SIZE;
	if(hash_table[key].string != NULL)
	{
		if(strcmp(hash_table[key].string, tag) == 0)
		{
			hash_table[key].count++;
		}
		else 
		{
			while(hash_table[key].string!=NULL)
			{
				key++;
				if(hash_table[key].string != NULL)
				{
					if(strcmp(hash_table[key].string, tag) == 0)
					{
						hash_table[key].count++;
						break;
					}
				}
			}
		}
	}
	if(hash_table[key].string ==NULL)
	{
		hash_table[key].count++;
		hash_table[key].string=tag;
	}
}

void printResult()
{
	int k;
	for(k =0; k<HASH_TABLE_SIZE;k++)
	{
		if(hash_table[k].count!=0)
		{
			printf("%s %d \n", hash_table[k].string, hash_table[k].count);
		}
	}
}