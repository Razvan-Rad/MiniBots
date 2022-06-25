#include <iostream>
#include "lib/debugger.hpp"
int main()
{
    std::cout << "Hello World!" << std::endl;
    error::buffer buffer;
    buffer.printAll();
    return 0;
}