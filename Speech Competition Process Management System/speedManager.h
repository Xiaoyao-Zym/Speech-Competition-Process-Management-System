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
//���캯��
using namespace std;
//����ݽ�������
class SpeedManager
{
public:
	//���캯��
	SpeedManager();
	//��ʾ�˵�
	void show_Menu();
	//����ѡ��  ���� 12��
	vector<int>v1;
	//��һ�ֽ�������
	vector<int>v2;
	//ʤ��ǰ��������
	vector<int>victory;
	//��ű��  �Լ���Ӧ�ľ���ѡ�� ����
	map<int, Speaker>m_Speaker;
	//��¼��������
	int m_Index;
	//��ʼ������
	void initSpeech();
	//����ѡ�ֶ�����
	void createSpeeder();
	//�������̿��ƺ���
	void startSpeech();
	//��ǩ��Ա����
	void speechDraw();
	//�������̺���
	void speechContest();
	//���������ʾ����
	void show_Score();
	//�����¼
	void save_Record();
	//��ȡ��¼
	void loadRecord();
	//�鿴��¼����
	void showRecord();
	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;
	//�����¼
	map<int, vector<string>>m_Record;
	//��ռ�¼
	 void clearRecord();
	//�˳�ϵͳ
	void exitSystem();
	//��������
	~SpeedManager();
};