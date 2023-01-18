/*
װ����ģʽ��
1��װ����ģʽ��������������չһ���࣬���ǲ���ʹ�ü̳еķ�������Ϊ��ʹ�����෺�ģ�
	�ǾͶ���ʹ��һ�����ӣ�ʹ����ϵķ�ʽ����Ƕһ��ԭ�����࣬���ǣ������ǹؼ�����������Ҫ
	��ԭ�л���֮������չ�������Լ�ҲҪ�̳���ԭ���ࡣ
	- �Ž�ģʽ��ʹ����ϵ��ֶΣ��������ͬ���������һ�飬���漰��չ���˵����
	- �ӽṹ�Ͽ��ʹ���ģʽ���񣬶��ߵı���������Ŀ�겻ͬ��һ�����벻�����̳б�ը���������չһ���࣬
		һ������һ������Ȩ��ת�ơ�
2��������ͣ�
	https://www.runoob.com/design-pattern/decorator-pattern.html
3����Ƶ��
	https://www.bilibili.com/video/BV1hp4y1D7MP/?spm_id_from=333.337.search-card.all.click&vd_source=516dfe4cef988e085bc8928f5cc68d86
*/

#include<iostream>
using namespace std;
//��ʼ��
class Robot {
public:
	 virtual void doSomthing();
};
//��һ��������
class firstRobot :public Robot {
public:
	virtual void doSomthing() override;
};

void firstRobot::doSomthing() {
	cout << "dance" << endl;
	cout << "sing" << endl;
}

//ʹ�� װ����ģʽ ��ʵ����չ�����˹���

class DecoraterRobot :public firstRobot {
private:
	Robot* my_robot;
public:
	DecoraterRobot(Robot* robot) :my_robot(robot) {}
	virtual void doSomthing() override;
};

void DecoraterRobot::doSomthing() {
	my_robot->doSomthing();
	cout << "running" << endl;
}