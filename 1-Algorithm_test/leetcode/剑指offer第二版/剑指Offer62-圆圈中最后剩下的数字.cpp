#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lastRemaining(int n, int m) {
        vector<int> quan(n,0);
        vector<bool> isok(n,false);
        for(int i = 0;i < n;i++)
            quan[i] = i;
        int count = 0;
        int index = 0;
        while(count < n){
            int buchang = m;
            while(buchang--){
                index++;
                if(index >= n)
                    index = index%n;
            }
            while(isok[index] == false){
                index++;
                if(index >= n)
                    index = index%n;
            }
            isok[index] = true;
        }
        return quan[index];
    }
};

	
int main() {
	Solution sol;

    int n = 5,m = 3;

	auto ans = sol.lastRemaining(n,m);
	cout << ans << endl;
	
	return 0;
}



