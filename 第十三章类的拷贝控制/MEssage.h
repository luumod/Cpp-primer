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
	//�������Ƴ�Ա������ָ��Message��ָ��
	Message(const Message& msg);
	Message& operator=(const Message& msg);
	~Message();
	//�Ӹ�����folder��������ӣ�ɾ��message
	void save(Folder& fld);
	void remove(Folder& fld);
private:
	string contens;		//ʵ���ı���Ϣ
	set<Folder*> folders;		//����message ��folder

	//���������Ϳ�����ֵ�������Ҫ�Ĳ���
	void add_to_Folders(const Message&);	//��Message��ӵ�ĳ��Folder��
	void remove_from_Folders();				//��Message��ĳ��Folderɾ��
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