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
		vector<int> dp(1 << n,0);	// �������״̬��
		queue<int> q;
		q.push(0);
		int step;
		while(!q.empty()){
			int begin = q.front();q.pop();	
			for(auto s : stickers){	//����������ֽ����
				int state = begin;
				// cout << s << endl;
				vector<int> cnt(26);	// ͳ�Ƹ���stickers��ÿ����ֽ��������ʲô��ĸ
				for(auto c : s){
					cnt[c - 'a']++;
				}
				// PrintVector(cnt);
				for(int i = 0;i < n;i++){	// ����Ŀ������
					// ���Ŀ����������Ҫ����ֽ���� && ��Ŀ���state��һλ���1
					if(cnt[target[i] - 'a'] && !(state & (1 << i))){
						state |= 1 << i;	// ��Ŀ���state��һλ���1
						cnt[target[i] - 'a']--;	// ���ù�����ĸȡ����
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



