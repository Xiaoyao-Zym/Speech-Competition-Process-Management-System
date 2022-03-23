# 演讲比赛流程管理系统
## 1. 演讲比赛程序需求
### 1.1 比赛规则
* 学校举行一场演讲比赛，共有12个人参加。比赛共两轮，第一轮为淘汰赛，第二轮为比赛。
* 每名选手都有对应的编号，如10001~10012
* 比赛方式：分组比赛，每组6个人；
* 第一轮分为两个小组，整体按照选手编号进行抽签后顺序演讲。
* 十个评委分别给每名选手打分，去除最高分和最低分，求平均分为本轮选手的成绩
* 当小组演讲完后，淘汰组内排名最后三名选手，前三名晋级，进入下一轮的比赛
* 第二轮为决赛，前三名胜出
* 每轮比赛过后需要显示晋级选手的信息
### 1.2 程序功能
* 开始演讲比赛：完成正届比赛的流程，每个比赛阶段需要给用户一个提示，用户按任意键后继续下一个阶段
* 查看往届记录，查看之前比赛前三名结果，每次比赛都会记录到文件中，文件用.csv后缀名保存
* 清空比赛记录：将文件当前数据清空
* 退出比赛程序：可以退出当前程序
### 1.3 程序界面



## 2  菜单显示/退出系统
1. 制作一个菜单界面界面，显示选项
```C++
//显示菜单
void SpeedManager::show_Menu()
{
    cout << "*************************************" << endl;
    cout << "******" << "欢迎参加演讲比赛" << "******" << endl;
    cout << "******" << "1. 开始演讲比赛" << "******" << endl;
    cout << "******" << "2. 查看往届记录" << "******" << endl;
    cout << "******" << "3. 清空比赛记录" << "******" << endl;
    cout << "******" << "4. 退出比赛程序" << "******" << endl;
    cout << "*************************************" << endl;
    cout << endl;
}
```
编写退出系统界面
```C++
//退出系统
void SpeedManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}
```
## 3 演讲比赛功能
### 3.1 功能分析
比赛流程分析：
抽签——开始演讲比赛——显示第一轮比赛结果
抽签——开始演讲比赛——显示前三名结果——保存分数
### 3.2 创建选手类
* 选手类中的属性包含：选手姓名、分数
* 头文件中创建speaker.h文件，并添加代码：
```C++
//选手类
class Speaker
{
public:
	string m_Name;   //姓名
	double m_Score[2];  //分数，最多有两轮得分
};
```
### 3.3 比赛
####成员属性添加
* 在speechManager.h中添加属性
```C++
//比赛选手  容器 12人
	vector<int>v1;
	//第一轮晋级比赛
	vector<int>v2;
	//胜利前三名容器
	vector<int>wictory;
	//存放编号  以及对应的具体选手 容器
	map<int, Speaker>m_Speaker;
	//记录比赛轮数
	int m_Indx;
```
* 在speedManager.h中声明**void initSpeed()**
```C++
void SpeedManager::initSpeech()
{
    this->v1.clear();
    this->v2.clear();
    this->wictory.clear();
    this->m_Speaker.clear();
    //初始化比赛轮数
    this->m_Index = 1;
}
```
* 在管理类构造函数中调用initSpeed()函数
### 3.4 创建选手对象
在speechManager.cpp中编写void creatSpeaker();
```C++
void SpeedManager::createSpeeder()
{
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size() ; i++)
    {
        string name = "选手";
        name += nameSeed[i];
        Speaker sp;
        sp.m_Name = name;
        for (int i = 0; i < 2; i++)
        {
            sp.m_Score[i] = 0;
        }
        //12名选手编号
        this->v1.push_back(i + 10001);
        //选手编号、对应的选手存放到map容器中
        this->m_Speaker.insert(make_pair(i + 10001, sp));
    }
}
```
* 在管理类构造函数中调用CreateSpeed()函数
* 测试在main()函数中，可以创建完管理对象后，测试12名选手的对象
```C++
	//测试12名选手状态
	for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	{
		cout << "选手编号：" << it->first
			<< "姓名：" << it->second.m_Name
			<< "分数：" << it->second.m_Score << endl;
	}
```
###3.4 添加比赛成员函数
* 在speechManager.h添加开始比赛成员函数**void startSpeech();**
* 该函数功能是控制比赛的流程
>**//开始比赛 -比赛流程控制
  void startSpeech();**
