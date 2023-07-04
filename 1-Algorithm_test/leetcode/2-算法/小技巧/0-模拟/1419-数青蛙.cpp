#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char,char> pre_map = {{'c','k'},{'r','c'},{'o','r'},{'a','o'},{'k','a'}};
        vector<int> cnt('s',0);
        for(auto c : croakOfFrogs){
            char pre = pre_map[c];
            if(cnt[pre])
                cnt[pre]--; // 遇到后面一个，就会把前面一个字符消掉
            else if(c != 'c')
                return -1;
            cnt[c]++;
            // printf("c[%d] r[%d] o[%d] a[%d] k[%d]\n",cnt['c'],cnt['r'],cnt['o'],cnt['a'],cnt['k']);
        }
        if(cnt['c'] || cnt['r'] || cnt['o'] || cnt['a'])
            return -1;
        return cnt['k'];
    }
};

	
int main() {
	Solution solution;
	string croakOfFrogs = "croakcroak";

	auto ans = solution.minNumberOfFrogs(croakOfFrogs);
	
	cout << ans << endl;
	
	return 0;
}



