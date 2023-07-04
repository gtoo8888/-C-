#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<pair<int,int>> tongji(n);
        for(int i = 0;i < n;i++){
            int sum = 0;
            for(int j = 0;j < mat[i].size();j++){
                if(mat[i][j] == 1)
                    sum++;
            }
            tongji[i] = {i,sum};
        }
        // PrintVP(tongji);
        sort(tongji.begin(),tongji.end(),[](pair<int,int> a,pair<int,int> b){
            if(a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
        });
        // PrintVP(tongji);
        vector<int> ans{tongji[0].first,tongji[0].second};
        return ans;
    }
};



int main() {
	Solution solution;
    vector<vector<int>> mat;
    // mat = vector<vector<int>>{{0,1},{1,0}};
    // PrintVector(solution.rowAndMaximumOnes(mat));cout <<"-------------"<< endl;

    mat = vector<vector<int>>{{0,0,0},{0,1,1}};
    PrintVector(solution.rowAndMaximumOnes(mat));cout <<"-------------"<< endl;

    mat = vector<vector<int>>{{0,0},{1,1},{0,0}};
    PrintVector(solution.rowAndMaximumOnes(mat));cout <<"-------------"<< endl;
	return 0;
}







