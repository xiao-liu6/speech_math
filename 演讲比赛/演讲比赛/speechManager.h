#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SpeechManager{
public:
	//构造函数
	SpeechManager();
	//析构函数
	~SpeechManager();
	//显示菜单
	void show_Menu();
	//开始演讲比赛
	void begin_speech();
	//查看往届比赛信息
	void scan_message();
	//清空比赛记录
	void clear_message();
	//退出比赛程序
	void exitSystem();

};