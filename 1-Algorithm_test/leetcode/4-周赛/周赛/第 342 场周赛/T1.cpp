#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime+delayedTime)%24;
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







