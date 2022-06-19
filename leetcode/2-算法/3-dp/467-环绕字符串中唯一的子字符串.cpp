#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

// 给定字符串s="abcdefghijklmnopqrstuvwxyzabcd..."
// 输入一个字符串 p，输出 p 的子串的数量，满足条件
// 1，子串同时是 s 的子串
// 2，重复的子串不计数
// 3，子串在 p 中是连续的
// 4，子串在 s 中是连续的
// 5，子串是非空的
// 注意：p 不是无限循环字符串的根
// 举例
// 输入 p="a"，p 的子串有 "", "a"
// 满足条件的子串的数量是 1
// 输入 p="cac"，p的子串有 "", "c", "a", "ca", "ac", "cac"
// 满足条件的子串的数量是 2，也就是说 "ca"、"ac"、"cac"不是 s 的子串
// 输入 p="zab"，p的子串有 "", "z", "a", "b", "za", "ab", "zab"
// 满足条件的子串的数量是 6，也就是说 "z", "a", "b", "za", "ab", "zab" 都是 s 的子串


class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        int ans = 0;
        int k = 0;
        vector<int> dp(26);
        for(int i = 0;i < n;i++){
            if(i && (p[i] - p[i-1] + 26)%26 == 1) {// 每次就判断，前后两个字符，是不是连续的
            // 向前ab是连续,ba也可以，同时abc可以，cba可以
                ++k;    // 只要是连续的，也就是在s里面，就可以当做是连续子串，统计数值自加 
            }
            else
                k = 1;  // 否则重置为1
            // printf("%d %c %c %d %d %d\n",k,p[i],p[i-1],abs(p[i] - p[i-1]),(p[i] - p[i-1] + 26)%26,p[i] - p[i-1]);
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'],k); // 不停的更新最大值
            printVector(dp);
        }
        return accumulate(dp.begin(),dp.end(),0);
    }
};




int main() {
	freopen("out.out","w",stdout);
	Solution solution;
	// string p = "zababa";
    // string p = "cac";
    string p = "zababababahytjncxcgrstr";
	
	auto ans = solution.findSubstringInWraproundString(p);
	cout << ans << endl;
	return 0;
}



