#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
    int convertTime(string current, string correct) {
        int cur_H = (current[0]-'0')*10 + (current[1]-'0');
        int cur_M = (current[3]-'0')*10 + (current[4]-'0');

        int cor_H = (correct[0]-'0')*10 + (correct[1]-'0');
        int cor_M = (correct[3]-'0')*10 + (correct[4]-'0');
        printf("%d:%d,%d:%d\n",cur_H,cur_M,cor_H,cor_M);
        int chaH,chaM;
        if(chaH == 0 && chaM == 0)
            return 0;
        if(cor_M >= cur_M){
            chaH = cor_H - cur_H;
            chaM = cor_M - cur_M;
        }else{
            chaH = cor_H - cur_H-1;
            chaM = (60-cur_M) + cor_M;
        }
        printf("%d:%d\n",chaH,chaM);
        int ans = 0;

        if(chaH > 0)
            ans += chaH;

        if(chaM >= 15){
            ans += chaM/15;
            int tmp = chaM%15;
            if(tmp >= 5){
                ans += tmp/5;
                tmp = chaM%5;  
                if(tmp > 0)
                    ans += tmp;
            }else if(tmp > 0) {
                ans += tmp;
            }
        }else if(chaM >= 5) {
            ans += chaM/5;
            int tmp = chaM%5;
            if(tmp > 0)
                ans += tmp;
        }else if(chaM >= 0) {
            ans += chaM;
        }

        return ans;
    }
};



	
int main() {
	Solution solution;
	string current = "00:00";
    string correct = "00:00";

	
	auto ans = solution.convertTime(current,correct);
	
	cout << ans << endl;
	
	return 0;
}




