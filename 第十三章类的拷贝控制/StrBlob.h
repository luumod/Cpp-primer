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
	strBlob(const strBlob& sbl)
	{
		shared_ptr<vector<string>> data = make_shared<vector<string>>(*sbl.data);
		this->data = data;
		
	}
	strBlob& operator=(const strBlob& sbl)
	{
		shared_ptr<vector<string>> data = make_shared<vector<string>>(*sbl.data);
		this->data = data;
		return *this;
	}
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
public:
	strBlobPtr() :curr(0) {}
	strBlobPtr(strBlob& a, size_t sz = 0)
		:wptr(a.data), curr(sz) {}
	strBlobPtr(const strBlobPtr& sblptr)
	{
		weak_ptr<vector<string>> data(sblptr.wptr);
		this->wptr = data;
		this->curr = sblptr.curr;
	}
	string& deref()const;
	strBlobPtr& incr();		//前缀递增
private:
	shared_ptr<vector<string>> check(size_t, const string&)const;
	weak_ptr<vector<string>> wptr;
	size_t curr;

};