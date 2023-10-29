#include <iostream>

int main()
{
    char ch;
    std::cin.get(ch);
    int vowel_count = 0;
    int novowel_count = 0;
    int others = 0;
    bool isLoweVowel = (ch == 'a'||ch == 'e'||ch == 'i'||ch == 'o'||ch == 'u');
    bool isUperVowel = (ch == 'A'||ch == 'E'||ch == 'I'||ch == 'O'||ch == 'U');
    while(ch != 'q'){
        if(isalpha(ch)){
            if(isLoweVowel || isUperVowel){
                vowel_count++;
            }
            else{
                novowel_count++;
            }

            while(isalpha(ch)){
                std::cin.get(ch);
            }
        }
        else if(isspace(ch)){
            std::cin.get(ch);
        }
        else{
            others++;
            while(!isalpha(ch))
                std::cin.get(ch);
        }
    }
    std::cout << vowel_count << " words beginning with vowels\n";
    std::cout << novowel_count << " words beginning with consonants\n";
    std::cout << others << " others";

    return 0;
}