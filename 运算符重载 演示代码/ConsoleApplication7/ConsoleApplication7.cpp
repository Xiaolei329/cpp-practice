#include <iostream>
#include <string>

using namespace std;

//演示一下：
//1.输入输出运算符重载实现
//2.关系运算符重载实现
//3.两种重载方式比较


class Person {
private:
    string name;
    string idCard;
    int age;

public:

    void study();

    //构造函数
    Person(string name, string idCard, int age);

    //运算符重载实现 << 输出
    friend ostream& operator<<(ostream& os, const Person& per);
    //运算符重载实现 >> 输入
    friend istream& operator>>(istream& is, Person& per);

    // == 重载为类的成员函数
    bool operator==(const Person& per);


    //get 和 set
    string getName();
    string getIdcard();
    int getAge();
    void setName(string name);
    void setIdcard(string idcard);
    void setAge(int age);
};

//在类外实现成员函数
void Person::study() {
    cout << this->name << "开始学习了" << endl;
}

Person::Person(string name, string idCard, int age) {
    this->age = age;
    this->name = name;
    this->idCard = idCard;
}


//getter 和 Setter
//通过接口来访问和设置属性的值
string Person::getIdcard() {
    return this->idCard;
}

string Person::getName() {
    return this->name;
}

int Person::getAge() {
    return this->age;
}

void Person::setIdcard(string idcard) {
    this->idCard = idcard;
}

void Person::setName(string name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

//运算符重载类外友元函数实现
ostream& operator<<(ostream& os, const Person& per) {
    os << "name:"+ per.name << " idCard:"+per.idCard << " age:"<<per.age;
    return os;
}

istream& operator>>(istream& is, Person& per) {
    is >> per.name >> per.idCard >> per.age;
    return is;
}

//运算符重载类外 成员函数实现
bool Person::operator==(const Person& per) {
    if (this->name == per.name && 
            this->idCard == per.idCard
            && this->age == per.age) {
        return true;
    }
    return false;
}


int main()
{
    Person per1("张三","12345",10 );
    //整体输出对象
    cout << per1;

    cout << "\n分别再输入name，idcard,age:" << endl;
    cin >> per1;
    cout << "重新输入后 新对象为" << endl;
    cout << per1;

    Person per2("张三", "12345", 10);
    if (per1 == per2) {
        cout << "\nper1与per2相同" << endl;
    }


}

