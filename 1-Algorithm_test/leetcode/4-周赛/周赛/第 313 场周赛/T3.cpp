#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


int calBit(int n) {
	int count = 0;
    while(n != 0 ) {
        if(n & 1 == 1)  
            count++;
        n >>= 1;
    }
	return count;
}

int calnum(string str) {
    int n = str.size();
    int ans = 0;
    int j = 0;
    for(int i = n-1;i >= 0;i--){
        // printf("%d\n",pow(2,j));
        if(str[i] == '1')
            ans += pow(2,j);
        j++;
    }
	return ans;
}

// class Solution {
// public:
//     int minimizeXor(int num1, int num2) {
//         PrintBit(num2);
//         PrintBit(111);
//         int num_len = max(num1,num2);
//         int min_XOR = INT32_MAX;
//         int ans = -1;
//         for(int i = 123;i > 0;i--){
            
//             if(calBit(i) == calBit(num2)){
//                 printf("i:%d %d %d\n",i,calBit(i) , calBit(num2));
//                 int num_XOR = i ^ num1;
                
//                 if(num_XOR < min_XOR){
//                     min_XOR = num_XOR;
//                     ans = i;
//                 }
//                 printf("num_XOR:%d %d \n",num_XOR,ans);
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // PrintBit(num2);
        // PrintBit(111);
        // calnum("11");
        printf("%d\n",63^95);
        printf("%d\n",calnum("1110"));
        int need_one = calBit(num2);
        
        // cout << tmp << endl;
        int min_XOR = INT32_MAX;
        int ans = 0;
        for(int i = 1;i <= need_one;i++){
            string tmp(need_one,'1');
            tmp.insert(tmp.begin()+i,'0');
             cout << tmp << endl;
            int str_num = calnum(tmp);
            int num_XOR = i ^ str_num;
            if(num_XOR < min_XOR){
                min_XOR = num_XOR;
                ans = str_num;
            }
            printf("i:%d %d %d %d\n",str_num,ans,num_XOR,min_XOR);
        }
        return ans;
    }
};
	
int main() {
	Solution solution;
    // int num1 = 3,num2 = 5;  // 3 
    // int num1 = 1,num2 = 12;
    // int num1 = 64,num2 = 40; // 65
    int num1 = 99,num2 = 63;    // 111

    auto ans = solution.minimizeXor(num1,num2);

	cout << ans << endl;
	return 0;
}




