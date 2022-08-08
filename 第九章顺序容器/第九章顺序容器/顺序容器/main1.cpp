#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <array>
#include <forward_list>

using namespace std;

vector<int>::iterator VectorFindNum(vector<int>& vec, int a);
void Insert_String(forward_list<string> s, string& s1, string& s2);
int main()
{
#if 0
	vector<int> a{ 1,2,3,4,5,6,7,8,9 };
	int num = 15;
	auto itx = VectorFindNum(a, num);
	if (itx == a.end())
	{
		cerr << "未找到!\n";
		return -1;
	}
	cout << *itx << endl;
#elif 0
	list<int> a{ 1,2,3,4,5,6 };
	const list<int> b(4);
	//auto it = a.begin(), it2 = b.begin();

	for (list<int>::iterator itera = a.begin(); itera != a.end(); ++itera)
	{
		*itera = 5;
	}
#elif 0
	list<int> a{ 1,2,3 };
	vector<double> b{ 1.1,2.2,3.3 };

	list<int> a1(a);
	list<double> a2(a);	//元素类型不匹配
	vector<int> a3(a);	//容器类型不匹配

	vector<int> b1(b.begin(), b.end());	//根据范围
	list<string> b2(b.begin(), b.end());
#elif 0
	array<int, 10> a{ 1,2,3,4,5 };
	array<int, 3> b{ 1,2,3,4 };

	//支持拷贝
	array<int, 10> c(a);
#elif 0
	list<int> a{ 1,2,3 };
	vector<double> b{ a.begin(),a.end() };
	vector<int> c(b.begin(), b.end());

	for (auto x = b.begin(); x != b.end(); ++x)
	{
		cout << *x << " ";
	}
	for (auto x = c.begin(); x != c.end(); ++x)
	{
		cout << *x << " ";
	}
#elif 0
	list<int> a{ 1,2,3,4,5 };
	list<int> b{ 1,2,3 };
	a = b;	//a自动变为与b一样的大小
	a = { 1,2,3,4,5,6,7,8,9 };//自动改变大小

	array<int, 5> ar{ 1,2,3,4,5 };
	array<int, 2> br{ 1,2 };
	ar = br;
#elif 0

	list<string> name;
	vector<const char*> str{ "我爱你","于良浩" };
	//实现了将vector的const char*赋值给了list的string
	name.assign(str.begin(), str.end());

	name.assign(10, "www");
#elif 0
	list<int> a(10, 1);
	list<int> b(20, 2);

	auto pa = &a, pb = &b;
	auto ita = a.begin(), itb = b.begin();
	vector<string> sa{ "woaini" };
	vector<string> sb{ "ylh" };
	auto x = &sa, y = &sb;
	swap(sa, sb);

	//交换容器，包括大小即数值
	a.swap(b);
	swap(a, b);
	cout << pa << " ";
#elif 0
	list<const char*> str1{ "wpaini" };

	vector<string> str2{ str1.begin(),str1.end() };
#elif 0
	vector<int> a{ 1,1,1 };
	list<int> b(3, 1);
	if (a[1] == *(b.begin()))
	{
		cout << "Yes!\n";
	}
#elif 0
	list<int> a;
	for (int i = 0; i < 5; i++)
	{
		a.push_back(i);
	}
	for (auto x : a)
	{
		cout << x << " ";
	}
	string str{ "woaini" };
	str.push_back('d');
#elif 0
	deque<int> a;
	for (int i = 0; i < 5; i++)
	{
		a.push_front(i);
	}
	for (auto x : a)
	{
		cout << x << " ";
	}
#elif 0
	vector<int> a{ 1,2,3 };
	for (int i = 0; i < 5; i++)
	{
		a.insert(a.begin(), i);
	}
#elif 0
	//插入范围内的元素
	list<int> a{ 1,2,3 };
	vector<int> b{ 4,5,6 };
	a.insert(a.begin(), 5, 1);
	a.insert(a.end(), b.begin() + 2, b.end());
	a.insert(a.begin(), { 9,9,9 });
	a.insert(a.begin(), a.begin(), a.end());
#elif 0
	list<int> a{ 4,5,6 };
	auto iter = a.begin();
	for (int i = 3; i > 0; i--)
	{
		iter = a.insert(iter, i);
	}
#elif 0
	struct io
	{
		int a;
		io() = default;
		io(int i) :a(i) {}
	};
	vector<io> a;
	vector<io> b;
	a.emplace_back();
	a.emplace_back(9);
	for (int i = 0; i < 5; i++)
	{
		b.emplace_back(i);
	}
	a.emplace(a.begin(), 7);
#elif 0
	string str;
	list<string> a;
	while (cin >> str)
	{
		a.push_back(str);
	}
	for (auto it = a.cbegin(); it != a.cend(); ++it)
	{
		cout << *it << " ";
	}
#elif 0
	list<int> a{ 1,2,3,4,5,6,7,8,9 };
	deque<int> o;
	deque<int> j;
	for (auto it = a.cbegin(); it != a.cend(); ++it)
	{
		if ((*it) % 2 == 0)
		{
			o.push_back(*it);
		}
		else
		{
			j.push_back(*it);
		}
	}
#elif 0
	vector<string> a;
	string word;
	auto it = a.begin();
	while (cin >> word)
	{
		it = a.insert(it, word);
	}
#elif 0
	vector<int> iv{ 1,2,3,4,5 };
	auto iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
	iv.push_back(5);
#elif 0
	vector<int> a;
	a.front() = 9;
#elif 0
	vector<int> a{ 1,2,3 };
	auto it = a.begin() + 1;
	a.erase(a.end(), a.end());
#elif 0
	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
	list<int> a;
	vector<int> b;
	for (auto x : ia)
	{
		a.push_back(x);
		b.push_back(x);
	}
	auto ita = a.begin();
	auto itb = b.begin();
	while (ita != a.end())
	{
		if (*ita % 2)
		{
			ita=a.erase(ita);
		}
		else
		{
			++ita;
		}
	}
	while (itb != b.end())
	{
		if (*itb % 2==0)
		{
			itb=b.erase(itb);
		}
		else
		{
			++itb;
		}
	}
#elif 0
forward_list<int> a{ 1,3,3,4,5,6,7,8,9 };
auto prev = a.before_begin();
auto curr = a.begin();
while (curr != a.end())
{
	if (*curr % 2)
	{
		curr = a.erase_after(prev);
	}
	else
	{
		prev = curr;
		++curr;
	}
}
#elif 0
forward_list<string> a{"woaini","ylh","dadw"};
string s1{"abcdefg"}, s2{"hijklmn"};
Insert_String(a, s1, s2);
#elif 0

list<int> a(10, 5);
a.resize(20, 1);
a.resize(5);
#elif 0

deque<int> a{ 1,2,3,4,5 };
auto it = a.begin();
auto it2 = a.begin();
auto ptr = &a;

auto& x = a;
a.erase(a.begin()+1);

for (auto x : *ptr)
{
	cout << x << " ";
}
for (auto i : x)
{
	cout << i << " ";
}
cout << *it << " " << *it2 << endl;
cout << "\n";
#elif 0
vector<int> a{ 1,2,3 };
auto it = a.begin();
it = a.insert(it, 9);
#elif 0
forward_list<int> a{ 0,1,2,3,4,5,6,7,8,9 };
auto prev = a.before_begin();
auto iter = a.begin();
while (iter != a.end())
{
	if (*iter % 2)
	{
		iter = a.insert_after(prev, *iter);
		++iter;		//移动迭代器到新插入的元素和原来插入前指向的元素之后
		++prev;
	}
	else
	{
		iter = a.erase_after(prev);
		prev = iter;
		
	}
}
#elif 0
vector<int> a{1,2,3,4,5,6};
int i = 0;
auto it = a.begin();
while (it != a.end())
{
	++it;
	it = it = a.insert(it, i);
	++it;
}
#elif 1
vector<int> a{ 1,2,3,4,5 };
auto iter = a.begin();
while (iter != a.end())
{
	if (*iter % 2)
	{
		iter = a.insert(iter, *iter);
		++iter;
	}
	++iter;
}


#endif
	return 0;
}


vector<int>::iterator  VectorFindNum(vector<int>& vec, int a)
{
	vector<int>::iterator it;
	for (it = vec.begin(); it != vec.end(); ++it)
	{
		if (*it == a)
		{
			return it;
		}
	}
	return vec.end();
}

void Insert_String(forward_list<string> s, string& s1, string& s2)
{
	auto prev = s.before_begin();
	auto curr = s.begin();
	while (curr != s.end())
	{
		if (*curr == s1)
		{
			s.insert_after(curr, s2);
		}
		else
		{
			prev = curr;
			++curr;
		}
	}
	s.insert_after(prev, s1);
}