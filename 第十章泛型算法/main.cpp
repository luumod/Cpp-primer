#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <forward_list>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
using namespace std;
struct s1
{
	int a;
	int c;
	ostream& operator<<(ostream& out)
	{
		out << a << "\t" << c << endl;
		return out;
	}
};
bool isShorter(const string& s1, const string& s2);

bool isfive(const string& s1);
//按字母顺序排序
void elimDups(vector<string>& words);
#if 0
void Biggest(vector<string>& words, vector<string>::size_type sz)
{
	//删除重复元素，按照字典序排序
	elimDups(words);
	//按长度再排序
	stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {return a.size() < b.size(); });
	//找到符合条件的下一个元素
	auto it = find_if(words.begin(), words.end(), [sz](const string& s) {return s.size() >= sz; });
	//获取元素个数
	auto count = words.end() - it;	
	cout << "有" << count << "个元素大于等于" << sz << endl;

	//打印
	for_each(it, words.end(), [](const string& s) {cout << s<<" "; });
}
#else
	//stable_partition替代find_if   count_if计数
void Biggest(vector<string>& words, vector<string>::size_type sz)
{
	//删除重复元素，按照字典序排序
	elimDups(words);
	//按长度再排序
	stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {return a.size() < b.size(); });
	for_each(words.begin(), words.end(), [](const string& s) {cout << s << " "; });
	//符合条件在前面，不复合条件在后面
	auto itNotfir=stable_partition(words.begin(), words.end(), [sz](const string& s) {return s.size() >=sz; });
	//返回第一个不符合条件的位置
	//获取大于6的元素个数
	auto count = count_if(words.begin(), itNotfir, [](const string& s) {return s.size() > 6; });
	cout << endl << "有" << count << "个元素大于等于 6" << sz << endl;
	//打印
	for_each(words.begin(),itNotfir, [](const string& s) {cout << s<<" "; });
}
#endif


void func1()
{
	size_t a = 50;
	auto f = [a] {return a; };
	a = 10;
	cout << f() << endl;
}

void func2(vector<string>& words, vector<string>::size_type sz, ostream& os = cout, char c = ' ')
{
	// os隐式捕获：引用捕获方式  c显示捕获
	for_each(words.begin(), words.end(), [&, c](const string& s) {os << s << c; });
	// os显式捕获：引用捕获方式  c隐式捕获
	for_each(words.begin(), words.end(), [=,&os](const string& s) {os << s << c; });
}
void func3()
{
	auto v1 = 50;
	auto f = [v1]()mutable {return ++v1; };
	v1 = 0;
	cout << f() << endl;	// 51
}
void func4()
{
	int num = 5;
	auto f = [num]()mutable->bool {return (--num > 0) ? false : true; };	//递减局部变量的值
	for (int i = 0; i < 5; i++)
	{
		cout << f() << endl;
	}
}
bool check_size(const int& str, string::size_type sz)
{
	return sz > str;
}

