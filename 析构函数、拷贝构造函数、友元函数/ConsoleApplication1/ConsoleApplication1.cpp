
#include <iostream>
using  namespace std;

//演示一下：
//1.栈中的对象，函数结束前调用析构函数；
//  堆中的对象，delete时调用析构函数；
//2.先构造的后析构，后构造的先析构；

class Person {

private:
    string name;
    string idCard;

public:
    Person();
    Person(string name, string idCard);

    ~Person();


    void study();

    //getter setter
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

void Person::setIdcard(string idCard) {
    this->idCard = idCard;
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

    cout << "调用了析构函数，name:"<<this->name << endl;
}


//演示在函数中创建对象，
//函数结束时自动调用析构函数
void fun1() {
    // 方式1：栈中创建对象
    // 通过.方式来调用成员函数
    Person per1 = Person("张三", "12345");
    per1.study();

    Person per2 = Person("李四", "12345");
    per2.study();

    //返回时，自动调用析构函数，
    //先创建的对象后析构
}


int main()
{

    fun1();

    // 方式2：堆中创建对象
    // 通过->方式来调用成员函数
    // 用完需要delete(per2);
    Person* per2 = new Person();
    per2->setName("王五");
    per2->setIdcard("7891011");
    per2->study();

    system("pause");
    delete(per2);
}

