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

class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int n = max(num1.size(),num2.size());
        int cnt = 0;
        string ans(n,'%');
        for(int i = 0;i < n;i++){
            if(i < num1.size())
                cnt += num1[i] - '0';
            if(i < num2.size())
                cnt += num2[i] - '0';
            // printf("%d \n",cnt);
            ans[i] = (cnt % 10) + '0';
            cnt /= 10;
            // cout << ans << endl;
        }
        if(cnt)
            ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
	Solution solution;
    // string a = "1010";
    // string b = "1011";

    string num1 = "1234";
    string num2 =  "567";
	
	auto ans = solution.addStrings(num1,num2);
	
	cout << ans << endl;
	
	return 0;
}



