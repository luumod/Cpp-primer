#include "��ͷ.h"

strBlobPtr strBlob::begin()
{
	return strBlobPtr(*this);
}

strBlobPtr strBlob::end()
{
	auto ret = strBlobPtr(*this, data->size());
	return ret;
}

strBlob::strBlob()
	:data(make_shared<vector<string>>())
{
}

strBlob::strBlob(initializer_list<string> il)
	:data(make_shared<vector<string>>(il))
{
}

void strBlob::pop_back()
{
	check(0, "pop_back on empty Blob!\n");
	return data->pop_back();
}

string& strBlob::front()
{
	check(0, "front on empty Blob!\n");
	return data->front();
}

string& strBlob::back()
{
	check(0, "back on empty Blob!\n");
	return data->back();
}

string& strBlob::front() const
{
	check(0, "front on empty Blob!\n");
	return data->front();
}

string& strBlob::back() const
{
	check(0, "back on empty Blob!\n");
	return data->back();
}

void strBlob::check(size_t i, const string& msg) const
{
	//�����������
	if (i >= data->size())
	{
		throw out_of_range(msg);	//������Ϣ�����쳣�������
	}
}

shared_ptr<vector<string>> strBlobPtr::check(size_t i, const string& msg) const
{
	auto ret = wptr.lock();	//vector��������
	if (!ret)
	{
		throw runtime_error("unbound strBlobPtr\n");
	}
	if (i >= ret->size())
	{
		throw out_of_range(msg);
	}
	return ret;
}

string& strBlobPtr::deref() const
{
	// TODO: �ڴ˴����� return ���
	auto p = check(curr, "defference past end");
	return (*p)[curr];
}

strBlobPtr& strBlobPtr::incr()
{
	// TODO: �ڴ˴����� return ���
	check(curr, "increment past end of strBlobPtr.");
	++curr;
	return *this;
}
