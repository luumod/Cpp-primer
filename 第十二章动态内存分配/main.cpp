
#include "��ͷ.h"
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

#if 0 //����ָ��
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
#else		//shared_ptrָ��
shared_ptr<vector<int>> VECTOR()
{
	shared_ptr<vector<int>> pVector(new vector<int>);	//Ĭ�ϳ�ʼ��
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
	return unique_ptr<int>(new int(p));		//�Ӻ�������unique_ptrָ��
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
	//ָ��һ��ֵΪ42��int��shared_ptr
	shared_ptr<int> p1 = make_shared<int>(42);
	shared_ptr<string> p2 = make_shared<string>(10, '*');//10��*
	shared_ptr<int> p3 = make_shared<int>();	//ֵ��ʼ����0

#elif 0
	shared_ptr<int> q = make_shared<int>(5);
	shared_ptr<int> p = make_shared<int>(10);
	auto q=p;	//qԭ���Ķ��󣬼�5���ͷ�

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
	int* p1 = new int;		//����ʧ�ܣ�new�׳�bad_alloc
	int* p2 = new (nothrow) int;	//����ʧ�ܣ�new����һ����ָ��

#elif 0
	const int* p = new const int(10);
	auto q = p;	//q��p���󶨵�ͬһ������
	delete p;				//�ͷ�p��qҲ���ͷ�
	p = nullptr;			//ֻ��p����Ϊ��ָ�룬����q��Ȼ�������Ѿ��ͷ��˵Ķ�̬�ڴ��ַ

#elif 0
	shared_ptr<vector<int>> p=VECTOR();
	Scanf_Vector(p);
	Printf_Vector(p);

#elif 0
	int* q = new int(42), * p = new int(100);
	p = q;		//��ָͨ�룬���и�ֵ��ָ���µ��ڴ�ռ䣬����ԭ�����ڴ��һֱ����������ڴ�й¶
	auto q2 = make_shared<int>(42), p2 = make_shared<int>(100);
	p2 = q2;	//����ָ�룬���и�ֵ�󣬻��Զ��ݼ����������ͷ�ԭ���ڴ�

#elif 0
	void process(shared_ptr<int> ptr)
	{
		//....
	}
	//��ȷ��ʽ��
	shared_ptr<int> p(new int(400));
	process(p);
	int i = *p;
	//����ʽ��
	int* x(new int(42));			//Σ�գ�x��������ָ��
	process(x);						//���󣬲��ܽ�int* ת��Ϊshared_ptr
	process(shared_ptr<int>(x));	//�Ϸ��������ڴ�ᱻ�ͷ�
	int j = *x;						//δ���壬x��һ������ָ��

#elif 0
	shared_ptr<int> p(new int(100));
	int* q = p.get();		// p �� q����һ���ڴ��ʹ��Ȩ
	//shared_ptr<int> s = p.get();	//����

	delete q;				//�ͷ�q������pҲ���ͷ�
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
	unique_ptr<int> q{ p };	//��֧�ֿ���
	unique_ptr<int> c;
	c = p;					//��֧�ָ�ֵ

#elif 0
	unique_ptr<int> p{ new int(100) };
	unique_ptr<int> q(p.release());		//ת�Ƹ�q
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
int* p1 = new int[50];	//����50��int�Ŀռ䣬�����ǳ���

typedef int arrT[50];	//�������arrT��ʾһ��50��int����������
int* p2 = new arrT;		//����50��Ԫ�ص�����

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
q.reset();	//ʹ��lamdba�ͷ����飬ʹ��delete[]

#elif 0
const char* s1 = "abc";
const char* s2 = "efg";//�ַ������泣��,�ַ���ĩβ�пո�
string si = "a";
string sl = "b";//��׼��string����
char* p = new char[strlen(s1) + strlen(s2) + 1];//����ָ��Ҫ�������ĸ���
strcpy(p, s1);//����
strcat(p, s2);//����
cout << p << endl;
//strcpy(p, (si + sl).c_str());//����ת��Ϊc�����ַ���(c����string����)
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
allocator<string> alloc;	//���Է���string��allocator����
auto p = alloc.allocate(10);//���Է���n��δ��ʼ����string
auto q = p;
alloc.construct(q++, 10, 'c');
alloc.construct(q++);
alloc.construct(q++, "hi");
cout << *p << endl;
while (q != p)
{
	alloc.destroy(--q);	//�ͷ��������������string����
}

#elif 0
vector<int> a{ 1,2,3,4,5,6,7,8,9 };
allocator<int> alloc;
//����һ���������������ĳ�ʼ�ڴ�
auto p = alloc.allocate(a.size() * 2);
//���صõ���qָ�����һ������Ԫ��֮���λ��
auto q = uninitialized_copy(a.cbegin(), a.cend(), p);
//���42
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
	return 0;				//�����p�ͷ�ʱ���Ѿ�ָ������Ч������
}

