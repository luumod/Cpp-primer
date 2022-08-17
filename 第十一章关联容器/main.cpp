#include <iostream>
#include <string>
#include <istream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <utility>
#include <algorithm>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <cctype>
using namespace std;

pair<string, int> process(vector<string>& v)
{
	if (!v.empty())
	{
		return { v.back(),v.back().size() };	//显式列表初始化
	}
	else
	{
		return pair<string, int>();				//隐式构造返回值
	}
}

map<string, string> bulidMap(ifstream& map_file)
{
	map<string, string> trans_file;
	string key;
	string value;
	while (map_file >> key && getline(map_file, value))
	{
		if (value.size() > 1)
		{
			//trans_file[key] = value.substr(1);
			trans_file.insert({ key,value.substr(1) });
		}
		else
		{
			throw runtime_error("no rule for " + key);
		}
	}
	return trans_file;
}
const string& transform(const string& s, const map<string, string>& m)
{
	auto map_find = m.find(s);
	if (map_find != m.cend())
	{
		return map_find->second;
	}
	else
	{
		return s;
	}
}
void word_transform(ifstream& map_file, ifstream& input)
{
	auto trans_map = bulidMap(map_file);
	string text;
	while (getline(input, text))
	{
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word)
		{
			if (firstword)
			{
				firstword = false;
			}
			else
			{
				cout << " ";
			}
			cout << transform(word, trans_map);
			cout << endl;
		}
	}
}
int main()
{
#if 0
	unordered_map<string, size_t> word_count;
	string word;
	while (cin >> word)
	{
		++word_count.insert({ word,0 }).first->second;
		/*auto it = word_count.insert(make_pair(word, 1));
		if (!it.second)
		{
			++it.first->second;
		}*/
	}
	for (const auto& x : word_count)
	{
		cout << x.first << " occurs " << x.second << ((x.second > 1) ? " times" : " time") << endl;
	}

#elif 0
	map<string, size_t> word_count;
	set<string> exclude{ "the","woaini","666","hhh","adaasa","dawdadadas","ylh","dwadada" };

	string word;
	while (cin >> word)
	{
		//找到返回word，没找到返回尾后迭代器
		if (exclude.find(word) == exclude.end())
		{
			++word_count[word];
		}
	}
	for (const auto& x : word_count)
	{
		cout << x.first << " occurs " << x.second << ((x.second > 1) ? " times" : " time") << endl;
	}

#elif 0
	map<string, size_t> word_count;
	set<string> exclude{ "the","woaini","666","hhh","adaasa","dawdadadas","ylh","dwadada" };

	string word;
	while (cin >> word)
	{
		for (auto it = word.begin(); it != word.end(); ++it)
		{
			*it = tolower(*it);	//统一转换为小写
		}
		word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
		//找到返回word，没找到返回尾后迭代器
		if (exclude.find(word) == exclude.end())
		{
			++word_count[word];
		}
	}
	for (const auto& x : word_count)
	{
		cout << x.first <<" : " << x.second << ((x.second > 1) ? " times" : " time") << endl;
	}

#elif 0
	map<string, string> a{
		{"ylh","da"},
		{"dad","oid"},
		{"oda","cece"} };
	set<string> b{ "wad","Da","grg","plda" };

#elif 0
	vector<int> a;
	for (size_t i = 0; i != 10; ++i)
	{
		a.push_back(i);
		a.push_back(i);
	}
	asdfg
	set<int> b1{ a.cbegin(),a.cend() };			//set.size()= 10
	multiset<int> b2{ a.cbegin(),a.cend() };	//multiset.size()= 20

#elif 1
	map<string, vector<pair<string,string>>> peo;	//姓： 名字和生日
	string fname, name, birth;
	int choice = 0;
	while ([&]()->bool {cout << "请输入家庭姓氏: "; return (cin >> fname) && (fname != "quit"); }())
	{
		while ([&]()->bool {cout << "请输入姓名: "; return (cin >> name) && (name != "quit"); }())
		{
			if ([&]()->bool {cout << "请输入生日: "; return (cin >> birth) && (birth != "quit"); }())
			{
				peo[fname].emplace_back(name, birth);
			}
		}
	}

	cout << endl;
	for (const auto& i : peo)
	{
		cout << i.first << ": " << endl;
		for (const auto& y : i.second)
		{
			cout << y.first << ", " << y.second << endl;
		}
	}

#elif 0
map<string, list<int>> a;

int line = 1;
string temp,str;
ifstream in("text.txt");
while (getline(in, temp))//先从文本中读取一整行
{
	istringstream read(temp);//绑定刚刚读取到的一整行
	while (read >> str)//从string输入流中读取单词  一次读取一个
	{
		a[str].push_back(line);//将刚刚读取到的单词(key键)关联行号(value_type值)
	}
	line++;//读完定义行完毕后加1  表示第二行
}
for (auto iter = a.begin(); iter != a.end(); ++iter)
{
	cout << "单词：" << iter->first << "\t行号：" << *(iter->second).begin() << endl;
	//因为value_type值为list  不能使用下标运算符  这里通过解引用该迭代器得到输出
}

#elif 0
pair<string, string> a;
pair<string, size_t> b;
pair<string, list<size_t>> c;
	
#elif 0
vector<pair<string, int>> a;
string temp;
int num;
while (cin >> temp >> num)
{
	a.push_back({ temp,num });	//隐式构造
	a.push_back(pair<string, int>{temp, num}); //显式构造
	a.push_back(make_pair(temp, num));	//make_pair构造
	a.emplace_back(temp, num);			//emplace_back构造函数
}

#elif 0
map<string, int> a{ {"ylh",666} };
auto map_it = a.begin();
cout << map_it->first << " " << map_it->second << endl;
map_it->first = "woaini";	//错误，关键字是const
++map_it->second;	//可以递增迭代器改变元素

#elif 0
set<int> a{ 1 };
auto set_it = a.begin();
++(* set_it)	//错误，set关键字只读

#elif 0
multiset<string> c;
vector<string> v{"woaini","ylh","oiu","abcd"};
copy(v.cbegin(), v.cend(), inserter(c, c.end()));
copy(c.cbegin(), c.cend(),back_inserter(v));

#elif 0
map<string, int> a{ {"ylh",666} };
map<string, int>::iterator map_it = a.begin();
cout << map_it->first << " " << map_it->second << endl;
map_it->first = "woaini";	//错误，关键字是const
++map_it->second;	//可以递增迭代器改变元素

#elif 0
vector<int> a{ 2,4,6,8,10 };
set<int> set2;
set2.insert(a.cbegin(), a.cend());	//5个
set2.insert({ 1,3,5,7,1,3,5,7 });	//4个
//总共9个
#elif 0
multimap<string, int> a;
a.insert(pair<string, int>{"ylh", 666});
a.insert({ "word",111 });
a.insert(make_pair("word", 222));
a.insert(map<string, int>::value_type{ "word",333 });

#elif 0
vector<size_t> temp{ 1,2,3,4,5,6 };
map<string, vector<size_t>> a;
string word = "word";
pair<map<string, vector<size_t>>::iterator, bool> it = a.insert(make_pair(word,temp));

for (auto it = a.cbegin(); it != a.cend(); ++it)
{
	cout << it->first << " ";	//得到string
	for (auto it2 = it->second.cbegin(); it2 != it->second.cend(); ++it2)
	{
		cout << *it2 << " ";
	}
	cout << endl;
}
//for_each(a.cbegin()->first, a.cbegin()->first, [](const string& str) {cout << str << " :"; });
//for_each(a.cbegin()->second.cbegin(), a.cbegin()->second.cend(), [](const size_t& num) {cout << num << " "; });

#elif 0
multimap<string, vector<string>> a;
string fname, name;
vector<string> temp;
while ([&]()->bool {cout << "请输入姓氏: "; return cin >> fname && fname != "quit"; }())
{
	auto it_ist = a.insert(make_pair(fname, temp));
	while ([&]()->bool {cout << "请输入姓名: "; return cin >> name && name != "quit"; }())
	{
		//it_ist->second.push_back(name);
	}
}

for (auto it1 = a.cbegin(); it1 != a.cend(); ++it1)
{
	cout << it1->first << " : ";
	for (auto it2 = it1->second.cbegin(); it2 != it1->second.cend(); ++it2)
	{
		cout << *it2 << " ";
	}
	cout << endl;
}

#elif 0
	multimap<string, int> a{ {"wo",1},{"ar",2},{"wo",2} };
	cout<<a.erase("wo");	//结果为2

#elif 0
multimap<string, int> a{ {"ylh",666},{"ylh",999},{"ylh",888},{"asd",555} };
auto a_count = a.count("ylh");	//查找出指定字出现的次数
auto it_beg = a.find("ylh");	//查找第一个出现的位置
while (a_count)
{
	cout << it_beg->second << " ";	//打印目标
	++it_beg;						//递增到下一目标
	--a_count;						//计数递减
}

#elif 0
multimap<string, int> a{ {"ylh",666},{"ylh",999},{"ylh",888},{"asd",555},{"zdwa",555},{"zoef",565} };
for (auto beg = a.lower_bound("wqe"), end = a.upper_bound("asdad"); beg != end; ++beg)
{
	cout << beg->second << endl;
}
#elif 0
multimap<string, int> a{ {"ylh",666},{"ylh",999},{"ylh",888},{"asd",555},{"zdwa",555},{"zoef",565} };
for (pair<multimap<string,int>::iterator,multimap<string,int>::iterator> beg=a.equal_range("ylh");beg.first!=beg.second;++beg.first)
{
	cout << beg.first->second << endl;
}

#elif 0
multimap<string, int> a{ {"ylh",666},{"ylh",999},{"ylh",888},{"asd",555},{"zdwa",555},{"zoef",565} };
cout << a.count("ylh");

#elif 0
	map<string, vector<int>> a{ {"ylh",{1,2,3}},{"ylh",{4,5,6}},{"hhh",{7,8,9}} };
	auto find_it=a.find("ylh");

#elif 0
	multimap<string, string> a{ {"ylh","iot"} ,{"wad","dwapd"},{"ylh","posa"},{"ylh","zbcd"},{"xsd","podv"}};
	auto beg = a.equal_range("ylh"); 
	a.erase(beg.first,beg.second);

for (auto beg = a.cbegin(); beg != a.cend(); ++beg)
{
	cout << beg->first << ": " << beg->second << endl;
}
#elif 0
ifstream in1("1.txt"), in2("2.txt");
word_transform(in1, in2);

#elif 0

#endif 
	return 0;
}

