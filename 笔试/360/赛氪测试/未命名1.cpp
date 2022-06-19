#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

int main() {

	int n;
	double x;
	while(~scanf("%lf%d", &x, &n))
    {
    	double s;
        for(s = 0.0; n--; x = sqrt(x))
            s += x;
        printf("%.2lf\n", s);
    }   
	return 0;
}
