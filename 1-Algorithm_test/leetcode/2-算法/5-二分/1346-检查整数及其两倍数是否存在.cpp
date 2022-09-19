#include <algorithm> 
#include <iostream>
#include <vector>
#include <map>
using namespace std;


void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

// 二分查找
// class Solution {
// public:
//     bool checkIfExist(vector<int>& arr) {
// 		sort(arr.begin(),arr.end());
// 		// PrintVector(arr);
// 		int n = arr.size();
// 		bool flag_find = false;
// 		for(int i = 0;i < n;i++){
// 			int l = 0,mid,r = n-1;
// 			while(l <= r){
// 				mid = l + (r -l)/2;
// 				// printf("%d %d %d %d %d\n",arr[mid],arr[i] * 2,l,mid,r);
// 				if(arr[mid] == arr[i] * 2 && mid != i){
// 					flag_find = true;
// 					break;
// 				}
// 				else if(arr[mid] < arr[i] * 2)
// 					l = mid + 1;
// 				else
// 					r = mid - 1;
// 			}
// 			// printf("\n");
// 			if(flag_find)
// 				break;
// 		}
// 		return flag_find;
//     }
// };


// void PrintSet(set<int> s) {
// 	// for(set<int>::iterator it = s.begin();it != s.end();it++)
// 	// 	printf("%d ",*it);
// 	for(auto it : s)
// 		printf("%d ",it);
// 	cout << endl;	
// }

void PrintMap(map<int,int> s) {
	// for(set<int>::iterator it = s.begin();it != s.end();it++)
	// 	printf("%d ",*it);
	for(auto it : s)
		printf("%d %d\n",it.first,it.second);
	cout << endl;	
}

// hash表存储
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
		int n = arr.size();
		map<int,int> m;
		for(auto a : arr){
			m[a]++;
		}
		// PrintMap(m);
		int find_flag = false;
		for(int i = 0;i < n;i++){
			if(arr[i] != 0 && m.find(arr[i]*2) != m.end()){
				find_flag = true;
				break;
			}else if(arr[i] == 0 && m[0] > 1){
				find_flag = true;
				break;
			}
		}
		return find_flag;
    }
};


int main(){
	Solution sol;
	// vector<int> arr = {10,2,5,3};
	// vector<int> arr = {7,1,14,11};
	// vector<int> arr = {3,1,7,11};
	// vector<int> arr = {-2,0,10,-19,4,6,-8};
	vector<int> arr = {-2,0,0,10,-19,4,6,-8};
	
	auto ans = sol.checkIfExist(arr);
	
	PrintBool(ans);
	return 0;
}
