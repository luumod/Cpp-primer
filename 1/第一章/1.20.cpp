#include "Sales_item.h"
using namespace std;

int main()
{
#if 0
	Sales_item books;
	cout << "�����鼮��Ϣ: " << endl;
	while (cin >> books)
	{
		cout << books << endl;
		cout << "��������: " << endl;
	}
#elif 0
	Sales_item books1, books2;

	/*while (cin >> books1 >> books2)
	{
		if (books1.isbn() == books2.isbn())
		{
			cout << "����isbn��� ��Ϊ:" << books1 + books2 << endl;
		}
		else
		{
			cout << "���������: " << endl;
		}
	}*/

	while (cin >> books1)
	{
		if (cin >> books2 && books1.isbn() == books2.isbn())
		{
			cout << "����isbn��� ��Ϊ:" << books1 + books2 << endl;
		}
		else
		{
			cerr << "���ǲ���� !" << endl;
		}
	}
#elif 0
	Sales_item totle, book1, book2;

	cout << "��������ͬisbn�ļ�¼: " << endl;
	if (cin >> book1)
	{
		totle += book1;
		while (cin >> book2)
		{
			if (book1.isbn() == book2.isbn())
			{
				totle += book2;
				cout << "totle : " << totle << endl;
			}
			else
			{
				cerr << "isbn�����!\n";
				break;
			}
		}
	}
	cout << "����: totle : " << totle << endl;
#elif 0
	Sales_item books, Curbooks;
	int count = 1;

	if (cin >> books)
	{
		Curbooks = books;
		while (cin >> books)
		{
			if (books == Curbooks)
			{
				count++;
			}
			else
			{
				cout << Curbooks.isbn() << " ��" << count << "�����ۼ�¼" << endl;
				Curbooks = books;		//������ֵ
				count = 1;				//����������
			}
		}
		cout << Curbooks.isbn() << " ��" << count << "�����ۼ�¼" << endl;
	}
#elif 1

	/*
	1.6 ���
	*/
	Sales_item totle;

	if (cin >> totle)
	{
		Sales_item trans;
		while (cin >> trans)
		{
			if (totle.isbn() == trans.isbn())
			{
				totle += trans;
			}
			else
			{
				cout << "totle: " << totle << endl;
			}
		}
		cout << "totle: " << totle << endl;
	}
	else
	{
		cerr << "No data?" << endl;
		return -1;
	}
#endif


	return 0;
}