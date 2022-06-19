#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<char> v){
	for(vector<char>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


void printVSector(vector<string> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

class Solution {
public:
	int change_num(string ip){
		reverse(ip.begin(),ip.end());
		int ans = 0;
		for(int i = 0;i < ip.size();i++){
			ans += (ip[i] - '0') * pow(10,i);
		}
		return ans;
	}
    string validIPAddress(string queryIP) {
		// printf("%d\n",change_nunm("01"));
		int n = queryIP.size();
		// printf("%d %c\n",n,queryIP[11]);
        if(queryIP.find(".") != string::npos){
			vector<string> string_save;
			int start = 0;
			int ipv4_sub = 0;
			for(int i = 0;i < n;i++){
				// printf("%d %d %c\n",start,i,queryIP[i]);
				if(queryIP[i] == '.'){
					string tmp;
					if(string_save.size() >= 1)
						tmp = queryIP.substr(start+1,i-start-1);
					else
						tmp = queryIP.substr(start,i-start);
					string_save.push_back(tmp);
					start = i;
					ipv4_sub++;
				}
			}
			if(ipv4_sub != 3)
				return "Neither";
			string tmp = queryIP.substr(start+1,n-start);
			string_save.push_back(tmp);
			// printVSector(string_save);
			for(string ipv4 : string_save){
				if(ipv4 == "")
					return "Neither";
				if(ipv4.size() > 3)
					return "Neither";
				for(int i = 0;i < ipv4.size();i++){
					if(!('0' <= ipv4[i] && ipv4[i] <= '9'))
						return "Neither";
				}
				int num_ipv4 = change_num(ipv4);
				if(num_ipv4 > 255)
					return "Neither";
				if(num_ipv4 >= 0 && num_ipv4 < 10)
					if(ipv4.size() != 1)
						return "Neither";
				if(num_ipv4 >= 10 && num_ipv4 < 100)
					if(ipv4.size() != 2)
						return "Neither";
			}
			return "IPv4";
		}
		else{
			vector<string> string_save;
			int start = 0;
			int ipv6_sub = 0;
			for(int i = 0;i < n;i++){
				// printf("%d %d %c\n",start,i,queryIP[i]);
				if(queryIP[i] == ':'){
					string tmp;
					if(string_save.size() >= 1)
						tmp = queryIP.substr(start+1,i-start-1);
					else
						tmp = queryIP.substr(start,i-start);
					string_save.push_back(tmp);
					start = i;
					ipv6_sub++;
				}
			}
			// printf("%d \n",ipv6_sub);
			if(ipv6_sub != 7)
				return "Neither";
			string tmp = queryIP.substr(start+1,n-start);
			string_save.push_back(tmp);
			// printVSector(string_save);
			for(string ipv6 : string_save){
				if(ipv6 == "")
					return "Neither";
				if(ipv6.size() > 4)
					return "Neither";
				for(int i = 0;i < ipv6.size();i++){
					if(!('0' <= ipv6[i] && ipv6[i] <= '9' || 
					'a'<= tolower(ipv6[i]) && tolower(ipv6[i]) <= 'f' ))
						return "Neither";
					if(ipv6.size() > 4)
						return "Neither";
				}
			}
			return "IPv6";
		}
		return "null";
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
	
	auto ans = solution.validIPAddress(queryIP);
	cout << ans << endl;
	return 0;
}


