#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

vector<int> pathX = {1,2,3};
int findfrind(int n,int k){
    queue<int> que;
    que.push(n);
    int ans = 0;
    vector<bool> used(n,false);
    while(que.size() > 0){
        int len = que.size();
        for(int i = 0;i < len;i++){
            int dx = que.front();
            if(dx == k)
                return ans;
            que.pop();
            for(int j = 0;j < 3;j++){
                int px = 0;
                if(j == 0){
                    px = dx + 1;
                }else if(j == 1){
                    px = dx - 1;
                }else{
                    px = dx * 2;
                }
                if(px < 0 || px >= 2*k){
                    continue;
                }
                if(!used[px]){
                    que.push(px);
                    used[px] = true;
                }
            }
        }
        ans++;
    }
    return -1;
}

	
int main() {
	int n = 0;
    int k = 2;
    // scanf("%d %d\n",&n,&k);
    auto ans = findfrind(n,k);
    if(ans == -1){
        printf("小青无法到达小码家");
    }else{
        printf("小青到小码家时间为:%d",ans);
    }
	return 0;
}




