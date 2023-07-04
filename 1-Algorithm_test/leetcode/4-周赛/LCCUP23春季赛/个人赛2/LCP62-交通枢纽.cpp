#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


bool mycompare(pair<int,int> p1,pair<int,int> p2){
    if(p1.first > p2.first){
        return true;
    }else{
        return false;
    }
}


class Solution {
public:
    int adventureCamp(vector<string>& expeditions) {
		set<string> ss;
		string root_camp = expeditions[0];
		int l = 0,r = 0;
		while(r < root_camp.size()){
			if(root_camp[r] == '-'){
				string camp = root_camp.substr(l,r-l);
				ss.insert(camp);
                l = r+2;
                r++;
			}
			r++;
		}
        ss.insert(root_camp.substr(l,r-l));
        int ans = INT32_MAX;
        vector<pair<int,int>> vp;
        for(int i = 1;i < expeditions.size();i++){
            int now_num = 0;
            string now_camp = expeditions[i];
            int l = 0,r = 0;
            while(r < now_camp.size()){
                if(now_camp[r] == '-'){
                    string camp = now_camp.substr(l,r-l);
                    if(ss.find(camp) == ss.end()){
                        now_num++;
                    }
                    l = r+2;
                    r++;
                }
                r++;
            }
            string campt = now_camp.substr(l,r-l);
            if(campt != "" && ss.find(campt) == ss.end()){
                now_num++;
            }
            vp.push_back({now_num,i});
            if(now_num != 0)
                ans = min(i,ans);
		}
        if(ans == INT32_MAX)
            return -1;
        sort(vp.begin(),vp.end(),mycompare);
        PrintVP(vp);
		return ans;
    }
};


int main() {
	Solution solution;
	// vector<string> expeditions = {"leet->code","leet->code->Campsite->Leet","leet->code->leet->courier"};
	// vector<string> expeditions = {"Alice->Dex","","Dex"};
    vector<string> expeditions = {"","Gryffindor->Slytherin->Gryffindor","Hogwarts->Hufflepuff->Ravenclaw"};

	auto ans = solution.adventureCamp(expeditions);
	
	cout << ans << endl;
	
	return 0;
}



