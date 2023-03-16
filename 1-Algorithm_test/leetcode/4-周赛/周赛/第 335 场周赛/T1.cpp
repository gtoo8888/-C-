#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int passThePillow(int n, int time) {
        int times = time;
        int pos = 1;
        int change = 1;
        while(times--){
            if(pos >= n)
                change = -1;
            if(pos <= 1)
                change = 1;
            pos += change;
        }
        return pos;
    }
};


	
int main() {
	Solution solution;
	// int n = 4,time1 = 5;
    int n = 4,time1 = 8;
    // int n = 3,time1 = 2;
    // int n = 3,time1 = 5;
	
	auto ans = solution.passThePillow(n,time1);
	
	cout << ans << endl;
	
	return 0;
}