bool xiaoyu6(const string& s, int len)
{
	return s.size() < len;
}
int main()
{
#if 0
	int ia[]{ 1,2,3,4,5,6 };
	int val = 5;
	int* p = find(begin(ia), end(ia), val);
	cout << *p << endl;
#elif 0
	vector<string> a;
	string temp;
	while (cin >> temp && temp != "quit")
	{
		a.push_back(temp);
	}
	auto num = accumulate(cbegin(a), cend(a), string(""));
	cout << num << endl;
#elif 0
	vector<double> a{ 1.5,2,3,4,5,6 };
	list<int> b{ 1,2,3,4,5,6};
	//可以是不用类型的容器
	cout << accumulate(cbegin(a), cend(a), 0) << endl;
#elif 0
	vector<string> s{ "woaini","hhh","666","niubi" };
	vector<const char*> s1{ "woaini","hhh","666","niubi" };
	cout << equal(cbegin(s), cend(s), cbegin(s1));
#elif 0
	vector<int> a(10);
	fill(begin(a), end(a), 1);
#elif 0
	vector<int> a(99);
	fill_n(begin(a), a.size(), 55);
#elif 0
	vector<int> a;
	fill_n(back_inserter(a), 100, 10);
#elif 0
	vector<double> a{ 1.5,2,3,4,5,6,7,8,5,10,11,5,5,5 };
	list<int> b;
	//可以是不同类型的容器
	replace_copy(cbegin(a), cend(a), back_inserter(b), 5, 666);
#elif 0
	int ar[]{ 1,2,3,4,5,6 };
	fill_n(begin(ar), sizeof(ar)/sizeof(ar[0]), 0);
#elif 0
	vector<int> a;
	list<int> b;
	int i = 0;
	while (cin >> i)
	{
		a.push_back(i);
	}
	
	copy(cbegin(a), cend(a), begin(b));
#elif 0
	vector<int> a;
	a.resize(10);
	fill_n(a.begin(), 10, 0);
#elif 0
	vector<int> a;
	int temp;
	while (cin >> temp)
	{
		a.push_back(temp);
	}
	for (auto x : a)
	{
		cout << x << " ";
	}
	cout << endl;
	//先排序
	sort(begin(a), end(a));
	for (auto x : a)
	{
		cout << x << " ";
	}
	cout << endl;
	//再消除
	auto it=unique(begin(a), end(a));
	for (auto x : a)
	{
		cout << x << " ";
	}
	cout << endl;
	//最后删除
	a.erase(it, a.end());
	for (auto x : a)
	{
		cout << x << " ";
	}
	cout << endl;
#elif 0
	vector<string> a{ "two","ab","yu","pp","gh","dawbiesfnos","so","danidnwfiafdawadadadaw" };
	//先排序
	sort(begin(a), end(a));
	//再消除
	auto it = unique(begin(a), end(a));
	//最后删除
	a.erase(it, a.end());
	//stable_sort(begin(a), end(a), isShorter);
	for (const auto& x : a)
	{
		cout << x << "\t";
	}
#elif 0

bool isLetter(const s1& a, const s1& b);
vector<s1> a(2);
s1 num = { 5,10 }, num2 = { 9,56 };
a.push_back(num);
a.push_back(num2);
//使用lamdba
sort(a.begin(), a.end(), [](const s1& a, const s1& b) {return a.a + a.c > b.c + b.a; });

for (auto& x : a)
{
	cout << x.a << x.c << "\t";
}
cout << endl;
#elif 0
vector<string> words{ "abcde","oiodwa","cenjd","66","yt","hhg","envisenvesv","uiytr" };
auto it=partition(words.begin(), words.end(), isfive);
for (auto iter = words.cbegin(); iter != it; ++iter)
{
	cout << *iter << '\t';
}
cout << endl;
auto x=find_if(words.cbegin(), words.cend(), isShorter);
cout << *x << endl;

#elif 0
auto f = [] {return 42; };
cout << f() << endl;

#elif 0
vector<string> a{ "two","ab","yu","pp","gh","dawbiesfnos","so","danidnwfiafdawadadadaw" };
stable_sort(a.begin(), a.end(), [](const string& a, const string& b) {return a.size() > b.size(); });

for (const auto& x : a)
{
	cout << x << "\t";
}


/*
lamdba测试
*/

#elif 0
auto f = [](const int& a, const int& c) {return a + c; };
cout << f(99,-100) << endl;
int num = 99;
auto f1 = [num](const int& a) {cout << a + num; };
f1(5);

#elif 0

/*
长度大于等于sz的string测试
vector<string>
*/
vector<string> a;
string temp;
while (cin >> temp)
{
	a.push_back(temp);
}
Biggest(a, 5);
#elif 0

func1();

#elif 0
int ar[] = { -1,-2,-3,-4,-5,-6,9,8,7,4,-5 };
transform(begin(ar), end(ar), begin(ar), [](int& i) {return (i < 0) ? -i : i; });
for_each(cbegin(ar), cend(ar), [](const int& a) {cout<<a<<" "; });

#elif 0
int ar[] = { -1,-2,-3,-4,-5,-6,9,8,7,4,-5 };
transform(begin(ar), end(ar), begin(ar), [](int i)->int {if (i < 0)return  -i; else return i; });
for_each(cbegin(ar), cend(ar), [](const int& a) {cout << a << " "; });
#elif 0

	func4();

#elif 0

auto check6 = bind(check_size, placeholders::_1, 6);

string s{ "woaini" };
auto b1 = check6(s);		//调用check_size(s,6)
ostream& print(ostream & os, const string & s, char c)
{
	return os << s << c;
}
for_each(words.begin(), words.end(), bind(print, os, _1, ' '));

#elif 1
string s = "woaini";
vector<int> a{ 1,2,5,6,9,15,20 };
string::size_type len = s.size();
cout << "第一个: " << *(find_if(a.begin(), a.end(), bind(check_size, placeholders::_1, len))) << endl;
#endif
	return 0;
}

bool isShorter(const string& a,const string& b)
{
	return a.size() >= b.size();
}

bool isfive(const string& s1)
{
	return s1.size() >= 5;
}

void elimDups(vector<string>& words)
{
	//字母顺序排序 
	sort(words.begin(), words.end());
	//消除重复元素
	auto it = unique(words.begin(), words.end());
	//删除元素
	words.erase(it, words.end());
}

bool isLetter(const s1& a, const s1& b)
{
	return (a.a + a.c) < (b.a + b.c);
}
