/*
c++反射的一个简单实现，只能实现获取类
title:
1:通过类名称获取类是通过 一个全局 的 map做了string 和 类的回调函数 的一个绑定
2：实现注册 是 string类型的名称 可以通过 宏定义的方法去搞定（#className 表示 string类型）
*/

#include <map>
#include <iostream>
#include <string>
using namespace std;
// 函数指针
typedef void* (*PTRCreateObject)(void);

//使用宏定义 实现 注册
#define REGISTER(className)                                             \
    className* objectCreator##className(){                              \
        return new className;                                           \
    }                                                                   \
    RegisterAction g_creatorRegister##className(                        \
        #className,(PTRCreateObject)objectCreator##className)

//函数注册工厂


//工厂类的定义
class ClassFactory {
private:
    map<string, PTRCreateObject> m_classMap;
    ClassFactory() {}; //构造函数私有化

public:
    void* getClassByName(string className);
    void registClass(string name, PTRCreateObject method);
    static ClassFactory& getInstance();
};

//工厂类的实现

//@brief:获取工厂类的单个实例对象  
ClassFactory& ClassFactory::getInstance() {
    static ClassFactory sLo_factory;
    return sLo_factory;
}

//@brief:通过类名称字符串获取类的实例
void* ClassFactory::getClassByName(string className) {
    map<string, PTRCreateObject>::const_iterator iter;
    iter = m_classMap.find(className);
    if (iter == m_classMap.end())
        return NULL;
    else
        return iter->second();
}

//@brief:将给定的类名称字符串和对应的创建类对象的函数保存到map中   
void ClassFactory::registClass(string name, PTRCreateObject method) {
    m_classMap.insert(pair<string, PTRCreateObject>(name, method));
}

//注册动作类
class RegisterAction {
public:
    RegisterAction(string className, PTRCreateObject ptrCreateFn) {
        ClassFactory::getInstance().registClass(className, ptrCreateFn);
    }
};

//测试：


class TestClass {
public:
    void m_print() {
        cout << "hello TestClass" << endl;
    };
};
REGISTER(TestClass);

//int main(int argc, char* argv[]) {
//   
//    TestClass* ptrObj = (TestClass*)ClassFactory::getInstance().getClassByName("TestClass");
//    ptrObj->m_print();
//}
