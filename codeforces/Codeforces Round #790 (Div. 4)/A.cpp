#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;



int main() {
	int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++){
		string str;
        cin >> str ;
		int l = (str[0] - '0') + (str[1] - '0') + (str[2] - '0');
		int r = (str[3] - '0') + (str[4] - '0') + (str[5] - '0');
		if(l == r)
			printf("YES\n");
		else
			printf("NO\n");
    }	
	return 0;
}




