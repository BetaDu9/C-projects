#include <iostream>
#include <string>
#include <ctime>
using namespace std;
#include "Manager.h"

int main(){
	srand((unsigned int)time(NULL));
	Manager m;
	int select;

	////测试
	//m.creatSpeaker();

	//for(map<int,Speaker>::iterator it=m.m_Speaker.begin();it!=m.m_Speaker.end();it++){
	//	cout<<"选手编号："<<it->first<<"  "<<"选手姓名："<<it->second.m_name
	//		<<"  "<<"选手得分："<<it->second.m_score[0]<<endl;
	//}

	
	while(true){
	m.showMenu();
	cin>>select;
	switch(select){
	case 1:m.StartSpeech();
		break;
	case 2:m.showContest();
		break;
	case 3:m.clearContest();
		break;
	case 0:
		cout<<"欢迎下次使用！"<<endl;
		system("pause");
		   return 0;
		break;
	default:
		system("cls");
		break;
	
	}
	
	}


system("pause");
return 0;

}