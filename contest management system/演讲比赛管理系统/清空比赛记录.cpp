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

//清空比赛记录
void Manager::clearContest(){
	if(this->emptyFile==1){
	cout<<"无比赛记录"<<endl;
	system("pause");
system("cls");
return;
}
int select;
cout<<"是否确认清空往届记录？"<<endl;
cout<<"1.是"<<endl;
cout<<"2.否"<<endl;
cin>>select;

if(select==1){
	//清空文件
ofstream ofs;
ofs.open("speech.csv",ios::trunc);//以清空重写方式打开
ofs.close();

//初始化往届记录容器
this->emptyFile=1;
this->init();
this->creatSpeaker();
this->loadScore();

cout<<"清空成功！"<<endl;


}
else{
system("cls");
return;
}
system("pause");
system("cls");
return;
}
