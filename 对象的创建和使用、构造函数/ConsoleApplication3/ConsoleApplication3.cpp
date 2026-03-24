#include <iostream>
#include <string>

using namespace std;

//演示一下：
//3.含有成员对象的类，初始化时；先执行成员对象的构造函数，
//再执行类的构造函数；（后面演示）


//定义类1： Birth类

class Birth {
public:
    Birth(int year, int month, int day);
    void show();//成员函数

private:
    int _year;
    int _month;
    int _day;
};

//全参构造函数，列表初始化方式
Birth::Birth(int year, int month, int day):
_year(year), _month(month), _day(day){
    cout << "调用了Birth全参数构造函数" << endl;
}

//成员函数的实现
void Birth::show() {
    cout << "出生日期" << this->_year << "-" << this->_month
        << "-" << this->_day << endl;
}


/////////////////分隔符 //////////////////////////

//类2： Person类
class Person {
private:
    string name;
    string idCard;
    
    Birth birth; //这是一个成员对象

public:
    //Person类全参构造函数
    Person(string name, string idCard, int year, int month, int day);

    void study();//成员函数
};

//在类外实现Person类成员函数
void Person::study() {
    cout << this->name << "开始学习了" << endl;
    this->birth.show();
}

//Person类实现全参数的 构造函数  列表形式进行
Person::Person(string name, string idCard, int year, int month, int day)
    : birth(year, month, day){

    this->name = name;
    this->idCard = idCard;
    cout << "调用了Person全参数构造函数" << endl;
}



int main()
{
    Person per = Person("李四", "123", 2023, 3,15);
    per.study();
}
