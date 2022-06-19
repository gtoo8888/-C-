#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
// 		int count = 0;
// 		while (n != 0){
// 			if(n & 1  == 1)	//就取出最后一位，看看是不是1
// 				count++;	//是的话就累加
// 			n >>= 1;
// 			// printf("%d\n",n);
// 		}
//         return count;
//     }
// };

class Solution {
public:
    int hammingWeight(uint32_t n) {
		int count = 0;
		while (n != 0){
			count++;
			n = n&(n-1); //这个操作每一次可以消掉一个1
			printf("%x\n",n);
		}
        return count;
    }
};


	
int main() {
	Solution sol;
	uint32_t nums = 17;	
	auto ans = sol.hammingWeight(nums);
	cout << ans << endl;
	
	return 0;
}



