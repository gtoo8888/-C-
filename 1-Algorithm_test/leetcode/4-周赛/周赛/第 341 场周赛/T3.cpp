#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int addMinimum(string word) {
        int ans = 0;
        int n = word.size();
        for(int i = 0;i < n;i++){
            if(word[i] == 'a'){
                int now_i = i;
                if(now_i+1 < n && now_i+1 >= 0 && word[now_i+1] == 'c'){
                    i++;   
                    ans++;
                    continue;
                }
                if(now_i+1 < n && now_i+1 >= 0 && word[now_i+1] == 'b'){
                    i++;   
                }else ans++;
                if(now_i+2 < n && now_i+2 >= 0 && word[now_i+1] == 'b' && word[now_i+2] == 'c'){
                    i++;   
                }else ans++;
            }else if(word[i] == 'b'){
                if(i-1 < n && i-1 >= 0 && word[i-1] == 'a'){
                    // i++;   
                }else ans++;
                if(i+1 < n && i+1 >= 0 && word[i+1] == 'c'){
                    i++;   
                }else ans++;
            }else if(word[i] == 'c'){
                if(i-1 < n && i-1 >= 0 && word[i-1] == 'b'){
                    // i++;   
                }else ans++;
                if(i-2 < n && i-2 >= 0 && word[i-1] == 'b' && word[i-2] == 'a'){
                    // i++;   
                }else ans++;
            }
                
        }
        return ans;
    }
};


int main() {
	Solution solution;
    string word;
    // word = "a";
    // cout << solution.addMinimum(word) << endl;cout <<"-------------"<< endl;

    // word = "b";
    // cout << solution.addMinimum(word) << endl;cout <<"-------------"<< endl;

    // word = "c";
    // cout << solution.addMinimum(word) << endl;cout <<"-------------"<< endl;

    // word = "bc";
    // cout << solution.addMinimum(word) << endl;cout <<"-------------"<< endl;

    // word = "aaa";
    // cout << solution.addMinimum(word) << endl;cout <<"-------------"<< endl;

    // word = "abc";
    // cout << solution.addMinimum(word) << endl;cout <<"-------------"<< endl;

    // word = "ababa";
    // cout << solution.addMinimum(word) << endl;cout <<"-------------"<< endl;

    word = "aaaaacc";
    cout << solution.addMinimum(word) << endl;cout <<"-------------"<< endl;

    // word = "ac";
    // cout << solution.addMinimum(word) << endl;cout <<"-------------"<< endl;

	return 0;
}




