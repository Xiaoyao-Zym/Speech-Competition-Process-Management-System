# �ݽ��������̹���ϵͳ
## 1. �ݽ�������������
### 1.1 ��������
* ѧУ����һ���ݽ�����������12���˲μӡ����������֣���һ��Ϊ��̭�����ڶ���Ϊ������
* ÿ��ѡ�ֶ��ж�Ӧ�ı�ţ���10001~10012
* ������ʽ�����������ÿ��6���ˣ�
* ��һ�ַ�Ϊ����С�飬���尴��ѡ�ֱ�Ž��г�ǩ��˳���ݽ���
* ʮ����ί�ֱ��ÿ��ѡ�ִ�֣�ȥ����߷ֺ���ͷ֣���ƽ����Ϊ����ѡ�ֵĳɼ�
* ��С���ݽ������̭���������������ѡ�֣�ǰ����������������һ�ֵı���
* �ڶ���Ϊ������ǰ����ʤ��
* ÿ�ֱ���������Ҫ��ʾ����ѡ�ֵ���Ϣ
### 1.2 ������
* ��ʼ�ݽ����������������������̣�ÿ�������׶���Ҫ���û�һ����ʾ���û���������������һ���׶�
* �鿴�����¼���鿴֮ǰ����ǰ���������ÿ�α��������¼���ļ��У��ļ���.csv��׺������
* ��ձ�����¼�����ļ���ǰ�������
* �˳��������򣺿����˳���ǰ����
### 1.3 �������



## 2  �˵���ʾ/�˳�ϵͳ
1. ����һ���˵�������棬��ʾѡ��
```C++
//��ʾ�˵�
void SpeedManager::show_Menu()
{
    cout << "*************************************" << endl;
    cout << "******" << "��ӭ�μ��ݽ�����" << "******" << endl;
    cout << "******" << "1. ��ʼ�ݽ�����" << "******" << endl;
    cout << "******" << "2. �鿴�����¼" << "******" << endl;
    cout << "******" << "3. ��ձ�����¼" << "******" << endl;
    cout << "******" << "4. �˳���������" << "******" << endl;
    cout << "*************************************" << endl;
    cout << endl;
}
```
��д�˳�ϵͳ����
```C++
//�˳�ϵͳ
void SpeedManager::exitSystem()
{
    cout << "��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(0);
}
```
## 3 �ݽ���������
### 3.1 ���ܷ���
�������̷�����
��ǩ������ʼ�ݽ�����������ʾ��һ�ֱ������
��ǩ������ʼ�ݽ�����������ʾǰ������������������
### 3.2 ����ѡ����
* ѡ�����е����԰�����ѡ������������
* ͷ�ļ��д���speaker.h�ļ�������Ӵ��룺
```C++
//ѡ����
class Speaker
{
public:
	string m_Name;   //����
	double m_Score[2];  //��������������ֵ÷�
};
```
### 3.3 ����
####��Ա�������
* ��speechManager.h���������
```C++
//����ѡ��  ���� 12��
	vector<int>v1;
	//��һ�ֽ�������
	vector<int>v2;
	//ʤ��ǰ��������
	vector<int>wictory;
	//��ű��  �Լ���Ӧ�ľ���ѡ�� ����
	map<int, Speaker>m_Speaker;
	//��¼��������
	int m_Indx;
```
* ��speedManager.h������**void initSpeed()**
```C++
void SpeedManager::initSpeech()
{
    this->v1.clear();
    this->v2.clear();
    this->wictory.clear();
    this->m_Speaker.clear();
    //��ʼ����������
    this->m_Index = 1;
}
```
* �ڹ����๹�캯���е���initSpeed()����
### 3.4 ����ѡ�ֶ���
��speechManager.cpp�б�дvoid creatSpeaker();
```C++
void SpeedManager::createSpeeder()
{
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size() ; i++)
    {
        string name = "ѡ��";
        name += nameSeed[i];
        Speaker sp;
        sp.m_Name = name;
        for (int i = 0; i < 2; i++)
        {
            sp.m_Score[i] = 0;
        }
        //12��ѡ�ֱ��
        this->v1.push_back(i + 10001);
        //ѡ�ֱ�š���Ӧ��ѡ�ִ�ŵ�map������
        this->m_Speaker.insert(make_pair(i + 10001, sp));
    }
}
```
* �ڹ����๹�캯���е���CreateSpeed()����
* ������main()�����У����Դ�����������󣬲���12��ѡ�ֵĶ���
```C++
	//����12��ѡ��״̬
	for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << it->first
			<< "������" << it->second.m_Name
			<< "������" << it->second.m_Score << endl;
	}
```
###3.4 ��ӱ�����Ա����
* ��speechManager.h��ӿ�ʼ������Ա����**void startSpeech();**
* �ú��������ǿ��Ʊ���������
>**//��ʼ���� -�������̿���
  void startSpeech();**
