#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <fstream>
using namespace std;
#include "Manager.h"
#include "Speaker.h"
#include<algorithm>
#include<numeric>
#include<functional>

//�������̺���
void Manager::StartSpeech(){
//��һ�ֱ���
	cout<<"<��һ�ֱ�����ʼ��>"<<endl;
	//��ǩ
	this->drawSpeaker();
	//��һ�ֱ�������
	cout<<"----------------------"<<endl;
	cout<<"��һ�ֱ���������..."<<endl;
	cout<<"----------------------"<<endl;
	system("pause");
	this->getScore();
	cout<<"----------------------"<<endl;
	cout<<"��һ�ֱ���������"<<endl;
	cout<<"----------------------"<<endl;
	
	//��ʾ�������
	cout<<"���������"<<endl;
	this->showResult();

//�ڶ��ֱ���
	this->index++;
	cout<<"------------------"<<endl;
	cout<<"<�ڶ��ֱ�����ʼ��>"<<endl;
	cout<<"------------------"<<endl;
	//��ǩ
	drawSpeaker();
	//���еڶ��ֱ���
	cout<<"----------------------"<<endl;
	cout<<"�ڶ��ֱ���������..."<<endl;
	cout<<"----------------------"<<endl;
	system("pause");
	this->getScore();
	cout<<"----------------------"<<endl;
	cout<<"�ڶ��ֱ���������"<<endl;
	cout<<"----------------------"<<endl;
	
	//��ʾ���ս��
	cout<<"���������"<<endl;
	this->showResult();
	cout<<"----------------------"<<endl;
	cout<<"�ݽ���������"<<endl;
	cout<<"----------------------"<<endl;
	this->saveScore();

	//���ñ���
	this->init();
	this->creatSpeaker();
	this->loadScore();

	system("pause");
	system("cls");
	return;
}