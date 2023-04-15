#include <iostream>
#include <fstream>
#include <ctime>
#include <random>
#include <chrono>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"
ofstream out("in.txt");

// std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
// std::uniform_int_distribution<int> dis(1, len);

int RandScope(int l,int r){
    return l+rand()%(l-r);
}


double RandDoubleScope(double l,double r){
    double x = (double)rand() / RAND_MAX; // 生成0~1之间的随机小数
    double range = r-l; // 计算随机数范围
    return x*range + l;// 将小数乘以范围并加上最小值，得到随机数
}


string NumtoString(vector<int> vec){
    string to_str = "{";
    for(auto it : vec){
        to_str += to_string(it) + ",";
    }
    to_str.erase(to_str.size()-1);
    to_str += "}";
    return to_str;
}


void CreateRandString(int num,int len,string template_str){
    int nt = template_str.size();

    for(int i = 0;i < num;i++){
        int str_len = RandScope(1,len);
        string create_tmp(str_len,' ');
        for(int i = 0;i < str_len;i++){
            create_tmp[i] = template_str[RandScope(0,nt)];
        }
        out << create_tmp << endl;
    }
}




void CreateVector(int num,int len,int range){
    for(int i = 0;i < num;i++){
        int vec_len = RandScope(1,len);
        vector<int> create_tmp(vec_len,0);
        for(int i = 0;i < vec_len;i++){
            create_tmp[i] = RandScope(-range,range);
        }
        out << NumtoString(create_tmp) << endl;
    }
}


void CreateUVector(int num,vector<int> range_len,vector<int> range_num){
    vector<vector<int>> to_UV;
    for(int i = 0;i < num;i++){
        int vec_len = RandScope(range_len[0],range_len[1]);
        vector<int> create_tmp(vec_len,0);
        for(int i = 0;i < vec_len;i++){
            create_tmp[i] = RandScope(range_num[0],range_num[1]);
        }
        to_UV.push_back(create_tmp);
        
    }
    sort(to_UV.begin(),to_UV.end(),[=](vector<int> v1,vector<int> v2){
        return v1[0] < v2[0];
    });
    for(int i = 0;i < to_UV.size();i++){
        string tmp_str = "[" + to_string(i) + "]";
        out << tmp_str << " " << NumtoString(to_UV[i]) << endl;
    }
}

void CreateNoRepeUVector(int num,vector<int> range_len,vector<int> range_num){
    vector<vector<int>> to_UV;
    for(int i = 0;i < num;i++){
        int vec_len = RandScope(range_len[0],range_len[1]);
        vector<int> create_tmp(vec_len,0);
        set<int> st;
        while(st.size() < vec_len){ // 使用set保证不重复
            st.emplace(RandScope(range_num[0],range_num[1]));
        }
        int j = 0;
        for(auto it : st){
            create_tmp[j++] = it;
        }
        to_UV.push_back(create_tmp);
    }
    sort(to_UV.begin(),to_UV.end(),[=](vector<int> v1,vector<int> v2){
        if(v1[0] < v2[0]){
            if(v1.size() < v2.size())
                return true;
            else 
                return false;
        }else{
            if(v1.size() < v2.size())
                return true;
            else 
                return false;  
        }
    });
    for(int i = 0;i < to_UV.size();i++){
        string tmp_str = "[" + to_string(i) + "]";
        out << tmp_str << " " << NumtoString(to_UV[i]) << endl;
    }
}


void CreateDouble(int num,vector<int> range_num){
    for(int i = 0;i < num;i++){
        out << RandDoubleScope(range_num[0],range_num[1]) << " "<<RandScope(range_num[0],range_num[1])<< endl;
    }

}

const string template_az = "abcdefghijklmnopqrstuvwxyz";
const string template_AZ = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
    srand((unsigned int)time(NULL));
    


    // 数量，长度，范围
    // CreateRandString(100,120,template_az);


    // vector<int> range_num = {-20,20};
    // CreateDouble(10,range_num);


    // vector<int> range_len = {5,20};
    // vector<int> range_num = {1,10};
    // CreateUVector(100,range_len,range_num);

    vector<int> range_len = {5,20};
    vector<int> range_num = {1,100};
    CreateNoRepeUVector(100,range_len,range_num);

	return 0;
}




