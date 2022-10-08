#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"


class Solution {
public:
    int transportationHub(vector<vector<int>>& path) {
		// PrintVVector(path);
		int n = path.size();
		vector<int> chudu;
		vector<int> rudu;
		for(auto vec : path){
			chudu.emplace_back(vec[0]);
			rudu.emplace_back(vec[1]);
		}
		// PrintVector(chudu);
		// PrintVector(rudu);
		// int hash[1010] = {0};
		map<int,int> hash_chudu;
		map<int,int> hash_rudu;
		map<int,int> nums;
		for(int i = 0;i < chudu.size();i++){
			hash_rudu[rudu[i]]++;
			hash_chudu[chudu[i]]++;

			nums[chudu[i]]++;
			nums[rudu[i]]++;
		}
		// PrintMap(hash_rudu);
		// PrintMap(hash_chudu);
		// PrintMap(nums);
		// cout << nums.size() << endl;
		vector<int> shuniu;
		for(auto it : hash_rudu){
			if(it.second == nums.size()-1){
				shuniu.push_back(it.first);
				break;
			}
		}
		// PrintVector(shuniu);
		for(int i = 0;i < shuniu.size();i++){
			if(hash_chudu.find(shuniu[i]) != hash_chudu.end()){
				break;
			}else{
				return shuniu[i];
			}
		}
		return -1;
    }
};


int main() {
	Solution solution;
	// vector<vector<int>> path =  {{0,1},{0,3},{1,3},{2,0},{2,3}}	;
	vector<vector<int>> path =  {{0,3},{1,0},{1,3},{2,0},{3,0},{3,2}};

	auto ans = solution.transportationHub(path);
	
	cout << ans << endl;
	
	return 0;
}



