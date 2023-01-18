/*
装饰器模式：
1、装饰器模式的做法：就是拓展一个类，但是不想使用继承的方法，因为会使得子类泛滥，
	那就额外使用一个壳子，使用组合的方式来内嵌一个原来的类，但是（这里是关键）本身由于要
	在原有基础之上做扩展，所以自己也要继承于原有类。
	- 桥接模式是使用组合的手段，将多个不同的类组合在一块，不涉及拓展这个说法。
	- 从结构上看和代理模式很像，二者的本质区别是目标不同，一个是想不产生继承爆炸的情况下拓展一个类，
		一个是做一个控制权的转移。
2、具体解释：
	https://www.runoob.com/design-pattern/decorator-pattern.html
3、视频：
	https://www.bilibili.com/video/BV1hp4y1D7MP/?spm_id_from=333.337.search-card.all.click&vd_source=516dfe4cef988e085bc8928f5cc68d86
*/

#include<iostream>
using namespace std;
//初始类
class Robot {
public:
	 virtual void doSomthing();
};
//第一代机器人
class firstRobot :public Robot {
public:
	virtual void doSomthing() override;
};

void firstRobot::doSomthing() {
	cout << "dance" << endl;
	cout << "sing" << endl;
}

//使用 装饰器模式 来实现拓展机器人功能

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