#include <algorithm> 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintVPector(vector<pair<int,int>> v){
	for(auto it : v)
		printf("%d %d\n",it.first,it.second);
	cout << endl; 
}

void PrintVVector(vector<vector<int>>& v){
	for(auto iter : v){
		auto it_tmp = iter;
		for(auto it : it_tmp)
			cout << it << " ";
		cout << endl;
	}
	cout << endl;
}


// 二分+排序
bool cmp(pair<int,int> i,pair<int,int> j) { 
	if(i.second != j.second)	// 如果军人数目不同，那就按军人数目排序
		return (i.second < j.second); 
	else						// 如果军人数目相同，就数量小的放在前面
		return (i.first < j.first); 
}
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		int n = mat.size();
		vector<pair<int,int>> v;
		int i = 0;
		for(auto mcol : mat){
			int m = mcol.size();
			int l = 0,mid,r = m;
			while(l < r){
				mid = l + (r - l)/2;
				// printf("%d %d %d %d\n",mcol[mid],l,mid,r);
				if(mcol[mid] >= 1){
					l = mid + 1;
				}else	
					r = mid;
			}
			// printf("%d\n",l);
			v.push_back({i,l});
			i++;
		}
		PrintVPector(v);
		sort(v.begin(),v.end(),cmp);	// 用仿函数排序
		PrintVPector(v);
		vector<int> ans(k);
		for(int j = 0;j < k;j++){
			ans[j] = v[j].first;
		}
		return ans;
    }
};



// 二分+小根堆排序
// void PrintVPector(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q){
// 	while(!q.empty()){
//         printf("%d %d\n",q.top().first,q.top().second);
//         q.pop();
//     }
// 	cout << endl; 
// }
// class Solution {
// public:
//     vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
// 		int n = mat.size();
// 		vector<pair<int,int>> v;
// 		int i = 0;
// 		for(auto mcol : mat){
// 			int m = mcol.size();
// 			int l = 0,mid,r = m;
// 			while(l < r){
// 				mid = l + (r - l)/2;
// 				// printf("%d %d %d %d\n",mcol[mid],l,mid,r);
// 				if(mcol[mid] >= 1){
// 					l = mid + 1;
// 				}else	
// 					r = mid;
// 			}
// 			// printf("%d\n",l);
// 			v.push_back({i,l});
// 			i++;
// 		}
// 		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > 
// 							qqq(greater<pair<int, int>>(), move(v));
// 			// 插入以后不会自动排序。。。。。
// 		PrintVPector(qqq);
//         vector<int> ans;
//         for (int i = 0; i < k; ++i) {
//             ans.push_back(qqq.top().second);
//             qqq.pop();
//         }
// 		return ans;
//     }
// };




int main(){ 
	Solution sol;
	vector<vector<int>> mat =  {{1,1,0,0,0}, {1,1,1,1,0}, {1,0,0,0,0}, {1,1,0,0,0}, {1,1,1,1,1}};
	// vector<vector<int>> mat =   {{1,0,0,0}, {1,1,1,1}, {1,0,0,0}, {1,0,0,0}};
	// vector<vector<int>> mat =   {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},{1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},{1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0}};
	int k = 3;
	
	PrintVVector(mat);

	auto ans = sol.kWeakestRows(mat,k);
	
	PrintVector(ans);
	return 0;
}
