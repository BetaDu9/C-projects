#include <iostream>
#include <string>
#include <ctime>
using namespace std;
#include "Manager.h"

int main(){
	srand((unsigned int)time(NULL));
	Manager m;
	int select;

	////����
	//m.creatSpeaker();

	//for(map<int,Speaker>::iterator it=m.m_Speaker.begin();it!=m.m_Speaker.end();it++){
	//	cout<<"ѡ�ֱ�ţ�"<<it->first<<"  "<<"ѡ��������"<<it->second.m_name
	//		<<"  "<<"ѡ�ֵ÷֣�"<<it->second.m_score[0]<<endl;
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
		cout<<"��ӭ�´�ʹ�ã�"<<endl;
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