#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

class Solution {
public:
	bool isPos(vector<int> now_pos,int n) {
		if(now_pos[0] > n-1 || now_pos[0] < 0)
			return false;
		if(now_pos[1] > n-1 || now_pos[1] < 0)
			return false;
		return true;
	}	
	
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<vector<int>> RLUD = {{0,1},{0,-1},{-1,0},{1,0}};
        vector<int> ans;
        for(int i = 0;i < s.size();i++) {
        	int path = 0;
        	vector<int> now_pos(2,0);
//        	cout << "------" << endl;
        	
	    	if(s[i] == 'R'){
				now_pos[0] = startPos[0] + RLUD[0][0];
				now_pos[1] = startPos[1] + RLUD[0][1];}
	    	if(s[i] == 'L'){
				now_pos[0] = startPos[0] + RLUD[1][0];
				now_pos[1] = startPos[1] + RLUD[1][1];}
	    	if(s[i] == 'U'){
				now_pos[0] = startPos[0] + RLUD[2][0];
				now_pos[1] = startPos[1] + RLUD[2][1];}
	    	if(s[i] == 'D'){
				now_pos[0] = startPos[0] + RLUD[3][0];
				now_pos[1] = startPos[1] + RLUD[3][1];}	
			
			if(isPos(now_pos,n)) {
				path += 1;
//				cout << s[i] << " " << path << " ";PrintVector(now_pos);			
	        	for(int j = i + 1;j < s.size();j++) {
	        		
	        		
			    	if(s[j] == 'R'){
						now_pos[0] = now_pos[0] + RLUD[0][0];
						now_pos[1] = now_pos[1] + RLUD[0][1];}
			    	if(s[j] == 'L'){
						now_pos[0] = now_pos[0] + RLUD[1][0];
						now_pos[1] = now_pos[1] + RLUD[1][1];}
			    	if(s[j] == 'U'){
						now_pos[0] = now_pos[0] + RLUD[2][0];
						now_pos[1] = now_pos[1] + RLUD[2][1];}
			    	if(s[j] == 'D'){
						now_pos[0] = now_pos[0] + RLUD[3][0];
						now_pos[1] = now_pos[1] + RLUD[3][1];}	
					
					if(isPos(now_pos,n)) {
						path += 1;
//						cout << s[j] << " " << path << " ";PrintVector(now_pos);			
						if(j == s.size() - 1){
							ans.push_back(path);	
							break;
						}
						
					}
					else {
//						cout << path << "!!!" << endl;
						ans.push_back(path);
						break;
					}	
				}
				if(i == s.size() - 1){
					ans.push_back(path);	
					break;
				}
			}
			else {
//				cout << path << "!!!" << endl;
				ans.push_back(path);
				continue;
			}
			
		}
		return ans;
    }
};



	
int main() {
	Solution solution;
	int n = 2;
	vector<int> startPos = {0,1};
	string s = "LRUDDLL";

	
	auto ans = solution.executeInstructions(n,startPos,s);
	
	PrintVector(ans);
	
	return 0;
}



