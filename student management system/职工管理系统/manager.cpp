#include <iostream>
#include <string>
using namespace std;
#include "manager.h"

//�����ʼ������Boss��Ա����
Manager::Manager(int id, string name, int dId){
	this->m_id=id;     //this ��ʾ������Boss��m_id��ֵ
	this->m_name=name;
	this->m_dId=dId;

}

void Manager::showInfo(){
		cout<<"ְ����ţ�"<<this->m_id<<"\tְ��������"
			<<this->m_name<<"\t���ű�ţ�"<<this->m_dId
			<<"\t��λְ������ϰ���������"<<endl;

}

string Manager::departmentInfo(){

	return string("����");

}