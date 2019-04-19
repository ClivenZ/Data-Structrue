#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//定义数据类型
typedef int SListDataType;

//定义结点
typedef struct ListNode {
	SListDataType value;
	struct ListNode* next;
} Node;

//定义第一个结点
typedef struct SList {
	Node* head;
} SList;

//初始化
void SListInit(SList * slist);
//头插
void SListPushFront(SList *slist, SListDataType value);
//尾插
void SListPushBack(SList *slist, SListDataType value);
//头删
void SListPopBack(SList *slist);
//尾删
void SListPopBack(SList *slist);
//在链表中查找指定值
Node * SListFind(SList *slist, SListDataType value);
// 在链表pos位置后插入置为value的节点 
void SListInsertAfter(SList *slist, Node* pos, SListDataType value);
// 在链表pos位置后的结点
void EraseAfter(SList *slist, Node* pos);
// 删除链表中值为value的节点 
void SListErase(SList *slist, SListDataType value);
