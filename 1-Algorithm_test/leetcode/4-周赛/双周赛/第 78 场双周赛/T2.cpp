#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

void PrintVector(vector<long long> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintVSector(vector<string> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << endl;
	cout << endl; 
}

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

void PrintVVector(vector<vector<int>> v){
	for(auto iter = v.begin();iter != v.end();iter++){
		auto it_temp = *iter;
		for(auto it = it_temp.begin();it != it_temp.end();it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}

void PrintSMap(unordered_map<string,int> m) {
	for(auto it = m.begin();it != m.end();it++)
		cout << (*it).first << " " << it->second << endl;
	cout << endl;	
}


class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
		int n = nums.size();
        vector<long long > pre(n+1);
		vector<long long > behen(n+1);
        for(int i = 0;i < n;i++) 
            pre[i+1] = pre[i] + nums[i];
		for(int i = n-1;i >= 0;i--) 
            behen[i] = behen[i+1] + nums[i];
		PrintVector(pre);
		PrintVector(behen);
		int ans = 0;
		for(int i = 0;i < n-1;i++){
			long long  qian = pre[i+1] - pre[0];
			long long  hou = behen[i+1] - behen[n];
			// for(int j = i+1;j < n;j++){
			// 	hou += nums[j];
			// }
			// printf("%d %d\n",qian,hou);
			if(qian >= hou)
				ans++;
		}
		return ans;
    }
};



	
int main() {
	Solution solution;
	// vector<int> num = {2,3,1,0};
    vector<int> num = {10,4,-8,7};
	// vector<int> num = {10,4,-8,7,12,3,45,6,7,7,8};
	// vector<int> num = {0,0,0,0,0,0};

    auto ans = solution.waysToSplitArray(num);

	cout << ans << endl;
	return 0;
}




