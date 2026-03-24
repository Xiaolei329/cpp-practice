#include <iostream>
using  namespace std;

//演示一下：
//1. 拷贝构造函数不写时候，也会默认创建一个；


class Person {

private:
    string name;
    string idCard;

public:
    Person();
    Person(string name, string idCard);

    ~Person();


    void study();

    string getName();
    string getIdcard();
    void setName(string name);
    void setIdcard(string idcard);

};
//在类外实现成员函数
void Person::study() {
    cout << this->name << "开始学习了" << endl;
}

//getter 和 Setter
//通过接口来访问和设置属性的值
string Person::getIdcard() {
    return this->idCard;
}

string Person::getName() {
    return this->name;
}

void Person::setIdcard(string idcard) {
    this->idCard = idcard;
}

void Person::setName(string name) {
    this->name = name;
}

//无参的构造函数
Person::Person() {
    cout << "调用了无参的构造函数" << endl;
}
//全参数的构造函数
Person::Person(string name, string idCard) {

    cout << "调用了全参的构造函数" << endl;
    this->name = name;
    this->idCard = idCard;
}

//析构函数的实现
Person::~Person() {

    cout << "调用了析构函数，name:" << this->name << endl;
}


int main()
{
    //创建对象1
    Person per1 = Person("张三", "12345");
    per1.study();

    //通过 默认的拷贝构造函数 构造对象2
    Person per2 = Person(per1);
    per2.study();
}
