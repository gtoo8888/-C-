#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class printVector{
public:
	void operator ()(int val){
		cout << val << " ";
	}
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int fast,slow;//�����˿���ָ�� 
    	int n = nums.size();
    	if(n == 0)//����������[]ʲô��û�У���Ӧ���з��� 
    		return 0;
    	fast = 1;
    	slow = 1;
    	while(fast < n){//��ָ���ߵ�ͷ�������ͽ����� 
    		if(nums.at(fast) != nums.at(fast - 1)){
    			nums.at(slow) = nums.at(fast);
    			slow++;
			}
    		fast++;
		}
		return slow;
    }
};


int main() {
	Solution sol;
	int nums[] = {1};
	vector<int> test_num(nums,nums + sizeof(nums)/sizeof(int));	
	int len = 0;
	for_each(test_num.begin(),test_num.end(),printVector());
	cout << endl;
	len = sol.removeDuplicates(test_num);

	for_each(test_num.begin(),test_num.begin()+len,printVector());//����vector��ǰ����Ԫ�� 
	return 0;
}

