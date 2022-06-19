#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++){ 
//		if()
		cout << *it << " ";
	} 
	cout << endl; 
}

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0;i < nums.size();i++) 
            sum += nums[i];	
            
        if(sum % 2 == 1) return false;	//如果是奇数，必然不能被分割成两个和相同的子集 
        int target = sum/2;
        
		vector<int> dp(target+1,0);
		
        cout << sum << endl;
        for(int i = 0;i < nums.size();i++) {	//物品个数就是数字个数 
            for(int j = target;j >= nums[i];j--) {
                dp[j] = max(dp[j],dp[j - nums[i]] + nums[i]);
//                printVector(dp);
            }
//            cout << endl;
        }

        if(dp[target] == target)
            return true;
        return false;
    }
};
		
int main() {
	Solution solution;
	
	vector<int> nums = {1,2,3,22};
	
	auto ans = solution.canPartition(nums);
	
	PrintBool(ans);
	return 0;
}



