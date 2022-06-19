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
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n+1);
        for(int i = 0;i < n;i++){
            pre[i+1] = pre[i] ^ arr[i];
        }
        // PrintVector(pre);
        int ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                for(int k = j;k <= n;k++){
                    int a = pre[j-1] ^ pre[i-1];
                    int b = pre[k] ^ pre[j-1];
                    if(a == b)
                        ans++;
                }
            }
        }
        return ans;
    }
};


int main() {
	Solution solution;
	vector<int> arr = {1,1,1,1,1};
	
	auto ans = solution.countTriplets(arr);
	
	cout << ans << endl;
	
	return 0;
}



