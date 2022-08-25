
#include "标头.h"
#include <string.h>

shared_ptr<int> factory(int arg)
{
	//.......
	return make_shared<int>(arg);
}
void use_factory1(int arg)
{
	shared_ptr<int> p = factory(arg);
}
shared_ptr<int> use_factory2(int arg)
{
	shared_ptr<int> p = factory(arg);
	return p;
}

void Scanf_Vector(vector<int>* pFunc);
void Printf_Vector(vector<int>* pFunc);

#if 0 //内置指针
void VECTOR()
{
	vector<int>* pVector = new vector<int>;
	Scanf_Vector(pVector);
	Printf_Vector(pVector);
	delete pVector;
	pVector = nullptr;
}
void Scanf_Vector(vector<int>* pFunc)
{
	int temp;
	while (cin >> temp)
	{
		pFunc->push_back(temp);
	}
}
void Printf_Vector(vector<int>* pFunc)
{
	//for_each(pFunc->cbegin(), pFunc->cend(), ostream_iterator<int>(cout, " "));
	for (auto it = pFunc->cbegin(); it != pFunc->cend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

}
#else		//shared_ptr指针
shared_ptr<vector<int>> VECTOR()
{
	shared_ptr<vector<int>> pVector(new vector<int>);	//默认初始化
	return pVector;
}
void Scanf_Vector(shared_ptr<vector<int>> pFunc)
{
	int temp;
	while (cin >> temp)
	{
		pFunc->push_back(temp);
	}
}
void Printf_Vector(shared_ptr<vector<int>> pFunc)
{
	for (auto it = pFunc->cbegin(); it != pFunc->cend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

}
#endif
	
unique_ptr<int> Clone1(int p)
{
	return unique_ptr<int>(new int(p));		//从函数返回unique_ptr指针
}
unique_ptr<int> Clone2(int p)
{
	unique_ptr<int> ret(new int(p));
	return ret;
}
int main()
{
#if 0
	shared_ptr<string> p1;
	if (p1 && p1->empty())
	{
		*p1 = "hi";
	}
	
#elif 0
	//指向一个值为42的int的shared_ptr
	shared_ptr<int> p1 = make_shared<int>(42);
	shared_ptr<string> p2 = make_shared<string>(10, '*');//10个*
	shared_ptr<int> p3 = make_shared<int>();	//值初始化，0

#elif 0
	shared_ptr<int> q = make_shared<int>(5);
	shared_ptr<int> p = make_shared<int>(10);
	auto q=p;	//q原来的对象，即5被释放

#elif 0
	shared_ptr<int> p = factory(10);

#elif 0
	vector<int> v1;
	{
		vector<int> v2{ 1,2,3,4,5 };
		v1 = v2;
	}
	copy(v1.cbegin(), v1.cend(), ostream_iterator<int>(cout, " "));

#elif 0
	strBlob b1;
	{
		strBlob b2{ "a","abc","abcd" };
		b1 = b2;
		b2.push_back("about");
	}
	b1.front() += "pol";
	cout << b1.front() << endl;
#elif 0
	auto x = new auto("abc");
	const int* a = new const int(10);
	const string* b = new const string("abc");
	auto c = new const string("5");

#elif 0
	int* p1 = new int;		//分配失败，new抛出bad_alloc
	int* p2 = new (nothrow) int;	//分配失败，new返回一个空指针

#elif 0
	const int* p = new const int(10);
	auto q = p;	//q和p被绑定到同一个对象
	delete p;				//释放p，q也被释放
	p = nullptr;			//只把p设置为空指针，但是q仍然保存着已经释放了的动态内存地址

#elif 0
	shared_ptr<vector<int>> p=VECTOR();
	Scanf_Vector(p);
	Printf_Vector(p);

#elif 0
	int* q = new int(42), * p = new int(100);
	p = q;		//普通指针，进行赋值后，指向新的内存空间，但是原来的内存会一直保留，造成内存泄露
	auto q2 = make_shared<int>(42), p2 = make_shared<int>(100);
	p2 = q2;	//智能指针，进行赋值后，会自动递减计数器，释放原有内存

#elif 0
	void process(shared_ptr<int> ptr)
	{
		//....
	}
	//正确方式：
	shared_ptr<int> p(new int(400));
	process(p);
	int i = *p;
	//错误方式：
	int* x(new int(42));			//危险：x不是智能指针
	process(x);						//错误，不能将int* 转换为shared_ptr
	process(shared_ptr<int>(x));	//合法，但是内存会被释放
	int j = *x;						//未定义，x是一个空悬指针

#elif 0
	shared_ptr<int> p(new int(100));
	int* q = p.get();		// p 和 q共享一个内存的使用权
	//shared_ptr<int> s = p.get();	//错误

	delete q;				//释放q，导致p也被释放
	int foo = *p;

#elif 0
	shared_ptr<int> p(new int(100));
	auto q(p);
	if (!p.unique())
	{
		p.reset(new int(*p));
	}
	*p += 10;

#elif 0
	unique_ptr<int> p{ new int(100) };
	unique_ptr<int> q{ p };	//不支持拷贝
	unique_ptr<int> c;
	c = p;					//不支持赋值

#elif 0
	unique_ptr<int> p{ new int(100) };
	unique_ptr<int> q(p.release());		//转移给q
	unique_ptr<int> c;
	c.reset(q.release());

#elif 0
auto p1=Clone1(10);
auto p2 = Clone2(20);

#elif 0
auto p = make_shared<int>(42);
weak_ptr<int> wp(p);
p.reset();
cout << wp.lock() << endl;

#elif 0
int* p1 = new int[50];	//分配50个int的空间，不必是常量

typedef int arrT[50];	//起别名，arrT表示一个50个int的数组类型
int* p2 = new arrT;		//分配50个元素的数组

#elif 0
int* p = new int[10] {1, 2, 3, 4, 5};

#elif 0
unique_ptr<int[]> p(new int[10]);
shared_ptr<int[]> q(new int[20], [](int* q) {delete[] q; });

for (size_t i = 0; i != 10; ++i)
{
	*(q.get()+i) = i;
}
for (size_t i = 0; i!= 10; ++i)
{
	cout << *(q.get() + i) << " ";
}
q.reset();	//使用lamdba释放数组，使用delete[]

#elif 0
const char* s1 = "abc";
const char* s2 = "efg";//字符串字面常量,字符串末尾有空格
string si = "a";
string sl = "b";//标准库string对象
char* p = new char[strlen(s1) + strlen(s2) + 1];//必须指明要分配对象的个数
strcpy(p, s1);//复制
strcat(p, s2);//接上
cout << p << endl;
//strcpy(p, (si + sl).c_str());//必须转换为c类型字符串(c中无string类型)
//cout << p << endl;
delete[] p;

#elif 0
string s;
while (cin >> s)
{
	char* str = new char[s.size()+1];
	strcpy(str, s.c_str());
	cout << str << " ";
}

#elif 0
allocator<string> alloc;	//可以分配string的allocator对象
auto p = alloc.allocate(10);//可以分配n个未初始化的string
auto q = p;
alloc.construct(q++, 10, 'c');
alloc.construct(q++);
alloc.construct(q++, "hi");
cout << *p << endl;
while (q != p)
{
	alloc.destroy(--q);	//释放我们真正构造的string对象
}

#elif 0
vector<int> a{ 1,2,3,4,5,6,7,8,9 };
allocator<int> alloc;
//创建一个比容器大两倍的初始内存
auto p = alloc.allocate(a.size() * 2);
//返回得到的q指向最后一个构造元素之后的位置
auto q = uninitialized_copy(a.cbegin(), a.cend(), p);
//填充42
uninitialized_fill_n(q, a.size(), 42);

#elif 1
allocator<string> alloc;
string s;
auto str = alloc.allocate(10);
auto p = str;
while (cin>>s && p != str + 10)
{
	alloc.construct(p++, s);
}
while (p != str)
{
	alloc.destroy(--p);
}
alloc.deallocate(str, 10);

#endif
	return 0;				//在最后p释放时，已经指向了无效的区域
}

