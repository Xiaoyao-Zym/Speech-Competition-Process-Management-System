#include<speedManager.h>
SpeedManager::SpeedManager()
{
    //初始化属性
    this->initSpeech();
    //创建选手
    this->createSpeeder();
   // 获取往届记录
    this->loadRecord();
}
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
//演讲比赛功能
//初始化属性
void SpeedManager::initSpeech()
{
    this->v1.clear();
    this->v2.clear();
    this->victory.clear();
    this->m_Speaker.clear();
    //初始化比赛轮数
    this->m_Index = 1;
    //初始化记录容器
    this->m_Record.clear();

}
void SpeedManager::createSpeeder()
{
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size() ; i++)
    {
        string name = "选手";
        name += nameSeed[i];
        Speaker sp;
        sp.m_Name = name;
        for (int j = 0; j < 2; j++)
        {
            sp.m_Score[j] = 0;
        }
        //12名选手编号
        this->v1.push_back(i + 10001);
        //选手编号、对应的选手存放到map容器中
        this->m_Speaker.insert(make_pair(i + 10001, sp));
    }
}
//比赛流程控制
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
    //重置比赛
    //初始化属性
    this->initSpeech();
    //创建选手
    this->createSpeeder();
    // 获取往届记录
    this->loadRecord();
    cout << "本届比赛完毕！" << endl;
    system("pause");
    system("cls");
}
//抽签函数
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
            cout << "------------第" << num / 6 << "小组比赛名次：---------------" << endl;
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
                    victory.push_back((*it).second);
                }
            }
            groupScore.clear();   //小组容器清空
        }
    }
    cout << endl;
    cout << "-----------第" << this->m_Index << "轮正式比赛结束：--------------" << endl;
}
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
    //有记录了，文件不为空
    this->fileIsEmpty = false;
}
//读取记录
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
            if (pos == -1)
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
    //for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
    //{
    //    cout << it->first << "冠军编号：" << it->second[0] << "分数：" << it->second[1] << endl;
    //}
}
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
//退出系统
void SpeedManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}
SpeedManager:: ~SpeedManager()
{

}