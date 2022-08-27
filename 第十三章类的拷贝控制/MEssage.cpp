#include "MEssage.h"

Message::Message(const Message& msg)
	:contens(msg.contens),folders(msg.folders)//拷贝Message的操作包括消息内容和Folder指针的set拷贝
{
	add_to_Folders(msg);	//在每个包含此Message的Folder中都添加一个新创建的Message的指针
}

Message& Message::operator=(const Message& msg)
{
	//先删除指针，在插入他们
	remove_from_Folders();		//从包含左侧Message的Folder中删除
	contens = msg.contens;
	folders = msg.folders;
	add_to_Folders(msg);		//将它添加到包含右侧Message的Folder中
	return *this;
}

Message::~Message()
{
	remove_from_Folders();
}

void Message::save(Folder& fld)
{
	folders.insert(&fld);		//将给定的folder添加到我们的Folder列表中
	fld.addMsg(this);				//将本Message添加到fld的Message集合中
}

void Message::remove(Folder& fld)
{
	folders.erase(&fld);		//将给定的folder从我们的Folder列表中删除
	fld.remMsg(this);				//将本Message从fld的Message集合中删除
}

void Message::add_to_Folders(const Message& m)
{
	for (auto f : m.folders)	//对每个包含m的folder执行操作
	{		
		f->addMsg(this);			//向该folder添加一个指向本Message的指针
	}
}

void Message::remove_from_Folders()	//对每个包含m的folder执行操作
{
	for (auto f : folders)	//从该folder中删除本Message
	{
		f->remMsg(this);
	}
}

void swap(Message& a, Message& b)
{
	using std::swap;
	for (auto f : a.folders)
	{
		f->remMsg(&a);
	}
	for (auto f :b.folders)
	{
		f->remMsg(&b);
	}
	//交换contens和Folder指针set：
	swap(a.contens, b.contens);	//swap(set&,set&)
	swap(a.folders, b.folders);	//swap(string&,string&)
	//将每个Message的指针添加到新的Folder中
	for (auto f : a.folders)
	{
		f->addMsg(&a);
	}
	for (auto f : b.folders)
	{
		f->addMsg(&b);
	}
}

inline void swap(Folder& a, Folder& b)
{
	a.remove_from_Messages();
	b.remove_from_Messages();

	swap(a.msg, b.msg);

	a.add_to_Messages(a);
	b.add_to_Messages(b);
}

void Folder::add_to_Messages(const Folder& fld)
{
	for (auto m : fld.msg)
	{
		m->folders.insert(this);
	}
}

void Folder::remove_from_Messages()
{
	for (auto m : msg)
	{
		m->folders.erase(this);
	}
}
