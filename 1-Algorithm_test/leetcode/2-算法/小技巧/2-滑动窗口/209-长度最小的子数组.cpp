#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


//class Solution {//�������� 
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//		int ans = INT_MAX;//�ȱ�������ֵ 
//		int sumarray;
//		int sublength = 0;
//		for(int i = 0;i < nums.size();i++){//ÿ��������һ�� 
//			sumarray = 0;
//			for(int j = i;j < nums.size();j++){//��ÿ������ʼ��������ʲôʱ���ܳ���target 
//				sumarray += nums[j];
////				cout << sumarray << endl;
//				if(sumarray >= target){//ֻҪ����Ŀ��ֵ�������Խ����ж� 
//					sublength =  j - i + 1;
//					ans = sublength < ans ? sublength : ans;
//					break;//�����ֱ�ӽض������ѭ�� 
//				}	
//			}
//		}
//		return ans == INT_MAX ? 0 : ans;
//    }
//};

class Solution {//�������ڣ�ֻ��Ҫһ��for 
public:
    int minSubArrayLen(int target, vector<int>& nums) {
		int ans = INT_MAX;//�ȱ�������ֵ 
		int sublenght;
		int i = 0;//��߽���Ҫ�����涨�壬��Ϊ��Ҫ�ڲ����б߽��ƶ� 
		int sum = 0;
		for(int j = 0;j < nums.size();j++){
			sum += nums[j];
			while(sum >= target){
				sublenght = j - i + 1;
				ans = sublenght < ans ? sublenght : ans;
				sum -= nums[i++];//�൱������forѭ���е�break
				//ͨ����i++Ҳ������߽������ƶ��ķ�ʽ
				//ͬʱ�������ֵ���ﵽ�������߽糤�ȵ�Ч�� 
			}
		}
		return ans == INT_MAX ? 0 : ans;
    }
};
		
int main() {
	Solution solution;
	int nums_test[]  = {2,3,1,2,4,3};
	int target = 7;
	vector<int> nums(nums_test,nums_test + sizeof(nums_test) / sizeof(int));
	int ans;
	
	ans = solution.minSubArrayLen(target,nums);
	
	cout << ans <<endl;
	return 0;
}



