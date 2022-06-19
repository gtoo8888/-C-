#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


void printVector(vector<bool> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}

void PrintMap(map<int,string> m) {
	for(auto it = m.begin();it != m.end();it++)
		cout << (*it).first << " " << it->second << endl;
	cout << endl;	
}

void PrintMap2(map<char,int> m) {
	for(auto it = m.begin();it != m.end();it++)
		cout << (*it).first << " " << it->second << endl;
	cout << endl;	
}

class Solution {
public:
    int countPoints(string rings) {
        map<int,string> m;
        for(int i = 0;i < rings.size();i += 2) {
        	string temp = m[rings[i+1] - '0'];
        	temp = temp + rings[i];
        	m[rings[i+1] - '0'] = temp;
		}
//		PrintMap(m);
		
		vector<bool> gan(10,false);
		for(int i = 0;i < 10;i++) {
			auto temp = m[i];
			bool flag1 = false;
			bool flag2 = false;
			bool flag3 = false;
			for(int j = 0;j < temp.size();j++) {
//				cout << temp[j] << " ";
				if(temp[j] == 'R') flag1 = true;
				if(temp[j] == 'G') flag2 = true;
				if(temp[j] == 'B') flag3 = true;
				if(flag1 && flag2 && flag3)	
					gan[i] = true;
			}
//			cout << endl;
		}
		
//		printVector(gan);
		int cout = 0;
		for(int i = 0;i < 10;i++) {
			if(gan[i] == true)
				cout++;
		}

		return cout;
    }
};


//			for(int j = 0;j < temp.size();j++) {
//				m2[temp[j]]++;
//			}
//			
//			for(auto it = m2.begin();it != m2.end();it++) {
////				cout << (*it).second << endl;
//				if((*it).second < min_rgb)
//					min_rgb = (*it).second;
//			}

	
int main() {
	Solution solution;
	string rings = "B0B6G0R6R0R6G9";
	
	auto ans = solution.countPoints(rings);
	
	cout << ans << endl;
	
	return 0;
}



