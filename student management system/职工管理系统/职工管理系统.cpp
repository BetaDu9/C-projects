#include <iostream>
#include <string>
using namespace std;
#include "worker manager.h"
#include "worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

int main(){
	workerManager wm;
	int select;
	 while(true){
	   wm.showMenu();
	   cin>>select;
	   switch(select){
	   case 0://退出系统
		   cout<<"欢迎下次使用！"<<endl;
		   system("pause");
		   return 0;
		   break;
	   case 1:wm.addPerson();
		  
		   break;
	   case 2:wm.showPerson();
		   break;
	   case 3:wm.deletePer();
		   break;
	   case 4:wm.modPerson();
		   break;
	   case 5:wm.search();
		   break;
        case 6:
		   break;
		case 7:wm.clear();
			break;
		default:
			 system("cls");
			break;

	   }

	 
	 }
	system("pause");
	return 0;

}