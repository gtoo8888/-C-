#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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


// 暴力将所有的开花时间取出来福在读O(n2)
// class Solution {
// public:    
//     vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
//         int max_time = INT32_MIN;
//         for(int i = 0;i < flowers.size();i++) {
//             max_time = max_time < flowers[i][1] ? flowers[i][1] : max_time;
//         }
//         // cout << max_time << endl;
//         vector<int> now_flower(max_time+1);
//         for(int i = 0;i < flowers.size();i++) {
//             for(int j = flowers[i][0];j <= flowers[i][1];j++){
//                 now_flower[j]++;
//             }
//         }
//         // PrintVector(now_flower);
//         vector<int> ans;
//         for(int i = 0;i < persons.size();i++){
//             if(persons[i] <= max_time)
//                 ans.push_back(now_flower[persons[i]]);
//             else
//                 ans.push_back(0);
//         }
//         return ans;
//     }
// };


// 二分
class Solution {
public:    
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int n = flowers.size();
        vector<int> s_time(n);
        vector<int> e_time(n);
        for(int i = 0;i < flowers.size();i++) {
            s_time[i] = flowers[i][0];
            e_time[i] = flowers[i][1];
        }
        sort(s_time.begin(),s_time.end());
        sort(e_time.begin(),e_time.end());  // 将开花的起始时间和结束时间都存起来
        // PrintVector(s_time);
        // PrintVector(e_time);
        vector<int> ans(persons.size());
        for(int i = 0;i < persons.size();i++){
            // ans[i] = (upper_bound(s_time.begin(), s_time.end(), persons[i]) - s_time.begin()) - 
            //          (lower_bound(e_time.begin(), e_time.end(), persons[i]) - e_time.begin());
            int s1 = upper_bound(s_time.begin(), s_time.end(), persons[i]) - s_time.begin();    // 二分查找第一个大于等于被查数的值
            int e1 = lower_bound(e_time.begin(), e_time.end(), persons[i]) - e_time.begin();    // 二分查找第一个大于被查数的值
            ans[i] = s1 - e1;
            
            // printf("%d %d %d \n",s1,e1,persons[i]);
        }
        return ans;
    }
};


	
int main() {
	Solution solution;

    vector<vector<int>> fullBloomFlowers= {{1,6},{3,7},{9,12},{4,13}};
    vector<int> persons = {2,3,7,11};

    auto ans = solution.fullBloomFlowers(fullBloomFlowers,persons);

	PrintVector(ans);
	return 0;
}









