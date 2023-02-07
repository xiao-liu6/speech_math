#include "speechManager.h"
#include <iostream>
using namespace std;

int main() {
	
	SpeechManager man;
	int choice = 0;
	
	while (true)
	{
		man.show_Menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			//开始比赛
			man.begin_speech();
			break;
		case 2:
			//查看比赛记录
			man.scan_message();
			break;
		case 3:
			//清空比赛记录
			man.clear_message();
			break;
		case 0:
			//退出程序
			man.exitSystem();
			break;
		default:
			cout << "===选择有误，请重新选择===" << endl;
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}