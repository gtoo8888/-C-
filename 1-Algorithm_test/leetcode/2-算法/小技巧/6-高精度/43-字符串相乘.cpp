#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


// ¼ò»¯µÄÄ£Äâ
// class Solution {
// public:
//     string addBinary(string a, string b) {
//         reverse(a.begin(),a.end());
//         reverse(b.begin(),b.end());
//         cout << a << endl;
//         cout << b << endl;
//         int n = max(a.size(),b.size());
//         int cnt = 0;
//         string ans(n,'%');
//         for(int i = 0;i < n;i++){
//             if(i < a.size())
//                 cnt += (a[i] == '1');
//             if(i < b.size())
//                 cnt += (b[i] == '1');
//             printf("%d \n",cnt);
//             ans[i] = (cnt%2) + '0';
//             cnt /= 2;
//             cout << ans << endl;
//         }
//         if(cnt)
//             ans.push_back('1');
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };


class Solution {
public:
    string addStrings(string num1, string num2) {
        // reverse(num1.begin(),num1.end());
        // reverse(num2.begin(),num2.end());
        int n = max(num1.size(),num2.size());
        int cnt = 0;
        string ans(n,'%');
        for(int i = 0;i < n;i++){
            if(i < num1.size())
                cnt += num1[i] - '0';
            if(i < num2.size())
                cnt += num2[i] - '0';
            ans[i] = (cnt % 10) + '0';
            cnt /= 10;
        }
        if(cnt)
            ans.push_back('1');
        // reverse(ans.begin(),ans.end());
        return ans;
    }

    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());  
        int n1 = num1.size();
        int n2 = num2.size();
        if(n2 > n1){
            n1 = num2.size();
            n2 = num1.size();
            string num_tmp = num1;
            num1 = num2;
            num2 = num_tmp;
        }

        int cnt = 0; 
        string ans(1,'0');
        for(int i = 0;i < n2;i++){
            string ans_tmp(n1,'%');
            int tmp1 = num2[i]-'0';
            for(int j = 0;j < n1;j++){
                int tmp2 = num1[j]-'0' ;
                cnt += tmp1 * tmp2 ;
                // printf("%d %d %d\n",cnt,tmp1,tmp2);
                ans_tmp[j] = (cnt%10) + '0';
                cnt /= 10;
                // cout << ans_tmp << endl;
            }
            string ans_t(i,'0');
            ans_tmp = ans_t + ans_tmp;
            if(cnt)
                ans_tmp.push_back(cnt + '0');
            cnt = 0;
            // cout << ans_tmp << endl;
            ans = addStrings(ans,ans_tmp);
            // cout << ans << endl;
            // cout << endl;
        }
        if(cnt)
            ans.push_back(cnt + '0');
        reverse(ans.begin(),ans.end());  
        return ans;
    }
};


int main() {
	Solution solution;
    // string a = "1010";
    // string b = "1011";

    string num1 = "999";
    string num2 =   "999";
	
	auto ans = solution.multiply(num1,num2);
	
	cout << ans << endl;
	
	return 0;
}



