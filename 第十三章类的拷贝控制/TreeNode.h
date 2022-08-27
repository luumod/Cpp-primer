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
	//拷贝构造函数
	TreeNode(const TreeNode& tree)
	{
		value = tree.value;
		count = tree.count;
		pLeft = tree.pLeft;
		pRight = tree.pRight;
		use = tree.use;
		++* use;
	}
	//拷贝赋值运算符
	TreeNode& operator=(const TreeNode& tree)
	{
		//递增右侧
		++* tree.use;
		//递减左侧
		if (-- * use == 0)
		{
			delete pLeft;
			delete pRight;
			delete use;

		}
		//数据赋值
		value = tree.value;
		count = tree.count;
		pLeft = tree.pLeft;
		pRight = tree.pRight;
		use = tree.use;
		return *this;
	}
	//析构函数
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
	size_t* use;	//记录的计数器
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