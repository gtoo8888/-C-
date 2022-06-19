#include<iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
		int nums[26] = {0};
		int n1 = s.size();
		int n2 = t.size();
//		if(n1 == 0 || n2 == 0)//��ĿҪ��s��t��Ϊ0�����Բ��ÿ�������߽����� 
//			return false;
		for (int i = 0;i < n1;i++) 
			nums[s.at(i)-'a']++;	
//		for (int i = 0;i < 26;i++) 
//			cout << nums[i] << " ";
//		cout << endl;
		for (int i = 0;i < n2;i++) 
			nums[t.at(i)-'a']--;
			
		for (int i = 0;i < 26;i++)
			if (nums[i] != 0)
				return false;
		return true;
    }
};


int main() {
	Solution solution;
	bool ans = 1;
	string str1 = "";
	string str2 = "";
	
	ans = solution.isAnagram(str1,str2);

	if(ans == true)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	return 0;
}


