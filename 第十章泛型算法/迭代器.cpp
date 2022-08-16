#include <iostream>
#include <fstream>
#include <istream>
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

int main()
{
#if 0
	deque<int> a{ 1,2,3,4,5,6 };
	list<int> b, c{1};
	auto it = inserter(c, c.begin());
	copy(a.cbegin(), a.cend(), front_inserter(b));
	copy(a.cbegin(), a.cend(), it);
	*it = 555;

#elif 0
	vector<int> a{ 1,1,2,2,3,4,5,6,7,7,8,8,9,10 };
	list<int> b;
	sort(a.begin(), a.end());
	unique_copy(a.cbegin(), a.cend(), inserter(b,b.begin()));

#elif 0
	vector<int> a{ 1,2,3,4,5,6,7,8,9 };
	deque<int> b;
	list<int> c;
	forward_list<int> d;

	copy(a.cbegin(), a.cend(), inserter(b,b.begin()));
	copy(a.cbegin(), a.cend(), inserter(c,c.begin()));
	copy(a.cbegin(), a.cend(), front_inserter(d));

#elif 0
	
	istream_iterator<int> int_int(cin),eof_hhh;
	cout << accumulate(int_int, eof_hhh, 0) << endl;

#elif 0
	ostream_iterator<int> out_iter(cout, " ");
	vector<int> a{ 1,2,3,4,5,6,7,8,9 };
	copy(a.cbegin(), a.cend(), out_iter);

#elif 0
	ifstream out_file("1.txt");
	istream_iterator<string> string_in(out_file),eof;
	ostream_iterator<string> out(cout, "\t");
	vector<string> a{ string_in,eof };
	copy(a.cbegin(), a.cend(), out);

#elif 0
	istream_iterator<int> in(cin), eof;
	ostream_iterator<int> out(cout, " ");
	vector<int> a;
	copy(in, eof, inserter(a, a.begin()));
	sort(a.begin(), a.end());
	unique_copy(a.cbegin(), a.cend(), out);

#elif 0
	ifstream in_file("输入.txt");
	ofstream out_file1("输出1.txt"),out_file2("输出2.txt");
	istream_iterator<int> in(in_file), eof;
	vector<int> temp{ in,eof };
	ostream_iterator<int> out1(out_file1, "\n"), out2(out_file2, " ");
	auto iter=partition(temp.begin(),temp.end(), [](const int& num) {return (num % 2 == 0) ? true : false; });	 //偶数在前，奇数在后
	//iter 指向最后一个使谓词为true的下一个位置，即第一个false的位置。
	copy(temp.begin(), iter,out1);	//偶数
	copy(iter, temp.end(), out2);		//奇数

#elif 0
	vector<int> a{ 1,2,3,4,5,7,8,9 };
	for (auto r_iter = a.crbegin(); r_iter != a.crend(); ++r_iter)
	{
		cout << *r_iter << " ";
	}
	sort(a.rbegin(), a.rend());

#elif 0
	string temp{"woainiylh,wdada"};
	auto iter = find(temp.cbegin(), temp.cend(), ',');
	cout << string(temp.cbegin(), iter) << endl;
	auto riter = find(temp.crbegin(), temp.crend(), ',');
	cout << string(riter.base(),temp.cend());

#elif 0
	istream_iterator<int> in(cin),eof;
	ostream_iterator<int> out(cout," ");
	vector<int> a{in,eof};
	copy(a.cbegin(), a.cend(), out);
	cout << endl;
	//copy(a.crbegin(), a.crend(), out);
	for (auto it = a.end(); it != a.begin(); --it)
	{
		*out++ = *(it-1);
	}

#elif 0
	list<int> a{ 1,2,3,0,4,5,6,0,7,8,9,0,11,12,0,15 };
	auto it=find(a.crbegin(), a.crend(), 0);
	cout << *it << endl;

#elif 0
	vector<int> a{ 1,2,3,4,5,6,7,8,9,10 };
	list<int> b{ a.crbegin() + 3,a.crend() - 2 };
	/*auto it1 = find(a.cbegin(), a.cend(), 3);
	auto it2 = find(a.cbegin(), a.cend(), 7);
	copy(it1, it2+1, front_inserter(b));*/
	for_each(b.cbegin(), b.cend(), [](const int& num) {cout << num << " "; });
#elif 0
list<string> a;
string temp;
while (cin >> temp)
{
	a.push_back(temp);
}
a.sort();
a.unique();
for_each(a.cbegin(), a.cend(), [](const string& s) {cout << s << " "; });
#elif 1
string str = "www*****ssssdojwdassssaaaa*****";
stable_sort(str.begin(), str.end());
auto it =unique(str.begin(), str.end());
str.erase(it, str.end());
for_each(str.cbegin(), str.cend(), [](const char& s) {cout << s; });
#endif
	return 0;
}