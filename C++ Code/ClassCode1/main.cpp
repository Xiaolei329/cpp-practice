#include <iostream>

//C++自定义的头文件 可以是.h 也可以是.hpp
#include "hisNameSpace"
#include"myNameSpace.h"
#include "yourNameSpace.hpp"


//一、演示一下命名空间的使用
// 1）引入 整个命名空间
// 2）单引入命名空间中某个对象
// 3）自定义命名空间 
// 4) C++头文件的多种类型： h hpp 和无扩展名

using namespace std;
//using std::cout; 


//using namespace myNamespace;
using namespace yourNamespace;
//using namespace hisNamespace;

int main()
{
	cout << "Hello World!\n";
	printName();

}

