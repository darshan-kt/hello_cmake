// Just main program
/*
#include <iostream>
int main() {
    std::cout << "Hello, CMake!" << std::endl;
    return 0;
}
*/


//Adding helper and utils files
#include <iostream>
#include "helper.h"
#include "utils.h"

int main() {
    std::cout << "Hello from main!" << std::endl;
    helperFunction();
    utilsFunction();
    return 0;
}
