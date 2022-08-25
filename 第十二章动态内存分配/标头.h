#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

class strBlobPtr;
class strBlob
{
public:
	friend class strBlobPtr;
	strBlobPtr begin();
	strBlobPtr end();
	typedef vector<string>::size_type size_type;
	strBlob();
	strBlob(initializer_list<string> il);
	size_type size()const { return data->size(); }
	bool isempty()const { return data->empty(); }
	//添加删除元素
	void push_back(const string& str) { data->push_back(str); }
	void pop_back();
	//元素访问
	string& front();
	string& back();
	string& front()const;
	string& back()const;

private:
	shared_ptr<vector<string>> data;
	void check(size_t i, const string& msg)const;
};

class strBlobPtr
{
private:
	shared_ptr<vector<string>> check(size_t, const string&)const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
public:
	strBlobPtr() :curr(0) {}
	strBlobPtr(strBlob& a, size_t sz = 0)
		:wptr(a.data), curr(sz) {}
	string& deref()const;
	strBlobPtr& incr();		//前缀递增
};