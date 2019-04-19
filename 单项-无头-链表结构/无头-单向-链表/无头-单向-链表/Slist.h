#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//������������
typedef int SListDataType;

//������
typedef struct ListNode {
	SListDataType value;
	struct ListNode* next;
} Node;

//�����һ�����
typedef struct SList {
	Node* head;
} SList;

//��ʼ��
void SListInit(SList * slist);
//ͷ��
void SListPushFront(SList *slist, SListDataType value);
//β��
void SListPushBack(SList *slist, SListDataType value);
//ͷɾ
void SListPopBack(SList *slist);
//βɾ
void SListPopBack(SList *slist);
//�������в���ָ��ֵ
Node * SListFind(SList *slist, SListDataType value);
// ������posλ�ú������Ϊvalue�Ľڵ� 
void SListInsertAfter(SList *slist, Node* pos, SListDataType value);
// ������posλ�ú�Ľ��
void EraseAfter(SList *slist, Node* pos);
// ɾ��������ֵΪvalue�Ľڵ� 
void SListErase(SList *slist, SListDataType value);
