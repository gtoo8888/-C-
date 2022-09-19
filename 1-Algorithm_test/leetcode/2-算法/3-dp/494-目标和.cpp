#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

//+1+1+1+1-1=3
//�����Ԫ�غ�(��������)Ϊsum
//����Ԫ�غ�neg
//����Ԫ�غ�sum-neg������ȥ���˸�������
//���ʽ��target
//+(sum-neg)-neg=target
//�õ�neg=(sum-target)/2

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = 0;
        for(int i = 0;i < nums.size();i++) 
            sum += nums[i];
        int bagsize = (target + sum) / 2;

        if(abs(target) > sum) //ȫ��������Ҳû��Ŀ��󣬱�Ȼû�з���
            return 0;
        if((target + sum) % 2 == 1)
            return 0;

        vector<int> dp(bagsize + 1,0);
        dp[0] = 1;
	    
        for(int i = 0;i < nums.size();i++) {
            for(int j = bagsize;j >= nums[i];j--) {
                dp[j] += dp[j - nums[i]]; //�ۼӵĶ�̬�滮�ķ���
                printVector(dp);  
            }
            cout << endl;
        }
        return dp[bagsize];
    }
};



int main() {
	Solution solution;
	vector<int> nums = {1,1,1,1,1,1,1,3,4,6};
	int target = 16;
	
	auto ans = solution.findTargetSumWays(nums,target);
	
	cout << ans << endl;
	return 0;
}



