#include<iostream>
#include<string>
#include<ctime>
#include<speedManager.h>
using namespace std;
int main()
{
	//���������
	srand((unsigned int)time(NULL));
	//�������������
	SpeedManager sm;
	////����12��ѡ��״̬
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	cout << "ѡ�ֱ�ţ�" << it->first<<" "
	//		    << "������" << it->second.m_Name<<" "
	//		    << "������" << it->second.m_Score << endl;
	//}
	int choice = 0;
	while (true)
	{
		//չʾ�˵�
		sm.show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:  sm.startSpeech(); // ��ʼ����
			break;
		case 2:  sm.showRecord();  //�鿴��¼
			break;
		case 3:  sm.clearRecord();  //��ռ�¼
			break;
		case 0:  sm.exitSystem(); //�˳�ϵͳ
			break;
		default:
			system("cls"); //����
			break;
		}
	}
	system("pause");
	return 0;
}