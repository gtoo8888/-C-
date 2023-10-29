#include <iostream>


extern "C"{
#include "libavcodec/avcodec.h"
}


int main()
{
    std::cout << "Hello World!\n";
    printf("%s", avcodec_configuration());
    system("pause");
}

