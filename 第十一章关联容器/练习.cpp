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

int main()
{

	map<string,vector<pair<string, size_t>>> family;
	string fname, name;
	size_t age;;
	vector<pair<string, size_t>> temp;
	while ([&]()->bool {cout << "请输入家族姓氏: "; return (cin >> fname && fname != "quit"); }())
	{
		pair<map<string,vector<pair<string,size_t>>>::iterator,bool> find_it = family.insert(make_pair(fname, temp));
		while ([&]()->bool {cout << "请输入家庭成员的成员姓名与年龄: "; return (cin >> name && name != "quit" && cin>>age); }())
		{
			//family[fname].emplace_back(name, age);
			find_it.first->second.emplace_back(name, age);
		}
	}

	//打印的两种方式
	for (const auto& it1 : family)
	{
		cout << it1.first << ": ";
		for (const auto& it2 : it1.second)
		{
			cout << it2.first << "," << it2.second << "; ";
		}
		cout << endl;
	}
	for (map<string, vector<pair<string, size_t>>>::const_iterator it = family.cbegin(); it != family.cend(); ++it)
	{
		cout << it->first << " : ";

		for (vector<pair<string, size_t>>::const_iterator it2 = it->second.cbegin(); it2 != it->second.cend(); ++it2)
		{
			cout << it2->first << ", " << it2->second << " ; ";
		}
		cout << endl;
	}
	return 0;
}