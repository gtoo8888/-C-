#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string maskPII(string s) {

    }
};

		 
int main() {
	Solution solution;
	// string queryIP = "172.16.255.2";
	// string queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334";
	// string queryIP = "2001:0db8:85a3::8A2E:037j:7334";
	// string queryIP = "02001:0db8:85a3:0000:0000:8a2e:0370:7334";
	// string queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334:";
	// string queryIP = "1.0.1.";
	// string queryIP = "01.01.01.01";
	// string queryIP = "2001:db8:85a3:0::8a2E:0370:7334";
	string queryIP = "111111111.1111111111111111111111.1111111111111111111.11111111111";
	
	auto ans = solution.maskPII(queryIP);
	cout << ans << endl;
	return 0;
}


