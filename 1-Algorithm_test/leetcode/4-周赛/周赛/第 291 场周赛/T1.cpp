#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        vector<string> vs;
        for(int i = 0;i < n;i++){
            string tmp_number = number;
            string tmp;
            if(number[i] == digit){
                tmp = tmp_number.erase(i, 1);
            }
            if(tmp != "")
                vs.push_back(tmp);
            // cout << tmp << endl;
        }
        PrintVSector(vs);
        string ans;
        string tmp_s = vs[0];
        for(int i = 1;i < vs.size();i++){
            int len = vs[0].size();
            int s = 0;
            if(vs[i] == tmp_s)
                continue;
            while(vs[i][s] == tmp_s[s] && s < len){
                // printf("%c %c\n",vs[i][s],tmp_s[s] );
                s++;
            }
            // cout << endl;
            if(vs[i][s] > tmp_s[s] )
                tmp_s = vs[i];
            else
                tmp_s = tmp_s;
            // cout << tmp_s << endl;
        }
        return tmp_s;
    }
};



	
int main() {
	Solution solution;
    string number = "3619552534";
    char digit = '5';

    auto ans = solution.removeDigit(number,digit);

	cout << ans << endl;
	return 0;
}




