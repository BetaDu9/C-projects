#pragma once
#include<iostream>
using namespace std;
#include<map>

class Order{
public:
	Order();

	void updateOrder();
	//Ô¤Ô¼ÌõÊı
	int m_size;

	map<int,map<string,string>>m_order;
};