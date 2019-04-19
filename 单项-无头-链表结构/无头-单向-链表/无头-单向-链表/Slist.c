#include "Slist.h"

//初始化
void SListInit(SList * slist) {
	assert(slist != NULL);
	slist->head = NULL;
}


//头插
void SListPushFront(SList *slist, SListDataType value) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = slist->head;
	slist->head = node;
}
//尾插
void SListPushBack(SList *slist, SListDataType value) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
	//如果链表为空
	if (slist->head == NULL) {
		slist->head = node;
		return;
	}
	//链表中至少有一个结点
	Node* cur = slist->head;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = node;
}

//头删
void SListPopBack(SList *slist) {
	assert(slist != NULL && slist->head != NULL);
	Node* node = slist->head->next;
	free(slist->head);
	slist->head = node;
}

//尾删
void SListPopBack(SList *slist) {
	assert(slist != NULL && slist->head != NULL);
	//只有一个结点
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

//在链表中查找指定值
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

// 在链表pos位置后插入置为value的节点 
void SListInsertAfter(SList *slist, Node* pos, SListDataType value) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = pos->next;
	pos->next = node;
}
// 在链表pos位置后的结点
void EraseAfter(SList *slist, Node* pos) {
	Node* cur = pos->next->next;
	free(pos->next);
	pos->next = cur;
}
// 删除链表中值为 value 的节点 
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