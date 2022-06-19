#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;


void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void printMap(unordered_map<int,int> &m){
	for(unordered_map<int,int>::iterator it = m.begin();it != m.end();it++)
		cout << (*it).first <<" " << it -> second << endl;
	cout << endl; 
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int,int> map;//�ù�ϣmap�棬��һ���������ڶ������±� 
		for(int i = 0;i < nums.size();i++){
			
			unordered_map<int,int>::iterator it = map.find(target - nums[i]);
			
			if(it != map.end()) {
			 //�Ա�һ�¹�ϣmap����û��������֣����û�еĻ���������� �� it == map.end()
			 //��������Ҫ�ҵ����֣���������� it != map.end(),�ͽ������� 
				vector<int> ans; //Ҫ���ص���vector 
				ans.push_back((*it).second);//�� 
				ans.push_back(i);
				return ans;
			} 
        
			map.insert(pair<int,int>(nums.at(i),i));//ÿ��ѡ��󶼽��ոռ�����Ķ��������ϣMap 
		}
		return {};
    }
};


int main() {
	Solution solution;
	int nums[] = {3,2,4};
	vector<int> test_num(nums,nums + sizeof(nums)/sizeof(int));
	vector<int> returnSize;
	int target = 6;
	
	returnSize = solution.twoSum(test_num,target);
		
	printVector(returnSize);

	return 0;
}

