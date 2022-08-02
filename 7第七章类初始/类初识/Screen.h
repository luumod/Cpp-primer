

#ifndef SCREEN_H_
#define SCREEN_H_
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Screen
{
	//������Ԫ���������϶�
	//friend void Window_mgr::clear(ScreenIndex);
	friend class Window_mgr;
public:
	using pos = string::size_type;
public:
	//���캯��
	Screen() = default;
	Screen(pos ht, pos wd) :height(ht), weight(wd), contents(ht* wd, ' ') {}
	Screen(pos ht, pos wd, char c) :height(ht), weight(wd), contents(ht* wd, c) {}
public:
	char get()const { return contents[cursor]; }//��ʽ����
	inline char get(pos ht, pos wd)const;//��ʽ����
	Screen& move(pos r, pos c);
	Screen& set(char c);
	Screen& set(pos r, pos col, char c);
	//�����Ƿ���const����display����
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
	mutable size_t access_ctr;	//����const���� 
private:
	pos cursor = 0;
	pos height = 0, weight = 0;
	string contents;
private:
	//˽�к���ʵ��  ֻ������ʾ����
	void do_display(ostream& out)const
	{
		out << contents;
	}
};

class Window_mgr
{
public:
	//������ÿ����Ļ�ı��
	using ScreenIndex = vector<Screen>::size_type;
	//���ձ�Ž�ָ����Screen����Ϊ�հ�
	void clear(ScreenIndex i);
	//�񴰿�������һ��Screen,�����ر��
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