#pragma once  //��ֹ�ظ�����ͷ�ļ�
#include <iostream>//�����������������
#include <string>
#include "worker.h"
using namespace std; //ʹ�ñ�׼�����ռ�
#include <fstream> //�����ļ���ͷ�ļ�
#define FILENAME "Employee.txt"//������Ҫ�������ļ�����

class workerManager{
public:
	//���캯��
	workerManager();
	//��ʾ�˵�
	void showMenu();

	//��Ա����
	int m_PerNum; //ְ������
	worker** m_PerArr; //��¼ְ������ָ��,�����м�¼ְ��ָ��worker*

	//���ְ��
	void addPerson();
	//�����ļ�
	void save();
	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileisEmpty;
	//��ȡ����ְ������
	int getNum();
	//��ʼ��Ա��
	void init();
	//��ʾԱ��
	void showPerson();
	//ɾ��Ա��
	void deletePer();
	//�޸�ְ��
	void modPerson();
	//����ְ��
	void search();
	//���ְ���б�
	void clear();
	//��������
	~workerManager();

};