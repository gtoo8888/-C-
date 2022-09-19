#include <iostream> 
#include <vector>
using namespace std;

int main(void) {
	vector<int> nums = {9,3,4,5,6,7,7,4,3};
	int len = nums.size();
	for(int i = 0;i < len;i++)
		for(int j = i+1;j < len;j++) {
			if(nums[i] > nums[j]){
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	
	for(auto it = nums.begin();it != nums.end();it++)
		cout << *it << " ";
	cout << endl;
		
	return 0;
}
