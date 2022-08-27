#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <fstream>
#include <string>
#include <istream>
#include <sstream>
#include <deque>
#include <list>
#include <forward_list>
#include <algorithm>
#include <functional>
#include <numeric>
#include <map>
#include <set>
using namespace std;

using line_NO = vector<string>::size_type;
class QueryResult;	//ǰ������
class TextQuery
{
public:
	TextQuery() = default;
	//��ȡָ������Ĺ��캯��
	TextQuery(ifstream& i_file);
	TextQuery(const TextQuery& text) = default;
	//{
	//	file = text.file;
	//	wm = text.wm;
	//}
	~TextQuery() = default;
	TextQuery& operator=(const TextQuery& text) = default;
	/*{
		file = text.file;
		wm = text.wm;
		return *this;
	}*/
	//��ѯ����
	QueryResult query(const string& word)const;	//���������ǣ�����������ݴ�����ӡ���ࡣ
private:
	shared_ptr<vector<string>> file;			//�����ļ�����
	map<string, shared_ptr<set<line_NO>>> wm;	//ÿ�����ʺ��������ֵ��к�

};

class QueryResult
{
	friend ostream& print(ostream& os, const QueryResult& q);
public:
	QueryResult(string s, shared_ptr<set<line_NO>> p, shared_ptr<vector<string>> f)
		:research(s), lines(p), file(f) {}	//�������Զ�ȡ���������
	QueryResult(const QueryResult& qrest) = default;
	/*{
		research = qrest.research;
		lines = qrest.lines;
		file = qrest.file;
	}*/
	QueryResult& operator=(const QueryResult& qrest) = default;
	/*{
		research = qrest.research;
		lines = qrest.lines;
		file = qrest.file;
		return *this;
	}*/
	~QueryResult() = default;
	set<line_NO>::iterator begin()const { return lines->begin(); }
	set<line_NO>::iterator end()const { return lines->end(); }
	shared_ptr<vector<string>> get_file()const { return file; }
private:
	string research;					//��ѯ����
	shared_ptr <set<line_NO>> lines;	//���ֵ��кţ�set����
	shared_ptr <vector<string>> file;	//�����ļ���vector����
};



TextQuery::TextQuery(ifstream& i_file) :file(new vector<string>)
{
	string text;
	while (getline(i_file, text))
	{
		file->push_back(text);	//�ļ�ÿһ�д���vector
		auto No = file->size() - 1;
		istringstream line(text);	//��ȡ��һ��
		string word;
		while (line >> word)
		{
			//��ȡ�е�ÿ������
			auto& lines = wm[word];//lines��һ��shared_ptr
			if (!lines)
			{
				lines.reset(new set<line_NO>);	//����һ���µ�set
			}
			lines->insert(No);	//�����кŲ��뵽set��
		}
	}

}

QueryResult TextQuery::query(const string& word) const
{
	//δ�ҵ���ѯ���ʣ�����һ���յ�set��
	static shared_ptr<set<line_NO>> nodata(new set<line_NO>);
	auto loc = wm.find(word);	//���ҹؼ���
	if (loc == wm.end())		//����һ��ָ������ؼ��ֶ�Ӧ�����е�ֵ��map������
	{
		return QueryResult(word, nodata, file);	//����set���룬��ʾδ�ҵ�
	}
	else
	{
		return QueryResult(word, loc->second, file);	//����ؼ��ֶ�Ӧ��set����
	}
}

ostream& print(ostream& os, const QueryResult& q)
{
	//�ҵ��˵��ʣ���ӡ���ִ����������ֵ�λ��
	//set��size��Ա��������set�ؼ��ֵĸ���
	os << q.research << " occurs " << q.lines->size() << endl;	
	for (auto num : *q.lines)				//�õ���set�ж�Ӧ���к�
	{
		//���ļ��и��ݻ�õ��к�����ӡ
		os << "\t(line " << num + 1 << ") " << *(q.file->begin() + num) << endl;
	}
	return os;
}
