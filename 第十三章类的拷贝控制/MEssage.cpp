#include "MEssage.h"

Message::Message(const Message& msg)
	:contens(msg.contens),folders(msg.folders)//����Message�Ĳ���������Ϣ���ݺ�Folderָ���set����
{
	add_to_Folders(msg);	//��ÿ��������Message��Folder�ж����һ���´�����Message��ָ��
}

Message& Message::operator=(const Message& msg)
{
	//��ɾ��ָ�룬�ڲ�������
	remove_from_Folders();		//�Ӱ������Message��Folder��ɾ��
	contens = msg.contens;
	folders = msg.folders;
	add_to_Folders(msg);		//������ӵ������Ҳ�Message��Folder��
	return *this;
}

Message::~Message()
{
	remove_from_Folders();
}

void Message::save(Folder& fld)
{
	folders.insert(&fld);		//��������folder��ӵ����ǵ�Folder�б���
	fld.addMsg(this);				//����Message��ӵ�fld��Message������
}

void Message::remove(Folder& fld)
{
	folders.erase(&fld);		//��������folder�����ǵ�Folder�б���ɾ��
	fld.remMsg(this);				//����Message��fld��Message������ɾ��
}

void Message::add_to_Folders(const Message& m)
{
	for (auto f : m.folders)	//��ÿ������m��folderִ�в���
	{		
		f->addMsg(this);			//���folder���һ��ָ��Message��ָ��
	}
}

void Message::remove_from_Folders()	//��ÿ������m��folderִ�в���
{
	for (auto f : folders)	//�Ӹ�folder��ɾ����Message
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
	//����contens��Folderָ��set��
	swap(a.contens, b.contens);	//swap(set&,set&)
	swap(a.folders, b.folders);	//swap(string&,string&)
	//��ÿ��Message��ָ����ӵ��µ�Folder��
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
