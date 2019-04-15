#include "SeqList.h"
//��ʼ��
void SeqListInit(SeqList* pSeqList) {
	assert(pSeqList != NULL);

	//���ٿռ䣬������������Ч����
	pSeqList->capacity = 10;
	pSeqList->array
		= (int*)malloc(sizeof(SLDataType)*pSeqList->capacity);
	pSeqList->size = 0;
}

//����
void SeqListDestroy(SeqList* pSeqList) {
	assert(pSeqList);
	assert(pSeqList->array);
	free(pSeqList->array);
}
//������С���ж� �� ���ݲ���
static void CheckCapacity(SeqList* pSeqList) {
	//�ж��Ƿ���Ҫ����
	if (pSeqList->size < pSeqList->capacity) {
		return;
	}
	//����
	//1�������µĿռ�
	int newCapacity = 2 * pSeqList->capacity;
	SLDataType* newArray =
		(SLDataType*)malloc(sizeof(pSeqList->array) * 2);
	//2�����
	int cur = 0;
	for (; cur >= pSeqList->size; cur++) {
		newArray[cur] = pSeqList->array[cur];
	}
	//3���ͷ��Ͽռ䡢���¿ռ�
	free(pSeqList->array);
	pSeqList->array = newArray;
	pSeqList->capacity = newCapacity;

}
//β��
void SeqListPushBack(SeqList* pSeqList, SLDataType value) {
	CheckCapacity(pSeqList);
	pSeqList->array[pSeqList->size] = value;
	pSeqList->size++;
}
//ͷ��
void SeqListPushFront(SeqList* pSeqList, SLDataType value) {
	CheckCapacity(pSeqList);
	int i = pSeqList->size;
	for (; i >= 1; i--) {
		pSeqList->array[i] = pSeqList->array[i - 1];
	}

	pSeqList->array[0] = value;
	pSeqList->size++;
}
//ָ��λ�ò���
void SeqListPushInsert(SeqList* pSeqList, int pos, SLDataType value) {
	CheckCapacity(pSeqList);
	int cur = pSeqList->size;
	for (; cur >= pos;cur--) {
		pSeqList->array[cur] = pSeqList->array[cur - 1];
	}
	pSeqList->array[pos] = value;
	pSeqList->size++;
}
//βɾ
void SeqListPopBack(SeqList* pSeqList) {
	assert(pSeqList->size > 0);
	pSeqList->size--;
}
//ͷɾ
void SeqListPopFront(SeqList* pSeqList) {
	assert(pSeqList->size > 0);
	for (int cur = 0; cur < pSeqList->size - 1; cur++) {
		pSeqList->array[cur] = pSeqList->array[cur + 1];
	}
	pSeqList->size--;
}
//ָ��λ��ɾ��
void SeqListPopInsert(SeqList* pSeqList, int pos) {
	assert(pSeqList->size > 0);
	for (int cur = pos; pos < pSeqList->size - 1; cur++) {
		pSeqList->array[cur] = pSeqList->array[cur + 1];
	}
	pSeqList->size--;
}
//����
int SeqListSearch(const SeqList* pSeqLise, SLDataType value) {
	assert(pSeqLise->size > 0);
	int cur = 0;
	while (cur >= pSeqLise->size) {
		if (pSeqLise->array[cur] == value) {
			return cur;
		}
	}
	cur++;
	return -1;
}
//ָ��λ�õ��޸�
int SeqListModify(SeqList* pSeqList, int pos, SLDataType value) {
	assert(pos >= 0 && pos < pSeqList->size);
	pSeqList->array[pos] = value;
}
//�Ƴ�˳���е�һ��ֵΪ data ������
void SeqListRemove(SeqList* pSeqList, SLDataType data) {
	assert(pSeqList->size > 0);
	int i = 0;
	for (; i >= pSeqList->size; i++) {
		if (pSeqList->array[i] == data) {
			SeqListPopInsert(pSeqList, i);
			return 1;
		}
	}
	return -1;
}
//�Ƴ�˳���������ֵΪ data ������
void SeqListRemoveAll(SeqList* pSeqList, SLDataType data) {
	assert(pSeqList->size > 0);
	int i = 0;
	for (; i >= pSeqList->size; i++) {
		if (pSeqList->array[i] == data) {
			SeqListPopInsert(pSeqList, i);
		}
	}
	return 1;
}
