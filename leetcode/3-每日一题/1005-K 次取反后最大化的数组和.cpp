#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}



class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
		sort(nums.begin(),nums.end());
//		printVector(nums);
		
		for(int i = 0;i < nums.size();i++) {
			if(nums[i] <= 0 && k > 0) {//k�ľ����߸�����ת���ˣ��������˳�ѭ�� 
				nums[i] = -nums[i];
				k--;
			}
			else
				break;
		}
//		printVector(nums);
		cout << k << endl;
		
		if(k > 0) { 
			sort(nums.begin(),nums.end());//�������� 
			if((k % 2) == 1)//��������� 
				nums[0] = -nums[0];//�Ͱ���С���Ǹ�����תһ�� 
			else {}//�����ż���Ǿ�ʲô���������� 
		} 
//		printVector(nums);
		
		int sum = accumulate(nums.cbegin(),nums.cend(),0);//���������ͺ��� 
		return sum;
    }
};


	
int main() {
	Solution solution;
	vector<int> nums = {-4,-2,-3};
	int k = 4;
	int ans;
	
	ans = solution.largestSumAfterKNegations(nums,k);
	
	cout << ans << endl;
	
	return 0;
}



