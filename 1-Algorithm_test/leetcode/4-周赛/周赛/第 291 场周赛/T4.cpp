#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;




class Solution {
public:
    int cout_str(string str){
        unordered_map<char,int> map;
        for(char s : str){
            map[s]++;
        }
        int res = 0;
        for(auto m : map){
            res++;
        }
        return res;
    }

    long long appealSum(string s) {
        int n = s.size();
        vector<string> str;
        for(int i = 1;i <= n;i++){
            string tmp;
            for(int j = 0;j <= n-i;j++){
                tmp = s.substr(j,i);
                // printf("%d %d \n",j,j+i);
                // cout << tmp << endl;
                str.push_back(tmp);
            }
        }
        // PrintVSector(str);
        int ans = 0;
        for(int i = 0;i < str.size();i++){
            ans += cout_str(str[i]);
        }
        return ans;
    }
};


	
int main() {
	Solution solution;

    string s = "abbca";

    auto ans = solution.appealSum(s);

	cout << ans << endl;
	return 0;
}




