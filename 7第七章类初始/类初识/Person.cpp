#include "Person.h"

ostream& print(ostream& out, const Person& p)
{
	out << p.name << " " << p.address;
	return out;
}

istream& read(istream& in, Person& p)
{
	in >> p.name >> p.address;
	// TODO: �ڴ˴����� return ���
	return in;
}
