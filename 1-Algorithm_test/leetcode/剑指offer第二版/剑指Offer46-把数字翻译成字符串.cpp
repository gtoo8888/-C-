#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

// class Solution {
// public:
//     int translateNum(int num) {
// 		vector<int> vnums;
// 		while(num != 0){
// 			vnums.push_back(num%10);
// 			num /= 10;
// 		}
// 		vnums.push_back(0);	// 用数组记录的时候，需要放置一个占位符，不然下面和dp数组不匹配
// 		reverse(vnums.begin(),vnums.end());
// 		PrintVector(vnums);
// 		int n = vnums.size();
// 		if(n == 1)
// 			return 1;
// 		if(n == 2){
// 			if(10 <= vnums[0]*10+vnums[1] && vnums[0]*10+vnums[1] <= 25)
// 				return 2;
// 			else
// 				return 1;
// 		}
// 		vector<int> dp(n,0);
// 		dp[0] = dp[1] = 1;
// 		for(int i = 2;i < n;i++){
// 			printf("%d\n",vnums[i-1]*10+vnums[i]);
// 			if(10 <= vnums[i-1]*10+vnums[i] && vnums[i-1]*10+vnums[i] <= 25)			
// 				dp[i] = dp[i-1] + dp[i-2];
// 			else
// 				dp[i] = dp[i-1];
// 			// PrintVector(dp);
// 		}
// 		return dp[n-1];
//     }
// };




class Solution {
public:
    int translateNum(int num) {
		string str = to_string(num);
		str = '0' + str;
		// cout << str << endl;
		int n = str.size();
		vector<int> dp(n+1,0);
		dp[0] = dp[1] = 1;
		for(int i = 2;i < n;i++){
			int num1 = str[i-1]-'0';
			int num2 = str[i]-'0';
			// printf("%d\n",num1*10+num2);
			if(10 <= num1*10+num2 && num1*10+num2 <= 25)			
				dp[i] = dp[i-1] + dp[i-2];
			else
				dp[i] = dp[i-1];
			// PrintVector(dp);
		}
		return dp[n-1];
    }
};
		
int main() {
	Solution solution;
	// int num = -156756;
	// int num = 12258;
	// int num = 25;
	int num = 26;
	// int num = 40;
	// int num = 123;
	// int num = 2145;
	// int num = 123423;


	auto ans = solution.translateNum(num);

	cout << ans << endl;

	
	return 0;
}


