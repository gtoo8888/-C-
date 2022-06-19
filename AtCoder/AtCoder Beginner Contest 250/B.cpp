#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
	
    char ans[a*n][b*n];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < a;j++){

            for(int k = 0;k < n;k++){
                for(int l = 0;l < b;l++){
                    if(i%2 == 0){
                        // printf("%d \n",k*b+l);
                        if(k%2 == 0)
                            ans[i*a+j][k*b+l] = '.';
                        else
                            ans[i*a+j][k*b+l] = '#';
                    }else{
                        if(k%2 == 0)
                            ans[i*a+j][k*b+l] = '#';
                        else
                            ans[i*a+j][k*b+l] = '.';
                    }
                }
                // printf("\n");
            }
        }
    }
    for(int i = 0;i < a*n;i++){
        for(int j = 0;j < b*n;j++){
            printf("%c",ans[i][j]);
        }
        printf("\n");
    }
	return 0;
}
