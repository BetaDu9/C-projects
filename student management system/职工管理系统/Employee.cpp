#include <iostream>
#include <string>
using namespace std;
#include "Employee.h"

//�����ʼ����Ա������Ҫ��������
//���캯����ʼ��Ա�����ԣ���Ա����ֵ
Employee::Employee(int id, string name, int dId){

	this->m_id=id;
	this->m_name=name;
	this->m_dId=dId;

	}

//���Ա����Ϣ
	void Employee::showInfo(){

		cout<<"ְ����ţ�"<<this->m_id<<"\tְ��������"
			<<this->m_name<<"\t���ű�ţ�"<<this->m_dId
			<<"\t��λְ����ɾ�����������"<<endl;
	}

//��λ��Ϣ
string Employee::departmentInfo(){
	return string("Ա��");     //�����ַ�������
	
	}


