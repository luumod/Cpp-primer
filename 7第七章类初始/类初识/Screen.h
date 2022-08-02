

#ifndef SCREEN_H_
#define SCREEN_H_
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Screen
{
	//定义友元函数条件较多
	//friend void Window_mgr::clear(ScreenIndex);
	friend class Window_mgr;
public:
	using pos = string::size_type;
public:
	//构造函数
	Screen() = default;
	Screen(pos ht, pos wd) :height(ht), weight(wd), contents(ht* wd, ' ') {}
	Screen(pos ht, pos wd, char c) :height(ht), weight(wd), contents(ht* wd, c) {}
public:
	char get()const { return contents[cursor]; }//隐式内联
	inline char get(pos ht, pos wd)const;//显式内联
	Screen& move(pos r, pos c);
	Screen& set(char c);
	Screen& set(pos r, pos col, char c);
	//根据是否是const重载display函数
	Screen& display(ostream& out)
	{
		do_display(out);
		return *this;
	}
	const Screen& display(ostream& out)const
	{
		do_display(out);
		return *this;
	}
public:
	void some_member()const;
private:
	mutable size_t access_ctr;	//不受const限制 
private:
	pos cursor = 0;
	pos height = 0, weight = 0;
	string contents;
private:
	//私有函数实现  只负责显示数据
	void do_display(ostream& out)const
	{
		out << contents;
	}
};

class Window_mgr
{
public:
	//窗口中每个屏幕的编号
	using ScreenIndex = vector<Screen>::size_type;
	//按照编号将指定的Screen设置为空白
	void clear(ScreenIndex i);
	//像窗口新增加一块Screen,并返回编号
	ScreenIndex addScreen(const Screen& s);
private:
	vector<Screen> screen{ Screen(5,9,'X') };
};




class X
{
	int i;
	int j;
public:
	X(int a) :j(a), i(j) {}
};



#endif