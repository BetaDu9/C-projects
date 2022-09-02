#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<vector>

class Teacher:public Identity{
public:
	Teacher();

	Teacher(int ID,string name,int password);

	void Menu();

	void showOrder();

	void orderCheck();

  int empID;


};