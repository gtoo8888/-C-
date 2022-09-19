#include<iostream>
#include<vector>
#include<string>
 
using namespace std;
 
class Monkey
{
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
    vector<Monkey*> v;
    
    Monkey m1("Roman",2);
    Monkey m2("Jack",3);
    Monkey m3("Tom",2);
    Monkey m4("Daniel",2);
 
     v.push_back(&m1);
    v.push_back(&m2);
    v.push_back(&m3);
    v.push_back(&m4);
 
//±éÀú
    for(vector<Monkey*>::iterator it = v.begin();it != v.end(); it++)
    {
        cout<<"ÐÕÃû"<<(*it)->m_Name<<"ÄêÁä"<<(*it)->m_Age<<endl;
    }
 
}
int main()
{
    test();
    system("pause");
    return 0;
}
