#ifndef LINK_LIST_H__
#define LINK_LIST_H__
#include<stdio.h>
#include<stdlib.h>

struct Stu
{
	int score;
	int stu_num;
	char name[12];
};

struct	Node
{
	struct Stu* data;
	Node* next;
};

//创建头结点
struct Node* create(void)
{
	struct Node* phead=(struct Node*)malloc(sizeof(struct Node));
	phead->next=nullptr;
	return phead;
}

//返回true表示链表不为空，返回0表示链表为空
bool isEmpty(struct Node* phead)
{
	if(phead->next)
		return true;
	return false;
}

//添加新节点
bool add(struct Node* phead)
{
	struct Node* p,* ptemp;
	p=(struct Node*)malloc(sizeof(struct Node));
	p->next=nullptr;
	//ptemp=phead->next;
	while(phead->next)	phead=phead->next;
	phead->next=p;

}
#endif
