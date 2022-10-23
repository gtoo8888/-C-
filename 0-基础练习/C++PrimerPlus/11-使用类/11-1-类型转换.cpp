#include<iostream> 
using namespace std;
#include "stonewt.h"

void display(const Stonewt & st,int n){
	for(int i = 0;i < n;i++){
		st.show_stn();
	}
}

int main()
{
	Stonewt incog = 275;
	Stonewt wol(285.7);
	Stonewt taf(12,8);

	incog.show_stn();
	wol.show_stn();
	taf.show_stn();
	
	incog
	taft = 325;

	return 0;
}

