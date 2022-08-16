//一个关于泛型算法和迭代器的练习
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <istream>
#include <fstream>
#include <list>
#include <deque>
#include <forward_list>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

int main()
{
#if 0
	//输入方式
	istream_iterator<int> in(cin), eof;
	//全部支持列表初始化
	vector<int> a{ in,eof };
	deque<int> b1;
	deque<int> b2;
	deque<int> b3;
	list<int> c1;
	list<int> c2;
	list<int> c3;
	forward_list<int> d1{ a.cbegin(),a.cend() };
	forward_list<int> d2;
	forward_list<int> d3{a.crbegin(),a.crend()};

	//deque:
	copy(a.cbegin(), a.cend(), back_inserter(b1));
	copy(a.cbegin(), a.cend(), front_inserter(b2));
	copy(a.cbegin(), a.cend(), inserter(b3, b3.begin()));

	//list：
	copy(a.cbegin(), a.cend(), back_inserter(c1));
	copy(a.cbegin(), a.cend(), front_inserter(c2));
	copy(a.cbegin(), a.cend(), inserter(c3, c3.begin()));

	//forward_list:  不支持back与随机inserter
	//copy(a.cbegin(), a.cend(), back_inserter(d1));
	copy(a.cbegin(), a.cend(), front_inserter(d2));
	//copy(a.cbegin(), a.cend(), inserter(d3, d3.begin()));


	//不同的打印方式
	cout << endl;
	ostream_iterator<int> out(cout, "  ");
	for_each(b1.cbegin(), b1.cend(), [](const int& num) {cout<<num<<" "; });
	cout << endl;
	for_each(c1.cbegin(), c1.cend(), [](const int& num) {cout << num<<" "; });
	cout << endl;
	for_each(d1.cbegin(), d1.cend(), [](const int& num) {cout << num<<" "; });

	cout << endl;
	copy(b2.cbegin(), b2.cend(), out);	//也可以使用隐式输出迭代器
	cout << endl;
	copy(c2.cbegin(), c2.cend(), out);
	cout << endl;
	copy(d2.cbegin(), d2.cend(), out);

#elif 0
	ostream_iterator<int> out(cout, "  ");
	vector<string> str;
	string s;
	while (cin >> s && s != "quit")
	{
		str.push_back(s);
	}
	int str_sz = 6;
	//输出
	copy(str.cbegin(), str.cend(), ostream_iterator<string>(cout, "  "));
	//排序  首先按照长度排序,保持原顺序
	stable_sort(str.begin(), str.end(), [](const string& s1, const string& s2) {return s1.size() > s2.size(); });
	cout << endl;
	copy(str.cbegin(), str.cend(), ostream_iterator<string>(cout, "  "));

#elif 1
	ostream_iterator<int> out(cout, "  ");
	vector<int> a{ 1,1,2,3,4,5,6,6,7,8,9,9,5,6,4,5,10,11,12,10 };
	//输出
	copy(a.cbegin(), a.cend(), ostream_iterator<int>(cout, "  "));
	//排序  
	sort(a.begin(), a.end(), [](const int& n1, const int& n2) {return n1 < n2; });
	auto it = unique(a.begin(), a.end());
	auto itend=fill_n(it, a.end() - it, 0);
	cout << endl;
	copy(a.begin(), itend, ostream_iterator<int>(cout, "  "));
	a.erase(it, a.end());
	cout << endl;
	copy(a.cbegin(), a.cend(), ostream_iterator<int>(cout, "  "));
	cout << endl;
	cout << "去重后总和为: " << accumulate(a.begin(), a.end(), 0) << endl;
	auto fin_it = find_if(a.begin(), a.end(), [](const int& num) {return num >= 10; });
	cout << "找到的位置: " << *fin_it << endl;
	stable_partition(a.begin(), fin_it, [](const int& num) {return num % 2; });
	cout << endl;
	copy(a.cbegin(), a.cend(), ostream_iterator<int>(cout, "  "));

	ifstream in("1.txt");
	ofstream out1("输出1.txt");
	ofstream out2("输出2.txt");

	istream_iterator<int> in_file(in), eof;
	ostream_iterator<int> out_file1(out1," "), out_file2(out2," ");

	//从文件读取
	while (in_file != eof)
	{
		a.push_back(*in_file++);
	}
	cout << endl;
	copy(a.cbegin(), a.cend(), ostream_iterator<int>(cout, "  "));

	*out_file1++ = count_if(a.cbegin(), a.cend(), [](const int& num) {return num % 2; });//true 奇数
	vector<int> b;
	partition_copy(a.cbegin(), a.cend(),out_file1,out_file2, [](const int& num) {return num % 2; });
	//copy(b.cbegin(), b.cend(), out);
	is_partitioned()
#endif
	return 0; 
}