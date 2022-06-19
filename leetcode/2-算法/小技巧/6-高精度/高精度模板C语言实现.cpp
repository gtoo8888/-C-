#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

static const int LEN = 1000;
int a[LEN],b[LEN];
void clear(int a[]){
    for(int i = 0;i < LEN;i++)
        a[i] = 0;
}

void read_s(int a[]){
    char s[LEN + 1];
    scanf("%s",s);

    clear(a);

    int len = strlen(s);
    for(int i = 0;i < len;++i)
        a[len - i - 1] = s[i] - '0';
}

void print_s(int a[]){
    int i;
    for(i = LEN-1;i >= 1;i--){
        if(a[i] != 0)
            break;
    }
    for(;i >= 0 ;i--)
        putchar(a[i] + '0');
    putchar('\n');
}


int main() {
	
	
	return 0;
}



