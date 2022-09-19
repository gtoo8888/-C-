#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintVB(vector<bool> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

// class Solution {
// public:
//     vector<int> NumSeparate(int n) {//每个位拆开求和 
//         vector<int> ans;
//         int temp = n;
//         while(temp != 0){
//             ans.push_back(temp%10);
//             temp = temp / 10;			
//         }
//         return ans;
//     }
//     int largestInteger(int num) {
//         vector<int> num_w_tmp = NumSeparate(num);
//         vector<int> num_w(num_w_tmp.size(),0);
//         for(int i = 0;i < num_w_tmp.size();i++){
//             num_w[num_w_tmp.size() - 1 - i] = num_w_tmp[i];
//         }
//         // PrintVector(num_w);
//         vector<int> num_jishu;
//         vector<int> num_oushu;
//         for(int i = 0;i < num_w.size();i += 2)
//             num_oushu.push_back(num_w[i]);

//         for(int i = 1;i < num_w.size();i += 2)
//             num_jishu.push_back(num_w[i]);

//         sort(num_oushu.begin(),num_oushu.end(),greater<int>());
//         sort(num_jishu.begin(),num_jishu.end(),greater<int>());
//         // PrintVector(num_oushu);
//         // PrintVector(num_jishu);
//         vector<int> ans(num_w.size(),0);
//         int oushu_i = 0;
//         int jishu_i = 0;
//         for(int i = 0;i < num_w.size();i++){
//             if(i%2 == 0){
//                 ans[i] = num_oushu[oushu_i++];
//             }else{
//                 ans[i] = num_jishu[jishu_i++];
//             }
//         }
//         // PrintVector(ans);
//         int ans_num = 0;
//         int ten_i = 0;
//         for(int i = ans.size()-1;i >= 0;i--){
//             ans_num += ans[i]*pow(10,ten_i);
//             // printf("%d %d\n",ans[i],pow(10,ten_i));
//             ten_i++;
//         }
//         return ans_num;
//     }
// };



class Solution {
public:
    vector<int> NumSeparate(int n) {//每个位拆开求和 
        vector<int> ans;
        int temp = n;
        while(temp != 0){
            ans.push_back(temp%10);
            temp = temp / 10;			
        }
        return ans;
    }
    int largestInteger(int num) {
        vector<int> num_w_tmp = NumSeparate(num);
        vector<int> num_w(num_w_tmp.size(),0);
        for(int i = 0;i < num_w_tmp.size();i++){
            num_w[num_w_tmp.size() - 1 - i] = num_w_tmp[i];
        }
        vector<bool> num_flag(num_w_tmp.size(),false);
        for(int i = 0;i < num_w.size();i++){
            if(num_w[i]%2 == 0)
                num_flag[i] = true;     //偶数
            else
                num_flag[i] = false;    //奇数
        }
        // PrintVB(num_flag);
        // PrintVector(num_w);
        vector<int> num_jishu;
        vector<int> num_oushu;
        for(int i = 0;i < num_w.size();i++){
            if(num_w[i]%2 == 0)
                num_oushu.push_back(num_w[i]);
            else    
                num_jishu.push_back(num_w[i]);  
        }
        sort(num_oushu.begin(),num_oushu.end(),greater<int>());
        sort(num_jishu.begin(),num_jishu.end(),greater<int>());
        // PrintVector(num_oushu);
        // PrintVector(num_jishu);
        vector<int> ans(num_w.size(),0);
        int oushu_i = 0;
        int jishu_i = 0;
        for(int i = 0;i < num_w.size();i++){
            if(num_flag[i] == true){
                ans[i] = num_oushu[oushu_i++];
            }else{
                ans[i] = num_jishu[jishu_i++];
            }
        }
        // PrintVector(ans);
        int ans_num = 0;
        int ten_i = 0;
        for(int i = ans.size()-1;i >= 0;i--){
            ans_num += ans[i]*pow(10,ten_i);
            // printf("%d %d\n",ans[i],pow(10,ten_i));
            ten_i++;
        }
        return ans_num;
    }
};




	
int main() {
	Solution solution;
	int num = 247;
	
	auto ans = solution.largestInteger(num);
	
	cout << ans << endl;
	
	return 0;
}




