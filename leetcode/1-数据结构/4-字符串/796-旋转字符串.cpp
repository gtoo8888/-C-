#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(vector<string> v){
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
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())
            return false;
        s = s + s;
        // cout << s << endl;
        int i = 0;
        for(i = 0;i <  s.size()/2;i++){
            // printf("%c,%c,%d\n",s[i],goal[0],i);
            if(s[i] == goal[0]){
                int tmp_i = i;
                int j = 0;
                for(j = 0;j < goal.size();j++){
                    if(s[tmp_i] != goal[j]){
                        break;
                    }else{
                        // printf("    %c,%c,%d,%d\n",s[i],goal[j],i,j);
                        tmp_i++;
                    }
                }
                if(j == goal.size())
                    return true;
            }
        }
        if(i == s.size()/2)
            return false;
        return true;
    }
};



	
int main() {
	Solution solution;
	string s = "vcuszhlbtpmksjleuchmjffufrwpiddgyynfujnqblngzoogzg";
	string goal = "fufrwpiddgyynfujnqblngzoogzgvcuszhlbtpmksjleuchmjf";

	
	auto ans = solution.rotateString(s,goal);
	
	PrintBool(ans);
	
	return 0;
}



