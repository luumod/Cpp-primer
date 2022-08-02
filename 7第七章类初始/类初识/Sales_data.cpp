#include "Sales_data.h"


//在类的外部定义成员函数
Sales_data& Sales_data::combine(const Sales_data& s)
{
	units_sold += s.units_sold;
	revenue += s.revenue;
	return *this;
}
//在类的外部定义成员函数
double Sales_data::avg_price() const
{
	if (units_sold)
	{
		return revenue / units_sold;
	}
	else
	{
		return 0.0;
	}
}

Sales_data add(const Sales_data& s1, const Sales_data& s2)
{
	Sales_data sum = s1;
	sum.combine(s1);
	return sum;
}

std::ostream& print(std::ostream& out, const Sales_data& s)
{
	out << s.isbn() << " " << s.units_sold << " " << s.revenue << " " << s.avg_price();
	return out;
}

std::istream& read(std::istream& in, Sales_data& s)
{
	double price = 0;
	in >> s.bookNo >> s.units_sold >> price;
	s.revenue = s.units_sold * price;
	return in;
}
