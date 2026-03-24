#include <iostream>
#include <string>

using namespace std;

//演示一下：
//1.友元函数 : 普通友元函数
//2.友元类 ：友元类中的函数都是友元函数


class sports;
class Person {
private:
    string name;
    string idCard;

public:
    
    friend void print(Person &per);
    friend class sports;

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
    cout << this->name << "开始学习了" << endl;
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
    this->idCard = idcard;
}

void Person::setName(string name) {
    this->name = name;
}


//普通友元函数的实现
void print(Person& per) {

    cout << "姓名：" << per.name << " 身份证号：" << per.idCard << endl;
}



//类2： 
class sports {

public :
    void playBasketball(Person &per);
    void playFootball(Person& per);
    void playBadminton(Person& per);
};

//实现成员函数
void sports::playBasketball(Person& per) {
    cout << per.name <<"在打篮球" << endl;
}

void sports::playFootball(Person& per) {
    cout << per.name << "在踢足球" << endl;
}

void sports::playBadminton(Person& per) {
    cout << per.name << "在打羽毛球" << endl;
}


int main()
{
    Person per1;
    per1.setName("张三");
    per1.setIdcard("12345");

    print(per1);

    sports sp;
    sp.playBasketball(per1);
    sp.playFootball(per1);
    sp.playBadminton(per1);
}

