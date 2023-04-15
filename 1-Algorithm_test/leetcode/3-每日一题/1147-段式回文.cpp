#include <iostream>
#include <vector>
#include <string> 
#include <unordered_map> 
#include <algorithm>
using namespace std;


class Solution {
public:
    int longestDecomposition(string text) {
        if(text.size() == 0)
            return 0;
        if(text.size() == 1)
            return 1;
		int n = text.size();
		for(int i = 1;i <= n/2;i++){
			string ls = text.substr(0,i);
			string rs = text.substr(n-i,i);
            // reverse(rs.begin(),rs.end());
            if(ls == rs)
			    return 2 + longestDecomposition(text.substr(i,n-i-i));
		}
		return 1;
    }
};
		
        
int main() {
	Solution solution;
	// string text = "ghiabcdefhelloadamhelloabcdefghi";
    // string text = "merchant";
    // string text = "antaprezatepzapreanta";
    string text = "elvtoelvto";
    // string text = "aba";
    
	
	auto ans = solution.longestDecomposition(text);
	
	cout << ans << endl;
	
	return 0;
}



