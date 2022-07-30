#include "Sales_item.h"
using namespace std;

int main()
{
#if 0
	Sales_item books;
	cout << "输入书籍信息: " << endl;
	while (cin >> books)
	{
		cout << books << endl;
		cout << "继续输入: " << endl;
	}
#elif 0
	Sales_item books1, books2;

	/*while (cin >> books1 >> books2)
	{
		if (books1.isbn() == books2.isbn())
		{
			cout << "他们isbn相等 和为:" << books1 + books2 << endl;
		}
		else
		{
			cout << "请继续输入: " << endl;
		}
	}*/

	while (cin >> books1)
	{
		if (cin >> books2 && books1.isbn() == books2.isbn())
		{
			cout << "他们isbn相等 和为:" << books1 + books2 << endl;
		}
		else
		{
			cerr << "他们不相等 !" << endl;
		}
	}
#elif 0
	Sales_item totle, book1, book2;

	cout << "请输入相同isbn的记录: " << endl;
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
				cerr << "isbn不相等!\n";
				break;
			}
		}
	}
	cout << "结束: totle : " << totle << endl;
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
				cout << Curbooks.isbn() << " 有" << count << "条销售记录" << endl;
				Curbooks = books;		//重置新值
				count = 1;				//计数器重置
			}
		}
		cout << Curbooks.isbn() << " 有" << count << "条销售记录" << endl;
	}
#elif 1

	/*
	1.6 书店
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