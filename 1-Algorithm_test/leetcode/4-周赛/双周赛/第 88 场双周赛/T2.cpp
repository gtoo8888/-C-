#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class LUPrefix {
public:
    vector<int> video_save;
	int now_index;
    
    LUPrefix(int n) {
		now_index = 0;
        video_save.resize(n+1);
        for(int i = 0;i < video_save.size();i++){
            video_save[i] = 0;
        }
        // printfLUPrefix();
    }
    
    void upload(int video) {
		video_save[video-1] = 1;
		if(video == now_index + 1)
			now_index += 1;
    }
    
    int longest() {
		int len = 0;
		// printfLUPrefix();
		for(int i = now_index;i < video_save.size();i++){
			if(video_save[i] == 0)
				return now_index;
			else
				now_index++;
            len++;
        }
        return len;
    }

    void printfLUPrefix(){
        for(auto it : video_save){
            cout << it << " ";
        }
        cout << endl;
    }
};

	
int main() {
	LUPrefix* obj = new LUPrefix(10);
	cout << obj->longest() << endl;

	obj->upload(9);
	cout << obj->longest() << endl;
	obj->upload(1);
	cout << obj->longest() << endl;
	obj->upload(2);
	cout << obj->longest() << endl;
	obj->upload(5);
	cout << obj->longest() << endl;
	obj->upload(6);
	cout << obj->longest() << endl;
	obj->upload(3);
	cout << obj->longest() << endl;
	obj->upload(4);
	cout << obj->longest() << endl;
	obj->upload(7);
	cout << obj->longest() << endl;
	obj->upload(8);
	cout << obj->longest() << endl;
	obj->upload(9);
	cout << obj->longest() << endl;
	obj->upload(10);
	cout << obj->longest() << endl;



    // auto ans = solution.equalFrequency(word);

	// PrintBool(ans);
	return 0;
}




