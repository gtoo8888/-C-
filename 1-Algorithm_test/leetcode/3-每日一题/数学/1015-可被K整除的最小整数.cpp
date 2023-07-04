#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int smallestRepunitDivByK(int k) {
		if(k%2 == 0 || k%5 == 0)
			return -1;
		int res = 0,r = 0;
		while(res == 0 || r != 0){
			r = r*10 + 1;
			r %= k;
			res++;
		}
		return res;
    }
};


int main() {
	Solution sol;

	cout << sol.smallestRepunitDivByK(1) << endl;cout << "---------------------" << endl;
	cout << sol.smallestRepunitDivByK(2) << endl;cout << "---------------------" << endl;
	cout << sol.smallestRepunitDivByK(3) << endl;cout << "---------------------" << endl;

	return 0;
}

