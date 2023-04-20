#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        long long max_right = 0;
        for(auto build : buildings){
            max_right = build[1] > max_right ? build[1] : max_right;
        }    
        // cout << max_right << endl;
        // vector<int> height(max_right+2,0);
        int height[max_right] = {0};
        // PrintVVector(buildings);
        int n = buildings.size();
        for(auto build : buildings){
            int l = build[0],r = build[1],h = build[2];
            for(int i = l;i <= r;i++){
                height[i] = max(height[i],h);
            }
        }
        // PrintVector(height);
        vector<vector<int>> ans;
        if(height[0] > 0)
            ans.push_back({0,height[0]});
        for(long long i = 0;i <= max_right;i++){
            if(height[i] < height[i+1]){
                ans.push_back({(int)i+1,height[i+1]});
            }else if(height[i] > height[i+1]){
                ans.push_back({(int)i,height[i+1]});
            }
        }
        return ans;
    }
};


int main() {
	Solution solution;
    vector<vector<int>> buildings;
    // buildings = vector<vector<int>>{{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
	// PrintVVector(solution.getSkyline(buildings));cout << "-----------------" << endl;
	
    // buildings = vector<vector<int>>{{0,2,3},{2,5,3}};
	// PrintVVector(solution.getSkyline(buildings));cout << "-----------------" << endl;
    
    buildings = vector<vector<int>>{{0,2147483647,2147483647}};
	PrintVVector(solution.getSkyline(buildings));cout << "-----------------" << endl;
	
	return 0;
}
		



