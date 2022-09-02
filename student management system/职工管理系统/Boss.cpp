#include <iostream>
#include <string>
using namespace std;
#include "boss.h"

//类外初始化子类Boss成员函数
Boss::Boss(int id, string name, int dId){
	this->m_id=id;     //this 表示给子类Boss的m_id赋值
	this->m_name=name;
	this->m_dId=dId;

}

void Boss::showInfo(){
		cout<<"职工编号："<<this->m_id<<"\t职工姓名："
			<<this->m_name<<"\t部门编号："<<this->m_dId
			<<"\t岗位职责：统筹管理"<<endl;
}

string Boss::departmentInfo(){

	return string("老板");

}