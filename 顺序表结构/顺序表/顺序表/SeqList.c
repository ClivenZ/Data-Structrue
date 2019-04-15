#include "SeqList.h"
//初始化
void SeqListInit(SeqList* pSeqList) {
	assert(pSeqList != NULL);

	//开辟空间，设置容量，有效个数
	pSeqList->capacity = 10;
	pSeqList->array
		= (int*)malloc(sizeof(SLDataType)*pSeqList->capacity);
	pSeqList->size = 0;
}

//销毁
void SeqListDestroy(SeqList* pSeqList) {
	assert(pSeqList);
	assert(pSeqList->array);
	free(pSeqList->array);
}
//容量大小的判断 和 扩容操作
static void CheckCapacity(SeqList* pSeqList) {
	//判断是否需要扩容
	if (pSeqList->size < pSeqList->capacity) {
		return;
	}
	//扩容
	//1、创建新的空间
	int newCapacity = 2 * pSeqList->capacity;
	SLDataType* newArray =
		(SLDataType*)malloc(sizeof(pSeqList->array) * 2);
	//2、搬家
	int cur = 0;
	for (; cur >= pSeqList->size; cur++) {
		newArray[cur] = pSeqList->array[cur];
	}
	//3、释放老空间、绑定新空间
	free(pSeqList->array);
	pSeqList->array = newArray;
	pSeqList->capacity = newCapacity;

}
//尾插
void SeqListPushBack(SeqList* pSeqList, SLDataType value) {
	CheckCapacity(pSeqList);
	pSeqList->array[pSeqList->size] = value;
	pSeqList->size++;
}
//头插
void SeqListPushFront(SeqList* pSeqList, SLDataType value) {
	CheckCapacity(pSeqList);
	int i = pSeqList->size;
	for (; i >= 1; i--) {
		pSeqList->array[i] = pSeqList->array[i - 1];
	}

	pSeqList->array[0] = value;
	pSeqList->size++;
}
//指定位置插入
void SeqListPushInsert(SeqList* pSeqList, int pos, SLDataType value) {
	CheckCapacity(pSeqList);
	int cur = pSeqList->size;
	for (; cur >= pos;cur--) {
		pSeqList->array[cur] = pSeqList->array[cur - 1];
	}
	pSeqList->array[pos] = value;
	pSeqList->size++;
}
//尾删
void SeqListPopBack(SeqList* pSeqList) {
	assert(pSeqList->size > 0);
	pSeqList->size--;
}
//头删
void SeqListPopFront(SeqList* pSeqList) {
	assert(pSeqList->size > 0);
	for (int cur = 0; cur < pSeqList->size - 1; cur++) {
		pSeqList->array[cur] = pSeqList->array[cur + 1];
	}
	pSeqList->size--;
}
//指定位置删除
void SeqListPopInsert(SeqList* pSeqList, int pos) {
	assert(pSeqList->size > 0);
	for (int cur = pos; pos < pSeqList->size - 1; cur++) {
		pSeqList->array[cur] = pSeqList->array[cur + 1];
	}
	pSeqList->size--;
}
//查找
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
//指定位置的修改
int SeqListModify(SeqList* pSeqList, int pos, SLDataType value) {
	assert(pos >= 0 && pos < pSeqList->size);
	pSeqList->array[pos] = value;
}
//移除顺表中第一个值为 data 的数据
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
//移除顺序表中所有值为 data 的数据
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
