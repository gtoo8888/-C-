#include <iostream>


extern "C"{
#include "libavcodec/avcodec.h"
}


int main(int arg,char* argv[])
{
    std::cout << "Hello World!\n";
    printf("%s\n", avcodec_configuration());
    system("pause");
}

