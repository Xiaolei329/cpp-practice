#include <iostream>
#include <string>

using namespace std;
//一。对象的创建和使用 
//1.Person per1; --- 栈中创建对象
// 通过.方式来调用成员函数
//2.Person *per2 = new Person()---堆中创建对象
//通过->方式来调用成员函数

//3.封装：属性设置为private 
//通过getter 和 setter 来访问和设置属性值

class Person {
private:
    string name;
    string idCard;

public:
    void study();
    void eat();
    void sleep();

    string getName();
    string getIdcard();
    void setName(string name);
    void setIdcard(string idcard);
};

//在类外实现成员函数
void Person::study() {
    cout << this->name<<"开始学习了" << endl;
}

void Person::eat() {
    cout << this->name << "开始吃饭了" << endl;
}

void Person::sleep() {
    cout << this->name << "开始睡觉了" << endl;
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
    this->idCard = idCard;
}

void Person::setName(string name) {
    this->name = name;
}

int main()
{
    // 方式1：栈中创建对象
    // 通过.方式来调用成员函数
    Person per;
    per.setIdcard("123456");
    per.setName("张三");
    per.sleep();

    // 方式2：堆中创建对象
    // 通过->方式来调用成员函数
    // 用完需要delete(per2);
    Person* per2 = new Person();
    per2->setName("李四");
    per2->setIdcard("7891011");
    per2->study();

    system("pause");
    delete(per2);
}
