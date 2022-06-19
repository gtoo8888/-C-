#include <iostream> 
#include <vector>
#include <queue>
using namespace std;


void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


void PrintVVector(vector<vector<int>> v){
	
	for(auto iter = v.begin();iter != v.end();iter++){		
		auto it_temp = *iter;
		for(auto it = it_temp.begin();it != it_temp.end();it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}


// 不可以用遍历的方法，需要用图的思想去做
// 如果一个一个遍历，可能出现先打开后面的房间，但是前面房间无法打开的情况
// class Solution {
// public:
//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
// 		int n = rooms.size(),m = rooms[0].size();
// 		vector<int> room_save(n,0);
// 		// printf("%d\n",n);
// 		room_save[0] = 1;
// 		for(int i = 0;i < n;i++){
// 			for(int j = 0;j < rooms[i].size();j++){
// 				if(room_save[i] == 1)
// 					room_save[rooms[i][j]] = 1;
// 			}
// 		}
// 		PrintVector(room_save);
// 		for(int i = 0;i < n;i++){
// 			if(room_save[i] == 0)
// 				return false;
// 		}
// 		return true;
//     }
// };

class Solution {
public:
	vector<int> room_save;
	int num = 0;
	void dfs(vector<vector<int>>& rooms,int x){
		room_save[x] = true;
		num++;
		// PrintVector(room_save);
		// PrintVector(rooms[x]);
		// printf("\n");
		for(auto it : rooms[x]){
			// printf("%d\n",it);
			if(room_save[it] == 0)
				dfs(rooms,it);
		}
		// for(int it = 0;it < rooms[x].size();it++){
		// 	if(room_save[rooms[x][it]] == 0)
		// 		dfs(rooms,it);
		// }
	}

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
		int n = rooms.size();
		room_save.resize(n);
		dfs(rooms,0);
		// printf("%d\n",num);
		return num == n;
    }
};

int main(){
	Solution solution;
	// vector<vector<int>> rooms =  {{1},{2},{3},{}};
	// vector<vector<int>> rooms =  {{1,3},{3,0,1},{2},{0}};
	vector<vector<int>> rooms =   {{6,7,8},{5,4,9},{},{8},{4},{},{1,9,2,3},{7},{6,5},{2,3,1}};

	// PrintVVector(rooms);
	
	auto ans = solution.canVisitAllRooms(rooms);
	
	PrintBool(ans);
	
	return 0;
}














