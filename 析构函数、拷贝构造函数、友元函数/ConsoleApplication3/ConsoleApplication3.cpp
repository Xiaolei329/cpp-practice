#include <iostream>
#include <string>
using  namespace std;


//三。演示一下：
//1.默认的拷贝构造函数是浅拷贝；
//2.浅拷贝在析构时存在重复释放的问题；
//3.重写拷贝构造函数 改为深拷贝；


class Person {

private:
    string name;
    char* idCard; //使用new来开辟内存

public:
    Person(string name, const char* idCard);

    ~Person();

    void study();


    //实现拷贝构造函数
    Person(const Person &another);
};


//在类外实现成员函数
void Person::study() {
    cout << this->name << "开始学习了" << endl;
}


//全参数的构造函数
Person::Person(string name, const char* idCard) {

    cout << "调用了全参的构造函数" << endl;
    this->name = name;
    int len = strlen(idCard) + 1;
    this->idCard = new char[len];
    memset(this->idCard, 0, len);//初始化0
    strcpy_s(this->idCard,len, idCard);

}

//析构函数的实现
Person::~Person() {

    cout << "调用了析构函数，name:" << this->name << endl;
    //此时的析构函数 需要把成员变量的动态内存也释放一下
    if (this->idCard != NULL) {
        delete[] idCard;
    }
}


//实现拷贝构造函数，需要深拷贝
Person::Person(const Person& another) {

    //name直接赋值拷贝
    this->name = another.name;

    //idcard是动态申请的内存，不能再直接赋值拷贝
    //需要也开辟一个同样的空间，再复制值

    //完成深拷贝
    int len = strlen(another.idCard) + 1;
    this->idCard = new char[len];
    strcpy_s(this->idCard,len,  another.idCard);
}

int main()
{
    //1.析构函数 需要释放掉成员变量 动态申请的内存
    const char* p = "12345";
    Person per1 = Person("张三", p);

    //2.使用默认的拷贝构造函数时是浅拷贝
    // idcard公用一块内存
    // 在退出析构时候会存在释放两次
    
    Person per2 = Person(per1);




}

