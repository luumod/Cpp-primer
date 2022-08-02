#include "Person.h"

ostream& print(ostream& out, const Person& p)
{
	out << p.name << " " << p.address;
	return out;
}

istream& read(istream& in, Person& p)
{
	in >> p.name >> p.address;
	// TODO: 在此处插入 return 语句
	return in;
}
