#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> v)
{
	for (auto it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	cout << endl;
}

void PrintVVector(vector<vector<int>> v)
{
	for (auto iter = v.begin(); iter != v.end(); iter++)
	{
		auto it_temp = *iter;
		for (auto it = it_temp.begin(); it != it_temp.end(); it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}

class Solution{
public:
	int maxProduct(vector<int> &nums){
		// PrintVector(nums);
		sort(nums.begin(), nums.end(), greater<int>());
		// PrintVector(nums);
		return (nums[0]-1) * (nums[1]-1);
	}
};

int main()
{
	Solution solution;
	vector<int> nums = {3, 4, 5, 2};

	auto ans = solution.maxProduct(nums);

	cout << ans << endl;

	return 0;
}
