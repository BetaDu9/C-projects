#pragma once  //防止重复包含头文件
#include <iostream>//包含输入输出流函数
using namespace std;
#include "worker.h"

//子类重写父类worker抽象类
class Employee:public worker{
public:
	//构造函数，初始化员工属性
	Employee(int id, string name, int dId);
	//员工信息
	virtual void showInfo();
	//岗位信息
	virtual string departmentInfo();


};
