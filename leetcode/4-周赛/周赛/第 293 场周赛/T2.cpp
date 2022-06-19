#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;


void PrintVector(vector<int> v){for(auto it : v) cout << it << " ";cout << endl;}
void PrintVSector(vector<string> v){for(auto it : v)cout << it << endl;cout << endl;}
void PrintVVector(vector<vector<int>>& v){for(auto iter : v){auto it_tmp = iter;for(auto it : it_tmp)cout << it << " ";cout << endl;}cout << endl;}
void PrintBool(bool val){if(val == true)cout << "true" << endl;else cout << "false" << endl;cout << endl;}
void PrintMap(unordered_map<int,int> m) {for(auto it : m)printf("%d %d\n",it.first,it.second);cout << endl;}

void printarrary(int a[]){
	for(int i = 0;i < 26;i++)
		printf("%d ",a[i]);
}

void PrintSet(set<int> s) {
	for(auto it : s)
		printf("%d ",it);
	cout << endl;	
}

// class Solution {
// public:
//     int maxConsecutive(int bottom, int top, vector<int>& special) {
//         int l = bottom,r = bottom;
// 		set<int> hash_set;
// 		for(auto s : special)
// 			hash_set.insert(s);
// 		// PrintSet(hash_set);
// 		int ans = 0;
// 		while(r <= top){
// 			if(hash_set.find(r) != hash_set.end()){
// 				l = r;
// 				l++;
// 			}
// 			r++;	
// 			int len = r - l;
// 			// printf("%d %d %d\n",l,r,len);
// 			ans = len > ans ? len : ans;
// 		}
// 		return ans;
//     }
// };


// class Solution {
// public:
//     int maxConsecutive(int bottom, int top, vector<int>& special) {
//         int l = bottom,r = bottom;
// 		sort(special.begin(),special.end());
// 		int n = special.size();
// 		int ans = 0;
// 		int i = 0;
// 		while(r <= top){
// 			if(i < n && r == special[i]){
// 				l = r;
// 				l++;
// 				i++;
// 			}
// 			r++;	
// 			int len = r - l;
// 			printf("%d %d %d %d\n",l,r,len,i);
// 			ans = len > ans ? len : ans;
// 		}
// 		return ans;
//     }
// };

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
		sort(special.begin(),special.end());
		int n = special.size();
		int ans = 0;
		for(int i = 0;i < n-1;i++){
			int len = special[i+1] - special[i] - 1;
			printf("%d\n",len);
			ans = len > ans ? len : ans;
		}
		int kai = special[0] - bottom;
		int wei = top - special[n-1];
		printf("%d %d\n",kai,wei);
		ans = kai > ans ? kai : ans;
		ans = wei > ans ? wei : ans;
		return ans;
    }
};
	
int main() {
	Solution solution;
    // string num = "2300019";
	// vector<int> num = {1,2,3,4,5};
	// vector<string> words = {"abba","baba","bbaa","cd","cd"};
	// vector<string> words = {"a","b","c","d","e"};
	// vector<string> words = {"abbb","aaab"};
	int bottom = 2,top = 9;
	vector<int> special = {4,6};
	// int bottom = 3,top = 15;
	// vector<int> special = {7,9,13};
	// int bottom = 6,top = 8;
	// vector<int> special = {7,6,8};
	// PrintVSector(words);

    auto ans = solution.maxConsecutive(bottom,top,special);

	cout << ans << endl;
	return 0;
}




