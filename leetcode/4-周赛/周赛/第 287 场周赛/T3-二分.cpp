#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

// 没有通过需要使用二分法
// class Solution {
// public:
//     int maximumCandies(vector<int>& candies, long long k) {
//         long long sum = 0;
//         for(int n : candies)
//             sum += n;
//         if (sum < k)
//             return 0;
//         long long each = sum/k;
//         int can_max = INT32_MIN;
//         for(int i = each;i > 0;i--){
//             int tmp = 0;
//             for(int j = 0;j < candies.size();j++) {
//                 printf("%d,%d\n",i,candies[j]);
//                 if(i <= candies[j]){
//                     if(candies[j]/i > 0)
//                         tmp += candies[j]/i;            
//                 }
//             }
//             cout << tmp << endl; 
//             if(tmp >= k){
//                 can_max = max(can_max,i);
//                 break;
//             }
//         }
//         cout << each << endl;
//         return can_max;
//     }
// };

// 抽象二分
// 测试数量级为1012，所以所有的变量都要为long long
// 将分到的堆数heap设置为int,也通不过
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for(int n : candies)        // 总共有多少糖果
            sum += n;
        // printf("%lld\n",sum);
        long long left = 0;
        long long right = sum / k;  // sum/k表示总糖数量，总数平均分，每个人分到的糖果数量
        // 对每个人可以分的糖果数量从0-sum/k列举
        // 普通的方法对left到right列举每一个，看看可不可以时间复杂度O(n)
        // 为了节约时间列举的过程用二分列举，时间复杂度降低到O(logn)
        // printf("%lld %lld\n",left,right);
        long long mid;
        while(left != right){
            mid = (left + right + 1) / 2;   // mid表示当前每个人分到的糖果数量，就是二分的枚举过程
            long long heap = 0;   // 用来记录，每个人分mid个，可以分到的总堆数
            for(int n : candies){
                heap += n / mid;
            }
            // printf("L:%lld R:%lld mid:%lld heap:%d\n",left,right,mid,heap);
            if(heap < k)   // 如果堆数比人数少，那么每个人就要少分一点，增加堆数，让每个人都有，右边界左移
                right = mid - 1;
            else // 如果堆数比人数多，那么每个人就要多分一点，减少堆数，左边界右移
                left = mid;
        }
        return (int)right;
    }
};
	
int main() {
	Solution solution;

	vector<int> candies  = {5,8,6};
    long long k = 3;

	auto ans = solution.maximumCandies(candies,k);
	
	cout << ans << endl;
	
	return 0;
}




