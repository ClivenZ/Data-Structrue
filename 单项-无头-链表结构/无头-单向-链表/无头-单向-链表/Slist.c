#include "Slist.h"

//��ʼ��
void SListInit(SList * slist) {
	assert(slist != NULL);
	slist->head = NULL;
}


//ͷ��
void SListPushFront(SList *slist, SListDataType value) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = slist->head;
	slist->head = node;
}
//β��
void SListPushBack(SList *slist, SListDataType value) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
	//�������Ϊ��
	if (slist->head == NULL) {
		slist->head = node;
		return;
	}
	//������������һ�����
	Node* cur = slist->head;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = node;
}

//ͷɾ
void SListPopBack(SList *slist) {
	assert(slist != NULL && slist->head != NULL);
	Node* node = slist->head->next;
	free(slist->head);
	slist->head = node;
}

//βɾ
void SListPopBack(SList *slist) {
	assert(slist != NULL && slist->head != NULL);
	//ֻ��һ�����
	if (slist->head->next = NULL) {
		free(slist->head);
		slist->head = NULL;
		return;
	}
	Node* node = slist->head;
	while (node->next->next != NULL) {
		node = node->next;
	}
	free(node->next);
	node->next = NULL;
}

//�������в���ָ��ֵ
Node * SListFind(SList *slist, SListDataType value) {
	assert(slist != NULL);
	Node* node = slist->head;
	while (node->next != NULL) {
		if (node->value == value) {
			return node;
		}
		node = node->next;
	}
	return NULL;
}

// ������posλ�ú������Ϊvalue�Ľڵ� 
void SListInsertAfter(SList *slist, Node* pos, SListDataType value) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = pos->next;
	pos->next = node;
}
// ������posλ�ú�Ľ��
void EraseAfter(SList *slist, Node* pos) {
	Node* cur = pos->next->next;
	free(pos->next);
	pos->next = cur;
}
// ɾ��������ֵΪ value �Ľڵ� 
void SListErase(SList *slist, SListDataType value) {
	assert(slist != NULL);
	if (slist->head->next == NULL) {
		if (slist->head->value == value) {
			free(slist->head);
		}
		return;
	}
	Node* cur = slist->head;
	Node* arr = NULL;
	while (cur->next != NULL) {
		arr = cur->next;
		if (cur->value == value) {
			free(cur);
		}
		cur = arr;
	}
}