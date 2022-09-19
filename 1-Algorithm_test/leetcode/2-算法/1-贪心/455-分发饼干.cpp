#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(),g.end());
		sort(s.begin(),s.end());
		int ans = 0;
		for(int i = s.size() - 1;i >= 0;i--) {
			for(int j = g.size() - 1;j >= 0;j--) {
				cout << s[i] << " " << g[j] << endl << endl;
				if(s[i] >= g[j]){
					s.erase(s.begin() + i);
					g.erase(g.begin() + j);
					printVector(g);	
					ans++;
					break;
				}	
			}
		}
		return ans;
    }
};

		
int main() {
	Solution solution;
	int nums1[]  = {1,2,7,10};//º¢×ÓÎ¸¿Ú 
	vector<int> g(nums1,nums1 + sizeof(nums1) / sizeof(int));
	int nums2[]  = {1,3,5,9};//±ý¸É 
	vector<int> s(nums2,nums2 + sizeof(nums2) / sizeof(int));
	int ans;
	
//	printVector(g);
//	printVector(s);
	
	ans = solution.findContentChildren(g,s);
	
	cout << ans << endl;
	return 0;
}


