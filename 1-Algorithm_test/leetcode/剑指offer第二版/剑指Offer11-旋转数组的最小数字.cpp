#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int minArray(vector<int>& numbers) {
        int min = INT32_MAX;
        for(int i = 0;i < numbers.size();i++)
            if(numbers[i] < min)
                min = numbers[i];
        return min;
    }
};


	
int main() {
	Solution sol;
	vector<int> numbers = {3,4,5,1,2};

	auto ans = sol.minArray(numbers);
	cout << ans << endl;
	
	return 0;
}



