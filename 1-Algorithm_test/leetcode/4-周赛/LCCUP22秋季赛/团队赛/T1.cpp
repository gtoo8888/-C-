#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"



class Solution {
public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
		int n = temperatureA.size();
		vector<int> tendA(n-1);
		vector<int> tendB(n-1);
		for(int i = 0;i < n-1;i++){
			if(temperatureA[i] < temperatureA[i+1])
				tendA[i] = 1;
			else if(temperatureA[i] > temperatureA[i+1]){
				tendA[i] = -1;
			}else{
				tendA[i] = 0;
			}

			if(temperatureB[i] < temperatureB[i+1])
				tendB[i] = 1;
			else if(temperatureB[i] > temperatureB[i+1]){
				tendB[i] = -1;
			}else{
				tendB[i] = 0;
			}
		}
		// PrintVector(tendA);
		// PrintVector(tendB);
		// int ans = 0;
		// if(tendA[0] == tendB[0])
		// 	ans++;
		// if(tendA[1] != tendB[1])
		// 	ans = 0;
		// for(int i = 1;i < n-1;i++){
		// 	if(tendA[i] == tendB[i]){
		// 		ans++;
		// 	}else{
		// 		if(tendA[i-1] != tendB[i-1])
		// 			ans = 0;
		// 	}
		// }
		int n2 = tendA.size();
		vector<bool> tendBool(n2,0);
		for(int i = 0;i < n2;i++){
			if(tendA[i] == tendB[i]){
				tendBool[i] = true;
			}else{
				tendBool[i] = false;
			}
		}
		// tendBool = vector<bool>{1,1,0,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1};
		// PrintVBector(tendBool);
		int len = 0;
		int l = 0,r = 0;
		int ans = 0;
		while(r < tendBool.size()){
			if(tendBool[r] == true){
				len++;
				r++;
			}else{
				r++;
				len = 0;
				l = r;
			}
			ans = max(len,ans);
		}
		return ans;
    }
};
	
int main() {
	Solution solution;
	vector<int> temperatureA = {5,10,16,-6,15,11,3};
	vector<int> temperatureB = {16,22,23,23,25,3,-16};

	auto ans = solution.temperatureTrend(temperatureA,temperatureB);
	
	cout << ans << endl;
	
	return 0;
}



