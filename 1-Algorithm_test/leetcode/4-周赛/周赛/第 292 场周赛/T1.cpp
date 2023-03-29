#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

// class Solution {
// public:
//     bool check(string& tmp){
//         if(tmp[0] == tmp[1] && tmp[1] == tmp[2] && tmp[0] == tmp[2])
//             return true;
//         else
//             return false;
//     }
//     string largestGoodInteger(string num) {
//         if(num.size() < 3)
//             return "";
//         string ans = "000";
//         int n = num.size();
//         bool flag = false;
//         for(int i = 0;i+3 <= n;i++){
//             string tmp = num.substr(i,3);
//             // cout << tmp << endl;
//             if(check(tmp)){
//                 flag = true;
//                 // cout << tmp << endl;
//                 if(tmp[0] >= ans[0])
//                     ans = tmp;
//             }
//         }
//         if(!flag)
//             return "";
//         return ans;
//     }
// };

// Ëõ¶Ì´úÂëºó
class Solution {
public:
    string largestGoodInteger(string num) {
        if(num.size() < 3)
            return "";
        string ans = "";
        for(int i = 0;i+3 <= num.size();i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]){
                ans = max(ans,num.substr(i,3));
            }
        }
        return ans;
    }
};
	
int main() {
	Solution solution;
    string num = "2300019";

    auto ans = solution.largestGoodInteger(num);

	cout << ans << endl;
	return 0;
}




