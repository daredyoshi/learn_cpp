#include <iostream>
#include <plog/Log.h>
#include "add.h"

void printValue(int value){
    std::cout << value << '\n';
}

int main()
{
    plog::init(plog::debug, "Logfile.txt");
    LOGD << "main() called";
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
    printValue(3);
    return 0;
}
