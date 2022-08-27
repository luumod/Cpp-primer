



#ifndef  SALES_DATA_H_
#define SALES_DATA_H_

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

class Sales_data
{
	friend std::istream& read(std::istream& in, Sales_data& s);
	friend Sales_data add(const Sales_data& s1, const Sales_data& s2);
	friend std::ostream& print(std::ostream& out, const Sales_data& s);
public:
	//构造函数
	Sales_data(const string& s, unsigned n, double p)
		:bookNo(s), units_sold(n), revenue(p* n) {}
	//三个委托构造
	Sales_data() = default;
	explicit Sales_data(const string& s) :Sales_data(s, 0, 0) { }
	explicit Sales_data(std::istream& in):Sales_data()
	{
		read(in, *this);
	}
	//成员函数 ：关于对象的操作 定义在类内的是inline函数
	string isbn()const
	{
		return bookNo;
	}
	Sales_data& combine(const Sales_data& s);
private:
	double avg_price()const;
	string bookNo;				//isbn编号
	unsigned units_sold = 0;	//某本书的销量
	double revenue = 0.0;		//某本书总销售收入
};



class NoDeFault
{
	int a;
public:
	NoDeFault(int x) :a(x) {}
};
class C
{
	NoDeFault x;
public:
	C(int num = 5) :x(num) {}
};

#if 1
class Foo
{
public:
	Foo(const int& data = 5) :a(new int(data)) { cout << "Foo(cnst int& data)" << endl; }
	Foo(const Foo& foo)
	{
		cout << "Foo(const Foo& foo)" << endl;
		this->a=make_shared<int>(*foo.a);
	}
	~Foo() { cout <<*a<< "  ~Foo()" << endl; }
	Foo& operator=(const Foo& foo)
	{
		shared_ptr<int> temp = make_shared<int>(*foo.a);
		this->a = temp;
		cout << "Foo& operator=(const Foo& foo)" << endl;
		return *this;
	}
private:
	shared_ptr<int> a;
};
#else

class Foo
{
public:
	Foo(const int& data = 5) :a(new int(data)) { cout << "Foo(cnst int& data)" << endl; }
	Foo(const Foo& foo)
	{
		cout << "Foo(const Foo& foo)" << endl;
		this->a = new int(*foo.a);
	}
	~Foo() { cout << *a << "  ~Foo()" << endl; }
	Foo& operator=(const Foo& foo)
	{
		int* temp = new int(*foo.a);
		this->a = temp;
		cout << "Foo& operator=(const Foo& foo)" << endl;
		return *this;
	}
private:
	int* a;
};
#endif


class A
{
public:
	A() = default;				//合成默认构造函数
	A(const A& a) = delete;				//删除拷贝
	~A() = delete;				//合成的析构函数
	A& operator=(const A& a)=delete;	//删除赋值
private:
	int* p;
};

class Emplyee
{
public:
	Emplyee();
	Emplyee(const string& name);
	size_t GetNum()const { return number; }
	Emplyee(const Emplyee& emo)
	{
		name = emo.name;
		number = emo.number;
		number++;
	}
	Emplyee& operator=(const Emplyee& emo)
	{
		name = emo.name;
		number = emo.number;
		number++;
		return *this;
	}
private:
	static size_t i;
	string name;
	size_t number;
};

size_t Emplyee::i = 0;

Emplyee::Emplyee()
{
	name = "moren";
	number = i++;
}
Emplyee::Emplyee(const string& name)
{
	this->name = name;
	this->number = i++;
}
#endif // ! SALES_DATA_H_
