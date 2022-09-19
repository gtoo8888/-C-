#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

class Solution {
public:
    //O(2n)——这个已经击败100%了。。。。。
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> haiba(n+1);
        for(int i = 0;i < n;i++){
            haiba[i+1] = haiba[i] + gain[i];
        }
        PrintVector(haiba);
        int max_haiba = INT32_MIN;
        for(int i = 0;i < n+1;i++)
            max_haiba = max_haiba < haiba[i] ? haiba[i] : max_haiba;
        return max_haiba;
    }
    //O(n)
    // int largestAltitude(vector<int>& gain) {
    //     int n = gain.size();
    //     vector<int> haiba(n+1);
    //     int max_haiba = haiba[0];
    //     for(int i = 0;i < n;i++){
    //         haiba[i+1] = haiba[i] + gain[i];
    //         max_haiba = max_haiba < haiba[i+1] ? haiba[i+1] : max_haiba;
    //     }
    //     // PrintVector(haiba);
    //     return max_haiba;
    // }
};


int main() {
	Solution solution;
	vector<int> gain = {-4,-3,-2,-1,4,3,2};
	
	auto ans = solution.largestAltitude(gain);
	
	cout << ans << endl;
	
	return 0;
}



