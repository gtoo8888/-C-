#include<iostream>
#include<vector>
#include<string>
 
using namespace std;
//����Զ���ָ������
class Monkey
{
    //����һ�����ӵ���
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
    vector<Monkey> v;//����һ�����������������
    //��ֵ
    Monkey m1("Jack",2);//����������
    Monkey m2("Roman",3);
    Monkey m3("Daniel",2);
    Monkey m4("Tom",2);
 
    //���������������
    v.push_back(m1);
    v.push_back(m2);
    v.push_back(m3);
    v.push_back(m4);
 
//��������
    for (vector<Monkey>::iterator it =v.begin();it!=v.end();it++)
{
    cout<<"����"<<(*it).m_Name<<"����"<<(*it).m_Age<<endl;
}
    
}
 
int main()
{
    test();
    system("pause");
    return 0;
}
