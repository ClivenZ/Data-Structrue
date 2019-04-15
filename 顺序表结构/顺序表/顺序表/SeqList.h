#pragma once
#include <stdio.h>
#include <stdlib.h>
//静态顺序表
//typedef struct SeqList{
//	int array[1024];
//	int size;
//} SeqList;

//数据类型
typedef int SLDataType;


//动态顺序表
typedef struct SeqList {
 	SLDataType* array;   //指向堆上空间，存放数据
	int size;     //有效个数
	int capacity; //容量
}	SeqList;

//服务列表，函数列表
//创建 | 销毁
void SeqListInit(SeqList* pSeqList);

void SeqListDestroy(SeqList* pSeqList);

//增 删 查 改

//尾插
void SeqListPushBack(SeqList* pSeqList, SLDataType value);
//头插
void SeqListPushFront(SeqList* pSeqList,SLDataType value);
//指定位置插入
void SeqListPushInsert(SeqList* pSeqList,int pos,SLDataType value);

//尾删
void SeqListPopBack(SeqList* pSeqList);
//头删
void SeqListPopFront(SeqList* pSeqList);
//指定位置删除
void SeqListPopInsert(SeqList* pSeqList,int pos);

//查找
int SeqListSearch(const SeqList *pSeqLise, SLDataType value);
//指定位置的修改
int SeqListModify(SeqList* pSeqList, int pos, SLDataType value);

//移除顺表中第一个值为 data 的数据
void SeqListRemove(SeqList* pSeqList, SLDataType data);
//移除顺序表中所有值为 data 的数据
void SeqListRemoveAll(SeqList* pSeqList, SLDataType data);

//容量大小的判断 和 扩容操作
static void CheckCapacity(SeqList* pSeqList);