#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#if 1
void iostate_test(istream& in) {
	// 流状态打印
	cout << "goodstate: " << in.good() << ", goodbit: " << in.goodbit << endl;
	cout << "failstate: " << in.fail() << ", failbit: " << in.failbit << endl;
	cout << "eofstate: " << in.eof() << ", eofbit: " << in.eofbit << endl;
	cout << "badstate: " << in.bad() << ", badbit: " << in.badbit << endl;
	cout << endl;
}
void Input_Test() {
	int value;
	while (cin >> value) {
		iostate_test(cin);
	}									//假设触发eofbit错误 

	auto old_state = cin.rdstate();			// 记录当前错误状态
	iostate_test(cin);

	cout << "清除全部错误:\n";
	cin.clear();						// 流状态复位，即错误位全部清除，恢复正常
	iostate_test(cin);

	cout << "清除failbit错误:\n";
	cin.setstate(old_state);					// 还原错误，导致eofbit置位
	cin.clear(cin.rdstate() & ~cin.failbit);	// 流状态复位，failbit复位，但不会复位其他状态
	iostate_test(cin);

	cout << "清除failbit和eofbit错误:\n";
	cin.setstate(old_state);					// 设置错误，导致eofbit置位
	cin.clear(cin.rdstate() & ~cin.failbit & ~cin.eofbit); // 流状态复位，failbit和badbit复位
	iostate_test(cin);

	cout << "还原原始eofbit错误:\n";
	cin.setstate(old_state); // 设置为原来错误状态，导致failbit和eofbit置位
	iostate_test(cin);

	int temp = 0;
	return;
}
int main(int argc, char* argv[])
{
	//Input_Test();
#if 1
	istringstream instring;
	ostringstream outstring;
	string infile = "./1.txt";
	string temp;
	vector<string> vec;
	ifstream in(infile);
	if (!in)
	{
		cerr << "打开文件失败!\n";
		exit(-1);
	}
	while (in>>temp)
	{
		vec.push_back(temp);
	}
	for (int i=0;i<vec.size();++i)
	{
		instring.str(vec[i]);
		instring.clear();
		while (instring >> temp)
		{
			outstring << temp << " ";
		}
	}
	outstring << "我爱你" << endl;
	cout << outstring.str() << endl;

#elif 0
	ifstream in(argv[1]);
	ofstream out(argv[2],ios_base::app);
	if (!in && !out)
	{
		cerr << "文件打开失败!\n";
		exit(-1);
	}
	string temp;
	vector<string> sd;
	while (getline(in, temp))
	{
		sd.push_back(temp);
	}
	for (auto x : sd)
	{
		out << x << endl;
	}
#endif
	return 0;
}

istream& asd(istream& in)
{
	int a;
	char s;
	auto old_iostate = in.rdstate();
	while (in>>a)
	{
		cout << a << " ";
	}
	if (in.fail())
	{
		iostate_test(in);
		in.clear();	//复位为有效状态
	}

	return in;
}
#else

#endif