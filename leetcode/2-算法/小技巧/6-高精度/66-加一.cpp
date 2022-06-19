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


// 从前往后
// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits) {
//         reverse(digits.begin(),digits.end());
//         int n = digits.size();
//         int cnt = 0;
//         vector<int> ans(n);
//         cnt += digits[0] + 1;
//         ans[0] = cnt % 10;
//         cnt /= 10;
//         for(int i = 1;i < n;i++){
//             cnt += digits[i];
//             // printf("%d %d\n",cnt,digits[i]);
//             ans[i] = cnt % 10;
//             cnt /= 10;
//             // PrintVector(ans);
//         }
//         if(cnt)
//             ans.emplace_back(1);
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };


// 直接从后向前
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i = n-1;i >= 0;i--){    // 因为只是加1所以进位的话，必定变成10
            digits[i] = (digits[i] + 1) % 10;   // 如果进位的话，10%10必定是0
            if(digits[i])   // 如果余数是0表示进位了，不会返回，继续加，这一位出现非0,就直接可以返回了
                return digits;
        }
        vector<int> ans(n+1,0); // 如果全都循环下来没有返回成功，说明需要大进位
        ans[0] = 1;
        return ans;
    }
};


int main() {
	Solution solution;
    vector<int> digits = {2,4,5,9,9,9};

	auto ans = solution.plusOne(digits);
	
	PrintVector(ans);	
	return 0;
}



