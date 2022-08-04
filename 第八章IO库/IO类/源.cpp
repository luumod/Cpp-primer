#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#if 1
void iostate_test(istream& in) {
	// ��״̬��ӡ
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
	}									//���败��eofbit���� 

	auto old_state = cin.rdstate();			// ��¼��ǰ����״̬
	iostate_test(cin);

	cout << "���ȫ������:\n";
	cin.clear();						// ��״̬��λ��������λȫ��������ָ�����
	iostate_test(cin);

	cout << "���failbit����:\n";
	cin.setstate(old_state);					// ��ԭ���󣬵���eofbit��λ
	cin.clear(cin.rdstate() & ~cin.failbit);	// ��״̬��λ��failbit��λ�������Ḵλ����״̬
	iostate_test(cin);

	cout << "���failbit��eofbit����:\n";
	cin.setstate(old_state);					// ���ô��󣬵���eofbit��λ
	cin.clear(cin.rdstate() & ~cin.failbit & ~cin.eofbit); // ��״̬��λ��failbit��badbit��λ
	iostate_test(cin);

	cout << "��ԭԭʼeofbit����:\n";
	cin.setstate(old_state); // ����Ϊԭ������״̬������failbit��eofbit��λ
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
		cerr << "���ļ�ʧ��!\n";
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
	outstring << "�Ұ���" << endl;
	cout << outstring.str() << endl;

#elif 0
	ifstream in(argv[1]);
	ofstream out(argv[2],ios_base::app);
	if (!in && !out)
	{
		cerr << "�ļ���ʧ��!\n";
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
		in.clear();	//��λΪ��Ч״̬
	}

	return in;
}
#else

#endif