
#include "Sales_data.h"
#include "Screen.h"
#include "Person.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;



#if 1
int main()
{
#if 0
	Sales_data total;
	if (read(cin,total))
	{
		Sales_data trans;
		while (read(cin,trans))
		{
			if (total.isbn()==trans.isbn())
			{
				add(total, trans);
			}
			else
			{
				print(cout, total);
				total = trans;
			}
		}
		print(cout, total);
	}
	else
	{
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
#elif 1
	string s = "wada";
	Sales_data a(s);
	Sales_data b("dwad");
	
	constexpr int A::c; 
#endif
	
	return 0;
}
#endif


#if 0
int main()
{
	/*Screen a(5, 5, 'X');
	a.move(4, 0).set('#').display(cout);
	cout << "\n";
	a.display(cout);
	cout << "\n";*/

	X a(5);

	return 0;

}
#endif 