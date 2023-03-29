#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0;
        for(auto str : s){
            if(str == letter)
                count++;
        }
        return (double)count/s.size()*100;
    }
};
	
int main() {
	Solution solution;
    string s = "foobar";
	char letter = 'o';

    auto ans = solution.percentageLetter(s,letter);

	cout << ans << endl;
	return 0;
}




