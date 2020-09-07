#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
#define nullptr (void*)0 

struct Node* DbList;
struct DbList Position;

struct Node
{
	DbList prior;
	int data;
	DbList next;
}
=====================================================================
DbList
InitDbList(void);

void
DeleteList(DbList L);

Position
Add(DbList L);

void
PrintList(DbList L);
======================================================================
DbList
InitDbList(void)
{
	 DbList P=(DbList)malloc(sizeof(struct Node));
	 P -> prior = P -> next = nullptr;
}

void
DeleteList(DbList L)
{
	DbList temp;
	while(L -> next)
	{
		temp = L -> next ->next;
		free(L -> next);
		L -> next = temp;
	}
	free(L);

}

Position
Add(DbList L)
{
	DbList P;
	P = malloc(sizeof(struct Node));
	L -> next = P;
	P -> prior = L;
	return P;
}

void
PrintList(DbList L)
{
	while(L -> next)
	{
		printf("第%d个元素",L -> next -> data);
		L -> next = L-> next -> next;
	}
}
=======================================================================
int main()
{
	DlList P = InitDbList();
	int i=100;
	while(i--)
		
	return 0;
}
