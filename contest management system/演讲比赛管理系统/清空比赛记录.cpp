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

//��ձ�����¼
void Manager::clearContest(){
	if(this->emptyFile==1){
	cout<<"�ޱ�����¼"<<endl;
	system("pause");
system("cls");
return;
}
int select;
cout<<"�Ƿ�ȷ����������¼��"<<endl;
cout<<"1.��"<<endl;
cout<<"2.��"<<endl;
cin>>select;

if(select==1){
	//����ļ�
ofstream ofs;
ofs.open("speech.csv",ios::trunc);//�������д��ʽ��
ofs.close();

//��ʼ�������¼����
this->emptyFile=1;
this->init();
this->creatSpeaker();
this->loadScore();

cout<<"��ճɹ���"<<endl;


}
else{
system("cls");
return;
}
system("pause");
system("cls");
return;
}
