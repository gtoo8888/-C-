#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// 每位的数字相加即可
// 由于正常都是大的在前面，如果前面是小的，把前面的数字变为负数
class Solution {
public:
    map<char,int> luoma = {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
    };
    int romanToInt(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0;i < n;i++){
            if(i+1<n){
                int now = luoma[s[i]];
                int next = luoma[s[i+1]];
                if(now < next){
                    ans += (-1)*luoma[s[i]];
                }else{
                    ans += luoma[s[i]];
                }
            }else{
                ans += luoma[s[i]];
            }
        }
        return ans;
    }
};



	
int main() {
	Solution solution;
	// string s = "III";
	// string s = "IV";
    string s = "MCMXCIV";
    

	auto ans = solution.romanToInt(s);
	
	cout << ans << endl;
	
	return 0;
}



