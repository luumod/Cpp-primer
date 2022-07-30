
#ifndef SALESITEM_H
// we're here only if SALESITEM_H has not yet been defined 
#define SALESITEM_H

// Definition of Sales_item class and related functions goes here
#include <iostream>
#include <string>

class Sales_item {
    // 这些声明在第 7.2.1 节第 7.2.1 页解释。 270
    // 在第 14 章，第 557、558、561 页
    friend std::istream& operator>>(std::istream&, Sales_item&);
    friend std::ostream& operator<<(std::ostream&, const Sales_item&);
    friend bool operator<(const Sales_item&, const Sales_item&);
    friend bool operator==(const Sales_item&, const Sales_item&);
public:
    //构造函数在第 7.1.4 节，第 262 - 265 页中进行了解释
    // 初始化内置类型成员所需的默认构造函数
    Sales_item() = default;
    Sales_item(const std::string& book) : bookNo(book) { }
    Sales_item(std::istream& is)
    {
        is >> *this;
    }
public:
    // 对销售项目对象的操作
   // 成员二元运算符：绑定到隐式 this 指针的左侧操作数
    Sales_item& operator+=(const Sales_item&);

    // 对销售项目对象的操作
    std::string isbn() const
    {
        return bookNo;
    }
    double avg_price() const;
    // private members as before
private:
    std::string bookNo;      // 隐式初始化为空字符串
    unsigned units_sold = 0; // 显式初始化
    double revenue = 0.0;
};

// used in chapter 10
inline bool compareIsbn(const Sales_item& lhs, const Sales_item& rhs)
{
    return lhs.isbn() == rhs.isbn();
}

//非成员二元运算符：必须为每个操作数声明一个参数
Sales_item operator+(const Sales_item&, const Sales_item&);

inline bool operator==(const Sales_item& lhs, const Sales_item& rhs)
{
    // must be made a friend of Sales_item
    return lhs.units_sold == rhs.units_sold &&
        lhs.revenue == rhs.revenue &&
        lhs.isbn() == rhs.isbn();
}

inline bool
operator!=(const Sales_item& lhs, const Sales_item& rhs)
{
    return !(lhs == rhs); //!= 根据运算符 == 定义
}

// assumes that both objects refer to the same ISBN
Sales_item& Sales_item::operator+=(const Sales_item& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// 假设两个对象都引用同一个 ISBN
Sales_item
operator+(const Sales_item& lhs, const Sales_item& rhs)
{
    Sales_item ret(lhs);    // 将 (|lhs|) 复制到我们将返回的本地对象中
    ret += rhs;             // 添加 (|rhs|) 的内容
    return ret;             // 按值返回 (|ret|)
}

std::istream&
operator>>(std::istream& in, Sales_item& s)
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    // check that the inputs succeeded
    if (in)
        s.revenue = s.units_sold * price;
    else
        s = Sales_item();  //输入失败：将对象重置为默认状态
    return in;
}

std::ostream&
operator<<(std::ostream& out, const Sales_item& s)
{
    out << s.isbn() << " " << s.units_sold << " "
        << s.revenue << " " << s.avg_price();
    return out;
}

double Sales_item::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}
#endif
