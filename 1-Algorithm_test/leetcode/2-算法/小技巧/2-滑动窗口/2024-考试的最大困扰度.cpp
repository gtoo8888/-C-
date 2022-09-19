#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}



class Solution {
public:
	int huadongchankou(string answerKey, int k,char ch) {//例如传入T
		string temp_string;
		int n = answerKey.size();
		int left = 0;
		int right = 0;
		int sum = 0;
		int ans = 0;
		for(;right < n;right++) {
			if(answerKey[right] != ch){
				sum += 1;//如果最右得到的不是T，那就需要改变，改变的总数+1
				// temp_string += answerKey[right];
			}
			while(sum > k) {
				sum -= answerKey[left++] != ch;
				// int temp_left = left;
			}
			ans = max(ans,right - left + 1);
			// cout << ans << " " << temp_string << endl;
		}
		// cout <<ans <<endl<<endl;
		return ans;
	}

    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(huadongchankou(answerKey,k,'T'),huadongchankou(answerKey,k,'F'));
    }
};


	
int main() {
	Solution solution;
	string answerKey = "TTFTTFTT";
	int k = 1;
	
	auto ans = solution.maxConsecutiveAnswers(answerKey,k);
	cout << ans << endl;
	
	return 0;
}



