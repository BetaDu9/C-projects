#pragma once  //��ֹ�ظ�����ͷ�ļ�
#include <iostream>//�����������������
using namespace std;
#include "worker.h"

//������д����worker������
class Employee:public worker{
public:
	//���캯������ʼ��Ա������
	Employee(int id, string name, int dId);
	//Ա����Ϣ
	virtual void showInfo();
	//��λ��Ϣ
	virtual string departmentInfo();


};
