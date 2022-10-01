#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


	
int main() {
	string str1 = "[[0,1,2,0],[3,4,5,2],[1,3,1,5]]";
	for(int i = 0;i < str1.size();i++){
		if(str1[i] == '[')
			str1[i] = '{';
		if(str1[i] == ']')
			str1[i] = '}';
		if(str1[i] == '\"')
			str1[i] = '\'';
	}
	
	
	
	cout << str1 << endl;
	
	return 0;
}



