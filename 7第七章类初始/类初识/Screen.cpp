#include "Screen.h"

inline char Screen::get(pos r, pos c) const
{
	pos row = r * weight;
	return contents[row + c];	//返回给定的列的字符

}

Screen& Screen::move(pos r, pos c)
{
	pos rwo = r * weight;   //计算行位置
	cursor = rwo + c;       //在行内将光标移动到指定列
	return *this;
	// TODO: 在此处插入 return 语句
}

Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

Screen& Screen::set(pos r, pos col, char c)
{
	contents[r * weight + col] = c;
	return *this;
}

void Screen::some_member() const
{
	++access_ctr;	//保存一个计数值
}

void Window_mgr::clear(ScreenIndex i)
{
	//s是一个引用，指向我们想要清空的那块屏幕
	Screen& s = screen[i];
	//清空
	s.contents = string(s.height * s.weight, ' ');
}

//首先处理返回类型，然后才进入类的作用域种，因此要先声明其位于哪个作用域中
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen& s)
{
	screen.push_back(s);
	return screen.size() - 1;
}
