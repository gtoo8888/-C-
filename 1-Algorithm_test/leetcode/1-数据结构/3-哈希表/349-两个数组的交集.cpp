#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class printVector{
public:
	void operator ()(int val) {
		cout << val << " ";
	}
};

void printUSet(unordered_set<int> s){
	for(auto it : s)
		cout << it << " ";
	cout << endl; 
}

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> temp(nums1.begin(),nums1.end());
        
//        printUSet(temp);
        
        for(vector<int>::iterator it = nums2.begin();it != nums2.end();it++){
        	int num_temp = *it;//��num1�е�ֵȡ������һ���Ǻ�hums2�е�ֵ�Ƚ� 
            if(temp.find(num_temp) != temp.end() )//���ǹ�ϣ���Լ��ļ�鷽�� 
            	result.insert(num_temp);//���ù�ϣ��洢��������ת��һ�� 
        }
        return vector<int>(result.begin(),result.end());//ʹ�������������д��� 
    }
};


int main() {
	Solution solution;
	int nums1_test[] = {4,9,5};
	vector<int> nums1(nums1_test,nums1_test + sizeof(nums1_test) / sizeof(int));
	int nums2_test[] = {9,4,9,8,4};
	vector<int> nums2(nums2_test,nums2_test + sizeof(nums2_test) / sizeof(int));	
	vector<int> ans;
	
	ans = solution.intersection(nums1,nums2);

	for_each(ans.begin(),ans.end(),printVector());

	return 0;
}



