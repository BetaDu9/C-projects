#pragma once
#include<iostream>
using namespace std;
#include <vector>
#include <map>
#include"Speaker.h"

//管理类
class Manager{
public:
	Manager();
	//初始化成员属性
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
	//成员属性
	//第一轮比赛的选手编号
	 vector<int>v1;
	 //第二轮比赛的选手编号
	  vector<int>v2;
	  //胜出选手编号
	  vector<int>v3;
	//选手信息
	  map<int,Speaker>m_Speaker;
	//比赛轮数
	int index;
};
