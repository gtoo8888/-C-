#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(vector<string> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
    	int start = 0;
    	int end = 0;
		for(int i = 0;i < text.size();i++) {
			string temp = " ";
			if(text[i] == ' ') {
				end = i - 1;
				temp.append(text,start,end);
				start = i + 1;
			}
			cout << temp << endl;
		}
    }
};



	
int main() {
	Solution solution;
	string text = "alice is a good girl she is a good student";
	string first = "a";
	string second = "good";

	
	auto ans = solution.findOcurrences(text,first,second);
	
//	PrintVector(ans);
	
	return 0;
}