* ��speedManager.cpp��ʵ�ֺ���
```C++

```

### 3.5 ��ǩ
����������
* ��ʽ����ǰ������ѡ�ֵı���˳����Ҫ���ң�����ֻ��Ҫ���ѡ�ֱ�ŵ����������Ҵ��򼴿�
* ��speechManger.h�ṩ��ǩ�ĳ�Ա����**void speechDraw();
>**//��ǩ
void speechDraw();**
* ��speechManager.cpp��ʵ�ֳ�Ա����**void speechDraw();**
```C++
void SpeedManager::speechDraw()
{
    cout << "�ڡ�" << this->m_Index << "���ֱ���ѡ�����ڳ�ǩ" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "��ǩ���ݽ�˳�����£�" << endl;
    if (this->m_Index == 1)
    {
        random_shuffle(v1.begin(), v1.end());
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else
    {
        random_shuffle(v2.begin(), v2.end());
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    system("pause");
    cout << endl;
}
```
###3.6 ����
* ��speechManager.cpp��ʵ�ֳ�Ա����void speechStart();
```C++
void SpeedManager::startSpeech()
{
    //��������
    for (int i = 0; i < 2; i++)
    {
        //1.��ǩ
        this->speechDraw();
        //2.����
        this->speechContest();
        //3. ��ʾ�������
        this->show_Score();
        this->m_Index++;
    }
    //4. �������
    this->save_Record();
    cout << "���������ϣ�" << endl;
    system("pause");
    system("cls");
}
```
* ��speechManager.cpp��ʵ�ֳ�Ա����void speechContest();
```C++
//�������̺���
void SpeedManager::speechContest()
{
    cout << "-----------��" << this->m_Index << "����ʽ������ʼ��--------------" << endl;
    multimap<double, int, greater<double>>groupScore;   //��ʱ����������key����valueѡ�ֱ��
    int num = 0;   //��¼��Ա����6��Ϊ1��
    vector<int>v_Src;    //��������Ա����
    if (this->m_Index == 1)
    {
        v_Src = v1;
    }
    else
    {
        v_Src = v2;
    }
    //�������в���ѡ��
    for (vector<int>::iterator it=v_Src.begin(); it!=v_Src.end(); it++)
    {
        num++;
        //��ί���
        deque<double>d;
        for (int i = 0; i < 10; i++)
        {
            double score = (rand() % 401 + 600) / 10.f;  //600~1000
            //cout << score << " ";
            d.push_back(score);
        }
        //cout << endl;
        sort(d.begin(), d.end(), greater<double>());                //����
        d.pop_front();                                                               //ȥ����߷�
        d.pop_back();                                                               //ȥ����ͷ�
        double sum = accumulate(d.begin(), d.end(), 0.0f);   //��ȡ�ܷ�
        double avg = sum / (double)d.size();                         //��ȡƽ����
        //cout<<"��ţ�" << *it << "������" << this->m_Speaker[*it].m_Name << "   ��ȡƽ����Ϊ��" << avg << endl; //��ӡ����
        //��ƽ���ַŵ�map������
        this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;
        //6����һ�飬����ʱ��������
        groupScore.insert(make_pair(avg, *it));   //key�ǵ÷֣�value�Ǿ���ѡ�ֱ��
        if (num % 6 == 0)
        {
            cout << "��" << num / 6 << "С��������Σ�" << endl;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
            {
                cout << "��ţ�" << it->second<<" "
                        << "������" << this->m_Speaker[it->second].m_Name <<" "
                        << "�ɼ���" << this->m_Speaker[it->second].m_Score[this->m_Index-1] << endl;
            }
            //ȡ��ǰ����
            int count = 0;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end()&&count<3; it++, count++)
            {
                if (this->m_Index == 1)
                {
                    v2.push_back((*it).second);
                }
                else
                {
                    wictory.push_back((*it).second);
                }
            }
            groupScore.clear();   //С���������
        }
    }
    cout << "-----------��" << this->m_Index << "����ʽ����������--------------" << endl;
    cout << endl;
}
```
### 3.7��ʾ�������
* ��speechManager.cpp��ʵ�ֳ�Ա����void showScore();
```C++
//���������ʾ
void SpeedManager::show_Score()
{
    cout << "-----------��" << this->m_Index << "�ֽ���ѡ�ֳɼ���--------------" << endl;
    vector<int>v;
    if (this->m_Index == 1)
    {
        v = v2;
    }
    else
    {
        v = victory;
    }
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout << "ѡ�ֱ�ţ�" << *it << "   "
            << "������" << m_Speaker[*it].m_Name << "  "
            << "�÷֣�" << m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
    }
    cout << endl;
    system("pause");
    system("cls");
    this->show_Menu();
}
```
### 3.8 �����¼ 
* ��speechManager.cpp��ʵ�ֳ�Ա����void saveRecord();
```C++
//�����¼
void SpeedManager::save_Record()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);  //��׷�ӵķ�ʽ���ļ���д��
    //����������д���ļ�
    for (vector<int>::iterator it = victory.begin(); it != victory.end(); it++)
    {
        ofs << *it << ","<< this->m_Speaker[*it].m_Score[1] << ",";
    }
    ofs << endl;
    //�ر�
    ofs.close();
    cout << "��¼�ѱ���" << endl;
}
```
## 4 �鿴��¼
### 4.1 ��ȡ��¼����
* ��speechManager.h����ӱ����¼�ĳ�Ա����**void loadRecord();**
* ����ж��ļ��Ƿ�Ϊ�յı�־**bool fileIsEmpty;
* ��������¼������map<int,  vecctor<string,>> m_Record;

