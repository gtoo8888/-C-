#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#define digit 30
using namespace std;
string LLMax="9223372036854775807";
string IntMax="2147483647";
string SmellAlphabet="abcdefghijklmnopqrstuvwxyz";
string UpperAlphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string RandomString()
{
    int n=rand()%digit+1;//接下来生成n位字符串
    string s;
    for(int i=0;i<n;i++) s+=SmellAlphabet[rand()%26];//随机产生字符串
    return s;
}
int main()
{
    int m=0;
    srand((unsigned)time(NULL));
    for(int i=0;i<50;i++)
        cout<<RandomString()<<endl;
    return 0;
}