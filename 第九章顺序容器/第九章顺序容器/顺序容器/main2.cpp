#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <list>
#include <forward_list>
#include <stack>
#include <queue>
using namespace std;

int main()
{
#if 0
	vector<int> a;
	a.reserve(50);
	cout << "size: " << a.size() << "\t" << "capacity: " << a.capacity() << endl;
	while (a.size() != a.capacity())
	{
		a.push_back(1);
	}
	a.push_back(99);
	cout << "size: " << a.size() << "\t" << "capacity: " << a.capacity() << endl;
	a.shrink_to_fit();
	cout << "size: " << a.size() << "\t" << "capacity: " << a.capacity() << endl;
	a.resize(a.size() + a.size() / 2);
	cout << "size: " << a.size() << "\t" << "capacity: " << a.capacity() << endl;

#elif 1
	deque<int> deq{ 1,2,3 };
	stack<int> stk(deq);

	stack<string, vector<string>> str_stk;

	//’ª  ≈‰∆˜
	stack<int> intStack;
	for (int i = 0; i < 10; i++)
	{
		intStack.push(i);
	}
	while (!intStack.empty())
	{
		int val = intStack.top();
		intStack.pop();
	}
	
	//∂”¡–  ≈‰∆˜
	queue<int> Que;
	for (int i = 0; i < 10; i++)
	{
		Que.push(i);
	}
	while (!Que.empty())
	{
		int val = Que.front();
		Que.pop();
	}
#endif
	return 0;
}