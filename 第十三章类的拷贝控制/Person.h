
#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>
using namespace std;

class Person
{
	friend ostream& print(ostream& out, const Person& p);
	friend istream& read(istream& in, Person& p);
public:
	Person() = default;
	Person(const string& n, const string& a) :name(n), address(a) {}
	explicit Person(const string& n) :name(n) {}
	explicit Person(istream& in)
	{
		read(in, *this);
	}
private:
	string name;
	string address;
public:
	string Getname()const
	{
		return name;
	}
	string Getaddress()const
	{
		return address;
	}
	string& Getname()
	{
		return name;
	}
	string& Getaddress()
	{
		return address;
	}
};

//class A
//{
//private:
//	int a;
//	int b;
//	static constexpr int c = 20;
//	static int d;
//	//普通成员只能声明为所属类型的指针或者引用
//	A fad;	
//	A* old;
//	static A abc;//不完全类型
//public:
//	//静态成员作为默认实参
//	A& Dwadadwad(int = c);	
//};

#endif