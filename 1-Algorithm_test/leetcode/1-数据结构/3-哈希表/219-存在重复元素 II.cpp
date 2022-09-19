#include <iostream>
#include <vector>
#include <unordered_map> 
using namespace std;


void printBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

void PrintMap(unordered_map<int,int> m) {
	for(auto it = m.begin();it != m.end();it++)
		cout << (*it).first << " " << it->second << endl;
	cout << endl;	
}

//class Solution {//暴力超过时间限制 
//public:
//    bool containsNearbyDuplicate(vector<int>& nums, int k) {
//    	unordered_multimap<int,int> mm;
//		for(int i = 0;i < nums.size();i++) {
//			for(int j = i+1;j < nums.size();j++) {
//				if(nums[i] == nums[j])
//					mm.insert(pair<int,int>(i,j));
//			}
//		}
////		PrintMap(mm);
//		int min_ans = INT32_MAX;
//		for(unordered_multimap<int,int>::iterator it = mm.begin();it != mm.end();it++) {
//			int temp = abs(it->first - it->second);//求出相差的值 
//			min_ans = temp < min_ans ? temp : min_ans;
//		}
//		if(min_ans > k)
//			return false;
//		else
//			return true;
//    }
//};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    	unordered_map<int,int> mm;//key是数值，val是下标 
		for(int i = 0;i < nums.size();i++) {
//			PrintMap(mm);
			if(mm.find(nums[i]) != mm.end() && abs(i - mm[nums[i]]) <= k)
				return true;//找到后不需要保存哪个差值最少，只要找到，就可以退出了 
			mm[nums[i]] = i;//不断的找，因为前面找过都没有找到相似的值，所以就直接更新了
			//是没找到才更新的数值 
		} 
		return false;
    }
};


int main() {
	Solution solution;
	vector<int> nums = {0,1,2,3,4,0,0,7,8,9,10,11,12,0};
	int k = 1;
	bool ans;
	
	ans = solution.containsNearbyDuplicate(nums,k);

	printBool(ans);

	return 0;
}



