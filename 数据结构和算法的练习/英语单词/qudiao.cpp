#include <iostream> 
#include <vector>
#include <queue>
#include <string.h>
#include <fstream>

using namespace std;


int main(){

	ifstream infile;
	infile.open("cn-en.md", ios::in);
	if (!infile.is_open())
	{
		cout << "读取文件失败" << endl;
		return 0;
	}

	ofstream outfile;
    outfile.open("en.md");
	string buff;
	while (getline(infile, buff))
	{
        int index = buff.find("|");
        string en_word = buff.substr(0,index);
        outfile << en_word << endl;
	}
	return 0;
}














