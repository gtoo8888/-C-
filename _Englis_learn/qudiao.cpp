#include <iostream> 
#include <vector>
#include <queue>
#include <string.h>
#include <fstream>
#include <algorithm>

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
	int line_num = 0;
	while (getline(infile, buff)){
		// cout << buff << endl;
		if(buff.size() != 0){ 	// 去掉非空行
			if(buff[0] != '#' && buff[1] != ' '){
				line_num++;
			}
			if(buff[0] == '#' && buff[1] == ' '){	
				line_num = 0;
			}
			int index = buff.find("|");
			string eng_word = buff.substr(0,index);
			string lower_eng_word = eng_word;
			string upper_eng_word = eng_word;
			transform(eng_word.begin(),eng_word.end(),upper_eng_word.begin(),::toupper);
			transform(eng_word.begin(),eng_word.end(),lower_eng_word.begin(),::tolower);
			// if(eng_word[0] >= 'A' && eng_word[0] <= 'Z')
			// 	eng_word[0] = eng_word[0] - ('A' - 'a');
			if(buff[0] != '#'){	// 单词前面要加标号
				// eng_word = to_string(line_num) + ". " + lower_eng_word + "           " + upper_eng_word;
				eng_word = to_string(line_num) + ". " + lower_eng_word;
			}else if(buff == "# 常见缩写"){	// 失败了
				eng_word = eng_word;
			}else{
				eng_word = eng_word;
			}
				
			outfile << eng_word << endl;
		}
	}
	return 0;
}