* 在speedManager.cpp中实现函数
```C++

```

### 3.5 抽签
功能描述：
* 正式比赛前，所有选手的比赛顺序需要打乱，我们只需要存放选手编号的容器，打乱次序即可
* 在speechManger.h提供抽签的成员函数**void speechDraw();
>**//抽签
void speechDraw();**
* 在speechManager.cpp中实现成员函数**void speechDraw();**
```C++
void SpeedManager::speechDraw()
{
    cout << "第《" << this->m_Index << "》轮比赛选手正在抽签" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "抽签后演讲顺序如下：" << endl;
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
###3.6 比赛
* 在speechManager.cpp中实现成员函数void speechStart();
```C++
void SpeedManager::startSpeech()
{
    //比赛过程
    for (int i = 0; i < 2; i++)
    {
        //1.抽签
        this->speechDraw();
        //2.比赛
        this->speechContest();
        //3. 显示晋级结果
        this->show_Score();
        this->m_Index++;
    }
    //4. 保存分数
    this->save_Record();
    cout << "本届比赛完毕！" << endl;
    system("pause");
    system("cls");
}
```
* 在speechManager.cpp中实现成员函数void speechContest();
```C++
//比赛过程函数
void SpeedManager::speechContest()
{
    cout << "-----------第" << this->m_Index << "轮正式比赛开始：--------------" << endl;
    multimap<double, int, greater<double>>groupScore;   //临时容器，保存key分数value选手编号
    int num = 0;   //记录人员数，6个为1组
    vector<int>v_Src;    //比赛的人员容器
    if (this->m_Index == 1)
    {
        v_Src = v1;
    }
    else
    {
        v_Src = v2;
    }
    //遍历所有参赛选手
    for (vector<int>::iterator it=v_Src.begin(); it!=v_Src.end(); it++)
    {
        num++;
        //评委打分
        deque<double>d;
        for (int i = 0; i < 10; i++)
        {
            double score = (rand() % 401 + 600) / 10.f;  //600~1000
            //cout << score << " ";
            d.push_back(score);
        }
        //cout << endl;
        sort(d.begin(), d.end(), greater<double>());                //排序
        d.pop_front();                                                               //去掉最高分
        d.pop_back();                                                               //去掉最低分
        double sum = accumulate(d.begin(), d.end(), 0.0f);   //获取总分
        double avg = sum / (double)d.size();                         //获取平均分
        //cout<<"编号：" << *it << "姓名：" << this->m_Speaker[*it].m_Name << "   获取平均分为：" << avg << endl; //打印分数
        //将平均分放到map容器内
        this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;
        //6个人一组，用临时容器保存
        groupScore.insert(make_pair(avg, *it));   //key是得分，value是具体选手编号
        if (num % 6 == 0)
        {
            cout << "第" << num / 6 << "小组比赛名次：" << endl;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
            {
                cout << "编号：" << it->second<<" "
                        << "姓名：" << this->m_Speaker[it->second].m_Name <<" "
                        << "成绩：" << this->m_Speaker[it->second].m_Score[this->m_Index-1] << endl;
            }
            //取走前三名
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
            groupScore.clear();   //小组容器清空
        }
    }
    cout << "-----------第" << this->m_Index << "轮正式比赛结束：--------------" << endl;
    cout << endl;
}
```
### 3.7显示比赛结果
* 在speechManager.cpp中实现成员函数void showScore();
```C++
//比赛结果显示
void SpeedManager::show_Score()
{
    cout << "-----------第" << this->m_Index << "轮晋级选手成绩：--------------" << endl;
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
        cout << "选手编号：" << *it << "   "
            << "姓名：" << m_Speaker[*it].m_Name << "  "
            << "得分：" << m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
    }
    cout << endl;
    system("pause");
    system("cls");
    this->show_Menu();
}
```
### 3.8 保存记录 
* 在speechManager.cpp中实现成员函数void saveRecord();
```C++
//保存记录
void SpeedManager::save_Record()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);  //用追加的方式打开文件，写入
    //将比赛数据写入文件
    for (vector<int>::iterator it = victory.begin(); it != victory.end(); it++)
    {
        ofs << *it << ","<< this->m_Speaker[*it].m_Score[1] << ",";
    }
    ofs << endl;
    //关闭
    ofs.close();
    cout << "记录已保存" << endl;
}
```
## 4 查看记录
### 4.1 读取记录分数
* 在speechManager.h中添加保存记录的成员函数**void loadRecord();**
* 添加判断文件是否为空的标志**bool fileIsEmpty;
* 添加往届记录的容器map<int,  vecctor<string,>> m_Record;

其中m_Record中key代表第几层，value记录具体的信息
 * 在speechManager.cpp中实现保存记录的成员函数**void loadRecord();**

```C++
void SpeedManager:: loadRecord()
{
    ifstream ifs("speech.csv", ios::in);     //输入流对象 读取文件
    if (!ifs.is_open())
    {
        this->fileIsEmpty = true;
        cout << "文件不存在！" << endl;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        this->fileIsEmpty = true;
        cout << "文件不存在！" << endl;
        ifs.close();
        return;
    }
    //文件不为空
    this->fileIsEmpty = false;
    ifs.putback(ch); //读取单个字符
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
            pos = data.find(",", start);    //从0开始查找'."
            if (pos == 1)
            {
                break;  //找不到break返回
            }
            string tmp = data.substr(start, pos - start);    //找到了，进行分割 参数1 起始位置，参数2，截取长度
            v.push_back(tmp);
            start = pos + 1;
        }
        this->m_Record.insert(make_pair(index, v));
        index++;
    }
    ifs.close();
    cout << "记录已保存" << endl;
    //有记录了，文件不为空
    this->fileIsEmpty = false;
}
```
 * 在speechManager构造函数中调用获取往届记录函数

```C++
SpeedManager::SpeedManager()
{
    //初始化属性
    this->initSpeech();
    //创建选手
    this->createSpeeder();
    //获取往届记录
    this->loadRecord();
}
```
### 4.2 解析文件中的数据
```C++
    while (ifs >> data)
    {
        //cout<<data<<endl;
        vector<string>v;
        int pos = -1;
        int start = 0;
        while (true)
        {
            pos = data.find(",", start);    //从0开始查找'."
            if (pos == 1)
            {
                break;  //找不到break返回
            }
            string tmp = data.substr(start, pos - start);    //找到了，进行分割 参数1 起始位置，参数2，截取长度
            v.push_back(tmp);
            start = pos + 1;
        }
        this->m_Record.insert(make_pair(index, v));
        index++;
    }
