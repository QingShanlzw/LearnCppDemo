/*
再main函数之前执行：
https://blog.csdn.net/qq_38836770/article/details/108871608
全局变量和 静态变量的初始化：也就是data段的变量的初始化。

*/

#include <map>
#include <iostream>
#include <string>
using namespace std;
int k;

class A {
public:
	A() {
		cout << ++k << endl;
	}
};

static A a;

int func1(void) {
	cout << "function 1" << endl;
	return 1;
}
void func2(void) {
	cout << "function 2" << endl;
}

int main() {
	cout << "begin main" << endl;
	static A aa;

	onexit(func1);
	atexit(func2);


	return 0;
}