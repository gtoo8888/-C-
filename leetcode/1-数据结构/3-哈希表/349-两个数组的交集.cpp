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
        	int num_temp = *it;//把num1中的值取出，下一步是和hums2中的值比较 
            if(temp.find(num_temp) != temp.end() )//这是哈希表自己的检查方法 
            	result.insert(num_temp);//先用哈希表存储结果，最后转换一下 
        }
        return vector<int>(result.begin(),result.end());//使用匿名函数进行传递 
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



