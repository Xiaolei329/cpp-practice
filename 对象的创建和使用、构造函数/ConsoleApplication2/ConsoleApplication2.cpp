
#include <iostream>
#include <string>

using namespace std;

//演示一下：
//1.构造函数的重载；
//2.构造函数的列表初始化；
//3.含有成员对象的类，初始化时；先执行成员对象的构造函数，
//再执行类的构造函数；（后面演示）


class Person {
private:
    string name;
    string idCard;

public:
    Person();//无参构造函数
    Person(string name);
    Person(string name, string idCard);


    void study();//成员函数

    string getName();//getter 和 setter函数
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
    this->idCard = idCard;
}

void Person::setName(string name) {
    this->name = name;
}

//实现无参构造函数
Person::Person() {
  //假设，无参数时 初始化默认 name为 张三
    cout << "调用了无参构造函数，取默认名张三" << endl;
    this->name = "张三";
}
//实现一个参数的 构造函数
Person::Person(string name) {
    cout << "调用了一个参数构造函数" << endl;
    this->name = name;
}
//实现两个参数的 构造函数  列表形式进行
Person::Person(string name, string idCard)
:name(name),idCard(idCard){
 
    cout << "调用了两个参数构造函数" << endl;
}


int main()
{
   //创建对象时，自动调用对应的构造函数进行初始化

    //此时会调用无参数的构造函数
    Person per1;
    per1.study();


    //此时会调用带一个参数的构造函数
    Person per2 = Person("李四");
    per2.study();

    //此时会调用带两个参数的构造函数
    Person per3 = Person("李四", "123");
    per3.study();
}
