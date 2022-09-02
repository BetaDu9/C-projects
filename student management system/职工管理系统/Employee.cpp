#include <iostream>
#include <string>
using namespace std;
#include "Employee.h"

//类外初始化成员函数需要加作用域
//构造函数初始化员工属性，给员工赋值
Employee::Employee(int id, string name, int dId){

	this->m_id=id;
	this->m_name=name;
	this->m_dId=dId;

	}

//输出员工信息
	void Employee::showInfo(){

		cout<<"职工编号："<<this->m_id<<"\t职工姓名："
			<<this->m_name<<"\t部门编号："<<this->m_dId
			<<"\t岗位职责：完成经理分配的任务"<<endl;
	}

//岗位信息
string Employee::departmentInfo(){
	return string("员工");     //返回字符串类型
	
	}


