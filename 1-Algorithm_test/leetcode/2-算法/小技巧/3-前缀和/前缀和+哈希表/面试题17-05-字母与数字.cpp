#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int n = array.size();
        vector<int> zero_one(n,0);
        for(int i = 0;i < n;i++){
            if(array[i][0] >= '0' && array[i][0] <= '9'){
                zero_one[i] = -1;
            }else
                zero_one[i] = 1;
        }
        vector<int> pre(n+1,0);
        for(int i = 0;i < n;i++){
            pre[i+1] = pre[i] + zero_one[i];
        }
        // PrintVector(zero_one);
        // PrintVector(pre);
        int left = 0,right = 0;
        unordered_map<int,int> map;
        for(int i = 0;i <= n;i++){
            auto it = map.find(pre[i]);
            if(it == map.end())
                map[pre[i]] = i;
            else if((i - it->second )> (right - left)){
                left = it->second;
                right = i;
            }
        }
        return {array.begin()+left,array.begin()+right};
    }
};


int main() {
	Solution solution;
	// vector<string> array = {"A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"};
    vector<string> array = {"A","1"};

	
	auto ans = solution.findLongestSubarray(array);
	
	PrintVector(ans);
	
	return 0;
}



