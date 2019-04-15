#pragma once
#include <stdio.h>
#include <stdlib.h>
//��̬˳���
//typedef struct SeqList{
//	int array[1024];
//	int size;
//} SeqList;

//��������
typedef int SLDataType;


//��̬˳���
typedef struct SeqList {
 	SLDataType* array;   //ָ����Ͽռ䣬�������
	int size;     //��Ч����
	int capacity; //����
}	SeqList;

//�����б������б�
//���� | ����
void SeqListInit(SeqList* pSeqList);

void SeqListDestroy(SeqList* pSeqList);

//�� ɾ �� ��

//β��
void SeqListPushBack(SeqList* pSeqList, SLDataType value);
//ͷ��
void SeqListPushFront(SeqList* pSeqList,SLDataType value);
//ָ��λ�ò���
void SeqListPushInsert(SeqList* pSeqList,int pos,SLDataType value);

//βɾ
void SeqListPopBack(SeqList* pSeqList);
//ͷɾ
void SeqListPopFront(SeqList* pSeqList);
//ָ��λ��ɾ��
void SeqListPopInsert(SeqList* pSeqList,int pos);

//����
int SeqListSearch(const SeqList *pSeqLise, SLDataType value);
//ָ��λ�õ��޸�
int SeqListModify(SeqList* pSeqList, int pos, SLDataType value);

//�Ƴ�˳���е�һ��ֵΪ data ������
void SeqListRemove(SeqList* pSeqList, SLDataType data);
//�Ƴ�˳���������ֵΪ data ������
void SeqListRemoveAll(SeqList* pSeqList, SLDataType data);

//������С���ж� �� ���ݲ���
static void CheckCapacity(SeqList* pSeqList);