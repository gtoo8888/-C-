#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        stack<int> st;
        int n = s.size();
        int ans = 0;
        int len = 0;
        for(int i = 0;i < n;i++){
            if(s[i] == '0'){
                len++;
                st.push(s[i]);
            }else if(s[i] == '1'){
                if(st.empty() == true){
                    ans = max(len,ans);
                    len = 0;
                }else{
                    len++;
                    st.pop();
                    if(st.empty() == true){
                        ans = max(len,ans);
                        len = 0;
                    }else if(st.empty() == false){
                        if(i < n-1){
                            if(s[i+1] == '0'){
                                len = len - st.size();
                                ans = max(len,ans);
                                len = 0;
                                while(!st.empty()) st.pop();
                            }
                        }
                    }
                }
            }
        }
        if(st.empty() == false){
            len = len - st.size();
            ans = max(len,ans);
        }
        return ans;
    }
};


	
int main() {
	Solution solution;
    // string s = "0100011110";
    // string s = "00111";
    // string s = "111";
    // string s = "000";
    // string s = "11100000000000000111";
    // string s = "00101";
    // string s = "000000011000111";
    string s = "00110010";


	auto ans = solution.findTheLongestBalancedSubstring(s);
	cout << ans << endl;
	return 0;
}







