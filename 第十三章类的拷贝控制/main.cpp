#if 0
#include "Sales_data.hpp"

#elif 0
#include "StrBlob.h"

#elif 0
#include "13.hpp"

#elif 1
#include "MEssage.h"

#endif
using namespace std;


int main()
{

#if 0
	Foo a = 10;
	Foo b = 5;
	Foo c(2);
	c = b;

	cout << endl;
	cout << endl;

	//ÈÝÆ÷
	vector<Foo> f;
	f.push_back(10);

	cout << endl;
	cout << endl;

	//¶¯Ì¬·ÖÅä
	Foo* g = new Foo(15);
	shared_ptr<Foo> h = make_shared<Foo>(b);
	delete g;

	cout << endl;
	cout << endl;

#elif 0
	shared_ptr<int> a = make_shared<int>();

#elif 0
	Emplyee a;
	Emplyee b("ylh");
	Emplyee c(b);
	Emplyee d;
	d = c;
	cout<< a.GetNum()<<" "<<b.GetNum() << " "<<c.GetNum()<<" "<<d.GetNum()<<endl;

#elif 0
	HasPtr a("aaaaa", 150);
	HasPtr b("bbbbb",50);
	cout << a << "\t" << b << endl;
	swap(a, b);
	cout << a << "\t" << b << endl;
#elif 0
	vector<HasPtr> a;

	HasPtr b("aaa", 15);
	HasPtr c("bbb", 20);
	HasPtr d("fff", 30);
	HasPtr e("zzz", 40);
	HasPtr f("ccc", 5);

	a.push_back(b);
	a.push_back(c);
	a.push_back(d);
	a.push_back(e);
	a.push_back(f);
	for (auto itbeg = a.cbegin(); itbeg != a.cend(); ++itbeg)
	{
		cout << *itbeg << " ";
	}
	sort(a.begin(), a.end());
	cout << endl;
	for (auto itbeg = a.cbegin(); itbeg != a.cend(); ++itbeg)
	{
		cout << *itbeg << " ";
	}
#elif 0
	strBlob a({ "abc","bdcd","oid","dlpa" });
	strBlob b(a);
	strBlob c;
	c = b;
	strBlobPtr d(a, 100);
	strBlobPtr e(d);
	d.incr();
	e.incr();
	cout << d.deref() << endl;
	/*while (!a.isempty())
	{
		cout << a.back() << " ";
		a.pop_back();
	}*/


#elif 1

	Message a("ÐÜ³öÃ»");
	Message b("Ï²ÑòÑò");
	Message c("ºÚÃ¨¾¯³¤");
	Folder e;
	a.save(e);
	b.save(e);
	c.save(e);
	a.remove(e);
#endif
	return 0;
}