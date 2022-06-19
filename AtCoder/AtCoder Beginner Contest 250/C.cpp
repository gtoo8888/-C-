#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;


// void test1(int ans[n];){
//     for(int i = 0;i < n;i++){
//         for(int j = 0;j < m;j++){
//             printf("%c ",ans[i][j]);
//         }
//         printf("\n");
//     }
// }
// void swap(int a,int b){
//     int c = a;
//     a = b;
//     b = c;
// }

void test1(int ans[],int n){
    for(int i = 0;i < n;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
}


int main(){
	int n,q;
    scanf("%d %d",&n,&q);
	
    int ans[n];
    for(int i = 1;i <= n;i++)
        ans[i-1] = i;
    // test1(ans,n);


    while(q--){
        int x;
        scanf("%d",&x);
        for(int i = 0;i < n;i++){
            // printf("%d %d\n",ans[i],x);
            if(ans[i] == x){
                int tmp = ans[i];
                if(i+1 < n){
                    ans[i] = ans[i+1];
                    ans[i+1] = tmp; 
                }else{
                    ans[i] = ans[i-1];
                    ans[i-1] = tmp; 
                }
                break;
            }
        }
        
    }
    test1(ans,n);

	return 0;
}
