#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
// 		int count = 0;
// 		while (n != 0){
// 			if(n & 1  == 1)	//��ȡ�����һλ�������ǲ���1
// 				count++;	//�ǵĻ����ۼ�
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
			n = n&(n-1); //�������ÿһ�ο�������һ��1
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



