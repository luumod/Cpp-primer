#include "Screen.h"

inline char Screen::get(pos r, pos c) const
{
	pos row = r * weight;
	return contents[row + c];	//���ظ������е��ַ�

}

Screen& Screen::move(pos r, pos c)
{
	pos rwo = r * weight;   //������λ��
	cursor = rwo + c;       //�����ڽ�����ƶ���ָ����
	return *this;
	// TODO: �ڴ˴����� return ���
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
	++access_ctr;	//����һ������ֵ
}

void Window_mgr::clear(ScreenIndex i)
{
	//s��һ�����ã�ָ��������Ҫ��յ��ǿ���Ļ
	Screen& s = screen[i];
	//���
	s.contents = string(s.height * s.weight, ' ');
}

//���ȴ��������ͣ�Ȼ��Ž�������������֣����Ҫ��������λ���ĸ���������
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen& s)
{
	screen.push_back(s);
	return screen.size() - 1;
}
