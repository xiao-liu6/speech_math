#include "speechManager.h"
#include "speaker.h"
#include <algorithm>
#include <time.h>
#include <fstream>

//构造函数
SpeechManager::SpeechManager() {

}

//析构函数
SpeechManager::~SpeechManager() {

}

//显示菜单
void SpeechManager::show_Menu() {
	cout << "========================================================" << endl;
	cout << "=================== 欢迎参加演讲比赛 ===================" << endl;
	cout << "===================  1.开始演讲比赛 ====================" << endl;
	cout << "===================  2.查看比赛记录 ====================" << endl;
	cout << "===================  3.清空比赛记录 ====================" << endl;
	cout << "===================  0.退出比赛程序 ====================" << endl;
	cout << "========================================================" << endl;
	cout << endl;
}

bool compare_score(const Speaker& s1, const Speaker& s2 ) {
	return s1.s_score > s2.s_score;
}

//开始演讲比赛
void SpeechManager::begin_speech() {
	vector<Speaker> v;
	string str = "ABCDEFGHIJKL";
	string s = "选手";
	int num = 1000000;
	Speaker sp;
	srand(time(NULL));

	for (size_t i = 1; i <= 12; i++)
	{
		sp.s_num = num + i;
		sp.s_name = s + str[i - 1];
		sp.s_score = (rand() % 1000 + 8000) / 100.0;
		v.push_back(sp);
	}

	random_shuffle(v.begin(),v.end());

	vector<Speaker> v1;
	vector<Speaker> v2;

	vector<Speaker> v_last;

	for (size_t i = 0; i < v.size() / 2; i++)
	{
		v1.push_back(v[i]);
		v2.push_back(v[i + 6]);
	}

	for (size_t i = 0; i < 3; i++)
	{
		v1[i].s_score = (rand() % 1000 + 8000) / 100.0;
		v2[i].s_score = (rand() % 1000 + 8000) / 100.0;
		v_last.push_back(v1[i]);
		v_last.push_back(v2[i]);
	}
	sort(v_last.begin(), v_last.end(), compare_score);
	v_last.pop_back();
	v_last.pop_back();
	v_last.pop_back();

	static int count = 1;
	if (count == 1)
	{
		cout << "第<< " << count << " >>轮演讲比赛结果" << endl;
		cout << "---第一组成绩---" << endl;
		sort(v1.begin(), v1.end(), compare_score);
		for (vector<Speaker>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << " 编号：" << it->s_num << " 姓名：" << it->s_name << " 分数：" << it->s_score << endl;
		}
		cout << "---第二组成绩---" << endl;
		sort(v2.begin(), v2.end(), compare_score);
		for (vector<Speaker>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << " 编号：" << it->s_num << " 姓名：" << it->s_name << " 分数：" << it->s_score << endl;
		}
		count++;
	}
	else if (count == 2) {
		
		cout << "第<< " << count << " >>轮演讲比赛结果" << endl;
		cout << "---晋级赛选手信息---" << endl;
		sort(v_last.begin(), v_last.end(), compare_score);
		for (vector<Speaker>::iterator it = v_last.begin(); it != v_last.end(); it++)
		{
			cout << " 编号：" << it->s_num << " 姓名：" << it->s_name << " 分数：" << it->s_score << endl;
		}
		
		ifstream ifs("speech_winer.txt", ios::in);
		int line_num = 0;
		string s;
		while (getline(ifs, s))
		{
			line_num++;
		}
		ifs.close();

		ofstream ofs("speech_winer.txt", ios::out | ios::app);
		int n = 0;
		n += line_num / 4 + 1;
		ofs << "第" << n << "届演讲比赛" << endl;
		for (vector<Speaker>::iterator it = v_last.begin(); it != v_last.end(); it++)
		{
			ofs << " 编号：" << it->s_num << " 姓名：" << it->s_name << " 分数：" << it->s_score << endl;
		}
		
		ofs.close();
	}
	
	system("pause");
	system("cls");
}

void SpeechManager::scan_message() {
	ifstream ifs("speech_winer.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}

	char ch;	
	ifs >> ch;	//读取一个字符
	if (ifs.eof())  //如果读取不到
	{
		cout << "文件为空" << endl;
		return;
	}
	ifs.putback(ch);	//放回读取的字符

	string buf3;
	while (getline(ifs, buf3)) {
		cout << buf3 << endl;
	}

	ifs.close();
}

//清空比赛记录
void SpeechManager::clear_message() {
	cout << "是否确认清空文件" << endl;
	cout << " 1.确认" << endl;
	cout << " 0.返回" << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		ofstream ofs("speech_winer.txt", ios::trunc);
		ofs.close();
	}
	else if (choice == 0) {
		system("cls");
	}
}

//退出比赛程序
void SpeechManager::exitSystem() {
	cout << "请问是否确认退出程序" << endl;
	cout << "  1.确认" << endl;
	cout << "  0.返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "欢迎下次使用" << endl;
		exit(0);
	}
	else if (select == 0) {
		system("cls");
	}
}
