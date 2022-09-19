#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n+1);
        for(int i = 0;i < n;i++) 
            pre[i+1] = pre[i] + arr[i];
        // PrintVector(pre);
        int ans = 0;
        // for(int start = 0;start < n;start++){    //对每个点的长度都遍历一下
        //     for(int len = 1;start + len <= n;len += 2){
        //         int end = start + len - 1;
        //         ans += pre[end+1] - pre[start];
        //         printf("%d %d\n",start,len);
        //         printf("ans:%d %d %d\n",ans,pre[end+1],pre[start]);
        //     }
        // }
        for(int len = 1;len <= n;len+=2){           //把每个长度比如1,3,5依次先遍历完
            for(int start = 0;start + len <= n;start++){
                int end = start + len - 1;
                ans += pre[end+1] - pre[start];
                // printf("%d %d\n",start,len);
                // printf("ans:%d %d %d\n",ans,pre[end+1],pre[start]);
            }
        }
        return ans;
    }
};


int main() {
	Solution solution;
	vector<int> arr = {10,11,12};
	
	auto ans = solution.sumOddLengthSubarrays(arr);
	
	cout << ans << endl;
	
	return 0;
}



