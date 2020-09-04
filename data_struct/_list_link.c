#include<stdio.h>
#include<stdlib.h>

#define nullptr (void*)0

struct Node;
typedef struct Node* List;
typedef List Position;


struct	Node
{
	int data;
	List next;
};

//创建头结点
List
create(void);

//destroy the list L
void
destroy(List L);
//返回true表示链表不为空，返回0表示链表为空
int
IsEmpty(List phead);

//添加新节点
int
add(List phead);

//return true if P is the last porsition in list
int
IsLast(Position P);

//return Position of X int L,NULL if not found
Position
Find(int X,List L);

//====================================================================

List create(void)
{
	List phead=(List)malloc(sizeof(struct Node));
	phead->next=nullptr;
	return phead;
}

void destroy(List L)
{
	List temp=L->next;
	while(temp)
	{
		free(temp);
		temp=L->next;
	}
}

int IsEmpty(List phead)
{
	return phead->next==NULL;
}

int add(List phead)
{
	List p,ptemp;
	p=(List)malloc(sizeof(struct Node));
	p->next=nullptr;
	//ptemp=phead->next;
	while(phead->next)	phead=phead->next;
	phead->next=p;

}

int
IsLast(Position P)
{
	return P->next==NULL;
}

Position
Find(int X,List L)
{
	
}

//===================================================================
int main(void)
{
	
	return 0;
}
