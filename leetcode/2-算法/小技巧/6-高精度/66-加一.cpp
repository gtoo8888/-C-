#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


// ��ǰ����
// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits) {
//         reverse(digits.begin(),digits.end());
//         int n = digits.size();
//         int cnt = 0;
//         vector<int> ans(n);
//         cnt += digits[0] + 1;
//         ans[0] = cnt % 10;
//         cnt /= 10;
//         for(int i = 1;i < n;i++){
//             cnt += digits[i];
//             // printf("%d %d\n",cnt,digits[i]);
//             ans[i] = cnt % 10;
//             cnt /= 10;
//             // PrintVector(ans);
//         }
//         if(cnt)
//             ans.emplace_back(1);
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };


// ֱ�ӴӺ���ǰ
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i = n-1;i >= 0;i--){    // ��Ϊֻ�Ǽ�1���Խ�λ�Ļ����ض����10
            digits[i] = (digits[i] + 1) % 10;   // �����λ�Ļ���10%10�ض���0
            if(digits[i])   // ���������0��ʾ��λ�ˣ����᷵�أ������ӣ���һλ���ַ�0,��ֱ�ӿ��Է�����
                return digits;
        }
        vector<int> ans(n+1,0); // ���ȫ��ѭ������û�з��سɹ���˵����Ҫ���λ
        ans[0] = 1;
        return ans;
    }
};


int main() {
	Solution solution;
    vector<int> digits = {2,4,5,9,9,9};

	auto ans = solution.plusOne(digits);
	
	PrintVector(ans);	
	return 0;
}



