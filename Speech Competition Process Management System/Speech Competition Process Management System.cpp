#include<iostream>
#include<string>
#include<ctime>
#include<speedManager.h>
using namespace std;
int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	//创建管理类对象
	SpeedManager sm;
	////测试12名选手状态
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	cout << "选手编号：" << it->first<<" "
	//		    << "姓名：" << it->second.m_Name<<" "
	//		    << "分数：" << it->second.m_Score << endl;
	//}
	int choice = 0;
	while (true)
	{
		//展示菜单
		sm.show_Menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:  sm.startSpeech(); // 开始比赛
			break;
		case 2:  sm.showRecord();  //查看记录
			break;
		case 3:  sm.clearRecord();  //清空记录
			break;
		case 0:  sm.exitSystem(); //退出系统
			break;
		default:
			system("cls"); //清屏
			break;
		}
	}
	system("pause");
	return 0;
}