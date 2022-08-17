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
		return { v.back(),v.back().size() };	//��ʽ�б��ʼ��
	}
	else
	{
		return pair<string, int>();				//��ʽ���췵��ֵ
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
		//�ҵ�����word��û�ҵ�����β�������
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
			*it = tolower(*it);	//ͳһת��ΪСд
		}
		word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
		//�ҵ�����word��û�ҵ�����β�������
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
	map<string, vector<pair<string,string>>> peo;	//�գ� ���ֺ�����
	string fname, name, birth;
	int choice = 0;
	while ([&]()->bool {cout << "�������ͥ����: "; return (cin >> fname) && (fname != "quit"); }())
	{
		while ([&]()->bool {cout << "����������: "; return (cin >> name) && (name != "quit"); }())
		{
			if ([&]()->bool {cout << "����������: "; return (cin >> birth) && (birth != "quit"); }())
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
while (getline(in, temp))//�ȴ��ı��ж�ȡһ����
{
	istringstream read(temp);//�󶨸ոն�ȡ����һ����
	while (read >> str)//��string�������ж�ȡ����  һ�ζ�ȡһ��
	{
		a[str].push_back(line);//���ոն�ȡ���ĵ���(key��)�����к�(value_typeֵ)
	}
	line++;//���궨������Ϻ��1  ��ʾ�ڶ���
}
for (auto iter = a.begin(); iter != a.end(); ++iter)
{
	cout << "���ʣ�" << iter->first << "\t�кţ�" << *(iter->second).begin() << endl;
	//��Ϊvalue_typeֵΪlist  ����ʹ���±������  ����ͨ�������øõ������õ����
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
	a.push_back({ temp,num });	//��ʽ����
	a.push_back(pair<string, int>{temp, num}); //��ʽ����
	a.push_back(make_pair(temp, num));	//make_pair����
	a.emplace_back(temp, num);			//emplace_back���캯��
}

#elif 0
map<string, int> a{ {"ylh",666} };
auto map_it = a.begin();
cout << map_it->first << " " << map_it->second << endl;
map_it->first = "woaini";	//���󣬹ؼ�����const
++map_it->second;	//���Ե����������ı�Ԫ��

#elif 0
set<int> a{ 1 };
auto set_it = a.begin();
++(* set_it)	//����set�ؼ���ֻ��

#elif 0
multiset<string> c;
vector<string> v{"woaini","ylh","oiu","abcd"};
copy(v.cbegin(), v.cend(), inserter(c, c.end()));
copy(c.cbegin(), c.cend(),back_inserter(v));

#elif 0
map<string, int> a{ {"ylh",666} };
map<string, int>::iterator map_it = a.begin();
cout << map_it->first << " " << map_it->second << endl;
map_it->first = "woaini";	//���󣬹ؼ�����const
++map_it->second;	//���Ե����������ı�Ԫ��

#elif 0
vector<int> a{ 2,4,6,8,10 };
set<int> set2;
set2.insert(a.cbegin(), a.cend());	//5��
set2.insert({ 1,3,5,7,1,3,5,7 });	//4��
//�ܹ�9��
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
	cout << it->first << " ";	//�õ�string
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
while ([&]()->bool {cout << "����������: "; return cin >> fname && fname != "quit"; }())
{
	auto it_ist = a.insert(make_pair(fname, temp));
	while ([&]()->bool {cout << "����������: "; return cin >> name && name != "quit"; }())
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
	cout<<a.erase("wo");	//���Ϊ2

#elif 0
multimap<string, int> a{ {"ylh",666},{"ylh",999},{"ylh",888},{"asd",555} };
auto a_count = a.count("ylh");	//���ҳ�ָ���ֳ��ֵĴ���
auto it_beg = a.find("ylh");	//���ҵ�һ�����ֵ�λ��
while (a_count)
{
	cout << it_beg->second << " ";	//��ӡĿ��
	++it_beg;						//��������һĿ��
	--a_count;						//�����ݼ�
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

