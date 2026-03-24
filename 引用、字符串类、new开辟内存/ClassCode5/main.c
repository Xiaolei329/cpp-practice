#include"stdio.h"


//一、先复习一下C语言字符串处理方式
//1.字符数组方式
//2.字符指针方式

void main() {
    //定义字符数组，并初始化
    //此时编译器自动为数组开辟长度为 字符串长度+1
    char str[] = "HelloWorld";

    //这个只是定义的一个char指针，指向一个字符串常量
    char* str_p = "HelloWorld";
    
    
    int a = sizeof(str);//这个求取的是整个字符串的大小11
    int b = sizeof(str_p);//求取的仅仅是指针的空间大小8

    //打印字符数组的长度，
    printf("%d\n", a);

    //这个打印出来仅仅
    printf("%d\n", b);


    //字符数组的内容支持更改；
    str[0] = 'h';
    printf("%s\n", str);

    //字符指针 所指内容是不能更改的 str_p
    //str_p[1] = 'h';
    //printf("%s\n", str_p); //不可以的


}