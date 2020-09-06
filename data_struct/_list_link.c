#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
CreateList(void);

//destroy the list L
void
DeleteList(List L);
//返回true表示链表不为空，返回0表示链表为空
int
IsEmpty(List phead);

//添加新节点,插入到链表最后，返回新元素的位置
Position
Add(int X,List phead);

//return true if P is the last porsition in list
int
IsLast(Position P);

//return Position of X int L,NULL if not found
Position
Find(int X,List L);

//Delete element X from L
Position
Delete(int X,List L);

void
PrintList(List L);

//Find the element that bofor X
//if X is not found,return NULL
//if X is found,return the element's position that befor X
Position
FindPrevious(int X,List L);

//insert (after leagal position P)
void
Insert(int X,List L);
//====================================================================

List
CreateList(void)
{
	List phead=(List)malloc(sizeof(struct Node));
	phead->next=nullptr;
	return phead;
}

void
DeleteList(List L)
{
	List P;
	while(L -> next)
	{
		P = L -> next -> next;
		free(L -> next );
		L -> next = P;
	}
	free(L);
}

int
IsEmpty(List phead)
{
	return phead->next==NULL;
}

Position
Add(int X,List phead)
{
	List P;
	P=(List)malloc(sizeof(struct Node));
	P->next=nullptr;
	P->data=X;
	//ptemp=phead->next;
	while(phead->next)	phead=phead->next;
	phead->next=P;
	return P;
}

int
IsLast(Position P)
{
	return P->next==NULL;
}

Position
Find(int X,List L)
{
	while(L->next&&L->next->data!=X)
		L = L->next;
	return	L->next;
}

Position
Delete(int X,List L)
{
	int count=0;
	List P;
	while(L->next && L->next->data != X)
		L = L -> next;
	if(L -> next)
	{
		P = L -> next -> next;
		free(L -> next);
		L ->next = P;
		return L;
	}	

}

void
PrintList(List L)
{
	int count = 0;
	List temp;
	while(L -> next )
	{
		printf("第%d个元素：%d\n",++count,L -> next ->data);
		L = L -> next;
	}
}

Position
FindPrevious(int X,List L)
{
	while(L -> next && L -> next -> data != X) L = L -> next;
	if(L -> next) return L;
	return L->next;

}

void
Insert(int X,Position P)
{
	List PX,temp;
	PX=malloc(sizeof(struct Node));
	PX->data=X;
	temp=P->next;
	P->next=PX;
	PX->next=temp;
}
//===================================================================
int main(void)
{
	List MyList = CreateList();
	int i=100;
	srand((unsigned int)time(NULL));
	while(i)
		Add(i--,MyList);
	PrintList(MyList);
	
	Delete(90,MyList);
	PrintList(MyList);
	Position P=Find(73,MyList);
	printf("找到的元素为：%d\n",P->data);
	P=FindPrevious(14,MyList);
	printf("14的前一个元素为：%d",P->data);
	Insert(2333,Find(3,MyList));
	PrintList(MyList);
	DeleteList(MyList);
	return 0;
}
