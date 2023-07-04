#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


// dfs递归超时
// class Solution {
// public:
//     set<int> sans;
//     void dfs(int x,int y,int bound,int i,int j,int numx,int numy){
//         int sum_xy = numx+numy;
//         if(sum_xy > bound)
//             return;
//         sans.insert(sum_xy);
//         if(x != 1)
//             dfs(x,y,bound,i+1,j,numx*x,numy);
//         if(y != 1)
//             dfs(x,y,bound,i,j+1,numx,numy*y);
//     }

//     vector<int> powerfulIntegers(int x, int y, int bound) {
//         dfs(x,y,bound,0,0,1,1);
//         vector<int> ans;
//         for(auto it : sans)
//             ans.push_back(it);
//         sort(ans.begin(),ans.end());
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> sans;
        for(int numx = 1;numx <= bound;numx *= x){
            for(int numy = 1;numy + numx <= bound;numy *= y){
                int tmp_sum = numx+numy;
                if(tmp_sum <= bound)
                    sans.insert(tmp_sum);
                if(y == 1)
                    break;
            }
            if(x == 1)
                break;
        }
        return vector<int>{sans.begin(),sans.end()};
    }
};

	
int main() {
	Solution solution;
	int x = 2; int y = 3; int bound = 10;
	// int x = 73; int y = 3; int bound = 700000;	
    // int x = 2; int y = 1; int bound = 10;	
    // int x = 2; int y = 3; int bound = 400000; // 超时

	auto ans = solution.powerfulIntegers(x,y,bound);
	
	PrintVector(ans);
	
	return 0;
}



