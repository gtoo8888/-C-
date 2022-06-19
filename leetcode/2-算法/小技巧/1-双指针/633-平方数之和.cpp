#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}

// 双指针
// 如果low*low + high*high < c那么low++;
// 如果low*low + high*high > c那么high--;
class Solution {
public:
    bool judgeSquareSum(int c) {
		long long low = 0,high = sqrt(c);
		while(low <= high){
			// printf("%lld %lld %d\n",low*low ,high*high,c);
			if(low*low + high*high == c)
				return true;
			else if(low*low + high*high < c)
				low++;
			else
				high--;
			
		}
		return false;
    }
};


	
int main() {
	Solution solution;
	int c = 2;
	
	auto ans = solution.judgeSquareSum(c);
	cout << ans << endl;
	
	return 0;
}



