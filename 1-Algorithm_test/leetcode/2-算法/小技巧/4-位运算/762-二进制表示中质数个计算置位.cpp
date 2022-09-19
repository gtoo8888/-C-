#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

	
class Solution {
public:
    bool issushu(int x) {
        if(x == 1) return false;
        if(x == 2) return true;
        for(int i = 2;i < x;i++){
            if(x%i == 0)
                return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left;i <= right;i++){
            int zero_num = 0;
            int tmp = i;
            while(tmp != 0){
                if(tmp & 1 == 1)
                    zero_num++;
                tmp = tmp >> 1;
            }
            printf("%d,%d\n",i,zero_num);
            if(issushu(zero_num))
                ans++;
        }
        return ans;
    }
};


	
int main() {
	Solution solution;
	int left=10,right=15;
	
	auto ans = solution.countPrimeSetBits(left,right);
	
	cout << ans << endl;
	
	return 0;
}




