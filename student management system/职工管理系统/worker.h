#pragma once  //��ֹ�ظ�����ͷ�ļ�
#include <iostream>//�����������������
#include <string>
using namespace std;

//worker�����࣬���������Ա����������������Ϊ
class worker{
public:
	//Ա����Ϊ����Ա��������ӡ���
	//Ա����Ϣ�����麯������д
	virtual void showInfo()=0;
	//��λ��Ϣ
	virtual string departmentInfo()=0;

	//Ա������
	int m_id;
	string m_name;
	int m_dId;

};