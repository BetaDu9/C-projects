#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<vector>
#include"Computer.h"

class Student:public Identity{
public:
	Student();

	Student(int ID,string name,int password);

	void Menu();

   void Apply();

   void showMy();

   void showAll();

   void cancelOrder();

   int m_sID;

   vector<Computer>v;
};