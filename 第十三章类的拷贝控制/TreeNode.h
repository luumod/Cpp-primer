#pragma once


#include <iostream>
#include <string>
using namespace std;

class TreeNode
{
public:
	TreeNode() :value(string()), count(0), pLeft(nullptr), pRight(nullptr), use(new size_t(1)) {}
	TreeNode(const string& str, int num)
		:value(str), count(num), pLeft(nullptr), pRight(nullptr),use(new size_t(1)) {}
	//�������캯��
	TreeNode(const TreeNode& tree)
	{
		value = tree.value;
		count = tree.count;
		pLeft = tree.pLeft;
		pRight = tree.pRight;
		use = tree.use;
		++* use;
	}
	//������ֵ�����
	TreeNode& operator=(const TreeNode& tree)
	{
		//�����Ҳ�
		++* tree.use;
		//�ݼ����
		if (-- * use == 0)
		{
			delete pLeft;
			delete pRight;
			delete use;

		}
		//���ݸ�ֵ
		value = tree.value;
		count = tree.count;
		pLeft = tree.pLeft;
		pRight = tree.pRight;
		use = tree.use;
		return *this;
	}
	//��������
	~TreeNode()
	{
		if (-- * use == 0)
		{
			delete pLeft;
			delete pRight;
			delete use;
		}
	}
private:
	string value;
	int count;
	TreeNode* pLeft;
	TreeNode* pRight;
	size_t* use;	//��¼�ļ�����
};

class BinStrTree
{
public:
	BinStrTree() :pRoot(new TreeNode()) {}
	BinStrTree(const BinStrTree& bst) :pRoot(new TreeNode(*bst.pRoot)) {}
	BinStrTree& operator=(const BinStrTree& bst)
	{
		pRoot = bst.pRoot;
		return *this;
	}
	~BinStrTree() { delete pRoot; }
private:
	TreeNode* pRoot;
};