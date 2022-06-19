#include <stdio.h>
#include <iostream>
using namespace std;


int main()
{
	char kuohaol[20];	
	FILE *filename;
	
	
	filename = fopen("1.txt","r");
	fscanf(filename,"%s",kuohaol);
	
	cout << kuohaol << endl;
	
	
	return 0;
}
 
