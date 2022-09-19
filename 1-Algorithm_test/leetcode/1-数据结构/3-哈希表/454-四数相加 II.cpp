#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void printMap(unordered_map<int,int> m) {
	for(auto it = m.begin();it != m.end();it++)
		cout << (*it).first << " " << it->second << endl;
	cout << endl;	
}


class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
		unordered_map<int,int> map1;
		for(int i = 0;i < nums1.size();i++) 
			for(int j = 0;j < nums2.size();j++) 
				map1[nums1[i] + nums2[j]]++;//�Ѻ͵Ľ�������� 
			
//		printMap(map1);
		int ans = 0;
		for(int i = 0;i < nums3.size();i++) {
			for(int j = 0;j < nums4.size();j++) { 
//				cout << -(nums3[i] + nums4[j]) << endl;
				if(map1.find(-(nums3[i] + nums4[j])) != map1.end()) {//�ҵ���a+b = -(c+d) 
					ans += map1[-(nums3[i] + nums4[j])];//��ǰ�����ĺ͵���ɴ����ӵ���������� 
				}
			}
		}
		return ans;
    }
};


int main() {
	Solution solution;
	vector<int> nums1 = {1,2}; 
	vector<int> nums2 = {-2,-1}; 
	vector<int> nums3 = {-1,2}; 
	vector<int> nums4 = {0,2}; 
	
	int ans;



	ans = solution.fourSumCount(nums1,nums2,nums3,nums4);


	cout << ans << endl; 

	return 0;
}


