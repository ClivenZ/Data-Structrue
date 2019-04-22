#include<stdio.h>
#include<stdlib.h>


//定义数据类型
typedef char BTDataType;

//结构体定义
typedef struct BTNode {
	int value;
	struct BTNode *left;		//左孩子
	struct BTNode *right;		//右孩子
} BTNode;

//创建二叉树
BTNode* CreateBinTree(BTDataType* value, int size);
//拷贝二叉树
BTNode* CopyBinTree(BTNode* root);
// 销毁二叉树 
void DestroyBinTree(BTNode** root);

//递归遍历
//前序遍历   根 左子树 右子树
void PreorderTraversal(BTNode* root);
//中序遍历   左子树 根 右子树
void InorderTraversal(BTNode* root);
//后序遍历   左子树 右子树 根
void PostorderTraversal(BTNode* root);

//非递归遍历
//前序遍历
void PreOrderNor(BTNode* root);
//中序遍历
void InOrderNor(BTNode* root);
//后序遍历
void PostOrderNor(BTNode* root);

//层序遍历
void LevelOrder(BTNode* root);

//求二叉树的节点个数
void GetNodeCount1(BTNode* root);
int GetNodeCount2(BTNode* root);

// 求二叉树的高度 
int Height(BTNode* root);

// 获取二叉数中叶子节点的个数 
int GetLeafNodeCount(BTNode* root);

// 获取二叉树第K层节点的个数 
int GetKLevelNodeCount(BTNode* root, int K);

// 求二叉树的镜像 
void Mirror(BTNode* root);