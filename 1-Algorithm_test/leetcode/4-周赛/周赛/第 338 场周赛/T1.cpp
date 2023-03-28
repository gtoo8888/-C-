#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if(k - numOnes <= 0){
            return k;
        }else if(k - numOnes - numZeros <= 0)
            return numOnes;

        return numOnes-(k-numOnes-numZeros);
    }
};


	
int main() {
	Solution solution;
    // int numOnes = 3, numZeros = 2, numNegOnes = 0, k = 2;
    // int numOnes = 3, numZeros = 2, numNegOnes = 0, k = 3;
    // int numOnes = 3, numZeros = 2, numNegOnes = 0, k = 4;
    // int numOnes = 3, numZeros = 2, numNegOnes = 3, k = 6;
    int numOnes = 6, numZeros = 6, numNegOnes = 6, k = 13;

	auto ans = solution.kItemsWithMaximumSum(numOnes,numZeros,numNegOnes,k);
	
	cout << ans << endl;
	
	return 0;
}







