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

#if 1		//指针版本
class HasPtr
{
	friend void swap(HasPtr& a, HasPtr& b);
	friend ostream& operator<<(ostream& os, const HasPtr& h);
	friend bool operator<(const HasPtr& a, const HasPtr& b);
public:
	HasPtr(const string& s = string(),int i=0)
		:ps(new string(s)), i(i),use(new size_t(1)) {}
	//析构函数
	~HasPtr()
	{
		if (* use == 0)
		{
			delete ps;
			delete use;
		}
	}
	//拷贝构造函数
	HasPtr(const HasPtr& h)
		:ps(h.ps), i(h.i), use(h.use) {++* use;}
	//拷贝赋值运算符
	HasPtr& operator=(const HasPtr& h);
	/*HasPtr& operator=(HasPtr h)
	{
		swap(*this, h);
		return *this;
	}*/
private:
	string* ps;
	int i;
	size_t* use;	//记录有多少个对象共享*ps的成员
};

//
inline HasPtr& HasPtr::operator=(const HasPtr& h)
{
	//递增右侧
	++* h.use;
	//递减左侧
	if (-- * use==0)
	{
		delete ps;
		delete use;
	}

	//数据赋值
	ps = h.ps;
	i = h.i;
	use = h.use;
	return *this;
}

inline void swap(HasPtr& a, HasPtr& b)
{
	cout << "swap函数  " << endl;
	swap(a.ps, b.ps);	//交换指针，不是数据
	swap(a.i, b.i);		//交换int数据
	swap(a.use, b.use);
}

#else		//类值版本

class HasPtr
{
	friend void swap(HasPtr& a, HasPtr& b);
	friend ostream& operator<<(ostream& os, const HasPtr& h);
	friend bool operator<(const HasPtr& a, const HasPtr& b);
public:
	HasPtr(const string& s = string(), int i = 0)
		:ps(new string(s)), i(i) {}
	//析构函数
	~HasPtr() { delete ps; }
	//拷贝构造函数
	HasPtr(const HasPtr& h)
		:ps(h.ps), i(h.i) {}
	//拷贝赋值运算符
	HasPtr& operator=(const HasPtr& h);
	/*HasPtr& operator=(HasPtr h)
	{
		swap(*this, h);
		return *this;
	}*/
private:
	string* ps;
	int i;
};

//
inline HasPtr& HasPtr::operator=(const HasPtr& h)
{
	string* temp = new string(*h.ps);
	delete ps;
	//数据赋值
	ps = temp;
	i = h.i;
	return *this;
}

inline void swap(HasPtr& a, HasPtr& b)
{
	swap(a.ps, b.ps);	//交换指针，不是数据
	swap(a.i, b.i);		//交换int数据
}
#endif
inline ostream& operator<<(ostream& os, const HasPtr& h)
{
	os << *h.ps << '\t' << h.i;
	return os;
}
inline bool operator<(const HasPtr& a, const HasPtr& b)
{
	return *a.ps < *b.ps;
}
