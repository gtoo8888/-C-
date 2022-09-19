#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int h,w,r,c;
    scanf("%d %d\n%d %d",&h,&w,&r,&c);
	// printf("%d %d\n%d %d",h,w,r,c);
	
    if(h == 1 && w == 1)
        printf("0\n");
    else if(h == 1){
        if(r == 1 && c == 1 || r == 1 && c == w)
            printf("1\n");
        else
            printf("2\n");
    }
    else if(w == 1){
        if(r == 1 && c == 1 || r == h && c == 1)
            printf("1\n");
        else
            printf("2\n");
    }
    else{
        if(r == h && c == w || r == 1 && c == w || r == h && c == 1 || r == 1 && c == 1 ){
            printf("2\n");
        }
        else if(r == h || c == w || r == 1 || c == 1){
            printf("3\n");
        }
        else{
            printf("4\n");
        }
    }




    printf("%d\n",(r>1)+(r<h)+(c>1)+(c<w));


	return 0;
}
