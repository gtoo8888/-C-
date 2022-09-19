#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

void PrintVector(vector<int> v){
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


// bool cmp (vector<int> a,vector<int> b) { 
// 	return (a[0]<b[0]); 
// }
// class Solution {
// public:
//     int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
//         sort(tiles.begin(),tiles.end(),cmp);
// 			PrintVVector(tiles);
// 		int n = tiles.size();
// 		vector<vector<int>> tmp;
// 		for(int i = 0;i < n-1;i++){
// 			if(tiles[i][1] + 1 ==  tiles[i+1][0]){
// 				tmp.push_back({tiles[i][0],tiles[i+1][1]});
// 				i += 2;
// 			}
// 			tmp.push_back({tiles[i][0],tiles[i][1]});
// 		}
// 		tmp.push_back({tiles[n-1][0],tiles[n-1][1]});
// 		PrintVVector(tmp);
// 		int n1 = tmp.size();
// 		int ans = 0;
// 		for(int i = 0;i < n1;i++){
// 			int len = tmp[i][1] - tmp[i][0] + 1;
// 			printf("%d %d %d\n",len,ans,carpetLen);
// 			if(len < carpetLen){
// 				// ans += len;
// 				// carpetLen -= len;
// 				ans = len > ans ? len : ans;
// 			}
// 			else
// 				ans = carpetLen > ans ? carpetLen : ans;
// 		}
// 		return ans;
//     }
// };




bool cmp (vector<int> a,vector<int> b) { 
	return (a[0]<b[0]); 
}
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(),tiles.end(),cmp);
			PrintVVector(tiles);
		int n = tiles.size();
		vector<int> tmp;
		for(int i = 0;i < n-1;i++){
			if(tiles[i][1] + 1 ==  tiles[i+1][0]){
				tmp.push_back(tiles[i+1][1] - tiles[i][0] + 1);
				i += 2;
			}
			tmp.push_back(tiles[i][1] - tiles[i][0] + 1);
		}
		tmp.push_back(tiles[n-1][1] - tiles[n-1][0] + 1);
		PrintVector(tmp);
		sort(tmp.begin(),tmp.end());
		PrintVector(tmp);
		int n1 = tmp.size();
		int sum = 0;
		int ans = 0;
		for(int i = 0;i < n1;i++){
			ans = tmp[i] > ans ? tmp[i] : ans;
			sum += tmp[i];
		}
		if(carpetLen > sum)
			ans = sum;
		// int ans = 0;
		// for(int i = 0;i < n1;i++){
		// 	int len = tmp[i][1] - tmp[i][0] + 1;
		// 	printf("%d %d %d\n",len,ans,carpetLen);
		// 	if(len < carpetLen){
		// 		// ans += len;
		// 		// carpetLen -= len;
		// 		ans = len > ans ? len : ans;
		// 	}
		// 	else
		// 		ans = carpetLen > ans ? carpetLen : ans;
		// }
		return ans;
    }
};


	
int main() {
	Solution solution;
	// vector<vector<int>> tiles = {{1,5},{10,11},{12,18},{20,25},{30,32}} ;
	// vector<vector<int>> tiles = {{10,11},{1,1}};
	// vector<vector<int>> tiles = {{1,5},{10,11},{12,18},{20,25},{30,32}};
	// vector<vector<int>> tiles = {{8051,8057},{8074,8089},{7994,7995},{7969,7987},{8013,8020},{8123,8139},{7930,7950},{8096,8104},{7917,7925},{8027,8035},{8003,8011}};
	vector<vector<int>> tiles = {{3745,3757},{3663,3681},{3593,3605},{3890,3903},{3529,3539},{3684,3686},{3023,3026},{2551,2569},{3776,3789},{3243,3256},{3477,3497},{2650,2654},{2264,2266},{2582,2599},{2846,2863},{2346,2364},{3839,3842},{3926,3935},{2995,3012},{3152,3167},{4133,4134},{4048,4058},{3719,3730},{2498,2510},{2277,2295},{4117,4128},{3043,3054},{3394,3402},{3921,3924},{3500,3514},{2789,2808},{3291,3294},{2873,2881},{2760,2760},{3349,3362},{2888,2899},{3802,3822},{3540,3542},{3128,3142},{2617,2632},{3979,3994},{2780,2781},{3213,3233},{3099,3113},{3646,3651},{3956,3963},{2674,2691},{3860,3873},{3363,3370},{2727,2737},{2453,2471},{4011,4031},{3566,3577},{2705,2707},{3560,3565},{3454,3456},{3655,3660},{4100,4103},{2382,2382},{4032,4033},{2518,2531},{2739,2749},{3067,3079},{4068,4074},{2297,2312},{2489,2490},{2954,2974},{2400,2418},{3271,3272},{3628,3632},{3372,3377},{2920,2940},{3315,3330},{3417,3435},{4146,4156},{2324,2340},{2426,2435},{2373,2376},{3621,3626},{2826,2832},{3937,3949},{3178,3195},{4081,4082},{4092,4098},{3688,3698}};
	int carpetLen = 1638;
	// PrintVVector(tiles);

    auto ans = solution.maximumWhiteTiles(tiles,carpetLen);

	cout << ans << endl;
	return 0;
}




