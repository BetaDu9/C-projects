#include <iostream>
#include"Teacher.h"
#include<fstream>
using namespace std;
#include"Order.h"

Teacher::Teacher(){}

Teacher::Teacher(int ID,string name,int password){

}

void Teacher::Menu(){
    cout<<"---------------------"<<endl;
	cout<<"     ��ӭ��ʦ��¼    "<<endl;
	cout<<"                     "<<endl;
	cout<<"     1.�鿴ԤԼ      "<<endl;
	cout<<"                     "<<endl;
	cout<<"     2.���ԤԼ      "<<endl;
	cout<<"                     "<<endl;
	cout<<"     5.ע����¼      "<<endl;
	cout<<"                     "<<endl;
	cout<<"---------------------"<<endl;
}

void Teacher::showOrder(){
	Order od;
	if(od.m_size==0){
	cout<<"��ԤԼ��Ϣ��"<<endl;
	system("pause");
		system("cls");
	return;
	}

		for(int i=0;i<od.m_size;i++){
		cout<<i+1<<". ";
		cout<<"ѧ��ѧ�ţ�"<<od.m_order[i]["studentID"]<<" ";
		cout<<"ѧ��������"<<od.m_order[i]["studentName"]<<" ";
		cout<<"ԤԼ���ڣ���"<<od.m_order[i]["date"]<<" ";
		cout<<"ԤԼʱ��Σ�"<<(od.m_order[i]["interval"]=="1"?"����":"����")<<" ";
		cout<<"ԤԼ������"<<od.m_order[i]["comRoom"]<<" ";

		string sta=od.m_order[i]["state"];
		if(sta=="1"){
		cout<<"ԤԼ״̬��"<<"�����"<<endl;
		}
		else if(sta=="2"){
		cout<<"ԤԼ״̬��"<<"���ͨ��"<<endl;
		}
		else if(sta=="3"){
		cout<<"ԤԼ״̬��"<<"ԤԼȡ��"<<endl;
		}
		else if(sta=="-1"){
		cout<<"ԤԼ״̬��"<<"ԤԼʧ��"<<endl;
		}
		}

system("pause");
		system("cls");
		return;

}

void Teacher::orderCheck(){
	//��ʾ�����
	Order od;
	if(od.m_size==0){
	cout<<"��ԤԼ��Ϣ��"<<endl;
	system("pause");
		system("cls");
	return;
	}

	vector<int>v;
	int index=1;
	cout<<"�����ԤԼ��Ϣ���£�"<<endl;
		for(int i=0;i<od.m_size;i++){
			if(od.m_order[i]["state"]=="1"){
			v.push_back(i);
		cout<<index<<". ";
		cout<<"ѧ��ѧ�ţ�"<<od.m_order[i]["studentID"]<<" ";
		cout<<"ѧ��������"<<od.m_order[i]["studentName"]<<" ";
		cout<<"ԤԼ���ڣ���"<<od.m_order[i]["date"]<<" ";
		cout<<"ԤԼʱ��Σ�"<<(od.m_order[i]["interval"]=="1"?"����":"����")<<" ";
		cout<<"ԤԼ������"<<od.m_order[i]["comRoom"]<<" ";
		cout<<"ԤԼ״̬�������"<<endl;
	    index++;
			}
     
}
		int select;
		int check;

		if(v.size()==0){
		cout<<"������Ҫ��˵�ԤԼ��Ϣ"<<endl;
		cout<<endl;
		system("pause");
		system("cls");
		return;
		}
		else{
		cout<<"��ѡ�������Ϣ��"<<endl;
		cout<<"(����0������һ��)"<<endl;
		cin>>select;
		if(select>=0 && select<=v.size()){
		
			if(select!=0){
		cout<<"��ѡ���Ƿ�ͨ����"<<endl;
		cout<<"1.ͨ��"<<endl;
		cout<<"2.��ͨ��"<<endl;
		cin>>check;
		if(check==1){
			od.m_order[v[select-1]]["state"]="2";
		
		}
		else{
		    od.m_order[v[select-1]]["state"]="-1";
		}
		od.updateOrder();
		cout<<"������"<<endl;
			}
			else if(select==0){
		
		system("cls");
			return;
			}

		}
		else{
		cout<<"�������"<<endl;
		}
		system("pause");
		system("cls");
		return;
		}
}