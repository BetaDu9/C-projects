#include <iostream>
#include <string>
using namespace std;
#include "manager.h"

//类外初始化子类Boss成员函数
Manager::Manager(int id, string name, int dId){
	this->m_id=id;     //this 表示给子类Boss的m_id赋值
	this->m_name=name;
	this->m_dId=dId;

}

void Manager::showInfo(){
		cout<<"职工编号："<<this->m_id<<"\t职工姓名："
			<<this->m_name<<"\t部门编号："<<this->m_dId
			<<"\t岗位职责：完成老板分配的任务"<<endl;

}

string Manager::departmentInfo(){

	return string("经理");

}