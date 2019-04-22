#include "BinaryTreeh.h"


//����������
BTNode* CreateBinTree(BTDataType* value, int size) {

}
//����������
BTNode* CopyBinTree(BTNode* root) {

}
// ���ٶ����� 
void DestroyBinTree(BTNode** root) {

}

//�ݹ����
//ǰ�����   �� ������ ������
void PreorderTraversal(BTNode* root) {
	if (root == NULL) {
		return;
	}
	printf("%s ",root->value);
	PostorderTraversal(root->left);
	PostorderTraversal(root->right);
}

//�������   ������ �� ������
void InorderTraversal(BTNode* root) {
	if (root == NULL) {
		return;
	}
	InorderTraversal(root->left);
	printf("%s ",root->value);
	InorderTraversal(root->right);
}

//�������   ������ ������ ��
void PostorderTraversal(BTNode* root) {
	if (root == NULL) {
		return;
	}
	PostorderTraversal(root->left);
	PostorderTraversal(root->right);
	printf("%s ", root->value);
}

//�ǵݹ����
//ǰ�����
void PreOrderNor(BTNode* root) {

}
//�������
void InOrderNor(BTNode* root) {

}
//�������
void PostOrderNor(BTNode* root) {

}

//�������
void LevelOrder(BTNode* root) {

}

//��������Ľڵ����
int count = 0;
void GetNodeCount1(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	count++;
	GetNodeCount1(root->left);
	GetNodeCount1(root->right);	
}
//����
int GetNodeCount2(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	int left = GetNodeCount2(root->left);
	int right = GetNodeCount2(root->right);
	return left + right + 1;
}
// ��������ĸ߶� 
int Height(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	int left = Height(root->left);
	int right = Height(root->left);
	return (left > right ? left : right) + 1;
}
// ��ȡ��������Ҷ�ӽڵ�ĸ��� 
int GetLeafNodeCount(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	int left = GetLeafNodeCount(root->left);
	int right = GetLeafNodeCount(root->right);

	return left + right;
}

// ��������ľ��� 
void Mirror(BTNode* root) {

}