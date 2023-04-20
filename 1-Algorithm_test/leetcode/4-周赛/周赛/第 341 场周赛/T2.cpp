#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


void PrintVP(vector<pair<int,int>> vec){
    for(int i = 0;i < vec.size();i++){
        cout << vec[i].first << " " << vec[i].second << endl;
    }
    cout << endl;
}


// class Solution {
// public:
//     int maxDivScore(vector<int>& nums, vector<int>& divisors) {
//         int defen_max = -1,index_max = -1;
//         int n = divisors.size();
//         int m = nums.size();
//         vector<pair<int,int>> meifen;
//         for(int i = 0;i < n;i++){
//             int defen = 0;
//             for(int j = 0;j < m;j++){
//                 if(nums[j] % divisors[i] == 0)
//                     defen++;
//             }
//             printf("[%d]: %d\n",i,defen);
//             if(defen == 0)
//                 meifen.push_back({i,divisors[i]});
//             if(defen > defen_max){
//                 defen_max = defen;
//                 index_max = i;
//             }
//         }
//         if(meifen.size() != 0){
//             sort(meifen.begin(),meifen.end(),[](pair<int,int> a,pair<int,int> b){
//                 return a.second < b.second;
//             });
//             PrintVP(meifen);
//             return divisors[meifen[0].first];
//         }

//         // return ans;
//         return divisors[index_max];
//     }
// };


void PrintUV(unordered_map<int,vector<int>> vec){
    for(auto it = vec.begin();it != vec.end();it++){
        cout << it->first << " ";
        PrintVector(it->second);
    }
    cout << endl;
}

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int defen_max = -1,index_max = -1;
        int n = divisors.size();
        int m = nums.size();
        unordered_map<int,vector<int>> fenshu_jilu;
        for(int i = 0;i < n;i++){
            int defen = 0;
            for(int j = 0;j < m;j++){
                if(nums[j] % divisors[i] == 0)
                    defen++;
            }
            // printf("[%d]: %d\n",i,defen);
            fenshu_jilu[defen].push_back(divisors[i]);
            if(defen > defen_max){
                defen_max = defen;
                index_max = i;
            }
        }
        // PrintUV(fenshu_jilu);
        vector<int> ans = fenshu_jilu[defen_max];
        sort(ans.begin(),ans.end());
        // PrintVector(ans);
        return ans[0];
    }
};




int main() {
	Solution solution;
    vector<int> divisors;
    vector<int> nums;
    // nums = vector<int>{4,7,9,3,9};
    // divisors = vector<int>{5,2,3};
    // cout << solution.maxDivScore(nums,divisors) << endl;cout <<"-------------"<< endl;

    // nums = vector<int>{20,14,21,10};
    // divisors = vector<int>{5,7,5};
    // cout << solution.maxDivScore(nums,divisors) << endl;cout <<"-------------"<< endl;

    // nums = vector<int>{12};
    // divisors = vector<int>{10,16};
    // cout << solution.maxDivScore(nums,divisors) << endl;cout <<"-------------"<< endl;

    nums = vector<int>{73,13,20,6};
    divisors = vector<int>{56,75,83,26,24,53,56,61};
    cout << solution.maxDivScore(nums,divisors) << endl;cout <<"-------------"<< endl;

	return 0;
}