����m_Record��key����ڼ��㣬value��¼�������Ϣ
 * ��speechManager.cpp��ʵ�ֱ����¼�ĳ�Ա����**void loadRecord();**

```C++
void SpeedManager:: loadRecord()
{
    ifstream ifs("speech.csv", ios::in);     //���������� ��ȡ�ļ�
    if (!ifs.is_open())
    {
        this->fileIsEmpty = true;
        cout << "�ļ������ڣ�" << endl;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        this->fileIsEmpty = true;
        cout << "�ļ������ڣ�" << endl;
        ifs.close();
        return;
    }
    //�ļ���Ϊ��
    this->fileIsEmpty = false;
    ifs.putback(ch); //��ȡ�����ַ�
    string data;
    int index = 0;
    while (ifs >> data)
    {
        //cout<<data<<endl;
        vector<string>v;
        int pos = -1;
        int start = 0;
        while (true)
        {
            pos = data.find(",", start);    //��0��ʼ����'."
            if (pos == 1)
            {
                break;  //�Ҳ���break����
            }
            string tmp = data.substr(start, pos - start);    //�ҵ��ˣ����зָ� ����1 ��ʼλ�ã�����2����ȡ����
            v.push_back(tmp);
            start = pos + 1;
        }
        this->m_Record.insert(make_pair(index, v));
        index++;
    }
    ifs.close();
    cout << "��¼�ѱ���" << endl;
    //�м�¼�ˣ��ļ���Ϊ��
    this->fileIsEmpty = false;
}
```
 * ��speechManager���캯���е��û�ȡ�����¼����

```C++
SpeedManager::SpeedManager()
{
    //��ʼ������
    this->initSpeech();
    //����ѡ��
    this->createSpeeder();
    //��ȡ�����¼
    this->loadRecord();
}
```
### 4.2 �����ļ��е�����
```C++
    while (ifs >> data)
    {
        //cout<<data<<endl;
        vector<string>v;
        int pos = -1;
        int start = 0;
        while (true)
        {
            pos = data.find(",", start);    //��0��ʼ����'."
            if (pos == 1)
            {
                break;  //�Ҳ���break����
            }
            string tmp = data.substr(start, pos - start);    //�ҵ��ˣ����зָ� ����1 ��ʼλ�ã�����2����ȡ����
            v.push_back(tmp);
            start = pos + 1;
        }
        this->m_Record.insert(make_pair(index, v));
        index++;
    }
```
##4.3�鿴��¼����
* ��speedManager.h����ӱ����¼�ĳ�Ա����**void showRecored();**
* ��speedManager.cpp��ʵ�ֳ�Ա����**void showRecord();**
```C++
//��ʾ�����¼
void SpeedManager::showRecord()
{
    if (this->fileIsEmpty)
    {
        cout << "�ļ������ڣ����¼Ϊ�գ�" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_Record.size(); i++)
        {
            cout << "��" << i + 1 << "�� " <<
                "�ھ���ţ�" << this->m_Record[i][0] << " �÷֣� " << this->m_Record[i][1] << " "
                "�Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣� " << this->m_Record[i][3] << " "
                "������ţ�" << this->m_Record[i][4] << " �÷֣� " << this->m_Record[i][5] << " "
                << endl;
        }
    }
    system("pause");
    system("cls");
}
```
## 5 ��ռ�¼
* ��speedManager.h����ӱ����¼�ĳ�Ա����**void clearRecored();**
```C++
//��ռ�¼
void SpeedManager::clearRecord()
{
    cout << "ȷ����գ�"
        << "1��ȷ�� "
        << "2������ " << endl;
    int slect = 0;
    cin >> slect;
    if (slect == 1)
    {
        //��ģʽ ios::trunc �������ɾ���ļ�������
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();
        //��ʼ������
        this->initSpeech();
        //����ѡ��
        this->createSpeeder();
        //��ȡ�����¼
        this->loadRecord();
        cout << "�����ɣ�" << endl;
    }
    system("pause");
    system("cls");
}
```

  
