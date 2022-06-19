#include<iostream>
#include<vector>
#include<string>
 
using namespace std;
//存放自定义指针类型
class Monkey
{
    //创建一个猴子的类
    public:
        Monkey(string name,int age)
            {
                this->m_Name=name;
                this->m_Age=age;
            }
        string m_Name;
        int m_Age;
 
};
void test()
{
    vector<Monkey> v;//创建一个容器用来存放数据
    //赋值
    Monkey m1("Jack",2);//姓名，年龄
    Monkey m2("Roman",3);
    Monkey m3("Daniel",2);
    Monkey m4("Tom",2);
 
    //给容器中添加数据
    v.push_back(m1);
    v.push_back(m2);
    v.push_back(m3);
    v.push_back(m4);
 
//遍历容器
    for (vector<Monkey>::iterator it =v.begin();it!=v.end();it++)
{
    cout<<"姓名"<<(*it).m_Name<<"年龄"<<(*it).m_Age<<endl;
}
    
}
 
int main()
{
    test();
    system("pause");
    return 0;
}
