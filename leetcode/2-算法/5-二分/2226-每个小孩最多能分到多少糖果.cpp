#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

// û��ͨ����Ҫʹ�ö��ַ�
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

// �������
// ����������Ϊ1012���������еı�����ҪΪlong long
// ���ֵ��Ķ���heap����Ϊint,Ҳͨ����
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for(int n : candies)        // �ܹ��ж����ǹ�
            sum += n;
        // printf("%lld\n",sum);
        long long left = 0;
        long long right = sum / k;  // sum/k��ʾ��������������ƽ���֣�ÿ���˷ֵ����ǹ�����
        // ��ÿ���˿��Էֵ��ǹ�������0-sum/k�о�
        // ��ͨ�ķ�����left��right�о�ÿһ���������ɲ�����ʱ�临�Ӷ�O(n)
        // Ϊ�˽�Լʱ���оٵĹ����ö����о٣�ʱ�临�ӶȽ��͵�O(logn)
        // printf("%lld %lld\n",left,right);
        long long mid;
        while(left != right){
            mid = (left + right + 1) / 2;   // mid��ʾ��ǰÿ���˷ֵ����ǹ����������Ƕ��ֵ�ö�ٹ���
            long long heap = 0;   // ������¼��ÿ���˷�mid�������Էֵ����ܶ���
            for(int n : candies){
                heap += n / mid;
            }
            // printf("L:%lld R:%lld mid:%lld heap:%d\n",left,right,mid,heap);
            if(heap < k)   // ��������������٣���ôÿ���˾�Ҫ�ٷ�һ�㣬���Ӷ�������ÿ���˶��У��ұ߽�����
                right = mid - 1;
            else // ��������������࣬��ôÿ���˾�Ҫ���һ�㣬���ٶ�������߽�����
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




