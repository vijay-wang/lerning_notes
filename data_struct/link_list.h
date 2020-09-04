#ifndef LINK_LIST_H__
#define LINK_LIST_H__
#include<stdio.h>
#include<stdlib.h>

struct Node;
typedef struct Node* List;

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
List create(void);

//返回true表示链表不为空，返回0表示链表为空
int IsEmpty(List phead);

//添加新节点
int add(List phead);

#end
