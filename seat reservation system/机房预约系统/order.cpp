#include <iostream>
#include"Order.h"
#include<fstream>
#include<string>
using namespace std;
#include"globalFILE.h"

Order::Order(){
	string ID;
	string name;
	string date;
	string interval;
	string comRoom;
	string state;
	
	this->m_size=0;
	ifstream ifs;
	ifs.open(ORDER,ios::in);

	string key;
	string value;
	map<string,string>m;


	if(!ifs.is_open()){
	cout<<"�ļ���ʧ�ܣ�"<<endl;
	return;
	}

	else{
		while(ifs>>ID && ifs>>name && ifs>>date && ifs>>interval && ifs>>comRoom &&ifs>>state){

		 //��һ��ԤԼ���� 
		  //ID��������
		  int pos=ID.find(":");
		  key=ID.substr(0,pos);
		  value=ID.substr(pos+1,ID.size()-pos-1);
		  m.insert(make_pair(key,value));

		  //name
		  pos=name.find(":");
		  key=name.substr(0,pos);
		  value=name.substr(pos+1,name.size()-pos-1);
		  m.insert(make_pair(key,value));
		  
		  //date
		  pos=date.find(":");
		  key=date.substr(0,pos);
		  value=date.substr(pos+1,date.size()-pos-1);
		  m.insert(make_pair(key,value));
		
		  //interval
		  pos=interval.find(":");
		  key=interval.substr(0,pos);
		  value=interval.substr(pos+1,interval.size()-pos-1);
		  m.insert(make_pair(key,value));

		  //����
		  pos=comRoom.find(":");
		  key=comRoom.substr(0,pos);
		  value=comRoom.substr(pos+1,comRoom.size()-pos-1);
		   m.insert(make_pair(key,value));

		   //״̬
		   pos=state.find(":");
		  key=state.substr(0,pos);
		  value=state.substr(pos+1,state.size()-pos-1);
		   m.insert(make_pair(key,value));
		 
		   m_order.insert(make_pair(this->m_size,m));
		   m.clear();
		   this->m_size++;
           
		}	 
		ifs.close();
		

	////�鿴������m_order����
	//	cout<<this->m_size<<endl;
	//for(map<int,map<string,string>>::iterator it=m_order.begin();it!=m_order.end();it++){
	//		cout<<"ԤԼ������"<<it->first<<endl;
	//		cout<<"��Ϣ��";
	//		for(map<string,string>::iterator mit=it->second.begin();mit!=it->second.end();mit++){
	//			
	//			cout<<mit->first<<" "<<mit->second<<" ";	
	//		}	
	//		cout<<endl;
	//	}
			
	}

		return;
}

//�����ļ�
void Order::updateOrder(){
	if(this->m_size==0){
	cout<<"��ԤԼ��¼��"<<endl;
	}
	ofstream ofs;
	ofs.open(ORDER,ios::out|ios::trunc);
	for(int i=0;i<this->m_size;i++){
	ofs<<"studentID:"<<this->m_order[i]["studentID"]<<" "
		<<"studentName:"<<this->m_order[i]["studentName"]<<" "
		<<"date:"<<this->m_order[i]["date"]<<" "
		<<"interval:"<<this->m_order[i]["interval"]<<" "
		<<"comRoom:"<<this->m_order[i]["comRoom"]<<" "
		<<"state:"<<this->m_order[i]["state"]<<endl;
	}

}