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

#if 1		//ָ��汾
class HasPtr
{
	friend void swap(HasPtr& a, HasPtr& b);
	friend ostream& operator<<(ostream& os, const HasPtr& h);
	friend bool operator<(const HasPtr& a, const HasPtr& b);
public:
	HasPtr(const string& s = string(),int i=0)
		:ps(new string(s)), i(i),use(new size_t(1)) {}
	//��������
	~HasPtr()
	{
		if (* use == 0)
		{
			delete ps;
			delete use;
		}
	}
	//�������캯��
	HasPtr(const HasPtr& h)
		:ps(h.ps), i(h.i), use(h.use) {++* use;}
	//������ֵ�����
	HasPtr& operator=(const HasPtr& h);
	/*HasPtr& operator=(HasPtr h)
	{
		swap(*this, h);
		return *this;
	}*/
private:
	string* ps;
	int i;
	size_t* use;	//��¼�ж��ٸ�������*ps�ĳ�Ա
};

//
inline HasPtr& HasPtr::operator=(const HasPtr& h)
{
	//�����Ҳ�
	++* h.use;
	//�ݼ����
	if (-- * use==0)
	{
		delete ps;
		delete use;
	}

	//���ݸ�ֵ
	ps = h.ps;
	i = h.i;
	use = h.use;
	return *this;
}

inline void swap(HasPtr& a, HasPtr& b)
{
	cout << "swap����  " << endl;
	swap(a.ps, b.ps);	//����ָ�룬��������
	swap(a.i, b.i);		//����int����
	swap(a.use, b.use);
}

#else		//��ֵ�汾

class HasPtr
{
	friend void swap(HasPtr& a, HasPtr& b);
	friend ostream& operator<<(ostream& os, const HasPtr& h);
	friend bool operator<(const HasPtr& a, const HasPtr& b);
public:
	HasPtr(const string& s = string(), int i = 0)
		:ps(new string(s)), i(i) {}
	//��������
	~HasPtr() { delete ps; }
	//�������캯��
	HasPtr(const HasPtr& h)
		:ps(h.ps), i(h.i) {}
	//������ֵ�����
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
	//���ݸ�ֵ
	ps = temp;
	i = h.i;
	return *this;
}

inline void swap(HasPtr& a, HasPtr& b)
{
	swap(a.ps, b.ps);	//����ָ�룬��������
	swap(a.i, b.i);		//����int����
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
