/*
c++�����һ����ʵ�֣�ֻ��ʵ�ֻ�ȡ��
title:
1:ͨ�������ƻ�ȡ����ͨ�� һ��ȫ�� �� map����string �� ��Ļص����� ��һ����
2��ʵ��ע�� �� string���͵����� ����ͨ�� �궨��ķ���ȥ�㶨��#className ��ʾ string���ͣ�
*/

#include <map>
#include <iostream>
#include <string>
using namespace std;
// ����ָ��
typedef void* (*PTRCreateObject)(void);

//ʹ�ú궨�� ʵ�� ע��
#define REGISTER(className)                                             \
    className* objectCreator##className(){                              \
        return new className;                                           \
    }                                                                   \
    RegisterAction g_creatorRegister##className(                        \
        #className,(PTRCreateObject)objectCreator##className)

//����ע�Ṥ��


//������Ķ���
class ClassFactory {
private:
    map<string, PTRCreateObject> m_classMap;
    ClassFactory() {}; //���캯��˽�л�

public:
    void* getClassByName(string className);
    void registClass(string name, PTRCreateObject method);
    static ClassFactory& getInstance();
};

//�������ʵ��

//@brief:��ȡ������ĵ���ʵ������  
ClassFactory& ClassFactory::getInstance() {
    static ClassFactory sLo_factory;
    return sLo_factory;
}

//@brief:ͨ���������ַ�����ȡ���ʵ��
void* ClassFactory::getClassByName(string className) {
    map<string, PTRCreateObject>::const_iterator iter;
    iter = m_classMap.find(className);
    if (iter == m_classMap.end())
        return NULL;
    else
        return iter->second();
}

//@brief:���������������ַ����Ͷ�Ӧ�Ĵ��������ĺ������浽map��   
void ClassFactory::registClass(string name, PTRCreateObject method) {
    m_classMap.insert(pair<string, PTRCreateObject>(name, method));
}

//ע�ᶯ����
class RegisterAction {
public:
    RegisterAction(string className, PTRCreateObject ptrCreateFn) {
        ClassFactory::getInstance().registClass(className, ptrCreateFn);
    }
};

//���ԣ�


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
