#pragma once
#include<iostream>
#include<speaker.h>
#include<vector>
#include<map>
#include<string>
#include<functional>
#include<algorithm>
#include<deque>
#include<numeric>
#include<fstream>
//构造函数
using namespace std;
//设计演讲管理类
class SpeedManager
{
public:
	//构造函数
	SpeedManager();
	//显示菜单
	void show_Menu();
	//比赛选手  容器 12人
	vector<int>v1;
	//第一轮晋级比赛
	vector<int>v2;
	//胜利前三名容器
	vector<int>victory;
	//存放编号  以及对应的具体选手 容器
	map<int, Speaker>m_Speaker;
	//记录比赛轮数
	int m_Index;
	//初始化属性
	void initSpeech();
	//创建选手对象函数
	void createSpeeder();
	//比赛流程控制函数
	void startSpeech();
	//抽签成员函数
	void speechDraw();
	//比赛过程函数
	void speechContest();
	//比赛结果显示函数
	void show_Score();
	//保存记录
	void save_Record();
	//读取记录
	void loadRecord();
	//查看记录功能
	void showRecord();
	//判读文件是否为空
	bool fileIsEmpty;
	//往届记录
	map<int, vector<string>>m_Record;
	//清空记录
	 void clearRecord();
	//退出系统
	void exitSystem();
	//析构函数
	~SpeedManager();
};