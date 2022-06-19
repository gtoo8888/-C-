#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


void PrintBit(int n) {
	string str;
    while(n != 0 ) {
        if(n & 1 == 1)  
            str.push_back('1');
        else   
            str.push_back('0');
        n >>= 1;
    }
	reverse(str.begin(),str.end());
	cout << str << endl;
    cout << endl;
}


class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
		int n = target.size();
		vector<int> dp(1 << n,0);	// 保存的是状态数
		queue<int> q;
		q.push(0);
		int step;
		while(!q.empty()){
			int begin = q.front();q.pop();	
			for(auto s : stickers){	//遍历整个贴纸集合
				int state = begin;
				// cout << s << endl;
				vector<int> cnt(26);	// 统计给定stickers，每个贴纸，包含了什么字母
				for(auto c : s){
					cnt[c - 'a']++;
				}
				// PrintVector(cnt);
				for(int i = 0;i < n;i++){	// 遍历目标数组
					// 如果目标数组有想要的贴纸的字 && 把目标的state这一位变成1
					if(cnt[target[i] - 'a'] && !(state & (1 << i))){
						state |= 1 << i;	// 把目标的state这一位变成1
						cnt[target[i] - 'a']--;	// 把用过的字母取消掉
					}
				}
				// PrintVector(cnt);
				if(dp[state] || state == 0)
					continue;
				q.push(state);
				dp[state] = dp[begin] + 1;
				// PrintVector(dp);
				// PrintBit(state);
				if(state == (1 << n) - 1)
					return dp[state];
			}
		}
		return -1;
    }
};


		
int main() {

	freopen("out.out","w",stdout);

	Solution solution;

	vector<string> stickers = {"with","example","science"};
	string target = "thehat";

	auto ans = solution.minStickers(stickers,target);
	
	cout << ans << endl;
	return 0;
}



