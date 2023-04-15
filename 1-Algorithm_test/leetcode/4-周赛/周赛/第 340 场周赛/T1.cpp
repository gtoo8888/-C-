#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


bool isPrime( int num ){
    if(num == 1) // 1不是质数
        return false;
    if(num == 2|| num== 3 )//两个较小数另外处理
        return 1;
    if(num %6!= 1&&num %6!= 5)//不在6的倍数两侧的一定不是质数
        return 0 ;
    int tmp =(int)__builtin_sqrtf(1.0*num);
    for(int i = 5;i <= tmp;i += 6 )//在6的倍数两侧的也可能不是质数
        if(num%i == 0||num%(i+2) ==0 )
                    return 0 ;
    return 1 ;//排除所有，剩余的是质数
}


class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        // PrintVVector(nums);
        int n = nums.size();
        long long ans = 0;
        for(int i = 0;i < n;i++){
            long long lduijiao = nums[i][i];
            long long rduijiao = nums[i][n-i-1];
            if(isPrime(lduijiao)){
                ans = lduijiao > ans ? lduijiao : ans;
            }
            if(isPrime(rduijiao)){
                ans = rduijiao > ans ? rduijiao : ans;
            }
        }
        return ans;
    }
};


	
int main() {
	Solution solution;
    // vector<vector<int>> nums = {{1,2,3},{5,6,7},{9,10,11}};
    vector<vector<int>> nums = {{788,645,309,559},{624,160,435,724},{770,483,95,695},{510,779,984,238}};


	auto ans = solution.diagonalPrime(nums);
	cout << ans << endl;
	return 0;
}







