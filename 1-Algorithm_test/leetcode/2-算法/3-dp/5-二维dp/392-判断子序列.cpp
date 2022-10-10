#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

// 双指针
// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//         int n = s.size();
//         int m = t.size();
//         int j = 0,i = 0;
//         while(i < m){
//             printf("%c %c\n",s[i] , t[j]);
//             if(s[i] == t[j]){
//                 j++;
//                 i++;
//             }else
//                 j++;
//             if(j == m)
//                 break;
//         }
//         printf("%d %d\n",i ,j);
//         if(i == n)
//             return true;
//         else
//             return false;
//     }
// };


// 双指针 优化
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(),m = t.size();
        int j = 0,i = 0;
        while(i < m && j < m){
            printf("%c %c\n",s[i] , t[j]);
            if(s[i] == t[j]){
                i++;
            }
            j++;
        }
        printf("%d %d\n",i ,j);
        return i == n;
    }
};

// TODO dp


int main() {
	Solution solution;
	// string s = "abc";
    // string t = "ahbgdc";

	string s = "axc";
    string t = "ahbgdc";
	
	auto ans = solution.isSubsequence(s,t);
	
	PrintBool(ans);
	return 0;
}



