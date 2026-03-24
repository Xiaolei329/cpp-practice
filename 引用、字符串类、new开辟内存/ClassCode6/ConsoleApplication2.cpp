
#include <iostream>
#include <string>
using namespace std;

//字符串类的基本操作
//定义字符串类对象
//并使用字符串类的 常用的方法
//注意：
//1.string 类也是定义std命名空间下面的
//2.str.length() 与 str.size()都是字符的长度。
//3.find()找不到时候 返回是一个常量npos 
int main()
{
    string str1 = "Hello";
    string str2("World");
   

    string str3;
    //1.使用= 复制str1给str3
    str3 = str1;
    cout << "str3为:" << str3 << endl;   

    string str4;
    //2.使用+ 连接字符串
    str4 = str1 + str2;
    cout << "str4为:" << str4 << endl;
     
    //3. str.length() 与 str.size()
    cout << "str4.length为:" << str4.length() << endl;
    cout << "str4.size为:" << str4.size() << endl;

    //4.append()方式末尾拼接
    str4.append("C++");
    cout << "str4为:" << str4 << endl;

    //字符串比较
    string str5 = "aaaa";
    if (str4 < str5) {
        cout << "字符串比较：" << "str4<str5" << endl;
    }

    //查找子串是否存在
    //返回的是：首次匹配上的位置，
    //如果没有匹配上返回 npos
    cout << "str4里面找C++时返回值" << str4.find("C++") << endl;
    cout <<"str4里面找A++时返回值" << str4.find("A++") << endl;
    cout << "str4里面找B++时返回值" << str4.find("B++") << endl;

    if (str4.find("A++") == string::npos) { 
        cout << "str4里面没有找到A++" << endl;
    }



}
