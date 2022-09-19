#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

void printMap(unordered_map<int,int> m) {
	for(auto it = m.begin();it != m.end();it++)
		cout << (*it).first << " " << it->second << endl;
	cout << endl;	
}

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
// 		unordered_map<int,int> map1;
// 		for(int i = 0;i < nums1.size();i++) {
// 			map1[nums1[i]]++;
// 		}
// //		printMap(map1);
// 		vector<int> ans;
// 		for(int i = 0;i < nums2.size();i++) {
// 			if(map1.find( nums2[i] ) != map1.end()) {
// 				ans.push_back( nums2[i] );
// 				map1[nums2[i]]--;
// 				if(map1[nums2[i]] == 0)
// 					map1.erase(nums2[i]);
// 			}
// 		}
// //		printMap(map1);
// 		return ans;
//     }
// };


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		int hash_map[2000] = {0};	// 没有赋初值会出问题
		// vector<int> hash_map(2000);
		for(int i = 0;i < nums1.size();i++) {
			hash_map[nums1[i]]++;
		}
		vector<int> ans;
		for(int i = 0;i < nums2.size();i++) {
			if(hash_map[nums2[i]] != 0){
				ans.push_back(nums2[i]);
				hash_map[nums2[i]]--;
			}
		}
		return ans;
    }
};


int main() {
	Solution solution;
	vector<int> nums1 = {4,9,5}; 
	vector<int> nums2 = {9,4,9,8,4}; 
	// vector<int> nums1 = {1}; 
	// vector<int> nums2 = {1,1}; 

	auto ans = solution.intersect(nums1,nums2);
	
	printVector(ans);

	return 0;
}


