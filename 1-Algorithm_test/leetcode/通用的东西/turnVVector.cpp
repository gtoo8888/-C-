#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void turnVVector(string str1){
	for(int i = 0;i < str1.size();i++){
		if(str1[i] == '[')
			str1[i] = '{';
		if(str1[i] == ']')
			str1[i] = '}';
		if(str1[i] == '\"')
			str1[i] = '\'';
	}
	cout << str1 << endl;
}


int main() {
	string str1 = "[[1,2],[3,1],[2,4],[2,3],[4,4]]";
	turnVVector(str1);

	vector<vector<int>> grid ={{1,2,5},{3,2,1}};
	
	return 0;
}



