#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

class Folder;
class Message
{
	friend class Folder;
	friend void swap(Message& a, Message& b);
public:
	explicit Message(const string& str = " ") :contens(str) {}
	//拷贝控制成员，管理指向本Message的指针
	Message(const Message& msg);
	Message& operator=(const Message& msg);
	~Message();
	//从给定的folder集合中添加，删除message
	void save(Folder& fld);
	void remove(Folder& fld);
private:
	string contens;		//实际文本信息
	set<Folder*> folders;		//包含message 的folder

	//析构函数和拷贝赋值运算符需要的操作
	void add_to_Folders(const Message&);	//将Message添加到某个Folder中
	void remove_from_Folders();				//将Message从某个Folder删除
};

class Folder
{
	friend void swap(Folder& a, Folder& b);
public:
	Folder() = default;
	Folder(const Folder& fld) :msg(fld.msg) { add_to_Messages(fld); }
	Folder& operator=(const Folder& f) {
		remove_from_Messages();
		msg = f.msg;
		add_to_Messages(f);
		return *this;
	}
	~Folder() {
		remove_from_Messages();
	}
	void addMsg(Message* m)
	{
		msg.insert(m);
	}
	void remMsg(Message* m)
	{
		msg.erase(m);
	}
private:
	set<Message*> msg;
	void add_to_Messages(const Folder& fld);
	void remove_from_Messages();
};