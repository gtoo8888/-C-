#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


	
int main() {
	int t;
    scanf("%d",&t);

    for(int i = 0;i < t;i++){
        int rating;
        scanf("%d",&rating);
        if(rating >= 1900)
            std::cout << "Division 1" << std::endl;
        else if(rating >= 1600)
            std::cout << "Division 2" << std::endl;
        else if(rating >= 1400)
            std::cout << "Division 3" << std::endl;
        else 
            std::cout << "Division 4" << std::endl;
    }	
	return 0;
}




