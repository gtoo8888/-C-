#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// class Solution {
// public:
//     int garbageCollection(vector<string>& garbage, vector<int>& travel) {
// 		int Gall = 0,Pall = 0,Hall = 0;
// 		int Gnum = 0,Pnum = 0,Hnum = 0;
// 		int n = garbage.size();
// 		for(int i = 0;i < n;i++){
// 			string str_cost = garbage[i];
// 			int Gcost = 0,Pcost = 0,HCost = 0;
// 			for(int j = 0;j < str_cost.size();j++){
// 				if(str_cost[j] == 'G')
// 					Gcost++,Gnum++;
// 				else if(str_cost[j] == 'H')
// 					HCost++,Hnum++;
// 				else if(str_cost[j] == 'P')
// 					Pcost++,Pnum++;
// 			}
// 			if(i < n-1){
// 				Gall += Gcost + travel[i];
// 				Pall += Pcost + travel[i];
// 				Hall += HCost + travel[i];
// 			}else{
// 				Gall += Gcost ;
// 				Pall += Pcost ;
// 				Hall += HCost ;		
// 			}
// 		}
// 		return -1;     
//     }
// };


class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
		int Glast = 0,Plast = 0,Mlast = 0;
		int n = garbage.size();
		int ans = 0;
		for(int i = 0;i < n;i++){
			string str_cost = garbage[i];
			int len = str_cost.size();
			ans += len;
			for(int j = 0;j < len;j++){
				if(str_cost[j] == 'G')
					Glast = i;
				else if(str_cost[j] == 'M')
					Mlast = i;
				else if(str_cost[j] == 'P')
					Plast = i;
			}		
		}
		for(int i = 0;i < travel.size();i++){
			if(i < Glast)
				ans += travel[i];
			if(i < Plast)
				ans += travel[i];
			if(i < Mlast)
				ans += travel[i];
		}
		return ans;     
    }
};

int main() {
	Solution solution;
	// vector<string> garbage = {"G","P","GP","GG"};
	// vector<int> travel = {2,4,3};

	vector<string> garbage = {"MMM","PGM","GP"};
	vector<int> travel = {3,10};
    auto ans = solution.garbageCollection(garbage,travel);

	cout << ans << endl;
	return 0;
}