```
##4.3查看记录功能
* 在speedManager.h中添加保存记录的成员函数**void showRecored();**
* 在speedManager.cpp中实现成员函数**void showRecord();**
```C++
//显示往届记录
void SpeedManager::showRecord()
{
    if (this->fileIsEmpty)
    {
        cout << "文件不存在，或记录为空！" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_Record.size(); i++)
        {
            cout << "第" << i + 1 << "届 " <<
                "冠军编号：" << this->m_Record[i][0] << " 得分： " << this->m_Record[i][1] << " "
                "亚军编号：" << this->m_Record[i][2] << " 得分： " << this->m_Record[i][3] << " "
                "季军编号：" << this->m_Record[i][4] << " 得分： " << this->m_Record[i][5] << " "
                << endl;
        }
    }
    system("pause");
    system("cls");
}
```
## 5 清空记录
* 在speedManager.h中添加保存记录的成员函数**void clearRecored();**
```C++
//清空记录
void SpeedManager::clearRecord()
{
    cout << "确认清空？"
        << "1：确认 "
        << "2：返回 " << endl;
    int slect = 0;
    cin >> slect;
    if (slect == 1)
    {
        //打开模式 ios::trunc 如果存在删除文件并创建
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();
        //初始化属性
        this->initSpeech();
        //创建选手
        this->createSpeeder();
        //获取往届记录
        this->loadRecord();
        cout << "清空完成！" << endl;
    }
    system("pause");
    system("cls");
}
```

  
