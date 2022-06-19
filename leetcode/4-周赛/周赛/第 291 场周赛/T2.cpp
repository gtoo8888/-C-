//#include <iostream>
//#include <vector>
//#include <algorithm>
//// #include <string>
//#include <unordered_map>
//#include <stdio.h>
//#include <string.h>
#include<bits/stdc++.h>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
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




// 超时的方法
// class Solution {
// public:
//     int minimumCardPickup(vector<int>& cards) {
//         unordered_map<int,int> map;
//         for(auto c : cards){
//             map[c]++;
//         }
//         // PrintMap(map);
//         vector<int> chongfu;
//         for(auto m : map){
//             int fi = m.first;
//             int se = m.second;
//             if(se != 1)
//                 chongfu.push_back(fi);
//         }
//         if(chongfu.empty())
//             return -1;
//         PrintVector(chongfu);
//         int ans = INT32_MAX;
//         for(int j = 0;j < chongfu.size();j++){
//             vector<int> tmp;
//             for(int i = 0;i < cards.size();i++){
//                 if(chongfu[j] == cards[i])
//                     tmp.push_back(i);
//             }
//             for(int i = 1;i < tmp.size();i++){
//                 int tmp1 = tmp[i] - tmp[i-1] + 1;
//                 if(tmp1 < ans)
//                     ans = tmp1;
//             }
//             // PrintVector(tmp);
//         }
//         return ans;
//     }
// };


// void PrintMap(unordered_map<int,vector<int>> m) {
// 	for(auto it : m){
//         vector<int> tmp = it.second;
// 		printf("%d ",it.first);
//         PrintVector(tmp);
//     }
// 	cout << endl;	
// }

// map + vector实现
// O(n2)
// class Solution {
// public:
//     int minimumCardPickup(vector<int>& cards) {
//         unordered_map<int,vector<int>> map;
//         int n = cards.size();
//         for(int i = 0;i < n;i++){
//             map[cards[i]].push_back(i);
//         }
//         PrintMap(map);
//         int ans = INT32_MAX;
//         for(auto m : map){
//             int fi = m.first;
//             vector<int> se = m.second;
//             if(se.size() > 1){
//                 for(int i = 1;i < se.size();i++){
//                     int dis = se[i] - se[i-1] + 1;
//                     ans = min(dis,ans);
//                 }
//             }      
//         }
//         return (ans != INT32_MAX) ? ans : -1;
//     }
// };

void PrintMap(unordered_map<int,int> m) {
	for(auto it : m)
		printf("%d %d\n",it.first,it.second);
	cout << endl;	
}

// map实现，不停更新下标
// O(n)
//  class Solution {
//  public:
//      int minimumCardPickup(vector<int>& cards) {
//          unordered_map<int,int> map;
//          int n = cards.size();
//          int ans = INT32_MAX;
//          for(int i = 0;i < n;i++){   // 每次哈希表就保存一个下标
//              if(map.count(cards[i]))     // 如果再次遇到了这个元素
//                  ans = min(ans,i - map[cards[i]] + 1);   // 那么就计算这个距离
//              map[cards[i]] = i;      // 每次下标会被刷新
//          }
//           PrintMap(map);
//          return (ans != INT32_MAX) ? ans : -1;
//      }
//  };


// 根据题目的数据范围，直接建立了一个数组的hash表，不用STL创建，更快了
// O(n)
class Solution {
public:
   int minimumCardPickup(vector<int>& cards) {
        cout << "!!!" <<endl; 
        int n = cards.size();
        int hash[1000010];
        memset(hash,-1,sizeof(hash));
        int ans = INT32_MAX;
        for(int i = 0;i < n;i++){  
            if(hash[cards[i]] != -1)     // 如果再次遇到了这个元素
                ans = min(ans,i - hash[cards[i]] + 1);   // 那么就计算这个距离
            hash[cards[i]] = i;      // 每次下标会被刷新
        }
        return (ans != INT32_MAX) ? ans : -1;
   }
};
	
int main() {
	Solution solution;
    // vector<int> cards = {3,4,2,3,4,7,6,9,3};
    // vector<int> cards = {1,0,5,3};
    vector<int> cards = {3,4,2,3,4,7};
    

    auto ans = solution.minimumCardPickup(cards);

	cout << ans << endl;
	return 0;
}




