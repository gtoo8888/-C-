#include <iostream>
using namespace std;


void printBool(bool val){
	if(val == true)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	cout << endl;
}

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
		bool ans;
		int nums[26] = {0};
		for(int i = 0;i < magazine.size();i++){
			nums[magazine.at(i) - 'a']++;
		}
		for(int i = 0;i < ransomNote.size();i++){
			nums[ransomNote.at(i) - 'a']--;
		}
		for(int i = 0;i < 26;i++){
			if(nums[i] < 0)
				return false;
		}
		return true;
    }
};
		
int main() {
	Solution solution;
	string ransomNote = "aa";
	string magazine = "ab";
	int ans;
	
	ans = solution.canConstruct(ransomNote,magazine);
	
	printBool(ans);
	return 0;
}



