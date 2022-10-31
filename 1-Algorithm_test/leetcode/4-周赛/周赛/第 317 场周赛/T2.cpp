#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"


bool myconpare2(pair<string,int> p1,pair<string,int> p2){
	if(p1.second > p2.second)
		return true;
	// else if(p1.second < p2.second)
    else
		return false;
    return true;
}

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        unordered_map<string,int> umap;
        for(int i = 0;i < n;i++){
            umap[creators[i]] += views[i];
        }
        // PrintUnorder_Map(umap);
        vector<pair<string,int>> vp;
        for(auto it : umap){
            vp.emplace_back(it.first,it.second);
        }
        sort(vp.begin(),vp.end(),myconpare2);
        int max = vp[0].second;
        vector<string> ans_t;
        for(auto it : vp){
            if(it.second == max)
                ans_t.emplace_back(it.first);
        }
        // PrintVector(ans_t);
        vector<vector<string>> ans;
        for(int i = 0;i < ans_t.size();i++){
            string ans_str = ans_t[i];
            vector<pair<string,int>> houxuan;
            for(int j = 0;j < n;j++){
                if(ans_str == creators[j]){
                    houxuan.emplace_back(ids[j],views[j]);
                }
            }
            sort(houxuan.begin(),houxuan.end(),myconpare2);
            vector<string> houxuan2;
            int houxuan_max = houxuan[0].second;
            
            for(auto it : houxuan){
                if(it.second == houxuan_max)
                    houxuan2.emplace_back(it.first);
            }
            // PrintVector(houxuan2);
            sort(houxuan2.begin(),houxuan2.end());
            // cout << endl;
            vector<string> aans ;
            aans.emplace_back(ans_str);
            aans.emplace_back(houxuan2[0]);
            ans.emplace_back(aans);
        }
        return ans;
    }
};
	
int main() {
	Solution solution;
  
    // vector<string> creators = {"alice","bob","alice","chris"};
    // vector<string> ids = {"one","two","three","four"};
    // vector<int> views = {5,10,5,4};


    // vector<string> creators = {"alice","bob","alice","chris","alice"};
    // vector<string> ids = {"one","two","three","four","five"};
    // vector<int> views = {5,10,5,4,3};

    vector<string> creators = {"alice","alice","alice"};
    vector<string> ids = {"a","b","c"};
    vector<int> views = {1,2,2};


    auto ans = solution.mostPopularCreator(creators,ids,views);

	PrintVVector(ans);
	return 0;
}




