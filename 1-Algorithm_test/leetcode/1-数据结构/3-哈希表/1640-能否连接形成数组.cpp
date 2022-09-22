#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
		unordered_map<int,int> index;
		for(int i = 0;i < pieces.size();i++){
			index[pieces[i][0]] = i;
		}
		for(int i = 0;i < arr.size();i++){
			auto it = index.find(arr[i]);
			if(it == index.end()){	// 如果数组还没有读完，就已经找不到这个字字符了，说明有问题
				return false;
			}
			for(int j = 0;j < pieces[index[arr[i]]].size();j++){	// 如果读取到了，就把这数字读完
				printf("%d %d %d\n",arr[i],pieces[index[arr[i]]][j],j);
				if(arr[i] != pieces[index[arr[i]]][j]){
					return false;
				}
				i++;
				// if(i == arr.size())
				// 	break;
			}
		}
		return true;
    }
};

int main() {
	Solution solution;
	// vector<int> arr = {15,88}; 
	// vector<vector<int>> pieces = {{88},{15}}; 

	// vector<int> arr = {49,18,16}; 
	// vector<vector<int>> pieces = {{16,18,49}}; 

	vector<int> arr = {91,4,64,78}; 
	vector<vector<int>> pieces =  {{78},{4,64},{91}}; 
	auto ans = solution.canFormArray(arr,pieces);
	
	PrintBool(ans);
	return 0;
}


