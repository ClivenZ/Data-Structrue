	#pragma once

#include <iostream>
using namespace std;

//BST: binary search tree

template<class T>
struct BSTreeNode
{
	BSTreeNode(const T& data = T())
	: _pLeft(nullptr)
	, _pRight(nullptr)
	, _data(data)
	{}

	BSTreeNode<T>* _pLeft;
	BSTreeNode<T>* _pRight;
	T _data;
};


template<class T>
class BSTree
{
	typedef BSTreeNode<T> Node;
public:
	BSTree()
		: _pRoot(nullptr)
	{}

	~BSTree()
	{
		_Destroy(_pRoot);
	}

	bool Insert(const T& data)
	{
		// 空树--->直接插入
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}

		// 非空
		// 找到待插入元素在二叉搜索树中的位置
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_pRight;
			else
				return false;
		}

		// 插入节点
		pCur = new Node(data);
		if (data < pParent->_data)
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;

		return true;
	}

	void Delete(const T& data)
	{
		if (nullptr == _pRoot)
			return;

		// 找到待删除元素在二叉搜索树中的位置
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			if (data < pCur->_data)
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else if (data > pCur->_data)
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
			else
				break;
		}

		// 节点不存在
		if (nullptr == pCur)
			return false;	

		// 节点已经找到---分情况删除
		// 1. 左右孩子都不存在
		// 2. 只有左孩子
		// 3. 只有右孩子
		// 4. 左右孩子均存在
		if (nullptr == pCur->_pRight)
		{
			// 叶子节点 || 只有左孩子
		}
		else if (nullptr == pCur->_pLeft)
		{
			// 只有右孩子
		}
		else
		{
			// 左右孩子均存在
		}
	}	

	Node* Find(const T& data)
	{
		Node* pCur = _pRoot;
		while (pCur)
		{
			if (data == pCur->_data)
				return pCur;
			else if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else
				pCur = pCur->_pRight;
		}

		return nullptr;
	}

	Node* LeftMost()
	{
		if (nullptr == _pRoot)
			return nullptr;

		Node* pCur = _pRoot;
		while (pCur->_pLeft)
			pCur = pCur->_pLeft;

		return pCur;
	}

	Node* RightMost()
	{
		if (nullptr == _pRoot)
			return nullptr;

		Node* pCur = _pRoot;
		while (pCur->_pRight)
			pCur = pCur->_pRight;

		return pCur;
	}

	void InOrder()
	{
		_InOrder(_pRoot);
	}
private:
	void _InOrder(Node* pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}

	void _Destroy(Node* pRoot)
	{
		if (pRoot)
		{
			_Destroy(pRoot->_pLeft);
			_Destroy(pRoot->_pRight);
			delete pRoot;
			pRoot = nullptr;
		}
	}
private:
	Node* _pRoot;
};

void TestBSTree()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> t;
	for (auto e : a)
		t.Insert(e);

	cout << t.LeftMost() << endl;
	cout << t.RightMost() << endl;
	t.InOrder();
}