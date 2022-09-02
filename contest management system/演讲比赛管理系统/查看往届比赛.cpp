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


//查看往届记录
void Manager::showContest(){
//无比赛记录
if(this->emptyFile==1){
	cout<<"无比赛记录"<<endl;
	system("pause");
system("cls");
return;
}

  int index=0;
  for(map<int,vector<string>>::iterator it=this->m_Contest.begin();it!=this->m_Contest.end();it++){
	  cout<<"第"<<it->first<<"届比赛成绩如下："<<endl;
	  cout<<"冠军："<<it->second[0]<<" 得分："<<it->second[1]
	  <<"   亚军："<<it->second[2]<<" 得分："<<it->second[3]
	  <<"   季军："<<it->second[4]<<" 得分："<<it->second[5]<<endl;
	  cout<<endl;

  }
system("pause");
system("cls");
return;
}