#include "BinaryTreeh.h"


//创建二叉树
BTNode* CreateBinTree(BTDataType* value, int size) {

}
//拷贝二叉树
BTNode* CopyBinTree(BTNode* root) {

}
// 销毁二叉树 
void DestroyBinTree(BTNode** root) {

}

//递归遍历
//前序遍历   根 左子树 右子树
void PreorderTraversal(BTNode* root) {
	if (root == NULL) {
		return;
	}
	printf("%s ",root->value);
	PostorderTraversal(root->left);
	PostorderTraversal(root->right);
}

//中序遍历   左子树 根 右子树
void InorderTraversal(BTNode* root) {
	if (root == NULL) {
		return;
	}
	InorderTraversal(root->left);
	printf("%s ",root->value);
	InorderTraversal(root->right);
}

//后序遍历   左子树 右子树 根
void PostorderTraversal(BTNode* root) {
	if (root == NULL) {
		return;
	}
	PostorderTraversal(root->left);
	PostorderTraversal(root->right);
	printf("%s ", root->value);
}

//非递归遍历
//前序遍历
void PreOrderNor(BTNode* root) {

}
//中序遍历
void InOrderNor(BTNode* root) {

}
//后序遍历
void PostOrderNor(BTNode* root) {

}

//层序遍历
void LevelOrder(BTNode* root) {

}

//求二叉树的节点个数
int count = 0;
void GetNodeCount1(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	count++;
	GetNodeCount1(root->left);
	GetNodeCount1(root->right);	
}
//递推
int GetNodeCount2(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	int left = GetNodeCount2(root->left);
	int right = GetNodeCount2(root->right);
	return left + right + 1;
}
// 求二叉树的高度 
int Height(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	int left = Height(root->left);
	int right = Height(root->left);
	return (left > right ? left : right) + 1;
}
// 获取二叉数中叶子节点的个数 
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

// 求二叉树的镜像 
void Mirror(BTNode* root) {

}