#include "link_list.h"

struct Node* create(void)
{
	struct Node* phead=(struct Node*)malloc(sizeof(struct Node));
	phead->next=nullptr;
	return phead;
}

int IsEmpty(struct Node* phead)
{
	return phead->next==NULL;
}

int add(struct Node* phead)
{
	struct Node* p,* ptemp;
	p=(struct Node*)malloc(sizeof(struct Node));
	p->next=nullptr;
	//ptemp=phead->next;
	while(phead->next)	phead=phead->next;
	phead->next=p;

}
