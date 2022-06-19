#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long gcd(long long a,long long b){
    if(a < b){
        long long temp = a;
        a = b;
        b = temp;        
    }

    while(a%b != 0){
        long long r1 = a%b;
        a = b;
        b = r1;
    }
    return b;
}

int lcm(long long a,long long b,long long gcd_num){
    return a*b/gcd_num;
}
	
// int main() {
//     long long n = 10;
// //    scanf("%d",&n);

//     long long lcm_gcd_max = INT32_MIN;
//     long long count = 0;
// 	for(long long i = 1;i <= n;i++){
//         for(long long j = i+1;j <= n;j++){
//             long long gcd_num = gcd(i,j);
//             long long lcm_num = lcm(i,j,gcd_num);
//             long long temp_max = lcm_num - gcd_num;
//             printf("%d %d %d %d %d\n",i,j,gcd_num,lcm_num,temp_max);
//             if(lcm_gcd_max < temp_max)
//                 lcm_gcd_max = temp_max;
//              count++;
//         }
//         cout << endl;
//     }
// 	cout << lcm_gcd_max << endl;
// //    printf("%d\n",count);

// 	return 0;
// }


int main() {
    long long n = 123143435252;
//    scanf("%d",&n);

    cout << n*(n-1) - 1 << endl;

	return 0;
}



