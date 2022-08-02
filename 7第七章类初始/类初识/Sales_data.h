



#ifndef  SALES_DATA_H_
#define SALES_DATA_H_

#include <iostream>
#include <string>
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

#endif // ! SALES_DATA_H_
