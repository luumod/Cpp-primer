
#include "text.hpp"


#if 0
int main()
{
	string file_name;
	cout << "输入文件名:";
	cin >> file_name;
	ifstream in_file(file_name);
	if (!in_file.is_open())
	{
		cerr << "文件打开失败!\n";
		exit(-1);
	}

	vector<string> vec;
	map<string, set<size_t>> MAP;

	string text_str;
	while (getline(in_file,text_str))	//读取每一行，存储在vector的每一个元素
	{
		vec.push_back(text_str);
	}
	for (size_t i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << endl;
	} 
	string research;
	string word;
	while ([&]()->bool{ cout << "请输入你要查询的单词(输入quit退出): "; return (cin >> research && research != "quit"); }())
	{
		for (size_t i = 0; i < vec.size(); ++i)
		{
			istringstream line_str(vec[i]);	//读取每一行
			while (line_str >> word)
			{
				if (research == word)
				{
					MAP[word].insert(i);	// 单词：行号
					break;
				}
			}
		}
		cout << "element occurs " << MAP[research].size() << " times" << endl;
		for (auto it = MAP[research].cbegin(); it != MAP[research].cend(); ++it)
		{
			cout << '\t' << "(line " << *it << ") " << vec[*it] << endl;
		}
	}


	return 0;
}
#else
int main()
{
	ifstream in_file("111.txt");
	TextQuery tq(in_file);
	TextQuery tq2(tq);
	TextQuery tq3;
	tq3 = tq2;
	while (true)
	{
		cout << "请输入要查询的单词,输入quit退出: ";
		string word;
		if (!(cin >> word) || word== "quit")
		{
			break;
		}
		print(cout, tq3.query(word)) << endl;
	}
	return 0;
}


#endif