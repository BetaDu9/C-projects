#pragma once
#include<iostream>
using namespace std;
#include <vector>
#include <map>
#include"Speaker.h"

//������
class Manager{
public:
	Manager();
	//��ʼ����Ա����
	void init();

	void showMenu();

	void creatSpeaker();

	void StartSpeech();

	void drawSpeaker();

	void getScore();
	
	void showResult();

	void saveScore();

	void loadScore();

	void showContest();

	void clearContest();

	bool emptyFile;

	map<int,vector<string>>m_Contest;

	~Manager();
	//��Ա����
	//��һ�ֱ�����ѡ�ֱ��
	 vector<int>v1;
	 //�ڶ��ֱ�����ѡ�ֱ��
	  vector<int>v2;
	  //ʤ��ѡ�ֱ��
	  vector<int>v3;
	//ѡ����Ϣ
	  map<int,Speaker>m_Speaker;
	//��������
	int index;
};
