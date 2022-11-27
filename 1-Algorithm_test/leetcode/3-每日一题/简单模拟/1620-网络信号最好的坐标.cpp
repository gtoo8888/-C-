#include <algorithm> 
#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// ???sqrt????????
// class Solution {
// public:
//     vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
// 		int xmax = -1,ymax = -1;
// 		for(auto tower : towers){	
// 			xmax = xmax < tower[0] ? tower[0] : xmax;
// 			ymax = ymax < tower[1] ? tower[1] : ymax;
// 		}
// 		// printf("%d %d",xmax,ymax);
// 		int max_q = -1;
// 		int ansx=0,ansy=0;
// 		for(int i = 0;i <= xmax;i++){
// 			for(int j = 0;j <= ymax;j++){
// 				int qiangdu = 0;
// 				for(auto tower : towers){
// 					int dis = calc(i,j,tower);
					
// 					if(dis <= radius){
// 						printf("%d %d\n",dis,tower[2]);
// 						qiangdu += tower[2]/(1+dis);
// 					}
// 					// printf("%d %d\n",dis,qiangdu);
// 				}
				
// 				if(qiangdu > max_q){
// 					ansx = i;ansy = j;
// 					max_q = qiangdu;
// 				}
// 				printf("(%d,%d) %d (%d,%d)\n",i,j,qiangdu,ansx,ansy);
// 			}
// 		}
// 		return {ansx,ansy};
//     }

// 	int calc(int& x,int& y,vector<int>& tower){
// 		return sqrt(abs(x-tower[0])*abs(x-tower[0]) + abs(y-tower[1])*abs(y-tower[1]));
// 	}
// };


// ?????????
class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
		int xmax = -1,ymax = -1;
		for(auto tower : towers){	
			xmax = xmax < tower[0] ? tower[0] : xmax;
			ymax = ymax < tower[1] ? tower[1] : ymax;
		}
		// printf("%d %d",xmax,ymax);
		int max_q = -1;
		int ansx=0,ansy=0;
		for(int i = 0;i <= xmax;i++){
			for(int j = 0;j <= ymax;j++){
				int qiangdu = 0;
				for(auto tower : towers){
					int sqr_dis = calc(i,j,tower);	
					if(sqr_dis <= radius*radius){
						// printf("%d %d\n",sqr_dis,tower[2]);
						qiangdu += (double)tower[2]/(1+sqrt(sqr_dis));
					}
				}
				if(qiangdu > max_q){
					ansx = i;ansy = j;
					max_q = qiangdu;
				}
				// printf("(%d,%d) %d (%d,%d)\n",i,j,qiangdu,ansx,ansy);
			}
		}
		return {ansx,ansy};
    }

	int calc(int& x,int& y,vector<int>& tower){
		return abs(x-tower[0])*abs(x-tower[0]) + abs(y-tower[1])*abs(y-tower[1]);
	}
};


int main(){
	Solution sol;
	// vector<vector<int>> towers = {{1,2,5},{2,1,7},{3,1,9}};
	// int radius = 2;

	// vector<vector<int>> towers = {{23,11,21}};
	// int radius = 9;

	// vector<vector<int>> towers = {{1,2,13},{2,1,7},{0,1,9}};
	// int radius = 2;

	vector<vector<int>> towers = {{0,1,2},{2,1,2},{1,0,2},{1,2,2}};
	int radius = 1;

	auto ans = sol.bestCoordinate(towers,radius);
	PrintVector(ans);
    return 0;
}


