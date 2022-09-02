#pragma once
#include<iostream>
#include"Identity.h"
using namespace std;



class Manager:public Identity{
public:
	Manager();

	Manager(string name,int password);

	void Menu();

	void addPerson();

	bool checkRepeat(int id,int type);

	void showPerson();

	void showCom();

	void clearOrder();


};