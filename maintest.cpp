#include "IntCell.h"
#include <iostream>

int main(){
    IntCell test(4);
    IntCell test2(test);

    std::cout << test2.getValue() << std::endl;

    return 0;
}