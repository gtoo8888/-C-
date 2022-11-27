#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


// 如果使用移位的操作，如果输入为一个负数，会形成死循环
// 由于移位以后负数前面会自动补1
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
		// PrintBit(n);
		int count = 0;
		while (n != 0){
			count++;
			n = n&(n-1); //这个操作每一次可以消掉一个1
			// PrintBit(n);
		}
        return count;
    }
};


	
int main() {
	Solution sol;
	// uint32_t nums = 3;	
	// uint32_t nums = 127;	

	uint32_t n = -1;	

	while (n != 0){
		n >>= 1;
		printf("%d\n",n);
	}

	string str;
	while(n != 0 ) {
		if(n & 1 == 1)  
			str.push_back('1');
		else   
			str.push_back('0');
		n >>= 1;
		printf("%d\n",n);
	}
	reverse(str.begin(),str.end());
	cout << str << endl;



	PrintBit(-1);
	// printf("%d",~(-5));
	// uint32_t nums = 127;	
	// auto ans = sol.hammingWeight(nums);
	// cout << ans << endl;
	
	return 0;
}



