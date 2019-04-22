#include<stdio.h>
#include<stdlib.h>


//������������
typedef char BTDataType;

//�ṹ�嶨��
typedef struct BTNode {
	int value;
	struct BTNode *left;		//����
	struct BTNode *right;		//�Һ���
} BTNode;

//����������
BTNode* CreateBinTree(BTDataType* value, int size);
//����������
BTNode* CopyBinTree(BTNode* root);
// ���ٶ����� 
void DestroyBinTree(BTNode** root);

//�ݹ����
//ǰ�����   �� ������ ������
void PreorderTraversal(BTNode* root);
//�������   ������ �� ������
void InorderTraversal(BTNode* root);
//�������   ������ ������ ��
void PostorderTraversal(BTNode* root);

//�ǵݹ����
//ǰ�����
void PreOrderNor(BTNode* root);
//�������
void InOrderNor(BTNode* root);
//�������
void PostOrderNor(BTNode* root);

//�������
void LevelOrder(BTNode* root);

//��������Ľڵ����
void GetNodeCount1(BTNode* root);
int GetNodeCount2(BTNode* root);

// ��������ĸ߶� 
int Height(BTNode* root);

// ��ȡ��������Ҷ�ӽڵ�ĸ��� 
int GetLeafNodeCount(BTNode* root);

// ��ȡ��������K��ڵ�ĸ��� 
int GetKLevelNodeCount(BTNode* root, int K);

// ��������ľ��� 
void Mirror(BTNode* root);