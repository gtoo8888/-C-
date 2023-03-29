#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int closeLampInTree(TreeNode* root) {

    }
};


int main() {
	Solution solution;
	// int num = 4;
	// vector<string> plate = {"..E.",".EOW","..W."};

	// int num = 5;
	// vector<string> plate = {".....","..E..",".WO..","....."};

	// int num = 3;
	// vector<string> plate = {".....","....O","....O","....."};

	int num = 69;
	vector<string> plate = {"W.W.WE..",".WWWEW..","EWW.WE.E","E.W.E.E.",".OEOO.EO","WE.WOE.W","WW...E..",".WEWO..O","E....E..",".OWE...."};

	auto ans = solution.ballGame(num,plate);
	
	PrintVVector(ans);
	return 0;
}



