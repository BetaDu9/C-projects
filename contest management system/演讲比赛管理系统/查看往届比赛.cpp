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


//�鿴�����¼
void Manager::showContest(){
//�ޱ�����¼
if(this->emptyFile==1){
	cout<<"�ޱ�����¼"<<endl;
	system("pause");
system("cls");
return;
}

  int index=0;
  for(map<int,vector<string>>::iterator it=this->m_Contest.begin();it!=this->m_Contest.end();it++){
	  cout<<"��"<<it->first<<"������ɼ����£�"<<endl;
	  cout<<"�ھ���"<<it->second[0]<<" �÷֣�"<<it->second[1]
	  <<"   �Ǿ���"<<it->second[2]<<" �÷֣�"<<it->second[3]
	  <<"   ������"<<it->second[4]<<" �÷֣�"<<it->second[5]<<endl;
	  cout<<endl;

  }
system("pause");
system("cls");
return;
}