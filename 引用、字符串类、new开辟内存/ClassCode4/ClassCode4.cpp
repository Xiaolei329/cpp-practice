#include <iostream>
using namespace std;

//引用的演示
//1.参数传递时，用引用和用指针都可以实现对原来的实参的更改；
//2.用引用方式  等价于是直接操作的原来的实参；
//3.用指针是传入时需要取地址，使用时还需要一直取内容方式 弊


//传递值的方式：
//效果：在函数里面的操作 不会影响到原来的实参
void swap1(int a, int b) {
    int temp;
    temp = b;
    b = a;
    a = temp;
    cout << "调用传值方式交换了ab的值\r\n";
}

//传递 地址的方式：
//效果：在函数里面的操作 会影响到原来的实参
void swap2(int* a, int* b) {
    int temp;

    temp = *b;
    *b = *a;
    *a = temp;
    cout  << "调用传指针方式交换了ab的值\r\n";
}


//C++ 引用的方式：
//效果：在函数里面的操作 会影响到原来的实参
void swap3(int& a, int& b) {
    int temp;

    temp = b;
    b = a;
    a = temp;
    cout << "调用传引用方式交换了ab的值\r\n";
}



int main()
{
    int a = 100;
    int b = 300;

    cout << "初始值：a="<<a <<" b=" <<b <<endl;
    swap1(a, b);
    cout << "调用传值方式后：a=" << a << " b=" << b << endl;

    cout <<endl<< "初始值：a=" << a << " b=" << b << endl;
    swap2(&a, &b);
    cout << "调用传地址方式后：a=" << a << " b=" << b << endl;


    //这个地方把 a b值重新回归到 100 和 300
    a = 100;
    b = 300;
    cout << endl << "初始值：a=" << a << " b=" << b << endl;
    swap3(a, b);
    cout << "调用传引用方式后：a=" << a << " b=" << b << endl;

}

