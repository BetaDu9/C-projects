#pragma once  //防止重复包含头文件
#include <iostream>//包含输入输出流函数
#include <string>
using namespace std;
#include "worker.h"

class Manager:public worker{
public:
	//初始化函数
	Manager(int id, string name, int dId);
	//员工信息
	void showInfo();
	//岗位信息
	string departmentInfo();


};