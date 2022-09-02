#pragma once  //防止重复包含头文件
#include <iostream>//包含输入输出流函数
#include <string>
using namespace std;

//worker抽象类，抽象出对象员工的所有属性与行为
class worker{
public:
	//员工行为，成员函数，打印输出
	//员工信息，纯虚函数待重写
	virtual void showInfo()=0;
	//岗位信息
	virtual string departmentInfo()=0;

	//员工属性
	int m_id;
	string m_name;
	int m_dId;

};