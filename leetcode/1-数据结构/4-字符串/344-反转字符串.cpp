#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<char> v){
	for(vector<char>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

class Solution {
public:
    void reverseString(vector<char>& s) {
    	int i = 0;
    	int j = s.size() - 2;//实际上-1就行了 
		while(i < j) {
//			printVector(s);
			swap(s[i],s[j]);
			i++;j--;
		}
    }
};

		
int main() {
	Solution solution;
	char str[] = "helaom";
	vector<char> s(str,str + sizeof(str) / sizeof(char));
	
	solution.reverseString(s);
	
	
	printVector(s);
	return 0;
}


