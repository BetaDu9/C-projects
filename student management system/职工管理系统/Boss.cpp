#include <iostream>
#include <string>
using namespace std;
#include "boss.h"

//�����ʼ������Boss��Ա����
Boss::Boss(int id, string name, int dId){
	this->m_id=id;     //this ��ʾ������Boss��m_id��ֵ
	this->m_name=name;
	this->m_dId=dId;

}

void Boss::showInfo(){
		cout<<"ְ����ţ�"<<this->m_id<<"\tְ��������"
			<<this->m_name<<"\t���ű�ţ�"<<this->m_dId
			<<"\t��λְ��ͳ�����"<<endl;
}

string Boss::departmentInfo(){

	return string("�ϰ�");

}